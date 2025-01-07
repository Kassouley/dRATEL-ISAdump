import re
import subprocess
import sys

def decode_mask(mask):
    
    xor_mask, or_mask, and_mask = mask
    decoded_mask = ""

    # Decode each bit position
    for i in range(5):
        xor_bit = xor_mask[i]
        or_bit = or_mask[i]
        and_bit = and_mask[i]

        if xor_bit == '1':
            decoded_mask += 'i'  # Inverse bit
        elif or_bit == '1':
            decoded_mask += '1'  # Set to 1
        elif and_bit == '1':
            decoded_mask += 'p'  # Preserve bit
        else:
            decoded_mask += '0'  # Set to 0

    return decoded_mask

symbols = ['i', 'p', '1', '0']
def generate_combinations(current, length, symbols, results):
    if length == 0:
        results.append(current)
        return
    for symbol in symbols:
        generate_combinations(current + symbol, length - 1, symbols, results)
results = []
generate_combinations("", 5, symbols, results)

source = """
#include <stdio.h>
#include <hip/hip_runtime.h>

int main(void) { return 0; }

__global__ void ds_swizzle_b32() {
    __asm__ volatile(" \\
"""

asm_lines = []
for combo in results:
    asm_lines.append(f'\t\tds_swizzle_b32 v0, v0 offset:swizzle(BITMASK_PERM, \\"{combo}\\")')

asm = "\\n \\\n".join(asm_lines)

source = source + asm + '");\n}'


output_file = "mask_tester.cpp"
with open(output_file, "w") as file:
    file.write(source)

result = subprocess.run("hipcc " + output_file, shell=True, text=True, capture_output=True)

if result.returncode != 0: 
    print("Command Error:")
    print(result.stderr)
    exit()

result = subprocess.run('roc-obj -d a.out && grep -v "s_nop" a.out\:1.hipv4-amdgcn-amd-amdhsa--gfx90a.s', shell=True, text=True, capture_output=True)

if result.returncode != 0: 
    print("Command Error:")
    print(result.stderr)
    exit()

pattern = r'(swizzle\(.*?\))\s*//\s*[0-9A-F]*: ([0-9A-F]{8})'
pattern2 = r'swizzle\(BITMASK_PERM,\s*"(.*)"\)'

lines_and_hex = []

for line in result.stdout.splitlines():
    match = re.search(pattern, line, re.IGNORECASE)
    if match:
        swizzle_part = match.group(1)
        hex_code = match.group(2)  # Hex code
        last_4_chars = hex_code[-4:]  # Last 4 hex characters
        decimal_value = int(last_4_chars, 16)  # Convert hex to decimal
        binary_equivalent = bin(decimal_value)[2:].zfill(16)  # Convert to binary and pad to 16 bits
        mask = [binary_equivalent[i:i+5] for i in range(1, len(binary_equivalent), 5)]
        decoded_mask = decode_mask(mask)
        spaced_binary = binary_equivalent[0] + ' ' + ' '.join(mask)

        is_correct = "WRONG"
        match2 = re.search(pattern2, swizzle_part)
        if match2:
            true_decoded_mask = match.group(1)
            if true_decoded_mask == decoded_mask:
                is_correct = "CORRECT"

        # Add tuple (hex_value, decimal_value, line) to list
        lines_and_hex.append((decimal_value, f"{swizzle_part:<{30}} : {is_correct} : {decoded_mask} : {last_4_chars:<{5}} : {spaced_binary:<{20}} : {decimal_value:<{10}}"))

if len(sys.argv) > 1 and sys.argv[1] == '--sort':
    lines_and_hex.sort(key=lambda x: x[0])

for _, line in lines_and_hex:
    print(line)

import re
import subprocess

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

lines_and_hex = []

for line in result.stdout.splitlines():
    match = re.search(pattern, line, re.IGNORECASE)
    if match:
        swizzle_part = match.group(1)
        hex_code = match.group(2)  # Hex code
        last_4_chars = hex_code[-4:]  # Last 4 hex characters
        binary_equivalent = bin(int(last_4_chars, 16))[2:].zfill(16)  # Convert to binary and pad to 16 bits
        spaced_binary = ' '.join([binary_equivalent[i:i+4] for i in range(0, len(binary_equivalent), 4)])

        # Add tuple (hex_code, line) to list
        lines_and_hex.append((int(last_4_chars, 16), f"{swizzle_part:<{40}} : {last_4_chars:<{5}} : {spaced_binary:<{20}}"))

lines_and_hex.sort(key=lambda x: x[0])

for _, line in lines_and_hex:
    print(line)
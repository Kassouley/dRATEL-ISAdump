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
    __asm__ volatile("
"""

asm_lines = []
for combo in results:
    asm_lines.append(f"\t\tds_swizzle_b32 v0, v0 offset:swizzle(BITMASK_PERM, \"{combo}\")")

asm = "\\n \\\n".join(asm_lines)

source = source + asm + '");\n}'

with open("../../output/swizzle_pattern_tester/mask_tester.cpp", "w") as file:
    file.write(source)

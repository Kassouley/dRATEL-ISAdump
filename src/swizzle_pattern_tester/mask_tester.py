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
        ds_swizzle_b32 v0, v0 offset:swizzle(QUAD_PERM, 0, 0, 0, 0)   \n \\
                      ds_swizzle_b32 v0, v0 offset:swizzle(QUAD_PERM, 0, 1, 2, 3)   \n \\
                      ds_swizzle_b32 v0, v0 offset:swizzle(QUAD_PERM, 3, 3, 3, 3)   \n \\
                      ds_swizzle_b32 v0, v0 offset:swizzle(BITMASK_PERM, \"00000\") \n \\
                      ds_swizzle_b32 v0, v0 offset:swizzle(BITMASK_PERM, \"11111\") \n \\
                      ds_swizzle_b32 v0, v0 offset:swizzle(BITMASK_PERM, \"iiiii\") \n \\
                      ds_swizzle_b32 v0, v0 offset:swizzle(BITMASK_PERM, \"ppppp\") \n \\
                      ds_swizzle_b32 v0, v0 offset:swizzle(BITMASK_PERM, \"01pi0\") \n \\
                      ds_swizzle_b32 v0, v0 offset:swizzle(BROADCAST, 2, 0)         \n \\
                      ds_swizzle_b32 v0, v0 offset:swizzle(BROADCAST, 32, 0)        \n \\
                      ds_swizzle_b32 v0, v0 offset:swizzle(SWAP, 1)                 \n \\
                      ds_swizzle_b32 v0, v0 offset:swizzle(SWAP, 8)                 \n \\
                      ds_swizzle_b32 v0, v0 offset:swizzle(SWAP, 16)                \n \\
                      ds_swizzle_b32 v0, v0 offset:swizzle(REVERSE, 2)              \n \\
                      ds_swizzle_b32 v0, v0 offset:swizzle(REVERSE, 16)             \n \\
                      ds_swizzle_b32 v0, v0 offset:swizzle(REVERSE, 32)             \n");
}
"""

asm_lines = []
for combo in results:
    asm_lines.append(f"\t\tds_swizzle_b32 v0, v0 offset:swizzle(BITMASK_PERM, \"{combo}\")\\n \\")

asm = "\n".join(asm_lines)

source = source + asm + '\n");\n}'

with open("swizzle_pattern_tester/mask_tester.cpp", "w") as file:
    file.write(source)

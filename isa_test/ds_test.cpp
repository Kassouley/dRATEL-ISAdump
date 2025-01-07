#include <stdio.h>
#include <hip/hip_runtime.h>
#include "types.h"

__global__ void ds_swizzle_b32() {
    b32 vdst; b32 vaddr;
    __asm__ volatile("ds_swizzle_b32 v0, v0 offset:swizzle(QUAD_PERM, 0, 0, 0, 0)   \n \
                      ds_swizzle_b32 v0, v0 offset:swizzle(QUAD_PERM, 0, 1, 2, 3)   \n \
                      ds_swizzle_b32 v0, v0 offset:swizzle(QUAD_PERM, 3, 3, 3, 3)   \n \
                      ds_swizzle_b32 v0, v0 offset:swizzle(BITMASK_PERM, \"00000\") \n \
                      ds_swizzle_b32 v0, v0 offset:swizzle(BITMASK_PERM, \"11111\") \n \
                      ds_swizzle_b32 v0, v0 offset:swizzle(BITMASK_PERM, \"iiiii\") \n \
                      ds_swizzle_b32 v0, v0 offset:swizzle(BITMASK_PERM, \"ppppp\") \n \
                      ds_swizzle_b32 v0, v0 offset:swizzle(BITMASK_PERM, \"01pi0\") \n \
                      ds_swizzle_b32 v0, v0 offset:swizzle(BROADCAST, 2, 0)         \n \
                      ds_swizzle_b32 v0, v0 offset:swizzle(BROADCAST, 32, 0)        \n \
                      ds_swizzle_b32 v0, v0 offset:swizzle(SWAP, 1)                 \n \
                      ds_swizzle_b32 v0, v0 offset:swizzle(SWAP, 8)                 \n \
                      ds_swizzle_b32 v0, v0 offset:swizzle(SWAP, 16)                \n \
                      ds_swizzle_b32 v0, v0 offset:swizzle(REVERSE, 2)              \n \
                      ds_swizzle_b32 v0, v0 offset:swizzle(REVERSE, 16)             \n \
                      ds_swizzle_b32 v0, v0 offset:swizzle(REVERSE, 32)             \n");
}

int main(void) { return 0; }
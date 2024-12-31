#include "types.h"
#include <hip/hip_runtime.h>
#include <stdio.h>
#include <emmintrin.h>

typedef char charx4 __attribute__((ext_vector_type(4)));

__global__ void v_dot4_i32_i8(i32 vdst, charx4 src0, charx4 src1, i32 src2) {
    __asm__ volatile("v_dot4_i32_i8 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0[0]), "v"(src1[0]), "v"(src2));
}

__global__ void v_mfma_f32_16x16x1f32(f32x16 vdst, f32 vsrc0, f32 vsrc1, f32x16 src2) {
    __asm__("v_mfma_f32_16x16x1f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void duh(b32x16 vdst, f32 vsrc0, f32 vsrc1, b32x16 src2) {
	__asm__ volatile("v_mfma_f32_16x16x1f32 %0, %1, %2, %3 \n" :  : "v"(vdst), "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_accvgpr_read(b32 vdst, b32 vsrc) {
    __asm__("v_accvgpr_read %0, %1 \n" : "=v"(vdst) : "s"(vsrc));
}
int main() { printf("%lu\n", sizeof(charx4));  return 0; }

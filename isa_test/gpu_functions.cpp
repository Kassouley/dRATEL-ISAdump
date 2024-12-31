#include <stdint.h>
#include <hip/hip_runtime.h>
#include "types.h"

int main(void) { return 0; }


__global__ void s_bitcmp0_b32() {
    b32 ssrc0; b32 ssrc1;
    __asm__ volatile("s_bitcmp0_b32 %0, %1 \n" :  : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_bitcmp0_b64() {
    b64 ssrc0; u32 ssrc1;
    __asm__ volatile("s_bitcmp0_b64 %0, %1 \n" :  : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_bitcmp1_b32() {
    b32 ssrc0; b32 ssrc1;
    __asm__ volatile("s_bitcmp1_b32 %0, %1 \n" :  : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_bitcmp1_b64() {
    b64 ssrc0; u32 ssrc1;
    __asm__ volatile("s_bitcmp1_b64 %0, %1 \n" :  : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_cmp_eq_i32() {
    i32 ssrc0; i32 ssrc1;
    __asm__ volatile("s_cmp_eq_i32 %0, %1 \n" :  : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_cmp_eq_u32() {
    u32 ssrc0; u32 ssrc1;
    __asm__ volatile("s_cmp_eq_u32 %0, %1 \n" :  : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_cmp_eq_u64() {
    u64 ssrc0; u64 ssrc1;
    __asm__ volatile("s_cmp_eq_u64 %0, %1 \n" :  : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_cmp_ge_i32() {
    i32 ssrc0; i32 ssrc1;
    __asm__ volatile("s_cmp_ge_i32 %0, %1 \n" :  : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_cmp_ge_u32() {
    u32 ssrc0; u32 ssrc1;
    __asm__ volatile("s_cmp_ge_u32 %0, %1 \n" :  : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_cmp_gt_i32() {
    i32 ssrc0; i32 ssrc1;
    __asm__ volatile("s_cmp_gt_i32 %0, %1 \n" :  : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_cmp_gt_u32() {
    u32 ssrc0; u32 ssrc1;
    __asm__ volatile("s_cmp_gt_u32 %0, %1 \n" :  : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_cmp_le_i32() {
    i32 ssrc0; i32 ssrc1;
    __asm__ volatile("s_cmp_le_i32 %0, %1 \n" :  : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_cmp_le_u32() {
    u32 ssrc0; u32 ssrc1;
    __asm__ volatile("s_cmp_le_u32 %0, %1 \n" :  : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_cmp_lg_i32() {
    i32 ssrc0; i32 ssrc1;
    __asm__ volatile("s_cmp_lg_i32 %0, %1 \n" :  : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_cmp_lg_u32() {
    u32 ssrc0; u32 ssrc1;
    __asm__ volatile("s_cmp_lg_u32 %0, %1 \n" :  : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_cmp_lg_u64() {
    u64 ssrc0; u64 ssrc1;
    __asm__ volatile("s_cmp_lg_u64 %0, %1 \n" :  : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_cmp_lt_i32() {
    i32 ssrc0; i32 ssrc1;
    __asm__ volatile("s_cmp_lt_i32 %0, %1 \n" :  : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_cmp_lt_u32() {
    u32 ssrc0; u32 ssrc1;
    __asm__ volatile("s_cmp_lt_u32 %0, %1 \n" :  : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_set_gpr_idx_on() {
    b32 ssrc;
    __asm__ volatile("s_set_gpr_idx_on %0, %1 \n" :  : "s"(ssrc), "i"(0));
}

__global__ void s_setvskip() {
    b32 ssrc0; b32 ssrc1;
    __asm__ volatile("s_setvskip %0, %1 \n" :  : "s"(ssrc0), "s"(ssrc1));
}

__global__ void v_accvgpr_read_b32() {
    b32 vdst; b32 vsrc;
    __asm__ volatile("v_accvgpr_read_b32 %0, %1 \n" : "=v"(vdst) : "a"(vsrc));
}

__global__ void v_accvgpr_write_b32() {
    b32 vdst; b32 src;
    __asm__ volatile("v_accvgpr_write_b32 %0, %1 \n" : "=a"(vdst) : "v"(src));
}

__global__ void v_dot2_f32_f16() {
    f32 vdst; f16x2 src0; f16x2 src1; f32 src2;
    __asm__ volatile("v_dot2_f32_f16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_dot2_i32_i16() {
    i32 vdst; i16x2 src0; i16x2 src1; i32 src2;
    __asm__ volatile("v_dot2_i32_i16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_dot2_u32_u16() {
    u32 vdst; u16x2 src0; u16x2 src1; u32 src2;
    __asm__ volatile("v_dot2_u32_u16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_dot4_i32_i8() {
    i32 vdst; i8x4 src0; i8x4 src1; i32 src2;
    __asm__ volatile("v_dot4_i32_i8 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_dot4_u32_u8() {
    u32 vdst; u8x4 src0; u8x4 src1; u32 src2;
    __asm__ volatile("v_dot4_u32_u8 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_dot8_i32_i4() {
    i32 vdst; i4x8 src0; i4x8 src1; i32 src2;
    __asm__ volatile("v_dot8_i32_i4 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_dot8_u32_u4() {
    u32 vdst; u4x8 src0; u4x8 src1; u32 src2;
    __asm__ volatile("v_dot8_u32_u4 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_fma_mix_f32() {
    f32 vdst; f32 src0; f32 src1; f32 src2;
    __asm__ volatile("v_fma_mix_f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_fma_mixhi_f16() {
    f16 vdst; f32 src0; f32 src1; f32 src2;
    __asm__ volatile("v_fma_mixhi_f16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_fma_mixlo_f16() {
    f16 vdst; f32 src0; f32 src1; f32 src2;
    __asm__ volatile("v_fma_mixlo_f16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_pk_add_f16() {
    f16 vdst; f16 src0; f16 src1;
    __asm__ volatile("v_pk_add_f16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_pk_add_f32() {
    b64 vdst; b64 src0; b64 src1;
    __asm__ volatile("v_pk_add_f32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_pk_add_i16() {
    i16 vdst; i16 src0; i16 src1;
    __asm__ volatile("v_pk_add_i16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_pk_add_u16() {
    u16 vdst; u16 src0; u16 src1;
    __asm__ volatile("v_pk_add_u16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_pk_ashrrev_i16() {
    i16 vdst; u16x2 src0; i16 src1;
    __asm__ volatile("v_pk_ashrrev_i16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_pk_fma_f16() {
    f16 vdst; f16 src0; f16 src1; f16 src2;
    __asm__ volatile("v_pk_fma_f16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_pk_fma_f32() {
    b64 vdst; b64 src0; b64 src1; b64 src2;
    __asm__ volatile("v_pk_fma_f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_pk_lshlrev_b16() {
    b16 vdst; u16x2 src0; b16 src1;
    __asm__ volatile("v_pk_lshlrev_b16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_pk_lshrrev_b16() {
    b16 vdst; u16x2 src0; b16 src1;
    __asm__ volatile("v_pk_lshrrev_b16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_pk_mad_i16() {
    i16 vdst; i16 src0; i16 src1; i16 src2;
    __asm__ volatile("v_pk_mad_i16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_pk_mad_u16() {
    u16 vdst; u16 src0; u16 src1; u16 src2;
    __asm__ volatile("v_pk_mad_u16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_pk_max_f16() {
    f16 vdst; f16 src0; f16 src1;
    __asm__ volatile("v_pk_max_f16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_pk_max_i16() {
    i16 vdst; i16 src0; i16 src1;
    __asm__ volatile("v_pk_max_i16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_pk_max_u16() {
    u16 vdst; u16 src0; u16 src1;
    __asm__ volatile("v_pk_max_u16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_pk_min_f16() {
    f16 vdst; f16 src0; f16 src1;
    __asm__ volatile("v_pk_min_f16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_pk_min_i16() {
    i16 vdst; i16 src0; i16 src1;
    __asm__ volatile("v_pk_min_i16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_pk_min_u16() {
    u16 vdst; u16 src0; u16 src1;
    __asm__ volatile("v_pk_min_u16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_pk_mov_b32() {
    b64 vdst; b64 src0; b64 src1;
    __asm__ volatile("v_pk_mov_b32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_pk_mul_f16() {
    f16 vdst; f16 src0; f16 src1;
    __asm__ volatile("v_pk_mul_f16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_pk_mul_f32() {
    b64 vdst; b64 src0; b64 src1;
    __asm__ volatile("v_pk_mul_f32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_pk_mul_lo_u16() {
    u16 vdst; u16 src0; u16 src1;
    __asm__ volatile("v_pk_mul_lo_u16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_pk_sub_i16() {
    i16 vdst; i16 src0; i16 src1;
    __asm__ volatile("v_pk_sub_i16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_pk_sub_u16() {
    u16 vdst; u16 src0; u16 src1;
    __asm__ volatile("v_pk_sub_u16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void ds_add_f32() {
    f32 vaddr; f32 vdata;
    __asm__ volatile("ds_add_f32 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_add_f64() {
    b32 vaddr; f64 vdata;
    __asm__ volatile("ds_add_f64 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_add_rtn_f32() {
    f32 vdst; f32 vaddr; f32 vdata;
    __asm__ volatile("ds_add_rtn_f32 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_add_rtn_f64() {
    f64 vdst; b32 vaddr; f64 vdata;
    __asm__ volatile("ds_add_rtn_f64 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_add_rtn_u32() {
    u32 vdst; u32 vaddr; u32 vdata;
    __asm__ volatile("ds_add_rtn_u32 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_add_rtn_u64() {
    u64 vdst; b32 vaddr; u64 vdata;
    __asm__ volatile("ds_add_rtn_u64 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_add_u32() {
    u32 vaddr; u32 vdata;
    __asm__ volatile("ds_add_u32 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_add_u64() {
    b32 vaddr; u64 vdata;
    __asm__ volatile("ds_add_u64 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_and_b32() {
    b32 vaddr; b32 vdata;
    __asm__ volatile("ds_and_b32 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_and_b64() {
    b32 vaddr; b64 vdata;
    __asm__ volatile("ds_and_b64 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_and_rtn_b32() {
    b32 vdst; b32 vaddr; b32 vdata;
    __asm__ volatile("ds_and_rtn_b32 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_and_rtn_b64() {
    b64 vdst; b32 vaddr; b64 vdata;
    __asm__ volatile("ds_and_rtn_b64 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_append() {
    b32 vdst;
    __asm__ volatile("ds_append %0 \n" : "=v"(vdst) : );
}

__global__ void ds_bpermute_b32() {
    b32 vdst; b32 vaddr; b32 vdata;
    __asm__ volatile("ds_bpermute_b32 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_cmpst_b32() {
    b32 vaddr; b32 vdata0; b32 vdata1;
    __asm__ volatile("ds_cmpst_b32 %0, %1, %2 \n" :  : "v"(vaddr), "v"(vdata0), "v"(vdata1));
}

__global__ void ds_cmpst_b64() {
    b32 vaddr; b64 vdata0; b64 vdata1;
    __asm__ volatile("ds_cmpst_b64 %0, %1, %2 \n" :  : "v"(vaddr), "v"(vdata0), "v"(vdata1));
}

__global__ void ds_cmpst_f32() {
    f32 vaddr; f32 vdata0; f32 vdata1;
    __asm__ volatile("ds_cmpst_f32 %0, %1, %2 \n" :  : "v"(vaddr), "v"(vdata0), "v"(vdata1));
}

__global__ void ds_cmpst_f64() {
    b32 vaddr; f64 vdata0; f64 vdata1;
    __asm__ volatile("ds_cmpst_f64 %0, %1, %2 \n" :  : "v"(vaddr), "v"(vdata0), "v"(vdata1));
}

__global__ void ds_cmpst_rtn_b32() {
    b32 vdst; b32 vaddr; b32 vdata0; b32 vdata1;
    __asm__ volatile("ds_cmpst_rtn_b32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata0), "v"(vdata1));
}

__global__ void ds_cmpst_rtn_b64() {
    b64 vdst; b32 vaddr; b64 vdata0; b64 vdata1;
    __asm__ volatile("ds_cmpst_rtn_b64 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata0), "v"(vdata1));
}

__global__ void ds_cmpst_rtn_f32() {
    f32 vdst; f32 vaddr; f32 vdata0; f32 vdata1;
    __asm__ volatile("ds_cmpst_rtn_f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata0), "v"(vdata1));
}

__global__ void ds_cmpst_rtn_f64() {
    f64 vdst; b32 vaddr; f64 vdata0; f64 vdata1;
    __asm__ volatile("ds_cmpst_rtn_f64 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata0), "v"(vdata1));
}

__global__ void ds_condxchg32_rtn_b64() {
    b64 vdst; b32 vaddr; b64 vdata;
    __asm__ volatile("ds_condxchg32_rtn_b64 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_consume() {
    b32 vdst;
    __asm__ volatile("ds_consume %0 \n" : "=v"(vdst) : );
}

__global__ void ds_dec_rtn_u32() {
    u32 vdst; u32 vaddr; u32 vdata;
    __asm__ volatile("ds_dec_rtn_u32 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_dec_rtn_u64() {
    u64 vdst; b32 vaddr; u64 vdata;
    __asm__ volatile("ds_dec_rtn_u64 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_dec_u32() {
    u32 vaddr; u32 vdata;
    __asm__ volatile("ds_dec_u32 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_dec_u64() {
    b32 vaddr; u64 vdata;
    __asm__ volatile("ds_dec_u64 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_gws_barrier() {
    b32 vdata;
    __asm__ volatile("ds_gws_barrier %0 gds\n" :  : "v"(vdata));
}

__global__ void ds_gws_init() {
    b32 vdata;
    __asm__ volatile("ds_gws_init %0 gds\n" :  : "v"(vdata));
}

__global__ void ds_gws_sema_br() {
    b32 vdata;
    __asm__ volatile("ds_gws_sema_br %0 gds\n" :  : "v"(vdata));
}

__global__ void ds_gws_sema_p() {
    ;
    __asm__ volatile("ds_gws_sema_p  gds\n" :  : );
}

__global__ void ds_gws_sema_release_all() {
    ;
    __asm__ volatile("ds_gws_sema_release_all  gds\n" :  : );
}

__global__ void ds_gws_sema_v() {
    ;
    __asm__ volatile("ds_gws_sema_v  gds\n" :  : );
}

__global__ void ds_inc_rtn_u32() {
    u32 vdst; u32 vaddr; u32 vdata;
    __asm__ volatile("ds_inc_rtn_u32 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_inc_rtn_u64() {
    u64 vdst; b32 vaddr; u64 vdata;
    __asm__ volatile("ds_inc_rtn_u64 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_inc_u32() {
    u32 vaddr; u32 vdata;
    __asm__ volatile("ds_inc_u32 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_inc_u64() {
    b32 vaddr; u64 vdata;
    __asm__ volatile("ds_inc_u64 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_max_f32() {
    f32 vaddr; f32 vdata;
    __asm__ volatile("ds_max_f32 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_max_f64() {
    b32 vaddr; f64 vdata;
    __asm__ volatile("ds_max_f64 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_max_i32() {
    i32 vaddr; i32 vdata;
    __asm__ volatile("ds_max_i32 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_max_i64() {
    b32 vaddr; i64 vdata;
    __asm__ volatile("ds_max_i64 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_max_rtn_f32() {
    f32 vdst; f32 vaddr; f32 vdata;
    __asm__ volatile("ds_max_rtn_f32 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_max_rtn_f64() {
    f64 vdst; b32 vaddr; f64 vdata;
    __asm__ volatile("ds_max_rtn_f64 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_max_rtn_i32() {
    i32 vdst; i32 vaddr; i32 vdata;
    __asm__ volatile("ds_max_rtn_i32 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_max_rtn_i64() {
    i64 vdst; b32 vaddr; i64 vdata;
    __asm__ volatile("ds_max_rtn_i64 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_max_rtn_u32() {
    u32 vdst; u32 vaddr; u32 vdata;
    __asm__ volatile("ds_max_rtn_u32 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_max_rtn_u64() {
    u64 vdst; b32 vaddr; u64 vdata;
    __asm__ volatile("ds_max_rtn_u64 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_max_u32() {
    u32 vaddr; u32 vdata;
    __asm__ volatile("ds_max_u32 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_max_u64() {
    b32 vaddr; u64 vdata;
    __asm__ volatile("ds_max_u64 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_min_f32() {
    f32 vaddr; f32 vdata;
    __asm__ volatile("ds_min_f32 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_min_f64() {
    b32 vaddr; f64 vdata;
    __asm__ volatile("ds_min_f64 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_min_i32() {
    i32 vaddr; i32 vdata;
    __asm__ volatile("ds_min_i32 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_min_i64() {
    b32 vaddr; i64 vdata;
    __asm__ volatile("ds_min_i64 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_min_rtn_f32() {
    f32 vdst; f32 vaddr; f32 vdata;
    __asm__ volatile("ds_min_rtn_f32 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_min_rtn_f64() {
    f64 vdst; b32 vaddr; f64 vdata;
    __asm__ volatile("ds_min_rtn_f64 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_min_rtn_i32() {
    i32 vdst; i32 vaddr; i32 vdata;
    __asm__ volatile("ds_min_rtn_i32 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_min_rtn_i64() {
    i64 vdst; b32 vaddr; i64 vdata;
    __asm__ volatile("ds_min_rtn_i64 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_min_rtn_u32() {
    u32 vdst; u32 vaddr; u32 vdata;
    __asm__ volatile("ds_min_rtn_u32 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_min_rtn_u64() {
    u64 vdst; b32 vaddr; u64 vdata;
    __asm__ volatile("ds_min_rtn_u64 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_min_u32() {
    u32 vaddr; u32 vdata;
    __asm__ volatile("ds_min_u32 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_min_u64() {
    b32 vaddr; u64 vdata;
    __asm__ volatile("ds_min_u64 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_mskor_b32() {
    b32 vaddr; b32 vdata0; b32 vdata1;
    __asm__ volatile("ds_mskor_b32 %0, %1, %2 \n" :  : "v"(vaddr), "v"(vdata0), "v"(vdata1));
}

__global__ void ds_mskor_b64() {
    b32 vaddr; b64 vdata0; b64 vdata1;
    __asm__ volatile("ds_mskor_b64 %0, %1, %2 \n" :  : "v"(vaddr), "v"(vdata0), "v"(vdata1));
}

__global__ void ds_mskor_rtn_b32() {
    b32 vdst; b32 vaddr; b32 vdata0; b32 vdata1;
    __asm__ volatile("ds_mskor_rtn_b32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata0), "v"(vdata1));
}

__global__ void ds_mskor_rtn_b64() {
    b64 vdst; b32 vaddr; b64 vdata0; b64 vdata1;
    __asm__ volatile("ds_mskor_rtn_b64 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata0), "v"(vdata1));
}

__global__ void ds_nop() {
    ;
    __asm__ volatile("ds_nop  \n" :  : );
}

__global__ void ds_or_b32() {
    b32 vaddr; b32 vdata;
    __asm__ volatile("ds_or_b32 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_or_b64() {
    b32 vaddr; b64 vdata;
    __asm__ volatile("ds_or_b64 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_or_rtn_b32() {
    b32 vdst; b32 vaddr; b32 vdata;
    __asm__ volatile("ds_or_rtn_b32 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_or_rtn_b64() {
    b64 vdst; b32 vaddr; b64 vdata;
    __asm__ volatile("ds_or_rtn_b64 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_permute_b32() {
    b32 vdst; b32 vaddr; b32 vdata;
    __asm__ volatile("ds_permute_b32 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_read2_b32() {
    b32x2 vdst; b32 vaddr;
    __asm__ volatile("ds_read2_b32 %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void ds_read2_b64() {
    b64x2 vdst; b32 vaddr;
    __asm__ volatile("ds_read2_b64 %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void ds_read2st64_b32() {
    b32x2 vdst; b32 vaddr;
    __asm__ volatile("ds_read2st64_b32 %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void ds_read2st64_b64() {
    b64x2 vdst; b32 vaddr;
    __asm__ volatile("ds_read2st64_b64 %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void ds_read_addtid_b32() {
    b32 vdst;
    __asm__ volatile("ds_read_addtid_b32 %0 \n" : "=v"(vdst) : );
}

__global__ void ds_read_b128() {
    b128 vdst; b32 vaddr;
    __asm__ volatile("ds_read_b128 %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void ds_read_b32() {
    b32 vdst; b32 vaddr;
    __asm__ volatile("ds_read_b32 %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void ds_read_b64() {
    b64 vdst; b32 vaddr;
    __asm__ volatile("ds_read_b64 %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void ds_read_b96() {
    b96 vdst; b32 vaddr;
    __asm__ volatile("ds_read_b96 %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void ds_read_i16() {
    i16 vdst; i16 vaddr;
    __asm__ volatile("ds_read_i16 %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void ds_read_i8() {
    i8 vdst; i8 vaddr;
    __asm__ volatile("ds_read_i8 %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void ds_read_i8_d16() {
    b32 vdst; b32 vaddr;
    __asm__ volatile("ds_read_i8_d16 %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void ds_read_i8_d16_hi() {
    b32 vdst; b32 vaddr;
    __asm__ volatile("ds_read_i8_d16_hi %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void ds_read_u16() {
    u16 vdst; u16 vaddr;
    __asm__ volatile("ds_read_u16 %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void ds_read_u16_d16() {
    b32 vdst; b32 vaddr;
    __asm__ volatile("ds_read_u16_d16 %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void ds_read_u16_d16_hi() {
    b32 vdst; b32 vaddr;
    __asm__ volatile("ds_read_u16_d16_hi %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void ds_read_u8() {
    u8 vdst; u8 vaddr;
    __asm__ volatile("ds_read_u8 %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void ds_read_u8_d16() {
    b32 vdst; b32 vaddr;
    __asm__ volatile("ds_read_u8_d16 %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void ds_read_u8_d16_hi() {
    b32 vdst; b32 vaddr;
    __asm__ volatile("ds_read_u8_d16_hi %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void ds_rsub_rtn_u32() {
    u32 vdst; u32 vaddr; u32 vdata;
    __asm__ volatile("ds_rsub_rtn_u32 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_rsub_rtn_u64() {
    u64 vdst; b32 vaddr; u64 vdata;
    __asm__ volatile("ds_rsub_rtn_u64 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_rsub_u32() {
    u32 vaddr; u32 vdata;
    __asm__ volatile("ds_rsub_u32 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_rsub_u64() {
    b32 vaddr; u64 vdata;
    __asm__ volatile("ds_rsub_u64 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_sub_rtn_u32() {
    u32 vdst; u32 vaddr; u32 vdata;
    __asm__ volatile("ds_sub_rtn_u32 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_sub_rtn_u64() {
    u64 vdst; b32 vaddr; u64 vdata;
    __asm__ volatile("ds_sub_rtn_u64 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_sub_u32() {
    u32 vaddr; u32 vdata;
    __asm__ volatile("ds_sub_u32 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_sub_u64() {
    b32 vaddr; u64 vdata;
    __asm__ volatile("ds_sub_u64 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_swizzle_b32() {
    b32 vdst; b32 vaddr;
    __asm__ volatile("ds_swizzle_b32 %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void ds_wrap_rtn_b32() {
    b32 vdst; b32 vaddr; b32 vdata0; b32 vdata1;
    __asm__ volatile("ds_wrap_rtn_b32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata0), "v"(vdata1));
}

__global__ void ds_write2_b32() {
    b32 vaddr; b32 vdata0; b32 vdata1;
    __asm__ volatile("ds_write2_b32 %0, %1, %2 \n" :  : "v"(vaddr), "v"(vdata0), "v"(vdata1));
}

__global__ void ds_write2_b64() {
    b32 vaddr; b64 vdata0; b64 vdata1;
    __asm__ volatile("ds_write2_b64 %0, %1, %2 \n" :  : "v"(vaddr), "v"(vdata0), "v"(vdata1));
}

__global__ void ds_write2st64_b32() {
    b32 vaddr; b32 vdata0; b32 vdata1;
    __asm__ volatile("ds_write2st64_b32 %0, %1, %2 \n" :  : "v"(vaddr), "v"(vdata0), "v"(vdata1));
}

__global__ void ds_write2st64_b64() {
    b32 vaddr; b64 vdata0; b64 vdata1;
    __asm__ volatile("ds_write2st64_b64 %0, %1, %2 \n" :  : "v"(vaddr), "v"(vdata0), "v"(vdata1));
}

__global__ void ds_write_addtid_b32() {
    b32 vdata;
    __asm__ volatile("ds_write_addtid_b32 %0 \n" :  : "v"(vdata));
}

__global__ void ds_write_b128() {
    b32 vaddr; b128 vdata;
    __asm__ volatile("ds_write_b128 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_write_b16() {
    b16 vaddr; b16 vdata;
    __asm__ volatile("ds_write_b16 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_write_b16_d16_hi() {
    b32 vaddr; b32 vdata;
    __asm__ volatile("ds_write_b16_d16_hi %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_write_b32() {
    b32 vaddr; b32 vdata;
    __asm__ volatile("ds_write_b32 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_write_b64() {
    b32 vaddr; b64 vdata;
    __asm__ volatile("ds_write_b64 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_write_b8() {
    b8 vaddr; b8 vdata;
    __asm__ volatile("ds_write_b8 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_write_b8_d16_hi() {
    b32 vaddr; b32 vdata;
    __asm__ volatile("ds_write_b8_d16_hi %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_write_b96() {
    b32 vaddr; b96 vdata;
    __asm__ volatile("ds_write_b96 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_wrxchg2_rtn_b32() {
    b32x2 vdst; b32 vaddr; b32 vdata0; b32 vdata1;
    __asm__ volatile("ds_wrxchg2_rtn_b32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata0), "v"(vdata1));
}

__global__ void ds_wrxchg2_rtn_b64() {
    b64x2 vdst; b32 vaddr; b64 vdata0; b64 vdata1;
    __asm__ volatile("ds_wrxchg2_rtn_b64 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata0), "v"(vdata1));
}

__global__ void ds_wrxchg2st64_rtn_b32() {
    b32x2 vdst; b32 vaddr; b32 vdata0; b32 vdata1;
    __asm__ volatile("ds_wrxchg2st64_rtn_b32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata0), "v"(vdata1));
}

__global__ void ds_wrxchg2st64_rtn_b64() {
    b64x2 vdst; b32 vaddr; b64 vdata0; b64 vdata1;
    __asm__ volatile("ds_wrxchg2st64_rtn_b64 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata0), "v"(vdata1));
}

__global__ void ds_wrxchg_rtn_b32() {
    b32 vdst; b32 vaddr; b32 vdata;
    __asm__ volatile("ds_wrxchg_rtn_b32 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_wrxchg_rtn_b64() {
    b64 vdst; b32 vaddr; b64 vdata;
    __asm__ volatile("ds_wrxchg_rtn_b64 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_xor_b32() {
    b32 vaddr; b32 vdata;
    __asm__ volatile("ds_xor_b32 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_xor_b64() {
    b32 vaddr; b64 vdata;
    __asm__ volatile("ds_xor_b64 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void ds_xor_rtn_b32() {
    b32 vdst; b32 vaddr; b32 vdata;
    __asm__ volatile("ds_xor_rtn_b32 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void ds_xor_rtn_b64() {
    b64 vdst; b32 vaddr; b64 vdata;
    __asm__ volatile("ds_xor_rtn_b64 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_add() {
    b32 vdst; b64 vaddr; b32 vdata;
    __asm__ volatile("flat_atomic_add %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_add_f64() {
    f64 vdst; f64 vaddr; f64 vdata;
    __asm__ volatile("flat_atomic_add_f64 %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_add_x2() {
    b64 vdst; b64 vaddr; b64 vdata;
    __asm__ volatile("flat_atomic_add_x2 %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_and() {
    b32 vdst; b64 vaddr; b32 vdata;
    __asm__ volatile("flat_atomic_and %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_and_x2() {
    b64 vdst; b64 vaddr; b64 vdata;
    __asm__ volatile("flat_atomic_and_x2 %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_cmpswap() {
    b32 vdst; b64 vaddr; b32x2 vdata;
    __asm__ volatile("flat_atomic_cmpswap %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_cmpswap_x2() {
    b64 vdst; b64 vaddr; b64x2 vdata;
    __asm__ volatile("flat_atomic_cmpswap_x2 %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_dec() {
    u32 vdst; b64 vaddr; u32 vdata;
    __asm__ volatile("flat_atomic_dec %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_dec_x2() {
    u64 vdst; b64 vaddr; u64 vdata;
    __asm__ volatile("flat_atomic_dec_x2 %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_inc() {
    u32 vdst; b64 vaddr; u32 vdata;
    __asm__ volatile("flat_atomic_inc %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_inc_x2() {
    u64 vdst; b64 vaddr; u64 vdata;
    __asm__ volatile("flat_atomic_inc_x2 %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_max_f64() {
    f64 vdst; f64 vaddr; f64 vdata;
    __asm__ volatile("flat_atomic_max_f64 %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_min_f64() {
    f64 vdst; f64 vaddr; f64 vdata;
    __asm__ volatile("flat_atomic_min_f64 %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_or() {
    b32 vdst; b64 vaddr; b32 vdata;
    __asm__ volatile("flat_atomic_or %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_or_x2() {
    b64 vdst; b64 vaddr; b64 vdata;
    __asm__ volatile("flat_atomic_or_x2 %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_smax() {
    i32 vdst; b64 vaddr; i32 vdata;
    __asm__ volatile("flat_atomic_smax %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_smax_x2() {
    i64 vdst; b64 vaddr; i64 vdata;
    __asm__ volatile("flat_atomic_smax_x2 %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_smin() {
    i32 vdst; b64 vaddr; i32 vdata;
    __asm__ volatile("flat_atomic_smin %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_smin_x2() {
    i64 vdst; b64 vaddr; i64 vdata;
    __asm__ volatile("flat_atomic_smin_x2 %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_sub() {
    b32 vdst; b64 vaddr; b32 vdata;
    __asm__ volatile("flat_atomic_sub %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_sub_x2() {
    b64 vdst; b64 vaddr; b64 vdata;
    __asm__ volatile("flat_atomic_sub_x2 %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_swap() {
    b32 vdst; b64 vaddr; b32 vdata;
    __asm__ volatile("flat_atomic_swap %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_swap_x2() {
    b64 vdst; b64 vaddr; b64 vdata;
    __asm__ volatile("flat_atomic_swap_x2 %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_umax() {
    u32 vdst; b64 vaddr; u32 vdata;
    __asm__ volatile("flat_atomic_umax %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_umax_x2() {
    u64 vdst; b64 vaddr; u64 vdata;
    __asm__ volatile("flat_atomic_umax_x2 %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_umin() {
    u32 vdst; b64 vaddr; u32 vdata;
    __asm__ volatile("flat_atomic_umin %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_umin_x2() {
    u64 vdst; b64 vaddr; u64 vdata;
    __asm__ volatile("flat_atomic_umin_x2 %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_xor() {
    b32 vdst; b64 vaddr; b32 vdata;
    __asm__ volatile("flat_atomic_xor %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_atomic_xor_x2() {
    b64 vdst; b64 vaddr; b64 vdata;
    __asm__ volatile("flat_atomic_xor_x2 %0, %1, %2 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata));
}

__global__ void flat_load_dword() {
    b32 vdst; b64 vaddr;
    __asm__ volatile("flat_load_dword %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void flat_load_dwordx2() {
    b64 vdst; b64 vaddr;
    __asm__ volatile("flat_load_dwordx2 %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void flat_load_dwordx3() {
    b96 vdst; b64 vaddr;
    __asm__ volatile("flat_load_dwordx3 %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void flat_load_dwordx4() {
    b128 vdst; b64 vaddr;
    __asm__ volatile("flat_load_dwordx4 %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void flat_load_sbyte() {
    b32 vdst; b64 vaddr;
    __asm__ volatile("flat_load_sbyte %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void flat_load_sbyte_d16() {
    b32 vdst; b64 vaddr;
    __asm__ volatile("flat_load_sbyte_d16 %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void flat_load_sbyte_d16_hi() {
    b32 vdst; b64 vaddr;
    __asm__ volatile("flat_load_sbyte_d16_hi %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void flat_load_short_d16() {
    b32 vdst; b64 vaddr;
    __asm__ volatile("flat_load_short_d16 %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void flat_load_short_d16_hi() {
    b32 vdst; b64 vaddr;
    __asm__ volatile("flat_load_short_d16_hi %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void flat_load_sshort() {
    b32 vdst; b64 vaddr;
    __asm__ volatile("flat_load_sshort %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void flat_load_ubyte() {
    b32 vdst; b64 vaddr;
    __asm__ volatile("flat_load_ubyte %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void flat_load_ubyte_d16() {
    b32 vdst; b64 vaddr;
    __asm__ volatile("flat_load_ubyte_d16 %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void flat_load_ubyte_d16_hi() {
    b32 vdst; b64 vaddr;
    __asm__ volatile("flat_load_ubyte_d16_hi %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void flat_load_ushort() {
    b32 vdst; b64 vaddr;
    __asm__ volatile("flat_load_ushort %0, %1 \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void flat_store_byte() {
    b64 vaddr; b32 vdata;
    __asm__ volatile("flat_store_byte %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void flat_store_byte_d16_hi() {
    b64 vaddr; b32 vdata;
    __asm__ volatile("flat_store_byte_d16_hi %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void flat_store_dword() {
    b64 vaddr; b32 vdata;
    __asm__ volatile("flat_store_dword %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void flat_store_dwordx2() {
    b64 vaddr; b64 vdata;
    __asm__ volatile("flat_store_dwordx2 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void flat_store_dwordx3() {
    b64 vaddr; b96 vdata;
    __asm__ volatile("flat_store_dwordx3 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void flat_store_dwordx4() {
    b64 vaddr; b128 vdata;
    __asm__ volatile("flat_store_dwordx4 %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void flat_store_short() {
    b64 vaddr; b32 vdata;
    __asm__ volatile("flat_store_short %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void flat_store_short_d16_hi() {
    b64 vaddr; b32 vdata;
    __asm__ volatile("flat_store_short_d16_hi %0, %1 \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void global_atomic_add() {
    b32 vdst; b32 vaddr; b32 vdata; b64 saddr;
    __asm__ volatile("global_atomic_add %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_add_f32() {
    f32 vdst; f32 vaddr; f32 vdata; b64 saddr;
    __asm__ volatile("global_atomic_add_f32 %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_add_f64() {
    f64 vdst; b32 vaddr; f64 vdata; f64 saddr;
    __asm__ volatile("global_atomic_add_f64 %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_add_x2() {
    b64 vdst; b32 vaddr; b64 vdata; b64 saddr;
    __asm__ volatile("global_atomic_add_x2 %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_and() {
    b32 vdst; b32 vaddr; b32 vdata; b64 saddr;
    __asm__ volatile("global_atomic_and %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_and_x2() {
    b64 vdst; b32 vaddr; b64 vdata; b64 saddr;
    __asm__ volatile("global_atomic_and_x2 %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_cmpswap() {
    b32 vdst; b32 vaddr; b32x2 vdata; b64 saddr;
    __asm__ volatile("global_atomic_cmpswap %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_cmpswap_x2() {
    b64 vdst; b32 vaddr; b64x2 vdata; b64 saddr;
    __asm__ volatile("global_atomic_cmpswap_x2 %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_dec() {
    u32 vdst; b32 vaddr; u32 vdata; b64 saddr;
    __asm__ volatile("global_atomic_dec %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_dec_x2() {
    u64 vdst; b32 vaddr; u64 vdata; b64 saddr;
    __asm__ volatile("global_atomic_dec_x2 %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_inc() {
    u32 vdst; b32 vaddr; u32 vdata; b64 saddr;
    __asm__ volatile("global_atomic_inc %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_inc_x2() {
    u64 vdst; b32 vaddr; u64 vdata; b64 saddr;
    __asm__ volatile("global_atomic_inc_x2 %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_max_f64() {
    f64 vdst; b32 vaddr; f64 vdata; f64 saddr;
    __asm__ volatile("global_atomic_max_f64 %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_min_f64() {
    f64 vdst; b32 vaddr; f64 vdata; f64 saddr;
    __asm__ volatile("global_atomic_min_f64 %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_or() {
    b32 vdst; b32 vaddr; b32 vdata; b64 saddr;
    __asm__ volatile("global_atomic_or %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_or_x2() {
    b64 vdst; b32 vaddr; b64 vdata; b64 saddr;
    __asm__ volatile("global_atomic_or_x2 %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_pk_add_f16() {
    f16 vdst; f16 vaddr; f16 vdata; b64 saddr;
    __asm__ volatile("global_atomic_pk_add_f16 %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_smax() {
    i32 vdst; b32 vaddr; i32 vdata; b64 saddr;
    __asm__ volatile("global_atomic_smax %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_smax_x2() {
    i64 vdst; b32 vaddr; i64 vdata; b64 saddr;
    __asm__ volatile("global_atomic_smax_x2 %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_smin() {
    i32 vdst; b32 vaddr; i32 vdata; b64 saddr;
    __asm__ volatile("global_atomic_smin %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_smin_x2() {
    i64 vdst; b32 vaddr; i64 vdata; b64 saddr;
    __asm__ volatile("global_atomic_smin_x2 %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_sub() {
    b32 vdst; b32 vaddr; b32 vdata; b64 saddr;
    __asm__ volatile("global_atomic_sub %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_sub_x2() {
    b64 vdst; b32 vaddr; b64 vdata; b64 saddr;
    __asm__ volatile("global_atomic_sub_x2 %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_swap() {
    b32 vdst; b32 vaddr; b32 vdata; b64 saddr;
    __asm__ volatile("global_atomic_swap %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_swap_x2() {
    b64 vdst; b32 vaddr; b64 vdata; b64 saddr;
    __asm__ volatile("global_atomic_swap_x2 %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_umax() {
    u32 vdst; b32 vaddr; u32 vdata; b64 saddr;
    __asm__ volatile("global_atomic_umax %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_umax_x2() {
    u64 vdst; b32 vaddr; u64 vdata; b64 saddr;
    __asm__ volatile("global_atomic_umax_x2 %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_umin() {
    u32 vdst; b32 vaddr; u32 vdata; b64 saddr;
    __asm__ volatile("global_atomic_umin %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_umin_x2() {
    u64 vdst; b32 vaddr; u64 vdata; b64 saddr;
    __asm__ volatile("global_atomic_umin_x2 %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_xor() {
    b32 vdst; b32 vaddr; b32 vdata; b64 saddr;
    __asm__ volatile("global_atomic_xor %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_atomic_xor_x2() {
    b64 vdst; b32 vaddr; b64 vdata; b64 saddr;
    __asm__ volatile("global_atomic_xor_x2 %0, %1, %2, %3 glc\n" : "=v"(vdst) : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_load_dword() {
    b32 vdst; b32 vaddr; b64 saddr;
    __asm__ volatile("global_load_dword %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "s"(saddr));
}

__global__ void global_load_dwordx2() {
    b64 vdst; b32 vaddr; b64 saddr;
    __asm__ volatile("global_load_dwordx2 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "s"(saddr));
}

__global__ void global_load_dwordx3() {
    b96 vdst; b32 vaddr; b64 saddr;
    __asm__ volatile("global_load_dwordx3 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "s"(saddr));
}

__global__ void global_load_dwordx4() {
    b128 vdst; b32 vaddr; b64 saddr;
    __asm__ volatile("global_load_dwordx4 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "s"(saddr));
}

__global__ void global_load_sbyte() {
    b32 vdst; b32 vaddr; b64 saddr;
    __asm__ volatile("global_load_sbyte %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "s"(saddr));
}

__global__ void global_load_sbyte_d16() {
    b32 vdst; b32 vaddr; b64 saddr;
    __asm__ volatile("global_load_sbyte_d16 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "s"(saddr));
}

__global__ void global_load_sbyte_d16_hi() {
    b32 vdst; b32 vaddr; b64 saddr;
    __asm__ volatile("global_load_sbyte_d16_hi %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "s"(saddr));
}

__global__ void global_load_short_d16() {
    b32 vdst; b32 vaddr; b64 saddr;
    __asm__ volatile("global_load_short_d16 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "s"(saddr));
}

__global__ void global_load_short_d16_hi() {
    b32 vdst; b32 vaddr; b64 saddr;
    __asm__ volatile("global_load_short_d16_hi %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "s"(saddr));
}

__global__ void global_load_sshort() {
    b32 vdst; b32 vaddr; b64 saddr;
    __asm__ volatile("global_load_sshort %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "s"(saddr));
}

__global__ void global_load_ubyte() {
    b32 vdst; b32 vaddr; b64 saddr;
    __asm__ volatile("global_load_ubyte %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "s"(saddr));
}

__global__ void global_load_ubyte_d16() {
    b32 vdst; b32 vaddr; b64 saddr;
    __asm__ volatile("global_load_ubyte_d16 %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "s"(saddr));
}

__global__ void global_load_ubyte_d16_hi() {
    b32 vdst; b32 vaddr; b64 saddr;
    __asm__ volatile("global_load_ubyte_d16_hi %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "s"(saddr));
}

__global__ void global_load_ushort() {
    b32 vdst; b32 vaddr; b64 saddr;
    __asm__ volatile("global_load_ushort %0, %1, %2 \n" : "=v"(vdst) : "v"(vaddr), "s"(saddr));
}

__global__ void global_store_byte() {
    b32 vaddr; b32 vdata; b64 saddr;
    __asm__ volatile("global_store_byte %0, %1, %2 \n" :  : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_store_byte_d16_hi() {
    b32 vaddr; b32 vdata; b64 saddr;
    __asm__ volatile("global_store_byte_d16_hi %0, %1, %2 \n" :  : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_store_dword() {
    b32 vaddr; b32 vdata; b64 saddr;
    __asm__ volatile("global_store_dword %0, %1, %2 \n" :  : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_store_dwordx2() {
    b32 vaddr; b64 vdata; b64 saddr;
    __asm__ volatile("global_store_dwordx2 %0, %1, %2 \n" :  : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_store_dwordx3() {
    b32 vaddr; b96 vdata; b64 saddr;
    __asm__ volatile("global_store_dwordx3 %0, %1, %2 \n" :  : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_store_dwordx4() {
    b32 vaddr; b128 vdata; b64 saddr;
    __asm__ volatile("global_store_dwordx4 %0, %1, %2 \n" :  : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_store_short() {
    b32 vaddr; b32 vdata; b64 saddr;
    __asm__ volatile("global_store_short %0, %1, %2 \n" :  : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void global_store_short_d16_hi() {
    b32 vaddr; b32 vdata; b64 saddr;
    __asm__ volatile("global_store_short_d16_hi %0, %1, %2 \n" :  : "v"(vaddr), "v"(vdata), "s"(saddr));
}

__global__ void scratch_load_dword() {
    b32 vdst; b32 vaddr;
    __asm__ volatile("scratch_load_dword %0, %1, off \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void scratch_load_dwordx2() {
    b64 vdst; b32 vaddr;
    __asm__ volatile("scratch_load_dwordx2 %0, %1, off \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void scratch_load_dwordx3() {
    b96 vdst; b32 vaddr;
    __asm__ volatile("scratch_load_dwordx3 %0, %1, off \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void scratch_load_dwordx4() {
    b128 vdst; b32 vaddr;
    __asm__ volatile("scratch_load_dwordx4 %0, %1, off \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void scratch_load_sbyte() {
    b32 vdst; b32 vaddr;
    __asm__ volatile("scratch_load_sbyte %0, %1, off \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void scratch_load_sbyte_d16() {
    b32 vdst; b32 vaddr;
    __asm__ volatile("scratch_load_sbyte_d16 %0, %1, off \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void scratch_load_sbyte_d16_hi() {
    b32 vdst; b32 vaddr;
    __asm__ volatile("scratch_load_sbyte_d16_hi %0, %1, off \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void scratch_load_short_d16() {
    b32 vdst; b32 vaddr;
    __asm__ volatile("scratch_load_short_d16 %0, %1, off \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void scratch_load_short_d16_hi() {
    b32 vdst; b32 vaddr;
    __asm__ volatile("scratch_load_short_d16_hi %0, %1, off \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void scratch_load_sshort() {
    b32 vdst; b32 vaddr;
    __asm__ volatile("scratch_load_sshort %0, %1, off \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void scratch_load_ubyte() {
    b32 vdst; b32 vaddr;
    __asm__ volatile("scratch_load_ubyte %0, %1, off \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void scratch_load_ubyte_d16() {
    b32 vdst; b32 vaddr;
    __asm__ volatile("scratch_load_ubyte_d16 %0, %1, off \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void scratch_load_ubyte_d16_hi() {
    b32 vdst; b32 vaddr;
    __asm__ volatile("scratch_load_ubyte_d16_hi %0, %1, off \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void scratch_load_ushort() {
    b32 vdst; b32 vaddr;
    __asm__ volatile("scratch_load_ushort %0, %1, off \n" : "=v"(vdst) : "v"(vaddr));
}

__global__ void scratch_store_byte() {
    b32 vaddr; b32 vdata;
    __asm__ volatile("scratch_store_byte %0, %1, off \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void scratch_store_byte_d16_hi() {
    b32 vaddr; b32 vdata;
    __asm__ volatile("scratch_store_byte_d16_hi %0, %1, off \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void scratch_store_dword() {
    b32 vaddr; b32 vdata;
    __asm__ volatile("scratch_store_dword %0, %1, off \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void scratch_store_dwordx2() {
    b32 vaddr; b64 vdata;
    __asm__ volatile("scratch_store_dwordx2 %0, %1, off \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void scratch_store_dwordx3() {
    b32 vaddr; b96 vdata;
    __asm__ volatile("scratch_store_dwordx3 %0, %1, off \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void scratch_store_dwordx4() {
    b32 vaddr; b128 vdata;
    __asm__ volatile("scratch_store_dwordx4 %0, %1, off \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void scratch_store_short() {
    b32 vaddr; b32 vdata;
    __asm__ volatile("scratch_store_short %0, %1, off \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void scratch_store_short_d16_hi() {
    b32 vaddr; b32 vdata;
    __asm__ volatile("scratch_store_short_d16_hi %0, %1, off \n" :  : "v"(vaddr), "v"(vdata));
}

__global__ void s_atc_probe() {
    b64 sbase; b32 soffset;
    __asm__ volatile("s_atc_probe %0, %1, %2 \n" :  : "i"(0), "s"(sbase), "s"(soffset));
}

__global__ void s_atc_probe_buffer() {
    b128 sbase; b32 soffset;
    __asm__ volatile("s_atc_probe_buffer %0, %1, %2 \n" :  : "i"(0), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_add() {
    b32 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_add %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_add_x2() {
    b64 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_add_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_and() {
    b32 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_and %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_and_x2() {
    b64 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_and_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_cmpswap() {
    b32x2 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_cmpswap %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_cmpswap_x2() {
    b64x2 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_cmpswap_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_dec() {
    u32 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_dec %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_dec_x2() {
    u64 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_dec_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_inc() {
    u32 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_inc %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_inc_x2() {
    u64 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_inc_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_or() {
    b32 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_or %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_or_x2() {
    b64 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_or_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_smax() {
    i32 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_smax %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_smax_x2() {
    i64 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_smax_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_smin() {
    i32 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_smin %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_smin_x2() {
    i64 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_smin_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_sub() {
    b32 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_sub %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_sub_x2() {
    b64 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_sub_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_swap() {
    b32 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_swap %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_swap_x2() {
    b64 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_swap_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_umax() {
    u32 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_umax %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_umax_x2() {
    u64 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_umax_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_umin() {
    u32 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_umin %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_umin_x2() {
    u64 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_umin_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_xor() {
    b32 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_xor %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_atomic_xor_x2() {
    b64 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_atomic_xor_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_add() {
    b32 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_add %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_add_x2() {
    b64 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_add_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_and() {
    b32 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_and %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_and_x2() {
    b64 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_and_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_cmpswap() {
    b32x2 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_cmpswap %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_cmpswap_x2() {
    b64x2 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_cmpswap_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_dec() {
    u32 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_dec %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_dec_x2() {
    u64 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_dec_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_inc() {
    u32 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_inc %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_inc_x2() {
    u64 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_inc_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_or() {
    b32 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_or %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_or_x2() {
    b64 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_or_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_smax() {
    i32 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_smax %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_smax_x2() {
    i64 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_smax_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_smin() {
    i32 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_smin %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_smin_x2() {
    i64 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_smin_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_sub() {
    b32 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_sub %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_sub_x2() {
    b64 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_sub_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_swap() {
    b32 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_swap %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_swap_x2() {
    b64 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_swap_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_umax() {
    u32 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_umax %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_umax_x2() {
    u64 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_umax_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_umin() {
    u32 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_umin %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_umin_x2() {
    u64 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_umin_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_xor() {
    b32 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_xor %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_atomic_xor_x2() {
    b64 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_atomic_xor_x2 %0, %1, %2 glc\n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_load_dword() {
    b32 sdst; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_load_dword %0, %1, %2 \n" : "=s"(sdst) : "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_load_dwordx16() {
    b512 sdst; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_load_dwordx16 %0, %1, %2 \n" : "=s"(sdst) : "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_load_dwordx2() {
    b64 sdst; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_load_dwordx2 %0, %1, %2 \n" : "=s"(sdst) : "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_load_dwordx4() {
    b128 sdst; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_load_dwordx4 %0, %1, %2 \n" : "=s"(sdst) : "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_load_dwordx8() {
    b256 sdst; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_load_dwordx8 %0, %1, %2 \n" : "=s"(sdst) : "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_store_dword() {
    b32 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_store_dword %0, %1, %2 \n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_store_dwordx2() {
    b64 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_store_dwordx2 %0, %1, %2 \n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_buffer_store_dwordx4() {
    b128 sdata; b128 sbase; b32 soffset;
    __asm__ volatile("s_buffer_store_dwordx4 %0, %1, %2 \n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_dcache_discard() {
    b64 sbase; b32 soffset;
    __asm__ volatile("s_dcache_discard %0, %1 \n" :  : "s"(sbase), "s"(soffset));
}

__global__ void s_dcache_discard_x2() {
    b64 sbase; b32 soffset;
    __asm__ volatile("s_dcache_discard_x2 %0, %1 \n" :  : "s"(sbase), "s"(soffset));
}

__global__ void s_dcache_inv() {
    ;
    __asm__ volatile("s_dcache_inv  \n" :  : );
}

__global__ void s_dcache_inv_vol() {
    ;
    __asm__ volatile("s_dcache_inv_vol  \n" :  : );
}

__global__ void s_dcache_wb() {
    ;
    __asm__ volatile("s_dcache_wb  \n" :  : );
}

__global__ void s_dcache_wb_vol() {
    ;
    __asm__ volatile("s_dcache_wb_vol  \n" :  : );
}

__global__ void s_load_dword() {
    b32 sdst; b64 sbase; b32 soffset;
    __asm__ volatile("s_load_dword %0, %1, %2 \n" : "=s"(sdst) : "s"(sbase), "s"(soffset));
}

__global__ void s_load_dwordx16() {
    b512 sdst; b64 sbase; b32 soffset;
    __asm__ volatile("s_load_dwordx16 %0, %1, %2 \n" : "=s"(sdst) : "s"(sbase), "s"(soffset));
}

__global__ void s_load_dwordx2() {
    b64 sdst; b64 sbase; b32 soffset;
    __asm__ volatile("s_load_dwordx2 %0, %1, %2 \n" : "=s"(sdst) : "s"(sbase), "s"(soffset));
}

__global__ void s_load_dwordx4() {
    b128 sdst; b64 sbase; b32 soffset;
    __asm__ volatile("s_load_dwordx4 %0, %1, %2 \n" : "=s"(sdst) : "s"(sbase), "s"(soffset));
}

__global__ void s_load_dwordx8() {
    b256 sdst; b64 sbase; b32 soffset;
    __asm__ volatile("s_load_dwordx8 %0, %1, %2 \n" : "=s"(sdst) : "s"(sbase), "s"(soffset));
}

__global__ void s_memrealtime() {
    b64 sdst;
    __asm__ volatile("s_memrealtime %0 \n" : "=s"(sdst) : );
}

__global__ void s_memtime() {
    b64 sdst;
    __asm__ volatile("s_memtime %0 \n" : "=s"(sdst) : );
}

__global__ void s_scratch_load_dword() {
    b32 sdst; b64 sbase; b32 soffset;
    __asm__ volatile("s_scratch_load_dword %0, %1, %2 \n" : "=s"(sdst) : "s"(sbase), "s"(soffset));
}

__global__ void s_scratch_load_dwordx2() {
    b64 sdst; b64 sbase; b32 soffset;
    __asm__ volatile("s_scratch_load_dwordx2 %0, %1, %2 \n" : "=s"(sdst) : "s"(sbase), "s"(soffset));
}

__global__ void s_scratch_load_dwordx4() {
    b128 sdst; b64 sbase; b32 soffset;
    __asm__ volatile("s_scratch_load_dwordx4 %0, %1, %2 \n" : "=s"(sdst) : "s"(sbase), "s"(soffset));
}

__global__ void s_scratch_store_dword() {
    b32 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_scratch_store_dword %0, %1, %2 \n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_scratch_store_dwordx2() {
    b64 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_scratch_store_dwordx2 %0, %1, %2 \n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_scratch_store_dwordx4() {
    b128 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_scratch_store_dwordx4 %0, %1, %2 \n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_store_dword() {
    b32 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_store_dword %0, %1, %2 \n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_store_dwordx2() {
    b64 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_store_dwordx2 %0, %1, %2 \n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void s_store_dwordx4() {
    b128 sdata; b64 sbase; b32 soffset;
    __asm__ volatile("s_store_dwordx4 %0, %1, %2 \n" :  : "s"(sdata), "s"(sbase), "s"(soffset));
}

__global__ void v_cmp_class_f16() {
    f16 src0; b32 vsrc1;
    __asm__ volatile("v_cmp_class_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_class_f32() {
    f32 src0; b32 vsrc1;
    __asm__ volatile("v_cmp_class_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_class_f64() {
    f64 src0; b32 vsrc1;
    __asm__ volatile("v_cmp_class_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_eq_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmp_eq_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_eq_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmp_eq_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_eq_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmp_eq_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_eq_i16() {
    i16 src0; i16 vsrc1;
    __asm__ volatile("v_cmp_eq_i16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_eq_i32() {
    i32 src0; i32 vsrc1;
    __asm__ volatile("v_cmp_eq_i32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_eq_i64() {
    i64 src0; i64 vsrc1;
    __asm__ volatile("v_cmp_eq_i64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_eq_u16() {
    u16 src0; u16 vsrc1;
    __asm__ volatile("v_cmp_eq_u16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_eq_u32() {
    u32 src0; u32 vsrc1;
    __asm__ volatile("v_cmp_eq_u32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_eq_u64() {
    u64 src0; u64 vsrc1;
    __asm__ volatile("v_cmp_eq_u64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_f_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmp_f_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_f_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmp_f_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_f_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmp_f_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_f_i16() {
    i16 src0; i16 vsrc1;
    __asm__ volatile("v_cmp_f_i16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_f_i32() {
    i32 src0; i32 vsrc1;
    __asm__ volatile("v_cmp_f_i32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_f_i64() {
    i64 src0; i64 vsrc1;
    __asm__ volatile("v_cmp_f_i64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_f_u16() {
    u16 src0; u16 vsrc1;
    __asm__ volatile("v_cmp_f_u16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_f_u32() {
    u32 src0; u32 vsrc1;
    __asm__ volatile("v_cmp_f_u32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_f_u64() {
    u64 src0; u64 vsrc1;
    __asm__ volatile("v_cmp_f_u64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_ge_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmp_ge_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_ge_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmp_ge_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_ge_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmp_ge_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_ge_i16() {
    i16 src0; i16 vsrc1;
    __asm__ volatile("v_cmp_ge_i16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_ge_i32() {
    i32 src0; i32 vsrc1;
    __asm__ volatile("v_cmp_ge_i32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_ge_i64() {
    i64 src0; i64 vsrc1;
    __asm__ volatile("v_cmp_ge_i64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_ge_u16() {
    u16 src0; u16 vsrc1;
    __asm__ volatile("v_cmp_ge_u16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_ge_u32() {
    u32 src0; u32 vsrc1;
    __asm__ volatile("v_cmp_ge_u32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_ge_u64() {
    u64 src0; u64 vsrc1;
    __asm__ volatile("v_cmp_ge_u64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_gt_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmp_gt_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_gt_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmp_gt_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_gt_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmp_gt_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_gt_i16() {
    i16 src0; i16 vsrc1;
    __asm__ volatile("v_cmp_gt_i16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_gt_i32() {
    i32 src0; i32 vsrc1;
    __asm__ volatile("v_cmp_gt_i32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_gt_i64() {
    i64 src0; i64 vsrc1;
    __asm__ volatile("v_cmp_gt_i64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_gt_u16() {
    u16 src0; u16 vsrc1;
    __asm__ volatile("v_cmp_gt_u16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_gt_u32() {
    u32 src0; u32 vsrc1;
    __asm__ volatile("v_cmp_gt_u32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_gt_u64() {
    u64 src0; u64 vsrc1;
    __asm__ volatile("v_cmp_gt_u64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_le_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmp_le_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_le_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmp_le_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_le_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmp_le_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_le_i16() {
    i16 src0; i16 vsrc1;
    __asm__ volatile("v_cmp_le_i16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_le_i32() {
    i32 src0; i32 vsrc1;
    __asm__ volatile("v_cmp_le_i32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_le_i64() {
    i64 src0; i64 vsrc1;
    __asm__ volatile("v_cmp_le_i64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_le_u16() {
    u16 src0; u16 vsrc1;
    __asm__ volatile("v_cmp_le_u16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_le_u32() {
    u32 src0; u32 vsrc1;
    __asm__ volatile("v_cmp_le_u32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_le_u64() {
    u64 src0; u64 vsrc1;
    __asm__ volatile("v_cmp_le_u64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_lg_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmp_lg_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_lg_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmp_lg_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_lg_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmp_lg_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_lt_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmp_lt_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_lt_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmp_lt_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_lt_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmp_lt_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_lt_i16() {
    i16 src0; i16 vsrc1;
    __asm__ volatile("v_cmp_lt_i16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_lt_i32() {
    i32 src0; i32 vsrc1;
    __asm__ volatile("v_cmp_lt_i32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_lt_i64() {
    i64 src0; i64 vsrc1;
    __asm__ volatile("v_cmp_lt_i64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_lt_u16() {
    u16 src0; u16 vsrc1;
    __asm__ volatile("v_cmp_lt_u16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_lt_u32() {
    u32 src0; u32 vsrc1;
    __asm__ volatile("v_cmp_lt_u32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_lt_u64() {
    u64 src0; u64 vsrc1;
    __asm__ volatile("v_cmp_lt_u64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_ne_i16() {
    i16 src0; i16 vsrc1;
    __asm__ volatile("v_cmp_ne_i16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_ne_i32() {
    i32 src0; i32 vsrc1;
    __asm__ volatile("v_cmp_ne_i32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_ne_i64() {
    i64 src0; i64 vsrc1;
    __asm__ volatile("v_cmp_ne_i64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_ne_u16() {
    u16 src0; u16 vsrc1;
    __asm__ volatile("v_cmp_ne_u16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_ne_u32() {
    u32 src0; u32 vsrc1;
    __asm__ volatile("v_cmp_ne_u32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_ne_u64() {
    u64 src0; u64 vsrc1;
    __asm__ volatile("v_cmp_ne_u64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_neq_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmp_neq_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_neq_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmp_neq_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_neq_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmp_neq_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_nge_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmp_nge_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_nge_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmp_nge_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_nge_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmp_nge_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_ngt_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmp_ngt_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_ngt_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmp_ngt_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_ngt_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmp_ngt_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_nle_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmp_nle_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_nle_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmp_nle_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_nle_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmp_nle_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_nlg_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmp_nlg_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_nlg_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmp_nlg_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_nlg_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmp_nlg_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_nlt_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmp_nlt_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_nlt_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmp_nlt_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_nlt_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmp_nlt_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_o_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmp_o_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_o_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmp_o_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_o_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmp_o_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_t_i16() {
    i16 src0; i16 vsrc1;
    __asm__ volatile("v_cmp_t_i16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_t_i32() {
    i32 src0; i32 vsrc1;
    __asm__ volatile("v_cmp_t_i32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_t_i64() {
    i64 src0; i64 vsrc1;
    __asm__ volatile("v_cmp_t_i64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_t_u16() {
    u16 src0; u16 vsrc1;
    __asm__ volatile("v_cmp_t_u16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_t_u32() {
    u32 src0; u32 vsrc1;
    __asm__ volatile("v_cmp_t_u32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_t_u64() {
    u64 src0; u64 vsrc1;
    __asm__ volatile("v_cmp_t_u64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_tru_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmp_tru_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_tru_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmp_tru_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_tru_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmp_tru_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_u_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmp_u_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_u_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmp_u_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmp_u_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmp_u_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_class_f16() {
    f16 src0; b32 vsrc1;
    __asm__ volatile("v_cmpx_class_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_class_f32() {
    f32 src0; b32 vsrc1;
    __asm__ volatile("v_cmpx_class_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_class_f64() {
    f64 src0; b32 vsrc1;
    __asm__ volatile("v_cmpx_class_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_eq_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmpx_eq_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_eq_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmpx_eq_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_eq_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmpx_eq_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_eq_i16() {
    i16 src0; i16 vsrc1;
    __asm__ volatile("v_cmpx_eq_i16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_eq_i32() {
    i32 src0; i32 vsrc1;
    __asm__ volatile("v_cmpx_eq_i32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_eq_i64() {
    i64 src0; i64 vsrc1;
    __asm__ volatile("v_cmpx_eq_i64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_eq_u16() {
    u16 src0; u16 vsrc1;
    __asm__ volatile("v_cmpx_eq_u16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_eq_u32() {
    u32 src0; u32 vsrc1;
    __asm__ volatile("v_cmpx_eq_u32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_eq_u64() {
    u64 src0; u64 vsrc1;
    __asm__ volatile("v_cmpx_eq_u64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_f_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmpx_f_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_f_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmpx_f_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_f_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmpx_f_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_f_i16() {
    i16 src0; i16 vsrc1;
    __asm__ volatile("v_cmpx_f_i16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_f_i32() {
    i32 src0; i32 vsrc1;
    __asm__ volatile("v_cmpx_f_i32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_f_i64() {
    i64 src0; i64 vsrc1;
    __asm__ volatile("v_cmpx_f_i64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_f_u16() {
    u16 src0; u16 vsrc1;
    __asm__ volatile("v_cmpx_f_u16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_f_u32() {
    u32 src0; u32 vsrc1;
    __asm__ volatile("v_cmpx_f_u32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_f_u64() {
    u64 src0; u64 vsrc1;
    __asm__ volatile("v_cmpx_f_u64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_ge_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmpx_ge_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_ge_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmpx_ge_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_ge_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmpx_ge_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_ge_i16() {
    i16 src0; i16 vsrc1;
    __asm__ volatile("v_cmpx_ge_i16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_ge_i32() {
    i32 src0; i32 vsrc1;
    __asm__ volatile("v_cmpx_ge_i32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_ge_i64() {
    i64 src0; i64 vsrc1;
    __asm__ volatile("v_cmpx_ge_i64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_ge_u16() {
    u16 src0; u16 vsrc1;
    __asm__ volatile("v_cmpx_ge_u16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_ge_u32() {
    u32 src0; u32 vsrc1;
    __asm__ volatile("v_cmpx_ge_u32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_ge_u64() {
    u64 src0; u64 vsrc1;
    __asm__ volatile("v_cmpx_ge_u64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_gt_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmpx_gt_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_gt_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmpx_gt_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_gt_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmpx_gt_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_gt_i16() {
    i16 src0; i16 vsrc1;
    __asm__ volatile("v_cmpx_gt_i16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_gt_i32() {
    i32 src0; i32 vsrc1;
    __asm__ volatile("v_cmpx_gt_i32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_gt_i64() {
    i64 src0; i64 vsrc1;
    __asm__ volatile("v_cmpx_gt_i64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_gt_u16() {
    u16 src0; u16 vsrc1;
    __asm__ volatile("v_cmpx_gt_u16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_gt_u32() {
    u32 src0; u32 vsrc1;
    __asm__ volatile("v_cmpx_gt_u32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_gt_u64() {
    u64 src0; u64 vsrc1;
    __asm__ volatile("v_cmpx_gt_u64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_le_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmpx_le_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_le_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmpx_le_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_le_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmpx_le_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_le_i16() {
    i16 src0; i16 vsrc1;
    __asm__ volatile("v_cmpx_le_i16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_le_i32() {
    i32 src0; i32 vsrc1;
    __asm__ volatile("v_cmpx_le_i32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_le_i64() {
    i64 src0; i64 vsrc1;
    __asm__ volatile("v_cmpx_le_i64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_le_u16() {
    u16 src0; u16 vsrc1;
    __asm__ volatile("v_cmpx_le_u16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_le_u32() {
    u32 src0; u32 vsrc1;
    __asm__ volatile("v_cmpx_le_u32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_le_u64() {
    u64 src0; u64 vsrc1;
    __asm__ volatile("v_cmpx_le_u64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_lg_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmpx_lg_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_lg_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmpx_lg_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_lg_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmpx_lg_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_lt_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmpx_lt_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_lt_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmpx_lt_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_lt_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmpx_lt_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_lt_i16() {
    i16 src0; i16 vsrc1;
    __asm__ volatile("v_cmpx_lt_i16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_lt_i32() {
    i32 src0; i32 vsrc1;
    __asm__ volatile("v_cmpx_lt_i32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_lt_i64() {
    i64 src0; i64 vsrc1;
    __asm__ volatile("v_cmpx_lt_i64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_lt_u16() {
    u16 src0; u16 vsrc1;
    __asm__ volatile("v_cmpx_lt_u16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_lt_u32() {
    u32 src0; u32 vsrc1;
    __asm__ volatile("v_cmpx_lt_u32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_lt_u64() {
    u64 src0; u64 vsrc1;
    __asm__ volatile("v_cmpx_lt_u64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_ne_i16() {
    i16 src0; i16 vsrc1;
    __asm__ volatile("v_cmpx_ne_i16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_ne_i32() {
    i32 src0; i32 vsrc1;
    __asm__ volatile("v_cmpx_ne_i32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_ne_i64() {
    i64 src0; i64 vsrc1;
    __asm__ volatile("v_cmpx_ne_i64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_ne_u16() {
    u16 src0; u16 vsrc1;
    __asm__ volatile("v_cmpx_ne_u16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_ne_u32() {
    u32 src0; u32 vsrc1;
    __asm__ volatile("v_cmpx_ne_u32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_ne_u64() {
    u64 src0; u64 vsrc1;
    __asm__ volatile("v_cmpx_ne_u64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_neq_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmpx_neq_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_neq_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmpx_neq_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_neq_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmpx_neq_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_nge_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmpx_nge_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_nge_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmpx_nge_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_nge_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmpx_nge_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_ngt_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmpx_ngt_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_ngt_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmpx_ngt_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_ngt_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmpx_ngt_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_nle_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmpx_nle_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_nle_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmpx_nle_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_nle_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmpx_nle_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_nlg_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmpx_nlg_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_nlg_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmpx_nlg_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_nlg_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmpx_nlg_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_nlt_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmpx_nlt_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_nlt_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmpx_nlt_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_nlt_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmpx_nlt_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_o_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmpx_o_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_o_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmpx_o_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_o_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmpx_o_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_t_i16() {
    i16 src0; i16 vsrc1;
    __asm__ volatile("v_cmpx_t_i16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_t_i32() {
    i32 src0; i32 vsrc1;
    __asm__ volatile("v_cmpx_t_i32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_t_i64() {
    i64 src0; i64 vsrc1;
    __asm__ volatile("v_cmpx_t_i64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_t_u16() {
    u16 src0; u16 vsrc1;
    __asm__ volatile("v_cmpx_t_u16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_t_u32() {
    u32 src0; u32 vsrc1;
    __asm__ volatile("v_cmpx_t_u32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_t_u64() {
    u64 src0; u64 vsrc1;
    __asm__ volatile("v_cmpx_t_u64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_tru_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmpx_tru_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_tru_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmpx_tru_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_tru_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmpx_tru_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_u_f16() {
    f16 src0; f16 vsrc1;
    __asm__ volatile("v_cmpx_u_f16 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_u_f32() {
    f32 src0; f32 vsrc1;
    __asm__ volatile("v_cmpx_u_f32 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void v_cmpx_u_f64() {
    f64 src0; f64 vsrc1;
    __asm__ volatile("v_cmpx_u_f64 vcc, %0, %1 \n" :  : "v"(src0), "v"(vsrc1));
}

__global__ void tbuffer_load_format_d16_x() {
    b16 vdst; b128 srsrc; b16 soffset;
    __asm__ volatile("tbuffer_load_format_d16_x %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void tbuffer_load_format_d16_xy() {
    b16x2 vdst; b128 srsrc; b16x2 soffset;
    __asm__ volatile("tbuffer_load_format_d16_xy %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void tbuffer_load_format_d16_xyz() {
    b16x3 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("tbuffer_load_format_d16_xyz %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void tbuffer_load_format_d16_xyzw() {
    b16x4 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("tbuffer_load_format_d16_xyzw %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void tbuffer_load_format_x() {
    b32 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("tbuffer_load_format_x %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void tbuffer_load_format_xy() {
    b64 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("tbuffer_load_format_xy %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void tbuffer_load_format_xyz() {
    b96 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("tbuffer_load_format_xyz %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void tbuffer_load_format_xyzw() {
    b128 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("tbuffer_load_format_xyzw %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void tbuffer_store_format_d16_x() {
    b16 vdata; b128 srsrc; b16 soffset;
    __asm__ volatile("tbuffer_store_format_d16_x %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void tbuffer_store_format_d16_xy() {
    b16x2 vdata; b128 srsrc; b16x2 soffset;
    __asm__ volatile("tbuffer_store_format_d16_xy %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void tbuffer_store_format_d16_xyz() {
    b16x3 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("tbuffer_store_format_d16_xyz %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void tbuffer_store_format_d16_xyzw() {
    b16x4 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("tbuffer_store_format_d16_xyzw %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void tbuffer_store_format_x() {
    b32 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("tbuffer_store_format_x %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void tbuffer_store_format_xy() {
    b64 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("tbuffer_store_format_xy %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void tbuffer_store_format_xyz() {
    b96 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("tbuffer_store_format_xyz %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void tbuffer_store_format_xyzw() {
    b128 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("tbuffer_store_format_xyzw %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_add() {
    b32 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_add %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_add_f32() {
    f32 vdata; b128 srsrc; f32 soffset;
    __asm__ volatile("buffer_atomic_add_f32 %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_add_f64() {
    f64 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_add_f64 %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_add_x2() {
    b64 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_add_x2 %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_and() {
    b32 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_and %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_and_x2() {
    b64 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_and_x2 %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_cmpswap() {
    b32x2 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_cmpswap %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_cmpswap_x2() {
    b64x2 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_cmpswap_x2 %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_dec() {
    u32 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_dec %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_dec_x2() {
    u64 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_dec_x2 %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_inc() {
    u32 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_inc %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_inc_x2() {
    u64 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_inc_x2 %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_max_f64() {
    f64 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_max_f64 %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_min_f64() {
    f64 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_min_f64 %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_or() {
    b32 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_or %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_or_x2() {
    b64 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_or_x2 %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_pk_add_f16() {
    f16 vdata; b128 srsrc; f16 soffset;
    __asm__ volatile("buffer_atomic_pk_add_f16 %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_smax() {
    i32 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_smax %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_smax_x2() {
    i64 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_smax_x2 %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_smin() {
    i32 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_smin %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_smin_x2() {
    i64 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_smin_x2 %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_sub() {
    b32 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_sub %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_sub_x2() {
    b64 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_sub_x2 %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_swap() {
    b32 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_swap %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_swap_x2() {
    b64 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_swap_x2 %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_umax() {
    u32 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_umax %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_umax_x2() {
    u64 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_umax_x2 %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_umin() {
    u32 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_umin %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_umin_x2() {
    u64 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_umin_x2 %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_xor() {
    b32 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_xor %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_atomic_xor_x2() {
    b64 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_atomic_xor_x2 %0, off, %1, %2 glc\n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_invl2() {
    ;
    __asm__ volatile("buffer_invl2  \n" :  : );
}

__global__ void buffer_load_dword() {
    b32 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_load_dword %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_load_dwordx2() {
    b64 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_load_dwordx2 %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_load_dwordx3() {
    b96 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_load_dwordx3 %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_load_dwordx4() {
    b128 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_load_dwordx4 %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_load_format_d16_hi_x() {
    b32 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_load_format_d16_hi_x %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_load_format_d16_x() {
    b16 vdst; b128 srsrc; b16 soffset;
    __asm__ volatile("buffer_load_format_d16_x %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_load_format_d16_xy() {
    b16x2 vdst; b128 srsrc; b16x2 soffset;
    __asm__ volatile("buffer_load_format_d16_xy %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_load_format_d16_xyz() {
    b16x3 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_load_format_d16_xyz %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_load_format_d16_xyzw() {
    b16x4 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_load_format_d16_xyzw %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_load_format_x() {
    b32 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_load_format_x %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_load_format_xy() {
    b64 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_load_format_xy %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_load_format_xyz() {
    b96 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_load_format_xyz %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_load_format_xyzw() {
    b128 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_load_format_xyzw %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_load_sbyte() {
    b32 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_load_sbyte %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_load_sbyte_d16() {
    b32 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_load_sbyte_d16 %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_load_sbyte_d16_hi() {
    b32 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_load_sbyte_d16_hi %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_load_short_d16() {
    b32 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_load_short_d16 %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_load_short_d16_hi() {
    b32 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_load_short_d16_hi %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_load_sshort() {
    b32 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_load_sshort %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_load_ubyte() {
    b32 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_load_ubyte %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_load_ubyte_d16() {
    b32 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_load_ubyte_d16 %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_load_ubyte_d16_hi() {
    b32 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_load_ubyte_d16_hi %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_load_ushort() {
    b32 vdst; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_load_ushort %0, off, %1, %2 \n" : "=v"(vdst) : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_store_byte() {
    b32 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_store_byte %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_store_byte_d16_hi() {
    b32 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_store_byte_d16_hi %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_store_dword() {
    b32 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_store_dword %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_store_dwordx2() {
    b64 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_store_dwordx2 %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_store_dwordx3() {
    b96 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_store_dwordx3 %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_store_dwordx4() {
    b128 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_store_dwordx4 %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_store_format_d16_hi_x() {
    b32 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_store_format_d16_hi_x %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_store_format_d16_x() {
    b16 vdata; b128 srsrc; b16 soffset;
    __asm__ volatile("buffer_store_format_d16_x %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_store_format_d16_xy() {
    b16x2 vdata; b128 srsrc; b16x2 soffset;
    __asm__ volatile("buffer_store_format_d16_xy %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_store_format_d16_xyz() {
    b16x3 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_store_format_d16_xyz %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_store_format_d16_xyzw() {
    b16x4 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_store_format_d16_xyzw %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_store_format_x() {
    b32 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_store_format_x %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_store_format_xy() {
    b64 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_store_format_xy %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_store_format_xyz() {
    b96 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_store_format_xyz %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_store_format_xyzw() {
    b128 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_store_format_xyzw %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_store_lds_dword() {
    b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_store_lds_dword %0, %1 lds\n" :  : "s"(srsrc), "s"(soffset));
}

__global__ void buffer_store_short() {
    b32 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_store_short %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_store_short_d16_hi() {
    b32 vdata; b128 srsrc; b32 soffset;
    __asm__ volatile("buffer_store_short_d16_hi %0, off, %1, %2 \n" :  : "v"(vdata), "s"(srsrc), "s"(soffset));
}

__global__ void buffer_wbinvl1() {
    ;
    __asm__ volatile("buffer_wbinvl1  \n" :  : );
}

__global__ void buffer_wbinvl1_vol() {
    ;
    __asm__ volatile("buffer_wbinvl1_vol  \n" :  : );
}

__global__ void buffer_wbl2() {
    ;
    __asm__ volatile("buffer_wbl2  \n" :  : );
}

__global__ void v_add_co_u32() {
    u32 vdst; u32 src0; u32 vsrc1;
    __asm__ volatile("v_add_co_u32 %0, vcc, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_add_f16() {
    f16 vdst; f16 src0; f16 vsrc1;
    __asm__ volatile("v_add_f16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_add_f32() {
    f32 vdst; f32 src0; f32 vsrc1;
    __asm__ volatile("v_add_f32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_add_u16() {
    u16 vdst; u16 src0; u16 vsrc1;
    __asm__ volatile("v_add_u16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_add_u32() {
    u32 vdst; u32 src0; u32 vsrc1;
    __asm__ volatile("v_add_u32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_addc_co_u32() {
    u32 vdst; u32 src0; u32 vsrc1;
    __asm__ volatile("v_addc_co_u32 %0, vcc, %1, %2, vcc \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_and_b32() {
    b32 vdst; b32 src0; b32 vsrc1;
    __asm__ volatile("v_and_b32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_ashrrev_i16() {
    i16 vdst; u16 src0; i16 vsrc1;
    __asm__ volatile("v_ashrrev_i16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_ashrrev_i32() {
    i32 vdst; u32 src0; i32 vsrc1;
    __asm__ volatile("v_ashrrev_i32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_cndmask_b32() {
    b32 vdst; b32 src0; b32 vsrc1;
    __asm__ volatile("v_cndmask_b32 %0, %1, %2, vcc \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_dot2c_f32_f16() {
    f32 vdst; f16x2 src0; f16x2 vsrc1;
    __asm__ volatile("v_dot2c_f32_f16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_dot2c_i32_i16() {
    i32 vdst; i16x2 src0; i16x2 vsrc1;
    __asm__ volatile("v_dot2c_i32_i16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_dot4c_i32_i8() {
    i32 vdst; i8x4 src0; i8x4 vsrc1;
    __asm__ volatile("v_dot4c_i32_i8 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_dot8c_i32_i4() {
    i32 vdst; i4x8 src0; i4x8 vsrc1;
    __asm__ volatile("v_dot8c_i32_i4 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_fmac_f32() {
    f32 vdst; f32 src0; f32 vsrc1;
    __asm__ volatile("v_fmac_f32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_fmac_f64() {
    f64 vdst; f64 src0; f64 vsrc1;
    __asm__ volatile("v_fmac_f64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_ldexp_f16() {
    f16 vdst; f16 src0; i16 vsrc1;
    __asm__ volatile("v_ldexp_f16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_lshlrev_b16() {
    b16 vdst; u16 src0; b16 vsrc1;
    __asm__ volatile("v_lshlrev_b16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_lshlrev_b32() {
    b32 vdst; u32 src0; b32 vsrc1;
    __asm__ volatile("v_lshlrev_b32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_lshrrev_b16() {
    b16 vdst; u16 src0; b16 vsrc1;
    __asm__ volatile("v_lshrrev_b16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_lshrrev_b32() {
    b32 vdst; u32 src0; b32 vsrc1;
    __asm__ volatile("v_lshrrev_b32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_mac_f16() {
    f16 vdst; f16 src0; f16 vsrc1;
    __asm__ volatile("v_mac_f16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_mac_f32() {
    f32 vdst; f32 src0; f32 vsrc1;
    __asm__ volatile("v_mac_f32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_madak_f16() {
    f16 vdst; f16 src0; f16 vsrc1;
    __asm__ volatile("v_madak_f16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1), "i"(0));
}

__global__ void v_madak_f32() {
    f32 vdst; f32 src0; f32 vsrc1;
    __asm__ volatile("v_madak_f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1), "i"(0));
}

__global__ void v_madmk_f16() {
    f16 vdst; f16 src0; f16 vsrc2;
    __asm__ volatile("v_madmk_f16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "i"(0), "v"(vsrc2));
}

__global__ void v_madmk_f32() {
    f32 vdst; f32 src0; f32 vsrc2;
    __asm__ volatile("v_madmk_f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "i"(0), "v"(vsrc2));
}

__global__ void v_max_f16() {
    f16 vdst; f16 src0; f16 vsrc1;
    __asm__ volatile("v_max_f16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_max_f32() {
    f32 vdst; f32 src0; f32 vsrc1;
    __asm__ volatile("v_max_f32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_max_i16() {
    i16 vdst; i16 src0; i16 vsrc1;
    __asm__ volatile("v_max_i16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_max_i32() {
    i32 vdst; i32 src0; i32 vsrc1;
    __asm__ volatile("v_max_i32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_max_u16() {
    u16 vdst; u16 src0; u16 vsrc1;
    __asm__ volatile("v_max_u16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_max_u32() {
    u32 vdst; u32 src0; u32 vsrc1;
    __asm__ volatile("v_max_u32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_min_f16() {
    f16 vdst; f16 src0; f16 vsrc1;
    __asm__ volatile("v_min_f16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_min_f32() {
    f32 vdst; f32 src0; f32 vsrc1;
    __asm__ volatile("v_min_f32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_min_i16() {
    i16 vdst; i16 src0; i16 vsrc1;
    __asm__ volatile("v_min_i16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_min_i32() {
    i32 vdst; i32 src0; i32 vsrc1;
    __asm__ volatile("v_min_i32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_min_u16() {
    u16 vdst; u16 src0; u16 vsrc1;
    __asm__ volatile("v_min_u16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_min_u32() {
    u32 vdst; u32 src0; u32 vsrc1;
    __asm__ volatile("v_min_u32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_mul_f16() {
    f16 vdst; f16 src0; f16 vsrc1;
    __asm__ volatile("v_mul_f16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_mul_f32() {
    f32 vdst; f32 src0; f32 vsrc1;
    __asm__ volatile("v_mul_f32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_mul_hi_i32_i24() {
    b32 vdst; b32 src0; b32 vsrc1;
    __asm__ volatile("v_mul_hi_i32_i24 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_mul_hi_u32_u24() {
    b32 vdst; b32 src0; b32 vsrc1;
    __asm__ volatile("v_mul_hi_u32_u24 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_mul_i32_i24() {
    b32 vdst; b32 src0; b32 vsrc1;
    __asm__ volatile("v_mul_i32_i24 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_mul_lo_u16() {
    u16 vdst; u16 src0; u16 vsrc1;
    __asm__ volatile("v_mul_lo_u16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_mul_u32_u24() {
    b32 vdst; b32 src0; b32 vsrc1;
    __asm__ volatile("v_mul_u32_u24 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_or_b32() {
    b32 vdst; b32 src0; b32 vsrc1;
    __asm__ volatile("v_or_b32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_pk_fmac_f16() {
    f16 vdst; f16 src0; f16 vsrc1;
    __asm__ volatile("v_pk_fmac_f16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_sub_co_u32() {
    u32 vdst; u32 src0; u32 vsrc1;
    __asm__ volatile("v_sub_co_u32 %0, vcc, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_sub_f16() {
    f16 vdst; f16 src0; f16 vsrc1;
    __asm__ volatile("v_sub_f16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_sub_f32() {
    f32 vdst; f32 src0; f32 vsrc1;
    __asm__ volatile("v_sub_f32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_sub_u16() {
    u16 vdst; u16 src0; u16 vsrc1;
    __asm__ volatile("v_sub_u16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_sub_u32() {
    u32 vdst; u32 src0; u32 vsrc1;
    __asm__ volatile("v_sub_u32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_subb_co_u32() {
    u32 vdst; u32 src0; u32 vsrc1;
    __asm__ volatile("v_subb_co_u32 %0, vcc, %1, %2, vcc \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_subbrev_co_u32() {
    u32 vdst; u32 src0; u32 vsrc1;
    __asm__ volatile("v_subbrev_co_u32 %0, vcc, %1, %2, vcc \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_subrev_co_u32() {
    u32 vdst; u32 src0; u32 vsrc1;
    __asm__ volatile("v_subrev_co_u32 %0, vcc, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_subrev_f16() {
    f16 vdst; f16 src0; f16 vsrc1;
    __asm__ volatile("v_subrev_f16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_subrev_f32() {
    f32 vdst; f32 src0; f32 vsrc1;
    __asm__ volatile("v_subrev_f32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_subrev_u16() {
    u16 vdst; u16 src0; u16 vsrc1;
    __asm__ volatile("v_subrev_u16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_subrev_u32() {
    u32 vdst; u32 src0; u32 vsrc1;
    __asm__ volatile("v_subrev_u32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_xnor_b32() {
    b32 vdst; b32 src0; b32 vsrc1;
    __asm__ volatile("v_xnor_b32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_xor_b32() {
    b32 vdst; b32 src0; b32 vsrc1;
    __asm__ volatile("v_xor_b32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(vsrc1));
}

__global__ void v_add_co_u32_dpp() {
    u32 vdst; u32 vsrc0; u32 vsrc1;
    __asm__ volatile("v_add_co_u32_dpp %0, vcc, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_add_f16_dpp() {
    f16 vdst; f16 vsrc0; f16 vsrc1;
    __asm__ volatile("v_add_f16_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_add_f32_dpp() {
    f32 vdst; f32 vsrc0; f32 vsrc1;
    __asm__ volatile("v_add_f32_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_add_u16_dpp() {
    u16 vdst; u16 vsrc0; u16 vsrc1;
    __asm__ volatile("v_add_u16_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_add_u32_dpp() {
    u32 vdst; u32 vsrc0; u32 vsrc1;
    __asm__ volatile("v_add_u32_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_addc_co_u32_dpp() {
    u32 vdst; u32 vsrc0; u32 vsrc1;
    __asm__ volatile("v_addc_co_u32_dpp %0, vcc, %1, %2, vcc row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_and_b32_dpp() {
    b32 vdst; b32 vsrc0; b32 vsrc1;
    __asm__ volatile("v_and_b32_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_ashrrev_i16_dpp() {
    i16 vdst; u16 vsrc0; i16 vsrc1;
    __asm__ volatile("v_ashrrev_i16_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_ashrrev_i32_dpp() {
    i32 vdst; u32 vsrc0; i32 vsrc1;
    __asm__ volatile("v_ashrrev_i32_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_cndmask_b32_dpp() {
    b32 vdst; b32 vsrc0; b32 vsrc1;
    __asm__ volatile("v_cndmask_b32_dpp %0, %1, %2, vcc row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_dot2c_f32_f16_dpp() {
    f32 vdst; f16x2 vsrc0; f16x2 vsrc1;
    __asm__ volatile("v_dot2c_f32_f16_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_dot2c_i32_i16_dpp() {
    i32 vdst; i16x2 vsrc0; i16x2 vsrc1;
    __asm__ volatile("v_dot2c_i32_i16_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_dot4c_i32_i8_dpp() {
    i32 vdst; i8x4 vsrc0; i8x4 vsrc1;
    __asm__ volatile("v_dot4c_i32_i8_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_dot8c_i32_i4_dpp() {
    i32 vdst; i4x8 vsrc0; i4x8 vsrc1;
    __asm__ volatile("v_dot8c_i32_i4_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_fmac_f32_dpp() {
    f32 vdst; f32 vsrc0; f32 vsrc1;
    __asm__ volatile("v_fmac_f32_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_fmac_f64_dpp() {
    f64 vdst; f64 vsrc0; f64 vsrc1;
    __asm__ volatile("v_fmac_f64_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_ldexp_f16_dpp() {
    f16 vdst; f16 vsrc0; i16 vsrc1;
    __asm__ volatile("v_ldexp_f16_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_lshlrev_b16_dpp() {
    b16 vdst; u16 vsrc0; b16 vsrc1;
    __asm__ volatile("v_lshlrev_b16_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_lshlrev_b32_dpp() {
    b32 vdst; u32 vsrc0; b32 vsrc1;
    __asm__ volatile("v_lshlrev_b32_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_lshrrev_b16_dpp() {
    b16 vdst; u16 vsrc0; b16 vsrc1;
    __asm__ volatile("v_lshrrev_b16_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_lshrrev_b32_dpp() {
    b32 vdst; u32 vsrc0; b32 vsrc1;
    __asm__ volatile("v_lshrrev_b32_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_mac_f16_dpp() {
    f16 vdst; f16 vsrc0; f16 vsrc1;
    __asm__ volatile("v_mac_f16_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_mac_f32_dpp() {
    f32 vdst; f32 vsrc0; f32 vsrc1;
    __asm__ volatile("v_mac_f32_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_max_f16_dpp() {
    f16 vdst; f16 vsrc0; f16 vsrc1;
    __asm__ volatile("v_max_f16_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_max_f32_dpp() {
    f32 vdst; f32 vsrc0; f32 vsrc1;
    __asm__ volatile("v_max_f32_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_max_i16_dpp() {
    i16 vdst; i16 vsrc0; i16 vsrc1;
    __asm__ volatile("v_max_i16_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_max_i32_dpp() {
    i32 vdst; i32 vsrc0; i32 vsrc1;
    __asm__ volatile("v_max_i32_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_max_u16_dpp() {
    u16 vdst; u16 vsrc0; u16 vsrc1;
    __asm__ volatile("v_max_u16_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_max_u32_dpp() {
    u32 vdst; u32 vsrc0; u32 vsrc1;
    __asm__ volatile("v_max_u32_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_min_f16_dpp() {
    f16 vdst; f16 vsrc0; f16 vsrc1;
    __asm__ volatile("v_min_f16_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_min_f32_dpp() {
    f32 vdst; f32 vsrc0; f32 vsrc1;
    __asm__ volatile("v_min_f32_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_min_i16_dpp() {
    i16 vdst; i16 vsrc0; i16 vsrc1;
    __asm__ volatile("v_min_i16_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_min_i32_dpp() {
    i32 vdst; i32 vsrc0; i32 vsrc1;
    __asm__ volatile("v_min_i32_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_min_u16_dpp() {
    u16 vdst; u16 vsrc0; u16 vsrc1;
    __asm__ volatile("v_min_u16_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_min_u32_dpp() {
    u32 vdst; u32 vsrc0; u32 vsrc1;
    __asm__ volatile("v_min_u32_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_mul_f16_dpp() {
    f16 vdst; f16 vsrc0; f16 vsrc1;
    __asm__ volatile("v_mul_f16_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_mul_f32_dpp() {
    f32 vdst; f32 vsrc0; f32 vsrc1;
    __asm__ volatile("v_mul_f32_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_mul_hi_i32_i24_dpp() {
    b32 vdst; b32 vsrc0; b32 vsrc1;
    __asm__ volatile("v_mul_hi_i32_i24_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_mul_hi_u32_u24_dpp() {
    b32 vdst; b32 vsrc0; b32 vsrc1;
    __asm__ volatile("v_mul_hi_u32_u24_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_mul_i32_i24_dpp() {
    b32 vdst; b32 vsrc0; b32 vsrc1;
    __asm__ volatile("v_mul_i32_i24_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_mul_lo_u16_dpp() {
    u16 vdst; u16 vsrc0; u16 vsrc1;
    __asm__ volatile("v_mul_lo_u16_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_mul_u32_u24_dpp() {
    b32 vdst; b32 vsrc0; b32 vsrc1;
    __asm__ volatile("v_mul_u32_u24_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_or_b32_dpp() {
    b32 vdst; b32 vsrc0; b32 vsrc1;
    __asm__ volatile("v_or_b32_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_sub_co_u32_dpp() {
    u32 vdst; u32 vsrc0; u32 vsrc1;
    __asm__ volatile("v_sub_co_u32_dpp %0, vcc, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_sub_f16_dpp() {
    f16 vdst; f16 vsrc0; f16 vsrc1;
    __asm__ volatile("v_sub_f16_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_sub_f32_dpp() {
    f32 vdst; f32 vsrc0; f32 vsrc1;
    __asm__ volatile("v_sub_f32_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_sub_u16_dpp() {
    u16 vdst; u16 vsrc0; u16 vsrc1;
    __asm__ volatile("v_sub_u16_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_sub_u32_dpp() {
    u32 vdst; u32 vsrc0; u32 vsrc1;
    __asm__ volatile("v_sub_u32_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_subb_co_u32_dpp() {
    u32 vdst; u32 vsrc0; u32 vsrc1;
    __asm__ volatile("v_subb_co_u32_dpp %0, vcc, %1, %2, vcc row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_subbrev_co_u32_dpp() {
    u32 vdst; u32 vsrc0; u32 vsrc1;
    __asm__ volatile("v_subbrev_co_u32_dpp %0, vcc, %1, %2, vcc row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_subrev_co_u32_dpp() {
    u32 vdst; u32 vsrc0; u32 vsrc1;
    __asm__ volatile("v_subrev_co_u32_dpp %0, vcc, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_subrev_f16_dpp() {
    f16 vdst; f16 vsrc0; f16 vsrc1;
    __asm__ volatile("v_subrev_f16_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_subrev_f32_dpp() {
    f32 vdst; f32 vsrc0; f32 vsrc1;
    __asm__ volatile("v_subrev_f32_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_subrev_u16_dpp() {
    u16 vdst; u16 vsrc0; u16 vsrc1;
    __asm__ volatile("v_subrev_u16_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_subrev_u32_dpp() {
    u32 vdst; u32 vsrc0; u32 vsrc1;
    __asm__ volatile("v_subrev_u32_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_xnor_b32_dpp() {
    b32 vdst; b32 vsrc0; b32 vsrc1;
    __asm__ volatile("v_xnor_b32_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_xor_b32_dpp() {
    b32 vdst; b32 vsrc0; b32 vsrc1;
    __asm__ volatile("v_xor_b32_dpp %0, %1, %2 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1));
}

__global__ void v_add_co_u32_sdwa() {
    u32 vdst; u32 src0; u32 src1;
    __asm__ volatile("v_add_co_u32_sdwa %0, vcc, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_add_f16_sdwa() {
    f16 vdst; f16 src0; f16 src1;
    __asm__ volatile("v_add_f16_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_add_f32_sdwa() {
    f32 vdst; f32 src0; f32 src1;
    __asm__ volatile("v_add_f32_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_add_u16_sdwa() {
    u16 vdst; u16 src0; u16 src1;
    __asm__ volatile("v_add_u16_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_add_u32_sdwa() {
    u32 vdst; u32 src0; u32 src1;
    __asm__ volatile("v_add_u32_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_addc_co_u32_sdwa() {
    u32 vdst; u32 src0; u32 src1;
    __asm__ volatile("v_addc_co_u32_sdwa %0, vcc, %1, %2, vcc \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_and_b32_sdwa() {
    b32 vdst; b32 src0; b32 src1;
    __asm__ volatile("v_and_b32_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_ashrrev_i16_sdwa() {
    i16 vdst; u16 src0; i16 src1;
    __asm__ volatile("v_ashrrev_i16_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_ashrrev_i32_sdwa() {
    i32 vdst; u32 src0; i32 src1;
    __asm__ volatile("v_ashrrev_i32_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_cndmask_b32_sdwa() {
    b32 vdst; b32 src0; b32 src1;
    __asm__ volatile("v_cndmask_b32_sdwa %0, %1, %2, vcc \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_ldexp_f16_sdwa() {
    f16 vdst; f16 src0; i16 src1;
    __asm__ volatile("v_ldexp_f16_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_lshlrev_b16_sdwa() {
    b16 vdst; u16 src0; b16 src1;
    __asm__ volatile("v_lshlrev_b16_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_lshlrev_b32_sdwa() {
    b32 vdst; u32 src0; b32 src1;
    __asm__ volatile("v_lshlrev_b32_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_lshrrev_b16_sdwa() {
    b16 vdst; u16 src0; b16 src1;
    __asm__ volatile("v_lshrrev_b16_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_lshrrev_b32_sdwa() {
    b32 vdst; u32 src0; b32 src1;
    __asm__ volatile("v_lshrrev_b32_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_max_f16_sdwa() {
    f16 vdst; f16 src0; f16 src1;
    __asm__ volatile("v_max_f16_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_max_f32_sdwa() {
    f32 vdst; f32 src0; f32 src1;
    __asm__ volatile("v_max_f32_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_max_i16_sdwa() {
    i16 vdst; i16 src0; i16 src1;
    __asm__ volatile("v_max_i16_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_max_i32_sdwa() {
    i32 vdst; i32 src0; i32 src1;
    __asm__ volatile("v_max_i32_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_max_u16_sdwa() {
    u16 vdst; u16 src0; u16 src1;
    __asm__ volatile("v_max_u16_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_max_u32_sdwa() {
    u32 vdst; u32 src0; u32 src1;
    __asm__ volatile("v_max_u32_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_min_f16_sdwa() {
    f16 vdst; f16 src0; f16 src1;
    __asm__ volatile("v_min_f16_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_min_f32_sdwa() {
    f32 vdst; f32 src0; f32 src1;
    __asm__ volatile("v_min_f32_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_min_i16_sdwa() {
    i16 vdst; i16 src0; i16 src1;
    __asm__ volatile("v_min_i16_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_min_i32_sdwa() {
    i32 vdst; i32 src0; i32 src1;
    __asm__ volatile("v_min_i32_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_min_u16_sdwa() {
    u16 vdst; u16 src0; u16 src1;
    __asm__ volatile("v_min_u16_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_min_u32_sdwa() {
    u32 vdst; u32 src0; u32 src1;
    __asm__ volatile("v_min_u32_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mul_f16_sdwa() {
    f16 vdst; f16 src0; f16 src1;
    __asm__ volatile("v_mul_f16_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mul_f32_sdwa() {
    f32 vdst; f32 src0; f32 src1;
    __asm__ volatile("v_mul_f32_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mul_hi_i32_i24_sdwa() {
    b32 vdst; b32 src0; b32 src1;
    __asm__ volatile("v_mul_hi_i32_i24_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mul_hi_u32_u24_sdwa() {
    b32 vdst; b32 src0; b32 src1;
    __asm__ volatile("v_mul_hi_u32_u24_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mul_i32_i24_sdwa() {
    b32 vdst; b32 src0; b32 src1;
    __asm__ volatile("v_mul_i32_i24_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mul_lo_u16_sdwa() {
    u16 vdst; u16 src0; u16 src1;
    __asm__ volatile("v_mul_lo_u16_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mul_u32_u24_sdwa() {
    b32 vdst; b32 src0; b32 src1;
    __asm__ volatile("v_mul_u32_u24_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_or_b32_sdwa() {
    b32 vdst; b32 src0; b32 src1;
    __asm__ volatile("v_or_b32_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_sub_co_u32_sdwa() {
    u32 vdst; u32 src0; u32 src1;
    __asm__ volatile("v_sub_co_u32_sdwa %0, vcc, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_sub_f16_sdwa() {
    f16 vdst; f16 src0; f16 src1;
    __asm__ volatile("v_sub_f16_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_sub_f32_sdwa() {
    f32 vdst; f32 src0; f32 src1;
    __asm__ volatile("v_sub_f32_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_sub_u16_sdwa() {
    u16 vdst; u16 src0; u16 src1;
    __asm__ volatile("v_sub_u16_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_sub_u32_sdwa() {
    u32 vdst; u32 src0; u32 src1;
    __asm__ volatile("v_sub_u32_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_subb_co_u32_sdwa() {
    u32 vdst; u32 src0; u32 src1;
    __asm__ volatile("v_subb_co_u32_sdwa %0, vcc, %1, %2, vcc \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_subbrev_co_u32_sdwa() {
    u32 vdst; u32 src0; u32 src1;
    __asm__ volatile("v_subbrev_co_u32_sdwa %0, vcc, %1, %2, vcc \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_subrev_co_u32_sdwa() {
    u32 vdst; u32 src0; u32 src1;
    __asm__ volatile("v_subrev_co_u32_sdwa %0, vcc, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_subrev_f16_sdwa() {
    f16 vdst; f16 src0; f16 src1;
    __asm__ volatile("v_subrev_f16_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_subrev_f32_sdwa() {
    f32 vdst; f32 src0; f32 src1;
    __asm__ volatile("v_subrev_f32_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_subrev_u16_sdwa() {
    u16 vdst; u16 src0; u16 src1;
    __asm__ volatile("v_subrev_u16_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_subrev_u32_sdwa() {
    u32 vdst; u32 src0; u32 src1;
    __asm__ volatile("v_subrev_u32_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_xnor_b32_sdwa() {
    b32 vdst; b32 src0; b32 src1;
    __asm__ volatile("v_xnor_b32_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_xor_b32_sdwa() {
    b32 vdst; b32 src0; b32 src1;
    __asm__ volatile("v_xor_b32_sdwa %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void s_addk_i32() {
    i32 sdst;
    __asm__ volatile("s_addk_i32 %0, %1 \n" : "=s"(sdst) : "i"(0));
}

__global__ void s_call_b64() {
    b64 sdst;
    __asm__ volatile("s_call_b64 %0, %1 \n" : "=s"(sdst) : "i"(0));
}

__global__ void s_cbranch_i_fork() {
    b64 ssrc;
    __asm__ volatile("s_cbranch_i_fork %0, %1 \n" :  : "s"(ssrc), "i"(0));
}

__global__ void s_cmovk_i32() {
    i32 sdst;
    __asm__ volatile("s_cmovk_i32 %0, %1 \n" : "=s"(sdst) : "i"(0));
}

__global__ void s_cmpk_eq_i32() {
    i32 ssrc;
    __asm__ volatile("s_cmpk_eq_i32 %0, %1 \n" :  : "s"(ssrc), "i"(0));
}

__global__ void s_cmpk_eq_u32() {
    u32 ssrc;
    __asm__ volatile("s_cmpk_eq_u32 %0, %1 \n" :  : "s"(ssrc), "i"(0));
}

__global__ void s_cmpk_ge_i32() {
    i32 ssrc;
    __asm__ volatile("s_cmpk_ge_i32 %0, %1 \n" :  : "s"(ssrc), "i"(0));
}

__global__ void s_cmpk_ge_u32() {
    u32 ssrc;
    __asm__ volatile("s_cmpk_ge_u32 %0, %1 \n" :  : "s"(ssrc), "i"(0));
}

__global__ void s_cmpk_gt_i32() {
    i32 ssrc;
    __asm__ volatile("s_cmpk_gt_i32 %0, %1 \n" :  : "s"(ssrc), "i"(0));
}

__global__ void s_cmpk_gt_u32() {
    u32 ssrc;
    __asm__ volatile("s_cmpk_gt_u32 %0, %1 \n" :  : "s"(ssrc), "i"(0));
}

__global__ void s_cmpk_le_i32() {
    i32 ssrc;
    __asm__ volatile("s_cmpk_le_i32 %0, %1 \n" :  : "s"(ssrc), "i"(0));
}

__global__ void s_cmpk_le_u32() {
    u32 ssrc;
    __asm__ volatile("s_cmpk_le_u32 %0, %1 \n" :  : "s"(ssrc), "i"(0));
}

__global__ void s_cmpk_lg_i32() {
    i32 ssrc;
    __asm__ volatile("s_cmpk_lg_i32 %0, %1 \n" :  : "s"(ssrc), "i"(0));
}

__global__ void s_cmpk_lg_u32() {
    u32 ssrc;
    __asm__ volatile("s_cmpk_lg_u32 %0, %1 \n" :  : "s"(ssrc), "i"(0));
}

__global__ void s_cmpk_lt_i32() {
    i32 ssrc;
    __asm__ volatile("s_cmpk_lt_i32 %0, %1 \n" :  : "s"(ssrc), "i"(0));
}

__global__ void s_cmpk_lt_u32() {
    u32 ssrc;
    __asm__ volatile("s_cmpk_lt_u32 %0, %1 \n" :  : "s"(ssrc), "i"(0));
}

__global__ void s_getreg_b32() {
    b32 sdst;
    __asm__ volatile("s_getreg_b32 %0, hwreg(1, 2, 4) \n" : "=s"(sdst) : );
}

__global__ void s_movk_i32() {
    i32 sdst;
    __asm__ volatile("s_movk_i32 %0, %1 \n" : "=s"(sdst) : "i"(0));
}

__global__ void s_mulk_i32() {
    i32 sdst;
    __asm__ volatile("s_mulk_i32 %0, %1 \n" : "=s"(sdst) : "i"(0));
}

__global__ void s_setreg_b32() {
    b32 ssrc;
    __asm__ volatile("s_setreg_b32 hwreg(1, 2, 4), %0 \n" :  : "s"(ssrc));
}

__global__ void s_setreg_imm32_b32() {
    ;
    __asm__ volatile("s_setreg_imm32_b32 hwreg(1, 2, 4), %0 \n" :  : "i"(0));
}

__global__ void v_cmp_class_f16_sdwa() {
    b64 sdst; f16 src0; b32 src1;
    __asm__ volatile("v_cmp_class_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_class_f32_sdwa() {
    b64 sdst; f32 src0; b32 src1;
    __asm__ volatile("v_cmp_class_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_eq_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_eq_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_eq_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_eq_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_eq_i16_sdwa() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmp_eq_i16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_eq_i32_sdwa() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmp_eq_i32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_eq_u16_sdwa() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmp_eq_u16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_eq_u32_sdwa() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmp_eq_u32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_f_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_f_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_f_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_f_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_f_i16_sdwa() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmp_f_i16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_f_i32_sdwa() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmp_f_i32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_f_u16_sdwa() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmp_f_u16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_f_u32_sdwa() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmp_f_u32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ge_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_ge_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ge_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_ge_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ge_i16_sdwa() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmp_ge_i16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ge_i32_sdwa() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmp_ge_i32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ge_u16_sdwa() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmp_ge_u16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ge_u32_sdwa() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmp_ge_u32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_gt_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_gt_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_gt_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_gt_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_gt_i16_sdwa() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmp_gt_i16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_gt_i32_sdwa() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmp_gt_i32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_gt_u16_sdwa() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmp_gt_u16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_gt_u32_sdwa() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmp_gt_u32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_le_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_le_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_le_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_le_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_le_i16_sdwa() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmp_le_i16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_le_i32_sdwa() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmp_le_i32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_le_u16_sdwa() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmp_le_u16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_le_u32_sdwa() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmp_le_u32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_lg_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_lg_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_lg_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_lg_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_lt_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_lt_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_lt_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_lt_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_lt_i16_sdwa() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmp_lt_i16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_lt_i32_sdwa() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmp_lt_i32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_lt_u16_sdwa() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmp_lt_u16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_lt_u32_sdwa() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmp_lt_u32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ne_i16_sdwa() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmp_ne_i16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ne_i32_sdwa() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmp_ne_i32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ne_u16_sdwa() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmp_ne_u16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ne_u32_sdwa() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmp_ne_u32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_neq_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_neq_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_neq_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_neq_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_nge_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_nge_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_nge_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_nge_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ngt_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_ngt_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ngt_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_ngt_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_nle_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_nle_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_nle_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_nle_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_nlg_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_nlg_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_nlg_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_nlg_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_nlt_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_nlt_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_nlt_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_nlt_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_o_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_o_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_o_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_o_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_t_i16_sdwa() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmp_t_i16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_t_i32_sdwa() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmp_t_i32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_t_u16_sdwa() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmp_t_u16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_t_u32_sdwa() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmp_t_u32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_tru_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_tru_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_tru_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_tru_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_u_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_u_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_u_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_u_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_class_f16_sdwa() {
    b64 sdst; f16 src0; b32 src1;
    __asm__ volatile("v_cmpx_class_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_class_f32_sdwa() {
    b64 sdst; f32 src0; b32 src1;
    __asm__ volatile("v_cmpx_class_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_eq_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_eq_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_eq_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_eq_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_eq_i16_sdwa() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmpx_eq_i16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_eq_i32_sdwa() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmpx_eq_i32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_eq_u16_sdwa() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmpx_eq_u16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_eq_u32_sdwa() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmpx_eq_u32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_f_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_f_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_f_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_f_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_f_i16_sdwa() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmpx_f_i16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_f_i32_sdwa() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmpx_f_i32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_f_u16_sdwa() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmpx_f_u16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_f_u32_sdwa() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmpx_f_u32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ge_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_ge_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ge_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_ge_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ge_i16_sdwa() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmpx_ge_i16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ge_i32_sdwa() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmpx_ge_i32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ge_u16_sdwa() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmpx_ge_u16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ge_u32_sdwa() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmpx_ge_u32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_gt_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_gt_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_gt_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_gt_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_gt_i16_sdwa() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmpx_gt_i16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_gt_i32_sdwa() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmpx_gt_i32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_gt_u16_sdwa() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmpx_gt_u16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_gt_u32_sdwa() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmpx_gt_u32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_le_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_le_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_le_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_le_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_le_i16_sdwa() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmpx_le_i16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_le_i32_sdwa() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmpx_le_i32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_le_u16_sdwa() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmpx_le_u16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_le_u32_sdwa() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmpx_le_u32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_lg_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_lg_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_lg_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_lg_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_lt_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_lt_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_lt_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_lt_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_lt_i16_sdwa() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmpx_lt_i16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_lt_i32_sdwa() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmpx_lt_i32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_lt_u16_sdwa() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmpx_lt_u16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_lt_u32_sdwa() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmpx_lt_u32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ne_i16_sdwa() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmpx_ne_i16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ne_i32_sdwa() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmpx_ne_i32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ne_u16_sdwa() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmpx_ne_u16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ne_u32_sdwa() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmpx_ne_u32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_neq_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_neq_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_neq_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_neq_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_nge_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_nge_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_nge_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_nge_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ngt_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_ngt_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ngt_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_ngt_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_nle_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_nle_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_nle_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_nle_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_nlg_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_nlg_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_nlg_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_nlg_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_nlt_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_nlt_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_nlt_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_nlt_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_o_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_o_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_o_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_o_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_t_i16_sdwa() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmpx_t_i16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_t_i32_sdwa() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmpx_t_i32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_t_u16_sdwa() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmpx_t_u16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_t_u32_sdwa() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmpx_t_u32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_tru_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_tru_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_tru_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_tru_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_u_f16_sdwa() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_u_f16_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_u_f32_sdwa() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_u_f32_sdwa %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void s_barrier() {
    ;
    __asm__ volatile("s_barrier  \n" :  : );
}

__global__ void s_branch() {
    ;
    __asm__ volatile("s_branch %0 \n" :  : "i"(0));
}

__global__ void s_cbranch_cdbgsys() {
    ;
    __asm__ volatile("s_cbranch_cdbgsys %0 \n" :  : "i"(0));
}

__global__ void s_cbranch_cdbgsys_and_user() {
    ;
    __asm__ volatile("s_cbranch_cdbgsys_and_user %0 \n" :  : "i"(0));
}

__global__ void s_cbranch_cdbgsys_or_user() {
    ;
    __asm__ volatile("s_cbranch_cdbgsys_or_user %0 \n" :  : "i"(0));
}

__global__ void s_cbranch_cdbguser() {
    ;
    __asm__ volatile("s_cbranch_cdbguser %0 \n" :  : "i"(0));
}

__global__ void s_cbranch_execnz() {
    ;
    __asm__ volatile("s_cbranch_execnz %0 \n" :  : "i"(0));
}

__global__ void s_cbranch_execz() {
    ;
    __asm__ volatile("s_cbranch_execz %0 \n" :  : "i"(0));
}

__global__ void s_cbranch_scc0() {
    ;
    __asm__ volatile("s_cbranch_scc0 %0 \n" :  : "i"(0));
}

__global__ void s_cbranch_scc1() {
    ;
    __asm__ volatile("s_cbranch_scc1 %0 \n" :  : "i"(0));
}

__global__ void s_cbranch_vccnz() {
    ;
    __asm__ volatile("s_cbranch_vccnz %0 \n" :  : "i"(0));
}

__global__ void s_cbranch_vccz() {
    ;
    __asm__ volatile("s_cbranch_vccz %0 \n" :  : "i"(0));
}

__global__ void s_decperflevel() {
    ;
    __asm__ volatile("s_decperflevel %0 \n" :  : "i"(0));
}

__global__ void s_endpgm() {
    ;
    __asm__ volatile("s_endpgm  \n" :  : );
}

__global__ void s_endpgm_ordered_ps_done() {
    ;
    __asm__ volatile("s_endpgm_ordered_ps_done  \n" :  : );
}

__global__ void s_endpgm_saved() {
    ;
    __asm__ volatile("s_endpgm_saved  \n" :  : );
}

__global__ void s_icache_inv() {
    ;
    __asm__ volatile("s_icache_inv  \n" :  : );
}

__global__ void s_incperflevel() {
    ;
    __asm__ volatile("s_incperflevel %0 \n" :  : "i"(0));
}

__global__ void s_nop() {
    ;
    __asm__ volatile("s_nop %0 \n" :  : "i"(0));
}

__global__ void s_sendmsg() {
    ;
    __asm__ volatile("s_sendmsg %0 \n" :  : "i"(0));
}

__global__ void s_sendmsghalt() {
    ;
    __asm__ volatile("s_sendmsghalt %0 \n" :  : "i"(0));
}

__global__ void s_set_gpr_idx_mode() {
    ;
    __asm__ volatile("s_set_gpr_idx_mode %0 \n" :  : "i"(0));
}

__global__ void s_set_gpr_idx_off() {
    ;
    __asm__ volatile("s_set_gpr_idx_off  \n" :  : );
}

__global__ void s_sethalt() {
    ;
    __asm__ volatile("s_sethalt %0 \n" :  : "i"(0));
}

__global__ void s_setkill() {
    ;
    __asm__ volatile("s_setkill %0 \n" :  : "i"(0));
}

__global__ void s_setprio() {
    ;
    __asm__ volatile("s_setprio %0 \n" :  : "i"(0));
}

__global__ void s_sleep() {
    ;
    __asm__ volatile("s_sleep %0 \n" :  : "i"(0));
}

__global__ void s_trap() {
    ;
    __asm__ volatile("s_trap %0 \n" :  : "i"(0));
}

__global__ void s_ttracedata() {
    ;
    __asm__ volatile("s_ttracedata  \n" :  : );
}

__global__ void s_waitcnt() {
    ;
    __asm__ volatile("s_waitcnt %0 \n" :  : "i"(0));
}

__global__ void s_wakeup() {
    ;
    __asm__ volatile("s_wakeup  \n" :  : );
}

__global__ void s_absdiff_i32() {
    i32 sdst; i32 ssrc0; i32 ssrc1;
    __asm__ volatile("s_absdiff_i32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_add_i32() {
    i32 sdst; i32 ssrc0; i32 ssrc1;
    __asm__ volatile("s_add_i32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_add_u32() {
    u32 sdst; u32 ssrc0; u32 ssrc1;
    __asm__ volatile("s_add_u32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_addc_u32() {
    u32 sdst; u32 ssrc0; u32 ssrc1;
    __asm__ volatile("s_addc_u32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_and_b32() {
    b32 sdst; b32 ssrc0; b32 ssrc1;
    __asm__ volatile("s_and_b32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_and_b64() {
    b64 sdst; b64 ssrc0; b64 ssrc1;
    __asm__ volatile("s_and_b64 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_andn2_b32() {
    b32 sdst; b32 ssrc0; b32 ssrc1;
    __asm__ volatile("s_andn2_b32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_andn2_b64() {
    b64 sdst; b64 ssrc0; b64 ssrc1;
    __asm__ volatile("s_andn2_b64 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_ashr_i32() {
    i32 sdst; i32 ssrc0; u32 ssrc1;
    __asm__ volatile("s_ashr_i32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_ashr_i64() {
    i64 sdst; i64 ssrc0; u32 ssrc1;
    __asm__ volatile("s_ashr_i64 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_bfe_i32() {
    i32 sdst; i32 ssrc0; u32 ssrc1;
    __asm__ volatile("s_bfe_i32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_bfe_i64() {
    i64 sdst; i64 ssrc0; u32 ssrc1;
    __asm__ volatile("s_bfe_i64 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_bfe_u32() {
    u32 sdst; u32 ssrc0; u32 ssrc1;
    __asm__ volatile("s_bfe_u32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_bfe_u64() {
    u64 sdst; u64 ssrc0; u32 ssrc1;
    __asm__ volatile("s_bfe_u64 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_bfm_b32() {
    b32 sdst; b32 ssrc0; b32 ssrc1;
    __asm__ volatile("s_bfm_b32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_bfm_b64() {
    b64 sdst; b32 ssrc0; b32 ssrc1;
    __asm__ volatile("s_bfm_b64 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_cbranch_g_fork() {
    b64 ssrc0; b64 ssrc1;
    __asm__ volatile("s_cbranch_g_fork %0, %1 \n" :  : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_cselect_b32() {
    b32 sdst; b32 ssrc0; b32 ssrc1;
    __asm__ volatile("s_cselect_b32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_cselect_b64() {
    b64 sdst; b64 ssrc0; b64 ssrc1;
    __asm__ volatile("s_cselect_b64 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_lshl1_add_u32() {
    u32 sdst; u32 ssrc0; u32 ssrc1;
    __asm__ volatile("s_lshl1_add_u32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_lshl2_add_u32() {
    u32 sdst; u32 ssrc0; u32 ssrc1;
    __asm__ volatile("s_lshl2_add_u32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_lshl3_add_u32() {
    u32 sdst; u32 ssrc0; u32 ssrc1;
    __asm__ volatile("s_lshl3_add_u32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_lshl4_add_u32() {
    u32 sdst; u32 ssrc0; u32 ssrc1;
    __asm__ volatile("s_lshl4_add_u32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_lshl_b32() {
    b32 sdst; b32 ssrc0; u32 ssrc1;
    __asm__ volatile("s_lshl_b32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_lshl_b64() {
    b64 sdst; b64 ssrc0; u32 ssrc1;
    __asm__ volatile("s_lshl_b64 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_lshr_b32() {
    b32 sdst; b32 ssrc0; u32 ssrc1;
    __asm__ volatile("s_lshr_b32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_lshr_b64() {
    b64 sdst; b64 ssrc0; u32 ssrc1;
    __asm__ volatile("s_lshr_b64 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_max_i32() {
    i32 sdst; i32 ssrc0; i32 ssrc1;
    __asm__ volatile("s_max_i32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_max_u32() {
    u32 sdst; u32 ssrc0; u32 ssrc1;
    __asm__ volatile("s_max_u32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_min_i32() {
    i32 sdst; i32 ssrc0; i32 ssrc1;
    __asm__ volatile("s_min_i32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_min_u32() {
    u32 sdst; u32 ssrc0; u32 ssrc1;
    __asm__ volatile("s_min_u32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_mul_hi_i32() {
    i32 sdst; i32 ssrc0; i32 ssrc1;
    __asm__ volatile("s_mul_hi_i32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_mul_hi_u32() {
    u32 sdst; u32 ssrc0; u32 ssrc1;
    __asm__ volatile("s_mul_hi_u32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_mul_i32() {
    i32 sdst; i32 ssrc0; i32 ssrc1;
    __asm__ volatile("s_mul_i32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_nand_b32() {
    b32 sdst; b32 ssrc0; b32 ssrc1;
    __asm__ volatile("s_nand_b32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_nand_b64() {
    b64 sdst; b64 ssrc0; b64 ssrc1;
    __asm__ volatile("s_nand_b64 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_nor_b32() {
    b32 sdst; b32 ssrc0; b32 ssrc1;
    __asm__ volatile("s_nor_b32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_nor_b64() {
    b64 sdst; b64 ssrc0; b64 ssrc1;
    __asm__ volatile("s_nor_b64 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_or_b32() {
    b32 sdst; b32 ssrc0; b32 ssrc1;
    __asm__ volatile("s_or_b32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_or_b64() {
    b64 sdst; b64 ssrc0; b64 ssrc1;
    __asm__ volatile("s_or_b64 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_orn2_b32() {
    b32 sdst; b32 ssrc0; b32 ssrc1;
    __asm__ volatile("s_orn2_b32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_orn2_b64() {
    b64 sdst; b64 ssrc0; b64 ssrc1;
    __asm__ volatile("s_orn2_b64 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_pack_hh_b32_b16() {
    b32 sdst; b32 ssrc0; b32 ssrc1;
    __asm__ volatile("s_pack_hh_b32_b16 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_pack_lh_b32_b16() {
    b32 sdst; b16 ssrc0; b32 ssrc1;
    __asm__ volatile("s_pack_lh_b32_b16 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_pack_ll_b32_b16() {
    b32 sdst; b16 ssrc0; b16 ssrc1;
    __asm__ volatile("s_pack_ll_b32_b16 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_rfe_restore_b64() {
    b64 ssrc0; b32 ssrc1;
    __asm__ volatile("s_rfe_restore_b64 %0, %1 \n" :  : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_sub_i32() {
    i32 sdst; i32 ssrc0; i32 ssrc1;
    __asm__ volatile("s_sub_i32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_sub_u32() {
    u32 sdst; u32 ssrc0; u32 ssrc1;
    __asm__ volatile("s_sub_u32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_subb_u32() {
    u32 sdst; u32 ssrc0; u32 ssrc1;
    __asm__ volatile("s_subb_u32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_xnor_b32() {
    b32 sdst; b32 ssrc0; b32 ssrc1;
    __asm__ volatile("s_xnor_b32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_xnor_b64() {
    b64 sdst; b64 ssrc0; b64 ssrc1;
    __asm__ volatile("s_xnor_b64 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_xor_b32() {
    b32 sdst; b32 ssrc0; b32 ssrc1;
    __asm__ volatile("s_xor_b32 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void s_xor_b64() {
    b64 sdst; b64 ssrc0; b64 ssrc1;
    __asm__ volatile("s_xor_b64 %0, %1, %2 \n" : "=s"(sdst) : "s"(ssrc0), "s"(ssrc1));
}

__global__ void v_accvgpr_mov_b32() {
    b32 vdst; b32 vsrc;
    __asm__ volatile("v_accvgpr_mov_b32 %0, %1 \n" : "=a"(vdst) : "a"(vsrc));
}

__global__ void v_bfrev_b32() {
    b32 vdst; b32 src;
    __asm__ volatile("v_bfrev_b32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_ceil_f16() {
    f16 vdst; f16 src;
    __asm__ volatile("v_ceil_f16 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_ceil_f32() {
    f32 vdst; f32 src;
    __asm__ volatile("v_ceil_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_ceil_f64() {
    f64 vdst; f64 src;
    __asm__ volatile("v_ceil_f64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_clrexcp() {
    ;
    __asm__ volatile("v_clrexcp  \n" :  : );
}

__global__ void v_cos_f16() {
    f16 vdst; f16 src;
    __asm__ volatile("v_cos_f16 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cos_f32() {
    f32 vdst; f32 src;
    __asm__ volatile("v_cos_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f16_f32() {
    f16 vdst; f32 src;
    __asm__ volatile("v_cvt_f16_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f16_i16() {
    f16 vdst; i16 src;
    __asm__ volatile("v_cvt_f16_i16 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f16_u16() {
    f16 vdst; u16 src;
    __asm__ volatile("v_cvt_f16_u16 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_f16() {
    f32 vdst; f16 src;
    __asm__ volatile("v_cvt_f32_f16 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_f64() {
    f32 vdst; f64 src;
    __asm__ volatile("v_cvt_f32_f64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_i32() {
    f32 vdst; i32 src;
    __asm__ volatile("v_cvt_f32_i32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_u32() {
    f32 vdst; u32 src;
    __asm__ volatile("v_cvt_f32_u32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_ubyte0() {
    b32 vdst; b32 src;
    __asm__ volatile("v_cvt_f32_ubyte0 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_ubyte1() {
    b32 vdst; b32 src;
    __asm__ volatile("v_cvt_f32_ubyte1 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_ubyte2() {
    b32 vdst; b32 src;
    __asm__ volatile("v_cvt_f32_ubyte2 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_ubyte3() {
    b32 vdst; b32 src;
    __asm__ volatile("v_cvt_f32_ubyte3 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f64_f32() {
    f64 vdst; f32 src;
    __asm__ volatile("v_cvt_f64_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f64_i32() {
    f64 vdst; i32 src;
    __asm__ volatile("v_cvt_f64_i32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f64_u32() {
    f64 vdst; u32 src;
    __asm__ volatile("v_cvt_f64_u32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_flr_i32_f32() {
    i32 vdst; f32 src;
    __asm__ volatile("v_cvt_flr_i32_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_i16_f16() {
    i16 vdst; f16 src;
    __asm__ volatile("v_cvt_i16_f16 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_i32_f32() {
    i32 vdst; f32 src;
    __asm__ volatile("v_cvt_i32_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_i32_f64() {
    i32 vdst; f64 src;
    __asm__ volatile("v_cvt_i32_f64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_norm_i16_f16() {
    i16 vdst; f16 src;
    __asm__ volatile("v_cvt_norm_i16_f16 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_norm_u16_f16() {
    u16 vdst; f16 src;
    __asm__ volatile("v_cvt_norm_u16_f16 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_off_f32_i4() {
    f32 vdst; i4 src;
    __asm__ volatile("v_cvt_off_f32_i4 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_rpi_i32_f32() {
    i32 vdst; f32 src;
    __asm__ volatile("v_cvt_rpi_i32_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_u16_f16() {
    u16 vdst; f16 src;
    __asm__ volatile("v_cvt_u16_f16 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_u32_f32() {
    u32 vdst; f32 src;
    __asm__ volatile("v_cvt_u32_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_u32_f64() {
    u32 vdst; f64 src;
    __asm__ volatile("v_cvt_u32_f64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_exp_f16() {
    f16 vdst; f16 src;
    __asm__ volatile("v_exp_f16 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_exp_f32() {
    f32 vdst; f32 src;
    __asm__ volatile("v_exp_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_exp_legacy_f32() {
    f32 vdst; f32 src;
    __asm__ volatile("v_exp_legacy_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_ffbh_i32() {
    i32 vdst; i32 src;
    __asm__ volatile("v_ffbh_i32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_ffbh_u32() {
    u32 vdst; u32 src;
    __asm__ volatile("v_ffbh_u32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_ffbl_b32() {
    b32 vdst; b32 src;
    __asm__ volatile("v_ffbl_b32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_floor_f16() {
    f16 vdst; f16 src;
    __asm__ volatile("v_floor_f16 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_floor_f32() {
    f32 vdst; f32 src;
    __asm__ volatile("v_floor_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_floor_f64() {
    f64 vdst; f64 src;
    __asm__ volatile("v_floor_f64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_fract_f16() {
    f16 vdst; f16 src;
    __asm__ volatile("v_fract_f16 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_fract_f32() {
    f32 vdst; f32 src;
    __asm__ volatile("v_fract_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_fract_f64() {
    f64 vdst; f64 src;
    __asm__ volatile("v_fract_f64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_frexp_exp_i16_f16() {
    i16 vdst; f16 src;
    __asm__ volatile("v_frexp_exp_i16_f16 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_frexp_exp_i32_f32() {
    i32 vdst; f32 src;
    __asm__ volatile("v_frexp_exp_i32_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_frexp_exp_i32_f64() {
    i32 vdst; f64 src;
    __asm__ volatile("v_frexp_exp_i32_f64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_frexp_mant_f16() {
    f16 vdst; f16 src;
    __asm__ volatile("v_frexp_mant_f16 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_frexp_mant_f32() {
    f32 vdst; f32 src;
    __asm__ volatile("v_frexp_mant_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_frexp_mant_f64() {
    f64 vdst; f64 src;
    __asm__ volatile("v_frexp_mant_f64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_log_f16() {
    f16 vdst; f16 src;
    __asm__ volatile("v_log_f16 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_log_f32() {
    f32 vdst; f32 src;
    __asm__ volatile("v_log_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_log_legacy_f32() {
    f32 vdst; f32 src;
    __asm__ volatile("v_log_legacy_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_mov_b32() {
    b32 vdst; b32 src;
    __asm__ volatile("v_mov_b32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_nop() {
    ;
    __asm__ volatile("v_nop  \n" :  : );
}

__global__ void v_not_b32() {
    b32 vdst; b32 src;
    __asm__ volatile("v_not_b32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rcp_f16() {
    f16 vdst; f16 src;
    __asm__ volatile("v_rcp_f16 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rcp_f32() {
    f32 vdst; f32 src;
    __asm__ volatile("v_rcp_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rcp_f64() {
    f64 vdst; f64 src;
    __asm__ volatile("v_rcp_f64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rcp_iflag_f32() {
    f32 vdst; f32 src;
    __asm__ volatile("v_rcp_iflag_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_readfirstlane_b32() {
    b32 sdst; b32 vsrc;
    __asm__ volatile("v_readfirstlane_b32 %0, %1 \n" : "=s"(sdst) : "v"(vsrc));
}

__global__ void v_rndne_f16() {
    f16 vdst; f16 src;
    __asm__ volatile("v_rndne_f16 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rndne_f32() {
    f32 vdst; f32 src;
    __asm__ volatile("v_rndne_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rndne_f64() {
    f64 vdst; f64 src;
    __asm__ volatile("v_rndne_f64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rsq_f16() {
    f16 vdst; f16 src;
    __asm__ volatile("v_rsq_f16 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rsq_f32() {
    f32 vdst; f32 src;
    __asm__ volatile("v_rsq_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rsq_f64() {
    f64 vdst; f64 src;
    __asm__ volatile("v_rsq_f64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_sat_pk_u8_i16() {
    u8x4 vdst; i16 src;
    __asm__ volatile("v_sat_pk_u8_i16 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_screen_partition_4se_b32() {
    b32 vdst; b32 src;
    __asm__ volatile("v_screen_partition_4se_b32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_sin_f16() {
    f16 vdst; f16 src;
    __asm__ volatile("v_sin_f16 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_sin_f32() {
    f32 vdst; f32 src;
    __asm__ volatile("v_sin_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_sqrt_f16() {
    f16 vdst; f16 src;
    __asm__ volatile("v_sqrt_f16 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_sqrt_f32() {
    f32 vdst; f32 src;
    __asm__ volatile("v_sqrt_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_sqrt_f64() {
    f64 vdst; f64 src;
    __asm__ volatile("v_sqrt_f64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_swap_b32() {
    b32 vdst; b32 vsrc;
    __asm__ volatile("v_swap_b32 %0, %1 \n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_trunc_f16() {
    f16 vdst; f16 src;
    __asm__ volatile("v_trunc_f16 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_trunc_f32() {
    f32 vdst; f32 src;
    __asm__ volatile("v_trunc_f32 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_trunc_f64() {
    f64 vdst; f64 src;
    __asm__ volatile("v_trunc_f64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_bfrev_b32_dpp() {
    b32 vdst; b32 vsrc;
    __asm__ volatile("v_bfrev_b32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_ceil_f16_dpp() {
    f16 vdst; f16 vsrc;
    __asm__ volatile("v_ceil_f16_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_ceil_f32_dpp() {
    f32 vdst; f32 vsrc;
    __asm__ volatile("v_ceil_f32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_ceil_f64_dpp() {
    f64 vdst; f64 vsrc;
    __asm__ volatile("v_ceil_f64_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cos_f16_dpp() {
    f16 vdst; f16 vsrc;
    __asm__ volatile("v_cos_f16_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cos_f32_dpp() {
    f32 vdst; f32 vsrc;
    __asm__ volatile("v_cos_f32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cvt_f16_f32_dpp() {
    f16 vdst; f32 vsrc;
    __asm__ volatile("v_cvt_f16_f32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cvt_f16_i16_dpp() {
    f16 vdst; i16 vsrc;
    __asm__ volatile("v_cvt_f16_i16_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cvt_f16_u16_dpp() {
    f16 vdst; u16 vsrc;
    __asm__ volatile("v_cvt_f16_u16_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cvt_f32_f16_dpp() {
    f32 vdst; f16 vsrc;
    __asm__ volatile("v_cvt_f32_f16_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cvt_f32_f64_dpp() {
    f32 vdst; f64 vsrc;
    __asm__ volatile("v_cvt_f32_f64_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cvt_f32_i32_dpp() {
    f32 vdst; i32 vsrc;
    __asm__ volatile("v_cvt_f32_i32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cvt_f32_u32_dpp() {
    f32 vdst; u32 vsrc;
    __asm__ volatile("v_cvt_f32_u32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cvt_f32_ubyte0_dpp() {
    b32 vdst; b32 vsrc;
    __asm__ volatile("v_cvt_f32_ubyte0_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cvt_f32_ubyte1_dpp() {
    b32 vdst; b32 vsrc;
    __asm__ volatile("v_cvt_f32_ubyte1_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cvt_f32_ubyte2_dpp() {
    b32 vdst; b32 vsrc;
    __asm__ volatile("v_cvt_f32_ubyte2_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cvt_f32_ubyte3_dpp() {
    b32 vdst; b32 vsrc;
    __asm__ volatile("v_cvt_f32_ubyte3_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cvt_flr_i32_f32_dpp() {
    i32 vdst; f32 vsrc;
    __asm__ volatile("v_cvt_flr_i32_f32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cvt_i16_f16_dpp() {
    i16 vdst; f16 vsrc;
    __asm__ volatile("v_cvt_i16_f16_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cvt_i32_f32_dpp() {
    i32 vdst; f32 vsrc;
    __asm__ volatile("v_cvt_i32_f32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cvt_i32_f64_dpp() {
    i32 vdst; f64 vsrc;
    __asm__ volatile("v_cvt_i32_f64_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cvt_norm_i16_f16_dpp() {
    i16 vdst; f16 vsrc;
    __asm__ volatile("v_cvt_norm_i16_f16_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cvt_norm_u16_f16_dpp() {
    u16 vdst; f16 vsrc;
    __asm__ volatile("v_cvt_norm_u16_f16_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cvt_off_f32_i4_dpp() {
    f32 vdst; i4 vsrc;
    __asm__ volatile("v_cvt_off_f32_i4_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cvt_rpi_i32_f32_dpp() {
    i32 vdst; f32 vsrc;
    __asm__ volatile("v_cvt_rpi_i32_f32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cvt_u16_f16_dpp() {
    u16 vdst; f16 vsrc;
    __asm__ volatile("v_cvt_u16_f16_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cvt_u32_f32_dpp() {
    u32 vdst; f32 vsrc;
    __asm__ volatile("v_cvt_u32_f32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_cvt_u32_f64_dpp() {
    u32 vdst; f64 vsrc;
    __asm__ volatile("v_cvt_u32_f64_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_exp_f16_dpp() {
    f16 vdst; f16 vsrc;
    __asm__ volatile("v_exp_f16_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_exp_f32_dpp() {
    f32 vdst; f32 vsrc;
    __asm__ volatile("v_exp_f32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_exp_legacy_f32_dpp() {
    f32 vdst; f32 vsrc;
    __asm__ volatile("v_exp_legacy_f32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_ffbh_i32_dpp() {
    i32 vdst; i32 vsrc;
    __asm__ volatile("v_ffbh_i32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_ffbh_u32_dpp() {
    u32 vdst; u32 vsrc;
    __asm__ volatile("v_ffbh_u32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_ffbl_b32_dpp() {
    b32 vdst; b32 vsrc;
    __asm__ volatile("v_ffbl_b32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_floor_f16_dpp() {
    f16 vdst; f16 vsrc;
    __asm__ volatile("v_floor_f16_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_floor_f32_dpp() {
    f32 vdst; f32 vsrc;
    __asm__ volatile("v_floor_f32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_floor_f64_dpp() {
    f64 vdst; f64 vsrc;
    __asm__ volatile("v_floor_f64_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_fract_f16_dpp() {
    f16 vdst; f16 vsrc;
    __asm__ volatile("v_fract_f16_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_fract_f32_dpp() {
    f32 vdst; f32 vsrc;
    __asm__ volatile("v_fract_f32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_fract_f64_dpp() {
    f64 vdst; f64 vsrc;
    __asm__ volatile("v_fract_f64_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_frexp_exp_i16_f16_dpp() {
    i16 vdst; f16 vsrc;
    __asm__ volatile("v_frexp_exp_i16_f16_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_frexp_exp_i32_f32_dpp() {
    i32 vdst; f32 vsrc;
    __asm__ volatile("v_frexp_exp_i32_f32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_frexp_exp_i32_f64_dpp() {
    i32 vdst; f64 vsrc;
    __asm__ volatile("v_frexp_exp_i32_f64_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_frexp_mant_f16_dpp() {
    f16 vdst; f16 vsrc;
    __asm__ volatile("v_frexp_mant_f16_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_frexp_mant_f32_dpp() {
    f32 vdst; f32 vsrc;
    __asm__ volatile("v_frexp_mant_f32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_frexp_mant_f64_dpp() {
    f64 vdst; f64 vsrc;
    __asm__ volatile("v_frexp_mant_f64_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_log_f16_dpp() {
    f16 vdst; f16 vsrc;
    __asm__ volatile("v_log_f16_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_log_f32_dpp() {
    f32 vdst; f32 vsrc;
    __asm__ volatile("v_log_f32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_log_legacy_f32_dpp() {
    f32 vdst; f32 vsrc;
    __asm__ volatile("v_log_legacy_f32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_mov_b32_dpp() {
    b32 vdst; b32 vsrc;
    __asm__ volatile("v_mov_b32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_not_b32_dpp() {
    b32 vdst; b32 vsrc;
    __asm__ volatile("v_not_b32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_rcp_f16_dpp() {
    f16 vdst; f16 vsrc;
    __asm__ volatile("v_rcp_f16_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_rcp_f32_dpp() {
    f32 vdst; f32 vsrc;
    __asm__ volatile("v_rcp_f32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_rcp_iflag_f32_dpp() {
    f32 vdst; f32 vsrc;
    __asm__ volatile("v_rcp_iflag_f32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_rndne_f16_dpp() {
    f16 vdst; f16 vsrc;
    __asm__ volatile("v_rndne_f16_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_rndne_f32_dpp() {
    f32 vdst; f32 vsrc;
    __asm__ volatile("v_rndne_f32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_rsq_f16_dpp() {
    f16 vdst; f16 vsrc;
    __asm__ volatile("v_rsq_f16_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_rsq_f32_dpp() {
    f32 vdst; f32 vsrc;
    __asm__ volatile("v_rsq_f32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_sat_pk_u8_i16_dpp() {
    u8x4 vdst; i16 vsrc;
    __asm__ volatile("v_sat_pk_u8_i16_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_screen_partition_4se_b32_dpp() {
    b32 vdst; b32 vsrc;
    __asm__ volatile("v_screen_partition_4se_b32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_sin_f16_dpp() {
    f16 vdst; f16 vsrc;
    __asm__ volatile("v_sin_f16_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_sin_f32_dpp() {
    f32 vdst; f32 vsrc;
    __asm__ volatile("v_sin_f32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_sqrt_f16_dpp() {
    f16 vdst; f16 vsrc;
    __asm__ volatile("v_sqrt_f16_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_sqrt_f32_dpp() {
    f32 vdst; f32 vsrc;
    __asm__ volatile("v_sqrt_f32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_trunc_f16_dpp() {
    f16 vdst; f16 vsrc;
    __asm__ volatile("v_trunc_f16_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_trunc_f32_dpp() {
    f32 vdst; f32 vsrc;
    __asm__ volatile("v_trunc_f32_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_trunc_f64_dpp() {
    f64 vdst; f64 vsrc;
    __asm__ volatile("v_trunc_f64_dpp %0, %1 row_newbcast:1\n" : "=v"(vdst) : "v"(vsrc));
}

__global__ void v_bfrev_b32_sdwa() {
    b32 vdst; b32 src;
    __asm__ volatile("v_bfrev_b32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_ceil_f16_sdwa() {
    f16 vdst; f16 src;
    __asm__ volatile("v_ceil_f16_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_ceil_f32_sdwa() {
    f32 vdst; f32 src;
    __asm__ volatile("v_ceil_f32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cos_f16_sdwa() {
    f16 vdst; f16 src;
    __asm__ volatile("v_cos_f16_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cos_f32_sdwa() {
    f32 vdst; f32 src;
    __asm__ volatile("v_cos_f32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f16_f32_sdwa() {
    f16 vdst; f32 src;
    __asm__ volatile("v_cvt_f16_f32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f16_i16_sdwa() {
    f16 vdst; i16 src;
    __asm__ volatile("v_cvt_f16_i16_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f16_u16_sdwa() {
    f16 vdst; u16 src;
    __asm__ volatile("v_cvt_f16_u16_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_f16_sdwa() {
    f32 vdst; f16 src;
    __asm__ volatile("v_cvt_f32_f16_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_i32_sdwa() {
    f32 vdst; i32 src;
    __asm__ volatile("v_cvt_f32_i32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_u32_sdwa() {
    f32 vdst; u32 src;
    __asm__ volatile("v_cvt_f32_u32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_ubyte0_sdwa() {
    b32 vdst; b32 src;
    __asm__ volatile("v_cvt_f32_ubyte0_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_ubyte1_sdwa() {
    b32 vdst; b32 src;
    __asm__ volatile("v_cvt_f32_ubyte1_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_ubyte2_sdwa() {
    b32 vdst; b32 src;
    __asm__ volatile("v_cvt_f32_ubyte2_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_ubyte3_sdwa() {
    b32 vdst; b32 src;
    __asm__ volatile("v_cvt_f32_ubyte3_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_flr_i32_f32_sdwa() {
    i32 vdst; f32 src;
    __asm__ volatile("v_cvt_flr_i32_f32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_i16_f16_sdwa() {
    i16 vdst; f16 src;
    __asm__ volatile("v_cvt_i16_f16_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_i32_f32_sdwa() {
    i32 vdst; f32 src;
    __asm__ volatile("v_cvt_i32_f32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_norm_i16_f16_sdwa() {
    i16 vdst; f16 src;
    __asm__ volatile("v_cvt_norm_i16_f16_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_norm_u16_f16_sdwa() {
    u16 vdst; f16 src;
    __asm__ volatile("v_cvt_norm_u16_f16_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_off_f32_i4_sdwa() {
    f32 vdst; i4 src;
    __asm__ volatile("v_cvt_off_f32_i4_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_rpi_i32_f32_sdwa() {
    i32 vdst; f32 src;
    __asm__ volatile("v_cvt_rpi_i32_f32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_u16_f16_sdwa() {
    u16 vdst; f16 src;
    __asm__ volatile("v_cvt_u16_f16_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_u32_f32_sdwa() {
    u32 vdst; f32 src;
    __asm__ volatile("v_cvt_u32_f32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_exp_f16_sdwa() {
    f16 vdst; f16 src;
    __asm__ volatile("v_exp_f16_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_exp_f32_sdwa() {
    f32 vdst; f32 src;
    __asm__ volatile("v_exp_f32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_exp_legacy_f32_sdwa() {
    f32 vdst; f32 src;
    __asm__ volatile("v_exp_legacy_f32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_ffbh_i32_sdwa() {
    i32 vdst; i32 src;
    __asm__ volatile("v_ffbh_i32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_ffbh_u32_sdwa() {
    u32 vdst; u32 src;
    __asm__ volatile("v_ffbh_u32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_ffbl_b32_sdwa() {
    b32 vdst; b32 src;
    __asm__ volatile("v_ffbl_b32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_floor_f16_sdwa() {
    f16 vdst; f16 src;
    __asm__ volatile("v_floor_f16_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_floor_f32_sdwa() {
    f32 vdst; f32 src;
    __asm__ volatile("v_floor_f32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_fract_f16_sdwa() {
    f16 vdst; f16 src;
    __asm__ volatile("v_fract_f16_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_fract_f32_sdwa() {
    f32 vdst; f32 src;
    __asm__ volatile("v_fract_f32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_frexp_exp_i16_f16_sdwa() {
    i16 vdst; f16 src;
    __asm__ volatile("v_frexp_exp_i16_f16_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_frexp_exp_i32_f32_sdwa() {
    i32 vdst; f32 src;
    __asm__ volatile("v_frexp_exp_i32_f32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_frexp_mant_f16_sdwa() {
    f16 vdst; f16 src;
    __asm__ volatile("v_frexp_mant_f16_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_frexp_mant_f32_sdwa() {
    f32 vdst; f32 src;
    __asm__ volatile("v_frexp_mant_f32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_log_f16_sdwa() {
    f16 vdst; f16 src;
    __asm__ volatile("v_log_f16_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_log_f32_sdwa() {
    f32 vdst; f32 src;
    __asm__ volatile("v_log_f32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_log_legacy_f32_sdwa() {
    f32 vdst; f32 src;
    __asm__ volatile("v_log_legacy_f32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_mov_b32_sdwa() {
    b32 vdst; b32 src;
    __asm__ volatile("v_mov_b32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_not_b32_sdwa() {
    b32 vdst; b32 src;
    __asm__ volatile("v_not_b32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rcp_f16_sdwa() {
    f16 vdst; f16 src;
    __asm__ volatile("v_rcp_f16_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rcp_f32_sdwa() {
    f32 vdst; f32 src;
    __asm__ volatile("v_rcp_f32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rcp_iflag_f32_sdwa() {
    f32 vdst; f32 src;
    __asm__ volatile("v_rcp_iflag_f32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rndne_f16_sdwa() {
    f16 vdst; f16 src;
    __asm__ volatile("v_rndne_f16_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rndne_f32_sdwa() {
    f32 vdst; f32 src;
    __asm__ volatile("v_rndne_f32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rsq_f16_sdwa() {
    f16 vdst; f16 src;
    __asm__ volatile("v_rsq_f16_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rsq_f32_sdwa() {
    f32 vdst; f32 src;
    __asm__ volatile("v_rsq_f32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_sat_pk_u8_i16_sdwa() {
    u8x4 vdst; i16 src;
    __asm__ volatile("v_sat_pk_u8_i16_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_screen_partition_4se_b32_sdwa() {
    b32 vdst; b32 src;
    __asm__ volatile("v_screen_partition_4se_b32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_sin_f16_sdwa() {
    f16 vdst; f16 src;
    __asm__ volatile("v_sin_f16_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_sin_f32_sdwa() {
    f32 vdst; f32 src;
    __asm__ volatile("v_sin_f32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_sqrt_f16_sdwa() {
    f16 vdst; f16 src;
    __asm__ volatile("v_sqrt_f16_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_sqrt_f32_sdwa() {
    f32 vdst; f32 src;
    __asm__ volatile("v_sqrt_f32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_trunc_f16_sdwa() {
    f16 vdst; f16 src;
    __asm__ volatile("v_trunc_f16_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_trunc_f32_sdwa() {
    f32 vdst; f32 src;
    __asm__ volatile("v_trunc_f32_sdwa %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_add3_u32() {
    u32 vdst; u32 src0; u32 src1; u32 src2;
    __asm__ volatile("v_add3_u32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_add_f16_e64() {
    f16 vdst; f16 src0; f16 src1;
    __asm__ volatile("v_add_f16_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_add_f32_e64() {
    f32 vdst; f32 src0; f32 src1;
    __asm__ volatile("v_add_f32_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_add_f64() {
    f64 vdst; f64 src0; f64 src1;
    __asm__ volatile("v_add_f64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_add_i16() {
    i16 vdst; i16 src0; i16 src1;
    __asm__ volatile("v_add_i16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_add_i32() {
    i32 vdst; i32 src0; i32 src1;
    __asm__ volatile("v_add_i32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_add_lshl_u32() {
    u32 vdst; u32 src0; u32 src1; u32 src2;
    __asm__ volatile("v_add_lshl_u32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_add_u16_e64() {
    u16 vdst; u16 src0; u16 src1;
    __asm__ volatile("v_add_u16_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_add_u32_e64() {
    u32 vdst; u32 src0; u32 src1;
    __asm__ volatile("v_add_u32_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_alignbit_b32() {
    b32 vdst; b32 src0; b32 src1; b16 src2;
    __asm__ volatile("v_alignbit_b32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_alignbyte_b32() {
    b32 vdst; b32 src0; b32 src1; b16 src2;
    __asm__ volatile("v_alignbyte_b32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_and_b32_e64() {
    b32 vdst; b32 src0; b32 src1;
    __asm__ volatile("v_and_b32_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_and_or_b32() {
    b32 vdst; b32 src0; b32 src1; b32 src2;
    __asm__ volatile("v_and_or_b32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_ashrrev_i16_e64() {
    i16 vdst; u16 src0; i16 src1;
    __asm__ volatile("v_ashrrev_i16_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_ashrrev_i32_e64() {
    i32 vdst; u32 src0; i32 src1;
    __asm__ volatile("v_ashrrev_i32_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_ashrrev_i64() {
    i64 vdst; u32 src0; i64 src1;
    __asm__ volatile("v_ashrrev_i64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_bcnt_u32_b32() {
    u32 vdst; b32 src0; b32 src1;
    __asm__ volatile("v_bcnt_u32_b32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_bfe_i32() {
    i32 vdst; i32 src0; u32 src1; u32 src2;
    __asm__ volatile("v_bfe_i32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_bfe_u32() {
    u32 vdst; u32 src0; u32 src1; u32 src2;
    __asm__ volatile("v_bfe_u32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_bfi_b32() {
    b32 vdst; b32 src0; b32 src1; b32 src2;
    __asm__ volatile("v_bfi_b32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_bfm_b32() {
    b32 vdst; b32 src0; b32 src1;
    __asm__ volatile("v_bfm_b32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_bfrev_b32_e64() {
    b32 vdst; b32 src;
    __asm__ volatile("v_bfrev_b32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_ceil_f16_e64() {
    f16 vdst; f16 src;
    __asm__ volatile("v_ceil_f16_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_ceil_f32_e64() {
    f32 vdst; f32 src;
    __asm__ volatile("v_ceil_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_ceil_f64_e64() {
    f64 vdst; f64 src;
    __asm__ volatile("v_ceil_f64_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_clrexcp_e64() {
    ;
    __asm__ volatile("v_clrexcp_e64  \n" :  : );
}

__global__ void v_cmp_class_f16_e64() {
    b64 sdst; f16 src0; b32 src1;
    __asm__ volatile("v_cmp_class_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_class_f32_e64() {
    b64 sdst; f32 src0; b32 src1;
    __asm__ volatile("v_cmp_class_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_class_f64_e64() {
    f64 sdst; f64 src0; b32 src1;
    __asm__ volatile("v_cmp_class_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_eq_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_eq_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_eq_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_eq_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_eq_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmp_eq_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_eq_i16_e64() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmp_eq_i16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_eq_i32_e64() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmp_eq_i32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_eq_i64_e64() {
    i64 sdst; i64 src0; i64 src1;
    __asm__ volatile("v_cmp_eq_i64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_eq_u16_e64() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmp_eq_u16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_eq_u32_e64() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmp_eq_u32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_eq_u64_e64() {
    u64 sdst; u64 src0; u64 src1;
    __asm__ volatile("v_cmp_eq_u64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_f_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_f_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_f_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_f_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_f_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmp_f_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_f_i16_e64() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmp_f_i16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_f_i32_e64() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmp_f_i32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_f_i64_e64() {
    i64 sdst; i64 src0; i64 src1;
    __asm__ volatile("v_cmp_f_i64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_f_u16_e64() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmp_f_u16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_f_u32_e64() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmp_f_u32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_f_u64_e64() {
    u64 sdst; u64 src0; u64 src1;
    __asm__ volatile("v_cmp_f_u64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ge_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_ge_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ge_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_ge_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ge_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmp_ge_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ge_i16_e64() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmp_ge_i16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ge_i32_e64() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmp_ge_i32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ge_i64_e64() {
    i64 sdst; i64 src0; i64 src1;
    __asm__ volatile("v_cmp_ge_i64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ge_u16_e64() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmp_ge_u16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ge_u32_e64() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmp_ge_u32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ge_u64_e64() {
    u64 sdst; u64 src0; u64 src1;
    __asm__ volatile("v_cmp_ge_u64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_gt_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_gt_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_gt_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_gt_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_gt_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmp_gt_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_gt_i16_e64() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmp_gt_i16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_gt_i32_e64() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmp_gt_i32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_gt_i64_e64() {
    i64 sdst; i64 src0; i64 src1;
    __asm__ volatile("v_cmp_gt_i64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_gt_u16_e64() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmp_gt_u16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_gt_u32_e64() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmp_gt_u32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_gt_u64_e64() {
    u64 sdst; u64 src0; u64 src1;
    __asm__ volatile("v_cmp_gt_u64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_le_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_le_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_le_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_le_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_le_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmp_le_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_le_i16_e64() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmp_le_i16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_le_i32_e64() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmp_le_i32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_le_i64_e64() {
    i64 sdst; i64 src0; i64 src1;
    __asm__ volatile("v_cmp_le_i64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_le_u16_e64() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmp_le_u16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_le_u32_e64() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmp_le_u32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_le_u64_e64() {
    u64 sdst; u64 src0; u64 src1;
    __asm__ volatile("v_cmp_le_u64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_lg_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_lg_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_lg_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_lg_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_lg_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmp_lg_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_lt_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_lt_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_lt_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_lt_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_lt_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmp_lt_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_lt_i16_e64() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmp_lt_i16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_lt_i32_e64() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmp_lt_i32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_lt_i64_e64() {
    i64 sdst; i64 src0; i64 src1;
    __asm__ volatile("v_cmp_lt_i64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_lt_u16_e64() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmp_lt_u16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_lt_u32_e64() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmp_lt_u32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_lt_u64_e64() {
    u64 sdst; u64 src0; u64 src1;
    __asm__ volatile("v_cmp_lt_u64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ne_i16_e64() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmp_ne_i16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ne_i32_e64() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmp_ne_i32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ne_i64_e64() {
    i64 sdst; i64 src0; i64 src1;
    __asm__ volatile("v_cmp_ne_i64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ne_u16_e64() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmp_ne_u16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ne_u32_e64() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmp_ne_u32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ne_u64_e64() {
    u64 sdst; u64 src0; u64 src1;
    __asm__ volatile("v_cmp_ne_u64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_neq_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_neq_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_neq_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_neq_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_neq_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmp_neq_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_nge_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_nge_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_nge_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_nge_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_nge_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmp_nge_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ngt_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_ngt_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ngt_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_ngt_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_ngt_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmp_ngt_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_nle_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_nle_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_nle_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_nle_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_nle_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmp_nle_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_nlg_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_nlg_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_nlg_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_nlg_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_nlg_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmp_nlg_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_nlt_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_nlt_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_nlt_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_nlt_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_nlt_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmp_nlt_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_o_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_o_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_o_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_o_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_o_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmp_o_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_t_i16_e64() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmp_t_i16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_t_i32_e64() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmp_t_i32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_t_i64_e64() {
    i64 sdst; i64 src0; i64 src1;
    __asm__ volatile("v_cmp_t_i64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_t_u16_e64() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmp_t_u16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_t_u32_e64() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmp_t_u32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_t_u64_e64() {
    u64 sdst; u64 src0; u64 src1;
    __asm__ volatile("v_cmp_t_u64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_tru_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_tru_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_tru_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_tru_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_tru_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmp_tru_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_u_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmp_u_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_u_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmp_u_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmp_u_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmp_u_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_class_f16_e64() {
    b64 sdst; f16 src0; b32 src1;
    __asm__ volatile("v_cmpx_class_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_class_f32_e64() {
    b64 sdst; f32 src0; b32 src1;
    __asm__ volatile("v_cmpx_class_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_class_f64_e64() {
    f64 sdst; f64 src0; b32 src1;
    __asm__ volatile("v_cmpx_class_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_eq_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_eq_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_eq_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_eq_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_eq_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmpx_eq_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_eq_i16_e64() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmpx_eq_i16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_eq_i32_e64() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmpx_eq_i32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_eq_i64_e64() {
    i64 sdst; i64 src0; i64 src1;
    __asm__ volatile("v_cmpx_eq_i64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_eq_u16_e64() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmpx_eq_u16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_eq_u32_e64() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmpx_eq_u32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_eq_u64_e64() {
    u64 sdst; u64 src0; u64 src1;
    __asm__ volatile("v_cmpx_eq_u64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_f_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_f_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_f_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_f_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_f_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmpx_f_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_f_i16_e64() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmpx_f_i16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_f_i32_e64() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmpx_f_i32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_f_i64_e64() {
    i64 sdst; i64 src0; i64 src1;
    __asm__ volatile("v_cmpx_f_i64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_f_u16_e64() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmpx_f_u16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_f_u32_e64() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmpx_f_u32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_f_u64_e64() {
    u64 sdst; u64 src0; u64 src1;
    __asm__ volatile("v_cmpx_f_u64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ge_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_ge_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ge_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_ge_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ge_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmpx_ge_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ge_i16_e64() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmpx_ge_i16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ge_i32_e64() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmpx_ge_i32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ge_i64_e64() {
    i64 sdst; i64 src0; i64 src1;
    __asm__ volatile("v_cmpx_ge_i64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ge_u16_e64() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmpx_ge_u16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ge_u32_e64() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmpx_ge_u32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ge_u64_e64() {
    u64 sdst; u64 src0; u64 src1;
    __asm__ volatile("v_cmpx_ge_u64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_gt_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_gt_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_gt_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_gt_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_gt_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmpx_gt_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_gt_i16_e64() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmpx_gt_i16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_gt_i32_e64() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmpx_gt_i32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_gt_i64_e64() {
    i64 sdst; i64 src0; i64 src1;
    __asm__ volatile("v_cmpx_gt_i64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_gt_u16_e64() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmpx_gt_u16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_gt_u32_e64() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmpx_gt_u32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_gt_u64_e64() {
    u64 sdst; u64 src0; u64 src1;
    __asm__ volatile("v_cmpx_gt_u64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_le_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_le_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_le_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_le_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_le_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmpx_le_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_le_i16_e64() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmpx_le_i16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_le_i32_e64() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmpx_le_i32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_le_i64_e64() {
    i64 sdst; i64 src0; i64 src1;
    __asm__ volatile("v_cmpx_le_i64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_le_u16_e64() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmpx_le_u16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_le_u32_e64() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmpx_le_u32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_le_u64_e64() {
    u64 sdst; u64 src0; u64 src1;
    __asm__ volatile("v_cmpx_le_u64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_lg_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_lg_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_lg_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_lg_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_lg_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmpx_lg_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_lt_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_lt_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_lt_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_lt_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_lt_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmpx_lt_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_lt_i16_e64() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmpx_lt_i16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_lt_i32_e64() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmpx_lt_i32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_lt_i64_e64() {
    i64 sdst; i64 src0; i64 src1;
    __asm__ volatile("v_cmpx_lt_i64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_lt_u16_e64() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmpx_lt_u16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_lt_u32_e64() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmpx_lt_u32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_lt_u64_e64() {
    u64 sdst; u64 src0; u64 src1;
    __asm__ volatile("v_cmpx_lt_u64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ne_i16_e64() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmpx_ne_i16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ne_i32_e64() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmpx_ne_i32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ne_i64_e64() {
    i64 sdst; i64 src0; i64 src1;
    __asm__ volatile("v_cmpx_ne_i64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ne_u16_e64() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmpx_ne_u16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ne_u32_e64() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmpx_ne_u32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ne_u64_e64() {
    u64 sdst; u64 src0; u64 src1;
    __asm__ volatile("v_cmpx_ne_u64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_neq_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_neq_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_neq_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_neq_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_neq_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmpx_neq_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_nge_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_nge_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_nge_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_nge_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_nge_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmpx_nge_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ngt_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_ngt_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ngt_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_ngt_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_ngt_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmpx_ngt_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_nle_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_nle_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_nle_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_nle_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_nle_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmpx_nle_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_nlg_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_nlg_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_nlg_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_nlg_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_nlg_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmpx_nlg_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_nlt_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_nlt_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_nlt_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_nlt_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_nlt_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmpx_nlt_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_o_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_o_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_o_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_o_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_o_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmpx_o_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_t_i16_e64() {
    b64 sdst; i16 src0; i16 src1;
    __asm__ volatile("v_cmpx_t_i16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_t_i32_e64() {
    b64 sdst; i32 src0; i32 src1;
    __asm__ volatile("v_cmpx_t_i32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_t_i64_e64() {
    i64 sdst; i64 src0; i64 src1;
    __asm__ volatile("v_cmpx_t_i64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_t_u16_e64() {
    b64 sdst; u16 src0; u16 src1;
    __asm__ volatile("v_cmpx_t_u16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_t_u32_e64() {
    b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_cmpx_t_u32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_t_u64_e64() {
    u64 sdst; u64 src0; u64 src1;
    __asm__ volatile("v_cmpx_t_u64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_tru_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_tru_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_tru_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_tru_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_tru_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmpx_tru_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_u_f16_e64() {
    b64 sdst; f16 src0; f16 src1;
    __asm__ volatile("v_cmpx_u_f16_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_u_f32_e64() {
    b64 sdst; f32 src0; f32 src1;
    __asm__ volatile("v_cmpx_u_f32_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cmpx_u_f64_e64() {
    f64 sdst; f64 src0; f64 src1;
    __asm__ volatile("v_cmpx_u_f64_e64 %0, %1, %2 \n" : "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_cndmask_b32_e64() {
    b32 vdst; b32 src0; b32 src1; b64 ssrc2;
    __asm__ volatile("v_cndmask_b32_e64 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "s"(ssrc2));
}

__global__ void v_cos_f16_e64() {
    f16 vdst; f16 src;
    __asm__ volatile("v_cos_f16_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cos_f32_e64() {
    f32 vdst; f32 src;
    __asm__ volatile("v_cos_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cubeid_f32() {
    f32 vdst; f32 src0; f32 src1; f32 src2;
    __asm__ volatile("v_cubeid_f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_cubema_f32() {
    f32 vdst; f32 src0; f32 src1; f32 src2;
    __asm__ volatile("v_cubema_f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_cubesc_f32() {
    f32 vdst; f32 src0; f32 src1; f32 src2;
    __asm__ volatile("v_cubesc_f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_cubetc_f32() {
    f32 vdst; f32 src0; f32 src1; f32 src2;
    __asm__ volatile("v_cubetc_f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_cvt_f16_f32_e64() {
    f16 vdst; f32 src;
    __asm__ volatile("v_cvt_f16_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f16_i16_e64() {
    f16 vdst; i16 src;
    __asm__ volatile("v_cvt_f16_i16_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f16_u16_e64() {
    f16 vdst; u16 src;
    __asm__ volatile("v_cvt_f16_u16_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_f16_e64() {
    f32 vdst; f16 src;
    __asm__ volatile("v_cvt_f32_f16_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_f64_e64() {
    f32 vdst; f64 src;
    __asm__ volatile("v_cvt_f32_f64_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_i32_e64() {
    f32 vdst; i32 src;
    __asm__ volatile("v_cvt_f32_i32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_u32_e64() {
    f32 vdst; u32 src;
    __asm__ volatile("v_cvt_f32_u32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_ubyte0_e64() {
    b32 vdst; b32 src;
    __asm__ volatile("v_cvt_f32_ubyte0_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_ubyte1_e64() {
    b32 vdst; b32 src;
    __asm__ volatile("v_cvt_f32_ubyte1_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_ubyte2_e64() {
    b32 vdst; b32 src;
    __asm__ volatile("v_cvt_f32_ubyte2_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f32_ubyte3_e64() {
    b32 vdst; b32 src;
    __asm__ volatile("v_cvt_f32_ubyte3_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f64_f32_e64() {
    f64 vdst; f32 src;
    __asm__ volatile("v_cvt_f64_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f64_i32_e64() {
    f64 vdst; i32 src;
    __asm__ volatile("v_cvt_f64_i32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_f64_u32_e64() {
    f64 vdst; u32 src;
    __asm__ volatile("v_cvt_f64_u32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_flr_i32_f32_e64() {
    i32 vdst; f32 src;
    __asm__ volatile("v_cvt_flr_i32_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_i16_f16_e64() {
    i16 vdst; f16 src;
    __asm__ volatile("v_cvt_i16_f16_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_i32_f32_e64() {
    i32 vdst; f32 src;
    __asm__ volatile("v_cvt_i32_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_i32_f64_e64() {
    i32 vdst; f64 src;
    __asm__ volatile("v_cvt_i32_f64_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_norm_i16_f16_e64() {
    i16 vdst; f16 src;
    __asm__ volatile("v_cvt_norm_i16_f16_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_norm_u16_f16_e64() {
    u16 vdst; f16 src;
    __asm__ volatile("v_cvt_norm_u16_f16_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_off_f32_i4_e64() {
    f32 vdst; i4 src;
    __asm__ volatile("v_cvt_off_f32_i4_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_pk_i16_i32() {
    i16 vdst; i32 src0; i32 src1;
    __asm__ volatile("v_cvt_pk_i16_i32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_cvt_pk_u16_u32() {
    u16 vdst; u32 src0; u32 src1;
    __asm__ volatile("v_cvt_pk_u16_u32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_cvt_pk_u8_f32() {
    b32 vdst; f32 src0; u32 src1; u32 src2;
    __asm__ volatile("v_cvt_pk_u8_f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_cvt_pkaccum_u8_f32() {
    b32 vdst; f32 src0; u32 src1;
    __asm__ volatile("v_cvt_pkaccum_u8_f32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_cvt_pknorm_i16_f16() {
    i16 vdst; f16 src0; f16 src1;
    __asm__ volatile("v_cvt_pknorm_i16_f16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_cvt_pknorm_i16_f32() {
    i16 vdst; f32 src0; f32 src1;
    __asm__ volatile("v_cvt_pknorm_i16_f32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_cvt_pknorm_u16_f16() {
    u16 vdst; f16 src0; f16 src1;
    __asm__ volatile("v_cvt_pknorm_u16_f16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_cvt_pknorm_u16_f32() {
    u16 vdst; f32 src0; f32 src1;
    __asm__ volatile("v_cvt_pknorm_u16_f32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_cvt_pkrtz_f16_f32() {
    f16 vdst; f32 src0; f32 src1;
    __asm__ volatile("v_cvt_pkrtz_f16_f32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_cvt_rpi_i32_f32_e64() {
    i32 vdst; f32 src;
    __asm__ volatile("v_cvt_rpi_i32_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_u16_f16_e64() {
    u16 vdst; f16 src;
    __asm__ volatile("v_cvt_u16_f16_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_u32_f32_e64() {
    u32 vdst; f32 src;
    __asm__ volatile("v_cvt_u32_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_cvt_u32_f64_e64() {
    u32 vdst; f64 src;
    __asm__ volatile("v_cvt_u32_f64_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_div_fixup_f16() {
    f16 vdst; f16 src0; f16 src1; f16 src2;
    __asm__ volatile("v_div_fixup_f16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_div_fixup_f32() {
    f32 vdst; f32 src0; f32 src1; f32 src2;
    __asm__ volatile("v_div_fixup_f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_div_fixup_f64() {
    f64 vdst; f64 src0; f64 src1; f64 src2;
    __asm__ volatile("v_div_fixup_f64 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_div_fixup_legacy_f16() {
    f16 vdst; f16 src0; f16 src1; f16 src2;
    __asm__ volatile("v_div_fixup_legacy_f16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_div_fmas_f32() {
    f32 vdst; f32 src0; f32 src1; f32 src2;
    __asm__ volatile("v_div_fmas_f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_div_fmas_f64() {
    f64 vdst; f64 src0; f64 src1; f64 src2;
    __asm__ volatile("v_div_fmas_f64 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_dot2c_f32_f16_e64() {
    f32 vdst; f16x2 src0; f16x2 src1;
    __asm__ volatile("v_dot2c_f32_f16_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_dot2c_i32_i16_e64() {
    i32 vdst; i16x2 src0; i16x2 src1;
    __asm__ volatile("v_dot2c_i32_i16_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_dot4c_i32_i8_e64() {
    i32 vdst; i8x4 src0; i8x4 src1;
    __asm__ volatile("v_dot4c_i32_i8_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_dot8c_i32_i4_e64() {
    i32 vdst; i4x8 src0; i4x8 src1;
    __asm__ volatile("v_dot8c_i32_i4_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_exp_f16_e64() {
    f16 vdst; f16 src;
    __asm__ volatile("v_exp_f16_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_exp_f32_e64() {
    f32 vdst; f32 src;
    __asm__ volatile("v_exp_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_exp_legacy_f32_e64() {
    f32 vdst; f32 src;
    __asm__ volatile("v_exp_legacy_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_ffbh_i32_e64() {
    i32 vdst; i32 src;
    __asm__ volatile("v_ffbh_i32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_ffbh_u32_e64() {
    u32 vdst; u32 src;
    __asm__ volatile("v_ffbh_u32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_ffbl_b32_e64() {
    b32 vdst; b32 src;
    __asm__ volatile("v_ffbl_b32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_floor_f16_e64() {
    f16 vdst; f16 src;
    __asm__ volatile("v_floor_f16_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_floor_f32_e64() {
    f32 vdst; f32 src;
    __asm__ volatile("v_floor_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_floor_f64_e64() {
    f64 vdst; f64 src;
    __asm__ volatile("v_floor_f64_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_fma_f16() {
    f16 vdst; f16 src0; f16 src1; f16 src2;
    __asm__ volatile("v_fma_f16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_fma_f32() {
    f32 vdst; f32 src0; f32 src1; f32 src2;
    __asm__ volatile("v_fma_f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_fma_f64() {
    f64 vdst; f64 src0; f64 src1; f64 src2;
    __asm__ volatile("v_fma_f64 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_fma_legacy_f16() {
    f16 vdst; f16 src0; f16 src1; f16 src2;
    __asm__ volatile("v_fma_legacy_f16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_fmac_f32_e64() {
    f32 vdst; f32 src0; f32 src1;
    __asm__ volatile("v_fmac_f32_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_fmac_f64_e64() {
    f64 vdst; f64 src0; f64 src1;
    __asm__ volatile("v_fmac_f64_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_fract_f16_e64() {
    f16 vdst; f16 src;
    __asm__ volatile("v_fract_f16_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_fract_f32_e64() {
    f32 vdst; f32 src;
    __asm__ volatile("v_fract_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_fract_f64_e64() {
    f64 vdst; f64 src;
    __asm__ volatile("v_fract_f64_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_frexp_exp_i16_f16_e64() {
    i16 vdst; f16 src;
    __asm__ volatile("v_frexp_exp_i16_f16_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_frexp_exp_i32_f32_e64() {
    i32 vdst; f32 src;
    __asm__ volatile("v_frexp_exp_i32_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_frexp_exp_i32_f64_e64() {
    i32 vdst; f64 src;
    __asm__ volatile("v_frexp_exp_i32_f64_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_frexp_mant_f16_e64() {
    f16 vdst; f16 src;
    __asm__ volatile("v_frexp_mant_f16_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_frexp_mant_f32_e64() {
    f32 vdst; f32 src;
    __asm__ volatile("v_frexp_mant_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_frexp_mant_f64_e64() {
    f64 vdst; f64 src;
    __asm__ volatile("v_frexp_mant_f64_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_ldexp_f16_e64() {
    f16 vdst; f16 src0; i16 src1;
    __asm__ volatile("v_ldexp_f16_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_ldexp_f32() {
    f32 vdst; f32 src0; i32 src1;
    __asm__ volatile("v_ldexp_f32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_ldexp_f64() {
    f64 vdst; f64 src0; i32 src1;
    __asm__ volatile("v_ldexp_f64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_lerp_u8() {
    u32 vdst; b32 src0; b32 src1; b32 src2;
    __asm__ volatile("v_lerp_u8 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_log_f16_e64() {
    f16 vdst; f16 src;
    __asm__ volatile("v_log_f16_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_log_f32_e64() {
    f32 vdst; f32 src;
    __asm__ volatile("v_log_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_log_legacy_f32_e64() {
    f32 vdst; f32 src;
    __asm__ volatile("v_log_legacy_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_lshl_add_u32() {
    u32 vdst; u32 src0; u32 src1; u32 src2;
    __asm__ volatile("v_lshl_add_u32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_lshl_or_b32() {
    b32 vdst; b32 src0; u32 src1; b32 src2;
    __asm__ volatile("v_lshl_or_b32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_lshlrev_b16_e64() {
    b16 vdst; u16 src0; b16 src1;
    __asm__ volatile("v_lshlrev_b16_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_lshlrev_b32_e64() {
    b32 vdst; u32 src0; b32 src1;
    __asm__ volatile("v_lshlrev_b32_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_lshlrev_b64() {
    b64 vdst; u32 src0; b64 src1;
    __asm__ volatile("v_lshlrev_b64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_lshrrev_b16_e64() {
    b16 vdst; u16 src0; b16 src1;
    __asm__ volatile("v_lshrrev_b16_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_lshrrev_b32_e64() {
    b32 vdst; u32 src0; b32 src1;
    __asm__ volatile("v_lshrrev_b32_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_lshrrev_b64() {
    b64 vdst; u32 src0; b64 src1;
    __asm__ volatile("v_lshrrev_b64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mac_f16_e64() {
    f16 vdst; f16 src0; f16 src1;
    __asm__ volatile("v_mac_f16_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mac_f32_e64() {
    f32 vdst; f32 src0; f32 src1;
    __asm__ volatile("v_mac_f32_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mad_f16() {
    f16 vdst; f16 src0; f16 src1; f16 src2;
    __asm__ volatile("v_mad_f16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_mad_f32() {
    f32 vdst; f32 src0; f32 src1; f32 src2;
    __asm__ volatile("v_mad_f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_mad_i16() {
    i16 vdst; i16 src0; i16 src1; i16 src2;
    __asm__ volatile("v_mad_i16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_mad_i32_i16() {
    i32 vdst; i16 src0; i16 src1; i32 src2;
    __asm__ volatile("v_mad_i32_i16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_mad_i32_i24() {
    b32 vdst; b32 src0; b32 src1; i32 src2;
    __asm__ volatile("v_mad_i32_i24 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_mad_legacy_f16() {
    f16 vdst; f16 src0; f16 src1; f16 src2;
    __asm__ volatile("v_mad_legacy_f16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_mad_legacy_f32() {
    f32 vdst; f32 src0; f32 src1; f32 src2;
    __asm__ volatile("v_mad_legacy_f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_mad_legacy_i16() {
    i16 vdst; i16 src0; i16 src1; i16 src2;
    __asm__ volatile("v_mad_legacy_i16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_mad_legacy_u16() {
    u16 vdst; u16 src0; u16 src1; u16 src2;
    __asm__ volatile("v_mad_legacy_u16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_mad_u16() {
    u16 vdst; u16 src0; u16 src1; u16 src2;
    __asm__ volatile("v_mad_u16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_mad_u32_u16() {
    u32 vdst; u16 src0; u16 src1; u32 src2;
    __asm__ volatile("v_mad_u32_u16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_mad_u32_u24() {
    b32 vdst; b32 src0; b32 src1; u32 src2;
    __asm__ volatile("v_mad_u32_u24 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_max3_f16() {
    f16 vdst; f16 src0; f16 src1; f16 src2;
    __asm__ volatile("v_max3_f16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_max3_f32() {
    f32 vdst; f32 src0; f32 src1; f32 src2;
    __asm__ volatile("v_max3_f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_max3_i16() {
    i16 vdst; i16 src0; i16 src1; i16 src2;
    __asm__ volatile("v_max3_i16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_max3_i32() {
    i32 vdst; i32 src0; i32 src1; i32 src2;
    __asm__ volatile("v_max3_i32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_max3_u16() {
    u16 vdst; u16 src0; u16 src1; u16 src2;
    __asm__ volatile("v_max3_u16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_max3_u32() {
    u32 vdst; u32 src0; u32 src1; u32 src2;
    __asm__ volatile("v_max3_u32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_max_f16_e64() {
    f16 vdst; f16 src0; f16 src1;
    __asm__ volatile("v_max_f16_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_max_f32_e64() {
    f32 vdst; f32 src0; f32 src1;
    __asm__ volatile("v_max_f32_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_max_f64() {
    f64 vdst; f64 src0; f64 src1;
    __asm__ volatile("v_max_f64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_max_i16_e64() {
    i16 vdst; i16 src0; i16 src1;
    __asm__ volatile("v_max_i16_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_max_i32_e64() {
    i32 vdst; i32 src0; i32 src1;
    __asm__ volatile("v_max_i32_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_max_u16_e64() {
    u16 vdst; u16 src0; u16 src1;
    __asm__ volatile("v_max_u16_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_max_u32_e64() {
    u32 vdst; u32 src0; u32 src1;
    __asm__ volatile("v_max_u32_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mbcnt_hi_u32_b32() {
    u32 vdst; b32 src0; b32 src1;
    __asm__ volatile("v_mbcnt_hi_u32_b32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mbcnt_lo_u32_b32() {
    u32 vdst; b32 src0; b32 src1;
    __asm__ volatile("v_mbcnt_lo_u32_b32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_med3_f16() {
    f16 vdst; f16 src0; f16 src1; f16 src2;
    __asm__ volatile("v_med3_f16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_med3_f32() {
    f32 vdst; f32 src0; f32 src1; f32 src2;
    __asm__ volatile("v_med3_f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_med3_i16() {
    i16 vdst; i16 src0; i16 src1; i16 src2;
    __asm__ volatile("v_med3_i16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_med3_i32() {
    i32 vdst; i32 src0; i32 src1; i32 src2;
    __asm__ volatile("v_med3_i32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_med3_u16() {
    u16 vdst; u16 src0; u16 src1; u16 src2;
    __asm__ volatile("v_med3_u16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_med3_u32() {
    u32 vdst; u32 src0; u32 src1; u32 src2;
    __asm__ volatile("v_med3_u32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_min3_f16() {
    f16 vdst; f16 src0; f16 src1; f16 src2;
    __asm__ volatile("v_min3_f16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_min3_f32() {
    f32 vdst; f32 src0; f32 src1; f32 src2;
    __asm__ volatile("v_min3_f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_min3_i16() {
    i16 vdst; i16 src0; i16 src1; i16 src2;
    __asm__ volatile("v_min3_i16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_min3_i32() {
    i32 vdst; i32 src0; i32 src1; i32 src2;
    __asm__ volatile("v_min3_i32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_min3_u16() {
    u16 vdst; u16 src0; u16 src1; u16 src2;
    __asm__ volatile("v_min3_u16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_min3_u32() {
    u32 vdst; u32 src0; u32 src1; u32 src2;
    __asm__ volatile("v_min3_u32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_min_f16_e64() {
    f16 vdst; f16 src0; f16 src1;
    __asm__ volatile("v_min_f16_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_min_f32_e64() {
    f32 vdst; f32 src0; f32 src1;
    __asm__ volatile("v_min_f32_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_min_f64() {
    f64 vdst; f64 src0; f64 src1;
    __asm__ volatile("v_min_f64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_min_i16_e64() {
    i16 vdst; i16 src0; i16 src1;
    __asm__ volatile("v_min_i16_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_min_i32_e64() {
    i32 vdst; i32 src0; i32 src1;
    __asm__ volatile("v_min_i32_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_min_u16_e64() {
    u16 vdst; u16 src0; u16 src1;
    __asm__ volatile("v_min_u16_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_min_u32_e64() {
    u32 vdst; u32 src0; u32 src1;
    __asm__ volatile("v_min_u32_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mov_b32_e64() {
    b32 vdst; b32 src;
    __asm__ volatile("v_mov_b32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_mqsad_pk_u16_u8() {
    u16x4 vdst; u8x8 src0; u8x4 src1; u16x4 src2;
    __asm__ volatile("v_mqsad_pk_u16_u8 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_mqsad_u32_u8() {
    u32x4 vdst; u8x8 src0; u8x4 src1; u32x4 vsrc2;
    __asm__ volatile("v_mqsad_u32_u8 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(vsrc2));
}

__global__ void v_msad_u8() {
    u32 vdst; u8x4 src0; u8x4 src1; u32 src2;
    __asm__ volatile("v_msad_u8 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_mul_f16_e64() {
    f16 vdst; f16 src0; f16 src1;
    __asm__ volatile("v_mul_f16_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mul_f32_e64() {
    f32 vdst; f32 src0; f32 src1;
    __asm__ volatile("v_mul_f32_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mul_f64() {
    f64 vdst; f64 src0; f64 src1;
    __asm__ volatile("v_mul_f64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mul_hi_i32() {
    i32 vdst; i32 src0; i32 src1;
    __asm__ volatile("v_mul_hi_i32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mul_hi_i32_i24_e64() {
    b32 vdst; b32 src0; b32 src1;
    __asm__ volatile("v_mul_hi_i32_i24_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mul_hi_u32() {
    u32 vdst; u32 src0; u32 src1;
    __asm__ volatile("v_mul_hi_u32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mul_hi_u32_u24_e64() {
    b32 vdst; b32 src0; b32 src1;
    __asm__ volatile("v_mul_hi_u32_u24_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mul_i32_i24_e64() {
    b32 vdst; b32 src0; b32 src1;
    __asm__ volatile("v_mul_i32_i24_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mul_legacy_f32() {
    f32 vdst; f32 src0; f32 src1;
    __asm__ volatile("v_mul_legacy_f32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mul_lo_u16_e64() {
    u16 vdst; u16 src0; u16 src1;
    __asm__ volatile("v_mul_lo_u16_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mul_lo_u32() {
    u32 vdst; u32 src0; u32 src1;
    __asm__ volatile("v_mul_lo_u32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_mul_u32_u24_e64() {
    b32 vdst; b32 src0; b32 src1;
    __asm__ volatile("v_mul_u32_u24_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_nop_e64() {
    ;
    __asm__ volatile("v_nop_e64  \n" :  : );
}

__global__ void v_not_b32_e64() {
    b32 vdst; b32 src;
    __asm__ volatile("v_not_b32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_or3_b32() {
    b32 vdst; b32 src0; b32 src1; b32 src2;
    __asm__ volatile("v_or3_b32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_or_b32_e64() {
    b32 vdst; b32 src0; b32 src1;
    __asm__ volatile("v_or_b32_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_pack_b32_f16() {
    b32 vdst; f16 src0; f16 src1;
    __asm__ volatile("v_pack_b32_f16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_perm_b32() {
    b32 vdst; b32 src0; b32 src1; b32 src2;
    __asm__ volatile("v_perm_b32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_qsad_pk_u16_u8() {
    u16x4 vdst; u8x8 src0; u8x4 src1; u16x4 src2;
    __asm__ volatile("v_qsad_pk_u16_u8 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_rcp_f16_e64() {
    f16 vdst; f16 src;
    __asm__ volatile("v_rcp_f16_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rcp_f32_e64() {
    f32 vdst; f32 src;
    __asm__ volatile("v_rcp_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rcp_f64_e64() {
    f64 vdst; f64 src;
    __asm__ volatile("v_rcp_f64_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rcp_iflag_f32_e64() {
    f32 vdst; f32 src;
    __asm__ volatile("v_rcp_iflag_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_readlane_b32() {
    b32 sdst; b32 vsrc0; b32 ssrc1;
    __asm__ volatile("v_readlane_b32 %0, %1, %2 \n" : "=s"(sdst) : "v"(vsrc0), "s"(ssrc1));
}

__global__ void v_rndne_f16_e64() {
    f16 vdst; f16 src;
    __asm__ volatile("v_rndne_f16_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rndne_f32_e64() {
    f32 vdst; f32 src;
    __asm__ volatile("v_rndne_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rndne_f64_e64() {
    f64 vdst; f64 src;
    __asm__ volatile("v_rndne_f64_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rsq_f16_e64() {
    f16 vdst; f16 src;
    __asm__ volatile("v_rsq_f16_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rsq_f32_e64() {
    f32 vdst; f32 src;
    __asm__ volatile("v_rsq_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_rsq_f64_e64() {
    f64 vdst; f64 src;
    __asm__ volatile("v_rsq_f64_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_sad_hi_u8() {
    u32 vdst; u8x4 src0; u8x4 src1; u32 src2;
    __asm__ volatile("v_sad_hi_u8 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_sad_u16() {
    u32 vdst; u16x2 src0; u16x2 src1; u32 src2;
    __asm__ volatile("v_sad_u16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_sad_u32() {
    u32 vdst; u32 src0; u32 src1; u32 src2;
    __asm__ volatile("v_sad_u32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_sad_u8() {
    u32 vdst; u8x4 src0; u8x4 src1; u32 src2;
    __asm__ volatile("v_sad_u8 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_sat_pk_u8_i16_e64() {
    u8x4 vdst; i16 src;
    __asm__ volatile("v_sat_pk_u8_i16_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_screen_partition_4se_b32_e64() {
    b32 vdst; b32 src;
    __asm__ volatile("v_screen_partition_4se_b32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_sin_f16_e64() {
    f16 vdst; f16 src;
    __asm__ volatile("v_sin_f16_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_sin_f32_e64() {
    f32 vdst; f32 src;
    __asm__ volatile("v_sin_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_sqrt_f16_e64() {
    f16 vdst; f16 src;
    __asm__ volatile("v_sqrt_f16_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_sqrt_f32_e64() {
    f32 vdst; f32 src;
    __asm__ volatile("v_sqrt_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_sqrt_f64_e64() {
    f64 vdst; f64 src;
    __asm__ volatile("v_sqrt_f64_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_sub_f16_e64() {
    f16 vdst; f16 src0; f16 src1;
    __asm__ volatile("v_sub_f16_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_sub_f32_e64() {
    f32 vdst; f32 src0; f32 src1;
    __asm__ volatile("v_sub_f32_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_sub_i16() {
    i16 vdst; i16 src0; i16 src1;
    __asm__ volatile("v_sub_i16 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_sub_i32() {
    i32 vdst; i32 src0; i32 src1;
    __asm__ volatile("v_sub_i32 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_sub_u16_e64() {
    u16 vdst; u16 src0; u16 src1;
    __asm__ volatile("v_sub_u16_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_sub_u32_e64() {
    u32 vdst; u32 src0; u32 src1;
    __asm__ volatile("v_sub_u32_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_subrev_f16_e64() {
    f16 vdst; f16 src0; f16 src1;
    __asm__ volatile("v_subrev_f16_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_subrev_f32_e64() {
    f32 vdst; f32 src0; f32 src1;
    __asm__ volatile("v_subrev_f32_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_subrev_u16_e64() {
    u16 vdst; u16 src0; u16 src1;
    __asm__ volatile("v_subrev_u16_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_subrev_u32_e64() {
    u32 vdst; u32 src0; u32 src1;
    __asm__ volatile("v_subrev_u32_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_trig_preop_f64() {
    f64 vdst; f64 src0; u32 src1;
    __asm__ volatile("v_trig_preop_f64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_trunc_f16_e64() {
    f16 vdst; f16 src;
    __asm__ volatile("v_trunc_f16_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_trunc_f32_e64() {
    f32 vdst; f32 src;
    __asm__ volatile("v_trunc_f32_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_trunc_f64_e64() {
    f64 vdst; f64 src;
    __asm__ volatile("v_trunc_f64_e64 %0, %1 \n" : "=v"(vdst) : "v"(src));
}

__global__ void v_writelane_b32() {
    b32 vdst; b32 ssrc0;
    __asm__ volatile("v_writelane_b32 %0, %1, m0 \n" : "=v"(vdst) : "s"(ssrc0));
}

__global__ void v_xad_u32() {
    u32 vdst; u32 src0; u32 src1; u32 src2;
    __asm__ volatile("v_xad_u32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_xnor_b32_e64() {
    b32 vdst; b32 src0; b32 src1;
    __asm__ volatile("v_xnor_b32_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_xor_b32_e64() {
    b32 vdst; b32 src0; b32 src1;
    __asm__ volatile("v_xor_b32_e64 %0, %1, %2 \n" : "=v"(vdst) : "v"(src0), "v"(src1));
}

__global__ void v_add_co_u32_e64() {
    u32 vdst; b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_add_co_u32_e64 %0, %1, %2, %3 \n" : "=v"(vdst), "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_addc_co_u32_e64() {
    u32 vdst; b64 sdst; u32 src0; u32 src1; b64 ssrc2;
    __asm__ volatile("v_addc_co_u32_e64 %0, %1, %2, %3, %4 \n" : "=v"(vdst), "=s"(sdst) : "v"(src0), "v"(src1), "s"(ssrc2));
}

__global__ void v_div_scale_f32() {
    f32 vdst; f32 src0; f32 src1; f32 src2;
    __asm__ volatile("v_div_scale_f32 %0, vcc, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_div_scale_f64() {
    f64 vdst; f64 src0; f64 src1; f64 src2;
    __asm__ volatile("v_div_scale_f64 %0, vcc, %1, %2, %3 \n" : "=v"(vdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_mad_i64_i32() {
    i64 vdst; i64 sdst; i32 src0; i32 src1; i64 src2;
    __asm__ volatile("v_mad_i64_i32 %0, %1, %2, %3, %4 \n" : "=v"(vdst), "=s"(sdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_mad_u64_u32() {
    u64 vdst; u64 sdst; u32 src0; u32 src1; u64 src2;
    __asm__ volatile("v_mad_u64_u32 %0, %1, %2, %3, %4 \n" : "=v"(vdst), "=s"(sdst) : "v"(src0), "v"(src1), "v"(src2));
}

__global__ void v_sub_co_u32_e64() {
    u32 vdst; b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_sub_co_u32_e64 %0, %1, %2, %3 \n" : "=v"(vdst), "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void v_subb_co_u32_e64() {
    u32 vdst; b64 sdst; u32 src0; u32 src1; b64 ssrc2;
    __asm__ volatile("v_subb_co_u32_e64 %0, %1, %2, %3, %4 \n" : "=v"(vdst), "=s"(sdst) : "v"(src0), "v"(src1), "s"(ssrc2));
}

__global__ void v_subbrev_co_u32_e64() {
    u32 vdst; b64 sdst; u32 src0; u32 src1; b64 ssrc2;
    __asm__ volatile("v_subbrev_co_u32_e64 %0, %1, %2, %3, %4 \n" : "=v"(vdst), "=s"(sdst) : "v"(src0), "v"(src1), "s"(ssrc2));
}

__global__ void v_subrev_co_u32_e64() {
    u32 vdst; b64 sdst; u32 src0; u32 src1;
    __asm__ volatile("v_subrev_co_u32_e64 %0, %1, %2, %3 \n" : "=v"(vdst), "=s"(sdst) : "v"(src0), "v"(src1));
}

__global__ void s_abs_i32() {
    i32 sdst; i32 ssrc;
    __asm__ volatile("s_abs_i32 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_and_saveexec_b64() {
    b64 sdst; b64 ssrc;
    __asm__ volatile("s_and_saveexec_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_andn1_saveexec_b64() {
    b64 sdst; b64 ssrc;
    __asm__ volatile("s_andn1_saveexec_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_andn1_wrexec_b64() {
    b64 sdst; b64 ssrc;
    __asm__ volatile("s_andn1_wrexec_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_andn2_saveexec_b64() {
    b64 sdst; b64 ssrc;
    __asm__ volatile("s_andn2_saveexec_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_andn2_wrexec_b64() {
    b64 sdst; b64 ssrc;
    __asm__ volatile("s_andn2_wrexec_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_bcnt0_i32_b32() {
    i32 sdst; b32 ssrc;
    __asm__ volatile("s_bcnt0_i32_b32 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_bcnt0_i32_b64() {
    i32 sdst; b64 ssrc;
    __asm__ volatile("s_bcnt0_i32_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_bcnt1_i32_b32() {
    i32 sdst; b32 ssrc;
    __asm__ volatile("s_bcnt1_i32_b32 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_bcnt1_i32_b64() {
    i32 sdst; b64 ssrc;
    __asm__ volatile("s_bcnt1_i32_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_bitreplicate_b64_b32() {
    b64 sdst; b32 ssrc;
    __asm__ volatile("s_bitreplicate_b64_b32 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_bitset0_b32() {
    b32 sdst; b32 ssrc;
    __asm__ volatile("s_bitset0_b32 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_bitset0_b64() {
    b64 sdst; b32 ssrc;
    __asm__ volatile("s_bitset0_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_bitset1_b32() {
    b32 sdst; b32 ssrc;
    __asm__ volatile("s_bitset1_b32 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_bitset1_b64() {
    b64 sdst; b32 ssrc;
    __asm__ volatile("s_bitset1_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_brev_b32() {
    b32 sdst; b32 ssrc;
    __asm__ volatile("s_brev_b32 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_brev_b64() {
    b64 sdst; b64 ssrc;
    __asm__ volatile("s_brev_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_cbranch_join() {
    b32 ssrc;
    __asm__ volatile("s_cbranch_join %0 \n" :  : "s"(ssrc));
}

__global__ void s_cmov_b32() {
    b32 sdst; b32 ssrc;
    __asm__ volatile("s_cmov_b32 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_cmov_b64() {
    b64 sdst; b64 ssrc;
    __asm__ volatile("s_cmov_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_ff0_i32_b32() {
    i32 sdst; b32 ssrc;
    __asm__ volatile("s_ff0_i32_b32 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_ff0_i32_b64() {
    i32 sdst; b64 ssrc;
    __asm__ volatile("s_ff0_i32_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_ff1_i32_b32() {
    i32 sdst; b32 ssrc;
    __asm__ volatile("s_ff1_i32_b32 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_ff1_i32_b64() {
    i32 sdst; b64 ssrc;
    __asm__ volatile("s_ff1_i32_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_flbit_i32() {
    i32 sdst; i32 ssrc;
    __asm__ volatile("s_flbit_i32 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_flbit_i32_b32() {
    i32 sdst; b32 ssrc;
    __asm__ volatile("s_flbit_i32_b32 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_flbit_i32_b64() {
    i32 sdst; b64 ssrc;
    __asm__ volatile("s_flbit_i32_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_flbit_i32_i64() {
    i32 sdst; i64 ssrc;
    __asm__ volatile("s_flbit_i32_i64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_getpc_b64() {
    b64 sdst;
    __asm__ volatile("s_getpc_b64 %0 \n" : "=s"(sdst) : );
}

__global__ void s_mov_b32() {
    b32 sdst; b32 ssrc;
    __asm__ volatile("s_mov_b32 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_mov_b64() {
    b64 sdst; b64 ssrc;
    __asm__ volatile("s_mov_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_movreld_b32() {
    b32 sdst; b32 ssrc;
    __asm__ volatile("s_movreld_b32 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_movreld_b64() {
    b64 sdst; b64 ssrc;
    __asm__ volatile("s_movreld_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_movrels_b32() {
    b32 sdst; b32 ssrc;
    __asm__ volatile("s_movrels_b32 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_movrels_b64() {
    b64 sdst; b64 ssrc;
    __asm__ volatile("s_movrels_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_nand_saveexec_b64() {
    b64 sdst; b64 ssrc;
    __asm__ volatile("s_nand_saveexec_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_nor_saveexec_b64() {
    b64 sdst; b64 ssrc;
    __asm__ volatile("s_nor_saveexec_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_not_b32() {
    b32 sdst; b32 ssrc;
    __asm__ volatile("s_not_b32 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_not_b64() {
    b64 sdst; b64 ssrc;
    __asm__ volatile("s_not_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_or_saveexec_b64() {
    b64 sdst; b64 ssrc;
    __asm__ volatile("s_or_saveexec_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_orn1_saveexec_b64() {
    b64 sdst; b64 ssrc;
    __asm__ volatile("s_orn1_saveexec_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_orn2_saveexec_b64() {
    b64 sdst; b64 ssrc;
    __asm__ volatile("s_orn2_saveexec_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_quadmask_b32() {
    b32 sdst; b32 ssrc;
    __asm__ volatile("s_quadmask_b32 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_quadmask_b64() {
    b64 sdst; b64 ssrc;
    __asm__ volatile("s_quadmask_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_rfe_b64() {
    b64 ssrc;
    __asm__ volatile("s_rfe_b64 %0 \n" :  : "s"(ssrc));
}

__global__ void s_set_gpr_idx_idx() {
    b32 ssrc;
    __asm__ volatile("s_set_gpr_idx_idx %0 \n" :  : "s"(ssrc));
}

__global__ void s_setpc_b64() {
    b64 ssrc;
    __asm__ volatile("s_setpc_b64 %0 \n" :  : "s"(ssrc));
}

__global__ void s_sext_i32_i16() {
    i32 sdst; i16 ssrc;
    __asm__ volatile("s_sext_i32_i16 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_sext_i32_i8() {
    i32 sdst; i8 ssrc;
    __asm__ volatile("s_sext_i32_i8 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_swappc_b64() {
    b64 sdst; b64 ssrc;
    __asm__ volatile("s_swappc_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_wqm_b32() {
    b32 sdst; b32 ssrc;
    __asm__ volatile("s_wqm_b32 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_wqm_b64() {
    b64 sdst; b64 ssrc;
    __asm__ volatile("s_wqm_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_xnor_saveexec_b64() {
    b64 sdst; b64 ssrc;
    __asm__ volatile("s_xnor_saveexec_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void s_xor_saveexec_b64() {
    b64 sdst; b64 ssrc;
    __asm__ volatile("s_xor_saveexec_b64 %0, %1 \n" : "=s"(sdst) : "s"(ssrc));
}

__global__ void v_mfma_f32_16x16x16bf16_1k() {
    f32x4 vdst; bf16x4 vsrc0; bf16x4 vsrc1; f32x4 src2;
    __asm__ volatile("v_mfma_f32_16x16x16bf16_1k %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_f32_16x16x16f16() {
    f32x4 vdst; f16x4 vsrc0; f16x4 vsrc1; f32x4 src2;
    __asm__ volatile("v_mfma_f32_16x16x16f16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_f32_16x16x1f32() {
    f32x16 vdst; f32 vsrc0; f32 vsrc1; f32x16 src2;
    __asm__ volatile("v_mfma_f32_16x16x1f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_f32_16x16x2bf16() {
    f32x16 vdst; bf16x2 vsrc0; bf16x2 vsrc1; f32x16 src2;
    __asm__ volatile("v_mfma_f32_16x16x2bf16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_f32_16x16x4bf16_1k() {
    f32x16 vdst; bf16x4 vsrc0; bf16x4 vsrc1; f32x16 src2;
    __asm__ volatile("v_mfma_f32_16x16x4bf16_1k %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_f32_16x16x4f16() {
    f32x16 vdst; f16x4 vsrc0; f16x4 vsrc1; f32x16 src2;
    __asm__ volatile("v_mfma_f32_16x16x4f16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_f32_16x16x4f32() {
    f32x4 vdst; f32 vsrc0; f32 vsrc1; f32x4 src2;
    __asm__ volatile("v_mfma_f32_16x16x4f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_f32_16x16x8bf16() {
    f32x4 vdst; bf16x2 vsrc0; bf16x2 vsrc1; f32x4 src2;
    __asm__ volatile("v_mfma_f32_16x16x8bf16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_f32_32x32x1f32() {
    f32x32 vdst; f32 vsrc0; f32 vsrc1; f32x32 src2;
    __asm__ volatile("v_mfma_f32_32x32x1f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_f32_32x32x2bf16() {
    f32x32 vdst; bf16x2 vsrc0; bf16x2 vsrc1; f32x32 src2;
    __asm__ volatile("v_mfma_f32_32x32x2bf16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_f32_32x32x2f32() {
    f32x16 vdst; f32 vsrc0; f32 vsrc1; f32x16 src2;
    __asm__ volatile("v_mfma_f32_32x32x2f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_f32_32x32x4bf16() {
    f32x16 vdst; bf16x2 vsrc0; bf16x2 vsrc1; f32x16 src2;
    __asm__ volatile("v_mfma_f32_32x32x4bf16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_f32_32x32x4bf16_1k() {
    f32x32 vdst; bf16x4 vsrc0; bf16x4 vsrc1; f32x32 src2;
    __asm__ volatile("v_mfma_f32_32x32x4bf16_1k %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_f32_32x32x4f16() {
    f32x32 vdst; f16x4 vsrc0; f16x4 vsrc1; f32x32 src2;
    __asm__ volatile("v_mfma_f32_32x32x4f16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_f32_32x32x8bf16_1k() {
    f32x16 vdst; bf16x4 vsrc0; bf16x4 vsrc1; f32x16 src2;
    __asm__ volatile("v_mfma_f32_32x32x8bf16_1k %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_f32_32x32x8f16() {
    f32x16 vdst; f16x4 vsrc0; f16x4 vsrc1; f32x16 src2;
    __asm__ volatile("v_mfma_f32_32x32x8f16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_f32_4x4x1f32() {
    f32x4 vdst; f32 vsrc0; f32 vsrc1; f32x4 src2;
    __asm__ volatile("v_mfma_f32_4x4x1f32 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_f32_4x4x2bf16() {
    f32x4 vdst; bf16x2 vsrc0; bf16x2 vsrc1; f32x4 src2;
    __asm__ volatile("v_mfma_f32_4x4x2bf16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_f32_4x4x4bf16_1k() {
    f32x4 vdst; bf16x4 vsrc0; bf16x4 vsrc1; f32x4 src2;
    __asm__ volatile("v_mfma_f32_4x4x4bf16_1k %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_f32_4x4x4f16() {
    f32x4 vdst; f16x4 vsrc0; f16x4 vsrc1; f32x4 src2;
    __asm__ volatile("v_mfma_f32_4x4x4f16 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_f64_16x16x4f64() {
    f64x4 vdst; f64 vsrc0; f64 vsrc1; f64x4 src2;
    __asm__ volatile("v_mfma_f64_16x16x4f64 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_f64_4x4x4f64() {
    f64 vdst; f64 vsrc0; f64 vsrc1; f64 src2;
    __asm__ volatile("v_mfma_f64_4x4x4f64 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_i32_16x16x16i8() {
    i32x4 vdst; i8x4 vsrc0; i8x4 vsrc1; i32x4 src2;
    __asm__ volatile("v_mfma_i32_16x16x16i8 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_i32_16x16x4i8() {
    i32x16 vdst; i8x4 vsrc0; i8x4 vsrc1; i32x16 src2;
    __asm__ volatile("v_mfma_i32_16x16x4i8 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_i32_32x32x4i8() {
    i32x32 vdst; i8x4 vsrc0; i8x4 vsrc1; i32x32 src2;
    __asm__ volatile("v_mfma_i32_32x32x4i8 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_i32_32x32x8i8() {
    i32x16 vdst; i8x4 vsrc0; i8x4 vsrc1; i32x16 src2;
    __asm__ volatile("v_mfma_i32_32x32x8i8 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_mfma_i32_4x4x4i8() {
    i32x4 vdst; i8x4 vsrc0; i8x4 vsrc1; i32x4 src2;
    __asm__ volatile("v_mfma_i32_4x4x4i8 %0, %1, %2, %3 \n" : "=v"(vdst) : "v"(vsrc0), "v"(vsrc1), "v"(src2));
}

__global__ void v_accvgpr_read() {
    b32 vdst; b32 vsrc;
    __asm__ volatile("v_accvgpr_read %0, %1 \n" : "=v"(vdst) : "a"(vsrc));
}

__global__ void v_accvgpr_write() {
    b32 vdst; b32 src;
    __asm__ volatile("v_accvgpr_write %0, %1 \n" : "=a"(vdst) : "v"(src));
}

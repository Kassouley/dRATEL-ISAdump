<stdin>:        file format elf64-amdgpu

Disassembly of section .text:

0000000000001600 <_Z14ds_swizzle_b32v>:
        ds_swizzle_b32 v0, v0 offset:swizzle(QUAD_PERM,0,0,0,0)    // 000000001600: D87A8000 00000000
        ds_swizzle_b32 v0, v0 offset:swizzle(QUAD_PERM,0,1,2,3)    // 000000001608: D87A80E4 00000000
        ds_swizzle_b32 v0, v0 offset:swizzle(QUAD_PERM,3,3,3,3)    // 000000001610: D87A80FF 00000000
        ds_swizzle_b32 v0, v0                                      // 000000001618: D87A0000 00000000
        ds_swizzle_b32 v0, v0 offset:swizzle(BROADCAST,32,31)      // 000000001620: D87A03E0 00000000
        ds_swizzle_b32 v0, v0 offset:swizzle(REVERSE,32)           // 000000001628: D87A7C1F 00000000
        ds_swizzle_b32 v0, v0 offset:swizzle(BITMASK_PERM,"ppppp") // 000000001630: D87A001F 00000000
        ds_swizzle_b32 v0, v0 offset:swizzle(BITMASK_PERM,"01pi0") // 000000001638: D87A0906 00000000
        ds_swizzle_b32 v0, v0 offset:swizzle(BROADCAST,2,0)        // 000000001640: D87A001E 00000000
        ds_swizzle_b32 v0, v0                                      // 000000001648: D87A0000 00000000
        ds_swizzle_b32 v0, v0 offset:swizzle(SWAP,1)               // 000000001650: D87A041F 00000000
        ds_swizzle_b32 v0, v0 offset:swizzle(SWAP,8)               // 000000001658: D87A201F 00000000
        ds_swizzle_b32 v0, v0 offset:swizzle(SWAP,16)              // 000000001660: D87A401F 00000000
        ds_swizzle_b32 v0, v0 offset:swizzle(SWAP,1)               // 000000001668: D87A041F 00000000
        ds_swizzle_b32 v0, v0 offset:swizzle(REVERSE,16)           // 000000001670: D87A3C1F 00000000
        ds_swizzle_b32 v0, v0 offset:swizzle(REVERSE,32)           // 000000001678: D87A7C1F 00000000
        s_endpgm                                                   // 000000001680: BF810000
        s_nop 0                                                    // 000000001684: BF800000
        s_nop 0                                                    // 000000001688: BF800000
        s_nop 0                                                    // 00000000168C: BF800000
        s_nop 0                                                    // 000000001690: BF800000
        s_nop 0                                                    // 000000001694: BF800000
        s_nop 0                                                    // 000000001698: BF800000
        s_nop 0                                                    // 00000000169C: BF800000
        s_nop 0                                                    // 0000000016A0: BF800000
        s_nop 0                                                    // 0000000016A4: BF800000
        s_nop 0                                                    // 0000000016A8: BF800000
        s_nop 0                                                    // 0000000016AC: BF800000
        s_nop 0                                                    // 0000000016B0: BF800000
        s_nop 0                                                    // 0000000016B4: BF800000
        s_nop 0                                                    // 0000000016B8: BF800000
        s_nop 0                                                    // 0000000016BC: BF800000
        s_nop 0                                                    // 0000000016C0: BF800000
        s_nop 0                                                    // 0000000016C4: BF800000
        s_nop 0                                                    // 0000000016C8: BF800000
        s_nop 0                                                    // 0000000016CC: BF800000
        s_nop 0                                                    // 0000000016D0: BF800000
        s_nop 0                                                    // 0000000016D4: BF800000
        s_nop 0                                                    // 0000000016D8: BF800000
        s_nop 0                                                    // 0000000016DC: BF800000
        s_nop 0                                                    // 0000000016E0: BF800000
        s_nop 0                                                    // 0000000016E4: BF800000
        s_nop 0                                                    // 0000000016E8: BF800000
        s_nop 0                                                    // 0000000016EC: BF800000
        s_nop 0                                                    // 0000000016F0: BF800000
        s_nop 0                                                    // 0000000016F4: BF800000
        s_nop 0                                                    // 0000000016F8: BF800000
        s_nop 0                                                    // 0000000016FC: BF800000
        s_nop 0                                                    // 000000001700: BF800000
        s_nop 0                                                    // 000000001704: BF800000
        s_nop 0                                                    // 000000001708: BF800000
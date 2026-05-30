/*
 * SPDX-FileCopyrightText: 2026 Ilya Egorov <0x42005e1f@gmail.com>
 * SPDX-License-Identifier: ISC
 */

#ifndef C11ATOMIC_H
#  error "this header file must not be included directly"
#endif

/* memory scope */
#ifdef C11ATOMIC_GCC_SCOPED
typedef __typeof__(__MEMORY_SCOPE_SINGLE) c11atomic_ms;
#  define c11atomic_ms_single __MEMORY_SCOPE_SINGLE
#  define c11atomic_ms_wvfrnt __MEMORY_SCOPE_WVFRNT
#  define c11atomic_ms_wrkgrp __MEMORY_SCOPE_WRKGRP
#  define c11atomic_ms_clustr __MEMORY_SCOPE_CLUSTR
#  define c11atomic_ms_device __MEMORY_SCOPE_DEVICE
#  define c11atomic_ms_system __MEMORY_SCOPE_SYSTEM
#else
typedef enum {
    c11atomic_ms_single,
    c11atomic_ms_wvfrnt,
    c11atomic_ms_wrkgrp,
    c11atomic_ms_clustr,
    c11atomic_ms_device,
    c11atomic_ms_system,
} c11atomic_ms;
#endif

/* memory order */
typedef __typeof__(__ATOMIC_RELAXED) c11atomic_mo;
#define c11atomic_mo_relaxed __ATOMIC_RELAXED
#define c11atomic_mo_acquire __ATOMIC_ACQUIRE
#define c11atomic_mo_release __ATOMIC_RELEASE
#define c11atomic_mo_acq_rel __ATOMIC_ACQ_REL
#define c11atomic_mo_seq_cst __ATOMIC_SEQ_CST

/* atomic type */
#define c11atomic_vt(...) __typeof__(__VA_ARGS__)
#include "c11atomic_def.h"

/* atomic flag */
#if C11ATOMIC_BOOL_LOCK_FREE >= 2
#  define _C11ATOMIC_FLAG C11ATOMIC_BOOL
#  define _C11ATOMIC_FLAG_SET C11ATOMIC_TRUE
#  define _C11ATOMIC_FLAG_CLEAR C11ATOMIC_FALSE
#elif C11ATOMIC_INT_FAST8_T_LOCK_FREE >= 2
#  define _C11ATOMIC_FLAG C11ATOMIC_INT_FAST8_T
#  define _C11ATOMIC_FLAG_SET 1
#  define _C11ATOMIC_FLAG_CLEAR 0
#elif C11ATOMIC_BOOL_LOCK_FREE >= 1
#  define _C11ATOMIC_FLAG C11ATOMIC_BOOL
#  define _C11ATOMIC_FLAG_SET C11ATOMIC_TRUE
#  define _C11ATOMIC_FLAG_CLEAR C11ATOMIC_FALSE
#elif C11ATOMIC_INT_FAST8_T_LOCK_FREE >= 1
#  define _C11ATOMIC_FLAG C11ATOMIC_INT_FAST8_T
#  define _C11ATOMIC_FLAG_SET 1
#  define _C11ATOMIC_FLAG_CLEAR 0
#else
#  define _C11ATOMIC_FLAG C11ATOMIC_BOOL
#  define _C11ATOMIC_FLAG_SET C11ATOMIC_TRUE
#  define _C11ATOMIC_FLAG_CLEAR C11ATOMIC_FALSE
#endif
typedef _C11ATOMIC_FLAG c11atomic_flag_vt;
typedef struct { c11atomic_flag_vt _c11atomic_flag_v; } c11atomic_flag;
#define C11ATOMIC_FLAG_INIT { _C11ATOMIC_FLAG_CLEAR }

/*
 * SPDX-FileCopyrightText: 2026 Ilya Egorov <0x42005e1f@gmail.com>
 * SPDX-License-Identifier: ISC
 */

#ifndef C11ATOMIC_H
#  error "this header file must not be included directly"
#endif

/* memory scope */
typedef enum {
    c11atomic_ms_single,
    c11atomic_ms_wvfrnt,
    c11atomic_ms_wrkgrp,
    c11atomic_ms_clustr,
    c11atomic_ms_device,
    c11atomic_ms_system,
} c11atomic_ms;

/* memory order */
typedef enum {
    c11atomic_mo_relaxed,
    c11atomic_mo_acquire,
    c11atomic_mo_release,
    c11atomic_mo_acq_rel,
    c11atomic_mo_seq_cst,
} c11atomic_mo;

/* atomic type */
#if defined(__TINYC__) || defined(__GNUC__) || defined(__clang__)
#  define _C11ATOMIC_TYPEOF(...) __typeof__(__VA_ARGS__)
#elif defined(C11ATOMIC_C)
#  if defined(_MSC_VER)
#    if _MSC_VER >= 1939 // VS 2022 17.9
#      define _C11ATOMIC_TYPEOF(...) __typeof__(__VA_ARGS__)
#    endif
#  elif C11ATOMIC_C >= 202311L // C23
#    define _C11ATOMIC_TYPEOF(...) typeof(__VA_ARGS__)
#  endif
#endif
#ifdef _C11ATOMIC_TYPEOF
#  define c11atomic_vt(...) _C11ATOMIC_TYPEOF(__VA_ARGS__)
#else
#  define c11atomic_vt(...) __VA_ARGS__
#endif
#include "c11atomic_def.h"

/* atomic flag */
#define _C11ATOMIC_FLAG C11ATOMIC_CHAR
#define _C11ATOMIC_FLAG_SET 1
#define _C11ATOMIC_FLAG_CLEAR 0
typedef _C11ATOMIC_FLAG c11atomic_flag_vt;
typedef struct { c11atomic_flag_vt _c11atomic_flag_v; } c11atomic_flag;
#define C11ATOMIC_FLAG_INIT { _C11ATOMIC_FLAG_CLEAR }

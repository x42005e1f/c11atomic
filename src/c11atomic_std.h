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
#ifdef C11ATOMIC_STDCPP
typedef std::memory_order c11atomic_mo;
#else
typedef memory_order c11atomic_mo;
#endif
#ifdef C11ATOMIC_STDCPP
constexpr c11atomic_mo c11atomic_mo_relaxed = std::memory_order_relaxed;
constexpr c11atomic_mo c11atomic_mo_acquire = std::memory_order_acquire;
constexpr c11atomic_mo c11atomic_mo_release = std::memory_order_release;
constexpr c11atomic_mo c11atomic_mo_acq_rel = std::memory_order_acq_rel;
constexpr c11atomic_mo c11atomic_mo_seq_cst = std::memory_order_seq_cst;
#else
#  define c11atomic_mo_relaxed memory_order_relaxed
#  define c11atomic_mo_acquire memory_order_acquire
#  define c11atomic_mo_release memory_order_release
#  define c11atomic_mo_acq_rel memory_order_acq_rel
#  define c11atomic_mo_seq_cst memory_order_seq_cst
#endif

/* atomic type */
#ifdef C11ATOMIC_STDCPP
template<typename T>
using _c11atomic_vt = std::atomic<T>;
#  define c11atomic_vt(...) _c11atomic_vt<__VA_ARGS__>
#else
#  define c11atomic_vt(...) _Atomic(__VA_ARGS__)
#endif
#include "c11atomic_def.h"

/* atomic flag */
#ifdef C11ATOMIC_STDCPP
typedef std::atomic_flag c11atomic_flag_vt;
#else
typedef atomic_flag c11atomic_flag_vt;
#endif
typedef struct { c11atomic_flag_vt _c11atomic_flag_v; } c11atomic_flag;
#define C11ATOMIC_FLAG_INIT { ATOMIC_FLAG_INIT }

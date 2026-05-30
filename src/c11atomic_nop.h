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
#if defined(C11ATOMIC_GCC)
typedef __typeof__(__ATOMIC_RELAXED) c11atomic_mo;
#  define c11atomic_mo_relaxed __ATOMIC_RELAXED
#  define c11atomic_mo_acquire __ATOMIC_ACQUIRE
#  define c11atomic_mo_release __ATOMIC_RELEASE
#  define c11atomic_mo_acq_rel __ATOMIC_ACQ_REL
#  define c11atomic_mo_seq_cst __ATOMIC_SEQ_CST
#elif defined(C11ATOMIC_STD)
#  ifdef C11ATOMIC_STDCPP
typedef std::memory_order c11atomic_mo;
#  else
typedef memory_order c11atomic_mo;
#  endif
#  ifdef C11ATOMIC_STDCPP
constexpr c11atomic_mo c11atomic_mo_relaxed = std::memory_order_relaxed;
constexpr c11atomic_mo c11atomic_mo_acquire = std::memory_order_acquire;
constexpr c11atomic_mo c11atomic_mo_release = std::memory_order_release;
constexpr c11atomic_mo c11atomic_mo_acq_rel = std::memory_order_acq_rel;
constexpr c11atomic_mo c11atomic_mo_seq_cst = std::memory_order_seq_cst;
#  else
#    define c11atomic_mo_relaxed memory_order_relaxed
#    define c11atomic_mo_acquire memory_order_acquire
#    define c11atomic_mo_release memory_order_release
#    define c11atomic_mo_acq_rel memory_order_acq_rel
#    define c11atomic_mo_seq_cst memory_order_seq_cst
#  endif
#else
typedef enum {
    c11atomic_mo_relaxed,
    c11atomic_mo_acquire,
    c11atomic_mo_release,
    c11atomic_mo_acq_rel,
    c11atomic_mo_seq_cst,
} c11atomic_mo;
#endif

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
#define _C11ATOMIC_FLAG C11ATOMIC_BOOL
#define _C11ATOMIC_FLAG_SET C11ATOMIC_TRUE
#define _C11ATOMIC_FLAG_CLEAR C11ATOMIC_FALSE
typedef _C11ATOMIC_FLAG c11atomic_flag_vt;
typedef struct { c11atomic_flag_vt _c11atomic_flag_v; } c11atomic_flag;
#define C11ATOMIC_FLAG_INIT { _C11ATOMIC_FLAG_CLEAR }

/*------------------------- c11atomic_is_lock_free --------------------------*/
#define _c11atomic_is_lock_free_impl(volatile, S, T)                          \
static inline C11ATOMIC_BOOL                                                  \
_c11atomic_is_lock_free##S(const volatile c11atomic_vt(T) *obj)               \
_C11ATOMIC_NOEXCEPT                                                           \
{                                                                             \
    return C11ATOMIC_TRUE;                                                    \
}
_C11ATOMIC_FUNDAMENTAL_DEF1(_c11atomic_is_lock_free)
#define _c11atomic_is_lock_free(...)                                          \
_C11ATOMIC_VA(                                                                \
    _C11ATOMIC_FUNDAMENTAL_CALL_CONST(                                        \
        _c11atomic_is_lock_free,                                              \
        __VA_ARGS__                                                           \
    )                                                                         \
)
#define c11atomic_is_lock_free(obj)                                           \
    _c11atomic_is_lock_free(&(obj)->_c11atomic_v)

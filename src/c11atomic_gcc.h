/*
 * SPDX-FileCopyrightText: 2026 Ilya Egorov <0x42005e1f@gmail.com>
 * SPDX-License-Identifier: ISC
 */

#ifndef C11ATOMIC_INC
#  error "this header file must not be included directly"
#else /*=====================================================================*/

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

/*------------------------- c11atomic_is_lock_free --------------------------*/
#define _c11atomic_is_lock_free_impl(N, S, T, volatile)                       \
static inline C11ATOMIC_BOOL                                                  \
_c11atomic_is_lock_free##S(const volatile c11atomic_vt(T) *obj)               \
_C11ATOMIC_NOEXCEPT                                                           \
{                                                                             \
    return __atomic_is_lock_free(sizeof(__typeof__(*obj)), obj);              \
}
_C11ATOMIC_FUNDAMENTAL_DEF1(_c11atomic_is_lock_free_impl)
#define _c11atomic_is_lock_free(...)                                          \
_C11ATOMIC_VA(                                                                \
    _C11ATOMIC_FUNDAMENTAL_CALL_CONST(                                        \
        _c11atomic_is_lock_free,                                              \
        __VA_ARGS__                                                           \
    )                                                                         \
)
#define c11atomic_is_lock_free(obj)                                           \
    _c11atomic_is_lock_free(&(obj)->_c11atomic_v)

/*-------------------------- c11atomic_load_order ---------------------------*/
static inline c11atomic_mo
_c11atomic_load_order(c11atomic_mo order) // <- read-modify-write
_C11ATOMIC_NOEXCEPT
{
    switch (order) {
        case c11atomic_mo_release:
            return c11atomic_mo_relaxed;
        case c11atomic_mo_acq_rel:
            return c11atomic_mo_acquire;
        default:
            return order;
    }
}
#define c11atomic_load_order(order)                                           \
    _c11atomic_load_order(order)

/*-------------------------- c11atomic_store_order --------------------------*/
static inline c11atomic_mo
_c11atomic_store_order(c11atomic_mo order) // <- read-modify-write
_C11ATOMIC_NOEXCEPT
{
    switch (order) {
        case c11atomic_mo_acquire:
            return c11atomic_mo_relaxed;
        case c11atomic_mo_acq_rel:
            return c11atomic_mo_release;
        default:
            return order;
    }
}
#define c11atomic_store_order(order)                                          \
    _c11atomic_store_order(order)

/*------------------------- c11atomic_signal_fence --------------------------*/
static inline void
_c11atomic_signal_fence_explicit(c11atomic_ms scope, c11atomic_mo order)
_C11ATOMIC_NOEXCEPT
{
    __atomic_signal_fence(order);
}
#define c11atomic_signal_fence_explicit(scope, order)                         \
    _c11atomic_signal_fence_explicit(                                         \
        scope,                                                                \
        order                                                                 \
    )
#define c11atomic_signal_fence_ordered(order)                                 \
    _c11atomic_signal_fence_explicit(                                         \
        C11ATOMIC_DEFAULT_MEMORY_SCOPE,                                       \
        order                                                                 \
    )
#define c11atomic_signal_fence_scoped(scope)                                  \
    _c11atomic_signal_fence_explicit(                                         \
        scope,                                                                \
        C11ATOMIC_DEFAULT_MEMORY_ORDER                                        \
    )
#define c11atomic_signal_fence()                                              \
    _c11atomic_signal_fence_explicit(                                         \
        C11ATOMIC_DEFAULT_MEMORY_SCOPE,                                       \
        C11ATOMIC_DEFAULT_MEMORY_ORDER                                        \
    )

/*----------------------- c11atomic_load_signal_fence -----------------------*/
static inline void
_c11atomic_load_signal_fence_explicit(c11atomic_ms scope, c11atomic_mo order)
_C11ATOMIC_NOEXCEPT
{
    switch (order) {
        case c11atomic_mo_acquire:
        case c11atomic_mo_acq_rel:
        case c11atomic_mo_seq_cst:
            _c11atomic_signal_fence_explicit(scope, order);
    }
}
#define c11atomic_load_signal_fence_explicit(scope, order)                    \
    _c11atomic_load_signal_fence_explicit(                                    \
        scope,                                                                \
        order                                                                 \
    )
#define c11atomic_load_signal_fence_ordered(order)                            \
    _c11atomic_load_signal_fence_explicit(                                    \
        C11ATOMIC_DEFAULT_MEMORY_SCOPE,                                       \
        order                                                                 \
    )
#define c11atomic_load_signal_fence_scoped(scope)                             \
    _c11atomic_load_signal_fence_explicit(                                    \
        scope,                                                                \
        C11ATOMIC_DEFAULT_MEMORY_ORDER                                        \
    )
#define c11atomic_load_signal_fence()                                         \
    _c11atomic_load_signal_fence_explicit(                                    \
        C11ATOMIC_DEFAULT_MEMORY_SCOPE,                                       \
        C11ATOMIC_DEFAULT_MEMORY_ORDER                                        \
    )

/*---------------------- c11atomic_store_signal_fence -----------------------*/
static inline void
_c11atomic_store_signal_fence_explicit(c11atomic_ms scope, c11atomic_mo order)
_C11ATOMIC_NOEXCEPT
{
    switch (order) {
        case c11atomic_mo_release:
        case c11atomic_mo_acq_rel:
        case c11atomic_mo_seq_cst:
            _c11atomic_signal_fence_explicit(scope, order);
    }
}
#define c11atomic_store_signal_fence_explicit(scope, order)                   \
    _c11atomic_store_signal_fence_explicit(                                   \
        scope,                                                                \
        order                                                                 \
    )
#define c11atomic_store_signal_fence_ordered(order)                           \
    _c11atomic_store_signal_fence_explicit(                                   \
        C11ATOMIC_DEFAULT_MEMORY_SCOPE,                                       \
        order                                                                 \
    )
#define c11atomic_store_signal_fence_scoped(scope)                            \
    _c11atomic_store_signal_fence_explicit(                                   \
        scope,                                                                \
        C11ATOMIC_DEFAULT_MEMORY_ORDER                                        \
    )
#define c11atomic_store_signal_fence()                                        \
    _c11atomic_store_signal_fence_explicit(                                   \
        C11ATOMIC_DEFAULT_MEMORY_SCOPE,                                       \
        C11ATOMIC_DEFAULT_MEMORY_ORDER                                        \
    )

/*------------------------- c11atomic_thread_fence --------------------------*/
static inline void
_c11atomic_thread_fence_explicit(c11atomic_ms scope, c11atomic_mo order)
_C11ATOMIC_NOEXCEPT
{
#ifdef C11ATOMIC_GCC_SCOPED_THREAD_FENCE
    __scoped_atomic_thread_fence(order, scope);
#else
    __atomic_thread_fence(order);
#endif
}
#define c11atomic_thread_fence_explicit(scope, order)                         \
    _c11atomic_thread_fence_explicit(                                         \
        scope,                                                                \
        order                                                                 \
    )
#define c11atomic_thread_fence_ordered(order)                                 \
    _c11atomic_thread_fence_explicit(                                         \
        C11ATOMIC_DEFAULT_MEMORY_SCOPE,                                       \
        order                                                                 \
    )
#define c11atomic_thread_fence_scoped(scope)                                  \
    _c11atomic_thread_fence_explicit(                                         \
        scope,                                                                \
        C11ATOMIC_DEFAULT_MEMORY_ORDER                                        \
    )
#define c11atomic_thread_fence()                                              \
    _c11atomic_thread_fence_explicit(                                         \
        C11ATOMIC_DEFAULT_MEMORY_SCOPE,                                       \
        C11ATOMIC_DEFAULT_MEMORY_ORDER                                        \
    )

/*----------------------- c11atomic_load_thread_fence -----------------------*/
static inline void
_c11atomic_load_thread_fence_explicit(c11atomic_ms scope, c11atomic_mo order)
_C11ATOMIC_NOEXCEPT
{
    switch (order) {
        case c11atomic_mo_acquire:
        case c11atomic_mo_acq_rel:
        case c11atomic_mo_seq_cst:
#if defined(__x86_64__) || defined(_M_X64) // x86-64
            _c11atomic_signal_fence_explicit(scope, order);
#elif defined(__i386__) || defined(_M_IX86) // x86
            _c11atomic_signal_fence_explicit(scope, order);
#else
            _c11atomic_thread_fence_explicit(scope, order);
#endif
    }
}
#define c11atomic_load_thread_fence_explicit(scope, order)                    \
    _c11atomic_load_thread_fence_explicit(                                    \
        scope,                                                                \
        order                                                                 \
    )
#define c11atomic_load_thread_fence_ordered(order)                            \
    _c11atomic_load_thread_fence_explicit(                                    \
        C11ATOMIC_DEFAULT_MEMORY_SCOPE,                                       \
        order                                                                 \
    )
#define c11atomic_load_thread_fence_scoped(scope)                             \
    _c11atomic_load_thread_fence_explicit(                                    \
        scope,                                                                \
        C11ATOMIC_DEFAULT_MEMORY_ORDER                                        \
    )
#define c11atomic_load_thread_fence()                                         \
    _c11atomic_load_thread_fence_explicit(                                    \
        C11ATOMIC_DEFAULT_MEMORY_SCOPE,                                       \
        C11ATOMIC_DEFAULT_MEMORY_ORDER                                        \
    )

/*---------------------- c11atomic_store_thread_fence -----------------------*/
static inline void
_c11atomic_store_thread_fence_explicit(c11atomic_ms scope, c11atomic_mo order)
_C11ATOMIC_NOEXCEPT
{
    switch (order) {
        case c11atomic_mo_release:
        case c11atomic_mo_acq_rel:
        case c11atomic_mo_seq_cst:
#if defined(__x86_64__) || defined(_M_X64) // x86-64
            _c11atomic_signal_fence_explicit(scope, order);
#elif defined(__i386__) || defined(_M_IX86) // x86
            _c11atomic_signal_fence_explicit(scope, order);
#else
            _c11atomic_thread_fence_explicit(scope, order);
#endif
    }
}
#define c11atomic_store_thread_fence_explicit(scope, order)                   \
    _c11atomic_store_thread_fence_explicit(                                   \
        scope,                                                                \
        order                                                                 \
    )
#define c11atomic_store_thread_fence_ordered(order)                           \
    _c11atomic_store_thread_fence_explicit(                                   \
        C11ATOMIC_DEFAULT_MEMORY_SCOPE,                                       \
        order                                                                 \
    )
#define c11atomic_store_thread_fence_scoped(scope)                            \
    _c11atomic_store_thread_fence_explicit(                                   \
        scope,                                                                \
        C11ATOMIC_DEFAULT_MEMORY_ORDER                                        \
    )
#define c11atomic_store_thread_fence()                                        \
    _c11atomic_store_thread_fence_explicit(                                   \
        C11ATOMIC_DEFAULT_MEMORY_SCOPE,                                       \
        C11ATOMIC_DEFAULT_MEMORY_ORDER                                        \
    )

#endif /*====================================================================*/

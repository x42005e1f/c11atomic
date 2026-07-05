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

/*------------------------- c11atomic_is_lock_free --------------------------*/
#define _c11atomic_is_lock_free_impl(N, S, T, volatile)                       \
static inline C11ATOMIC_BOOL                                                  \
_c11atomic_is_lock_free##S(const volatile c11atomic_vt(T) *obj)               \
_C11ATOMIC_NOEXCEPT                                                           \
{                                                                             \
    return _C11ATOMIC_STD_CALL(atomic_is_lock_free, obj);                     \
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
    _C11ATOMIC_STD_CALL(atomic_signal_fence, order);
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
    _C11ATOMIC_STD_CALL(atomic_thread_fence, order);
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

/*
 * SPDX-FileCopyrightText: 2026 Ilya Egorov <0x42005e1f@gmail.com>
 * SPDX-License-Identifier: ISC
 */

#ifndef C11ATOMIC_H
#  error "this header file must not be included directly"
#endif
#ifdef __has_include // Clang 2.7, GCC 5.1, C++17, C23, ...
#  define _C11ATOMIC_HAS_INCLUDE_OPTIMISTIC(...) __has_include(__VA_ARGS__)
#else
#  define _C11ATOMIC_HAS_INCLUDE_OPTIMISTIC(...) 1
#endif
#ifdef C11ATOMIC_CPP
#  if _C11ATOMIC_HAS_INCLUDE_OPTIMISTIC(<atomic>) // C++11
#    define _C11ATOMIC_ATOMIC_H
#  endif
#endif
#ifdef _MSC_VER
#  if _C11ATOMIC_HAS_INCLUDE_OPTIMISTIC(<intrin.h>) // MSVC intrinsics
#    define _C11ATOMIC_INTRIN_H
#  endif
#endif
#if _C11ATOMIC_HAS_INCLUDE_OPTIMISTIC(<limits.h>)
#  define _C11ATOMIC_LIMITS_H
#endif
#ifdef C11ATOMIC_C
#  if !defined(__STDC_NO_ATOMICS__)
#    if _C11ATOMIC_HAS_INCLUDE_OPTIMISTIC(<stdatomic.h>) // C11 (optional)
#      define _C11ATOMIC_STDATOMIC_H
#    endif
#  endif
#  if C11ATOMIC_C >= 202311L // C23: predefined `bool`, `true`, and `false`
#    define _C11ATOMIC_BOOL_TRUE_FALSE_ARE_DEFINED
#  elif _C11ATOMIC_HAS_INCLUDE_OPTIMISTIC(<stdbool.h>) // C99
#    define _C11ATOMIC_BOOL_TRUE_FALSE_ARE_DEFINED
#    define _C11ATOMIC_STDBOOL_H
#  endif
#else // C++: `bool`, `true`, and `false` are keywords
#  define _C11ATOMIC_BOOL_TRUE_FALSE_ARE_DEFINED
#endif
#if _C11ATOMIC_HAS_INCLUDE_OPTIMISTIC(<stddef.h>)
#  define _C11ATOMIC_STDDEF_H
#endif
#if _C11ATOMIC_HAS_INCLUDE_OPTIMISTIC(<stdint.h>) // C99
#  define _C11ATOMIC_STDINT_H
#endif

#ifdef __cplusplus
extern "C++" {
#endif
#ifdef _C11ATOMIC_ATOMIC_H
#  include <atomic>
#endif
#ifdef __cplusplus
}
#endif
#ifdef _C11ATOMIC_INTRIN_H
#  include <intrin.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif
#ifdef _C11ATOMIC_LIMITS_H
#  include <limits.h>
#endif
#ifdef _C11ATOMIC_STDATOMIC_H
#  include <stdatomic.h>
#endif
#ifdef _C11ATOMIC_STDBOOL_H
#  include <stdbool.h>
#endif
#ifdef _C11ATOMIC_STDDEF_H
#  include <stddef.h>
#endif
#ifdef _C11ATOMIC_STDINT_H
#  include <stdint.h>
#endif
#ifdef __cplusplus
}
#endif

#ifndef C11ATOMIC
#  ifdef _C11ATOMIC_ATOMIC_H
#    define C11ATOMIC
#    define C11ATOMIC_STD
#  endif
#  ifdef _C11ATOMIC_INTRIN_H
#    define C11ATOMIC
#    define C11ATOMIC_MSC
#  endif
#  ifdef _C11ATOMIC_STDATOMIC_H
#    define C11ATOMIC
#    define C11ATOMIC_STD
#  endif
#  if defined(__GNUC__) && defined(__GNUC_MINOR__)
#    if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 8)
#      define C11ATOMIC
#      define C11ATOMIC_GCC
#    endif
#  endif
#  if defined(__clang__) && defined(__has_feature) && defined(__has_extension)
#    if __has_feature(cxx_atomic) || __has_extension(c_atomic) // Clang 3.1
#      define C11ATOMIC
#      define C11ATOMIC_CLANG
#    endif
#  endif
#endif
#ifdef C11ATOMIC
#  if defined(C11ATOMIC_STDCPP) || defined(C11ATOMIC_STDC)
#    define C11ATOMIC_STD
#  elif defined(C11ATOMIC_STD)
#    if defined(_C11ATOMIC_ATOMIC_H)
#      define C11ATOMIC_STDCPP
#    elif defined(_C11ATOMIC_STDATOMIC_H)
#      define C11ATOMIC_STDC
#    elif defined(C11ATOMIC_CPP)
#      define C11ATOMIC_STDCPP
#    elif defined(C11ATOMIC_C)
#      define C11ATOMIC_STDC
#    endif
#  endif
#  ifdef C11ATOMIC_STDCPP
#    ifdef __cpp_lib_atomic_min_max // C++26
#      define C11ATOMIC_STDCPP_FETCH_MINMAX // `std::atomic_fetch_<min|max>()`
#    endif
#  endif
#  ifdef C11ATOMIC_CLANG
#    ifdef __has_builtin
#      if __has_builtin(__atomic_load) // Clang 3.1
#        define C11ATOMIC_GCC // `__atomic_*`
#      endif
#      if __has_builtin(__atomic_fetch_max) // Clang 7.0
#        define C11ATOMIC_GCC_FETCH_MINMAX // `__atomic_fetch_<min|max>()`
#      endif
#      if __has_builtin(__atomic_max_fetch) // Clang 10.0
#        define C11ATOMIC_GCC_MINMAX_FETCH // `__atomic_<min|max>_fetch()`
#      endif
#      if __has_builtin(__scoped_atomic_load) // Clang 18.1
#        define C11ATOMIC_GCC_SCOPED // `__scoped_atomic_*`
#      endif
#      if __has_builtin(__scoped_atomic_thread_fence) // Clang 20.1
#        define C11ATOMIC_GCC_SCOPED_THREAD_FENCE
#      endif
#    endif
#  endif
#  if defined(C11ATOMIC_GCC)
#    ifdef C11ATOMIC_NOP
#      include "c11atomic_nop.h"
#    else
#      include "c11atomic_gcc.h"
#    endif
#  elif defined(C11ATOMIC_STD)
#    ifdef C11ATOMIC_NOP
#      include "c11atomic_nop.h"
#    else
#      include "c11atomic_std.h"
#    endif
#  elif defined(C11ATOMIC_MSC)
#    ifdef C11ATOMIC_NOP
#      include "c11atomic_nop.h"
#    else
#      include "c11atomic_msc.h"
#    endif
#  endif
#endif

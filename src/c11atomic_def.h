/*
 * SPDX-FileCopyrightText: 2026 Ilya Egorov <0x42005e1f@gmail.com>
 * SPDX-License-Identifier: ISC
 */

#ifndef C11ATOMIC_H
#  error "this header file must not be included directly"
#endif
#ifndef C11ATOMIC_DEFAULT_MEMORY_SCOPE
#  define C11ATOMIC_DEFAULT_MEMORY_SCOPE                                      \
    c11atomic_ms_device
#endif
#ifndef C11ATOMIC_DEFAULT_MEMORY_ORDER
#  define C11ATOMIC_DEFAULT_MEMORY_ORDER                                      \
    c11atomic_mo_relaxed
#endif
#ifndef C11ATOMIC_DEFAULT_STORE_MEMORY_ORDER
#  define C11ATOMIC_DEFAULT_STORE_MEMORY_ORDER                                \
    C11ATOMIC_DEFAULT_MEMORY_ORDER
#endif
#ifndef C11ATOMIC_DEFAULT_LOAD_MEMORY_ORDER
#  define C11ATOMIC_DEFAULT_LOAD_MEMORY_ORDER                                 \
    C11ATOMIC_DEFAULT_MEMORY_ORDER
#endif
#ifndef C11ATOMIC_DEFAULT_RMW_MEMORY_ORDER
#  define C11ATOMIC_DEFAULT_RMW_MEMORY_ORDER                                  \
    C11ATOMIC_DEFAULT_MEMORY_ORDER
#endif
#ifndef C11ATOMIC_DEFAULT_SUCCESS_MEMORY_ORDER
#  define C11ATOMIC_DEFAULT_SUCCESS_MEMORY_ORDER                              \
    C11ATOMIC_DEFAULT_RMW_MEMORY_ORDER
#endif
#ifndef C11ATOMIC_DEFAULT_FAILURE_MEMORY_ORDER
#  define C11ATOMIC_DEFAULT_FAILURE_MEMORY_ORDER                              \
    C11ATOMIC_DEFAULT_LOAD_MEMORY_ORDER
#endif
#define C11ATOMIC_POINTER void *
#if defined(C11ATOMIC_STD)
#  define C11ATOMIC_POINTER_LOCK_FREE ATOMIC_POINTER_LOCK_FREE
#elif defined(C11ATOMIC_MSC)
#  define C11ATOMIC_POINTER_LOCK_FREE 2
#else
#  define C11ATOMIC_POINTER_LOCK_FREE 1
#endif
#if _C11ATOMIC_BOOL_TRUE_FALSE_ARE_DEFINED
#  define C11ATOMIC_BOOL bool
#  define C11ATOMIC_TRUE true
#  define C11ATOMIC_FALSE false
#else
#  define C11ATOMIC_BOOL _Bool // C99
#  define C11ATOMIC_TRUE 1
#  define C11ATOMIC_FALSE 0
#endif
#if defined(C11ATOMIC_STD)
#  define C11ATOMIC_BOOL_LOCK_FREE ATOMIC_BOOL_LOCK_FREE
#elif defined(C11ATOMIC_MSC)
#  define C11ATOMIC_BOOL_LOCK_FREE 2
#else
#  define C11ATOMIC_BOOL_LOCK_FREE 1
#endif
#define C11ATOMIC_CHAR char
#if defined(C11ATOMIC_STD)
#  define C11ATOMIC_CHAR_LOCK_FREE ATOMIC_CHAR_LOCK_FREE
#elif defined(C11ATOMIC_MSC)
#  define C11ATOMIC_CHAR_LOCK_FREE 2
#else
#  define C11ATOMIC_CHAR_LOCK_FREE 1
#endif
#define C11ATOMIC_SCHAR signed char
#define C11ATOMIC_SCHAR_LOCK_FREE C11ATOMIC_CHAR_LOCK_FREE
#define C11ATOMIC_UCHAR unsigned char
#define C11ATOMIC_UCHAR_LOCK_FREE C11ATOMIC_CHAR_LOCK_FREE
#define C11ATOMIC_SHORT short
#if defined(C11ATOMIC_STD)
#  define C11ATOMIC_SHORT_LOCK_FREE ATOMIC_SHORT_LOCK_FREE
#elif defined(C11ATOMIC_MSC)
#  define C11ATOMIC_SHORT_LOCK_FREE 2
#else
#  define C11ATOMIC_SHORT_LOCK_FREE 1
#endif
#define C11ATOMIC_USHORT unsigned short
#define C11ATOMIC_USHORT_LOCK_FREE C11ATOMIC_SHORT_LOCK_FREE
#define C11ATOMIC_INT int
#if defined(C11ATOMIC_STD)
#  define C11ATOMIC_INT_LOCK_FREE ATOMIC_INT_LOCK_FREE
#elif defined(C11ATOMIC_MSC)
#  define C11ATOMIC_INT_LOCK_FREE 2
#else
#  define C11ATOMIC_INT_LOCK_FREE 1
#endif
#define C11ATOMIC_UINT unsigned int
#define C11ATOMIC_UINT_LOCK_FREE C11ATOMIC_INT_LOCK_FREE
#define C11ATOMIC_LONG long
#if defined(C11ATOMIC_STD)
#  define C11ATOMIC_LONG_LOCK_FREE ATOMIC_LONG_LOCK_FREE
#elif defined(C11ATOMIC_MSC)
#  define C11ATOMIC_LONG_LOCK_FREE 2
#else
#  define C11ATOMIC_LONG_LOCK_FREE 1
#endif
#define C11ATOMIC_ULONG unsigned long
#define C11ATOMIC_ULONG_LOCK_FREE C11ATOMIC_LONG_LOCK_FREE
#define C11ATOMIC_LLONG long long
#if defined(C11ATOMIC_STD)
#  define C11ATOMIC_LLONG_LOCK_FREE ATOMIC_LLONG_LOCK_FREE
#elif defined(C11ATOMIC_MSC)
#  define C11ATOMIC_LLONG_LOCK_FREE 2
#else
#  define C11ATOMIC_LLONG_LOCK_FREE 1
#endif
#define C11ATOMIC_ULLONG unsigned long long
#define C11ATOMIC_ULLONG_LOCK_FREE C11ATOMIC_LLONG_LOCK_FREE
#ifdef _C11ATOMIC_STDINT_H
#  ifdef INT8_MAX // <stdint.h> (optional)
#    define C11ATOMIC_INT8_T int8_t
#    ifdef _C11ATOMIC_LIMITS_H
#      if INT8_MAX == SCHAR_MAX
#        define C11ATOMIC_INT8_T_LOCK_FREE C11ATOMIC_SCHAR_LOCK_FREE
#      endif
#    endif
#    ifndef C11ATOMIC_INT8_T_LOCK_FREE
#      define C11ATOMIC_INT8_T_LOCK_FREE 1
#    endif
#  endif
#  ifdef UINT8_MAX // <stdint.h> (optional)
#    define C11ATOMIC_UINT8_T uint8_t
#    ifdef _C11ATOMIC_LIMITS_H
#      if UINT8_MAX == UCHAR_MAX
#        define C11ATOMIC_UINT8_T_LOCK_FREE C11ATOMIC_UCHAR_LOCK_FREE
#      endif
#    endif
#    ifndef C11ATOMIC_UINT8_T_LOCK_FREE
#      define C11ATOMIC_UINT8_T_LOCK_FREE 1
#    endif
#  endif
#  ifdef INT16_MAX // <stdint.h> (optional)
#    define C11ATOMIC_INT16_T int16_t
#    ifdef _C11ATOMIC_LIMITS_H
#      if INT16_MAX == INT_MAX
#        define C11ATOMIC_INT16_T_LOCK_FREE C11ATOMIC_INT_LOCK_FREE
#      elif INT16_MAX == SHRT_MAX
#        define C11ATOMIC_INT16_T_LOCK_FREE C11ATOMIC_SHORT_LOCK_FREE
#      elif INT16_MAX == SCHAR_MAX
#        define C11ATOMIC_INT16_T_LOCK_FREE C11ATOMIC_SCHAR_LOCK_FREE
#      endif
#    endif
#    ifndef C11ATOMIC_INT16_T_LOCK_FREE
#      define C11ATOMIC_INT16_T_LOCK_FREE 1
#    endif
#  endif
#  ifdef UINT16_MAX // <stdint.h> (optional)
#    define C11ATOMIC_UINT16_T uint16_t
#    ifdef _C11ATOMIC_LIMITS_H
#      if UINT16_MAX == UINT_MAX
#        define C11ATOMIC_UINT16_T_LOCK_FREE C11ATOMIC_UINT_LOCK_FREE
#      elif UINT16_MAX == USHRT_MAX
#        define C11ATOMIC_UINT16_T_LOCK_FREE C11ATOMIC_USHORT_LOCK_FREE
#      elif UINT16_MAX == UCHAR_MAX
#        define C11ATOMIC_UINT16_T_LOCK_FREE C11ATOMIC_UCHAR_LOCK_FREE
#      endif
#    endif
#    ifndef C11ATOMIC_UINT16_T_LOCK_FREE
#      define C11ATOMIC_UINT16_T_LOCK_FREE 1
#    endif
#  endif
#  ifdef INT32_MAX // <stdint.h> (optional)
#    define C11ATOMIC_INT32_T int32_t
#    ifdef _C11ATOMIC_LIMITS_H
#      if INT32_MAX == LONG_MAX
#        define C11ATOMIC_INT32_T_LOCK_FREE C11ATOMIC_LONG_LOCK_FREE
#      elif INT32_MAX == INT_MAX
#        define C11ATOMIC_INT32_T_LOCK_FREE C11ATOMIC_INT_LOCK_FREE
#      elif INT32_MAX == SHRT_MAX
#        define C11ATOMIC_INT32_T_LOCK_FREE C11ATOMIC_SHORT_LOCK_FREE
#      elif INT32_MAX == SCHAR_MAX
#        define C11ATOMIC_INT32_T_LOCK_FREE C11ATOMIC_SCHAR_LOCK_FREE
#      endif
#    endif
#    ifndef C11ATOMIC_INT32_T_LOCK_FREE
#      define C11ATOMIC_INT32_T_LOCK_FREE 1
#    endif
#  endif
#  ifdef UINT32_MAX // <stdint.h> (optional)
#    define C11ATOMIC_UINT32_T uint32_t
#    ifdef _C11ATOMIC_LIMITS_H
#      if UINT32_MAX == ULONG_MAX
#        define C11ATOMIC_UINT32_T_LOCK_FREE C11ATOMIC_ULONG_LOCK_FREE
#      elif UINT32_MAX == UINT_MAX
#        define C11ATOMIC_UINT32_T_LOCK_FREE C11ATOMIC_UINT_LOCK_FREE
#      elif UINT32_MAX == USHRT_MAX
#        define C11ATOMIC_UINT32_T_LOCK_FREE C11ATOMIC_USHORT_LOCK_FREE
#      elif UINT32_MAX == UCHAR_MAX
#        define C11ATOMIC_UINT32_T_LOCK_FREE C11ATOMIC_UCHAR_LOCK_FREE
#      endif
#    endif
#    ifndef C11ATOMIC_UINT32_T_LOCK_FREE
#      define C11ATOMIC_UINT32_T_LOCK_FREE 1
#    endif
#  endif
#  ifdef INT64_MAX // <stdint.h> (optional)
#    define C11ATOMIC_INT64_T int64_t
#    ifdef _C11ATOMIC_LIMITS_H
#      if INT64_MAX == LLONG_MAX
#        define C11ATOMIC_INT64_T_LOCK_FREE C11ATOMIC_LLONG_LOCK_FREE
#      elif INT64_MAX == LONG_MAX
#        define C11ATOMIC_INT64_T_LOCK_FREE C11ATOMIC_LONG_LOCK_FREE
#      elif INT64_MAX == INT_MAX
#        define C11ATOMIC_INT64_T_LOCK_FREE C11ATOMIC_INT_LOCK_FREE
#      elif INT64_MAX == SHRT_MAX
#        define C11ATOMIC_INT64_T_LOCK_FREE C11ATOMIC_SHORT_LOCK_FREE
#      elif INT64_MAX == SCHAR_MAX
#        define C11ATOMIC_INT64_T_LOCK_FREE C11ATOMIC_SCHAR_LOCK_FREE
#      endif
#    endif
#    ifndef C11ATOMIC_INT64_T_LOCK_FREE
#      define C11ATOMIC_INT64_T_LOCK_FREE 1
#    endif
#  endif
#  ifdef UINT64_MAX // <stdint.h> (optional)
#    define C11ATOMIC_UINT64_T uint64_t
#    ifdef _C11ATOMIC_LIMITS_H
#      if UINT64_MAX == ULLONG_MAX
#        define C11ATOMIC_UINT64_T_LOCK_FREE C11ATOMIC_ULLONG_LOCK_FREE
#      elif UINT64_MAX == ULONG_MAX
#        define C11ATOMIC_UINT64_T_LOCK_FREE C11ATOMIC_ULONG_LOCK_FREE
#      elif UINT64_MAX == UINT_MAX
#        define C11ATOMIC_UINT64_T_LOCK_FREE C11ATOMIC_UINT_LOCK_FREE
#      elif UINT64_MAX == USHRT_MAX
#        define C11ATOMIC_UINT64_T_LOCK_FREE C11ATOMIC_USHORT_LOCK_FREE
#      elif UINT64_MAX == UCHAR_MAX
#        define C11ATOMIC_UINT64_T_LOCK_FREE C11ATOMIC_UCHAR_LOCK_FREE
#      endif
#    endif
#    ifndef C11ATOMIC_UINT64_T_LOCK_FREE
#      define C11ATOMIC_UINT64_T_LOCK_FREE 1
#    endif
#  endif
#  define C11ATOMIC_INT_LEAST8_T int_least8_t
#  ifdef _C11ATOMIC_LIMITS_H
#    ifdef INT_LEAST8_MAX // <stdint.h>
#      if INT_LEAST8_MAX == LLONG_MAX
#        define C11ATOMIC_INT_LEAST8_T_LOCK_FREE C11ATOMIC_LLONG_LOCK_FREE
#      elif INT_LEAST8_MAX == LONG_MAX
#        define C11ATOMIC_INT_LEAST8_T_LOCK_FREE C11ATOMIC_LONG_LOCK_FREE
#      elif INT_LEAST8_MAX == INT_MAX
#        define C11ATOMIC_INT_LEAST8_T_LOCK_FREE C11ATOMIC_INT_LOCK_FREE
#      elif INT_LEAST8_MAX == SHRT_MAX
#        define C11ATOMIC_INT_LEAST8_T_LOCK_FREE C11ATOMIC_SHORT_LOCK_FREE
#      elif INT_LEAST8_MAX == SCHAR_MAX
#        define C11ATOMIC_INT_LEAST8_T_LOCK_FREE C11ATOMIC_SCHAR_LOCK_FREE
#      endif
#    endif
#  endif
#  ifndef C11ATOMIC_INT_LEAST8_T_LOCK_FREE
#    define C11ATOMIC_INT_LEAST8_T_LOCK_FREE 1
#  endif
#  define C11ATOMIC_UINT_LEAST8_T uint_least8_t
#  ifdef _C11ATOMIC_LIMITS_H
#    ifdef UINT_LEAST8_MAX // <stdint.h>
#      if UINT_LEAST8_MAX == ULLONG_MAX
#        define C11ATOMIC_UINT_LEAST8_T_LOCK_FREE C11ATOMIC_ULLONG_LOCK_FREE
#      elif UINT_LEAST8_MAX == ULONG_MAX
#        define C11ATOMIC_UINT_LEAST8_T_LOCK_FREE C11ATOMIC_ULONG_LOCK_FREE
#      elif UINT_LEAST8_MAX == UINT_MAX
#        define C11ATOMIC_UINT_LEAST8_T_LOCK_FREE C11ATOMIC_UINT_LOCK_FREE
#      elif UINT_LEAST8_MAX == USHRT_MAX
#        define C11ATOMIC_UINT_LEAST8_T_LOCK_FREE C11ATOMIC_USHORT_LOCK_FREE
#      elif UINT_LEAST8_MAX == UCHAR_MAX
#        define C11ATOMIC_UINT_LEAST8_T_LOCK_FREE C11ATOMIC_UCHAR_LOCK_FREE
#      endif
#    endif
#  endif
#  ifndef C11ATOMIC_UINT_LEAST8_T_LOCK_FREE
#    define C11ATOMIC_UINT_LEAST8_T_LOCK_FREE 1
#  endif
#  define C11ATOMIC_INT_LEAST16_T int_least16_t
#  ifdef _C11ATOMIC_LIMITS_H
#    ifdef INT_LEAST16_MAX // <stdint.h>
#      if INT_LEAST16_MAX == LLONG_MAX
#        define C11ATOMIC_INT_LEAST16_T_LOCK_FREE C11ATOMIC_LLONG_LOCK_FREE
#      elif INT_LEAST16_MAX == LONG_MAX
#        define C11ATOMIC_INT_LEAST16_T_LOCK_FREE C11ATOMIC_LONG_LOCK_FREE
#      elif INT_LEAST16_MAX == INT_MAX
#        define C11ATOMIC_INT_LEAST16_T_LOCK_FREE C11ATOMIC_INT_LOCK_FREE
#      elif INT_LEAST16_MAX == SHRT_MAX
#        define C11ATOMIC_INT_LEAST16_T_LOCK_FREE C11ATOMIC_SHORT_LOCK_FREE
#      elif INT_LEAST16_MAX == SCHAR_MAX
#        define C11ATOMIC_INT_LEAST16_T_LOCK_FREE C11ATOMIC_SCHAR_LOCK_FREE
#      endif
#    endif
#  endif
#  ifndef C11ATOMIC_INT_LEAST16_T_LOCK_FREE
#    define C11ATOMIC_INT_LEAST16_T_LOCK_FREE 1
#  endif
#  define C11ATOMIC_UINT_LEAST16_T uint_least16_t
#  ifdef _C11ATOMIC_LIMITS_H
#    ifdef UINT_LEAST16_MAX // <stdint.h>
#      if UINT_LEAST16_MAX == ULLONG_MAX
#        define C11ATOMIC_UINT_LEAST16_T_LOCK_FREE C11ATOMIC_ULLONG_LOCK_FREE
#      elif UINT_LEAST16_MAX == ULONG_MAX
#        define C11ATOMIC_UINT_LEAST16_T_LOCK_FREE C11ATOMIC_ULONG_LOCK_FREE
#      elif UINT_LEAST16_MAX == UINT_MAX
#        define C11ATOMIC_UINT_LEAST16_T_LOCK_FREE C11ATOMIC_UINT_LOCK_FREE
#      elif UINT_LEAST16_MAX == USHRT_MAX
#        define C11ATOMIC_UINT_LEAST16_T_LOCK_FREE C11ATOMIC_USHORT_LOCK_FREE
#      elif UINT_LEAST16_MAX == UCHAR_MAX
#        define C11ATOMIC_UINT_LEAST16_T_LOCK_FREE C11ATOMIC_UCHAR_LOCK_FREE
#      endif
#    endif
#  endif
#  ifndef C11ATOMIC_UINT_LEAST16_T_LOCK_FREE
#    define C11ATOMIC_UINT_LEAST16_T_LOCK_FREE 1
#  endif
#  define C11ATOMIC_INT_LEAST32_T int_least32_t
#  ifdef _C11ATOMIC_LIMITS_H
#    ifdef INT_LEAST32_MAX // <stdint.h>
#      if INT_LEAST32_MAX == LLONG_MAX
#        define C11ATOMIC_INT_LEAST32_T_LOCK_FREE C11ATOMIC_LLONG_LOCK_FREE
#      elif INT_LEAST32_MAX == LONG_MAX
#        define C11ATOMIC_INT_LEAST32_T_LOCK_FREE C11ATOMIC_LONG_LOCK_FREE
#      elif INT_LEAST32_MAX == INT_MAX
#        define C11ATOMIC_INT_LEAST32_T_LOCK_FREE C11ATOMIC_INT_LOCK_FREE
#      elif INT_LEAST32_MAX == SHRT_MAX
#        define C11ATOMIC_INT_LEAST32_T_LOCK_FREE C11ATOMIC_SHORT_LOCK_FREE
#      elif INT_LEAST32_MAX == SCHAR_MAX
#        define C11ATOMIC_INT_LEAST32_T_LOCK_FREE C11ATOMIC_SCHAR_LOCK_FREE
#      endif
#    endif
#  endif
#  ifndef C11ATOMIC_INT_LEAST32_T_LOCK_FREE
#    define C11ATOMIC_INT_LEAST32_T_LOCK_FREE 1
#  endif
#  define C11ATOMIC_UINT_LEAST32_T uint_least32_t
#  ifdef _C11ATOMIC_LIMITS_H
#    ifdef UINT_LEAST32_MAX // <stdint.h>
#      if UINT_LEAST32_MAX == ULLONG_MAX
#        define C11ATOMIC_UINT_LEAST32_T_LOCK_FREE C11ATOMIC_ULLONG_LOCK_FREE
#      elif UINT_LEAST32_MAX == ULONG_MAX
#        define C11ATOMIC_UINT_LEAST32_T_LOCK_FREE C11ATOMIC_ULONG_LOCK_FREE
#      elif UINT_LEAST32_MAX == UINT_MAX
#        define C11ATOMIC_UINT_LEAST32_T_LOCK_FREE C11ATOMIC_UINT_LOCK_FREE
#      elif UINT_LEAST32_MAX == USHRT_MAX
#        define C11ATOMIC_UINT_LEAST32_T_LOCK_FREE C11ATOMIC_USHORT_LOCK_FREE
#      elif UINT_LEAST32_MAX == UCHAR_MAX
#        define C11ATOMIC_UINT_LEAST32_T_LOCK_FREE C11ATOMIC_UCHAR_LOCK_FREE
#      endif
#    endif
#  endif
#  ifndef C11ATOMIC_UINT_LEAST32_T_LOCK_FREE
#    define C11ATOMIC_UINT_LEAST32_T_LOCK_FREE 1
#  endif
#  define C11ATOMIC_INT_LEAST64_T int_least64_t
#  ifdef _C11ATOMIC_LIMITS_H
#    ifdef INT_LEAST64_MAX // <stdint.h>
#      if INT_LEAST64_MAX == LLONG_MAX
#        define C11ATOMIC_INT_LEAST64_T_LOCK_FREE C11ATOMIC_LLONG_LOCK_FREE
#      elif INT_LEAST64_MAX == LONG_MAX
#        define C11ATOMIC_INT_LEAST64_T_LOCK_FREE C11ATOMIC_LONG_LOCK_FREE
#      elif INT_LEAST64_MAX == INT_MAX
#        define C11ATOMIC_INT_LEAST64_T_LOCK_FREE C11ATOMIC_INT_LOCK_FREE
#      elif INT_LEAST64_MAX == SHRT_MAX
#        define C11ATOMIC_INT_LEAST64_T_LOCK_FREE C11ATOMIC_SHORT_LOCK_FREE
#      elif INT_LEAST64_MAX == SCHAR_MAX
#        define C11ATOMIC_INT_LEAST64_T_LOCK_FREE C11ATOMIC_SCHAR_LOCK_FREE
#      endif
#    endif
#  endif
#  ifndef C11ATOMIC_INT_LEAST64_T_LOCK_FREE
#    define C11ATOMIC_INT_LEAST64_T_LOCK_FREE 1
#  endif
#  define C11ATOMIC_UINT_LEAST64_T uint_least64_t
#  ifdef _C11ATOMIC_LIMITS_H
#    ifdef UINT_LEAST64_MAX // <stdint.h>
#      if UINT_LEAST64_MAX == ULLONG_MAX
#        define C11ATOMIC_UINT_LEAST64_T_LOCK_FREE C11ATOMIC_ULLONG_LOCK_FREE
#      elif UINT_LEAST64_MAX == ULONG_MAX
#        define C11ATOMIC_UINT_LEAST64_T_LOCK_FREE C11ATOMIC_ULONG_LOCK_FREE
#      elif UINT_LEAST64_MAX == UINT_MAX
#        define C11ATOMIC_UINT_LEAST64_T_LOCK_FREE C11ATOMIC_UINT_LOCK_FREE
#      elif UINT_LEAST64_MAX == USHRT_MAX
#        define C11ATOMIC_UINT_LEAST64_T_LOCK_FREE C11ATOMIC_USHORT_LOCK_FREE
#      elif UINT_LEAST64_MAX == UCHAR_MAX
#        define C11ATOMIC_UINT_LEAST64_T_LOCK_FREE C11ATOMIC_UCHAR_LOCK_FREE
#      endif
#    endif
#  endif
#  ifndef C11ATOMIC_UINT_LEAST64_T_LOCK_FREE
#    define C11ATOMIC_UINT_LEAST64_T_LOCK_FREE 1
#  endif
#  define C11ATOMIC_INT_FAST8_T int_fast8_t
#  ifdef _C11ATOMIC_LIMITS_H
#    ifdef INT_FAST8_MAX // <stdint.h>
#      if INT_FAST8_MAX == LLONG_MAX
#        define C11ATOMIC_INT_FAST8_T_LOCK_FREE C11ATOMIC_LLONG_LOCK_FREE
#      elif INT_FAST8_MAX == LONG_MAX
#        define C11ATOMIC_INT_FAST8_T_LOCK_FREE C11ATOMIC_LONG_LOCK_FREE
#      elif INT_FAST8_MAX == INT_MAX
#        define C11ATOMIC_INT_FAST8_T_LOCK_FREE C11ATOMIC_INT_LOCK_FREE
#      elif INT_FAST8_MAX == SHRT_MAX
#        define C11ATOMIC_INT_FAST8_T_LOCK_FREE C11ATOMIC_SHORT_LOCK_FREE
#      elif INT_FAST8_MAX == SCHAR_MAX
#        define C11ATOMIC_INT_FAST8_T_LOCK_FREE C11ATOMIC_SCHAR_LOCK_FREE
#      endif
#    endif
#  endif
#  ifndef C11ATOMIC_INT_FAST8_T_LOCK_FREE
#    define C11ATOMIC_INT_FAST8_T_LOCK_FREE 1
#  endif
#  define C11ATOMIC_UINT_FAST8_T uint_fast8_t
#  ifdef _C11ATOMIC_LIMITS_H
#    ifdef UINT_FAST8_MAX // <stdint.h>
#      if UINT_FAST8_MAX == ULLONG_MAX
#        define C11ATOMIC_UINT_FAST8_T_LOCK_FREE C11ATOMIC_ULLONG_LOCK_FREE
#      elif UINT_FAST8_MAX == ULONG_MAX
#        define C11ATOMIC_UINT_FAST8_T_LOCK_FREE C11ATOMIC_ULONG_LOCK_FREE
#      elif UINT_FAST8_MAX == UINT_MAX
#        define C11ATOMIC_UINT_FAST8_T_LOCK_FREE C11ATOMIC_UINT_LOCK_FREE
#      elif UINT_FAST8_MAX == USHRT_MAX
#        define C11ATOMIC_UINT_FAST8_T_LOCK_FREE C11ATOMIC_USHORT_LOCK_FREE
#      elif UINT_FAST8_MAX == UCHAR_MAX
#        define C11ATOMIC_UINT_FAST8_T_LOCK_FREE C11ATOMIC_UCHAR_LOCK_FREE
#      endif
#    endif
#  endif
#  ifndef C11ATOMIC_UINT_FAST8_T_LOCK_FREE
#    define C11ATOMIC_UINT_FAST8_T_LOCK_FREE 1
#  endif
#  define C11ATOMIC_INT_FAST16_T int_fast16_t
#  ifdef _C11ATOMIC_LIMITS_H
#    ifdef INT_FAST16_MAX // <stdint.h>
#      if INT_FAST16_MAX == LLONG_MAX
#        define C11ATOMIC_INT_FAST16_T_LOCK_FREE C11ATOMIC_LLONG_LOCK_FREE
#      elif INT_FAST16_MAX == LONG_MAX
#        define C11ATOMIC_INT_FAST16_T_LOCK_FREE C11ATOMIC_LONG_LOCK_FREE
#      elif INT_FAST16_MAX == INT_MAX
#        define C11ATOMIC_INT_FAST16_T_LOCK_FREE C11ATOMIC_INT_LOCK_FREE
#      elif INT_FAST16_MAX == SHRT_MAX
#        define C11ATOMIC_INT_FAST16_T_LOCK_FREE C11ATOMIC_SHORT_LOCK_FREE
#      elif INT_FAST16_MAX == SCHAR_MAX
#        define C11ATOMIC_INT_FAST16_T_LOCK_FREE C11ATOMIC_SCHAR_LOCK_FREE
#      endif
#    endif
#  endif
#  ifndef C11ATOMIC_INT_FAST16_T_LOCK_FREE
#    define C11ATOMIC_INT_FAST16_T_LOCK_FREE 1
#  endif
#  define C11ATOMIC_UINT_FAST16_T uint_fast16_t
#  ifdef _C11ATOMIC_LIMITS_H
#    ifdef UINT_FAST16_MAX // <stdint.h>
#      if UINT_FAST16_MAX == ULLONG_MAX
#        define C11ATOMIC_UINT_FAST16_T_LOCK_FREE C11ATOMIC_ULLONG_LOCK_FREE
#      elif UINT_FAST16_MAX == ULONG_MAX
#        define C11ATOMIC_UINT_FAST16_T_LOCK_FREE C11ATOMIC_ULONG_LOCK_FREE
#      elif UINT_FAST16_MAX == UINT_MAX
#        define C11ATOMIC_UINT_FAST16_T_LOCK_FREE C11ATOMIC_UINT_LOCK_FREE
#      elif UINT_FAST16_MAX == USHRT_MAX
#        define C11ATOMIC_UINT_FAST16_T_LOCK_FREE C11ATOMIC_USHORT_LOCK_FREE
#      elif UINT_FAST16_MAX == UCHAR_MAX
#        define C11ATOMIC_UINT_FAST16_T_LOCK_FREE C11ATOMIC_UCHAR_LOCK_FREE
#      endif
#    endif
#  endif
#  ifndef C11ATOMIC_UINT_FAST16_T_LOCK_FREE
#    define C11ATOMIC_UINT_FAST16_T_LOCK_FREE 1
#  endif
#  define C11ATOMIC_INT_FAST32_T int_fast32_t
#  ifdef _C11ATOMIC_LIMITS_H
#    ifdef INT_FAST32_MAX // <stdint.h>
#      if INT_FAST32_MAX == LLONG_MAX
#        define C11ATOMIC_INT_FAST32_T_LOCK_FREE C11ATOMIC_LLONG_LOCK_FREE
#      elif INT_FAST32_MAX == LONG_MAX
#        define C11ATOMIC_INT_FAST32_T_LOCK_FREE C11ATOMIC_LONG_LOCK_FREE
#      elif INT_FAST32_MAX == INT_MAX
#        define C11ATOMIC_INT_FAST32_T_LOCK_FREE C11ATOMIC_INT_LOCK_FREE
#      elif INT_FAST32_MAX == SHRT_MAX
#        define C11ATOMIC_INT_FAST32_T_LOCK_FREE C11ATOMIC_SHORT_LOCK_FREE
#      elif INT_FAST32_MAX == SCHAR_MAX
#        define C11ATOMIC_INT_FAST32_T_LOCK_FREE C11ATOMIC_SCHAR_LOCK_FREE
#      endif
#    endif
#  endif
#  ifndef C11ATOMIC_INT_FAST32_T_LOCK_FREE
#    define C11ATOMIC_INT_FAST32_T_LOCK_FREE 1
#  endif
#  define C11ATOMIC_UINT_FAST32_T uint_fast32_t
#  ifdef _C11ATOMIC_LIMITS_H
#    ifdef UINT_FAST32_MAX // <stdint.h>
#      if UINT_FAST32_MAX == ULLONG_MAX
#        define C11ATOMIC_UINT_FAST32_T_LOCK_FREE C11ATOMIC_ULLONG_LOCK_FREE
#      elif UINT_FAST32_MAX == ULONG_MAX
#        define C11ATOMIC_UINT_FAST32_T_LOCK_FREE C11ATOMIC_ULONG_LOCK_FREE
#      elif UINT_FAST32_MAX == UINT_MAX
#        define C11ATOMIC_UINT_FAST32_T_LOCK_FREE C11ATOMIC_UINT_LOCK_FREE
#      elif UINT_FAST32_MAX == USHRT_MAX
#        define C11ATOMIC_UINT_FAST32_T_LOCK_FREE C11ATOMIC_USHORT_LOCK_FREE
#      elif UINT_FAST32_MAX == UCHAR_MAX
#        define C11ATOMIC_UINT_FAST32_T_LOCK_FREE C11ATOMIC_UCHAR_LOCK_FREE
#      endif
#    endif
#  endif
#  ifndef C11ATOMIC_UINT_FAST32_T_LOCK_FREE
#    define C11ATOMIC_UINT_FAST32_T_LOCK_FREE 1
#  endif
#  define C11ATOMIC_INT_FAST64_T int_fast64_t
#  ifdef _C11ATOMIC_LIMITS_H
#    ifdef INT_FAST64_MAX // <stdint.h>
#      if INT_FAST64_MAX == LLONG_MAX
#        define C11ATOMIC_INT_FAST64_T_LOCK_FREE C11ATOMIC_LLONG_LOCK_FREE
#      elif INT_FAST64_MAX == LONG_MAX
#        define C11ATOMIC_INT_FAST64_T_LOCK_FREE C11ATOMIC_LONG_LOCK_FREE
#      elif INT_FAST64_MAX == INT_MAX
#        define C11ATOMIC_INT_FAST64_T_LOCK_FREE C11ATOMIC_INT_LOCK_FREE
#      elif INT_FAST64_MAX == SHRT_MAX
#        define C11ATOMIC_INT_FAST64_T_LOCK_FREE C11ATOMIC_SHORT_LOCK_FREE
#      elif INT_FAST64_MAX == SCHAR_MAX
#        define C11ATOMIC_INT_FAST64_T_LOCK_FREE C11ATOMIC_SCHAR_LOCK_FREE
#      endif
#    endif
#  endif
#  ifndef C11ATOMIC_INT_FAST64_T_LOCK_FREE
#    define C11ATOMIC_INT_FAST64_T_LOCK_FREE 1
#  endif
#  define C11ATOMIC_UINT_FAST64_T uint_fast64_t
#  ifdef _C11ATOMIC_LIMITS_H
#    ifdef UINT_FAST64_MAX // <stdint.h>
#      if UINT_FAST64_MAX == ULLONG_MAX
#        define C11ATOMIC_UINT_FAST64_T_LOCK_FREE C11ATOMIC_ULLONG_LOCK_FREE
#      elif UINT_FAST64_MAX == ULONG_MAX
#        define C11ATOMIC_UINT_FAST64_T_LOCK_FREE C11ATOMIC_ULONG_LOCK_FREE
#      elif UINT_FAST64_MAX == UINT_MAX
#        define C11ATOMIC_UINT_FAST64_T_LOCK_FREE C11ATOMIC_UINT_LOCK_FREE
#      elif UINT_FAST64_MAX == USHRT_MAX
#        define C11ATOMIC_UINT_FAST64_T_LOCK_FREE C11ATOMIC_USHORT_LOCK_FREE
#      elif UINT_FAST64_MAX == UCHAR_MAX
#        define C11ATOMIC_UINT_FAST64_T_LOCK_FREE C11ATOMIC_UCHAR_LOCK_FREE
#      endif
#    endif
#  endif
#  ifndef C11ATOMIC_UINT_FAST64_T_LOCK_FREE
#    define C11ATOMIC_UINT_FAST64_T_LOCK_FREE 1
#  endif
#  define C11ATOMIC_INTMAX_T intmax_t
#  ifdef _C11ATOMIC_LIMITS_H
#    ifdef INTMAX_MAX // <stdint.h>
#      if INTMAX_MAX == LLONG_MAX
#        define C11ATOMIC_INTMAX_T_LOCK_FREE C11ATOMIC_LLONG_LOCK_FREE
#      endif
#    endif
#  endif
#  ifndef C11ATOMIC_INTMAX_T_LOCK_FREE
#    define C11ATOMIC_INTMAX_T_LOCK_FREE 1
#  endif
#  define C11ATOMIC_UINTMAX_T uintmax_t
#  ifdef _C11ATOMIC_LIMITS_H
#    ifdef UINTMAX_MAX // <stdint.h>
#      if UINTMAX_MAX == ULLONG_MAX
#        define C11ATOMIC_UINTMAX_T_LOCK_FREE C11ATOMIC_ULLONG_LOCK_FREE
#      endif
#    endif
#  endif
#  ifndef C11ATOMIC_UINTMAX_T_LOCK_FREE
#    define C11ATOMIC_UINTMAX_T_LOCK_FREE 1
#  endif
#  ifdef INTPTR_MAX // <stdint.h> (optional)
#    define C11ATOMIC_INTPTR_T intptr_t
#    ifdef _C11ATOMIC_LIMITS_H
#      if INTPTR_MAX == LLONG_MAX
#        define C11ATOMIC_INTPTR_T_LOCK_FREE C11ATOMIC_LLONG_LOCK_FREE
#      elif INTPTR_MAX == LONG_MAX
#        define C11ATOMIC_INTPTR_T_LOCK_FREE C11ATOMIC_LONG_LOCK_FREE
#      elif INTPTR_MAX == INT_MAX
#        define C11ATOMIC_INTPTR_T_LOCK_FREE C11ATOMIC_INT_LOCK_FREE
#      elif INTPTR_MAX == SHRT_MAX
#        define C11ATOMIC_INTPTR_T_LOCK_FREE C11ATOMIC_SHORT_LOCK_FREE
#      elif INTPTR_MAX == SCHAR_MAX
#        define C11ATOMIC_INTPTR_T_LOCK_FREE C11ATOMIC_SCHAR_LOCK_FREE
#      endif
#    endif
#    ifndef C11ATOMIC_INTPTR_T_LOCK_FREE
#      define C11ATOMIC_INTPTR_T_LOCK_FREE 1
#    endif
#  endif
#  ifdef UINTPTR_MAX // <stdint.h> (optional)
#    define C11ATOMIC_UINTPTR_T uintptr_t
#    ifdef _C11ATOMIC_LIMITS_H
#      if UINTPTR_MAX == ULLONG_MAX
#        define C11ATOMIC_UINTPTR_T_LOCK_FREE C11ATOMIC_ULLONG_LOCK_FREE
#      elif UINTPTR_MAX == ULONG_MAX
#        define C11ATOMIC_UINTPTR_T_LOCK_FREE C11ATOMIC_ULONG_LOCK_FREE
#      elif UINTPTR_MAX == UINT_MAX
#        define C11ATOMIC_UINTPTR_T_LOCK_FREE C11ATOMIC_UINT_LOCK_FREE
#      elif UINTPTR_MAX == USHRT_MAX
#        define C11ATOMIC_UINTPTR_T_LOCK_FREE C11ATOMIC_USHORT_LOCK_FREE
#      elif UINTPTR_MAX == UCHAR_MAX
#        define C11ATOMIC_UINTPTR_T_LOCK_FREE C11ATOMIC_UCHAR_LOCK_FREE
#      endif
#    endif
#    ifndef C11ATOMIC_UINTPTR_T_LOCK_FREE
#      define C11ATOMIC_UINTPTR_T_LOCK_FREE 1
#    endif
#  endif
#endif
#ifdef _C11ATOMIC_STDDEF_H
#  define C11ATOMIC_SIZE_T size_t
#  ifdef _C11ATOMIC_LIMITS_H
#    ifdef SIZE_MAX // <stdint.h>
#      if SIZE_MAX == ULLONG_MAX
#        define C11ATOMIC_SIZE_T_LOCK_FREE C11ATOMIC_ULLONG_LOCK_FREE
#      elif SIZE_MAX == ULONG_MAX
#        define C11ATOMIC_SIZE_T_LOCK_FREE C11ATOMIC_ULONG_LOCK_FREE
#      elif SIZE_MAX == UINT_MAX
#        define C11ATOMIC_SIZE_T_LOCK_FREE C11ATOMIC_UINT_LOCK_FREE
#      elif SIZE_MAX == USHRT_MAX
#        define C11ATOMIC_SIZE_T_LOCK_FREE C11ATOMIC_USHORT_LOCK_FREE
#      elif SIZE_MAX == UCHAR_MAX
#        define C11ATOMIC_SIZE_T_LOCK_FREE C11ATOMIC_UCHAR_LOCK_FREE
#      endif
#    endif
#  endif
#  ifndef C11ATOMIC_SIZE_T_LOCK_FREE
#    define C11ATOMIC_SIZE_T_LOCK_FREE 1
#  endif
#  define C11ATOMIC_PTRDIFF_T ptrdiff_t
#  ifdef _C11ATOMIC_LIMITS_H
#    ifdef PTRDIFF_MAX // <stdint.h>
#      if PTRDIFF_MAX == LLONG_MAX
#        define C11ATOMIC_PTRDIFF_T_LOCK_FREE C11ATOMIC_LLONG_LOCK_FREE
#      elif PTRDIFF_MAX == LONG_MAX
#        define C11ATOMIC_PTRDIFF_T_LOCK_FREE C11ATOMIC_LONG_LOCK_FREE
#      elif PTRDIFF_MAX == INT_MAX
#        define C11ATOMIC_PTRDIFF_T_LOCK_FREE C11ATOMIC_INT_LOCK_FREE
#      elif PTRDIFF_MAX == SHRT_MAX
#        define C11ATOMIC_PTRDIFF_T_LOCK_FREE C11ATOMIC_SHORT_LOCK_FREE
#      elif PTRDIFF_MAX == SCHAR_MAX
#        define C11ATOMIC_PTRDIFF_T_LOCK_FREE C11ATOMIC_SCHAR_LOCK_FREE
#      endif
#    endif
#  endif
#  ifndef C11ATOMIC_PTRDIFF_T_LOCK_FREE
#    define C11ATOMIC_PTRDIFF_T_LOCK_FREE 1
#  endif
#endif
#define _C11ATOMIC_NA // to avoid C4003 (MSVC)
#define _C11ATOMIC_VA(expr) expr // https://stackoverflow.com/a/5134656 (MSVC)
#define _C11ATOMIC_FIRST_HELPER(first, ...) first // `...`: at least one (C99)
#define _C11ATOMIC_FIRST(...)                                                 \
_C11ATOMIC_VA(                                                                \
    _C11ATOMIC_FIRST_HELPER(__VA_ARGS__, _C11ATOMIC_NA)                       \
)
#ifdef C11ATOMIC_CPP
#  define _C11ATOMIC_FUNDAMENTAL_CALL(name, ...)                              \
_C11ATOMIC_VA((                                                               \
    name##_cpp(__VA_ARGS__)                                                   \
))
#else
#  define _C11ATOMIC_FUNDAMENTAL_CALL(name, ...)                              \
_C11ATOMIC_VA((                                                               \
    _Generic(_C11ATOMIC_FIRST(__VA_ARGS__),                                   \
        volatile c11atomic_vt(C11ATOMIC_POINTER) *: name##_v_pointer,         \
        volatile c11atomic_vt(C11ATOMIC_BOOL) *:    name##_v_bool,            \
        volatile c11atomic_vt(C11ATOMIC_CHAR) *:    name##_v_char,            \
        volatile c11atomic_vt(C11ATOMIC_SCHAR) *:   name##_v_schar,           \
        volatile c11atomic_vt(C11ATOMIC_UCHAR) *:   name##_v_uchar,           \
        volatile c11atomic_vt(C11ATOMIC_SHORT) *:   name##_v_short,           \
        volatile c11atomic_vt(C11ATOMIC_USHORT) *:  name##_v_ushort,          \
        volatile c11atomic_vt(C11ATOMIC_INT) *:     name##_v_int,             \
        volatile c11atomic_vt(C11ATOMIC_UINT) *:    name##_v_uint,            \
        volatile c11atomic_vt(C11ATOMIC_LONG) *:    name##_v_long,            \
        volatile c11atomic_vt(C11ATOMIC_ULONG) *:   name##_v_ulong,           \
        volatile c11atomic_vt(C11ATOMIC_LLONG) *:   name##_v_llong,           \
        volatile c11atomic_vt(C11ATOMIC_ULLONG) *:  name##_v_ullong,          \
        c11atomic_vt(C11ATOMIC_POINTER) *: name##_n_pointer,                  \
        c11atomic_vt(C11ATOMIC_BOOL) *:    name##_n_bool,                     \
        c11atomic_vt(C11ATOMIC_CHAR) *:    name##_n_char,                     \
        c11atomic_vt(C11ATOMIC_SCHAR) *:   name##_n_schar,                    \
        c11atomic_vt(C11ATOMIC_UCHAR) *:   name##_n_uchar,                    \
        c11atomic_vt(C11ATOMIC_SHORT) *:   name##_n_short,                    \
        c11atomic_vt(C11ATOMIC_USHORT) *:  name##_n_ushort,                   \
        c11atomic_vt(C11ATOMIC_INT) *:     name##_n_int,                      \
        c11atomic_vt(C11ATOMIC_UINT) *:    name##_n_uint,                     \
        c11atomic_vt(C11ATOMIC_LONG) *:    name##_n_long,                     \
        c11atomic_vt(C11ATOMIC_ULONG) *:   name##_n_ulong,                    \
        c11atomic_vt(C11ATOMIC_LLONG) *:   name##_n_llong,                    \
        c11atomic_vt(C11ATOMIC_ULLONG) *:  name##_n_ullong                    \
    )(__VA_ARGS__)                                                            \
))
#endif
#ifdef C11ATOMIC_CPP
#  define _C11ATOMIC_FUNDAMENTAL_CALL_CONST(name, ...)                        \
_C11ATOMIC_VA((                                                               \
    name##_cpp(__VA_ARGS__)                                                   \
))
#else
#  define _C11ATOMIC_FUNDAMENTAL_CALL_CONST(name, ...)                        \
_C11ATOMIC_VA((                                                               \
    _Generic(_C11ATOMIC_FIRST(__VA_ARGS__),                                   \
        const volatile c11atomic_vt(C11ATOMIC_POINTER) *: name##_v_pointer,   \
        const volatile c11atomic_vt(C11ATOMIC_BOOL) *:    name##_v_bool,      \
        const volatile c11atomic_vt(C11ATOMIC_CHAR) *:    name##_v_char,      \
        const volatile c11atomic_vt(C11ATOMIC_SCHAR) *:   name##_v_schar,     \
        const volatile c11atomic_vt(C11ATOMIC_UCHAR) *:   name##_v_uchar,     \
        const volatile c11atomic_vt(C11ATOMIC_SHORT) *:   name##_v_short,     \
        const volatile c11atomic_vt(C11ATOMIC_USHORT) *:  name##_v_ushort,    \
        const volatile c11atomic_vt(C11ATOMIC_INT) *:     name##_v_int,       \
        const volatile c11atomic_vt(C11ATOMIC_UINT) *:    name##_v_uint,      \
        const volatile c11atomic_vt(C11ATOMIC_LONG) *:    name##_v_long,      \
        const volatile c11atomic_vt(C11ATOMIC_ULONG) *:   name##_v_ulong,     \
        const volatile c11atomic_vt(C11ATOMIC_LLONG) *:   name##_v_llong,     \
        const volatile c11atomic_vt(C11ATOMIC_ULLONG) *:  name##_v_ullong,    \
        const c11atomic_vt(C11ATOMIC_POINTER) *: name##_n_pointer,            \
        const c11atomic_vt(C11ATOMIC_BOOL) *:    name##_n_bool,               \
        const c11atomic_vt(C11ATOMIC_CHAR) *:    name##_n_char,               \
        const c11atomic_vt(C11ATOMIC_SCHAR) *:   name##_n_schar,              \
        const c11atomic_vt(C11ATOMIC_UCHAR) *:   name##_n_uchar,              \
        const c11atomic_vt(C11ATOMIC_SHORT) *:   name##_n_short,              \
        const c11atomic_vt(C11ATOMIC_USHORT) *:  name##_n_ushort,             \
        const c11atomic_vt(C11ATOMIC_INT) *:     name##_n_int,                \
        const c11atomic_vt(C11ATOMIC_UINT) *:    name##_n_uint,               \
        const c11atomic_vt(C11ATOMIC_LONG) *:    name##_n_long,               \
        const c11atomic_vt(C11ATOMIC_ULONG) *:   name##_n_ulong,              \
        const c11atomic_vt(C11ATOMIC_LLONG) *:   name##_n_llong,              \
        const c11atomic_vt(C11ATOMIC_ULLONG) *:  name##_n_ullong,             \
        volatile c11atomic_vt(C11ATOMIC_POINTER) *: name##_v_pointer,         \
        volatile c11atomic_vt(C11ATOMIC_BOOL) *:    name##_v_bool,            \
        volatile c11atomic_vt(C11ATOMIC_CHAR) *:    name##_v_char,            \
        volatile c11atomic_vt(C11ATOMIC_SCHAR) *:   name##_v_schar,           \
        volatile c11atomic_vt(C11ATOMIC_UCHAR) *:   name##_v_uchar,           \
        volatile c11atomic_vt(C11ATOMIC_SHORT) *:   name##_v_short,           \
        volatile c11atomic_vt(C11ATOMIC_USHORT) *:  name##_v_ushort,          \
        volatile c11atomic_vt(C11ATOMIC_INT) *:     name##_v_int,             \
        volatile c11atomic_vt(C11ATOMIC_UINT) *:    name##_v_uint,            \
        volatile c11atomic_vt(C11ATOMIC_LONG) *:    name##_v_long,            \
        volatile c11atomic_vt(C11ATOMIC_ULONG) *:   name##_v_ulong,           \
        volatile c11atomic_vt(C11ATOMIC_LLONG) *:   name##_v_llong,           \
        volatile c11atomic_vt(C11ATOMIC_ULLONG) *:  name##_v_ullong,          \
        c11atomic_vt(C11ATOMIC_POINTER) *: name##_n_pointer,                  \
        c11atomic_vt(C11ATOMIC_BOOL) *:    name##_n_bool,                     \
        c11atomic_vt(C11ATOMIC_CHAR) *:    name##_n_char,                     \
        c11atomic_vt(C11ATOMIC_SCHAR) *:   name##_n_schar,                    \
        c11atomic_vt(C11ATOMIC_UCHAR) *:   name##_n_uchar,                    \
        c11atomic_vt(C11ATOMIC_SHORT) *:   name##_n_short,                    \
        c11atomic_vt(C11ATOMIC_USHORT) *:  name##_n_ushort,                   \
        c11atomic_vt(C11ATOMIC_INT) *:     name##_n_int,                      \
        c11atomic_vt(C11ATOMIC_UINT) *:    name##_n_uint,                     \
        c11atomic_vt(C11ATOMIC_LONG) *:    name##_n_long,                     \
        c11atomic_vt(C11ATOMIC_ULONG) *:   name##_n_ulong,                    \
        c11atomic_vt(C11ATOMIC_LLONG) *:   name##_n_llong,                    \
        c11atomic_vt(C11ATOMIC_ULLONG) *:  name##_n_ullong                    \
    )(__VA_ARGS__)                                                            \
))
#endif
#ifdef C11ATOMIC_CPP
#  define _C11ATOMIC_FUNDAMENTAL_DEF1(name)                                   \
    name##_impl(volatile, _cpp, C11ATOMIC_POINTER)                            \
    name##_impl(volatile, _cpp, C11ATOMIC_BOOL)                               \
    name##_impl(volatile, _cpp, C11ATOMIC_CHAR)                               \
    name##_impl(volatile, _cpp, C11ATOMIC_SCHAR)                              \
    name##_impl(volatile, _cpp, C11ATOMIC_UCHAR)                              \
    name##_impl(volatile, _cpp, C11ATOMIC_SHORT)                              \
    name##_impl(volatile, _cpp, C11ATOMIC_USHORT)                             \
    name##_impl(volatile, _cpp, C11ATOMIC_INT)                                \
    name##_impl(volatile, _cpp, C11ATOMIC_UINT)                               \
    name##_impl(volatile, _cpp, C11ATOMIC_LONG)                               \
    name##_impl(volatile, _cpp, C11ATOMIC_ULONG)                              \
    name##_impl(volatile, _cpp, C11ATOMIC_LLONG)                              \
    name##_impl(volatile, _cpp, C11ATOMIC_ULLONG)                             \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_POINTER)                       \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_BOOL)                          \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_CHAR)                          \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_SCHAR)                         \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_UCHAR)                         \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_SHORT)                         \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_USHORT)                        \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_INT)                           \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_UINT)                          \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_LONG)                          \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_ULONG)                         \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_LLONG)                         \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_ULLONG)
#else
#  define _C11ATOMIC_FUNDAMENTAL_DEF1(name)                                   \
    name##_impl(volatile, _v_pointer, C11ATOMIC_POINTER)                      \
    name##_impl(volatile, _v_bool,    C11ATOMIC_BOOL)                         \
    name##_impl(volatile, _v_char,    C11ATOMIC_CHAR)                         \
    name##_impl(volatile, _v_schar,   C11ATOMIC_SCHAR)                        \
    name##_impl(volatile, _v_uchar,   C11ATOMIC_UCHAR)                        \
    name##_impl(volatile, _v_short,   C11ATOMIC_SHORT)                        \
    name##_impl(volatile, _v_ushort,  C11ATOMIC_USHORT)                       \
    name##_impl(volatile, _v_int,     C11ATOMIC_INT)                          \
    name##_impl(volatile, _v_uint,    C11ATOMIC_UINT)                         \
    name##_impl(volatile, _v_long,    C11ATOMIC_LONG)                         \
    name##_impl(volatile, _v_ulong,   C11ATOMIC_ULONG)                        \
    name##_impl(volatile, _v_llong,   C11ATOMIC_LLONG)                        \
    name##_impl(volatile, _v_ullong,  C11ATOMIC_ULLONG)                       \
    name##_impl(_C11ATOMIC_NA, _n_pointer, C11ATOMIC_POINTER)                 \
    name##_impl(_C11ATOMIC_NA, _n_bool,    C11ATOMIC_BOOL)                    \
    name##_impl(_C11ATOMIC_NA, _n_char,    C11ATOMIC_CHAR)                    \
    name##_impl(_C11ATOMIC_NA, _n_schar,   C11ATOMIC_SCHAR)                   \
    name##_impl(_C11ATOMIC_NA, _n_uchar,   C11ATOMIC_UCHAR)                   \
    name##_impl(_C11ATOMIC_NA, _n_short,   C11ATOMIC_SHORT)                   \
    name##_impl(_C11ATOMIC_NA, _n_ushort,  C11ATOMIC_USHORT)                  \
    name##_impl(_C11ATOMIC_NA, _n_int,     C11ATOMIC_INT)                     \
    name##_impl(_C11ATOMIC_NA, _n_uint,    C11ATOMIC_UINT)                    \
    name##_impl(_C11ATOMIC_NA, _n_long,    C11ATOMIC_LONG)                    \
    name##_impl(_C11ATOMIC_NA, _n_ulong,   C11ATOMIC_ULONG)                   \
    name##_impl(_C11ATOMIC_NA, _n_llong,   C11ATOMIC_LLONG)                   \
    name##_impl(_C11ATOMIC_NA, _n_ullong,  C11ATOMIC_ULLONG)
#endif
#ifdef C11ATOMIC_CPP
#  define _C11ATOMIC_INTEGRAL_CALL(name, ...)                                 \
_C11ATOMIC_VA((                                                               \
    name##_cpp(__VA_ARGS__)                                                   \
))
#else
#  define _C11ATOMIC_INTEGRAL_CALL(name, ...)                                 \
_C11ATOMIC_VA((                                                               \
    _Generic(_C11ATOMIC_FIRST(__VA_ARGS__),                                   \
        volatile c11atomic_vt(C11ATOMIC_CHAR) *:   name##_v_char,             \
        volatile c11atomic_vt(C11ATOMIC_SCHAR) *:  name##_v_schar,            \
        volatile c11atomic_vt(C11ATOMIC_UCHAR) *:  name##_v_uchar,            \
        volatile c11atomic_vt(C11ATOMIC_SHORT) *:  name##_v_short,            \
        volatile c11atomic_vt(C11ATOMIC_USHORT) *: name##_v_ushort,           \
        volatile c11atomic_vt(C11ATOMIC_INT) *:    name##_v_int,              \
        volatile c11atomic_vt(C11ATOMIC_UINT) *:   name##_v_uint,             \
        volatile c11atomic_vt(C11ATOMIC_LONG) *:   name##_v_long,             \
        volatile c11atomic_vt(C11ATOMIC_ULONG) *:  name##_v_ulong,            \
        volatile c11atomic_vt(C11ATOMIC_LLONG) *:  name##_v_llong,            \
        volatile c11atomic_vt(C11ATOMIC_ULLONG) *: name##_v_ullong,           \
        c11atomic_vt(C11ATOMIC_CHAR) *:   name##_n_char,                      \
        c11atomic_vt(C11ATOMIC_SCHAR) *:  name##_n_schar,                     \
        c11atomic_vt(C11ATOMIC_UCHAR) *:  name##_n_uchar,                     \
        c11atomic_vt(C11ATOMIC_SHORT) *:  name##_n_short,                     \
        c11atomic_vt(C11ATOMIC_USHORT) *: name##_n_ushort,                    \
        c11atomic_vt(C11ATOMIC_INT) *:    name##_n_int,                       \
        c11atomic_vt(C11ATOMIC_UINT) *:   name##_n_uint,                      \
        c11atomic_vt(C11ATOMIC_LONG) *:   name##_n_long,                      \
        c11atomic_vt(C11ATOMIC_ULONG) *:  name##_n_ulong,                     \
        c11atomic_vt(C11ATOMIC_LLONG) *:  name##_n_llong,                     \
        c11atomic_vt(C11ATOMIC_ULLONG) *: name##_n_ullong                     \
    )(__VA_ARGS__)                                                            \
))
#endif
#ifdef C11ATOMIC_CPP
#  define _C11ATOMIC_INTEGRAL_CALL_CONST(name, ...)                           \
_C11ATOMIC_VA((                                                               \
    name##_cpp(__VA_ARGS__)                                                   \
))
#else
#  define _C11ATOMIC_INTEGRAL_CALL_CONST(name, ...)                           \
_C11ATOMIC_VA((                                                               \
    _Generic(_C11ATOMIC_FIRST(__VA_ARGS__),                                   \
        const volatile c11atomic_vt(C11ATOMIC_CHAR) *:   name##_v_char,       \
        const volatile c11atomic_vt(C11ATOMIC_SCHAR) *:  name##_v_schar,      \
        const volatile c11atomic_vt(C11ATOMIC_UCHAR) *:  name##_v_uchar,      \
        const volatile c11atomic_vt(C11ATOMIC_SHORT) *:  name##_v_short,      \
        const volatile c11atomic_vt(C11ATOMIC_USHORT) *: name##_v_ushort,     \
        const volatile c11atomic_vt(C11ATOMIC_INT) *:    name##_v_int,        \
        const volatile c11atomic_vt(C11ATOMIC_UINT) *:   name##_v_uint,       \
        const volatile c11atomic_vt(C11ATOMIC_LONG) *:   name##_v_long,       \
        const volatile c11atomic_vt(C11ATOMIC_ULONG) *:  name##_v_ulong,      \
        const volatile c11atomic_vt(C11ATOMIC_LLONG) *:  name##_v_llong,      \
        const volatile c11atomic_vt(C11ATOMIC_ULLONG) *: name##_v_ullong,     \
        const c11atomic_vt(C11ATOMIC_CHAR) *:   name##_n_char,                \
        const c11atomic_vt(C11ATOMIC_SCHAR) *:  name##_n_schar,               \
        const c11atomic_vt(C11ATOMIC_UCHAR) *:  name##_n_uchar,               \
        const c11atomic_vt(C11ATOMIC_SHORT) *:  name##_n_short,               \
        const c11atomic_vt(C11ATOMIC_USHORT) *: name##_n_ushort,              \
        const c11atomic_vt(C11ATOMIC_INT) *:    name##_n_int,                 \
        const c11atomic_vt(C11ATOMIC_UINT) *:   name##_n_uint,                \
        const c11atomic_vt(C11ATOMIC_LONG) *:   name##_n_long,                \
        const c11atomic_vt(C11ATOMIC_ULONG) *:  name##_n_ulong,               \
        const c11atomic_vt(C11ATOMIC_LLONG) *:  name##_n_llong,               \
        const c11atomic_vt(C11ATOMIC_ULLONG) *: name##_n_ullong,              \
        volatile c11atomic_vt(C11ATOMIC_CHAR) *:   name##_v_char,             \
        volatile c11atomic_vt(C11ATOMIC_SCHAR) *:  name##_v_schar,            \
        volatile c11atomic_vt(C11ATOMIC_UCHAR) *:  name##_v_uchar,            \
        volatile c11atomic_vt(C11ATOMIC_SHORT) *:  name##_v_short,            \
        volatile c11atomic_vt(C11ATOMIC_USHORT) *: name##_v_ushort,           \
        volatile c11atomic_vt(C11ATOMIC_INT) *:    name##_v_int,              \
        volatile c11atomic_vt(C11ATOMIC_UINT) *:   name##_v_uint,             \
        volatile c11atomic_vt(C11ATOMIC_LONG) *:   name##_v_long,             \
        volatile c11atomic_vt(C11ATOMIC_ULONG) *:  name##_v_ulong,            \
        volatile c11atomic_vt(C11ATOMIC_LLONG) *:  name##_v_llong,            \
        volatile c11atomic_vt(C11ATOMIC_ULLONG) *: name##_v_ullong,           \
        c11atomic_vt(C11ATOMIC_CHAR) *:   name##_n_char,                      \
        c11atomic_vt(C11ATOMIC_SCHAR) *:  name##_n_schar,                     \
        c11atomic_vt(C11ATOMIC_UCHAR) *:  name##_n_uchar,                     \
        c11atomic_vt(C11ATOMIC_SHORT) *:  name##_n_short,                     \
        c11atomic_vt(C11ATOMIC_USHORT) *: name##_n_ushort,                    \
        c11atomic_vt(C11ATOMIC_INT) *:    name##_n_int,                       \
        c11atomic_vt(C11ATOMIC_UINT) *:   name##_n_uint,                      \
        c11atomic_vt(C11ATOMIC_LONG) *:   name##_n_long,                      \
        c11atomic_vt(C11ATOMIC_ULONG) *:  name##_n_ulong,                     \
        c11atomic_vt(C11ATOMIC_LLONG) *:  name##_n_llong,                     \
        c11atomic_vt(C11ATOMIC_ULLONG) *: name##_n_ullong                     \
    )(__VA_ARGS__)                                                            \
))
#endif
#ifdef C11ATOMIC_CPP
#  define _C11ATOMIC_INTEGRAL_DEF1(name)                                      \
    name##_impl(volatile, _cpp, C11ATOMIC_CHAR)                               \
    name##_impl(volatile, _cpp, C11ATOMIC_SCHAR)                              \
    name##_impl(volatile, _cpp, C11ATOMIC_UCHAR)                              \
    name##_impl(volatile, _cpp, C11ATOMIC_SHORT)                              \
    name##_impl(volatile, _cpp, C11ATOMIC_USHORT)                             \
    name##_impl(volatile, _cpp, C11ATOMIC_INT)                                \
    name##_impl(volatile, _cpp, C11ATOMIC_UINT)                               \
    name##_impl(volatile, _cpp, C11ATOMIC_LONG)                               \
    name##_impl(volatile, _cpp, C11ATOMIC_ULONG)                              \
    name##_impl(volatile, _cpp, C11ATOMIC_LLONG)                              \
    name##_impl(volatile, _cpp, C11ATOMIC_ULLONG)                             \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_CHAR)                          \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_SCHAR)                         \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_UCHAR)                         \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_SHORT)                         \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_USHORT)                        \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_INT)                           \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_UINT)                          \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_LONG)                          \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_ULONG)                         \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_LLONG)                         \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_ULLONG)
#else
#  define _C11ATOMIC_INTEGRAL_DEF1(name)                                      \
    name##_impl(volatile, _v_char,   C11ATOMIC_CHAR)                          \
    name##_impl(volatile, _v_schar,  C11ATOMIC_SCHAR)                         \
    name##_impl(volatile, _v_uchar,  C11ATOMIC_UCHAR)                         \
    name##_impl(volatile, _v_short,  C11ATOMIC_SHORT)                         \
    name##_impl(volatile, _v_ushort, C11ATOMIC_USHORT)                        \
    name##_impl(volatile, _v_int,    C11ATOMIC_INT)                           \
    name##_impl(volatile, _v_uint,   C11ATOMIC_UINT)                          \
    name##_impl(volatile, _v_long,   C11ATOMIC_LONG)                          \
    name##_impl(volatile, _v_ulong,  C11ATOMIC_ULONG)                         \
    name##_impl(volatile, _v_llong,  C11ATOMIC_LLONG)                         \
    name##_impl(volatile, _v_ullong, C11ATOMIC_ULLONG)                        \
    name##_impl(_C11ATOMIC_NA, _n_char,   C11ATOMIC_CHAR)                     \
    name##_impl(_C11ATOMIC_NA, _n_schar,  C11ATOMIC_SCHAR)                    \
    name##_impl(_C11ATOMIC_NA, _n_uchar,  C11ATOMIC_UCHAR)                    \
    name##_impl(_C11ATOMIC_NA, _n_short,  C11ATOMIC_SHORT)                    \
    name##_impl(_C11ATOMIC_NA, _n_ushort, C11ATOMIC_USHORT)                   \
    name##_impl(_C11ATOMIC_NA, _n_int,    C11ATOMIC_INT)                      \
    name##_impl(_C11ATOMIC_NA, _n_uint,   C11ATOMIC_UINT)                     \
    name##_impl(_C11ATOMIC_NA, _n_long,   C11ATOMIC_LONG)                     \
    name##_impl(_C11ATOMIC_NA, _n_ulong,  C11ATOMIC_ULONG)                    \
    name##_impl(_C11ATOMIC_NA, _n_llong,  C11ATOMIC_LLONG)                    \
    name##_impl(_C11ATOMIC_NA, _n_ullong, C11ATOMIC_ULLONG)
#endif
#ifdef C11ATOMIC_CPP
#  define _C11ATOMIC_INTEGRAL_DEF2(name)                                      \
    name##_impl(volatile, _cpp, C11ATOMIC_CHAR,   C11ATOMIC_CHAR)             \
    name##_impl(volatile, _cpp, C11ATOMIC_SCHAR,  C11ATOMIC_SCHAR)            \
    name##_impl(volatile, _cpp, C11ATOMIC_UCHAR,  C11ATOMIC_UCHAR)            \
    name##_impl(volatile, _cpp, C11ATOMIC_SHORT,  C11ATOMIC_SHORT)            \
    name##_impl(volatile, _cpp, C11ATOMIC_USHORT, C11ATOMIC_USHORT)           \
    name##_impl(volatile, _cpp, C11ATOMIC_INT,    C11ATOMIC_INT)              \
    name##_impl(volatile, _cpp, C11ATOMIC_UINT,   C11ATOMIC_UINT)             \
    name##_impl(volatile, _cpp, C11ATOMIC_LONG,   C11ATOMIC_LONG)             \
    name##_impl(volatile, _cpp, C11ATOMIC_ULONG,  C11ATOMIC_ULONG)            \
    name##_impl(volatile, _cpp, C11ATOMIC_LLONG,  C11ATOMIC_LLONG)            \
    name##_impl(volatile, _cpp, C11ATOMIC_ULLONG, C11ATOMIC_ULLONG)           \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_CHAR,   C11ATOMIC_CHAR)        \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_SCHAR,  C11ATOMIC_SCHAR)       \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_UCHAR,  C11ATOMIC_UCHAR)       \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_SHORT,  C11ATOMIC_SHORT)       \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_USHORT, C11ATOMIC_USHORT)      \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_INT,    C11ATOMIC_INT)         \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_UINT,   C11ATOMIC_UINT)        \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_LONG,   C11ATOMIC_LONG)        \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_ULONG,  C11ATOMIC_ULONG)       \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_LLONG,  C11ATOMIC_LLONG)       \
    name##_impl(_C11ATOMIC_NA, _cpp, C11ATOMIC_ULLONG, C11ATOMIC_ULLONG)
#else
#  define _C11ATOMIC_INTEGRAL_DEF2(name)                                      \
    name##_impl(volatile, _v_char,   C11ATOMIC_CHAR,   C11ATOMIC_CHAR)        \
    name##_impl(volatile, _v_schar,  C11ATOMIC_SCHAR,  C11ATOMIC_SCHAR)       \
    name##_impl(volatile, _v_uchar,  C11ATOMIC_UCHAR,  C11ATOMIC_UCHAR)       \
    name##_impl(volatile, _v_short,  C11ATOMIC_SHORT,  C11ATOMIC_SHORT)       \
    name##_impl(volatile, _v_ushort, C11ATOMIC_USHORT, C11ATOMIC_USHORT)      \
    name##_impl(volatile, _v_int,    C11ATOMIC_INT,    C11ATOMIC_INT)         \
    name##_impl(volatile, _v_uint,   C11ATOMIC_UINT,   C11ATOMIC_UINT)        \
    name##_impl(volatile, _v_long,   C11ATOMIC_LONG,   C11ATOMIC_LONG)        \
    name##_impl(volatile, _v_ulong,  C11ATOMIC_ULONG,  C11ATOMIC_ULONG)       \
    name##_impl(volatile, _v_llong,  C11ATOMIC_LLONG,  C11ATOMIC_LLONG)       \
    name##_impl(volatile, _v_ullong, C11ATOMIC_ULLONG, C11ATOMIC_ULLONG)      \
    name##_impl(_C11ATOMIC_NA, _n_char,   C11ATOMIC_CHAR,   C11ATOMIC_CHAR)   \
    name##_impl(_C11ATOMIC_NA, _n_schar,  C11ATOMIC_SCHAR,  C11ATOMIC_SCHAR)  \
    name##_impl(_C11ATOMIC_NA, _n_uchar,  C11ATOMIC_UCHAR,  C11ATOMIC_UCHAR)  \
    name##_impl(_C11ATOMIC_NA, _n_short,  C11ATOMIC_SHORT,  C11ATOMIC_SHORT)  \
    name##_impl(_C11ATOMIC_NA, _n_ushort, C11ATOMIC_USHORT, C11ATOMIC_USHORT) \
    name##_impl(_C11ATOMIC_NA, _n_int,    C11ATOMIC_INT,    C11ATOMIC_INT)    \
    name##_impl(_C11ATOMIC_NA, _n_uint,   C11ATOMIC_UINT,   C11ATOMIC_UINT)   \
    name##_impl(_C11ATOMIC_NA, _n_long,   C11ATOMIC_LONG,   C11ATOMIC_LONG)   \
    name##_impl(_C11ATOMIC_NA, _n_ulong,  C11ATOMIC_ULONG,  C11ATOMIC_ULONG)  \
    name##_impl(_C11ATOMIC_NA, _n_llong,  C11ATOMIC_LLONG,  C11ATOMIC_LLONG)  \
    name##_impl(_C11ATOMIC_NA, _n_ullong, C11ATOMIC_ULLONG, C11ATOMIC_ULLONG)
#endif
#ifdef C11ATOMIC_CPP
#  define _C11ATOMIC_STD_CALL(name, ...)                                      \
_C11ATOMIC_VA((                                                               \
    std::name(__VA_ARGS__)                                                    \
))
#else
#  define _C11ATOMIC_STD_CALL(name, ...)                                      \
_C11ATOMIC_VA((                                                               \
    name(__VA_ARGS__)                                                         \
))
#endif
#ifdef C11ATOMIC_CPP
#  define _C11ATOMIC_NOEXCEPT noexcept
#else
#  define _C11ATOMIC_NOEXCEPT
#endif
#ifdef C11ATOMIC_CPP
template<class T>
struct _c11atomic {
    c11atomic_vt(T) _c11atomic_v;
    _c11atomic() noexcept = default;
    _c11atomic(const T desired) noexcept : _c11atomic_v(desired) {}
    _c11atomic(const _c11atomic&) = delete;
    _c11atomic& operator=(const _c11atomic&) = delete;
    _c11atomic& operator=(const _c11atomic&) volatile = delete;
};
#  define c11atomic(...)                                                      \
_C11ATOMIC_VA(                                                                \
    _c11atomic<__VA_ARGS__>                                                   \
)
#else
#  define c11atomic(...)                                                      \
_C11ATOMIC_VA(                                                                \
    struct { c11atomic_vt(__VA_ARGS__) _c11atomic_v; }                        \
)
#endif
#define C11ATOMIC_VAR_INIT(...) { __VA_ARGS__ }
typedef c11atomic(C11ATOMIC_POINTER) c11atomic_pointer;
typedef c11atomic(C11ATOMIC_BOOL) c11atomic_bool;
typedef c11atomic(C11ATOMIC_CHAR) c11atomic_char;
typedef c11atomic(C11ATOMIC_SCHAR) c11atomic_schar;
typedef c11atomic(C11ATOMIC_UCHAR) c11atomic_uchar;
typedef c11atomic(C11ATOMIC_SHORT) c11atomic_short;
typedef c11atomic(C11ATOMIC_USHORT) c11atomic_ushort;
typedef c11atomic(C11ATOMIC_INT) c11atomic_int;
typedef c11atomic(C11ATOMIC_UINT) c11atomic_uint;
typedef c11atomic(C11ATOMIC_LONG) c11atomic_long;
typedef c11atomic(C11ATOMIC_ULONG) c11atomic_ulong;
typedef c11atomic(C11ATOMIC_LLONG) c11atomic_llong;
typedef c11atomic(C11ATOMIC_ULLONG) c11atomic_ullong;
#ifdef C11ATOMIC_INT8_T
typedef c11atomic(C11ATOMIC_INT8_T) c11atomic_int8_t;
#endif
#ifdef C11ATOMIC_UINT8_T
typedef c11atomic(C11ATOMIC_UINT8_T) c11atomic_uint8_t;
#endif
#ifdef C11ATOMIC_INT16_T
typedef c11atomic(C11ATOMIC_INT16_T) c11atomic_int16_t;
#endif
#ifdef C11ATOMIC_UINT16_T
typedef c11atomic(C11ATOMIC_UINT16_T) c11atomic_uint16_t;
#endif
#ifdef C11ATOMIC_INT32_T
typedef c11atomic(C11ATOMIC_INT32_T) c11atomic_int32_t;
#endif
#ifdef C11ATOMIC_UINT32_T
typedef c11atomic(C11ATOMIC_UINT32_T) c11atomic_uint32_t;
#endif
#ifdef C11ATOMIC_INT64_T
typedef c11atomic(C11ATOMIC_INT64_T) c11atomic_int64_t;
#endif
#ifdef C11ATOMIC_UINT64_T
typedef c11atomic(C11ATOMIC_UINT64_T) c11atomic_uint64_t;
#endif
#ifdef C11ATOMIC_INT_LEAST8_T
typedef c11atomic(C11ATOMIC_INT_LEAST8_T) c11atomic_int_least8_t;
#endif
#ifdef C11ATOMIC_UINT_LEAST8_T
typedef c11atomic(C11ATOMIC_UINT_LEAST8_T) c11atomic_uint_least8_t;
#endif
#ifdef C11ATOMIC_INT_LEAST16_T
typedef c11atomic(C11ATOMIC_INT_LEAST16_T) c11atomic_int_least16_t;
#endif
#ifdef C11ATOMIC_UINT_LEAST16_T
typedef c11atomic(C11ATOMIC_UINT_LEAST16_T) c11atomic_uint_least16_t;
#endif
#ifdef C11ATOMIC_INT_LEAST32_T
typedef c11atomic(C11ATOMIC_INT_LEAST32_T) c11atomic_int_least32_t;
#endif
#ifdef C11ATOMIC_UINT_LEAST32_T
typedef c11atomic(C11ATOMIC_UINT_LEAST32_T) c11atomic_uint_least32_t;
#endif
#ifdef C11ATOMIC_INT_LEAST64_T
typedef c11atomic(C11ATOMIC_INT_LEAST64_T) c11atomic_int_least64_t;
#endif
#ifdef C11ATOMIC_UINT_LEAST64_T
typedef c11atomic(C11ATOMIC_UINT_LEAST64_T) c11atomic_uint_least64_t;
#endif
#ifdef C11ATOMIC_INT_FAST8_T
typedef c11atomic(C11ATOMIC_INT_FAST8_T) c11atomic_int_fast8_t;
#endif
#ifdef C11ATOMIC_UINT_FAST8_T
typedef c11atomic(C11ATOMIC_UINT_FAST8_T) c11atomic_uint_fast8_t;
#endif
#ifdef C11ATOMIC_INT_FAST16_T
typedef c11atomic(C11ATOMIC_INT_FAST16_T) c11atomic_int_fast16_t;
#endif
#ifdef C11ATOMIC_UINT_FAST16_T
typedef c11atomic(C11ATOMIC_UINT_FAST16_T) c11atomic_uint_fast16_t;
#endif
#ifdef C11ATOMIC_INT_FAST32_T
typedef c11atomic(C11ATOMIC_INT_FAST32_T) c11atomic_int_fast32_t;
#endif
#ifdef C11ATOMIC_UINT_FAST32_T
typedef c11atomic(C11ATOMIC_UINT_FAST32_T) c11atomic_uint_fast32_t;
#endif
#ifdef C11ATOMIC_INT_FAST64_T
typedef c11atomic(C11ATOMIC_INT_FAST64_T) c11atomic_int_fast64_t;
#endif
#ifdef C11ATOMIC_UINT_FAST64_T
typedef c11atomic(C11ATOMIC_UINT_FAST64_T) c11atomic_uint_fast64_t;
#endif
#ifdef C11ATOMIC_INTMAX_T
typedef c11atomic(C11ATOMIC_INTMAX_T) c11atomic_intmax_t;
#endif
#ifdef C11ATOMIC_UINTMAX_T
typedef c11atomic(C11ATOMIC_UINTMAX_T) c11atomic_uintmax_t;
#endif
#ifdef C11ATOMIC_INTPTR_T
typedef c11atomic(C11ATOMIC_INTPTR_T) c11atomic_intptr_t;
#endif
#ifdef C11ATOMIC_UINTPTR_T
typedef c11atomic(C11ATOMIC_UINTPTR_T) c11atomic_uintptr_t;
#endif
#ifdef C11ATOMIC_SIZE_T
typedef c11atomic(C11ATOMIC_SIZE_T) c11atomic_size_t;
#endif
#ifdef C11ATOMIC_PTRDIFF_T
typedef c11atomic(C11ATOMIC_PTRDIFF_T) c11atomic_ptrdiff_t;
#endif

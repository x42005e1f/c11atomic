/*
 * SPDX-FileCopyrightText: 2026 Ilya Egorov <0x42005e1f@gmail.com>
 * SPDX-License-Identifier: ISC
 */

#if defined(C11ATOMIC_CPP) || defined(C11ATOMIC_C) /* include guard */
#elif defined(__cplusplus) /* see `/Zc:__cplusplus` */
#  if defined(_MSC_VER) && defined(_MSVC_LANG) && __cplusplus == 199711L
#    if _MSC_VER >= 1929 && _MSVC_LANG >= 202002L /* VS 2019 16.10; C++20 */
#      define C11ATOMIC_CPP 202002L
#    elif _MSC_VER >= 1914 && _MSVC_LANG >= 201703L /* VS 2017 15.7; C++17 */
#      define C11ATOMIC_CPP 201703L
#    elif _MSC_VER >= 1910 && _MSVC_LANG >= 201402L /* VS 2017 15.0; C++14 */
#      define C11ATOMIC_CPP 201402L
#    elif _MSC_VER >= 1900 && _MSVC_LANG >= 201103L /* VS 2015 14.0; C++11 */
#      define C11ATOMIC_CPP 201103L
#    else
#      define C11ATOMIC_CPP 199711L
#    endif
#  else
#    define C11ATOMIC_CPP __cplusplus
#  endif
#elif defined(__STDC_VERSION__) || defined(__STDC__) /* see `/Zc:__STDC__` */
#  if defined(__STDC_VERSION__) /* C94/C95 */
#    define C11ATOMIC_C __STDC_VERSION__
#  else /* C89/C90 */
#    define C11ATOMIC_C 198912L
#  endif
#endif

/*
 * Note: By default, MSVC has non-standard-conforming behavior, so checking the
 * language version makes little sense unless we enforce certain compiler
 * options (see `/Zc` and `/permissive-`) or explicitly handle its specific
 * behavior (our choice). Moreover, the official "C/C++ language conformance"
 * sometimes lies, and you should use "C/C++ compiler support" from
 * cppreference.com as a more reliable source instead.
 *
 * The following features are ignored by the macros:
 *
 * - N1653 C99 preprocessor (C++11): VS 2019 16.6 (disabled by default)
 * - N2634 Expression SFINAE (C++11): VS 2017 15.7
 */

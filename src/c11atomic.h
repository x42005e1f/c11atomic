/*
 * SPDX-FileCopyrightText: 2026 Ilya Egorov <0x42005e1f@gmail.com>
 * SPDX-License-Identifier: ISC
 */

#ifndef C11ATOMIC_H
#define C11ATOMIC_H
#ifdef __cplusplus
extern "C++" {
#endif

#include "c11atomic_ver.h"
#if defined(C11ATOMIC_CPP) /* Standard C++ */
#  if C11ATOMIC_CPP >= 201103L /* C++11 */
#    include "c11atomic_inc.h"
#  endif
#elif defined(C11ATOMIC_C) /* Standard C */
#  if C11ATOMIC_C >= 201112L /* C11 */
#    include "c11atomic_inc.h"
#  endif
#endif

#ifdef __cplusplus
}
#endif
#endif /* C11ATOMIC_H */

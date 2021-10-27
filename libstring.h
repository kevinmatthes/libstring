/**
 * libstring.h : the main header of `libstring'.
 *
 * See `LICENSE' for full license.
 * See `README.md' for project details.
 */

/**
 * Copyright (C) 2021 Kevin Matthes
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/******************************************************************************/

/**
 * Security settings.
 */

#pragma once
#ifndef __LIBSTRING_H__
#define __LIBSTRING_H__



/**
 * Includes.
 */

#include <stdbool.h>
#include <stdlib.h>



/**
 * Macros.
 */

// The null pointer.  To use instead of `NULL'.
#ifndef nullptr
#define nullptr (void *) 0x0
#endif  // ! nullptr

// Name mangling macro.
#define NAME(identifier)    string_ ## identifier



/**
 * Type declarations.
 */

// Natural numbers.
#ifndef __TYPEDEF__NATURAL_T__
#define __TYPEDEF__NATURAL_T__
typedef unsigned long long int  natural_t;
#endif  // ! __TYPEDEF__NATURAL_T__

// Mutable strings.
#ifndef __TYPEDEF__STR_T__
#define __TYPEDEF__STR_T__
typedef char *  str_t;
#endif  // ! __TYPEDEF__STR_T__

// Immutable strings.
#ifndef __TYPEDEF__STRING_T__
#define __TYPEDEF__STRING_T__
typedef char * const    string_t;
#endif  // ! __TYPEDEF__STRING_T__



/**
 * Function declarations.
 */

// Parameter abbreviations.
#define OTHER   const string_t  other
#define SELF    const string_t  self

// The constructor.
extern  str_t       string          (const natural_t size);

// The methods.
extern  str_t       NAME (concat)   (SELF, OTHER);
extern  str_t       NAME (copy)     (SELF);
extern  bool        NAME (del)      (                     str_t     self);
extern  bool        NAME (eq)       (SELF, OTHER);
extern  str_t       NAME (join)     (SELF, OTHER,   const string_t  by);
extern  natural_t   NAME (len)      (SELF);
extern  str_t       NAME (lower)    (SELF);
extern  str_t       NAME (mul)      (SELF,          const natural_t times);
extern  str_t       NAME (upper)    (SELF);



/**
 * Constants.
 */

extern const int    NAME (latin_offset);



/**
 * End of header.
 */

// Tidying up.
#ifndef __LIBSTRING_INTERNAL__
#undef NAME
#undef OTHER
#undef SELF
#endif  // ! __LIBSTRING_INTERNAL__

// Leaving the header.
#endif  // ! __LIBSTRING_H__

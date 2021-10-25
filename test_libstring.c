/**
 * test_libstring.c : a set of tests for `libstring'.
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
 * Includes.
 */

#include <stdio.h>
#include "libstring.h"



/**
 * Function declarations of local auxillary functions.
 */

void    test_concat     (void);
void    test_constants  (void);
void    test_copy       (void);
void    test_eq         (void);
void    test_join       (void);
void    test_len        (void);
void    test_lower      (void);
void    test_mul        (void);
void    test_string     (void);
void    test_upper      (void);



/**
 * Local auxillary functions.
 */

void    test_concat (void)
{
    const string_t  test    = "Test";
    string_t        concat  = string_concat (test, test);

    printf ( "str_t string_concat (const string_t self, const string_t other):\n"
             "* Reference object: '%s' (%p), %lld char(s).\n"
             "* Expectation:      '%s%s', %lld char(s).\n"
             "* Result:           '%s' (%p), %lld char(s).\n\n"
           , test,   test,   string_len (test)
           , test,   test,   string_len (test) << 0x1
           , concat, concat, string_len (concat)
           );

    string_del (concat);

    return;
}

void    test_constants  (void)
{
    printf ( "Constants:\n"
             "* const int string_latin_offset: %d (0x%x).\n\n"
           , string_latin_offset, string_latin_offset
           );

    return;
}

void    test_copy   (void)
{
    const string_t  test    = "Test";
    string_t        copy    = string_copy (test);

    printf ( "str_t string_copy (const string_t self):\n"
             "* Reference object: '%s' (%p), %lld char(s).\n"
             "* Expectation:      '%s', %lld char(s).\n"
             "* Result:           '%s' (%p), %lld char(s).\n\n"
           , test, test, string_len (test)
           , test,       string_len (test)
           , copy, copy, string_len (copy)
           );

    string_del (copy);

    return;
}



/**
 * The main function.
 */

int main (void)
{
    test_concat     ();
    test_constants  ();
    test_copy       ();
    test_del        ();
    test_join       ();
    test_len        ();
    test_lower      ();
    test_string     ();
    test_upper      ();

    return 0x0;
}

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

void    license         (void);
void    test_concat     (void);
void    test_constants  (void);
void    test_contains   (void);
void    test_copy       (void);
void    test_crop       (void);
void    test_eq         (void);
void    test_join       (void);
void    test_len        (void);
void    test_lower      (void);
void    test_mul        (void);
void    test_upper      (void);



/**
 * Local auxillary functions.
 */

inline  void    license (void)
{
    printf ("Copyright (C) 2021 Kevin Matthes\n"
            "\n"
            "This program is free software; you can redistribute it and/or modify\n"
            "it under the terms of the GNU General Public License as published by\n"
            "the Free Software Foundation; either version 2 of the License, or\n"
            "(at your option) any later version.\n"
            "\n"
            "This program is distributed in the hope that it will be useful,\n"
            "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
            "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
            "GNU General Public License for more details.\n"
            "\n"
            "You should have received a copy of the GNU General Public License along\n"
            "with this program; if not, write to the Free Software Foundation, Inc.,\n"
            "51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.\n\n"
           );
    return;
}

void    test_concat (void)
{
    const string_t  expectation = "TestTest";
    const string_t  test        = "Test";
    string_t        concat      = string_concat (test, test);

    printf ( "str_t string_concat (const string_t self, const string_t other):\n"
             "* Reference object: '%s' (%p), %lld char(s).\n"
             "* Expectation:      '%s', %lld char(s).\n"
             "* Result:           '%s' (%p), %lld char(s).\n\n"
           , test,          test,           string_len (test)
           , expectation,                   string_len (expectation)
           , concat,        concat,         string_len (concat)
           );

    string_del (concat);

    return;
}

void    test_constants  (void)
{
    printf ( "Constants:\n"
             "* const int string_latin_offset: %d (0x%x).\n\n"
           , string_latin_offset,   string_latin_offset
           );

    return;
}

void    test_contains   (void)
{
    const string_t  test    = "Test";
    const string_t  substr1 = "T";
    const string_t  substr2 = "Test";
    const string_t  substr3 = "est";
    const string_t  substr4 = "Tes";
    const string_t  substr5 = "!";
    const string_t  substr6 = "TEST";

    printf ( "bool string_contains (const string_t self, const string_t other, const textpos_t where):\n"
             "* Reference object: '%s' (%p), %lld char(s).\n"
             "* Substrings:\n"
             "  - #1 (inside): '%s' (%p), %lld char(s).\n"
             "  - #2 (inside): '%s' (%p), %lld char(s).\n"
             "  - #3 (inside): '%s' (%p), %lld char(s).\n"
             "  - #4 (inside): '%s' (%p), %lld char(s).\n"
             "  - #5 (not in): '%s' (%p), %lld char(s).\n"
             "  - #6 (not in): '%s' (%p), %lld char(s).\n"
             "* Results:\n"
             "  - #1: %s.\n"
             "  - #2: %s.\n"
             "  - #3: %s.\n"
             "  - #4: %s.\n"
             "  - #5: %s.\n"
             "  - #6: %s.\n\n"
           , test,      test,       string_len (test)
           , substr1,   substr1,    string_len (substr1)
           , substr2,   substr2,    string_len (substr2)
           , substr3,   substr3,    string_len (substr3)
           , substr4,   substr4,    string_len (substr4)
           , substr5,   substr5,    string_len (substr5)
           , substr6,   substr6,    string_len (substr6)
           , string_contains (test, substr1, BEGIN) ? "true"    : "false"
           , string_contains (test, substr2, END)   ? "true"    : "false"
           , string_contains (test, substr3, END)   ? "true"    : "false"
           , string_contains (test, substr4, BEGIN) ? "true"    : "false"
           , string_contains (test, substr5, BEGIN) ? "true"    : "false"
           , string_contains (test, substr6, BEGIN) ? "true"    : "false"
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
           , test,  test,   string_len (test)
           , test,          string_len (test)
           , copy,  copy,   string_len (copy)
           );

    string_del (copy);

    return;
}

void    test_crop   (void)
{
    const string_t  test    = "Test";
    const string_t  substr1 = "T";
    const string_t  substr2 = "Test";
    const string_t  substr3 = "est";
    const string_t  substr4 = "Tes";
    const string_t  substr5 = "!";
    const string_t  substr6 = "TEST";
    string_t        crop1   = string_crop (test, substr1, BEGIN);
    string_t        crop2   = string_crop (test, substr2, END);
    string_t        crop3   = string_crop (test, substr3, END);
    string_t        crop4   = string_crop (test, substr4, BEGIN);
    string_t        crop5   = string_crop (test, substr5, BEGIN);
    string_t        crop6   = string_crop (test, substr6, BEGIN);
    string_t        crop7   = string_crop (test, substr2, BEGIN);

    printf ( "bool string_crop (const string_t self, const string_t other, const textpos_t where):\n"
             "* Reference object: '%s' (%p), %lld char(s).\n"
             "* Substrings:\n"
             "  - #1 (inside): '%s' (%p), %lld char(s).\n"
             "  - #2 (inside): '%s' (%p), %lld char(s).\n"
             "  - #3 (inside): '%s' (%p), %lld char(s).\n"
             "  - #4 (inside): '%s' (%p), %lld char(s).\n"
             "  - #5 (not in): '%s' (%p), %lld char(s).\n"
             "  - #6 (not in): '%s' (%p), %lld char(s).\n"
             "  - #7 (inside): '%s' (%p), %lld char(s).\n"
             "* Results:\n"
             "  - #1: '%s' (%p), %lld char(s).\n"
             "  - #2: '%s' (%p), %lld char(s).\n"
             "  - #3: '%s' (%p), %lld char(s).\n"
             "  - #4: '%s' (%p), %lld char(s).\n"
             "  - #5: '%s' (%p), %lld char(s).\n"
             "  - #6: '%s' (%p), %lld char(s).\n"
             "  - #7: '%s' (%p), %lld char(s).\n\n"
           , test,      test,       string_len (test)
           , substr1,   substr1,    string_len (substr1)
           , substr2,   substr2,    string_len (substr2)
           , substr3,   substr3,    string_len (substr3)
           , substr4,   substr4,    string_len (substr4)
           , substr5,   substr5,    string_len (substr5)
           , substr6,   substr6,    string_len (substr6)
           , substr2,   substr2,    string_len (substr2)
           , crop1,     crop1,      string_len (crop1)
           , crop2,     crop2,      string_len (crop2)
           , crop3,     crop3,      string_len (crop3)
           , crop4,     crop4,      string_len (crop4)
           , crop5,     crop5,      string_len (crop5)
           , crop6,     crop6,      string_len (crop6)
           , crop7,     crop7,      string_len (crop7)
           );

    string_del (crop1);
    string_del (crop2);
    string_del (crop3);
    string_del (crop4);
    string_del (crop5);
    string_del (crop6);
    string_del (crop7);

    return;
}

void    test_eq (void)
{
    const string_t  test    = "Test";
    const string_t  unequal = "TesT";
    string_t        copy    = string_copy (test);

    printf ( "bool string_eq (const string_t self, const string_t other):\n"
             "* Reference objects:\n"
             "  - '%s' (%p), %lld char(s).\n"
             "  - '%s' (%p), %lld char(s).\n"
             "  - '%s' (%p), %lld char(s).\n"
             "* Expectations:\n"
             "  - '%s' vs. '%s': true.\n"
             "  - '%s' vs. '%s': true.\n"
             "  - '%s' vs. '%s': false.\n"
             "* Results:\n"
             "  - '%s' vs. '%s': %s.\n"
             "  - '%s' vs. '%s': %s.\n"
             "  - '%s' vs. '%s': %s.\n\n"
           , test,      test,       string_len (test)
           , copy,      copy,       string_len (copy)
           , unequal,   unequal,    string_len (unequal)
           , test,      test
           , test,      copy
           , test,      unequal
           , test,      test,       string_eq (test, test)      ? "true"    : "false"
           , test,      copy,       string_eq (test, copy)      ? "true"    : "false"
           , test,      unequal,    string_eq (test, unequal)   ? "true"    : "false"
           );

    string_del (copy);

    return;
}

void    test_join   (void)
{
    const string_t  expectation = "TestTestTest";
    const string_t  test        = "Test";
    string_t        join        = string_join (test, test, test);

    printf ( "str_t string_join (const string_t self, const string_t other, const string_t by):\n"
             "* Reference object: '%s' (%p), %lld char(s).\n"
             "* Expectation:      '%s', %lld char(s).\n"
             "* Result:           '%s' (%p), %lld char(s).\n\n"
           , test,          test,           string_len (test)
           , expectation,                   string_len (expectation)
           , join,          join,           string_len (join)
           );

    string_del (join);

    return;
}

void    test_len    (void)
{
    const natural_t length  = 0x4;
    const string_t  test    = "Test";

    printf ( "natural_t string_len (const string_t self):\n"
             "* Reference object: %s (%p), %lld char(s).\n"
             "* Measured length:  %lld char(s).\n\n"
           , test,              test,   length
           , string_len (test)
           );

    return;
}

void    test_lower  (void)
{
    const string_t  expectation = "test";
    const string_t  test        = "Test";
    string_t        lower       = string_lower (test);

    printf ( "str_t string_lower (const string_t self):\n"
             "* Reference object: '%s' (%p), %lld char(s).\n"
             "* Expectation:      '%s', %lld char(s).\n"
             "* Result:           '%s' (%p), %lld char(s).\n\n"
           , test,          test,   string_len (test)
           , expectation,           string_len (expectation)
           , lower,         lower,  string_len (lower)
           );

    string_del (lower);

    return;
}

void    test_mul    (void)
{
    const string_t  expectation = "TestTestTestTest";
    const string_t  test        = "Test";
    string_t        mul         = string_mul (test, 0x4);

    printf ( "str_t string_mul (const string_t self, const natural_t times):\n"
             "* Reference object: '%s' (%p), %lld char(s).\n"
             "* Expectation:      '%s', %lld char(s).\n"
             "* Result:           '%s' (%p), %lld char(s).\n\n"
           , test,          test,   string_len (test)
           , expectation,           string_len (expectation)
           , mul,           mul,    string_len (mul)
           );

    string_del (mul);

    return;
}

void    test_upper  (void)
{
    const string_t  expectation = "TEST";
    const string_t  test        = "Test";
    string_t        upper       = string_upper (test);

    printf ( "str_t string_upper (const string_t self):\n"
             "* Reference object: '%s' (%p), %lld char(s).\n"
             "* Expectation:      '%s', %lld char(s).\n"
             "* Result:           '%s' (%p), %lld char(s).\n\n"
           , test,          test,   string_len (test)
           , expectation,           string_len (expectation)
           , upper,         upper,  string_len (upper)
           );

    string_del (upper);

    return;
}



/**
 * The main function.
 */

int main (void)
{
    license         ();

    test_concat     ();
    test_constants  ();
    test_contains   ();
    test_copy       ();
    test_crop       ();
    test_eq         ();
    test_join       ();
    test_len        ();
    test_lower      ();
    test_mul        ();
    test_upper      ();

    return 0x0;
}

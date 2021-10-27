<!--
    README.md : important information regarding this project.

    See `LICENSE' for full license.
-->

<!--
    Copyright (C) 2021 Kevin Matthes

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
-->

<!----------------------------------------------------------------------------->

# libstring

## Summary

A simple C library for string operations.



## License

This project's license is **GPL 2**.  The whole license text can be found in
`LICENSE` in the main directory of this repository.  The brief version of the
license is as follows:

> Copyright (C) 2021 Kevin Matthes
>
> This program is free software; you can redistribute it and/or modify
> it under the terms of the GNU General Public License as published by
> the Free Software Foundation; either version 2 of the License, or
> (at your option) any later version.
>
> This program is distributed in the hope that it will be useful,
> but WITHOUT ANY WARRANTY; without even the implied warranty of
> MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
> GNU General Public License for more details.
>
> You should have received a copy of the GNU General Public License along
> with this program; if not, write to the Free Software Foundation, Inc.,
> 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.



## Introduction

When developing C projects, a very common task is the handling of strings.
This library offers a possible solution for the work with strings.

Thereby, the string is considered an object in the meaning of Object Oriented
Programming such that the functions for the provided types `str_t` and
`string_t` are designed like methods.



## Build process

### Required software for the build process

In order to build the library, the following applications will be required when
using the default settings for the build process.  All named software can be
altered by adjusting the variables in `makefile`.

Application | Variable in `makefile`    | Role during build process
:-----------|:--------------------------|:--------------------------
`ar`        | `ARCHIVE`                 | library creation
`cp`        | `COPY`                    | copying of library
`gcc`       | `CC`                      | compiler
`rm`        | `REMOVE`                  | removal of build artifacts
`valgrind`  | `VALGRIND`                | check for memory leaks



### Build invocation

To start the build process, one just needs to execute the following command in a
terminal:

```
make
```

Thereby, the library will be created and tested using the applications named in
the table above.  The tests are processed by applying `valgrind` to an
application named `test-libstring` which is the compilation of
`test_libstring.c`.  This file specifies a set of tests for all methods, except
the constructor and destructor methods, which also contain the signature of the
methods.  Once the tests are finished, the testing application will be removed.

In order to compile the testing application, the command to execute is

```
make test-libstring
```

When used as a submodule in another project, this project offers the utility
build instruction `submodule`.  When executing this task, the library will be
created and copied to the parent working directory together will all relevant
headers of this project.

```
make submodule
```



## Content

### Constants

#### `const int string_latin_offset`

Within the ASCII table of characters, the block of upper case Latin letters is
separated by a certain count of characters from the block of lower case Latin
letters.  This count is provided by this constant.

When used in projects, please keep in mind that the upper case block is situated
before the lower case block in the table such that `'A'` has a lower integer
number then `'a'`.



### Defines

#### `nullptr`

A pointer to use instead of `NULL`.  This pointer will be returned by all
functions of this library in case that something went wrong.

`nullptr` will always evaluate to `false`.



### Functions

#### `str_t string_concat (const string_t self, const string_t other)`

Unite two strings.  In case this function was applied to `"A"` and `"B"` as
`self` and `other`, respectively, the resulting string would be `"AB"`.



#### `str_t string_copy (const string_t self)`

Create a copy of `self`.  Therefore, a new memory area will be allocated and
filled with the characters of `self`.



#### `bool string_del (str_t self)`

Free the allocated memory for `self`.  Returns `true` when finished.



#### `bool string_eq (const string_t self, const string_t other)`

Check two strings for equality.  Two strings are equal if both contain the same
sequence of `char`s.



#### `str_t string_join (const string_t self, const string_t other, const string_t by)`

Unite two strings by another one.  In case this function was applied to `"A"`,
`"C"` and `"B"` as `self`, `other` and `by`, respectively, the resulting string
would be `"ABC"`.



#### `natural_t string_len (const string_t self)`

Determine the effective count of characters of a string.  For instance, `"A"`
would have a length of `0x1`.



#### `str_t string_lower (const string_t lower)`

Create a copy of `self` whose upper case Latin letters were turned to lower case
ones.



#### `str_t string_mul (const string_t self, const natural_t times)`

Multiply a string's content.  For instance, `"A"` and `0x3` as parameters would
imply `"AAA"` as result.



#### `str_t string (const natural_t size)`

Allocate `size` bytes of memory for a new string.  Each byte is initialised with
`0x0`.



#### `str_t string_upper (const natural_t self)`

Create a copy of `self` whose lower case Latin letters were turned to upper case
ones.



### Typedefs

#### `natural_t`

A type for wide ranged positive integer numbers.  In case it is not already
defined, this library will introduce it.



#### `str_t`

A type for generic, mutable strings.



#### `string_t`

A type for mutable strings with a constant position in memory.

<!--
    CONTRIBUTING.md : important conventions regarding this project.

    See `LICENSE' for full license.
    See `README.md' for project details.
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

# Contributing to this project

When contributing to this project, several conventions should be honoured in
order keep the overall appearance of this repository uniform.  These conventions
will be listed and explained in the following.

Please note that the conventions are sorted by the concerning coding languages
since they may differ between different languages.



## C

### Brackets

Opening brackets of blocks (`{`) require their own line each.  The indentation
has to be the same like the one of the expression opening it.  For instance:

```
int foo (void)
{
    return 0x0;
}
```

An exception to this rule are `enum`s and array initialisations which are
counted to the category of further lists.

Any other lists shall be handled according to the *Haskell* conventions, such as
parameter lists, `enum` definitions and array initialisations, for instance.  An
example is as follows:

```
typedef enum    { ONE
                , TWO
                , THREE
                } type_t;

int foo ( type_t one
        , type_t two
        , type_t three
        )
{
    return 0x0;
}
```



### Compiler and options

The default C compiler for this project is **`gcc`**.  It has to be called with
*at least* the following flags and options:

* `-std=c99`
* `-Wall`
* `-Werror`
* `-Wextra`
* `-Wpedantic`



### Indentation

Indentation is processed by **four spaces** per level.  In case some situations
should require real tab characters, i. e. `\t`, the tab character shall be
assumed to evaluate as a sequence of four spaces.

After type names, the next lexeme must start at the next tab stop.  Hence, after
entering a type name, the tabulator key needs to be pressed once.  An exception
to this rule are declaration sections and parameter lists.  For instance, this
rule would be applied to the signature of a function.

After entering an identifier, such as a function's or variable's name, for
example, the next lexeme shall start at the next tab stop, too.  This, again,
needs to be applied to a function's declaration.

A `return` statement does not need to be followed by a tab stop but just one
space character, followed by either the value to return or a semicolon.  In case
that nothing is returned, `return` and `;` must not be separated by spaces.

Example:

```
type_t  foo_    (type_t parameter)
{
    type_t  ret_    = ONE;
    return ret_;
}
```



### Language

All code and comments shall be written using **British English** with *-ise*
suffixes.

As in the terminology of LaTeX, there will be *no* **French Spacing** such that
after finishing a phrase, two space characters or a line break must be placed.
This is only required if there will be another sentence following the previous
one.



### Name mangling

If the exported symbols share common prefixes, they must be mangled using the
preprocessor macro `NAME(identifier)`.  This macro has be removed at the end of
the header unless an according symbolic constant is defined.  This constant
should be passed to the compiler during the build process.  The macro is
mandatory to use in all source files when a symbol requires the prefix.
Internal symbols do not need to be mangled.  Anyway, a mangling is recommended,
as well, since they may be exported in a future version.

Common parameter declarations for exported functions can be abbreviated, as
well, for instance identifiers like `self` and `other`.  Once defined, they
should be used just like the name mangling macro, including the automatic
cleaning once the header is left.



### Return statements

Any function must contain exactly **one** `return` statement.  This also
includes `void` functions.

In case that functions may be quit at different positions, the general design of
the function has to be adjusted such that only return statement is left.  This
may be done, for instance, by using Boolean values as flags for refactoring the
control flow of the function.

The only reasonable exception to this convention is the argument of performance.
If the performance of a function is critical for the success of the project,
this convention does not need to be applied.  Such functions have to be marked
`inline`.  Hence, `inline` functions are the only ones which are allowed to
contain more than one return statement, **if and only if** their performance is
optimised due to multiple statements.  They need to contain at least one, even
if they are `void`.



### Standard

All C source code needs to apply **C99, ANSI C**.  The main aspect of this
standard is that function definitions *must not* be finished with a semicola
character (`;`) as other standards allow it. The decision to use C99 as standard
shall ensure atmost portability of the project.

If the required standard is applied correctly can be tested by compiling with
the following options for the compiler `gcc`:

* `-std=c99`
* `-Wpedantic`



### `void` parameter lists

In case that functions do not need to receive any data as parameters, their
parameter list **must** be filled with `void` instead.

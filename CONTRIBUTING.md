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

### Language

All code and comments shall be written using **British English** with *-ise*
suffixes.

As in the terminology of LaTeX, there will be *no* **French Spacing** such that
after finishing a phrase, two space characters or a line break must be placed.
This is only required if there will be another sentence following the previous
one.



### Standard

All C source code needs to apply **C99, ANSI C**.  The main aspect of this
standard is that function definitions *must not* be finished with a semicola
character (`;`) as other standards allow it. The decision to use the C99
standard shall ensure atmost portability of the project.

If the required standard is applied correctly can be tested by compiling with
the following options for the compiler `gcc`:

* `-std=c99`
* `-Wpedantic`

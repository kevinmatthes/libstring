/**
 * libstring_join.c : unite two strings by another one.
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

#include "libstring.h"



/**
 * Functions.
 */

str_t   NAME (join) (SELF, OTHER, const string_t by)
{
    natural_t   counter = 0x0;
    string_t    ret     = string ( NAME (len) (self)
                                 + NAME (len) (other)
                                 + NAME (len) (by)
                                 + 0x1
                                 );

    for (natural_t i = 0x0; ret && self[i];  counter++, i++)
        ret[counter] = self[i];

    for (natural_t i = 0x0; ret && by[i];    counter++, i++)
        ret[counter] = by[i];

    for (natural_t i = 0x0; ret && other[i]; counter++, i++)
        ret[counter] = other[i];

    return ret;
}

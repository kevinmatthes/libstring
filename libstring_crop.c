/**
 * libstring_crop.c : remove a part from a string.
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

str_t   NAME (crop) (SELF, OTHER, WHERE)
{
    const natural_t diff    = NAME (len) (self) - NAME (len) (other);
    str_t           ret     = NAME (contains) (self, other, where)
                            ? nullptr
                            : string (diff + 0x1);

    switch (where)
    {
        default:
        {
            NAME (del) (ret);
            ret = nullptr;
            break;
        };

        case BEGIN:
        {
            for (natural_t i = 0x0; ret && ret[i]; i++)
                ret[i] = self[i + diff];

            break;
        };

        case END:
        {
            for (natural_t i = 0x0; ret && ret[i]; i++)
                ret[i] = self[i];

            break;
        };
    };

    return ret;
}

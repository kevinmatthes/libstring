##
#
# makefile : build instructions for the project.
#
# See `LICENSE' for full license.
# See `README.md' for project details.
#
##

##
#
# Copyright (C) 2021 Kevin Matthes
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
#
##

################################################################################

##
#
# Variables.
#
##

AFLAGS   := rs
APP      := test-libstring
ARCHIVE  := ar
CC       := gcc
CFLAGS   := -std=c99 -Wall -Werror -Wextra -Wpedantic -D__LIBSTRING_INTERNAL__
COPY     := cp
HEADERS  := $(wildcard ./*.h)
LFLAGS   :=
LIBRARY  := libstring.a
OBJECTS  := $(subst .c,.o, $(wildcard ./libstring_*.c))
REMOVE   := rm
SOURCE   := $(wildcard ./libstring_*.c)
TESTARGS :=
TESTING  := ./test_libstring.c
TESTLINK := -L. -lstring
VALGRIND := valgrind.log
VFLAGS   := --leak-check=full --redzone-size=200 --show-leak-kinds=all



##
#
# Build instructions.
#
##

.PHONY: default
default: $(VALGRIND) tidy

$(APP): $(LIBRARY) $(TESTING)
	$(CC) $(CFLAGS) $(TESTING) $(TESTLINK) -o $@

$(LIBRARY): $(OBJECTS)
	$(ARCHIVE) $(AFLAGS) $@ $^

$(OBJECTS): $(SOURCE)
	$(CC) $(CFLAGS) -c $(LFLAGS) $^

.PHONY: submodule
submodule: $(HEADERS) $(LIBRARY)
	$(COPY) $^ ../

.PHONY: tidy
tidy: $(APP) $(LIBRARY) $(OBJECTS)
	$(REMOVE) $^

.PHONY: update
update: submodule tidy

$(VALGRIND): $(APP)
	valgrind $(VFLAGS) ./$^ $(TESTARGS) 2> ./$@

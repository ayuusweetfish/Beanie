#!/usr/bin/env make
#
# YYYY/XXX 	<<=== The IOCCC Judges will replace this line

#############################
# shell used by this Makefile
#############################

SHELL= bash


#######################
# common tool locations
#######################
#
# XXX - The IOCCC judges will remove this line and uncomment the next line later
# include ../../var.mk var.mk

# XXX - for now, set some common tool locations
# XXX - once var.mk is in use, the IOCCC judges will remove the section below
CC= cc
CHMOD= chmod
CLANG= clang
CLANG_FORMAT= clang-format
CPP= cpp
GCC= gcc
MV= mv
RM= rm
RMDIR= rmdir
TRUE= true


#####################
# C compiler settings
#####################

# Common C compiler warnings to silence
#
# Example: CSILENCE= -Wno-int-conversion
#
# NOTE(author): Edited
CSILENCE= \
  -Wno-parentheses -Wno-char-subscripts

# Attempt to silence unknown warning options
#
CUNKNOWN= -Wno-unknown-warning-option

# Common C compiler warning flags
#
# NOTE: The addition of -pedantic to CWARN is a challenge that
#       You may wish to avoid if it proves too problematic.
#       There is NO penalty for removing -pedantic from CWARN.
#
CWARN= -Wall -Wextra -pedantic ${CSILENCE} ${CUNKNOWN}

# Compiler standard
#
# NOTE(author): Modified (was: -std=gnu17)
CSTD= -std=c99

# Compiler bit architecture
#
# Example for 32-bitness: ARCH= -m32
# Example for 64-bitness: ARCH= -m64
#
# NOTE: Normally one should NOT specify a specific architecture.
#
ARCH=

# Defines that are needed to compile
#
# Example: -Dfoo -Dbar=baz
#
CDEFINE=

# Include files that are needed to compile
#
# Example: CINCLUDE= -include stdio.h
#
CINCLUDE=

# Other flags to pass to the C compiler
#
# Example: COTHER= -fno-math-errno
#
COTHER=

# Optimization
#
# NOTE: Feel free to change the level of compiler optimization.
#       The "-O3" is just a friendly default you might wish to try.
#
# Example: OPT= -O0 -g
#
OPT= -O3

# Default flags for ANSI C compilation
#
CFLAGS= ${CSTD} ${CWARN} ${ARCH} ${CDEFINE} ${CINCLUDE} ${COTHER} ${OPT}

# Libraries needed to build
#
# Example: LDFLAGS= -lncurses -lm
#
LDFLAGS=

# C compiler to use
#
# NOTE: The IOCCC Judges recommend you leave CC as just "cc"
#       and NOT set it to clang, or gcc, or something else
#       unless you have a STRONG reason to do so.
#
#       Setting CC to something other than "cc" makes your
#       code less portable to those who do not have your
#       particular C compiler.  **hint**
#
#       If you want to test your code with a particular C compiler,
#       use the make command line.  For example:
#
#           make all CC=clang
#           make all CC=gcc
#
CC= cc

# Compiler add-ons or replacements for clang only
#
ifeq "$(findstring $(CLANG),${CC})" "$(CLANG)"
#
# NOTE: This code is only invoked when CC contains "clang"
#       such as when you use the make command lines like:
#
#           make all CC=clang
#           make all CC=clang-mp-12
#
CSILENCE+=
#
# CWARN+= -Weverything \
#   -Wno-unsafe-buffer-usage -Wno-missing-variable-declarations -Wno-missing-prototypes \
#   -Wno-comma -Wno-shadow -Wno-sign-conversion -Wno-implicit-int-conversion
#
endif

# Specific add-ons or replacements for gcc only
#
ifeq "$(findstring $(GCC),${CC})" "$(GCC)"
#
# NOTE: This code is only invoked when CC contains "gcc"
#       such as when you use the make command lines like:
#
#    make all CC=gcc
#    make all CC=gcc-15
#
CSILENCE+=
#
CWARN+=
#
endif


###########################################
# Special Makefile variables for this entry
###########################################

#ENTRY= XXX - The IOCCC judges will change this line later
PROG= prog
#
OBJ= ${PROG}.o
TARGET= ${PROG}

# NOTE(author): Has alternative program
ALT_OBJ= ${PROG}.alt.o
ALT_TARGET= ${PROG}.alt

# list any data files supplied with your submission
#
# Example: DATA= curds whey
#
DATA=

# NOTE: Add any new Makefile variables your code might need below.
#
# Example: WIDTH= 120
#


#################
# build the entry
#################

all: data ${TARGET}
	@${TRUE}

.PHONY: all alt data everything clean clobber

${PROG}: ${PROG}.c
	${CC} ${CFLAGS} ${PROG}.c -o $@ ${LDFLAGS}

# suggested way(s) to run the program
# NOTE(author): Removed try rule

# alternative executable
#
alt: data ${ALT_TARGET}
	@${TRUE}

${PROG}.alt: ${PROG}.c
	${CC} ${CFLAGS} ${PROG}.c -DN=8 -o $@ ${LDFLAGS}

# suggested way(s) to run alt code, if you include a prog.alt.c
# NOTE(author): Removed try.alt rule

# data files
#
data: ${DATA}
	@${TRUE}

# both all and alt
#
everything: all alt
	@${TRUE}

# NOTE(author): Additional fuzz target
fuzz: ${PROG}.c fuzz.c
	clang ${CFLAGS} fuzz.c -o $@ -g -fsanitize=fuzzer,address,undefined

# NOTE(author): Additional arduino-sketch target
arduino-sketch: ${PROG}.c
	cp $< arduino/serial_play/prog.h
.PHONY: arduino-sketch


###############
# utility rules
###############
#
clean:
	@# NOTE(author): Additional fuzz target
	${RM} -f ${OBJ} ${ALT_OBJ} fuzz.o

clobber: clean
	@# NOTE(author): Additional fuzz and arduino-sketch targets
	${RM} -f ${TARGET} ${ALT_TARGET} fuzz
	${RM} -f arduino/serial_play/prog.h
	${RM} -rf *.dSYM


######################################
# optional include of 1337 hacker rulz
######################################

-include 1337.mk ../1337.mk ../../1337.mk

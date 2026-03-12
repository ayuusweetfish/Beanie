#!/usr/bin/env bash
#
# try.sh - demonstrate YYYY/XXX	    <<=== The IOCCC Judges will replace this line

# make sure CC is set so that when we do make CC="$CC" it isn't empty. Doing it
# this way allows us to have the user specify a different compiler in an easy way.
#
[[ -z "$CC" ]] && CC="cc"

# make sure the program has been built
#
MAKE=$(command -v gmake)
${MAKE:=make} CC="$CC" all >/dev/null || exit 1

# clear the screen
#
clear

# try the program
#
read -r -n 1 -p "Press any key to run: ./prog: "
echo 1>&2
./prog
echo 1>&2

# try the program with sound
#
echo 'The game supports sounds. If you have `sox` installed, you can try this.' 1>&2
echo 1>&2
read -r -n 1 -p "Press any key to run: ./prog >(sox --buffer 1024 -t s16 -r 48000 -c 1 - -d 2>/dev/null): "
echo 1>&2
./prog >(sox --buffer 1024 -t s16 -r 48000 -c 1 - -d 2>/dev/null)
echo 1>&2

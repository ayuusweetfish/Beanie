This program is a game that can be played in the console. Use `try.sh` to build and run; the rules are straightforward and you might want to dive in right away, without extensive reading.

### Rules

The game arena is a cell grid of `N - 1` rows and `N` columns. Some of the cells are traps; each row or column contains at most one trap. The player starts from outside the arena, entering on any cell on the first row, and aims to exit from the last, making moves in four directions into adjacent cells (L/R/U/D). Each time the player hits a trap, they are teleported back to the initial position, outside of the arena. The objective is to successfully exit the arena in as few attempts as possible.

The game is expected to run in an ANSI-compliant terminal emulator. Movement can be made by arrow keys or `h`/`j`/`k`/`l` keys as in `vi`. It can be exited by SIGINT (Control-C), or the `q` key. (Note that in `try.sh`, a SIGINT terminates the entire script; use the `q` key instead.)

### Features

#### Adversarial play

The distribution of traps is not predetermined. Instead, the computer plays against the player whenever they make a move, trying to maximize their number of attempts.

To test the player in varied cases, the program does not always take the "best" (most adverse) decision; instead, it traverses combinations of conditions, and the player might take on some risk to find an early win.

#### Sound

This game supports sound output by writing PCM to a pipe. An example working with `sox` is provided in `try.sh`.

#### Portability

The core game logic is exposed through functions `R()` (for reset) and `M()` (for movement/input handling). A player interface can be created by accessing the game state at the array `a` and the state indicator `o`; meanwhile, there is also a game loop scaffold `L()` that takes a minimal set of environment adapters (character I/O, sound, entropy) and presents a text-based interface.

The author believes that the core game logic can run correctly on any platform, agnostic of word size, endianness, and signedness of `char`. The author has tested the game under ARM64 Linux, x86-64 Linux, and the ATmega 8-bit MCU (and is eagerly looking to adding more to the list, especially on various MCUs ^ ^).

#### Fuzzing

There is a fuzzing program that uses LLVM's libFuzzer to test the algorithm against memory access violations, undefined behaviour, and overall correctness. Run `make fuzz` to build it, and `./fuzz` to run.

Note that the current algorithm only ensures correct operation at `N = 5` and holds a weaker guarantee at larger values of `N`; namely, if the player is lucky and clever, they can trick the game into generating less than `N - 1` traps. This, however, does not affect the gameplay logic, nor does it violate the rules stated above. If the player is at this corner case, they must have no problem winning the game! (\>\_\^)

#### Tangible form

Also included is an Arduino port. The `arduino/serial_play/` directory contains an Arduino sketch that exposes a game interface on the serial port, playable through an ANSI-compatible terminal emulator/multiplexor (e.g., `screen`). This sketch also supports sound output through a passive buzzer, and input through four direction buttons.

The author also has assembled a handheld gaming console that integrates these components and an addressable LED matrix. See `misc/handheld_hw/` for the circuit board design and `arduino/handheld/` for the Arduino sketch.

### Obfuscation techniques

#### Warnings

In author's tests with GCC 15.2.1 and Clang 20.1.8 on ARM64 Linux, as well as GCC 13.3.0 on x86-64 Linux, the code compiles cleanly with `-Wall -Wextra -pedantic` with the addition of `-Wno-parentheses -Wno-char-subscripts`. These two exemptions are due to deliberate choices, i.e., omitting paretheses as much as possible as an obfuscation technique, and reducing memory usage as much as possible with built-in C types (because we will be running on constrained 8-bit platforms!).

(Secret: GCC might complain about two `-Wsign-compare`'s, but that is actually a deobfuscating hint only available to users of some of the architectures!)

#### Macros

You might already notice how `r`, `R`, `r(r, N)`, `R(R, C)` are five different things; but are `R` and `C` really what they appear to stand for, while sometimes they are not properly wrapped by parentheses in the macro?

#### Positive energy

The core game logic does not use the character `0` in its code, without obvious direct escapes.

#### Custom operators

The code features many custom operators that extends the C standard:
- The sleepyhead operator `-~-`, with variants `=~-`, `=-~`, `-=-`, etc.;
- The crybaby operator `T:T`, with variant `T;T`;
- The fish operator `<o<<` and the fishing bait operator `<~-`;
- The barbecue/tanghulu operators `++>`, `o++`, `+o>>`;
- The shooting star operator `==*`;
- The little prince's rose operator `+~(`.

### Food for thought

1. Assuming that `char` equals `int8_t`, what is the maximum value of `N` that the game logic (`R()` and `M()`) correctly supports?
2. Under which values of `N` can the player determine whether it is possible to land on an empty cell on row _r_ (numbering starting from 1) on the first move, and achieve it when it is?
  - (a) If _r_ = 1?
  - (b) If _r_ = 2?
3. Win the game in 2 moves.

### Final spoiler

This game is actually a faithful replication of a problem on a well-known contest.

It is [IMO 2024 Problem 5](https://artofproblemsolving.com/wiki/index.php/2024_IMO_Problems/Problem_5). It's a hard problem on the contest, and a great brain-teaser as well. Hope you have enjoyed it!

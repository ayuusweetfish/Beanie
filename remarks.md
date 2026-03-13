This program is a game that can be played in the console. Use `try.sh` to build and run; the rules are straightforward and you might want to dive in right away, without extensive reading.

### Rules

The game arena is a cell grid of `N - 1` rows and `N` columns. Some of the cells are traps. There is one trap in each of the rows, and each column contains at most one trap (so exactly one column contains no trap). The player starts from outside the arena, from the top, and aims to exit from the bottom, making moves in four directions into adjacent cells (L/R/U/D). Each time the player hits a trap, they are teleported back to the initial position, outside the arena. The objective is to go through the arena in as few attempts as possible.

The game is expected to run in an ANSI-compliant terminal emulator. Movement can be made by arrow keys or `h`/`j`/`k`/`l` keys as in `vi`. It can be exited by `SIGINT` (Control-C), or the `q` key.

### Features

#### Reasoning guide

The game provides a visualization of  that can be trivially reasoned about.

#### Adversarial play

The distribution of traps is not predetermined. Instead, the computer plays against the player whenever they make a move, trying to maximize their number of attempts.

[IMO 2024 Problem 5](https://artofproblemsolving.com/wiki/index.php/2024_IMO_Problems/Problem_5).

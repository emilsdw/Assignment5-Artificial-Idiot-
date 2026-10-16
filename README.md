# Assignment 5 – Artificial Idiot

A small language model written in C++ for DA4007 Programming Techniques II. The program learns character patterns from a training text and uses them to generate new text.

## How it works
A **k-gram** is a sequence of `k` characters. The program counts which characters follow each k-gram in the training text.

The probability of generating character `c` after k-gram `w` is calculated using pseudo-count smoothing:

```text
P(c | w) = (n(w,c) + alpha) / (n(w) + alpha * A)
```

Here, `n(w,c)` counts how often `c` follows `w`, `n(w)` counts all observed characters following `w`, and `A` is the number of distinct characters in the training text. The pseudo-count `alpha` is currently fixed at `0.1`. Generated text varies between runs because characters are sampled randomly.


The generator takes a character from this distribution, appends it to the output, and updates the current k-gram by removing its first character and adding the character to the end.


## Compilation

Requires `make` and `g++` with C++17.

From the project directory, run:

```bash
make
```

This creates the executable `program`.

To remove the executable:

```bash
make clean
```

## Usage

```bash
./program <k> <training_file> <number_of_new_characters>
```

Example:

```bash
./program 3 moby_dick.txt 100
```



To save the output:

```bash
./program 3 moby_dick.txt 100 > generated.txt
```

## Code structure

- `src/reader.h` and `src/reader.cpp`: define the `Reader` class, which reads the training file and extracts its alphabet.
- `src/generator.h` and `src/generator.cpp`: define the `Generator` class, which counts the following characters, calculates probabilities, and generates text.
- `src/Artificial_idiot.cpp`: contains `main` and connects command-line arguments to the class functions.
- `Makefile`: provides compilation and cleanup commands.

## Remaining work

- Complete argument validation and exception handling, reporting errors through `std::cerr` and returning a non-zero exit status.
- Compile source files separately so that `make` recompile only what is necessary.
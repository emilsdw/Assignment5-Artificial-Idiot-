# Assignment 5 – Artificial Idiot

A small language model written in C++ for DA4007 Programming Techniques II. The program learns character patterns from a training file and generates new text.

## Compilation

Requires `make` and `g++` with C++17 support.

From the project directory, run:

```bash
make
```

This creates the executable `slm`. Source files are compiled separately, so new builds recompile only files affected by changes.

To remove the executable and object files:

```bash
make clean
```

## Usage

```bash
./slm [-a alpha] <k> <training_file> <length>
```

- `k`: positive integer specifying the number of characters in each k-gram.
- `training_file`: path to the training text.
- `length`: requested total number of output characters, including the starting k-gram. Must be at least `k`.
- `-a alpha`: optional non-negative pseudocount. Defaults to `0`.

The training file must contain at least `k + 1` characters. The supplied training texts use ASCII, so each character is represented by one `char`.

Generate up to 100 characters using k-grams of length 3:

```bash
./slm 3 moby_dick.txt 100
```

Generate 100 characters with pseudocount smoothing:

```bash
./slm -a 0.01 3 moby_dick.txt 100
```

Save generated text to a file:

```bash
./slm -a 0.01 3 moby_dick.txt 100 > generated.txt
```

Generated text is written to standard output. Error messages are written to standard error.

## How the model works

A k-gram is a sequence of `k` characters, which may include spaces and newlines.

The program counts how often each character follows each k-gram in the training text. It calculates the probability that a character follows a k-gram using:

```text
P(c | w) = (n(w,c) + alpha) / (n(w) + alpha * |A|)
```

Here:

- `n(w,c)` counts occurrences of k-gram `w` followed by character `c`.
- `n(w)` is the total number of observed characters following `w`.
- `|A|` is the number of distinct characters in the training text.
- `alpha` is the pseudocount added to each possible next character.

The starting k-gram is selected by sampling uniformly among all complete k-gram positions in the training text. This makes each k-gram's selection probability proportional to its occurrence frequency.

The generator then repeatedly:

1. Samples a character from the current k-gram's transition distribution.
2. Appends that character to the output.
3. Removes the first character of the current k-gram and appends the sampled character.

Generation stops when the requested length is reached. With `alpha = 0`, it also stops if the current k-gram has no observed transitions, so the output may be shorter than requested.

With positive `alpha`, every character in the alphabet has positive probability. For an unseen k-gram, the next-character distribution is uniform.

Larger `k` values generally preserve longer patterns from the training text. Larger pseudocounts make the output more random. Output may differ between runs.

## Error handling

The program uses standard C++ exceptions to report invalid input, including:

- Incorrect argument counts or unknown options.
- Invalid numerical arguments.
- Non-positive `k` or output length.
- Output length smaller than `k`.
- Negative or non-finite pseudocounts.
- Training files that cannot be opened.
- Training texts shorter than `k + 1` characters.

Exceptions are caught in `main`, which prints an error message.

## Code structure

- `src/Artificial_idiot.cpp`: command-line arguments, program execution, and exception handling.
- `src/reader.h` and `src/reader.cpp`: the `Reader` class, which reads the training text and extracts its alphabet.
- `src/generator.h` and `src/generator.cpp`: the `Generator` class, which counts transitions, calculates probabilities, and generates text.
- `Makefile`: compilation and cleanup.
- `.gitignore`: excludes generated build files from version control.



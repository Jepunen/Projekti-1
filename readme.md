# `reverse.c`

## Overview
`reverse` is a program that reads lines from an input file (or standard input) and prints them in reverse order to an output file (or standard output).

## Compilation
To compile `reverse`, use the following command:
```sh
gcc -o reverse reverse.c
```

## Usage
```sh
./reverse [input_file] [output_file]
```
-    If no files are provided, the program reads from standard input and writes to standard output.
-    If only an input file is provided, the program reads from the input file and writes to standard output.
-    If both input and output files are provided, the program reads from the input file and writes to the output file.

## Error Handling
-    If more than two arguments are provided, the program prints `Usage: reverse <input> <output>` and exits with status `1`.
-    If the input file cannot be opened, the program prints `Error: cannot open file 'input_file'` and exits with status `1`.
-    If the output file cannot be opened, the program prints `Error: cannot open file 'output_file'` and exits with status `1`.
-    If the input and output files are the same, the program prints `Input and output file must differ` and exits with status `1`.

## Example
```sh
./reverse input.txt output.txt
```

## Functions

### `createNode`
-    Creates a new node with the given line.
-    Prototype: `Node* createNode(char *line);`

### `read_lines`
-    Reads lines from the input file and stores them in a linked list.
-    Prototype: `Node* read_lines(FILE *input);`

### `print_lines`
-    Prints the lines in reverse order from the linked list.
-    Prototype: `void print_lines(Node *head, FILE *output);`

## Data Structures

### `Node`
-    Represents a node in a linked list.
-    Members:
  - `char *line`: The line of text.
  - `Node *next`: Pointer to the next node.

## Example Usage
```sh
./reverse input.txt output.txt
```
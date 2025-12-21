# C-alculator

A lightweight C project that parses and evaluates arithmetic expressions from the command line.

## Features

- Supports `+`, `-`, `*`, `/`, `%`, `^` operators
- Supports parentheses for grouping
- Prints tokens and AST (Abstract Syntax Tree) for debugging with optional flags
- Handles floating-point values

## Usage

Compile the project:
```Powershell
.\compile
```

Run the calculator with an expression:
```Powershell
.\c-alculator "((1.5 + 2.5) * 2) / (3 - 1) ^ 2"
```
Optional flags:	
| Flag | Description |
| -------- | -------- |
| --print-tokens or -t | Print tokens as they are parsed |
| --print-ast or -a | Print the AST structure |

## Inspiration & Guidance:
#### [Making a calculator from scratch by VoxelRifts](https://youtu.be/myZcNjKcVGw?si=gkroc_VdrHY4e-uT)

With this project, I aimed to use traditional learning resources rather than AI. The idea and understanding came from the video above. As this was my first C project, I also made extensive use of [w3schools](https://www.w3schools.com/c), [geeksforgeeks](https://www.geeksforgeeks.org/c), [stackoverflow](https://stackoverflow.com) and [google](https://google.com).

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


## Optional flags:
| Flag | Description |
| -------- | -------- |
| --print-tokens or -t | Print tokens as they are parsed |
| --print-ast or -a | Print the AST structure |


## Inspiration & Guidance:
#### [Making a calculator from scratch by VoxelRifts](https://youtu.be/myZcNjKcVGw?si=gkroc_VdrHY4e-uT)

With this project, I aimed to use traditional learning resources rather than AI. The idea and understanding came from the video above. As this was my first C project, I also made extensive use of [w3schools](https://www.w3schools.com/c), [geeksforgeeks](https://www.geeksforgeeks.org/c), [stackoverflow](https://stackoverflow.com) and [google](https://google.com).


## Refinements & Favorite learning moments:
- [Implement lexing without lexeme string allocation](https://github.com/TheoTheTorch/C-alculator/commit/1bcbb31d87ae713bea717e0f32b2453ab165cc93)
- [Refactor parser until I completely understood the underlying logic](https://github.com/TheoTheTorch/C-alculator/commit/988e2b12cc41a46040f420d17c24d36049293058)
- [Decouple parser from lexer via dependency injection](https://github.com/TheoTheTorch/C-alculator/commit/4ebb393bf9960600dc406378e40fee07898c9011)
- [Skip invalid characters in lexer by a simple recursion](https://github.com/TheoTheTorch/C-alculator/commit/6242cd30ae521ff268df28b2cf3dc0c238a0a786)
- [Find the last missing handle for a created Error node](https://github.com/TheoTheTorch/C-alculator/commit/8586128c12f56bc168255454f0cbee9b27f50390)

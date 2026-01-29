# C-alculator
A lightweight C project for evaluating arithmetic expressions via the command line.


## Features
- Operators: `+`, `-`, `*`, `/`, `%`, `^`
- Parentheses for grouping expressions
- Print tokens or the AST via flags
- Floating-point values


## Usage
Compile:
```Powershell
.\compile.ps1
```

Run:
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

With this project, I aimed to use traditional learning resources rather than AI. The idea and understanding came from the video above. My other most used resources were a simple combination of [w3schools](https://www.w3schools.com/c), [geeksforgeeks](https://www.geeksforgeeks.org/c), [stackoverflow](https://stackoverflow.com) and [google](https://google.com).


## Refinements & Favorite learning moments:
[After the program was first finished](https://github.com/TheoTheTorch/C-alculator/commit/0cfa074d81422100130478a531ebb0cc76cb2095), I went the extra mile to iteratively rewrite logic until it was sound, efficient and readable. I gained my deepest insights through deviating from the source material.

- [Implement lexing without lexeme string allocation](https://github.com/TheoTheTorch/C-alculator/commit/1bcbb31d87ae713bea717e0f32b2453ab165cc93)
- [Greatly simplify precedence tracking in parser](https://github.com/TheoTheTorch/C-alculator/commit/988e2b12cc41a46040f420d17c24d36049293058)
- [Refactor parser to fetch tokens lazily](https://github.com/TheoTheTorch/C-alculator/commit/eb19393ca480e1726a7be31d2565e4d76d3cbc79)
- [Decouple parser from lexer via dependency injection](https://github.com/TheoTheTorch/C-alculator/commit/4ebb393bf9960600dc406378e40fee07898c9011)
- [Use recursion to skip invalid characters in lexer](https://github.com/TheoTheTorch/C-alculator/commit/6242cd30ae521ff268df28b2cf3dc0c238a0a786)
- [Handle cases of an Error node in all code-paths](https://github.com/TheoTheTorch/C-alculator/commit/8586128c12f56bc168255454f0cbee9b27f50390)

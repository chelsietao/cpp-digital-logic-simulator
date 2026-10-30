# C++ Digital Logic Simulator

A beginner-friendly terminal-based C++ project implementing fundamental digital logic circuits, truth tables, number conversion, and binary adders. Built as practice for the first five lectures of NTU OpenCourseWare's introductory programming course.

## Learning scope

- Standard input/output (`iostream`)
- Selection (`if`, `else`), loops (`for`, `while`)
- Variables and fixed-size arrays
- Functions, parameters, array output parameters
- Decimal/binary numbers and basic Boolean logic

**Deliberately excluded:** classes, `std::vector`, dynamic memory allocation, external libraries, file I/O, and GUI.

## Features

1. AND, OR, NOT, XOR logic gates
2. Two-input truth tables
3. Unsigned 8-bit decimal/binary conversions
4. Half adder
5. Full adder
6. Four-bit ripple-carry adder (5-bit output)

## Requirements

- macOS with Apple Command Line Tools (Clang++)
- VS Code and Microsoft's C/C++ extension (optional)

Check your compiler:

```bash
clang++ --version
```

If missing on macOS, install the command line developer tools:

```bash
xcode-select --install
```

## Build and run

From the repository root:

```bash
clang++ -std=c++11 -Wall -Wextra -pedantic src/main.cpp -o digital-logic
./digital-logic
```

Or use VS Code `Terminal > Run Build Task` (or `Cmd+Shift+B`), then execute `./digital-logic` from the integrated terminal.

## Example

```text
Choose: 4
A: 1
B: 1
SUM=0 CARRY=1
```

## Project layout

```text
cpp-digital-logic-simulator/
├── .gitignore
├── .vscode/
│   └── tasks.json
├── docs/
│   └── test-cases.md
├── src/
│   └── main.cpp
└── README.md
```

## Notes

- For 8-bit conversion, numbers are unsigned (0 to 255).
- The 4-bit adder accepts exactly four input bits per operand, most-significant bit first, and prints a 5-bit result.
- `digital-logic` is a generated executable and is ignored by Git.

## Roadmap (after foundational coursework)

- Improve error handling and automatic tests
- Add signed two's-complement operations
- Add circuit visualizations

## Academic use

This project is a small independent learning exercise. It is not an industrial circuit simulator.

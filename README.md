# C - printf

This project involves creating a custom implementation of the standard C library printf function. It is part of the ALX SE Foundations curriculum and is a group project completed by Talal Omer and Tariq Omer.

## Table of Contents

- [Introduction](#introduction)
- [Concepts and Skills](#concepts-and-skills)
- [Requirements](#requirements)
- [Project Tasks](#project-tasks)
- [Usage](#usage)
- [Authors](#authors)

---

## Introduction

The goal of this project is to design and implement a function that mimics the behavior of C's printf. The project evaluates knowledge of C programming, function pointers, variadic functions, and custom formatting for various conversion specifiers.

---

## Concepts and Skills

- **Variadic Functions**: Handling functions with an indefinite number of arguments.
- **Custom Format Specifiers**: Implementing and extending conversion specifiers like %c, %s, %d, %i, %b, %u, %o, %x, %X, %S, %p, %r, and %R.
- **Buffer Management**: Using local buffers to optimize system calls.
- **Edge Case Handling**: Mimicking printf behavior for unsupported or non-printable characters and flags.
- **Team Collaboration**: Working in pairs to deliver a functional project.

---

## Requirements

- **Editors**: vi, vim, or emacs.
- **Compilation**: Files will be compiled on Ubuntu 20.04 LTS using gcc with the flags:
  `-Wall -Werror -Wextra -pedantic -std=gnu89`
- **Style Guidelines**:
  - Code should adhere to the Betty style.
  - All files must end with a new line.
  - A header file `main.h` with proper include guards must be used.
- **Constraints**:
  - No global variables.
  - A maximum of 5 functions per file.
  - Do not include any main functions in the root directory (use a separate test folder).

---

## Project Tasks

0. **Basic Printf**
   Implement `_printf` that handles `%c`, `%s`, and `%%`.

1. **Signed Numbers**
   Add support for `%d` and `%i`.

2. **Binary Conversion**
   Support `%b` to convert an unsigned int to binary.

3. **Unsigned Conversions**
   Handle `%u`, `%o`, `%x`, and `%X`.

4. **Buffered Output**
   Use a local buffer of 1024 characters to minimize calls to `write`.

5. **Custom Non-Printable Handling**
   Implement `%S` to show non-printable characters in hexadecimal.

6. **Pointer Address**
   Implement `%p` to print pointer addresses.

7. **Flags for Conversion Specifiers**
   Support flags like `+`, space, and `#` for non-custom conversions.

8. **Length Modifiers**
   Support `l` and `h` length modifiers for `%d`, `%i`, `%u`, `%o`, `%x`, `%X`.

9. **Field Width**
   Add support for field width.

10. **Precision**
    Implement precision handling.

11. **Zero Flag**
    Support the `0` flag character.

12. **Minus Flag**
    Support the `-` flag for left-justification.

13. **Reverse String**
    Implement `%r` to print the reversed string.

14. **ROT13 Conversion**
    Implement `%R` to print the ROT13 encoded string.

15. **All Options Together**
    Integrate all features ensuring they work in harmony.

---

## Usage

1. Clone the repository:

   ```bash
   git clone <your-repository-url>
   ```

2. Navigate to the project directory:

   ```bash
   cd /root/printf
   ```

3. Compile the project:

   ```bash
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
   ```

4. Run the executable:

   ```bash
   ./a.out
   ```

---

## Authors

Group Project by:

- Talal Omer
- Tariq Omer

**Contribution**: 100% by the group.
**Auto QA Review**: Detailed review metrics provided at submission.

---

Copyright © 2024.

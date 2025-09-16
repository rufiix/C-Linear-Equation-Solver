# C Linear Equation Solver

## Overview

This project is a C implementation of a solver for systems of linear equations of the form **Ax = b**. It utilizes Gaussian elimination with back substitution to find the solution vector **x**. The program is designed to read matrix **A** and vector **b** from input files, perform the necessary calculations, and print the resulting solution vector **x** to the screen.

---

## Features

* **File Input**: Reads matrices and vectors from text files.
* **Dynamic Memory Allocation**: Matrices are dynamically created based on dimensions specified in the input files.
* **Gaussian Elimination**: Implements the forward elimination phase to transform the augmented matrix into row echelon form.
* **Back Substitution**: Solves the system of equations from the row echelon form matrix.
* **Error Handling**: Includes basic checks for common issues such as:
    * Singular matrices (division by zero during elimination).
    * Mismatched matrix dimensions.
    * File I/O errors.

---

## How to Compile and Run

### Prerequisites

* A C compiler (e.g., `gcc`)
* `make` utility

### Compilation

To compile the project, navigate to the root directory and run the `make` command. This will compile all source files from the `src/` directory and create an executable file named `gauss` in the `bin/` directory.

```bash
make all

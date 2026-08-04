# Assignment 01 - GEMM (General Matrix Multiplication)

## Course
**CS509 - Programming Lab**

## Assignment Type
**Single Assignment**

## Student details

- Name - Mohd Shah Faaz
- Entry number - 2026AIM1013

## Objective

In this assignment, we have to implement General Matrix Multiplication (GEMM) using two different approaches:

- Simple GEMM (Direct Triple Nested Loop)
- Blocking GEMM (Tiled Matrix Multiplication)

The execution time of both implementations is measured and compared.

---

# Algorithm Description

## 1. Simple GEMM

The simple implementation performs matrix multiplication using three nested loops.

For matrices:

- A of size M × K
- B of size K × N

The output matrix C is computed as

```
C[i][j] = Σ A[i][k] × B[k][j]
```

---

## 2. Blocking GEMM

Blocking GEMM divides the matrices into smaller square blocks (tiles).

Instead of processing one complete row and column at a time, multiplication is performed block by block.

This improves cache utilization and generally provides better performance for large matrices.

Block Size used:

```
32
```

---

# Input Format

Each test case is stored in a separate text file.

Format:

```
M K N

Matrix A

Matrix B
```

Example:

```
2 3 2
1 2 3
4 5 6
7 8
9 10
11 12
```

Where

- Matrix A = 3 × 3
- Matrix B = 3 × 2

---

# Output

For every test case the program prints

- Result Matrix (Simple GEMM)
- Execution Time
- Result Matrix (Blocking GEMM)
- Execution Time

---

# Folder Structure

```text
Assignment_01/
│
└── gemm/
    ├── driver.cpp
    ├── gemm.h
    ├── gemm_src.cpp
    ├── gemm_test_01.txt
    ├── gemm_test_02.txt
    ├── gemm_test_03.txt
    ├── gemm_test_04.txt
    ├── gemm_test_05.txt
    └── README.md
```

---

# Files Description

| File | Description |
|------|-------------|
| `driver.cpp` | Reads the input test files, executes both Simple GEMM and Blocking GEMM algorithms, and measures their execution time. |
| `gemm.h` | Contains the function declarations and matrix type definition. |
| `gemm_src.cpp` | Implements both the Simple GEMM and Blocking GEMM algorithms. |
| `gemm_test_01.txt` | Test Case 1 (4 × 5 and 5 × 4 matrices). |
| `gemm_test_02.txt` | Test Case 2 (200 × 400 and 400 × 300 matrices). |
| `gemm_test_03.txt` | Test Case 3 (40 × 50 and 50 × 30 matrices). |
| `gemm_test_04.txt` | Test Case 4 (400 × 500 and 500 × 600 matrices). |
| `gemm_test_05.txt` | Test Case 5 (30 × 30 and 30 × 30 matrices). |
| `README.md` | Provides the project overview, algorithm description, compilation steps, execution instructions, file structure, and performance results. |

---

# Compilation

Using g++

```
g++ driver.cpp gemm_src.cpp -o gemm
```

---

# Execution

Run the executable

```
.\gemm.exe
```

The program displays a menu.

Choose

```
1
```

to run Test Case 1

```
2
```

to run Test Case 2

```
3
```

to run Test Case 3

```
4
```

to run Test Case 4

```
5
```

to run Test Case 5


```
6
```

to run all test cases.

---

# Time Complexity

### Simple GEMM

```
O(M × K × N)
```

### Blocking GEMM

```
O(M × K × N)
```

Although both have the same theoretical complexity, Blocking GEMM performs better in practice because of improved cache locality.

---

# Space Complexity

Simple GEMM

```
O(M × N)
```

Blocking GEMM

```
O(M × N)
```

---

## Result Table

| Test File | Input Matrix Size | Output Matrix Size | Simple GEMM Time (ms) | Blocking GEMM Time (ms) | Block Size | Status |
|-----------|-------------------|--------------------|----------------------:|------------------------:|-----------:|:------:|
| gemm_test_01.txt | 4 × 5 and 5 × 4 | 4 × 4 | 0.012000 | 0.008700 | 32 | Pass |
| gemm_test_02.txt | 200 × 400 and 400 × 300 | 200 × 300 | 378.914300 | 391.919700 | 32 | Pass |
| gemm_test_03.txt | 40 × 50 and 50 × 30 | 40 × 30 | 3.111400 | 3.138900 | 32 | Pass |
| gemm_test_04.txt | 400 × 500 and 500 × 600 | 400 × 600 | 8934.631700 | 8943.672900 | 32 | Pass |
| gemm_test_05.txt | 30 × 30 and 30 × 30 | 30 × 30 | 2.195900 | 2.174300 | 32 | Pass |





---

# Compiler

- Language : C++
- Compiler : g++

---

# References

1. geeksforgeeks.org
2. Striver DSA

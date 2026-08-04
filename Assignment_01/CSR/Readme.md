# CSR Graph Implementation

## Overview

This project implements the **Compressed Sparse Row (CSR)** representation for graphs. The program reads a graph from a text file, converts it into CSR format, and prints the `row_ptr`, `col_idx`, and `values` arrays along with the execution time.

## Compilation

```bash
g++ driver.cpp Source.cpp -o CSR
```

## Run

```bash
./CSR
```

or on Windows

```bash
CSR.exe
```

## Test Results

| Test File | Vertices | Edges | Output | Execution Time | Status |
|-----------|---------:|------:|--------|---------------:|:------:|
| csr_test_01.txt | 5 | 6 | CSR Representation | 4027 μs | Pass |
| csr_test_02.txt | 9 | 12 | CSR Representation | 10154 μs | Pass |
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
| csr_test_01.txt | 5 | 6 | CSR Representation | 4218 μs | Pass |
| csr_test_02.txt | 9 | 12 | CSR Representation | 5637 μs | Pass |
| csr_test_03.txt | 100 | 99 | CSR Representation | 1191.77 μs | Pass |

---

## Output

### csr_test_01.txt

**row_ptr**
```
0 2 4 7 9 10
```

**col_idx**
```
1 2 0 3 0 3 4 1 2 2
```

**values**
```
1 1 1 1 1 1 1 1 1 1
```

---

### csr_test_02.txt

**row_ptr**
```
0 2 2 14 15 18 18 24 24 28
```

**col_idx**
```
1 4 1 3 0 0 3 4 7 8 5 2 2 7 2 5 4 2 7 3 2 1 5 4 6 2 3 1
```

**values**
```
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
```

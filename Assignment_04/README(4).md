# Assignment 04 – PageRank and Vertex Coloring

## Submitted By

| Name | Entry Number |
|---|---|
| Mohd Shah Faaz | 2026aim1013 |

## Objective

Implementation and performance evaluation of **PageRank** and **Vertex Coloring** using CSR representation.

## Project Structure

```text
Assignment_04/
├── pagerank/
│   ├── driver.cpp
│   ├── pagerank.cpp
│   ├── pagerank.h
│   ├── input/
│   └── output/
│
├── vertex_colouring/
│   ├── driver.cpp
│   ├── vc.cpp
│   ├── vc.h
│   ├── input/
│   └── output/
│
└── ...
```

## PageRank

PageRank calculates the importance of vertices in a directed graph using a damping factor of `0.85`.

### Results

| Test Case | N | Damping | Iterations | Converged | Sum of Ranks | Execution Time |
|---|---:|---:|---:|---|---:|---:|
| `pagerank_10.txt` | 10 | 0.85 | 20 | true | 1.000000 | 0.057400 ms |
| `pagerank_100.txt` | 100 | 0.85 | 22 | true | 1.000000 | 4.759800 ms |
| `pagerank_1000.txt` | 1,000 | 0.85 | 21 | true | 1.000000 | 471.577100 ms |
| `pagerank_10000.txt` | 10,000 | 0.85 | 21 | true | 1.000000 | 52,583.362300 ms |
| `pagerank_50000.txt` | 50,000 | 0.85 | 21 | true | 1.000000 | 1,727,518.772000 ms |

## Vertex Coloring

Vertex Coloring assigns colors to vertices such that adjacent vertices have different colors using a greedy coloring approach.

### Results

| Test Case | N | Colors Used | Execution Time |
|---|---:|---:|---:|
| `color_10.txt` | 10 | 4 | 0.0057 ms |
| `color_100.txt` | 100 | 4 | 0.0614 ms |
| `color_10000.txt` | 10,000 | 5 | 4.5889 ms |
| `color_50000.txt` | 50,000 | 5 | 24.619 ms |
| `color_100000.txt` | 100,000 | 5 | 53.791 ms |

## Performance Summary

| Algorithm | Largest Input | Result |
|---|---:|---|
| PageRank | 50,000 vertices | Converged successfully |
| Vertex Coloring | 100,000 vertices | Completed using 5 colors |

CSR conversion is used as preprocessing and is excluded from the reported execution time.

## Conclusion

Both algorithms were successfully tested on graphs of increasing size. PageRank converged for all test cases with a rank sum of `1.000000`, while Vertex Coloring completed all test cases using 4–5 colors.

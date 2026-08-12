# CS509 – Assignment 02

**Name:** MOHD SHAH FAAZ  
**Entry Number:** 2026AIM1013

## Bellman-Ford and Floyd-Warshall

### Objective

Implement:
- **Bellman-Ford:** Single-source shortest path on weighted directed graphs.
- **Floyd-Warshall:** All-pairs shortest path on a weighted adjacency matrix.

## Repository Structure

```text
CS509_AIM1013/
│
├── Assignment_01/
│
├── Assignment_02/
│   │
│   ├── bellmanford/
│   │   ├── input/
│   │   ├── output/
│   │   ├── bf.cpp
│   │   ├── bf.h
│   │   ├── bf.exe
│   │   └── driver.cpp
│   │
│   ├── Floyd_warshall/
│   │   ├── input/
│   │   ├── output/
│   │   ├── fw.cpp
│   │   ├── fw.h
│   │   ├── fw.exe
│   │   └── driver.cpp
│   │
│   └── README.md
│
└── common_wrapper/

```

### Complexity

| Algorithm | Time Complexity | Space Complexity |
|---|---|---|
| Bellman-Ford | `O(VE)` | `O(V + E)` |
| Floyd-Warshall | `O(V³)` | `O(V²)` |

Bellman-Ford uses the CSR conversion from Assignment 1. The CSR conversion is preprocessing and is not included in the algorithm timing.

## Results

| Algorithm | Test File | Vertices | Edges | Source | Negative Cycle | Expected Output | Actual Output | Time | Status |
|---|---|---:|---:|---:|---|---|---|---:|---|
| Bellman-Ford | `bf_10.txt` | 10 | 18 | 0 | No | Distances | No negative cycle; distances generated | 0.0065 ms | Pass |
| Bellman-Ford | `bf_100.txt` | 100 | 300 | 0 | No | Distances | No negative cycle; distances generated | 0.0323 ms | Pass |
| Bellman-Ford | `bf_10000.txt` | 10,000 | 30,000 | 0 | Yes | Negative-cycle detection | Negative cycle detected | 10,348 ms | Pass |
| Bellman-Ford | `bf_50000.txt` | 50,000 | 150,000 | 0 | Yes | Negative-cycle detection | Negative cycle detected | 252,197 ms | Pass |
| Bellman-Ford | `bf_100000.txt` | 100,000 | 300,000 | 0 | Yes | Negative-cycle detection | Negative cycle detected | 1,579,950 ms | Pass |
| Floyd-Warshall | `fw_10.txt` | 10 | 24 | N/A | No | Distance matrix | Distance matrix; no negative cycle | 0.0138 ms | Pass |
| Floyd-Warshall | `fw_100.txt` | 100 | 294 | N/A | No | Distance matrix | Distance matrix; no negative cycle | 5.0389 ms | Pass |
| Floyd-Warshall | `fw_500.txt` | 500 | 1,494 | N/A | No | Distance matrix | Distance matrix; no negative cycle | 620.302 ms | Pass |
| Floyd-Warshall | `fw_1000.txt` | 1,000 | 2,994 | N/A | No | Distance matrix | Distance matrix; no negative cycle | 4,904.79 ms | Pass |
| Floyd-Warshall | `fw_2000.txt` | 2,000 | 5,994 | N/A | No | Distance matrix | Distance matrix; no negative cycle | 42,367.3 ms | Pass |

## Required Test Sizes

| Algorithm | Required Vertices |
|---|---|
| Bellman-Ford | 10, 100, 10,000, 50,000, 100,000 |
| Floyd-Warshall | 10, 100, 500, 1,000, 2,000 |

## Timing

Only algorithm execution time is measured. File reading, input parsing, CSR conversion, matrix construction, and output writing are excluded.

The negative-cycle check is included in the measured algorithm time.

## Compilation

### Bellman-Ford

```bash
g++ driver.cpp bf.cpp ../../Assignment_01/CSR/source.cpp -o bf.exe
bf.exe

```

### Floyd-Warshall

```bash
g++ driver.cpp fw.cpp -o fw.exe
fw.exe

```
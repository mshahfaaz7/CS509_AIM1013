# CS509 – Assignment 03

**Name:** MOHD SHAH FAAZ  
**Entry Number:** 2026AIM1013

## Prim's and Kruskal's Minimum Spanning Tree

### Objective

Implement:

- **Prim's Algorithm:** Minimum Spanning Tree on weighted undirected graphs, starting from vertex `0`.
- **Kruskal's Algorithm:** Minimum Spanning Tree using edge sorting and Disjoint Set Union (DSU).

Both algorithms use the **CSR conversion function from Assignment 1**. The CSR conversion is treated as preprocessing and is not included in the algorithm timing.

## Repository Structure

```text
CS509_AIM1013/
│
├── Assignment_01/
│
├── Assignment_02/
│
├── Assignment_03/
│   │
│   ├── driver/
│   │   ├── prims_driver.cpp
│   │   └── kruskal_driver.cpp
│   │
│   ├── input/
│   │   ├── mst_10.txt
│   │   ├── mst_100.txt
│   │   ├── mst_10000.txt
│   │   ├── mst_50000.txt
│   │   └── mst_100000.txt
│   │
│   ├── output/
│   │   ├── mst_10_prims.txt
│   │   ├── mst_100_prims.txt
│   │   ├── mst_10000_prims.txt
│   │   ├── mst_50000_prims.txt
│   │   ├── mst_100000_prims.txt
│   │   ├── mst_10_kruskal.txt
│   │   ├── mst_100_kruskal.txt
│   │   ├── mst_10000_kruskal.txt
│   │   ├── mst_50000_kruskal.txt
│   │   └── mst_100000_kruskal.txt
│   │
│   ├── src/
│   │   ├── prims.cpp
│   │   ├── prims.h
│   │   ├── kruskal.cpp
│   │   └── kruskal.h
│   │
│   └── README.md
│
└── common_wrapper/
```

## Complexity

| Algorithm | Time Complexity | Space Complexity |
|---|---|---|
| Prim's | `O((V + E) log V)` | `O(V + E)` |
| Kruskal's | `O(E log E)` | `O(V + E)` |

Prim's algorithm uses a priority queue and starts from vertex `0`.

Kruskal's algorithm sorts the edges by weight and uses a Disjoint Set Union (DSU) structure to detect cycles.

Both algorithms use the CSR conversion from Assignment 1. The CSR conversion is preprocessing and is not included in the algorithm timing.

## Results

| Algorithm | Test File | Vertices | Edges | Start Vertex | Expected Output | Actual Output | Time | Status |
|---|---|---:|---:|---:|---|---|---:|---|
| Prim's | `mst_10.txt` | 10 | 19 | 0 | MST | MST generated | 0.0269 ms | Pass |
| Prim's | `mst_100.txt` | 100 | 199 | 0 | MST | MST generated | 0.0919 ms | Pass |
| Prim's | `mst_10000.txt` | 10,000 | 29,999 | 0 | MST | MST generated | 14.5908 ms | Pass |
| Prim's | `mst_50000.txt` | 50,000 | 99,999 | 0 | MST | MST generated | 75.5906 ms | Pass |
| Prim's | `mst_100000.txt` | 100,000 | 199,999 | 0 | MST | MST generated | 138.779 ms | Pass |
| Kruskal's | `mst_10.txt` | 10 | 19 | N/A | MST | MST generated | 0.0159 ms | Pass |
| Kruskal's | `mst_100.txt` | 100 | 199 | N/A | MST | MST generated | 0.0578 ms | Pass |
| Kruskal's | `mst_10000.txt` | 10,000 | 29,999 | N/A | MST | MST generated | 11.112 ms | Pass |
| Kruskal's | `mst_50000.txt` | 50,000 | 99,999 | N/A | MST | MST generated | 31.7853 ms | Pass |
| Kruskal's | `mst_100000.txt` | 100,000 | 199,999 | N/A | MST | MST generated | 59.6847 ms | Pass |

## Required Test Sizes

| Algorithm | Required Vertices |
|---|---|
| Prim's | 10, 100, 10,000, 50,000, 100,000 |
| Kruskal's | 10, 100, 10,000, 50,000, 100,000 |

The MST test graphs are connected weighted undirected graphs. Each undirected edge appears in the adjacency list of both endpoint vertices.

## Input Format

The input graphs are provided in adjacency-list format.

The first line contains:

```text
V E
```

where:

- `V` = number of vertices
- `E` = number of undirected edges

Each following line contains:

```text
vertex degree neighbor weight neighbor weight ...
```

For example:

```text
5 7
0 2 1 2 3 6
1 4 0 2 2 3 3 8 4 5
2 2 1 3 4 7
3 3 0 6 1 8 4 9
4 3 1 5 2 7 3 9
```

The same input files are used for both Prim's and Kruskal's algorithms.

## Timing

Only algorithm execution time is measured.

File reading, input parsing, adjacency-list construction, CSR conversion, and output writing are excluded from the measured time.

For **Prim's**, the timed section contains the execution of Prim's algorithm using the prepared CSR representation.

For **Kruskal's**, CSR-to-edge extraction, edge sorting, DSU operations, and MST construction are included in the measured algorithm time.

## Compilation

### Prim's

From the `Assignment_03` directory:

```bash
g++ driver/prims_driver.cpp src/prims.cpp ../Assignment_01/CSR/source.cpp -o prims.exe
```

Run:

```bash
./prims.exe
```

On Windows PowerShell:

```powershell
.\prims.exe
```

### Kruskal's

From the `Assignment_03` directory:

```bash
g++ driver/kruskal_driver.cpp src/kruskal.cpp ../Assignment_01/CSR/source.cpp -o krus.exe
```

Run:

```bash
./krus.exe
```

On Windows PowerShell:

```powershell
.\krus.exe
```

## Common Wrapper

Assignment 03 is also accessible through the CS509 Laboratory Common Wrapper.

The Assignment 03 menu contains:

```text
========== Assignment 03 ==========
1. Prim's
2. Kruskal
0. Back
```

Selecting `Prim's` launches the Prim's driver.

Selecting `Kruskal` launches the Kruskal driver.

Selecting `Back` returns to the main wrapper menu.
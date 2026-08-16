#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "../../Assignment_01/CSR/csr.h"
#include <vector>

using namespace std;

struct Edge
{
    int u;
    int v;
    int weight;
};

struct MSTResult
{
    vector<Edge> edges;
    long long totalWeight;
};

MSTResult kruskal(
    int V,
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    const vector<int>& values
);
#endif
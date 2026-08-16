#ifndef PRIMS_H
#define PRIMS_H

#include "../../Assignment_01/CSR/csr.h"
#include <vector>

using namespace std;

struct PrimEdge
{
    int u;
    int v;
    int weight;
};

struct PrimResult
{
    vector<PrimEdge> edges;
    long long totalWeight;
};
PrimResult prims(
    int V,
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    const vector<int>& values
);

#endif
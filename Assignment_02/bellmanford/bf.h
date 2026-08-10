#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include <vector>

using namespace std;

bool bellmanFord(
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    const vector<int>& values,
    int V,
    int source,
    vector<int>& distance
);

#endif
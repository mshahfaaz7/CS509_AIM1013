#ifndef CSR_H
#define CSR_H

#include <vector>

using namespace std;

void convertToCSR(
    const vector<vector<int>>& adjList,
    vector<int>& row_ptr,
    vector<int>& col_idx
);

void printCSR(
    const vector<int>& row_ptr,
    const vector<int>& col_idx
);

#endif
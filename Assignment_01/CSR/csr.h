#ifndef CSR_H
#define CSR_H

#include <vector>
#include <utility>

using namespace std;

void convertToCSR(
    const vector<vector<pair<int, double>>>& adjList,
    vector<int>& row_ptr,
    vector<int>& col_idx,
    vector<double>& values
);

void printCSR(
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    const vector<double>& values
);

#endif
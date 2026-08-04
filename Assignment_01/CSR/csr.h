#ifndef CSR_H
#define CSR_H

#include <iostream>
#include <vector>

using namespace std;

void convertToCSR(
    const vector<vector<pair<int, int>>> &adjList,
    vector<int> &row_ptr,
    vector<int> &col_idx,
    vector<int> &values
);

void printCSR(
    const vector<int> &row_ptr,
    const vector<int> &col_idx,
    const vector<int> &values
);

#endif
#ifndef PAGERANK_H
#define PAGERANK_H

#include <vector>

using namespace std;

void pageRank(
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    double damping,
    double tolerance,
    int maxIterations,
    vector<double>& ranks,
    int& iterations,
    bool& converged
);

#endif
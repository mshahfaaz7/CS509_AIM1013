#ifndef VC_H
#define VC_H

#include <vector>

using namespace std;

void vertexColoring(
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    vector<int>& colors,
    int& numColors
);

bool checkColoring(
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    const vector<int>& colors
);

#endif
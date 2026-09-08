#include "csr.h"

using namespace std;

void convertToCSR(
    const vector<vector<int>>& adjList,
    vector<int>& row_ptr,
    vector<int>& col_idx)
{
    int V = adjList.size();

    row_ptr.clear();
    col_idx.clear();

    row_ptr.push_back(0);

    for (int i = 0; i < V; i++)
    {
        for (int neighbour : adjList[i])
        {
            col_idx.push_back(neighbour);
        }

        row_ptr.push_back(col_idx.size());
    }
}
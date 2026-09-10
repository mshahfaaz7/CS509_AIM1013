#include "csr.h"
#include <iostream>

using namespace std;

void convertToCSR(
    const vector<vector<pair<int, double>>>& adjList,
    vector<int>& row_ptr,
    vector<int>& col_idx,
    vector<double>& values)
{
    int V = adjList.size();

    row_ptr.clear();
    col_idx.clear();
    values.clear();

    row_ptr.push_back(0);

    for (int i = 0; i < V; i++)
    {
        for (auto edge : adjList[i])
        {
            col_idx.push_back(edge.first);
            values.push_back(edge.second);
        }

        row_ptr.push_back(col_idx.size());
    }
}

void printCSR(
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    const vector<double>& values)
{
    cout << "\nRow Pointer:\n";

    for (int x : row_ptr)
        cout << x << " ";

    cout << "\n\nColumn Index:\n";

    for (int x : col_idx)
        cout << x << " ";

    cout << "\n\nValues:\n";

    for (double x : values)
        cout << x << " ";

    cout << endl;
}
#include "csr.h"

using namespace std;

void convertToCSR(
    const vector<vector<pair<int, int>>> &adjList,
    vector<int> &row_ptr,
    vector<int> &col_idx,
    vector<int> &values)
{
    int V = adjList.size();

    row_ptr.clear();
    col_idx.clear();
    values.clear();

    row_ptr.push_back(0);

    for (int i = 0; i < V; i++)
    {
        for (const auto &edge : adjList[i])
        {
            col_idx.push_back(edge.first);   // Destination vertex
            values.push_back(edge.second);   // Edge weight
        }

        row_ptr.push_back(col_idx.size());
    }
}

// Print CSR arrays
void printCSR(
    const vector<int> &row_ptr,
    const vector<int> &col_idx,
    const vector<int> &values)
{
    cout << "\nCSR Representation\n";

    cout << "\nrow_ptr:\n";
    for (int x : row_ptr)
        cout << x << " ";
    cout << endl;

    cout << "\ncol_idx:\n";
    for (int x : col_idx)
        cout << x << " ";
    cout << endl;

    cout << "\nvalues:\n";
    for (int x : values)
        cout << x << " ";
    cout << endl;
}
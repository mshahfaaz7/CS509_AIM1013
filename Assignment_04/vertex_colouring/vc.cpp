#include "vc.h"
#include <algorithm>

using namespace std;

void vertexColoring(
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    vector<int>& colors,
    int& numColors)
{
    int V = row_ptr.size() - 1;

    colors.assign(V, -1);
    numColors = 0;

    vector<int> degree(V);

    for (int v = 0; v < V; v++)
    {
        degree[v] = row_ptr[v + 1] - row_ptr[v];
    }

    vector<int> order(V);

    for (int v = 0; v < V; v++)
    {
        order[v] = v;
    }

    sort(order.begin(), order.end(),
        [&](int a, int b)
        {
            if (degree[a] != degree[b])
                return degree[a] > degree[b];

            return a < b;
        });

    vector<int> used(V, -1);

    for (int v : order)
    {
        for (int i = row_ptr[v]; i < row_ptr[v + 1]; i++)
        {
            int neighbour = col_idx[i];

            if (colors[neighbour] != -1)
            {
                used[colors[neighbour]] = v;
            }
        }

        int color = 0;

        while (color < V && used[color] == v)
        {
            color++;
        }

        colors[v] = color;

        if (color + 1 > numColors)
        {
            numColors = color + 1;
        }
    }
}

bool checkColoring(
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    const vector<int>& colors)
{
    int V = row_ptr.size() - 1;

    if (colors.size() != V)
        return false;

    for (int v = 0; v < V; v++)
    {
        for (int i = row_ptr[v]; i < row_ptr[v + 1]; i++)
        {
            int neighbour = col_idx[i];

            if (colors[v] == colors[neighbour])
            {
                return false;
            }
        }
    }

    return true;
}
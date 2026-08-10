#include "bf.h"

#include <climits>

using namespace std;

bool bellmanFord(
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    const vector<int>& values,
    int V,
    int source,
    vector<int>& distance)
{
    distance.assign(V, INT_MAX);
    distance[source] = 0;

    
    for (int i = 0; i < V - 1; i++)
    {
        bool updated = false;

        for (int u = 0; u < V; u++)
        {
            for (int j = row_ptr[u]; j < row_ptr[u + 1]; j++)
            {
                int v = col_idx[j];
                int weight = values[j];

                if (distance[u] != INT_MAX &&
                    distance[u] + weight < distance[v])
                {
                    distance[v] = distance[u] + weight;
                    updated = true;
                }
            }
        }

        
        if (!updated)
            break;
    }

    
    for (int u = 0; u < V; u++)
    {
        for (int j = row_ptr[u]; j < row_ptr[u + 1]; j++)
        {
            int v = col_idx[j];
            int weight = values[j];

            if (distance[u] != INT_MAX &&
                distance[u] + weight < distance[v])
            {
                return false;
            }
        }
    }

    return true;
}
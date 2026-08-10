#include "fw.h"

#include <climits>

using namespace std;

bool floydWarshall(vector<vector<int>> &dist)
{
    int V = dist.size();

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            if (dist[i][k] == INT_MAX)
                continue;

            for (int j = 0; j < V; j++)
            {
                if (dist[k][j] == INT_MAX)
                    continue;

                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (dist[i][i] < 0)
            return false;
    }

    return true;
}
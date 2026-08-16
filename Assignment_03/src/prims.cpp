#include "prims.h"

#include <queue>
#include <limits>

using namespace std;

PrimResult prims(
    int V,
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    const vector<int>& values
)
{
    PrimResult result;
    result.totalWeight = 0;

    vector<bool> inMST(V, false);

    vector<int> key(V, numeric_limits<int>::max());
    vector<int> parent(V, -1);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u])
        {
            continue;
        }

        inMST[u] = true;

        if (parent[u] != -1)
        {
            result.edges.push_back(
                {parent[u], u, key[u]}
            );

            result.totalWeight += key[u];
        }

        for (int i = row_ptr[u]; i < row_ptr[u + 1]; i++)
        {
            int v = col_idx[i];
            int weight = values[i];

            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                parent[v] = u;

                pq.push({key[v], v});
            }
        }
    }

    return result;
}
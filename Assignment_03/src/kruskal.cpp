#include "kruskal.h"

#include <algorithm>
#include <numeric>

using namespace std;

class DSU
{
private:
    vector<int> parent;
    vector<int> rankValue;

public:
    DSU(int n)
    {
        parent.resize(n);
        rankValue.resize(n, 0);

        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    bool unite(int a, int b)
    {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB)
        {
            return false;
        }

        if (rankValue[rootA] < rankValue[rootB])
        {
            parent[rootA] = rootB;
        }
        else if (rankValue[rootA] > rankValue[rootB])
        {
            parent[rootB] = rootA;
        }
        else
        {
            parent[rootB] = rootA;
            rankValue[rootA]++;
        }

        return true;
    }
};

MSTResult kruskal(
    int V,
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    const vector<int>& values
)
{
    MSTResult result;
    result.totalWeight = 0;

    vector<Edge> edges;

    for (int u = 0; u < V; u++)
    {
        for (int i = row_ptr[u]; i < row_ptr[u + 1]; i++)
        {
            int v = col_idx[i];
            int weight = values[i];

            if (u < v)
            {
                edges.push_back({u, v, weight});
            }
        }
    }

    sort(
        edges.begin(),
        edges.end(),
        [](const Edge& a, const Edge& b)
        {
            return a.weight < b.weight;
        }
    );

    DSU dsu(V);

    for (const Edge& edge : edges)
    {
        if (dsu.unite(edge.u, edge.v))
        {
            result.edges.push_back(edge);
            result.totalWeight += edge.weight;

            if (result.edges.size() == V - 1)
            {
                break;
            }
        }
    }

    return result;
}
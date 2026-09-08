#include "pagerank.h"

#include <cmath>

using namespace std;

void pageRank(
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    double damping,
    double tolerance,
    int maxIterations,
    vector<double>& ranks,
    int& iterations,
    bool& converged)
{
    int V = row_ptr.size() - 1;

    ranks.assign(V, 1.0 / V);

    vector<double> newRanks(V);

    iterations = 0;
    converged = false;

    for (int iter = 1; iter <= maxIterations; iter++)
    {
        double danglingRank = 0.0;

        for (int u = 0; u < V; u++)
        {
            int outDegree = row_ptr[u + 1] - row_ptr[u];

            if (outDegree == 0)
            {
                danglingRank += ranks[u];
            }
        }

        double danglingContribution =
            danglingRank / V;

        for (int v = 0; v < V; v++)
        {
            double rank =
                (1.0 - damping) / V;

            rank += damping * danglingContribution;

            for (int u = 0; u < V; u++)
            {
                int start = row_ptr[u];
                int end = row_ptr[u + 1];

                int outDegree = end - start;

                if (outDegree == 0)
                    continue;

                for (int i = start; i < end; i++)
                {
                    if (col_idx[i] == v)
                    {
                        rank +=
                            damping *
                            ranks[u] /
                            outDegree;
                    }
                }
            }

            newRanks[v] = rank;
        }

        double change = 0.0;

        for (int v = 0; v < V; v++)
        {
            change +=
                abs(newRanks[v] - ranks[v]);
        }

        ranks = newRanks;

        iterations = iter;

        if (change <= tolerance)
        {
            converged = true;
            break;
        }
    }
}
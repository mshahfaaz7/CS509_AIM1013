#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

#include "csr.h"

using namespace std;
using namespace chrono;

int main()
{
    while (true)
    {
        string filename;

        cout << "\nEnter input file name (or 'exit' to quit): ";
        cin >> filename;

        if (filename == "exit")
            break;

        ifstream fin(filename);

        if (!fin)
        {
            fin.open("Assignment_01/CSR/" + filename);
        }

        if (!fin)
        {
            cout << "\nError: Cannot open input file.\n";
            continue;
        }

        int V, E;
        fin >> V >> E;

        cout << "V = " << V << " E = " << E << endl;

        // Unweighted graph:
        // Only store neighbour, no weight
        vector<vector<int>> adjList(V);

        for (int i = 0; i < V; i++)
        {
            int vertex, degree;
            fin >> vertex >> degree;

            cout << "Vertex = " << vertex
                 << " Degree = " << degree << endl;

            if (vertex < 0 || vertex >= V)
            {
                cout << "ERROR: Invalid vertex " << vertex << endl;
                return 0;
            }

            for (int j = 0; j < degree; j++)
            {
                int neighbour;
                fin >> neighbour;

                cout << "   Edge : "
                     << vertex << " -> "
                     << neighbour << endl;

                if (neighbour < 0 || neighbour >= V)
                {
                    cout << "ERROR: Invalid neighbour "
                         << neighbour << endl;
                    return 0;
                }

                // Add edge in both directions
                adjList[vertex].push_back(neighbour);
                adjList[neighbour].push_back(vertex);
            }
        }

        fin.close();

        vector<int> row_ptr;
        vector<int> col_idx;

        convertToCSR(adjList, row_ptr, col_idx);

        auto start = high_resolution_clock::now();

        printCSR(row_ptr, col_idx);

        auto stop = high_resolution_clock::now();

        double execTime =
            duration<double, milli>(stop - start).count();

        cout << "\nExecution Time : "
             << execTime << " ms\n";
    }

    return 0;
}
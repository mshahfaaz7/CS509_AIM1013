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

        vector<vector<pair<int, int>>> adjList(V);

        for (int i = 0; i < V; i++)
        {
            int vertex, degree;
            fin >> vertex >> degree;

            cout << "Vertex = " << vertex
                << " Degree = " << degree << endl;

            if(vertex < 0 || vertex >= V)
            {
                cout << "ERROR: Invalid vertex " << vertex << endl;
                return 0;
            }

            for (int j = 0; j < degree; j++)
            {
                int neighbour, weight;
                fin >> neighbour >> weight;

                cout << "   Edge : "
                    << vertex << " -> "
                    << neighbour
                    << " Weight = "
                    << weight << endl;

                if(neighbour < 0 || neighbour >= V)
                {
                    cout << "ERROR: Invalid neighbour "
                        << neighbour << endl;
                    return 0;
                }

                adjList[vertex].push_back({neighbour, weight});
            }
        }

        string temp;
        if (fin >> temp)
        {
            if (temp == "SOURCE")
            {
                int source;
                fin >> source;
            }
        }

        fin.close();

        vector<int> row_ptr;
        vector<int> col_idx;
        vector<int> values;

        
        convertToCSR(adjList, row_ptr, col_idx, values);

        auto start = high_resolution_clock::now();

        printCSR(row_ptr, col_idx, values);

        auto stop = high_resolution_clock::now();

        double execTime =
            duration<double, milli>(stop - start).count();

        cout << "\nExecution Time : "
             << execTime << " ms\n";
    }

    return 0;
}

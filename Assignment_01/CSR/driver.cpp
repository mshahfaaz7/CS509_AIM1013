#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "csr.h"

using namespace std;
using namespace std::chrono;

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
            cout << "Error: Cannot open input file.\n";
            continue;
        }

        int V, E;
        fin >> V >> E;

        vector<vector<pair<int, int>>> adjList(V);

        for (int i = 0; i < V; i++)
        {
            int vertex, degree;
            fin >> vertex >> degree;

            for (int j = 0; j < degree; j++)
            {
                int neighbour;
                fin >> neighbour;
                adjList[vertex].push_back({neighbour, 1});
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

        auto duration = duration_cast<microseconds>(stop - start);

        cout << "\nExecution Time: " << duration.count() << " microseconds\n";
    }

    return 0;
}

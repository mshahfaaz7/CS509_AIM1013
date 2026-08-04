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

        // If running from the common wrapper, try the repository path
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

        // Conversion is outside the timed region
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

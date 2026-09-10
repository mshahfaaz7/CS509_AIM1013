#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string>

#include "csr.h"

using namespace std;

void readGraph(
    const string& filename,
    int type,
    vector<vector<pair<int, double>>>& adjList,
    int& V,
    int& E)
{
    ifstream fin(filename);

    if (!fin)
    {
        cout << "Error: Cannot open input file.\n";
        return;
    }

    fin >> V >> E;

    adjList.resize(V);

    bool weighted = (type == 3 || type == 4);
    bool undirected = (type == 2 || type == 4);

    for (int i = 0; i < V; i++)
    {
        int vertex, degree;
        fin >> vertex >> degree;

        if (vertex < 0 || vertex >= V)
        {
            cout << "Error: Invalid vertex " << vertex << endl;
            return;
        }

        for (int j = 0; j < degree; j++)
        {
            int neighbour;
            double weight = 1.0;

            fin >> neighbour;

            if (weighted)
                fin >> weight;

            if (neighbour < 0 || neighbour >= V)
            {
                cout << "Error: Invalid neighbour "
                     << neighbour << endl;
                return;
            }

            adjList[vertex].push_back({neighbour, weight});

            if (undirected)
            {
                adjList[neighbour].push_back({vertex, weight});
            }
        }
    }

    fin.close();
}

int main()
{
    while (true)
    {
        cout << "\n====================================\n";
        cout << "          CSR Conversion\n";
        cout << "====================================\n";
        cout << "1. Unweighted Directed\n";
        cout << "2. Unweighted Undirected\n";
        cout << "3. Weighted Directed\n";
        cout << "4. Weighted Undirected\n";
        cout << "0. Exit\n";

        int choice;

        cout << "\nEnter Choice : ";
        cin >> choice;

        if (choice == 0)
            break;

        if (choice < 1 || choice > 4)
        {
            cout << "Invalid Choice\n";
            continue;
        }

        string filename;

        cout << "Enter input file name : ";
        cin >> filename;

        vector<vector<pair<int, double>>> adjList;

        int V, E;

        readGraph(
            filename,
            choice,
            adjList,
            V,
            E
        );

        if (adjList.empty())
            continue;

        vector<int> row_ptr;
        vector<int> col_idx;
        vector<double> values;

        convertToCSR(
            adjList,
            row_ptr,
            col_idx,
            values
        );

        cout << "\n====================================\n";
        cout << "              CSR\n";
        cout << "====================================\n";

        cout << "\nVertices : " << V << endl;
        cout << "Edges    : " << E << endl;

        printCSR(
            row_ptr,
            col_idx,
            values
        );
    }

    return 0;
}
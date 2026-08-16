#include "../src/kruskal.h"
#include "../../Assignment_01/CSR/csr.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <chrono>
#include <string>

using namespace std;

bool runKruskal(const string& inputFile, const string& outputFile)
{
    ifstream input(inputFile);

    if (!input)
    {
        cout << "Error: Cannot open input file: "
             << inputFile << endl;
        return false;
    }

    int V, E;

    input >> V >> E;

    vector<vector<pair<int, int>>> adjList(V);

    for (int i = 0; i < V; i++)
    {
        int u, degree;

        input >> u >> degree;

        for (int j = 0; j < degree; j++)
        {
            int v, weight;

            input >> v >> weight;

            adjList[u].push_back({v, weight});
        }
    }

    input.close();

    vector<int> row_ptr;
    vector<int> col_idx;
    vector<int> values;

    convertToCSR(
        adjList,
        row_ptr,
        col_idx,
        values
    );

    auto start = chrono::high_resolution_clock::now();

    MSTResult result = kruskal(
        V,
        row_ptr,
        col_idx,
        values
    );

    auto end = chrono::high_resolution_clock::now();

    double executionTime =
        chrono::duration<double, milli>(end - start).count();

    ofstream output(outputFile);

    if (!output)
    {
        cout << "Error: Cannot create output file: "
             << outputFile << endl;
        return false;
    }

    output << "Algorithm: Kruskal's MST" << endl;
    output << "MST edges:" << endl;

    for (const Edge& edge : result.edges)
    {
        output << edge.u << " "
               << edge.v << " "
               << edge.weight << endl;
    }

    output << endl;

    output << "Total MST weight: "
           << result.totalWeight << endl;

    output << "Execution time: "
           << executionTime
           << " ms" << endl;

    output.close();

    cout << "Execution time: "
         << executionTime
         << " ms" << endl;

    cout << "Output file: "
         << outputFile << endl;

    return true;
}

int main()
{
    int choice;

    const string inputFiles[] =
    {
        "input/mst_10.txt",
        "input/mst_100.txt",
        "input/mst_10000.txt",
        "input/mst_50000.txt",
        "input/mst_100000.txt"
    };

    const string outputFiles[] =
    {
        "output/mst_10_kruskal.txt",
        "output/mst_100_kruskal.txt",
        "output/mst_10000_kruskal.txt",
        "output/mst_50000_kruskal.txt",
        "output/mst_100000_kruskal.txt"
    };

    while (true)
    {
        cout << endl;
        cout << "========== Kruskal's MST ==========" << endl;
        cout << "1. mst_10.txt" << endl;
        cout << "2. mst_100.txt" << endl;
        cout << "3. mst_10000.txt" << endl;
        cout << "4. mst_50000.txt" << endl;
        cout << "5. mst_100000.txt" << endl;
        cout << "6. Run All" << endl;
        cout << "0. Exit" << endl;
        cout << endl;
        cout << "Enter Choice : ";

        cin >> choice;

        if (choice == 0)
        {
            cout << "Exiting..." << endl;
            break;
        }

        if (choice >= 1 && choice <= 5)
        {
            cout << endl;
            cout << "Running "
                 << inputFiles[choice - 1]
                 << " ..." << endl;

            runKruskal(
                inputFiles[choice - 1],
                outputFiles[choice - 1]
            );
        }
        else if (choice == 6)
        {
            cout << endl;
            cout << "========== Running All Tests ==========" << endl;

            for (int i = 0; i < 5; i++)
            {
                cout << endl;
                cout << "Running "
                     << inputFiles[i]
                     << " ..." << endl;

                runKruskal(
                    inputFiles[i],
                    outputFiles[i]
                );
            }

            cout << endl;
            cout << "========== All Tests Completed ==========" << endl;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
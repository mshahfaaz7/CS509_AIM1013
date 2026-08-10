#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <climits>

#include "fw.h"

using namespace std;
using namespace chrono;

const int INF = INT_MAX;

void runFloydWarshall(string inputFile, string outputFile)
{
    ifstream fin(inputFile);

    if (!fin)
    {
        cout << "Cannot open " << inputFile << endl;
        return;
    }

    int V;
    fin >> V;

    vector<vector<int>> dist(V, vector<int>(V));

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            string x;
            fin >> x;

            if (x == "INF")
                dist[i][j] = INF;
            else
                dist[i][j] = stoi(x);
        }
    }

    fin.close();

    auto start = high_resolution_clock::now();

    bool ok = floydWarshall(dist);

    auto stop = high_resolution_clock::now();

    double execTime =
        duration<double, milli>(stop - start).count();

    ofstream fout(outputFile);

    if (!fout)
    {
        cout << "Cannot create output file.\n";
        return;
    }

    fout << "Algorithm : Floyd-Warshall\n\n";

    if (!ok)
    {
        fout << "Negative cycle : true\n";
    }
    else
    {
        fout << "Distance matrix:\n";

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][j] == INF)
                    fout << "INF";
                else
                    fout << dist[i][j];

                if (j < V - 1)
                    fout << " ";
            }

            fout << "\n";
        }

        fout << "\nNegative cycle : none\n";
    }

    fout << "Execution time: "
         << execTime
         << " ms\n";

    fout.close();

    cout << inputFile
         << " --> "
         << execTime
         << " ms"
         << endl;
}

int main()
{
    while (true)
    {
        cout << "\n========== Floyd-Warshall ==========\n";
        cout << "1. fw_10.txt\n";
        cout << "2. fw_100.txt\n";
        cout << "3. fw_500.txt\n";
        cout << "4. fw_1000.txt\n";
        cout << "5. fw_2000.txt\n";
        cout << "6. Run All\n";
        cout << "0. Exit\n";

        int choice;

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            runFloydWarshall(
                "input/fw_10.txt",
                "output/output_fw_10.txt"
            );
            break;

        case 2:
            runFloydWarshall(
                "input/fw_100.txt",
                "output/output_fw_100.txt"
            );
            break;

        case 3:
            runFloydWarshall(
                "input/fw_500.txt",
                "output/output_fw_500.txt"
            );
            break;

        case 4:
            runFloydWarshall(
                "input/fw_1000.txt",
                "output/output_fw_1000.txt"
            );
            break;

        case 5:
            runFloydWarshall(
                "input/fw_2000.txt",
                "output/output_fw_2000.txt"
            );
            break;

        case 6:
            runFloydWarshall(
                "input/fw_10.txt",
                "output/output_fw_10.txt"
            );

            runFloydWarshall(
                "input/fw_100.txt",
                "output/output_fw_100.txt"
            );

            runFloydWarshall(
                "input/fw_500.txt",
                "output/output_fw_500.txt"
            );

            runFloydWarshall(
                "input/fw_1000.txt",
                "output/output_fw_1000.txt"
            );

            runFloydWarshall(
                "input/fw_2000.txt",
                "output/output_fw_2000.txt"
            );
            break;

        case 0:
            return 0;

        default:
            cout << "Invalid Choice\n";
        }
    }

    return 0;
}
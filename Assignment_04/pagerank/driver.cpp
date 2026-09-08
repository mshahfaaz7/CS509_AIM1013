#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <filesystem>
#include <iomanip>

#include "../../Assignment_01/CSR/csr.h"
#include "pagerank.h"

using namespace std;
using namespace chrono;
namespace fs = filesystem;

void runFile(const string& filename)
{
    string inputPath = "input/" + filename;

    ifstream fin(inputPath);

    if (!fin)
    {
        cout << "Error: Cannot open " << inputPath << endl;
        return;
    }

    int V, E;

    if (!(fin >> V >> E))
    {
        cout << "Error: Invalid input file.\n";
        return;
    }

    if (V <= 0 || E < 0)
    {
        cout << "Error: Invalid number of vertices or edges.\n";
        return;
    }

    vector<vector<int>> adjList(V);

    bool valid = true;

    for (int i = 0; i < V; i++)
    {
        int vertex;
        int outDegree;

        if (!(fin >> vertex >> outDegree))
        {
            cout << "Error: Invalid vertex data.\n";
            valid = false;
            break;
        }

        if (vertex < 0 || vertex >= V)
        {
            cout << "Error: Vertex out of range.\n";
            valid = false;
            break;
        }

        if (outDegree < 0)
        {
            cout << "Error: Invalid outdegree.\n";
            valid = false;
            break;
        }

        for (int j = 0; j < outDegree; j++)
        {
            int neighbour;

            if (!(fin >> neighbour))
            {
                cout << "Error: Mismatched outdegree/neighbour count.\n";
                valid = false;
                break;
            }

            if (neighbour < 0 || neighbour >= V)
            {
                cout << "Error: Neighbour out of range.\n";
                valid = false;
                break;
            }

            if (vertex == neighbour)
            {
                cout << "Error: Self-loop detected.\n";
                valid = false;
                break;
            }

            adjList[vertex].push_back(neighbour);
        }

        if (!valid)
            break;
    }

    if (!valid)
    {
        fin.close();
        return;
    }

    string label;
    double damping;
    double tolerance;
    int maxIterations;

    if (!(fin >> label >> damping) || label != "DAMPING")
    {
        cout << "Error: Invalid DAMPING parameter.\n";
        fin.close();
        return;
    }

    if (!(fin >> label >> tolerance) || label != "TOLERANCE")
    {
        cout << "Error: Invalid TOLERANCE parameter.\n";
        fin.close();
        return;
    }

    if (!(fin >> label >> maxIterations) ||
        label != "MAX_ITERATIONS")
    {
        cout << "Error: Invalid MAX_ITERATIONS parameter.\n";
        fin.close();
        return;
    }

    fin.close();

    if (damping <= 0.0 || damping >= 1.0)
    {
        cout << "Error: Damping must be greater than 0 and less than 1.\n";
        return;
    }

    if (tolerance <= 0.0)
    {
        cout << "Error: Tolerance must be positive.\n";
        return;
    }

    if (maxIterations <= 0)
    {
        cout << "Error: MAX_ITERATIONS must be positive.\n";
        return;
    }

    vector<int> row_ptr;
    vector<int> col_idx;

    convertToCSR(
        adjList,
        row_ptr,
        col_idx
    );

    vector<double> ranks;
    int iterations;
    bool converged;

    auto start = high_resolution_clock::now();

    pageRank(
        row_ptr,
        col_idx,
        damping,
        tolerance,
        maxIterations,
        ranks,
        iterations,
        converged
    );

    auto stop = high_resolution_clock::now();

    double executionTime =
        duration<double, milli>(
            stop - start
        ).count();

    fs::create_directories("output");

    string outputPath = "output/" + filename;

    ofstream fout(outputPath);

    if (!fout)
    {
        cout << "Error: Cannot create output file.\n";
        return;
    }

    fout << fixed << setprecision(6);

    fout << "Algorithm: PageRank\n";
    fout << "Damping: " << damping << "\n";
    fout << "Vertex ranks:\n";

    double sum = 0.0;

    for (int v = 0; v < V; v++)
    {
        fout << v << " " << ranks[v] << "\n";
        sum += ranks[v];
    }

    fout << "Sum of ranks: "
         << sum << "\n";

    fout << "Iterations: "
         << iterations << "\n";

    fout << "Converged: "
         << (converged ? "true" : "false")
         << "\n";

    fout << "Execution time: "
         << executionTime
         << " ms\n";

    fout.close();

    cout << "\nCompleted: " << filename << endl;
    cout << "Output: " << outputPath << endl;
}

int main()
{
    vector<string> files =
    {
        "pagerank_10.txt",
        "pagerank_100.txt",
        "pagerank_1000.txt",
        "pagerank_10000.txt",
        "pagerank_50000.txt"
    };

    while (true)
    {
        cout << "\nPageRank\n";
        cout << "1. " << files[0] << endl;
        cout << "2. " << files[1] << endl;
        cout << "3. " << files[2] << endl;
        cout << "4. " << files[3] << endl;
        cout << "5. " << files[4] << endl;
        cout << "6. Run all" << endl;
        cout << "7. Exit" << endl;

        cout << "\nEnter your choice: ";

        int choice;
        cin >> choice;

        if (choice >= 1 && choice <= 5)
        {
            runFile(files[choice - 1]);
        }
        else if (choice == 6)
        {
            cout << "\nRunning all files...\n";

            for (const string& file : files)
            {
                runFile(file);
            }

            cout << "\nAll files completed.\n";
        }
        else if (choice == 7)
        {
            break;
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
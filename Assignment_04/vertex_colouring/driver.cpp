#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <filesystem>

#include "../../Assignment_01/CSR/csr.h"
#include "vc.h"

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
        int vertex, degree;

        if (!(fin >> vertex >> degree))
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

        if (degree < 0)
        {
            cout << "Error: Invalid degree.\n";
            valid = false;
            break;
        }

        for (int j = 0; j < degree; j++)
        {
            int neighbour;

            if (!(fin >> neighbour))
            {
                cout << "Error: Mismatched degree/neighbour count.\n";
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

    fin.close();

    if (!valid)
        return;

    vector<int> row_ptr;
    vector<int> col_idx;

    convertToCSR(
        adjList,
        row_ptr,
        col_idx
    );

    vector<int> colors;
    int numColors;

    auto start = high_resolution_clock::now();

    vertexColoring(
        row_ptr,
        col_idx,
        colors,
        numColors
    );

    auto stop = high_resolution_clock::now();

    double executionTime =
        duration<double, milli>(
            stop - start
        ).count();

    bool validColoring =
        checkColoring(
            row_ptr,
            col_idx,
            colors
        );

    fs::create_directories("output");

    string outputPath = "output/" + filename;

    ofstream fout(outputPath);

    if (!fout)
    {
        cout << "Error: Cannot create output file.\n";
        return;
    }

    fout << "Algorithm: Greedy Vertex Coloring\n";
    fout << "Vertex colors:\n";

    for (int v = 0; v < V; v++)
    {
        fout << v << " " << colors[v] << "\n";
    }

    fout << "Colors used: "
         << numColors << "\n";

    fout << "Execution time: "
         << executionTime
         << " ms\n";

    fout.close();

    cout << "\nCompleted: " << filename << endl;
    cout << "Valid coloring: "
         << (validColoring ? "Yes" : "No") << endl;
    cout << "Output: " << outputPath << endl;
}

int main()
{
    vector<string> files =
    {
        "color_10.txt",
        "color_100.txt",
        "color_10000.txt",
        "color_50000.txt",
        "color_100000.txt"
    };

    while (true)
    {
        cout << "\nVertex Coloring\n";
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
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <climits>

#include "bf.h"
#include "../../Assignment_01/CSR/csr.h"

using namespace std;
using namespace chrono;

void runBellmanFord(string inputFile, string outputFile)
{
    ifstream fin(inputFile);

    if (!fin)
    {
        cout << "\nCannot open " << inputFile << endl;
        return;
    }

    int V, E;
    fin >> V >> E;

    vector<vector<pair<int,int>>> adjList(V);

    for(int i=0;i<V;i++)
    {
        int vertex, degree;
        fin >> vertex >> degree;

        for(int j=0;j<degree;j++)
        {
            int neighbour, weight;
            fin >> neighbour >> weight;

            adjList[vertex].push_back({neighbour, weight});
        }
    }

    string temp;
    int source;

    fin >> temp >> source;

    fin.close();

    vector<int> row_ptr;
    vector<int> col_idx;
    vector<int> values;

    // CSR conversion (NOT TIMED)
    convertToCSR(adjList,row_ptr,col_idx,values);

    vector<int> distance;

    auto start = high_resolution_clock::now();

    bool ok = bellmanFord(
                    row_ptr,
                    col_idx,
                    values,
                    V,
                    source,
                    distance);

    auto stop = high_resolution_clock::now();

    double execTime =
        duration<double,milli>(stop-start).count();

    ofstream fout(outputFile);

    if(!fout)
    {
        cout << "Cannot create output file.\n";
        return;
    }

    fout << "Algorithm : Bellman-Ford\n\n";

    if(!ok)
    {
        fout << "Negative cycle : true\n";
    }
    else
    {
        fout << "Source : " << source << "\n\n";

        fout << "Vertex\tDistance\n";

        for(int i=0;i<V;i++)
        {
            fout << i << "\t";

            if(distance[i]==INT_MAX)
                fout << "INF";
            else
                fout << distance[i];

            fout << endl;
        }

        fout << "\nNegative cycle : none\n";
    }

    fout << "\nExecution Time : "
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
    while(true)
    {
        cout << "\n========== Bellman-Ford ==========\n";
        cout << "1. bf_10.txt\n";
        cout << "2. bf_100.txt\n";
        cout << "3. bf_10000.txt\n";
        cout << "4. bf_50000.txt\n";
        cout << "5. bf_100000.txt\n";
        cout << "6. Run All\n";
        cout << "0. Exit\n";

        int choice;
        cout << "\nEnter Choice : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            runBellmanFord(
                "input/bf_10.txt",
                "output/output_bf_10.txt");
            break;

        case 2:
            runBellmanFord(
                "input/bf_100.txt",
                "output/output_bf_100.txt");
            break;

        case 3:
            runBellmanFord(
                "input/bf_10000.txt",
                "output/output_bf_10000.txt");
            break;

        case 4:
            runBellmanFord(
                "input/bf_50000.txt",
                "output/output_bf_50000.txt");
            break;

        case 5:
            runBellmanFord(
                "input/bf_100000.txt",
                "output/output_bf_100000.txt");
            break;

        case 6:
            runBellmanFord("input/bf_10.txt","output/output_bf_10.txt");
            runBellmanFord("input/bf_100.txt","output/output_bf_100.txt");
            runBellmanFord("input/bf_10000.txt","output/output_bf_10000.txt");
            runBellmanFord("input/bf_50000.txt","output/output_bf_50000.txt");
            runBellmanFord("input/bf_100000.txt","output/output_bf_100000.txt");
            break;

        case 0:
            return 0;

        default:
            cout << "\nInvalid Choice\n";
        }
    }

    return 0;
}
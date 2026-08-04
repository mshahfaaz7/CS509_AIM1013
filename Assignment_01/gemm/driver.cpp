#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>

#include "gemm.h"

using namespace std;
using namespace chrono;

void runTest(string fileName)
{
    ifstream fin(fileName);

    if (!fin)
    {
        cout << "\nCannot open " << fileName << endl;
        return;
    }

    int M, K, N;
    fin >> M >> K >> N;

    Matrix A(M, vector<int>(K));
    Matrix B(K, vector<int>(N));

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < K; j++)
            fin >> A[i][j];
    }

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N; j++)
            fin >> B[i][j];
    }

    fin.close();

    auto start1 = high_resolution_clock::now();

    Matrix simple = gemmSimple(A, B, M, K, N);

    auto stop1 = high_resolution_clock::now();

    double timeSimple =
        duration<double, milli>(stop1 - start1).count();

    auto start2 = high_resolution_clock::now();

    Matrix block = gemmBlocking(A, B, M, K, N, 32);

    auto stop2 = high_resolution_clock::now();

    double timeBlock =
        duration<double, milli>(stop2 - start2).count();

    cout << "\n=====================================\n";
    cout << "Input File : " << fileName << endl;

    cout << "\nAlgorithm : GEMM Simple\n";
    cout << "Result Matrix\n";

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cout << simple[i][j] << " ";

        cout << endl;
    }

    cout << "Execution Time : "
         << fixed << setprecision(6)
         << timeSimple << " ms\n";

    cout << "\nAlgorithm : GEMM Blocking\n";
    cout << "Result Matrix\n";

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cout << block[i][j] << " ";

        cout << endl;
    }

    cout << "Execution Time : "
         << fixed << setprecision(6)
         << timeBlock << " ms\n";

    cout << "=====================================\n";
}

int main()
{
    int choice;

    while (true)
    {
        cout << "\n========== GEMM ==========\n";
        cout << "1. Run gemm_test_01.txt\n";
        cout << "2. Run gemm_test_02.txt\n";
        cout << "3. Run gemm_test_03.txt\n";
        cout << "4. Run gemm_test_04.txt\n";
        cout << "5. Run All Test Files\n";
        cout << "0. Exit\n";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            runTest("gemm_test_01.txt");
            break;

        case 2:
            runTest("gemm_test_02.txt");
            break;

        case 3:
            runTest("gemm_test_03.txt");
            break;

        case 4:
            runTest("gemm_test_04.txt");
            break;

        case 5:
            runTest("gemm_test_01.txt");
            runTest("gemm_test_02.txt");
            runTest("gemm_test_03.txt");
            runTest("gemm_test_04.txt");
            break;

        case 0:
            return 0;

        default:
            cout << "Invalid Choice\n";
        }
    }
}

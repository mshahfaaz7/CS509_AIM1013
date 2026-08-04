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

    // If launched from wrapper, try repository path
    if (!fin)
    {
        fin.open("Assignment_01/gemm/" + fileName);
    }

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

    auto start = high_resolution_clock::now();
    Matrix simple = gemmSimple(A, B, M, K, N);
    auto stop = high_resolution_clock::now();

    double simpleTime =
        duration<double, milli>(stop - start).count();

    start = high_resolution_clock::now();
    Matrix block = gemmBlocking(A, B, M, K, N, 32);
    stop = high_resolution_clock::now();

    double blockTime =
        duration<double, milli>(stop - start).count();

    cout << "\n=====================================\n";
    cout << "Input File : " << fileName << endl;

    cout << "\nAlgorithm : GEMM Simple\n";
    cout << "Matrix Size : " << M << " x " << N << endl;
    cout << "Execution Time : "
         << fixed << setprecision(6)
         << simpleTime << " ms\n";

    cout << "\nAlgorithm : GEMM Blocking\n";
    cout << "Matrix Size : " << M << " x " << N << endl;
    cout << "Execution Time : "
         << fixed << setprecision(6)
         << blockTime << " ms\n";

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
        cout << "5. Run gemm_test_05.txt\n";
        cout << "6. Run All Test Files\n";
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
            runTest("gemm_test_05.txt");
            break;

        case 6:
            runTest("gemm_test_01.txt");
            runTest("gemm_test_02.txt");
            runTest("gemm_test_03.txt");
            runTest("gemm_test_04.txt");
            runTest("gemm_test_05.txt");
            break;

        case 0:
            return 0;

        default:
            cout << "Invalid Choice\n";
        }
    }
}
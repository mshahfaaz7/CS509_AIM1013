#include <iostream>
#include <cstdlib>

using namespace std;

void assignment01Menu()
{
    int choice;

    while (true)
    {
        cout << "\n========== Assignment 01 ==========\n";
        cout << "1. GEMM\n";
        cout << "2. CSR\n";
        cout << "0. Back\n";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:

#ifdef _WIN32
            system("cd ..\\Assignment_01\\gemm && gemm.exe");
#else
            system("cd ../Assignment_01/gemm && ./gemm");
#endif
            break;

        case 2:

#ifdef _WIN32
            system("cd ..\\Assignment_01\\CSR && CSR.exe");
#else
            system("cd ../Assignment_01/CSR && ./CSR");
#endif
            break;

        case 0:
            return;

        default:
            cout << "Invalid Choice\n";
        }
    }
}


void assignment02Menu()
{
    int choice;

    while (true)
    {
        cout << "\n========== Assignment 02 ==========\n";
        cout << "1. Bellman-Ford\n";
        cout << "2. Floyd-Warshall\n";
        cout << "0. Back\n";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:

#ifdef _WIN32
            system("cd ..\\Assignment_02\\bellmanford && bf.exe");
#else
            system("cd ../Assignment_02/bellmanford && ./bf");
#endif
            break;

        case 2:

#ifdef _WIN32
            system("cd ..\\Assignment_02\\Floyd_warshall && fw.exe");
#else
            system("cd ../Assignment_02/Floyd_warshall && ./fw");
#endif
            break;

        case 0:
            return;

        default:
            cout << "Invalid Choice\n";
        }
    }
}


int main()
{
    int choice;

    while (true)
    {
        cout << "\n=========================================\n";
        cout << "      CS509 Laboratory Common Wrapper\n";
        cout << "=========================================\n";
        cout << "1. Assignment 01\n";
        cout << "2. Assignment 02\n";
        cout << "0. Exit\n";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            assignment01Menu();
            break;

        case 2:
            assignment02Menu();
            break;

        case 0:
            return 0;

        default:
            cout << "Invalid Choice\n";
        }
    }

    return 0;
}
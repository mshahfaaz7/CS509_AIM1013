#include "gemm.h"
#include <algorithm>

Matrix gemmSimple(const Matrix &A,
                  const Matrix &B,
                  int M,
                  int K,
                  int N)
{
    Matrix C(M, std::vector<int>(N, 0));

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < K; k++)
            {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

Matrix gemmBlocking(const Matrix &A,
                    const Matrix &B,
                    int M,
                    int K,
                    int N,
                    int blockSize)
{
    Matrix C(M, std::vector<int>(N, 0));

    for (int row = 0; row < M; row += blockSize)
    {
        for (int col = 0; col < N; col += blockSize)
        {
            for (int temp = 0; temp < K; temp += blockSize)
            {
                int rowEnd = std::min(row + blockSize, M);
                int colEnd = std::min(col + blockSize, N);
                int tempEnd = std::min(temp + blockSize, K);

                for (int i = row; i < rowEnd; i++)
                {
                    for (int j = col; j < colEnd; j++)
                    {
                        for (int k = temp; k < tempEnd; k++)
                        {
                            C[i][j] = C[i][j] + A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }

    return C;
}

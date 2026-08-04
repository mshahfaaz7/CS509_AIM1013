#ifndef GEMM_H
#define GEMM_H

#include <vector>

typedef std::vector<std::vector<int>> Matrix;

// Function for normal matrix multiplication
Matrix gemmSimple(const Matrix &A,
                  const Matrix &B,
                  int M,
                  int K,
                  int N);

// Function for blocking (tiled) matrix multiplication
Matrix gemmBlocking(const Matrix &A,
                    const Matrix &B,
                    int M,
                    int K,
                    int N,
                    int blockSize = 32);

#endif
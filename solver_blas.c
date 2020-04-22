/*
 * Tema 2 ASC
 * 2020 Spring
 */
#include <cblas.h>
#include "utils.h"

#define IDX2L(i, j, N) (((i) * (N)) + (j))

/* 
 * Add your BLAS implementation here
 */

double* my_solver(int N, double *A, double *B) {
	int i, j;
	double alpha = 1.0;
	/* Calculate the final result in C matrix */
	double *C = calloc(N * N, sizeof(double));
	if (C == NULL) {
		return NULL;
	}
	/* Calculate the B*At part in D */
	double *D = calloc(N * N, sizeof(double));
	if (D == NULL) {
		return NULL;
	}
	/* Calculate the A * A in A_square */
	double *A_square = calloc(N * N, sizeof(double));
	if (A_square == NULL) {
		return NULL;
	}
	
	/* Copy B matrix in D matrix */
	for (i = 0; i != N; i++) {
		for (j = 0; j != N; j++) {
			D[IDX2L(i, j, N)] = B[IDX2L(i, j, N)];
		}
	}
	/* Copy A matrix in A_square matrix */
	for (i = 0; i != N; i++) {
		for (j = 0; j != N; j++) {
			if ( i <= j) {
				A_square[IDX2L(i, j, N)] = A[IDX2L(i, j, N)];
			}
		}
	}
	/* 
	 * Multiply matrixes B * At, where At is A transposed
	 * The result is saved in D matrix
	 */
	cblas_dtrmm(CblasRowMajor, CblasRight, CblasUpper, CblasTrans,
				CblasNonUnit, N, N, alpha, A, N, D, N);
	/* 
	 * Multiply matrixes A * A, saved result in A_square
	 * Matrix A_square is a triangular matrix
	 */
	cblas_dtrmm(CblasRowMajor, CblasRight, CblasUpper, CblasNoTrans,
			    CblasNonUnit, N, N, alpha, A, N, A_square, N);

	/* 
	 * Multiply matrixes A_square * B, where A_square = A * A
	 * The result is saved in B matrix
	 */
	cblas_dtrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans,
				CblasNonUnit, N, N, alpha, A_square, N, B, N);

	/* Add matrixes D and B, save the result in C matrix */
	for (i = 0; i != N; i++) {
		for (j = 0; j != N; j++) {
			C[IDX2L(i, j, N)] = D[IDX2L(i, j, N)] + B[IDX2L(i, j, N)];
		}
	}
	/* Free memory from D and A_square */
	free(D);
	free(A_square);
	printf("BLAS SOLVER\n");
	return C;
}

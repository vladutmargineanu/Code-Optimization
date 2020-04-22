/*
 * Tema 2 ASC
 * 2020 Spring
 */
#include "utils.h"

#define IDX2L(i, j, N) (((i) * (N)) + (j))

/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	int i, j, k;
	/* Calculate the final result in C matrix */
	double *C = calloc(N * N, sizeof(double));
	if (C == NULL) {
		return NULL;
	}
	/* Calculate the transposed A in At matrix */
	double *At = calloc(N * N, sizeof(double));
	if (At == NULL) {
		return NULL;
	}
	/* Calculate the B*At part in D */
	double *D = calloc(N * N, sizeof(double));
	if (D == NULL) {
		return NULL;
	}
	/* Calculate the A * A * B part in E */
	double *E = calloc(N * N, sizeof(double));
	if (E == NULL) {
		return NULL;
	}
	/* Calculate A * A part in A_square */
	double *A_square = calloc(N * N, sizeof(double));
	if (A_square == NULL) {
		return NULL;
	}
	/* Calculate the transpose of A matrix */
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if ( i <= j) {
				At[IDX2L(j, i, N)] = A[IDX2L(i, j, N)];
			}
		}
	}
	/* 
	 * Multiply matrixes  B * At, where At is A transposed
	 * The result is saved in D matrix
	 */
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			/* 
			 * At is triangular matrix so we go over
			 * the elements that give the zero amount.
			 */
			for (k = j; k < N; k++) {
				D[IDX2L(i, j, N)] += B[IDX2L(i, k, N)] * At[IDX2L(k, j, N)];
			}
		}
	}
	/* 
	 * Multiply matrixes  A * A, where A is triangular matrix
	 * The result is saved in A_square matrix
	 */
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (i <= j) {
				for (k = 0; k < N; k++) {
					A_square[IDX2L(i, j, N)] += A[IDX2L(i, k, N)] * 
											    A[IDX2L(k, j, N)];
				}
			}
		}	
	}
	/* 
	 * Multiply matrixes A_square * B, where A_square is A * A
	 * The result is saved in E matrix
	 */
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			/* 
			 * A_square is triangular matrix so we go over
			 * the elements that give the zero amount.
			 */
			for (k = i; k < N; k++) {
				E[IDX2L(i, j, N)] += A_square[IDX2L(i, k, N)] * 
									 B[IDX2L(k, j, N)];
			}
		}
	}
    /* 
	 * Add matrixes D + E, where D = B * At, E = A * A * B
	 * The result is saved in C matrix
	 */
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			C[IDX2L(i, j, N)] = D[IDX2L(i, j, N)] + E[IDX2L(i, j, N)];
		}
	}
	free(D);
	free(E);
	free(A_square);
	free(At);

	printf("NEOPT SOLVER\n");

	return C;
}

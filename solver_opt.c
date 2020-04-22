/*
 * Tema 2 ASC
 * 2020 Spring
 */
#include "utils.h"

#define IDX2L(i, j, N) (((i) * (N)) + (j))

/*
 * Add your optimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	int i, j, k;
	double *orig_pa, *orig_pa_aux, *orig_pa_square, *orig_pb, *orig_pd, *orig_pe;
	double *pa, *pa_aux, *pa_square, *pb, *pd, *pe;

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
			if (i <= j) {
				At[IDX2L(j, i, N)] = A[IDX2L(i, j, N)];
			}
		}
	}
	/* 
	 * Multiply matrixes  B * At, where At is A transposed
	 * The result is saved in D matrix
	 */
	orig_pb = B;					// line i from B
	orig_pd = D;		            // line i from D

	for (i = 0; i < N; i++, orig_pb += N, orig_pd += N) {
		orig_pa = At;				// column j from A
		pd = orig_pd;
		/* 
		 * At is triangular matrix so we go over
		 * the elements that give the zero amount.
	    */
		for (j = 0; j < N; j++, ++orig_pa, ++pd) {
			pb = orig_pb + j;
			pa = orig_pa + j * N;

			register double sum = 0.0;

			for (k = j; k < N; k++, ++pb, pa += N) {
				sum += *pb * *pa;
			}
			*pd = sum;
		}
	}
	/* 
	 * Multiply matrixes  A * A, where A is triangular matrix
	 * The result is saved in A_square matrix
	 */
	orig_pa = A;					// line i from A
	orig_pa_square = A_square;		// line i from A_square

	for (i = 0; i < N; i++, orig_pa += N, orig_pa_square += N) {
		orig_pa_aux = A;			// column j from A
		pa_square = orig_pa_square;

		for (j = 0; j < N; j++, ++orig_pa_aux, ++pa_square) {
			if (i <= j) {
				pa = orig_pa;
				pa_aux = orig_pa_aux;

				register double sum = 0.0;

				for (k = 0; k < N; k++, ++pa, pa_aux += N) {
					sum += *pa * *pa_aux;
				}
				*pa_square = sum;
			}
		}
	}
	/* 
	 * Multiply matrixes A_square * B, where A_square is A * A
	 * The result is saved in E matrix
	 */
	orig_pa_square = A_square;		// line i from A_square
	orig_pe = E;		            // line i from E

	for (i = 0; i < N; i++, orig_pa_square += N, orig_pe += N) {
		orig_pb = B;				// column j from A
		pe = orig_pe;
		/* 
		 * A_square is triangular matrix so we go over
		 * the elements that give the zero amount.
	     */
		for (j = 0; j < N; j++, ++orig_pb, ++pe) {
			pa_square = orig_pa_square + i;
			pb = orig_pb + i * N;

			register double sum = 0.0;

			for (k = i; k < N; k++, ++pa_square, pb += N) {
				sum += *pa_square * *pb;
			}
			*pe = sum;
		}
	}
    /* 
	 * Add matrixes D + E, where D = B * At, E = A * A * B
	 * The result is saved in E matrix
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

	printf("OPT SOLVER\n");

	return C;
}

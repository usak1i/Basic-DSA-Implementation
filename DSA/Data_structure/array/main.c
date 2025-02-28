#include <stdio.h>

#define rows_A 3
#define cols_A 3
#define rows_B 3
#define cols_B 3

int* matrixMulti(int A[rows_A][cols_A], int B[rows_A][cols_B]);
void transpose(int A[rows_A][cols_B]);

int main(int argc, char **argv) {
	// 1D array
	int arr[] = {0, 1, 2, 3 ,4 ,5 ,6};

	int *pArr = arr;

	printf("The address of matrix -> %p\n", pArr);
	printf("The first value of arr -> %d\n", *pArr);
	printf("The third value of arr -> %d\n", *pArr + 2);

	// 2D array(matrix)
	int rows = 3;

	int A[rows_A][cols_A] = {{1, 2, 3}, 
							 {4, 5, 6}, 
							 {7, 8 ,9}};

	int B[rows_B][cols_B] = {{0, 1, 0}, 
							 {1, 0, 0}, 
							 {0, 0, 2}};
	printf("Matrix A:\n");
	for (int i = 0; i < rows_A; i++) {
		for (int j = 0; j < cols_A; j++) {
			printf(" %d", A[i][j]);
		}
		printf("\n");
	}

	printf("Matrix B:\n");
	for (int i = 0; i < rows_B; i++) {
		for (int j = 0; j < cols_B; j++) {
			printf(" %d", B[i][j]);
		}
		printf("\n");
	}

	int res[rows_A][cols_B] = {{0, 0, 0},
							   {0, 0, 0}, 
							   {0, 0, 0}};
	
	for (int i = 0; i < rows_A; i++) {
		for (int j = 0; j < cols_B; j++) {
			for (int k = 0; k < cols_A; k++) {
				res[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	printf("A * B = \n");
	for (int i = 0; i < rows_A; i++) {
		for (int j = 0; j < cols_B; j++) {
			printf(" %d", res[i][j]);
		}
		printf("\n");
	}
	
	transpose(A);
	
	printf("After transpose A\n");
	for (int i =  0; i < rows_A; i++) {
		for (int j = 0; j < cols_A; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}

	transpose(res);
	
	printf("After transpose res\n");
	for (int i =  0; i < rows_A; i++) {
		for (int j = 0; j < cols_A; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	return 0;
}

	
void transpose(int A[rows_A][cols_B]) {
	int temp;

	for (int i = 0; i < rows_A; i++) {
		for (int j = i + 1; j < cols_A; j++) {
			temp = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = temp;
		}
	}
}
	



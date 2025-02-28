#include <stdio.h>

void TOH(int n, int A, int B, int C);

int count = 0;

int main(int argc, char *argv[]) {
	TOH(6, 1, 2, 3);
	printf("Total moved %d steps\n", count);
}

void TOH(int n, int A, int B, int C) {
	if (n > 0) {
		TOH(n - 1, A, C, B);
		printf("Move disk from %d to %d\n", A, C);
		count++;
		TOH(n - 1, B, A, C);
	}
}

#include <stdio.h>

int S(int m, int n) {
	if (n > m) return 0;
	if (m == n || n == 1) return 1;

	return S(m - 1, n - 1) + (n * S(m - 1, n));
}

int main() {
	printf("S(6,3) = %d\n", S(9,3));
	return 0;
}

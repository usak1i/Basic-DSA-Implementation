#include <stdio.h>

int solve(int len, int profit[]);
int solve_memo(int len, int profit[], int memo[]);
int max(int a, int b);

// DP relation
//
// C[i] = max{profit[k] + C[i - k]}, 1 <= k <= i
//


int main() {

	// test cases
	int p1[]= {1,5,8,9,10,17,17,20};
	int n = sizeof(p1) / sizeof(p1[0]);

	int res = solve(n, p1);
	printf("The maximum profit is %d\n", res);

	int memo[n + 1];
	for (int i  = 0; i <= n; i++) 
		memo[i] = -1;

	int result = solve_memo(n, p1, memo);
	printf("The maximum profit is %d\n", result);

	return 0;
}

// Bottom up
int solve(int len, int profit[]) {
	int c[len + 1];

	for (int i = 0; i < len; i++) {
		c[i] = 0;
	}

	for (int i = 1; i <= len; i++) {
		int maxval = 0;
		for (int k = 1; k <= i; k++) {
			maxval = max(maxval, profit[k - 1] + c[i - k]);
		}
		c[i] = maxval;
	}

	return c[len];
}

// Memoization
int solve_memo(int len, int profit[], int memo[]) {
	if (len == 0) return 0;
	if (memo[len] != -1) return memo[len];

	int maxval = 0;

	for (int i = 1; i <= len; i++) {
		int temp = profit[i - 1] + solve_memo(len - i, profit, memo);

		maxval = max(maxval, temp);
	}

	return memo[len] = maxval;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

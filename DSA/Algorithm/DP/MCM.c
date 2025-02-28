#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
	return (a < b) ? a : b;
}

int MCM(int arr[], int n) {
	int dp[n][n];
	int s[n][n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = 0;
		}
	}

	for (int d = 1; d < n - 1; d++) {
		for (int i = 1; i < n - d; i++) {
			int res = INT_MAX;
			int j = i + d;
			for (int k = i; k < j; k++) {
				int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
				if (cost < res) {
					res = cost;
					s[i][j] = k;
				}
			}
			dp[i][j] = res;
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	return dp[1][n - 1];
}

int main() {
	int arr[] = {5, 4, 6, 2 ,7};
	int n = sizeof(arr) / sizeof(arr[0]);
	int res = MCM(arr, n);
	printf("The minimum number of matrix chain multiplication is %d\n", res);

	return 0;
}

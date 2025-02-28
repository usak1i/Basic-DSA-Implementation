#include <stdio.h>

int max(int a, int b) {
	return (a > b) ? a : b;
}

int knapsack(int profit[], int wt[], int m, int n) {
	int dp[m + 1][n + 1];

	for (int i = 0; i <= m; i++) {
		for (int w = 0; w <= n; w++) {
			if (i == 0 || w == 0) {
				dp[i][w] = 0;
			} 
			else if (wt[i - 1] <= w) {
				dp[i][w] = max(dp[i - 1][w], profit[i - 1] + dp[i - 1][w - wt[i - 1]]);
			}
			else {
				dp[i][w] = dp[i - 1][w];
			}
		}
	}
	
	int i = m;
	int j = n;

	while (i > 0 && j >= 0) {
		if (dp[i][j] == dp[i - 1][j]) {
			printf("Item #%d: 0\n", i);
			i--;
		}
		else {
			printf("Item #%d: 1\n", i);
			j -= wt[--i];
		}
	}


	return dp[m][n];
}

int main() {
	int profit[] = {8, 6, 15, 3, 3, 5, 9};
	int weight[] = {2, 3, 5, 4, 3, 2, 6};
	int capacity = 16;
	int m = sizeof(profit)/sizeof(profit[0]);

	int res = knapsack(profit, weight, m, capacity);

	printf("The maximum profit is %d\n", res);
	
	return 0;
}

#include <stdio.h>
#include <limits.h>

int coinChange_Recurrsive(int coins[], int n, int amount);
int coinChange_memo(int coins[], int n, int amount, int memo[]);
int coinChange_Bottomup(int coins[], int n, int amount);

int min(int a, int b);

int main() {
	// test case
	int coins[] = {1, 2, 5};
	int amount = 100;

	int n = sizeof(coins) / sizeof(coins[0]);

	int memo[amount + 1];
	for (int i = 0; i <= amount; i++) {
		memo[i] = -1;
	}
		
	int res2 = coinChange_memo(coins, n, amount, memo);
	if (res2 == INT_MAX) 
		res2 = -1;

	printf("Memoization: The minimum number for coins is %d\n", res2);

	int res3 = coinChange_Bottomup(coins, n, amount);
	if (res3 == INT_MAX) 
		res3 = -1;

	printf("Bottom up: The minimum number for coins is %d\n", res3);

	int res1 = coinChange_Recurrsive(coins, n, amount);
	if (res1 == INT_MAX) 
		res1 = -1;

	printf("Recurrsive: The minimum number for coins is %d\n", res1);

	return 0;
}

// Recurrsive
int coinChange_Recurrsive(int coins[], int n, int amount) {
	if (amount < 0) return INT_MAX;
	if (amount == 0) return 0;

	int minval = INT_MAX;
	
	for (int i = 0; i < n; i++) {
		int curr = coinChange_Recurrsive(coins, n, amount - coins[i]);
		if (curr != INT_MAX) 
			minval = min(minval, curr + 1);
	}

	return minval;
}

// Memoization
int coinChange_memo(int coins[], int n, int amount, int memo[]) {
	if (amount < 0) return INT_MAX;
	if (amount == 0) return 0;
	if (memo[amount] != -1) return memo[amount];

	int minval = INT_MAX;
	for (int i = 0; i < n; i++) {
		int curr = coinChange_memo(coins, n, amount - coins[i], memo);
		if (curr != INT_MAX)
			minval = min(minval, curr + 1);
	}

	return memo[amount] = minval;
}

// Bottom up
int coinChange_Bottomup(int coins[], int n, int amount) {
	int dp[amount + 1];
	for (int i = 0; i <= amount; i++) {
		dp[i] = INT_MAX;
	}
	
	dp[0] = 0;
	for (int i = 1; i <= amount; i++) {
		for (int j = 0; j < n; j++) {
			if (i >= coins[j])
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
		}
	}

	return dp[amount];
}
int min(int a,int b) {
	return (a < b) ? a : b;
}

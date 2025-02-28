#include <stdio.h>

int solve_Bottomup(char s1[], char s2[], int m, int n);
int solve_recurrsive(char s1[], char s2[], int m, int n);
int solve_memo(char s1[], char s2[], int m, int n, int memo[m + 1][n + 1]);

int min(int a, int b);

int main() {
	char s1[] = "horse";
	char s2[] = "ros";

	int m = sizeof(s1) / sizeof(s1[0]) - 1;
	int n = sizeof(s2) / sizeof(s2[0]) - 1;
	
	printf("m = %d, n = %d\n", m, n);

	int res1 = solve_Bottomup(s1, s2, m, n);
	printf("Bottom up: The minimum cost to modify s1 to s2 is %d\n", res1);

	int memo[m+1][n+1];
	for (int i = 0; i <= m; i++) 
		for (int j = 0; j <= n; j++) 
			memo[i][j] = -1;
	
	int res2 = solve_memo(s1, s2, m, n, memo);
	printf("Memoization: %d\n", res2);

	int res3 = solve_recurrsive(s1, s2, m, n);
	printf("Recurrsive: %d\n", res3);
	
	printf("^: %d\n", '^');
	return 0;	
}

int solve_recurrsive(char s1[], char s2[], int m, int n) {
	if (m == 0) return n;
	if (n == 0) return m;

	int res;
	if (s1[m - 1] == s2[n - 1]) {
		res = solve_recurrsive(s1, s2, m - 1, n - 1);
	} else {
		int delete = solve_recurrsive(s1, s2, m - 1, n);
		int insert = solve_recurrsive(s1, s2, m, n - 1);
		int convert = solve_recurrsive(s1 , s2, m - 1, n - 1);
		res = min(delete, min(insert, convert)) + 1;
	}

	return res;
}

int solve_memo(char s1[], char s2[], int m, int n, int memo[m + 1][n + 1]) {
	if (m == 0) return memo[m][n] = n;
	if (n == 0) return memo[m][n] = m;
	if (memo[m][n] != -1) return memo[m][n];

	int res;
	if (s1[m - 1] == s2[n - 1]) {
		res = solve_memo(s1, s2, m - 1, n - 1, memo);
	} else {
		int delete = solve_memo(s1, s2, m - 1, n, memo);
		int insert = solve_memo(s1, s2, m, n - 1, memo);
		int convert = solve_memo(s1, s2, m - 1, n - 1, memo);
		res = min(delete, min(insert, convert)) + 1;
	}

	return memo[m][n] = res;
}

int solve_Bottomup(char s1[], char s2[],int m, int n) {
	int dp[m + 1][n + 1];

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = 0;
			if (i == 0) dp[i][j] = j;
			if (j == 0) dp[i][j] = i;
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s1[i - 1] == s2[j - 1]) 
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
		}
	}

	return dp[m][n];
}

int min(int a ,int b) {
	return (a < b) ? a : b;
}





#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* failfunc(char *pat) {
	int n = strlen(pat);
	int* f = malloc(sizeof(int) * n); 

	for (int i = 0; i < n;i ++) 
		f[i] = 0;

	int len = 0;
	int i = 1;
	while (i < n) {
		// if pattern is matched
		// then we increase length of pattern and f[i] = len
		if (pat[i] == pat[len]) {
			len++;
			f[i] = len;
			i++;
		} 
		// if there is a matched
		else {
			// if update the length to previous length
			// to avoid the reduntant comparisons
			if (len != 0) {
				len = f[len - 1];
			}
			// if there is no prefix is found 
			// then reset the value of length
			else {
				f[i] = 0;
				i++;
			}
		}
	}


	for (int i = 0 ;i < n; i++) {
		printf("%c ", pat[i]);
	}
	printf("\n");

	for (int i = 0;i < n; i++) {
		printf("%d ", f[i]);
	}
	printf("\n");

	return f;
}

void search(char *s, char *pat, int *f) {
	int m = strlen(s);
	int n = strlen(pat);
	
	int res[m];
	for (int i = 0; i < m; i++)
		res[i] = 0;

	int residx = 0;

	int i = 0;
	int j = 0;
	while (i < m) {
		// if there is a matched
		// then we increase the value of i and j
		if (s[i] == pat[j]) {
			i++;
			j++;
			
			// if j == length of pattern
			// that means whole pattern are matched
			// so we add the index into result
			if (j == n) {
				res[residx++] = (i - j);
			}
		}
		// if there is a mismatched
		else {
			// if j != 0
			// then set j to previous index
			if (j != 0)
				j = f[j - 1];
			// else reset the value of j 
			// and move i to the next character
			else {
				j = 0;
				i++;
			}
		}
	} 

	printf("Pattern are found at indices:");
	for (int i = 0; i < residx; i++) {
		printf("%d ", res[i]);
	}
	printf("\n");
}

int main() {
	char *s = "abcababcabab";
	char *pat = "abcab";
	int* f = failfunc(pat);

	search(s, pat, f);

	return 0;

}

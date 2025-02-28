#include <stdio.h>

void swap(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

void p(char arr[], int i, int n) {
	if (i == n) {
		for (int j = 0; j <= n; j++) {
			printf("%c", arr[j]);
		}
		printf("   ");
	}
	else {
		for (int j = i; j <= n; j++) {
			swap(&arr[i], &arr[j]);
			p(arr, i + 1, n);
			swap(&arr[i], &arr[j]);
		}
	}
}

int main() {
	char arr[] = {'1', '2', '3'};

	p(arr, 0, 2);

	return 0;
}

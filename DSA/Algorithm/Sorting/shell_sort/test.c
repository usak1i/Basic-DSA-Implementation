#include <stdio.h>

void shellSort(int arr[], int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			int temp = arr[i];

			int j;
			for (j = i; j >= gap && arr[j] < arr[j - gap]; j -= gap)
				arr[j] = arr[j - gap];

			arr[j] = temp;
		}
	}
}

int main() {
	int arr[] = {6, 2, 7, 1, 8, 3 ,9};
	int n = sizeof(arr) / sizeof(arr[0]);

	shellSort(arr, n);

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

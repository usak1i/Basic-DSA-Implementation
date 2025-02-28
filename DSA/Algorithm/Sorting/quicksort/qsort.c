#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int l, int h) {
	int pivot = arr[l];
	int i = l, j = h;

	while(i < j) {
		do {
			i++;
		} while(arr[i] <= pivot);

		do {
			j--;	
		} while(arr[j] > pivot);

		if (i < j)
			swap(&arr[i], &arr[j]);
	}
	swap(&arr[j], &arr[l]);

	return j;
}

void quicksort(int arr[], int l, int h) {
	if (l < h) {
		int j = partition(arr, l, h);
		quicksort(arr, l, j);
		quicksort(arr, j + 1, h);
	}
}

void printarr(int arr[], int n) {
	printf("Array: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[] = {3, 1, 6, 8, 2, 9, 5};
	int n = sizeof(arr) / sizeof(arr[0]);

	quicksort(arr, 0, n - 1);
	printarr(arr, n);

	return 0;
}

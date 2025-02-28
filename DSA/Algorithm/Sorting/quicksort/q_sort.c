#include <stdio.h>

int partition(int arr[], int l, int h);
void quickSort(int arr[], int l, int h);
void swap(int *x, int *y);

int count = 0;

int main(int argc, char *argv[]) {
	int arr[] = {5,4,3,2,1};
	int size = sizeof(arr) / sizeof(arr[0]);

	quickSort(arr, 0, size - 1);

	printf("arr:");
	for (int i = 0; i < size; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");

	printf("%d\n", count);

	return 0;
}

int	partition(int arr[], int l, int h) {
	count++;
	int pivot = arr[h];
	int i = l - 1;
	
	for (int j = l; j < h; j++) {
		if (arr[j] < pivot) {
			swap(&arr[++i], &arr[j]);
		}
	}
	swap(&arr[++i], &arr[h]);
	
	return i;
}

void quickSort(int arr[], int l, int h) {
	if (l < h) {
		int j = partition(arr, l, h);
		quickSort(arr, l ,j - 1);
		quickSort(arr, j + 1, h);
	}
}

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

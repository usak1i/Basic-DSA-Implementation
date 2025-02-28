#include <stdio.h>

void swap(int *x, int *y);
void selectionSort(int arr[], int size);

int main (int argc, char **argv) {
	int arr[] = {3, 5, 62, 1, 20, 12, 36, 48, 9, 20};
	int size = sizeof(arr) / sizeof(arr[0]);

	selectionSort(arr, size);

	printf("After sorted:");
	for (int i = 0; i < size; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");

	return 0;
}

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void selectionSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) 
	{
		int curr_min = i;

		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[curr_min]) {
				curr_min = j;
			}
		}

		if (curr_min != i) {
			swap(&arr[curr_min], &arr[i]);
		}
	}
}

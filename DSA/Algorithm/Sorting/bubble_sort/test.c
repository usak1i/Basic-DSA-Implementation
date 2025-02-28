#include <stdio.h>

void swap(int *x, int *y);
void bubbleSort(int arr[], int size);
void BubbleSort(int arr[], int n);

int main(int argc, char *argv[]) {
	int arr[] = {3, 5, 7, 1, 9, 6, 2};
	int size = sizeof(arr) / sizeof(arr[0]);

	BubbleSort(arr, size);

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

void bubbleSort(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void BubbleSort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int flag = 0;
		for (int j = 0; j < n - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

#include  <stdio.h>

void swap(int *x, int *y);
void insertionSort(int arr[], int size);
void InsertionSort(int arr[], int n);

int main(int argc, char *argv[]) {
	int arr[] = {2, 8, 5, 3, 9, 2, 4};
	int size = sizeof(arr) / sizeof(arr[0]);

	InsertionSort(arr, size);

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

void insertionSort(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		for (int j = i; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(&arr[j], &arr[j - 1]);
			}
		} 
	}
}

void InsertionSort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int next = arr[i];
		int j = i - 1;

		while(j >= 0 && arr[j] > next) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = next;
	}
}

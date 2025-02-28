#include <stdio.h>

void merge(int arr[], int low, int mid, int high);
void mergeSort(int arr[], int low, int high);
void merge2(int arr[], int low, int mid ,int high);
void mergeSort2(int arr[], int low, int high);
void printArray(int arr[], int size);


int count = 0;

int main(int argc, char **argv) {
	int arr[] = {3,4,5,2,1};
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array  ->");
	printArray(arr, size);

	mergeSort2(arr, 0, size - 1);

	printf("After sorted ->");
	printArray(arr, size);

	int arr2[] = {3, 6, 1, 9, 8, 2};
	mergeSort2(arr2, 0, 5);
	printf("arr2 after sorted: ");
	printArray(arr2, 6);

	printf("%d\n", count);

	return 0;
}

void mergeSort2(int arr[], int low, int high) {
	if (low < high) {
		int mid = (low + high) >> 1;
		mergeSort2(arr, low, mid);
		mergeSort2(arr, mid + 1, high);
		merge2(arr, low, mid, high);
	}
}

void merge2(int arr[], int low, int mid, int high) {
	int left = low, right = mid + 1, k = 0;
	int temp[high - low + 1];

	while (left <= mid) {
		while (right <= high && arr[right] <= arr[left]) {
			temp[k++] = arr[right++];
		}
		temp[k++] = arr[left++];
	}

	while (right <= high) {
		temp[k++] = arr[right++];
	}

	for (int i = 0; i < k; i++) {
		arr[low++] = temp[i];
	}
}

void merge(int arr[], int low, int mid, int high) {
	int i, j, k;
	int n1 = mid - low + 1;
	int n2 = high - mid;

	int A[n1], B[n2];

	for (i = 0; i < n1; i++) 
		A[i] = arr[low + i];

	for (j = 0; j < n2; j++) 
		B[j] = arr[mid + 1 + j];

	i = 0;
	j = 0;
	k = low;

	while (i < n1 && j < n2) {
		if (A[i] < B[j]) {
			arr[k++] = A[i++];
		}
		else {
			arr[k++] = B[j++];
		}
	}

	while (i < n1) {
		arr[k++] = A[i++];
	}

	while (j < n2) {
		arr[k++] = B[j++];
	}
}

void mergeSort(int arr[], int low, int high) {
	count++;
	int mid = (high + low) / 2;
	if (low < high) {
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}

void printArray(int arr[], int size) {
	for(int i = 0; i < size; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");
}

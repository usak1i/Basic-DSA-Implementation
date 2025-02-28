#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Heapify(int arr[], int n, int i) {
	// Initial a value
	int largest = i;

	int left = 2 * i + 1;

	int right =  2 * i + 2;

	// Swap the largest element to root
	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		Heapify(arr, n, largest);		 // Recursively build max heap to subtree	
	}
}

void heapify2(int arr[], int n, int root) {
	int temp = arr[root];
	int rootkey = arr[root];

	int child = root << 1;
	while (child < n) {
		if (child < n && arr[child] < arr[child + 1])
			child++;

		if (rootkey > arr[child]) break;
		else {
			arr[child >> 1] = arr[child];
			child <<= 1;
		}
		arr[child >> 1] = temp;
	}
}

void heapsort2(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) 
		heapify2(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {
		swap(&arr[i], &arr[i + 1]);
		heapify2(arr, i, 0);
	}
}

void HeapSort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) // build max heap
		Heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {	
		swap(&arr[0], &arr[i]);
		Heapify(arr, i, 0);				 // get the largest element in the tree again	
	}
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() { 
	int arr[] = {3 ,6, 1 ,7 ,8 ,2, 5};
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Given array: ");
	printArray(arr, n);

	heapsort2(arr, n);

	printf("After sorted: ");
	printArray(arr, n);

	return 0;
}

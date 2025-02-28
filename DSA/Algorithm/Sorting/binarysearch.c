#include <stdio.h>

int count = 0;

int binarysearch(int arr[], int l, int h, int target) {
	while (l <= h) {
		count++;
		int mid = (l + h) / 2;

		if (arr[mid] == target) return mid;

		if (arr[mid] < target) 
			l = mid + 1;
		else 
			h = mid - 1;
	}

	return -1;
}

int main() {
	int arr[] = {1,2,3,4,5,6,7,8};
	int n = sizeof(arr) / sizeof(arr[0]);
	int target = 8;
	int idx = binarysearch(arr, 0, n - 1, target);

	printf("the target index is %d\n", idx);
	printf("Total search time is %d\n", count);

	return 0;
}

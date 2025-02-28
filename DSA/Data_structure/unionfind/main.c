#include <stdio.h>

int find(int i);
void Union(int x, int y);
void printArray(int arr[], int n);

int parent[] = {0, 1, 2, 3, 4, 5};
int rank[] = {0, 0, 0, 0, 0, 0};


int main() {
	int n = sizeof(parent) / sizeof(parent[0]);

	Union(1, 2);
	printArray(parent, n);

	Union(3, 4);
	printArray(parent, n);

	Union(5, 6);
	printArray(parent, n);

	return 0;
}

int find(int i) {
	if (parent[i] == i)
		return parent[i];

	return find(parent[i]);
}

void Union(int x, int y) {
	int rootx = find(x);
	int rooty = find(y);

	if (rootx == rooty) return;	

	if (rank[rootx] > rank[rooty]) {
		parent[rooty] = rootx;
	} else if (rank[rooty] > rank[rootx]) {
		parent[rootx] = rooty;
	} else {
		parent[rooty] = rootx;
		rank[rootx]++;
	}
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	printf("\n");
}

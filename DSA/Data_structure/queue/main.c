#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct {
	int arr[MAX_SIZE];
	int front;
	int rear;
} quene;

quene *init_quene();
void enquene(quene *q, int val);
void dequene(quene *q);
void print_quene(quene *q);
int peek(quene *q);
bool isEmpty(quene *q);
bool isFull(quene *q);

int main(int argc, char *argv[]) {
	quene *q = init_quene();

	enquene(q, 3);
	enquene(q, 6);
	enquene(q, 9);

	print_quene(q);

	if (isEmpty(q) == true)
		printf("The quene is Empty\n");
	else
		printf("%d\n", peek(q));

	dequene(q);

	print_quene(q);

	return 0;
}

quene *init_quene() {
	quene *q = malloc(sizeof(quene));

	q->front = -1;
	q->rear = 0;

	return q;
}

bool isEmpty(quene *q) {
	return (q->front == q->rear - 1);
}

bool isFull(quene *q) {
	return (q->rear == MAX_SIZE);
}

void enquene(quene *q, int val) {
	if (isFull(q)) {
		printf("Quene is alreafy full\n");
		return; 
	}

	q->arr[q->rear++] = val;
}

void dequene(quene *q) {
	if (isEmpty(q)) {
		printf("There is nothing to pop\n");
		return;
	}

	q->front++;
}

int peek(quene *q) {
	if (isEmpty(q)) {
		printf("The quene is Empty\n");
		return 0;
	}

	return q->arr[q->front + 1];
}

void print_quene(quene *q) {
	if (isEmpty(q)) {
		printf("There is no element in quene\n");
		return;
	}

	printf("Current quene:");
	for (int i = q->front + 1; i < q->rear; i++) {
		printf(" %d", q->arr[i]);
	}
	printf("\n");
}

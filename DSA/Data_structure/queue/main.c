#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct {
	int arr[MAX_SIZE];
	int front;
	int rear;
} queue;

queue *init_queue();
void enqueue(queue *q, int val);
void dequeue(queue *q);
void print_queue(queue *q);
int peek(queue *q);
bool isEmpty(queue *q);
bool isFull(queue *q);

int main(int argc, char *argv[]) {
	queue *q = init_queue();

	enqueue(q, 3);
	enqueue(q, 6);
	enqueue(q, 9);

	print_queue(q);

	if (isEmpty(q) == true)
		printf("The queue is Empty\n");
	else
		printf("%d\n", peek(q));

	dequeue(q);

	print_queue(q);

	return 0;
}

queue *init_queue() {
	queue *q = malloc(sizeof(queue));

	q->front = -1;
	q->rear = 0;

	return q;
}

bool isEmpty(queue *q) {
	return (q->front == q->rear - 1);
}

bool isFull(queue *q) {
	return (q->rear == MAX_SIZE);
}

void enqueue(queue *q, int val) {
	if (isFull(q)) {
		printf("queue is alreafy full\n");
		return; 
	}

	q->arr[q->rear++] = val;
}

void dequeue(queue *q) {
	if (isEmpty(q)) {
		printf("There is nothing to pop\n");
		return;
	}

	q->front++;
}

int peek(queue *q) {
	if (isEmpty(q)) {
		printf("The queue is Empty\n");
		return 0;
	}

	return q->arr[q->front + 1];
}

void print_queue(queue *q) {
	if (isEmpty(q)) {
		printf("There is no element in queue\n");
		return;
	}

	printf("Current queue:");
	for (int i = q->front + 1; i < q->rear; i++) {
		printf(" %d", q->arr[i]);
	}
	printf("\n");
}

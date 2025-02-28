#include <stdio.h>

#define MAXSIZE 10

int queue[MAXSIZE];
int front = -1;
int rear = -1;

int isFull() {
	return rear + 1 == MAXSIZE;
}

int isEmpty() {
	return (front == -1 && rear == -1);
}

void enqueue(int val) {
	if (isFull()) {
		printf("Overflow: queue is already full!\n");
		return;
	}

	if (front == -1 && rear == -1) {
		front = 0;
		rear = 0;
		queue[rear] = val;
		return;
	}
		
	queue[++rear] = val;
}

void dequeue() {
	if (isEmpty()) {
		printf("Underflow: there is nothing to pop\n");
		return;
	}

	if (front == rear) {
		front = rear = -1;
	}

	front++;
}

void printqueue() {
	printf("Queue: ");
	for (int i = front; i != rear + 1; i++) {
		printf("%d ", queue[i]); 
	}
	printf("\n");
}

int main() {
	dequeue();
	enqueue(3);
	enqueue(6);
	enqueue(9);
	printqueue();
	dequeue();
	printqueue();
	enqueue(3);
	enqueue(12);
	enqueue(15);
	enqueue(18);
	enqueue(21);
	enqueue(24);
	enqueue(27);
	enqueue(30);
	enqueue(33);
	printqueue();
	return 0;
}

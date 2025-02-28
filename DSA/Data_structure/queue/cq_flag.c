#include <stdio.h>

/*
*	Circular queue implementation
*/

#define MAXSIZE 10

int front = -1, rear = -1;
int flag = 0;
int queue[MAXSIZE];

int isFull() {
	return (rear == front);
}

int isEmpty() {
	return front == rear;
}

void enqueue(int val) {
	if ((isFull() && flag == 1) || (rear == MAXSIZE - 1 && front == -1)) {
		printf("Overflow: queue is alerady full\n");
		return;
	}
	
	queue[rear] = val;
	rear = (rear + 1) % MAXSIZE;

	if (front == rear) // if after add an element the front == rear
		flag = 1;	   // it means the queue is full now
}

void dequeue() {
	if (isEmpty() && flag == 0) {
		printf("Underflow: queue is empty now\n");
		return;
	}

	// int val = queue[front]; if we want to return the value that is dequeued.
	front = (front + 1) % MAXSIZE;

	if (front == rear) 
		flag = 0;
}

void printqueue() {
	if (isEmpty() && flag == 0) {
		printf("There is nothing in the queue\n");
		return;
	}
	
	int i = front;
	printf("Circular queue: ");
	while (i != rear || (isFull() && flag == 1)) {
		printf("%d->", queue[i]);
		i = (i + 1) % MAXSIZE;
		if (i == front && (isFull() && flag == 1)) break;
	}
	printf("\n");
}

int main() {
	dequeue();
	enqueue(1);
	enqueue(2);
	enqueue(3);
	printqueue();
	dequeue();
	printqueue();
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(5);
	printqueue();
	dequeue();
	printqueue();
	enqueue(6);
	enqueue(7);
	enqueue(8);
	printqueue();
}

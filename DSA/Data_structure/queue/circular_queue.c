#include <stdio.h>

#define MAXSIZE 10

int queue[MAXSIZE];

int front = -1;
int rear = -1;

int isFull() {
	return (rear + 1) % MAXSIZE == front;
}


int isEmpty() {
	return front == -1;
}

void enqueue(int val) {
	if (isFull()) {
		printf("The queue is already full.\n");
		return;
	}

	if (front == -1)
		front = 0;

	rear = (rear + 1) % MAXSIZE;
	queue[rear] = val;
}

int dequeue() {
	if (isEmpty()) {
		printf("The queue is emtpy.\n");
		return 0;
	}

	int data = queue[front];

	if (front == rear) {
		front = rear = -1;
	}
	else {
		front = (front + 1) % MAXSIZE;
	}

	return data;
}

int main(int argc, char *argv[]) {

	return 0;
}

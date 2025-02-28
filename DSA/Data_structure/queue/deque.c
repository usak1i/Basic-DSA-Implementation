#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5

int deque[MAX_SIZE];
int front = -1;
int rear = -1;

void insertfront(int val);
void insertrear(int val);
void removefront();
void removerear();
void peekfront();
void peekrear();
bool isEmpty();
bool isFull();
void print_deque();

int main(int argc, char *argv[]) {
	if (isFull())
		printf("Deque is full\n");
	if (isEmpty())
		printf("Deque is empty\n");


	insertfront(3);
	insertfront(6);
	insertfront(9);
	insertfront(12);
	insertfront(15);

	print_deque();

	if (isFull())
		printf("Deque is full\n");

	removerear();
	removefront();
	insertrear(15);

	print_deque();

	return 0;
}

bool isFull() {
	return ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1));
}

bool isEmpty() {
	return front == -1;
}

void insertfront(int val) {
	if (isFull()) {
		printf("Overflow: Deque is already full\n");
		return;
	}
	
	if (front == 0) {
		front = MAX_SIZE - 1;
	} else if (front == -1) {
		front = 0;
		rear = 0;
	} else {
		front = front - 1;
	}

	deque[front] = val;
}

void insertrear(int val) {
	if (isFull()) {
		printf("Overflow: Deque is already full\n");
		return;
	}

	if (rear == -1) {
		front = 0;
		rear = 0;
	} else if (rear == MAX_SIZE - 1) {
		rear = 0;
	} else {
		rear++;
	}

	deque[rear] = val;
}

void removefront() {
	if (isEmpty()) {
		printf("Underflow: There is nothing to remove\n");
		return;
	}

	if (front == rear) {
		front = -1;
		rear = -1;
	} else if (front == MAX_SIZE - 1) {
		front = 0;
	} else {
		front = front + 1;
	}
}

void removerear() {
	if (isEmpty()) {
		printf("Underflow: There is nothing to remove\n");
		return;
	}

	if (front == rear) {
		front = -1;
		rear = -1;
	} else if (rear == 0) {
		rear = MAX_SIZE - 1;
	} else {
		rear--;
	}
}

void print_deque() {
	if (isEmpty()) {
		printf("Deque is Empty\n");
		return;
	}

	int i = front;
	while (true) {
		printf(" %d", deque[i]);
		if (i == rear) 
			break;
		i = (i + 1) % MAX_SIZE;
	}
	printf("\n");
}

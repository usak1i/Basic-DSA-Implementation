#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

typedef struct {
	Node *front;
	Node *rear;
} Queue;

Node *createNode(int val) {
	Node *new = malloc(sizeof(Node));

	if (new == NULL) {
		printf("Failed to create new node\n");
		return NULL;
	}

	new->data = val;
	new->next = NULL;

	return new;
}

Queue *createQueue() {
	Queue *q = (Queue *)malloc(sizeof(Queue));
	q->front = NULL;
	q->rear = NULL;

	return q;
}

int isEmpty(Queue *q) {
	if (q->front == NULL && q->rear == NULL)
		return 1;

	return 0;
}

void enqueue(Queue *q, int val) {
	Node *new = createNode(val);

	if (q->rear == NULL) {
		q->front = q->rear = new;
		return;
	}

	q->rear->next = new;
	q->rear = new;
}

int dequeue(Queue *q) {
	if (isEmpty(q)) {
		printf("Underflow: Queue is alreafy empty\n");
		return 0;
	}

	Node *temp = q->front;
	q->front = q->front->next;
	
	int pop_val = temp->data;
	
	if (q->front == NULL) 
		q->rear = NULL;

	free(temp);

	return pop_val;
}

int getfront(Queue *q) {
	if (isEmpty(q)) {
		printf("Queue is empty");
		return -1;
	}

	return q->front->data;
}

int getrear(Queue *q) {
	if(isEmpty(q)) {
		printf("Queue is empty");
		return -1;
	} 

	return q->rear->data;
}

void printQueue(Queue *q) {
	Node *temp = q->front;

	while (temp != q->rear->next) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	Queue *q = createQueue();

	enqueue(q, 3);
	enqueue(q, 6);
	enqueue(q, 9);

	printf("%d -> %d -> %d\n", q->front->data, q->front->next->data, q->front->next->next->data);
	
	printQueue(q);

	printf("front: %d\n", getfront(q));
	printf("rear: %d\n", getrear(q));

	printf("%d is pop from the queue\n", dequeue(q));

	printf("front: %d\n", getfront(q));
	printf("rear: %d\n", getrear(q));

	//printQueue(q);

	return 0;
}

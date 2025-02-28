#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	void *link;
} Node;

Node *top = NULL;

void Push(int x);
int Pop();
void Top();
void Isempty();
void Print();

int main(int argc, char **argv) {

	/*
	Push(3);
	Print();
	Push(6);
	Print();
	Top();
	Push(9);
	Print();
	printf("%d is poped\n", Pop());
	Print();
	Isempty();
	Pop();
	Print();
	Pop();
	Print();
	Isempty();
	*/

	return 0;
}

void Push(int x) {
	Node *temp = malloc(sizeof(Node));

	if (temp == NULL) {
		printf("Failed to allocate memeory\n");
		return;
	}

	temp->data = x;
	temp->link = top;
	top = temp;
}

int Pop() {
	Node *temp = top;

	if (top == NULL) {
		printf("Error: no element to pop\n");
		return -1;
	}
	
	temp = top;
	int popval = temp->data;
	top = top->link;
	free(temp);

	return popval;
}

void Top() {
	printf("Top value of stack is %d\n", top->data);
}

void Isempty() {
	if (top == NULL) {
		printf("There is no element in stack\n");
	} else {
		printf("stack is not empty\n");
	}
}

void Print() {
	Node *curr = top;
	printf("stack: ");
	while (curr != NULL) {
		printf("%d ", curr->data);
		curr = curr->link;
	}
	printf("\n");
}

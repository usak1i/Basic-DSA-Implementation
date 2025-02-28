#include <stdio.h>
#include "stdlib.h"
#include <limits.h>

#define MAX_SIZE 100

typedef struct {
	int top;
	unsigned capacity;
	int *arr;
} Stack;

void push(Stack *stack, int value);
int pop(Stack *stack);
int Top(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);

Stack *initStack(unsigned capacity) {
	Stack *stack = (Stack*)malloc(sizeof(Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->arr = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

int main(int argc, char *argv[]) {
	Stack *stack = initStack(MAX_SIZE);

	if (isFull(stack) == 1) {
		printf("Stack is full\n");
	} else {
		printf("Stakc is not full\n");
	}

	if (isEmpty(stack) == 1) {
		printf("Stack is empty\n");
	} else {
		printf("Stakc is not empty\n");
	}

	push(stack, 3);

	if (isEmpty(stack) == 1) {
		printf("Stack is empty\n");
	} else {
		printf("Stakc is not empty\n");
	}

	push(stack, 6);
	push(stack, 9);
	
	printf("Top value of stack is %d\n", Top(stack));
	printf("%d is poped from stack\n", pop(stack));
	printf("Top value of stack is %d\n", Top(stack));

	return 0;
}

int isFull(Stack *stack) {
	return stack->top == stack->capacity - 1;
}

int isEmpty(Stack *stack) {
	return stack->top == -1;
}

void push(Stack *stack, int value) {
	if (isFull(stack))
		return;
	stack->arr[++stack->top] = value;
	printf("Push %d to stack\n", value);
}

int pop(Stack *stack) {
	if (isEmpty(stack)) 
		return INT_MIN;
	return stack->arr[stack->top--];
}

int Top(Stack *stack) {
	if (isEmpty(stack)) {
		printf("Stack is empty\n");
		return -1;
	}
	return stack->arr[stack->top];
}

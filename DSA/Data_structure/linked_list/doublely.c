#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *prev;
	struct Node *next;
} Node;

Node *create(int val) {
	Node *new = malloc(sizeof(Node));
	if (new == NULL) {
		printf("Failed to created new node\n");
		return 0;
	}

	new->data = val;
	new->prev = NULL;
	new-> next = NULL;

	return new;
}

Node *insertBegin(Node *head, int val) {
	Node *new = create(val);

	new->next = head;

	if (head != NULL)
		head->prev = new;

	return new;
}

void printlist(Node *head) {
	Node *ptr = head;

	while (ptr != NULL) {
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int main() {
	Node *head = create(3);
	head->next = create(6);
	head->next->prev = head;

	printlist(head);

	insertBegin(head, 9);
	insertBegin(head, 12);

	printlist(head);
	return 0;
}

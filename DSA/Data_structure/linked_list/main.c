#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int val;
	void *next;
} Node;

Node *head = NULL;

void printlist();
int Remove(int target);
Node *add(int val);
Node *insert(int val, int pos);
void reverse();

int main(int argc, char *argv[]) {
	add(3);
	printlist();
	add(6);
	printlist();
	add(9);
	printlist();
	insert(12, 4);
	printlist();
	reverse();
	printlist();

	return 0;
}


Node *add(int val) {
	Node *new = (Node *)malloc(sizeof(Node));
	
	if (new == NULL) {
		printf("Failed to create new node\n");
		return NULL;
	}

	if (head == NULL) {
		new->val = val;
		head = new;
		new->next = NULL;
	} else {
		new->val = val;
		new->next = head;
		head = new;
	}

	return new;
}

void reverse() {
	Node *prev = NULL;
	Node *curr = head;
	Node *next = NULL;

	while (curr != 0) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	head = prev;
}

void printlist() {
	Node *curr = head;
	while (curr != NULL) {
		printf("%d->", curr->val);
		curr = curr->next;
	}
	printf("\n");
}

int Remove(int target) {
	Node *prev = head;
	Node *curr = head;

	while (curr != NULL) {
		if (curr->val == target) 
		{
			if (curr == head) {
				head = curr->next;
				free(curr);
				curr = NULL;
			} else {
				prev->next = curr->next;
				free(curr);
				curr = NULL;
			}

			return 1;
		} 
		prev = curr;
		curr = curr->next;
	}

	return -1;
}

Node *insert(int val, int pos) {
	Node *curr = head;

	while(curr != NULL && pos != 1) {
		curr = curr->next;
		pos--;
	}

	if (pos != 1 || curr == NULL) {
		printf("Requested position is too far to list\n");
		return NULL;
	} 
	
	Node *new = (Node *)malloc(sizeof(Node));

	new->val = val;
	new->next = curr->next;	
	curr->next = new;

	return new;
}

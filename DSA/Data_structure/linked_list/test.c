#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	void *next;
} Node;

Node* head = NULL;

Node* addNode(int data) {
	Node *new = NULL;

	if (head == NULL) {
		new = malloc(sizeof(Node));
		if (new == NULL)
			return NULL;

		new->data = data;
		head = new;
		new->next = NULL;
	} else {
		new = malloc(sizeof(Node));
		if (new == NULL)
			return NULL;

		new->data = data;
		new->next = head;
		head = new;
	}

	return new;
}

int removeNode(int target) {
	Node* curr = head;
	Node* prev = head;

	while (curr != NULL) {
		if (curr->data == target) {
			if (curr == head) {
				head = curr->next;
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
	return 0;
}

Node *Insert(int data, int position) {
	Node *curr = head;

	while (curr != NULL && position != 0) {
		curr = curr->next;
		position--;
	}

	if (position != 0) {
		printf("- - - Requested position is too far away - - -\n");
		return NULL;
	}
	Node *new = malloc(sizeof(Node));

	if (new == NULL) 
		return NULL;

	new->data = data;
	new->next = curr->next;
	curr->next = new;

	return new;
}

void reverseList() {
	Node *curr = head;
	Node *prev = NULL;

	while (curr != NULL) {
		Node *next_node = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next_node;
	}
	head = prev;
}

void printList() {
	Node* current = head;

	printf("List: ");
	while (current != NULL) {
		printf("%d->", current->data);
		current = current->next;
	}	
	printf("\n");
}

int main(int argc, char *argv[]) {
	int op; 
	int arg1;
	int arg2;

	while (op != 5) {
		printf("Choose a operation: ");
		printf("1.add, 2.remove, 3.insert, 4.reverse, 5.quit\n");
		int received_num = scanf("%d", &op);

		if (received_num == 1 && op > 0 && op <= 5) 
		{
			switch (op) 
			{
				// add Node
				case 1:
					printf("Enter a value: ");
					scanf("%d", &arg1);
					Node *new = addNode(arg1);
					printList();
					break;

				// remove Node
				case 2:
					printf("Enter a target value: ");
					scanf("%d", &arg1);
					int check = removeNode(arg1);

					if (check != 1)
						printf("- - - - - Target not found - - - - -\n");
					
					printList();
					break;

				// insert node
				case 3:
					printf("Enter a value: ");
					scanf("%d", &arg1);
					printf("Choose which position you want to insert: ");
					scanf("%d", &arg2);

					new = Insert(arg1, arg2);

					if (new == NULL)
						printf("- - - Failed to insert node - - -\n");

					printList();
					break;

				// reverse list
				case 4:
					reverseList();
					printList();
					
				// quit
				case 5:
					break;
			}
		} 
		else 
			printf("- - - - - Invalid option - - - - -\n");
	}
	return 0;
}







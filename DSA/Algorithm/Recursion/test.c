#include <stdio.h>
#include <stdlib.h>

struct Node {
	int val;
	struct Node *left;
	struct Node *right;
};

typedef struct Node Node;

Node *createNode(int val) {
	Node *new = malloc(sizeof(Node));
	new->val = val;
	new->left = NULL;
	new->right = NULL;
	return new;
}

void infix(Node *root) {
	if (!root) return;

	if (root->left) {
		printf("(");
		infix(root->left);
	}

	printf("%d", root->val);
	
	if (root->right) {
		infix(root->right);
		printf(")");
	}
}

void fun(int A[][5]) {
	printf("?\n");
}

int main() {
	Node *n1 = createNode(0); // +
	Node *n2 = createNode(1); // *
	Node *n3 = createNode(2); // -
	Node *n4 = createNode(3);
	Node *n5 = createNode(4);
	Node *n6 = createNode(6);
	Node *n7 = createNode(7);

	n1->left = n2;
	n1->right = n6;
	n2->left = n4;
	n2->right = n3;
	n3->left = n7;
	n3->right = n5;

	infix(n1);
	printf("\n");

	int a[5][5];
	fun(a);

	return 0;
}

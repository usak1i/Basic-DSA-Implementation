#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

int num_count = 0;

typedef struct Node {
	int val;
	struct Node *left;
	struct Node *right;
} Node;

Node *addnode(int val);
Node *insert(Node *root, int val);
Node *delete(Node *root, int target);
Node *findMax(Node *root);
Node *findMin(Node *root);
Node *search(Node *root, int target);
void traversal(Node *root);
int maxDepth(Node *root);

int main(int argc, char *argv[]) {
	Node *n1 = addnode(30);
	Node *n2 = addnode(15);
	Node *n3 = addnode(45);
	Node *n4 = addnode(10);
	Node *n5 = addnode(20);
	Node *n6 = addnode(40);
	Node *n7 = addnode(50);

	n1->left = n2;
	n1->right = n3;
	
	n2->left = n4;
	n2->right = n5;

	n3->left = n6;
	n3->right = n7;

	traversal(n1);

	Node *res = search(n1, 15);
	printf("value of res is %d\n", res->val);

	Node *min = findMin(n1);
	printf("the minimum value of the tree is %d\n", min->val);

	Node *max = findMax(n1);
	printf("The maximum value of the tree is %d\n", max->val);

	delete(n1, 20);

	printf("level of the tree is %d\n", maxDepth(n1));

	traversal(n1);

	return 0;
}

Node *addnode(int val) {
	num_count++;
	if(num_count > MAX_SIZE) {
		printf("Error: already have maximum number of nodes\n");
		return NULL;
	}

	Node *new = malloc(sizeof(Node));
	if (new == NULL) {
		printf("Error: Failed to create new node\n");
		return NULL;
	}

	new->val = val;
	new->left = NULL;
	new->right = NULL;

	return new;
}

Node *insert(Node *root, int val) {
	if (root == NULL) 
		return addnode(val);

	if (val < root->val) 
	{
		root->left = insert(root->left, val);		
	} 
	else if (val > root->val) 
	{
		root->right = insert(root->right, val);
	}

	return root;
}

Node *search(Node *root, int target) {
	if (root == NULL || root->val == target)
		return root;

	if (target < root->val) {
		return search(root->left, target);
	}	

	return search(root->right, target);
}

Node *delete(Node *root, int target) {
	if (root == NULL) 
		return root;

	if (target < root->val) 
	{
		root->left = delete(root->left, target);
	}
	else if (target > root->val) 
	{
		root->right = delete(root->right, target);
	}
	else if (target == root->val) 
	{
		if (root->left == NULL && root->right == NULL) 
		{
			free(root);
			return NULL;
		}
		else if (root->left == NULL) 
		{	
			Node *temp = root;
			root = root->right;
			free(temp);

			return root;
		}
		else if (root->right == NULL) 
		{
			Node *temp = root;
			root = root->left;
			free(temp);

			return root;
		}
		else 
		{
			Node *temp = findMax(root->left);

			root->val = temp->val;
			root->left = delete(root->left, temp->val);
		}
	}
	return root;
}

Node *findMax(Node *root) {
	if (root == NULL) 
		return NULL;

	if (root->right != NULL) 
		return findMax(root->right);

	return root;
}

Node *findMin(Node *root) {
	if (root == NULL) 
		return NULL;

	if (root->left != NULL) 
		return findMin(root->left);

	return root;
}

void traversal(Node *root) {
	if (root == NULL) {
		printf("\n");
		return;
	}	

	// Preorder traversal
	// printf(" %d", root->val);
	
	traversal(root->left);
	
	// Inorder traversal
	printf(" %d", root->val);
	
	traversal(root->right);
	
	// Postorder traversal
	// printf(" %d",  root->val);
}

int maxDepth(Node *root) {
	if (root == NULL) 
		return 0;

	int maxleft = maxDepth(root->left);
	int maxright = maxDepth(root->right);

	return fmax(maxleft, maxright) + 1;
}

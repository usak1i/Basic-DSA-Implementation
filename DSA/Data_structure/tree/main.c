#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct treenode {
	int value;
	struct treenode *left;
	struct treenode *right;
} treenode;

void print_recursive(treenode *root);
void print_tree(treenode *root);
treenode *addnode(int value);
treenode *insert(int value);
void removenode(int target);
void freetree(treenode *root);
int maxDepth(treenode *root);

int count = 0;

int main(int argc, char *argv[]) {
	treenode *node1 = addnode(1);
	treenode *node2 = addnode(2);
	treenode *node3 = addnode(3);
	treenode *node4 = addnode(4);
	treenode *node5 = addnode(5);
	treenode *node6 = addnode(6);
	treenode *node7 = addnode(7);
	treenode *node8 = addnode(8);

	node1->left = node2;
	node1->right = node3;
	
	node2->left = node4;
	node2->right = node5;
	
	node3->left = node6;
	node3->right = node7;
	
	int depth = maxDepth(node1);
	printf("The depth of the tree is %d\n", depth);

	print_tree(node1);
	printf("recursion times -> %d\n", count);

	freetree(node1);

	return 0;
}

int maxDepth(treenode *root) {
	if (root == NULL)
		return 0;

	int maxleft = maxDepth(root->left);
	int maxright = maxDepth(root->right);
	return fmax(maxleft, maxright) + 1;
}

void print_func(treenode *root, int depth) {
	/*
	 * try to print tree in this form:
	 *
	 *			 1
	 *         /   \
	 *		 2	     3
	 *	   /   \   /   \
	 *		     .
	 *		     .
	 *		     .
	 */

	char space = ' ';
	char b_slash = '\\';
	char f_slash = '/';

	for (int i = 0; i < depth; i++) {
		printf("%c", space);
	}
	printf("%d\n" ,root->value);

	for (int i = 0; i < depth - 1; i++) {
		if (root->left != NULL) {
			printf("%c", f_slash);\
		}
		if (root->right != NULL) {
			printf("    %c", b_slash);
		}
	}
	printf("\n");
}

void print_tree(treenode *root) {
	if (root == NULL) {
		printf("---empty---\n");
		return;
	}
	
	count++;

	print_tree(root->left);
	printf("%d\n", root->value);
	print_tree(root->right);
}

treenode *addnode(int value) {
	treenode *new = malloc(sizeof(treenode));
	if (new == NULL) {
		printf("Failed to create new node\n");
		return NULL;
	}
	
	new->value = value;
	new->left = NULL;
	new->right = NULL;

	return new;
}

void freetree(treenode *root) {
	if (root == NULL)
		return;

	freetree(root->left);
	freetree(root->right);
	free(root);
}

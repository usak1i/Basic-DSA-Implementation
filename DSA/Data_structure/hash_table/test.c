#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
	char key[MAX_NAME];
	int value;
} item;

void print_table();
void insert(item *p);
unsigned int hash_function(char *key);
void init_hash_table();

item *HashMap[TABLE_SIZE];

int main(int argc, char **argv) {
	init_hash_table();

	item x = {.key = "apple", .value = 3};
	item y = {.key = "mango", .value = 6};
	item z = {.key = "cherry", .value = 9};

	insert(&x);
	insert(&y);
	insert(&z);

	print_table();

	return 0;
}

void print_table() {
	printf("Start\n");
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (HashMap[i] == NULL) {
			printf("\t%i\t---\n", i);
		} else {
			printf("\t%i\t%s\n", i, HashMap[i]->key);
		}
	}
	printf("End\n");
}

void insert(item *p) {
	if(p == NULL) {
		printf("Error: nothing to input\n");
		return;
	}

	int index = hash_function(p->key);

	if (HashMap[index] != NULL) {
		return;
	}
	HashMap[index] = p;

}

unsigned int hash_function(char *key) {
	int len = strnlen(key, MAX_NAME);
	unsigned int hash_value = 0;

	for (int i = 0; i < len; i++) {
		hash_value += key[i];
		hash_value = (hash_value * key[i]) % TABLE_SIZE;
	} 
	return hash_value;
}

void init_hash_table() {
	for (int i = 0; i < TABLE_SIZE; i++) {
		HashMap[i] = NULL;
	}
	// table is empty
}

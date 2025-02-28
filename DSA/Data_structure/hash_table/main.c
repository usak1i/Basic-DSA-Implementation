#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define KEY_SIZE 100

typedef struct {
	char *key;
	char *val;
} item;

typedef struct {
	int size;
	int count;
	item **items;
} hash_table;

static item *new_item(const char *key, const char *val);
hash_table *init_table();
static void free_item(item *i);
void free_table(hash_table *ht);

int main(int argc, char *argv[]) {
	hash_table *ht = init_table();
	free_table(ht);
	return 0;
}

static item *new_item(const char *key, const char *val) {
	item *i = malloc(sizeof(item));
	if(i == NULL)
		return NULL;

	i->key = strdup(key);
	i->val = strdup(val);

	return i;
}

hash_table *init_table() {
	hash_table *HashMap = malloc(sizeof(hash_table));

	HashMap->size = TABLE_SIZE;
	HashMap->count = 0;
	HashMap->items = calloc((size_t)HashMap->size, sizeof(item*));

	return HashMap;
}

static void free_item(item *i) {
	free(i->key);
	free(i->val);
	free(i);
}

void free_table(hash_table* ht) {
	for (int i = 0; i < ht->size; i++) {
		item *ht_item = ht->items[i];

		if (ht_item != NULL)
			free(ht_item);
	}
	free(ht->items);
	free(ht);
}

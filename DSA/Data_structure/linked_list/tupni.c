#include <stdio.h> 
#include <stdlib.h>

typedef struct node {
	char c;
	struct node *next;
} node_t, *list_t;

void tupni(list_t *ptr, const char *s) {
	if (*s) {
		node_t *p = malloc(sizeof(node_t));
		p->c = *s;
		printf("%s", s);
		tupni(&p->next, s + 1);
		//printf("%c", p->c);
		*ptr = p;
	}
	else {
		*ptr = NULL;
	}
}

int main() {
	list_t p = NULL;
	tupni(&p, "abcd");
}



#include <stdbool.h>
#include <stdlib.h>

#ifndef _B_NODE
#define _B_NODE

#ifndef B_NODE_T
#define B_NODE_T int
#endif

#define T B_NODE_T

#define DIRN bool
#define LEFT false
#define RIGHT true

#define ERROR true
#define NO_ERR false

typedef struct b_node {
	T val;
	struct b_node *prev, *left, *right;
} B_NODE;

B_NODE *b_list_new(T val)
{
	B_NODE *n = malloc(sizeof(B_NODE));
	n->val = val;
	n->left = n->right = NULL;
	return n;
}

B_NODE *list_seek(B_NODE *self, const char *dirn)
{
	B_NODE *p = self;
	for (const char *c = dirn; *c != '\0'; c++) {
		if (p == NULL) {
			return NULL;
		} else {
			if (*c == 'l')
				p = p->left;
			else
				p = p->right;
		}
	}
	return p;
}


bool list_insert(B_NODE *self, const char *dirn, T val)
{
	B_NODE *p = list_seek(self, dirn);
	if (p == NULL) {
		return ERROR;
	} else {
		p->val = val;
		return NO_ERR;
	}
}

#undef ERROR
#undef NO_ERR
#undef T
#endif

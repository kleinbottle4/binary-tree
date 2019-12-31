/*
 * b_node.h
 * Copyright (C) 2019  Syed Shah

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdbool.h>
#include <stdlib.h>

#ifndef INCLUDE_B_NODE
#define INCLUDE_B_NODE

#ifndef B_NODE_T
#define B_NODE_T int
#endif

#define B_NODE_DIRN bool
#define B_NODE_LEFT false
#define B_NODE_RIGHT true

#define B_NODE_ERROR true
#define B_NODE_NO_ERR false

typedef struct b_node {
	B_NODE_T val;
	struct b_node *prev, *left, *right;
} B_NODE;

B_NODE *b_list_new(B_NODE_T val)
{
	B_NODE *n = malloc(sizeof(B_NODE));
	n->val = val;
	n->left = n->right = NULL;
	return n;
}


B_NODE *b_list_seek(B_NODE *self, const char *dirn)
{
	B_NODE *p = self;
	for (const char *c = dirn; *c != '\0'; c++) {
		if (p == NULL)
			return NULL;
		else
			p = *c == 'l' ? p->left : p->right;
	}
	return p;
}


bool b_list_insert
(B_NODE *self, const char *dirns, B_NODE_DIRN dirn, B_NODE_T val)
{
	B_NODE *p = b_list_seek(self, dirns);
	if (p == NULL) {
		return B_NODE_ERROR;
	} else {
		B_NODE *n;
		if (dirn == B_NODE_LEFT) {
			p->left = malloc(sizeof(B_NODE));
			n = p->left;
		} else {
			p->right = malloc(sizeof(B_NODE));
			n = p->right;
		}
		n->val = val;
		return B_NODE_NO_ERR;
	}
}

bool b_list_set(B_NODE *self, const char *dirn, B_NODE_T val)
{
	B_NODE *p = b_list_seek(self, dirn);
	if (p == NULL) {
		return B_NODE_ERROR;
	} else {
		p->val = val;
		return B_NODE_NO_ERR;
	}
}

#endif

/*
 * binary_tree.h
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

#ifndef INCLUDE_TREE
#define INCLUDE_TREE

#ifndef B_NODE_T
#define B_NODE_T int
#endif

#define BT_DIRN bool
#define BT_LEFT false
#define BT_RIGHT true

#define BT_ERR true
#define BT_NO_ERR false

typedef struct b_node {
	B_NODE_T val;
	struct b_node *prev, *left, *right;
} B_NODE;

B_NODE   *tree_new   (B_NODE_T val);
B_NODE   *tree_seek  (B_NODE *, const char *);
bool      tree_insert(B_NODE *, const char *, BT_DIRN, B_NODE_T);
bool      tree_set   (B_NODE *, const char *, B_NODE_T);

B_NODE *tree_new (B_NODE_T val)
{
	B_NODE *n = malloc(sizeof(B_NODE));
	n->val = val;
	n->left = n->right = NULL;
	return n;
}


B_NODE *tree_seek(B_NODE *self, const char *dirn)
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


bool tree_insert
(B_NODE *self, const char *dirns, BT_DIRN dirn, B_NODE_T val)
{
	B_NODE *p = tree_seek(self, dirns);
	if (p == NULL) {
		return BT_ERR;
	} else {
		B_NODE *n;
		if (dirn == BT_LEFT) {
			p->left = malloc(sizeof(B_NODE));
			n = p->left;
		} else {
			p->right = malloc(sizeof(B_NODE));
			n = p->right;
		}
		n->val = val;
		return BT_NO_ERR;
	}
}

bool tree_set(B_NODE *self, const char *dirn, B_NODE_T val)
{
	B_NODE *p = tree_seek(self, dirn);
	if (p == NULL) {
		return BT_ERR;
	} else {
		p->val = val;
		return BT_NO_ERR;
	}
}

#endif

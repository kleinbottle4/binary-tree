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

#ifndef LEAF_T
#define LEAF_T int
#endif

#define BRANCH_DIRN bool
#define BRANCH_LEFT false
#define BRANCH_RIGHT true

#define LEAF_ERROR true
#define LEAF_NO_ERR false

typedef struct leaf {
	T_NODE_T val;
	struct leaf *prev, *left, *right;
} LEAF;

LEAF   *tree_new   (LEAF_T val);
LEAF   *tree_seek  (LEAF_T *, const char *);
bool    tree_insert(LEAF_T *, const char *, BRANCH_DIRN, LEAF_T);
bool    tree_set   (LEAF_T *, const char *, LEAF_T);

LEAF *tree_new (LEAF_T val)
{
	LEAF *n = malloc(sizeof(LEAF));
	n->val = val;
	n->left = n->right = NULL;
	return n;
}


LEAF *tree_seek(LEAF *self, const char *dirn)
{
	LEAF *p = self;
	for (const char *c = dirn; *c != '\0'; c++) {
		if (p == NULL)
			return NULL;
		else
			p = *c == 'l' ? p->left : p->right;
	}
	return p;
}


bool tree_insert
(LEAF *self, const char *dirns, TREE_DIRN dirn, LEAF_T val)
{
	LEAF *p = tree_seek(self, dirns);
	if (p == NULL) {
		return TREE_ERROR;
	} else {
		LEAF *n;
		if (dirn == TREE_LEFT) {
			p->left = malloc(sizeof(LEAF));
			n = p->left;
		} else {
			p->right = malloc(sizeof(LEAF));
			n = p->right;
		}
		n->val = val;
		return TREE_NO_ERR;
	}
}

bool tree_set(LEAF *self, const char *dirn, LEAF_T val)
{
	LEAF *p = tree_seek(self, dirn);
	if (p == NULL) {
		return TREE_ERROR;
	} else {
		p->val = val;
		return TREE_NO_ERR;
	}
}

#endif

#include "binary_tree.h"
#include <stdio.h>
#include <stdbool.h>

bool test_insert(B_NODE *b, const char *s, BT_DIRN d, B_NODE_T i)
{
	const char *dir = d == BT_LEFT ? "l" : "r";
	printf("Inserting node at '%s%s'...\n", s, dir);
	bool rtn = tree_insert(b, s, d, i);
	puts("Done.\n");
	return rtn;
}

B_NODE *test_seek(B_NODE *b, const char *s)
{
	printf("Seeking node at '%s'...\n", s);
	B_NODE *rtn = tree_seek(b, s);
	puts("Done.\n");
	return rtn;
}

void print_val(B_NODE *b, bool e)
{
	printf("Printing value of b_node (0x%x)...\n", b);
	if (e != BT_ERR) {
		printf("%d\n", b->val);
	} else 
		puts("Error");
	putchar('\n');
}


int main(void)
{
	puts("Creating new b_list...");
	B_NODE *b = tree_new(0);

	bool err1 = test_insert(b, "", BT_LEFT, 1);
	bool err2 = test_insert(b, "", BT_RIGHT, 2);

	B_NODE *z = test_seek(b, "l");
	B_NODE *y = test_seek(b, "r");
	B_NODE *x = test_seek(b, "");
	/* (head of list) */

	print_val(x, BT_NO_ERR);
	print_val(z, err1);
	print_val(y, err2);
	return 0;
}

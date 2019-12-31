#include "b_node.h"
#include <stdio.h>
#include <stdbool.h>

bool test_insert(B_NODE *b, const char *s, B_NODE_DIRN d, B_NODE_T i)
{
	const char *dir = d == B_NODE_LEFT ? "l" : "r";
	printf("Inserting node at '%s%s'...\n", s, dir);
	bool rtn = b_list_insert(b, s, d, i);
	puts("Done.\n");
	return rtn;
}

B_NODE *test_seek(B_NODE *b, const char *s)
{
	printf("Seeking node at '%s'...\n", s);
	B_NODE *rtn = b_list_seek(b, s);
	puts("Done.\n");
	return rtn;
}

void print_val(B_NODE *b, bool e)
{
	printf("Printing value of b_node (0x%x)...\n", b);
	if (e != B_NODE_ERROR) {
		printf("%d\n", b->val);
	} else
		puts("Error");
	putchar('\n');
}


int main(void)
{
	puts("Creating new b_list...");
	B_NODE *b = b_list_new(0);

	bool err1 = test_insert(b, "", B_NODE_LEFT, 1);
	bool err2 = test_insert(b, "", B_NODE_RIGHT, 2);
	B_NODE *z = test_seek(b, "l");
	B_NODE *y = test_seek(b, "r");
	B_NODE *x = test_seek(b, "");
	print_val(z, err1);
	print_val(y, err2);
	print_val(x, B_NODE_NO_ERR);
	return 0;
}

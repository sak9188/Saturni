#include <stdio.h>
#include <stdlib.h>

#include <opcode.h>

#ifndef MAXSTACK
#define MAXSTACK 512
#endif

static Object stack[MAXSTACK] = {{T_MARK, {NULL}}};
static Object *top=stack+1, *base=stack+1;

int main()
{
	Byte* pc = calloc(1, sizeof(Byte));
	*pc = 1;
	printf("id: %p\n", pc);
	printf("base: %p\n", base);
	Object* newtop = base + *(pc++);
	printf("size_of: %d\n", sizeof(Object));
	printf("id: %p\n", newtop);
	return 0;
}
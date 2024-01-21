#include "monty.h"
/**
* _free_stackt - frees a doubly linked list
* @top: top of the stack
*/
void _free_stackt(stack_t *top)
{
	stack_t *rit;

	rit = top;
	while (top)
	{
		rit = top->next;
		free(top);
		top = rit;
	}
}

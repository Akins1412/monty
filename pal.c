#include "monty.h"
/**
 * _pallt - prints the stack
 * @top: stack top
 * @linumb: line num where opcode is found (unused)
*/
void _pallt(stack_t **top, unsigned int linumb)
{
	stack_t *allt;
	(void)linumb;

	allt = *top;
	if (allt == NULL)
		return;
	while (allt)
	{
		printf("%d\n", allt->n);
		allt = allt->next;
	}
}

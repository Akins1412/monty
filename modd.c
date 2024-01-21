#include "monty.h"
/**
 * _modt - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @tpr: stack head
 * @linumb: line_number
*/
void _modt(stack_t **tpr, unsigned int linumb)
{
	stack_t *bit;
	int len = 0, alt;

	bit = *tpr;
	while (bit)
	{
		bit = bit->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", linumb);
		fclose(glob.file);
		free(glob.cont);
		_free_stackt(*tpr);
		exit(EXIT_FAILURE);
	}
	bit = *tpr;
	if (bit->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", linumb);
		fclose(glob.file);
		free(glob.cont);
		_free_stackt(*tpr);
		exit(EXIT_FAILURE);
	}
	alt = bit->next->n % bit->n;
	bit->next->n = alt;
	*tpr = bit->next;
	free(bit);
}

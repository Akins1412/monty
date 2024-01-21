#include "monty.h"
/**
 * _mult - multiplies the top two elements of the stack.
 * @tpr: stack head
 * @linumb: line_number
*/
void _mult(stack_t **tpr, unsigned int linumb)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", linumb);
		fclose(glob.file);
		free(glob.cont);
		_free_stackt(*tpr);
		exit(EXIT_FAILURE);
	}
	bit = *tpr;
	alt = bit->next->n * bit->n;
	bit->next->n = alt;
	*tpr = bit->next;
	free(bit);
}

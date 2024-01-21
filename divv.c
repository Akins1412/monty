#include "monty.h"
/**
 * _divt - divides the top two elements of the stack.
 * @tpr: stack head
 * @linumb: line_number
*/
void _divt(stack_t **tpr, unsigned int linumb)
{
	stack_t *rit;
	int len = 0, alt;

	rit = *tpr;
	while (rit)
	{
		rit = rit->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", linumb);
		fclose(glob.file);
		free(glob.cont);
		_free_stackt(*tpr);
		exit(EXIT_FAILURE);
	}
	rit = *tpr;
	if (rit->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", linumb);
		fclose(glob.file);
		free(glob.cont);
		_free_stackt(*tpr);
		exit(EXIT_FAILURE);
	}
	alt = rit->next->n / rit->n;
	rit->next->n = alt;
	*tpr = rit->next;
	free(rit);
}

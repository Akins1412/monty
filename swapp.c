#include "monty.h"
/**
 * _swapt - adds the top two elements of the stack.
 * @tpr: stack head
 * @linumb: line_number
*/
void _swapt(stack_t **tpr, unsigned int linumb)
{
	stack_t *allt;
	int len = 0, bit;

	allt = *tpr;
	while (allt)
	{
		allt = allt->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", linumb);
		fclose(glob.file);
		free(glob.cont);
		_free_stackt(*tpr);
		exit(EXIT_FAILURE);
	}
	allt = *tpr;
	bit = allt->n;
	allt->n = allt->next->n;
	allt->next->n = bit;
}

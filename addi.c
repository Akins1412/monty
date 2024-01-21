#include "monty.h"
/**
 * _addit - adds the top two elements of the stack.
 * @tpr: stack head
 * @linumb: line_number
*/
void _addit(stack_t **tpr, unsigned int linumb)
{
	stack_t *alt;
	int len = 0, bit;

	alt = *tpr;
	while (alt)
	{
		alt = alt->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", linumb);
		fclose(glob.file);
		free(glob.cont);
		_free_stackt(*tpr);
		exit(EXIT_FAILURE);
	}
	alt = *tpr;
	bit = alt->n + alt->next->n;
	alt->next->n = bit;
	*tpr = alt->next;
	free(alt);
}

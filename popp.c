#include "monty.h"
/**
 * _popt - prints the top of the stack
 * @tpr: stack head
 * @linumb: line_number
*/
void _pop(stack_t **tpr, unsigned int linumb)
{
	stack_t *allt;

	if (*tpr == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", linumb);
		fclose(glob.file);
		free(glob.cont);
		_free_stackt(*tpr);
		exit(EXIT_FAILURE);
	}
	allt = *tpr;
	*tpr = allt->next;
	free(allt);
}

#include "monty.h"
/**
  *_subt- sustration
  *@tpr: stack head
  *@linumb: line_number
 */
void _subt(stack_t **tpr, unsigned int linumb)
{
	stack_t *allt;
	int len = 0, bit;

	allt = *tpr;
	for (bit = 0; allt != NULL; bit++)
		allt = allt->next;
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", linumb);
		fclose(glob.file);
		free(glob.cont);
		_free_stackt(*tpr);
		exit(EXIT_FAILURE);
	}
	allt = *tpr;
	bit = allt->next->n - allt->n;
	allt->next->n = bit;
	*tpr = allt->next;
	free(allt);
}

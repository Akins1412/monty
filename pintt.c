#include "monty.h"
/**
 * _pintt - prints the top of the stack
 * @tpr: stack head
 * @linumb: line_number
*/
void _pintt(stack_t **tpr, unsigned int linumb)
{
	if (*tpr == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", linumb);
		fclose(glob.file);
		free(glob.cont);
		_free_stackt(*tpr);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*tpr)->n);
}

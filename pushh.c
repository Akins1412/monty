#include "monty.h"
/**
 * _pusht - adds a node to the stack
 * @top: double pointer to the top of the stack
 * @linumb: the line number where the opcode is
*/
void _pusht(stack_t **top, unsigned int linumb)
{
	int n, k = 0, bags = 0;

	if (glob.arg)
	{
		if (glob.arg[0] == '-')
			k++;
		for (; glob.arg[k] != '\0'; k++)
		{
			if (glob.arg[k] > 57 || glob.arg[k] < 48)
				bags = 1;
		}
		if (bags == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", linumb);
			fclose(glob.file);
			free(glob.cont);
			_free_stackt(*top);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", linumb);
		fclose(glob.file);
		free(glob.cont);
		_free_stackt(*top);
		exit(EXIT_FAILURE);
	}
	n = atoi(glob.arg);
	if (glob.lifi == 0)
		_addnodet(top, n);
	else
		_addqueuet(top, n);
}

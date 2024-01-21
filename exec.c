#include "monty.h"
/**
* _executet - executes the opcode
* @tpr: head linked list - (stack)
* @linumb: line_counter
* @file: poiner to monty file
* @cont: line content
* Return: no return
*/
int _executet(char *cont, stack_t **tpr, unsigned int linumb, FILE *file)
{
	instruction_t opst[] = {
				{"push", _pusht}, {"pall", _pallt}, {"pint", _pintt},
				{"pop", _popt},
				{"swap", _swapt},
				{"add", _addit},
				{"nop", _nopt},
				{"sub", _subt},
				{"div", _divt},
				{"mul", _mult},
				{"mod", _mod},
				{"stack", _stackt},
				{"queue", _queue},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(cont, " \n\t");
	if (op && op[0] == '#')
		return (0);
	glob.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(tpr, linumb);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", linumb, op);
		fclose(file);
		free(cont);
		_free_stackt(*tpr);
		exit(EXIT_FAILURE); }
	return (1);
}

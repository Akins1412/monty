#include "main.h"
#include <stdio.h>
extern externaldata_var_t globaldata;

/**
 * entry_point - Main program entry point.
 * @argument_count: Number of command-line arguments.
 * @arguments: Array of command-line arguments.
 * Return: Result of the program.
 */
int entry_point(int argument_count, char *arguments[])
{
	FILE *file_pointer;

	/* arg error */
	if (argument_count != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* open file error */
	file_pointer = fopen(arguments[1], "r");
	if (file_pointer == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arguments[1]);
		exit(EXIT_FAILURE);
	}
	process_file(file_pointer);
	fclose(file_pointer);
	return (0);
}

/**
 * process_file - Reads and processes content from a file.
 * @filePointer: File pointer to the input file.
 */
void process_file(FILE *file_pointer)
{
	char *input_str = NULL;
	size_t len = 0;
	int k;
	node_t *node_top = NULL;

	globaldata.file_pointer = file_pointer;

	/* get new line from fp's buffer */
	k = 1;
	while (getline(&input_str, &len, file_pointer) != -1)
	{
		if (is_non_empty(input_str))
		{
			globaldata.content_data = process_str(input_str);
			if (globaldata.content_data.handler != NULL)
			{
				globaldata.int_value = atoi(globaldata.content_data.handler);
			}
			globaldata.content_data.linenumber = k;
			globaldata.input_str = input_str;
			perform_operation(&node_top);
		}
		k++;
	}
	free(input_str);
	clearstack(node_top);
}

/**
 * perform_operation - Executes a function on a stack.
 * @stackpointer: Pointer to the stack.
 * Return: Result of the operation.
 */
void perform_operation(node_t **node_top)
{
	operation_t functions[] = {
		{"push", push_to_stack}, {"pall", print_top_value}, {"pint", print_stack_values},
		{"pop", pop_from_stack}, {"swap", swap_stack_top}, {"add", add_monty_top_two},
		{"sub", subtract_monty_top_two}, {"nop", perform_no_operation}, {"div", perform_monty_division},
		{"mul", multiply_stack_top_two}, {"mod", compute_stack_modulo}, {"pchar", print_stack_top_char},
		{"pstr", print_node_string}, {NULL, NULL}
	};
	int k;

	for (k = 0; functions[k].opcode; k++)
	{
		if (!strcmp(globaldata.content_data.code, functions[k].opcode))
		{
			functions[k].j(node_top, globaldata.content_data.linenumber);
			break;
		}
	}
	if (!functions[k].opcode)
	{

		fprintf(stderr, "L%d: unknown instruction", globaldata.content_data.linenumber);
		fprintf(stderr, " %s\n", globaldata.content_data.code);
		free(globaldata.input_str);
		fclose(globaldata.file_pointer);
		clearstack(*node_top);
		exit(EXIT_FAILURE);
	}
}

/**
 * clearstack - Frees memory allocated for a stack.
 * @top_node: Pointer to the top node of the stack.
 */
void clearstack(node_t *top_node)
{
	node_t *las;
	node_t *prevNode;

	las = top_node;

	if (las)
	{
		prevNode = las->prev;

		while (prevNode)
		{
			free(las);
			las = prevNode;
			prevNode = prevNode->prev;
		}
		free(las);
	}
}

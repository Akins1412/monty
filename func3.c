#include "monty.h"

/**
 * perform_no_operation - No operation to be performed here.
 * @node_top: Pointer to the top of the stack.
 * @line_number: Line number where the 'nop' operation is called.
 */
void perform_no_operation(node_t **node_top, unsigned int line_number)
{
	*node_top = *node_top;
	line_number = line_number;
}

/**
 * print_stack_top_char - Print the character value at the top of the stack
 * followed by a new line.
 * @node_top: Pointer to the top of the stack.
 * @line_number: Line number where the 'pchar' operation is called.
 */
void print_stack_top_char(node_t **node_top, unsigned int line_number)
{
	if (!(*node_top))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free(globaldata.input_str);
		fclose(globaldata.file_pointer);
		clearstack(*node_top);
		exit(EXIT_FAILURE);
	}
	if (isascii((*node_top)->data))
		printf("%c\n", (char)((*node_top)->data));
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free(globaldata.input_str);
		fclose(globaldata.file_pointer);
		clearstack(*node_top);
		exit(EXIT_FAILURE);
	}
}

/**
 * print_node_string - Print the string starting from the top of the stack
 * until a zero (NULL) value is encountered, followed by a new line.
 * @node_top: Pointer to the top of the stack.
 * @line_number: Line number where the 'pstr' operation is called.
 */
void print_node_string(node_t **node_top, unsigned int line_number)
{
	node_t *aux_node = *node_top;

	(void)line_number;

	if (!node_top || !(*node_top))
	{
		putchar(10);
		return;
	}
	while (aux_node)
	{
		if (isascii(aux_node->data) && aux_node->data != 0)
		{
			printf("%c", (char)(aux_node->data));
		}
		else
			break;
		aux_node = aux_node->prev;
	}
	putchar(10);
}

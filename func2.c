#include "main.h"

/**
 * add_monty_top_two - Adds the top two elements of the stack.
 * @node_top: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void add_monty_top_two(node_t **node_top, unsigned int line_number)
{
	node_t *las = *node_top;

	if (!las || !las->prev)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free(globaldata.input_str);
		fclose(globaldata.file_pointer);
		clearstack(*node_top);
		exit(EXIT_FAILURE);
	}
	las->prev->data += las->data;

	pop_from_stack(node_top, line_number);
}

/**
 * subtract_monty_top_two - Subtracts top element from second top element stack
 * @node_top: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void subtract_monty_top_two(node_t **node_top, unsigned int line_number)
{
	node_t *las = *node_top;

	if (!las || !las->prev)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free(globaldata.input_str);
		fclose(globaldata.file_pointer);
		clearstack(*node_top);
		exit(EXIT_FAILURE);
	}
	las->prev->data -= las->data;

	pop_from_stack(node_top, line_number);
}

/**
 * perform_monty_division - Divide the second top element of the stack
 * by the top element of the stack.
 * @node_top: Pointer to the top of the stack.
 * @line_number: Line number where the division operation is called.
 */
void perform_monty_division(node_t **node_top, unsigned int line_number)
{
	node_t *las = *node_top;

	if (!las || !las->prev)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free(globaldata.input_str);
		fclose(globaldata.file_pointer);
		clearstack(*node_top);
		exit(EXIT_FAILURE);
	}
	if (las->data != 0)
		las->prev->data /= las->data;
	else
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free(globaldata.input_str);
		fclose(globaldata.file_pointer);
		clearstack(*node_top);
		exit(EXIT_FAILURE);
	}
	pop_from_stack(node_top, line_number);
}

/**
 * multiply_monty_top_two - Multiply the second top element of the stack
 * with the top element of the stack.
 * @node_top: Pointer to the top of the stack.
 * @line_number: Line number where the multiplication operation is called.
 */
void multiply_stack_top_two(node_t **node_top, unsigned int line_number)
{
	node_t *las = *node_top;

	if (!las || !las->prev)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free(globaldata.input_str);
		fclose(globaldata.file_pointer);
		clearstack(*node_top);
		exit(EXIT_FAILURE);
	}
	las->prev->data *= las->data;

	pop_from_stack(node_top, line_number);
}

/**
 * compute_stack_modulo - Compute the remainder of the division of the
 * second top element of the stack by the top element of the stack.
 * @node_top: Pointer to the top of the stack.
 * @line_number: Line number where the modulo operation is called.
 */
void compute_stack_modulo(node_t **node_top, unsigned int line_number)
{
	node_t *las = *node_top;

	if (!las || !las->prev)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free(globaldata.input_str);
		fclose(globaldata.file_pointer);
		clearstack(*node_top);
		exit(EXIT_FAILURE);
	}
	if (las->data != 0)
		las->prev->data %= las->data;
	else
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free(globaldata.input_str);
		fclose(globaldata.file_pointer);
		clearstack(*node_top);
		exit(EXIT_FAILURE);
	}

	pop_from_stack(node_top, line_number);
}

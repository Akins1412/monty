#include "monty.h"

/**
 * push_to_stack - Pushes an element onto the stack.
 * @node_top: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void push_to_stack(node_t **top_node, unsigned int line_number)
{
	/* temporal, esto en realidad viene en la variable externa */
	node_t *new_node, *node_top = *top_node;

	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(globaldata.input_str);
		fclose(globaldata.file_pointer);
		clearstack(*top_node);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(node_t));
	if (!new_node)
	{
		/*free function*/
		fprintf(stderr, "Error: malloc failed\n");
		free(globaldata.input_str);
		fclose(globaldata.file_pointer);
		clearstack(*top_node);
		exit(EXIT_FAILURE);
	}
	new_node->data = globaldata.int_value;

	if (!node_top)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*top_node = new_node;
	}
	else
	{
		new_node->next = NULL;
		new_node->prev = node_top;
		node_top->next = new_node;
		*top_node = new_node;
	}
}

/**
 * print_stack_values - Prints all values on the stack from the top.
 * @node_top: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void print_stack_values(node_t **node_top, unsigned int line_number)
{
	/* temporal, esto en realidad viene en la variable externa */
	node_t *aux = *node_top;

	(void)line_number;
	while (aux)
	{
		printf("%d\n", aux->data);
		aux = aux->prev;
	}
}

/**
 * print_top_value - Prints the value on top of stack followed by a new line.
 * @node_top: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void print_top_value(node_t **node_top, unsigned int line_number)
{
	if (!(*node_top))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free(globaldata.input_str);
		fclose(globaldata.file_pointer);
		clearstack(*node_top);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*node_top)->data);
}

/**
 * pop_from_stack - Removes the top element from the stack.
 * @node_top: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void pop_from_stack(node_t **node_top, unsigned int line_number)
{
	node_t *pop = *node_top;

	if (!pop)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free(globaldata.input_str);
		fclose(globaldata.file_pointer);
		clearstack(*node_top);
		exit(EXIT_FAILURE);
	}
	pop = *node_top;
	if (pop->prev != NULL)
	{
		pop->prev->next = NULL;
		*node_top = pop->prev;
	}
	else
		*node_top = NULL;

	free(pop);
}

/**
 * swap_stack_top - Swaps the top two elements of the stack.
 * @node_top: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */
void swap_stack_top(node_t **node_top, unsigned int line_number)
{
	node_t *las = *node_top;
	int aux = 0;

	if (!las || !las->prev)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free(globaldata.input_str);
		fclose(globaldata.file_pointer);
		clearstack(*node_top);
		exit(EXIT_FAILURE);
	}

	aux = las->prev->data;
	las->prev->data = las->data;
	las->data = aux;
}

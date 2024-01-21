#include "monty.h"
/**
 * _addnodet - add node to the head stack
 * @tpr: head of the stack
 * @n: new_value
*/
void _addnodet(stack_t **tpr, int n)
{

	stack_t *free_node, *alt;

	alt = *tpr;
	free_node = malloc(sizeof(stack_t));
	if (free_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (alt)
		alt->prev = free_node;
	free_node->n = n;
	free_node->next = *tpr;
	free_node->prev = NULL;
	*tpr = free_node;
}

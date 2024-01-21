#include "monty.h"

/**
 * _addqueuet - adds a new node to the rear of the queue
 * @n: new value to be added
 * @tpr: ptr to the head of the queue
*/
void _addqueuet(stack_t **tpr, int n)
{
	stack_t *free_node, *bit;

	bit = *tpr;
	free_node = malloc(sizeof(stack_t));
	if (free_node == NULL)
	{
		printf("Error\n");
	}
	free_node->n = n;
	free_node->next = NULL;
	if (bit)
	{
		while (bit->next)
			bit = bit->next;
	}
	if (!bit)
	{
		*tpr = free_node;
		free_node->prev = NULL;
	}
	else
	{
		bit->next = free_node;
		free_node->prev = bit;
	}
}

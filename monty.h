#ifndef MONTY
#define MONTY

#define  _GNU_SOURCE
#include <stdio.h>

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>


/* ****> Stack structure <**** */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct content  - opcode and its function
 * @op_func: the opcode
 * @value: function to handle the opcode
 * @line_n: number of the line
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct content
{
	char *op_func;
	char *value;
	int line_n;
} content_v;

/**
 * struct glob_s - holds relevant progam information
 * @arg: ptr to string which holds argument. dd.
 * @file: pointer to monty file
 * @cont: ptr to string containing the line content
 * @lifi: flag to indicate change btn. stack & queue
 * ... whether an operation should be performed in stack-like
 * or queue-like manner
 *
 * Description: for sharing program values throughout (each file)
 */
typedef struct glob_s
{
	char *arg;
	FILE *file;
	char *cont;
	int lifi;
}  glob_t;
extern glob_t glob;  /*Global variable*/

void _free_stackt(stack_t *head);

void _addit(stack_t **tpr, unsigned int linumb);
void _addnodet(stack_t **tpr, int n);
void _addqueuet(stack_t **tpr, int n);
void _mod(stack_t **tpr, unsigned int linumb);
int _executet(char *cont, stack_t **tpr, unsigned int linumb, FILE *file);
void _divt(stack_t **tpr, unsigned int linumb);
void _modt(stack_t **tpr, unsigned int linumb);
void _mult(stack_t **tpr, unsigned int linumb);


void _nopt(stack_t **tpr, unsigned int linumb);
void _pusht(stack_t **top, unsigned int linumb);
void _pintt(stack_t **tpr, unsigned int linumb);
void _queue(stack_t **tpr, unsigned int linumb);
void _subt(stack_t **tpr, unsigned int linumb);
void _stackt(stack_t **tpr, unsigned int linumb);
void _pallt(stack_t **top, unsigned int linumb);
void _popt(stack_t **tpr, unsigned int linumb);
void _swapt(stack_t **tpr, unsigned int linumb);
#endif

#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct node_s - Doubly linked list node for a stack (or queue)
 * @value: Integer value of the node
 * @prev: Pointer to the previous node in the stack (or queue)
 * @next: Pointer to the next node in the stack (or queue)
 *
 * Description: Node structure for stack and queue implementation
 */
typedef struct node_s
{
    int data;
    struct node_s *prev, *next;
} node_t;

/**
 * operation_s - Represents an opcode and its corresponding function
 * @code: The opcode
 * @handler: Pointer to the function handling the opcode
 *
 * Description: Structure for opcode and its associated function
 * Used in stack, queues, LIFO, FIFO for Holberton project
 */
typedef struct operation_s 
{
    char *opcode;
    void (*j)(node_t **node_top, unsigned int line_number);
} operation_t;

/**
 * instructioninfo - Represents opcode information and its function
 * @opcode: The opcode
 * @handler: Function to handle the opcode
 * @lineNumber: Line number associated with the opcode
 *
 * Description: Structure for opcode and its associated function
 * Used in stack, queues, LIFO, FIFO for Holberton project
 */
typedef struct instructioninfo 
{
    char *code;
    char *handler;
    int linenumber;
} instructioninfo_v;

/**
 * externaldata - Represents miscellaneous data for the program
 * @int_value: Some integer value, purpose unspecified
 * @content_data: Additional content data, purpose unspecified
 * @file_pointer: File pointer, purpose unspecified
 * @line_content: String representing a line, purpose unspecified
 *
 * Description: Structure for holding miscellaneous data
 * Used in an external variable for Holberton project
 */
typedef struct externaldata 
{
    int int_value;
    instructioninfo_v content_data;
    FILE *file_pointer;
    char *input_str;
} externaldata_var_t;
extern externaldata_var_t globaldata;

int entry_point(int argument_count, char *arguments[]);
void process_file(FILE *file_pointer);
void perform_operation(node_t **node_top);
size_t is_non_empty(char *inputstr);
instructioninfo_v process_str(char *input_str);

void push_to_stack(node_t **top_node, unsigned int line_number);
void print_stack_values(node_t **top_node, unsigned int line_number);
void print_top_value(node_t **top_node, unsigned int line_number);
void pop_from_stack(node_t **top_node, unsigned int line_number);
void swap_stack_top(node_t **top_node, unsigned int line_number);
void add_monty_top_two(node_t **top_node, unsigned int line_number);
void multiply_stack_top_two(node_t **node_top, unsigned int line_number);
void perform_monty_division(node_t **node_top, unsigned int line_number);
void subtract_monty_top_two(node_t **node_top, unsigned int line_number);
void perform_no_operation(node_t **node_top, unsigned int line_number);
void print_node_string(node_t **node_top, unsigned int line_number);
void print_stack_top_char(node_t **node_top, unsigned int line_number);
void compute_stack_modulo(node_t **node_top, unsigned int line_number);

void clearstack(node_t *node_top);

#endif

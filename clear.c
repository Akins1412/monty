#include "main.h"

/**
 * is_non_empty - Checks if a string is not empty.
 * @inputstr: Input string to be checked.
 * Return: 0 if empty, 1 if not empty.
 */
size_t is_non_empty(char *inputstr)
{
	size_t k;

	for (k = 0; k < strlen(inputstr); k++)
	{
		if (inputstr[k] != ' ' && inputstr[k] != '\t' && inputstr[k] != '\n')
			break;
	}
	if (k == strlen(inputstr) || inputstr[k] == '#')
		return (0); /* empty */
	return (1); /* not empty */
}

/**
 * process_str - Removes spaces from a given string.
 * @input_str: Input string to be processed.
 * Return: Modified data structure.
 */

instructioninfo_v process_str(char *input_str)
{
	instructioninfo_v content_data;
	char *tokenize;
	size_t k;

	content_data.code = NULL;
	content_data.handler = NULL;
	tokenize = strtok(input_str, " \n\t");
	while (tokenize != NULL)
	{
		if (strcmp(tokenize, ""))
		{
			content_data.code = tokenize;
			break;
		}
		tokenize = strtok(NULL, " \n\t");
	}
	if (tokenize == NULL)
		return (content_data);

	tokenize = strtok(NULL, " \n\t");
	while (tokenize != NULL)
	{
		if (strcmp(tokenize, ""))
		{
			for (k = 0; k < strlen(tokenize); k++)
			{
				if (!(tokenize[k] >= '0' && tokenize[k] <= '9'))
					if (tokenize[0] != '-')
						break;
			}
			if (k == strlen(tokenize))
			{
				if (!strcmp(tokenize, "-0"))
					content_data.handler = 0;
				content_data.handler = tokenize;
			}
		}
		tokenize = strtok(NULL, " \n\t");
	}
	return (content_data);
}

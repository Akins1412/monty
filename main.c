#include "monty.h"
glob_t glob = {NULL, NULL, NULL, 0};

/**
 * main - Monty code interpreter
 * @argc: Number of arguments
 * @argv: Monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[]);
int main(int argc, char *argv[])
{
	char *line_content;
	FILE *m_file;
	size_t line_sizet = 0;
	ssize_t read_resultt = 1;
	stack_t *stack = NULL;
	unsigned int line_counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	m_file = fopen(argv[1], "r");
	glob.file = m_file;

	if (!m_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_resultt > 0)
	{
		line_content = NULL;
		read_resultt = getline(&line_content, &line_sizet, m_file);
		glob.cont = line_content;
		line_counter++;

		if (read_resultt > 0)
		{
			_executet(line_content, &stack, line_counter, m_file);
		}

		free(line_content);
	}

	_free_stackt(stack);
	fclose(m_file);

	return (EXIT_SUCCESS);
}

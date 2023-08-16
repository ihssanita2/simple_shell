#include "header.h"

/* Collabration of JalalErr & ihssaneer*/
/**
 * main - 
 * @argc:
 * @argv:
 * Return:
 */
int main(int argc, __attribute__((unused)) char *argv[])
{
	/*Declaration section :*/
	char *line = NULL;
	size_t line_len = 0;
	ssize_t r_line = 0;
	/*Code section :*/
	if (argc == 1)
	{
		while (TRUE)
		{	if (isatty(STDIN_FILENO) == 1)
				_print_string("#cisfun$ "); /*Print prompt*/
			r_line = getline(&line, &line_len, stdin);
				if (r_line == -1)
				{	
					free(line);
					break;
				}
			if (r_line == 1 && line[0] == '\n')
				continue;
			line [r_line  - 1] = '\0'; /* replace the \n*/
			_cmd_execut(line); /*execute the command*/
			line = NULL;
		}
	}
	else if (argc > 1)
	{
		line = argv[1];
		_cmd_execut(line);
	}
	return (0);
}

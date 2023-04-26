#include "myshell.h"

/**
 * _remove - find the index
 * @v: string
 * @ch: character
 *
 * Return: Index position or total number of characters.
 */

size_t _remove(const char *v, char ch)
{
	size_t i = 0;

	for (; v[i]; i++)
	{
		if (v[i] == ch)
			return (i);
	}
	return (i);
}

/**
 * prompt - Execute a command from terminal.
 *
 * @arv: Argument vector
 * @env: Environement vector.
 */

void prompt(char **arv, char **env)
{
	int status, j;
	size_t n = 0;
	ssize_t num_char;
	char *argv[MAX_COMPOUND], *val = NULL;
	pid_t child_pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("cisfun$ ");

		num_char = getline(&val, &n, stdin);
		if (num_char == -1)
		{
			free(val);
			exit(EXIT_FAILURE);
		}

		val[_remove(val, '\n')] = 0;

		j = 0;
		argv[0] = strtok(val, " ");
		while (argv[j] != NULL)
		{
			argv[++j] = strtok(NULL, " ");
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			free(val);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: No such file directory\n", arv[0]);
		}
		else
			wait(&status);
	}
}

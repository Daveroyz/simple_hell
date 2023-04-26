#include "myshell.h"

void prompt(char **arv, char **env)
{
	char *val = NULL;
	int i, status;
	size_t n = 0;
	ssize_t num_char;
	char *argv[] = (NULL, NULL);
	pid_t child_pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			print("cisfun$ ");

		num_char = getline(&val, &n, stdin);
		if (num_char == -1)
		{
			free(val);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while (val[i])
		{
			if (val[i] == '\n')
				val[i] = 0;
			i++;
		}
		argv[0] = val;
		child_pid = fork();
		if(child_pid == -1)
		{
			free(val);
			exit(EXIT_FAILURE);
		}
		if(child_pid == 0)
		{
			if(execve(argv[0], argv, env) == -1)
				printf("%s: No such file directory\n", arv[0]);
		}
		else
			wait(&status);
	}
}

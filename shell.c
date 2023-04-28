#include "myshell.h"

/**
 * main - function infinite
 *
 * @arc: argument conditions
 * @arv: Argument vector
 * @env: environment
 *
 * Return: Zero.
 */

int main(int arc, char **arv, char **env)
{
	if (arc == 1)
		prompt(arv, env);
	return (0);
}


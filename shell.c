#include "myshell.h"

int main(int arc, char **arv, char **env)
{
	if (arc == 1)
		prompt(arv,env);
	return (0);
}


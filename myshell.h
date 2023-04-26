#ifndef MYSHELL_H
#define MYSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMPOUND 20
int multiply(int num1, int num2, long result);
void prompt(char **arv, char **env);
size_t _remove(const char *v, char ch);


#endif

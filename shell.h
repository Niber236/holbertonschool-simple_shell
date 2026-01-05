#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
extern char **environ;
char **split_line(char *line);
int execute_args(char **args, char *prog_name);
int new_process(char **args, char *prog_name);
char *read_line(void);
#endif

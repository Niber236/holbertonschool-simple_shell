#include "shell.h"

/**
 * new_process - Lance la commande dans un processus enfant
 * @args: Arguments de la commande
 * @prog_name: Nom du programme (pour l'affichage d'erreur)
 * Return: 1
 */
int new_process(char **args, char *prog_name)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			fprintf(stderr, "%s: 1: %s: Permission denied\n", prog_name, args[0]);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		wait(&status);
	}
	return (1);
}

/**
 * execute_args - Wrapper pour new_process
 * @args: Arguments
 * @prog_name: Nom du programme
 * Return: 1
 */
int execute_args(char **args, char *prog_name)
{
	return (new_process(args, prog_name));
}

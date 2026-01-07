#include "shell.h"

/**
 * print_env - Affiche les variables d'environnement
 */
void print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

/**
 * path_handler - Gère la recherche et l'exécution de la commande
 * @args: Arguments de la commande
 * @av: Arguments du main
 * @exit_status: Pointeur vers le statut de sortie
 */
void path_handler(char **args, char **av, int *exit_status)
{
	char *path;

	path = find_path(args[0]);
	if (path != NULL)
	{
		args[0] = path;
		*exit_status = execute_args(args, av[0]);
		free(path);
	}
	else
	{
		fprintf(stderr, "%s: 1: %s: not found\n", av[0], args[0]);
		*exit_status = 127;
	}
}

/**
 * main - Boucle principale du shell
 * @ac: Compteur d'arguments
 * @av: Tableau d'arguments
 * Return: 0 ou code d'erreur
 */
int main(int ac, char **av)
{
	char *line, **args;
	int status = 1, exit_status = 0;

	(void)ac;
	while (status)
	{
		if (isatty(STDIN_FILENO))
			printf("($) ");
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			return (exit_status);
		}
		args = split_line(line);
		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
				status = 0;
			else if (strcmp(args[0], "env") == 0)
				print_env();
			else
				path_handler(args, av, &exit_status);
		}
		free(line);
		free(args);
	}
	return (exit_status);
}

/**
 * read_line - Lit une ligne depuis stdin
 * Return: La ligne lue
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

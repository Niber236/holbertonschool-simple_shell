#include "shell.h"
/**
* main - Boucle principale
* @ac: Compteur d arguments
* @av: Tableau d arguments
* Return: 0
*/
int main(int ac, char **av)
{
char *line;
char **args;
char *path;
int status = 1;
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
return (0);
}
args = split_line(line);
if (args[0] != NULL)
{
path = find_path(args[0]);
if (path != NULL)
{
/* FIX: Ne JAMAIS free args[0] ici ! */
args[0] = path;
status = execute_args(args, av[0]);
free(path); /* On libere le path apres usage */
}
else
fprintf(stderr, "%s: 1: %s: not found\n", av[0], args[0]);
}
free(line);
free(args);
}
return (0);
}
/**
* read_line - Lit une ligne
* Return: La ligne
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

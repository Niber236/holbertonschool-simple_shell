#include "shell.h"
/**
* split_line - Découpe la ligne
* @line: La ligne
* Return: Tableau de mots
*/
char **split_line(char *line)
{
int bufsize = 64;
int position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;
if (!tokens)
{
fprintf(stderr, "Erreur d'allocation\n");
exit(EXIT_FAILURE);
}
token = strtok(line, " \t\r\n\a");
while (token != NULL)
{
tokens[position] = token;
position++;
token = strtok(NULL, " \t\r\n\a");
}
tokens[position] = NULL;
return (tokens);
}

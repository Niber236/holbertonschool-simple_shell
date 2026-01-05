#include "shell.h"
/**
* _getenv - Recupere la valeur d une variable d environnement
* @name: Nom de la variable (ex: PATH)
* Return: La valeur ou NULL
*/
char *_getenv(char *name)
{
int i = 0, j;
while (environ[i])
{
j = 0;
while (name[j] && environ[i][j] == name[j])
j++;
if (name[j] == '\0' && environ[i][j] == '=')
return (environ[i] + j + 1);
i++;
}
return (NULL);
}
/**
* find_path - Cherche le chemin complet d une commande
* @cmd: La commande (ex: ls)
* Return: Le chemin complet (ex: /bin/ls) ou NULL
*/
char *find_path(char *cmd)
{
char *path = _getenv("PATH");
char *path_copy, *token, *full_path;
struct stat st;
if (strchr(cmd, '/') != NULL && stat(cmd, &st) == 0)
return (strdup(cmd));
if (!path)
return (NULL);
path_copy = strdup(path);
token = strtok(path_copy, ":");
while (token)
{
full_path = malloc(strlen(token) + strlen(cmd) + 2);
sprintf(full_path, "%s/%s", token, cmd);
if (stat(full_path, &st) == 0)
{
free(path_copy);
return (full_path);
}
free(full_path);
token = strtok(NULL, ":");
}
free(path_copy);
return (NULL);
}

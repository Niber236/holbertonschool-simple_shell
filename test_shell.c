#include <stdio.h>
#include <stdlib.h>

int main(void)
{
char *buffer = NULL; /* Pointeur pour stocker ce que tu tapes */
size_t bufsize = 0;  /* Taille du buffer (getline gère ça tout seul) */
ssize_t n_characters; /* Nombre de caractères lus */
while (1) /* La boucle infinie : le cœur du shell */
{
printf("($) "); /* 1. On affiche le prompt */

/* 2. On attend que l'utilisateur tape une commande */
/* getline va allouer la mémoire nécessaire dans 'buffer' */
n_characters = getline(&buffer, &bufsize, stdin);

/* Si getline renvoie -1, c'est une erreur ou la fin du fichier (Ctrl+D) */
if (n_characters == -1)
{
printf("\nBye bye !\n");
break; /* On casse la boucle pour quitter */
}

/* 3. Pour l'instant, on affiche juste ce qu'on a reçu pour vérifier */
printf("Tu as écrit : %s", buffer);
}

/* Important : getline a utilisé malloc, il faut free */
free(buffer);
return (0);
}

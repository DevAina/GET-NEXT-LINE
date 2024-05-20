# get_next_line

## Introduction

Le projet `get_next_line` est une introduction à la programmation système en C, faisant partie du programme pédagogique de l'école 42. L'ambition de ce projet est de concevoir une fonction hautement performante, fiable et réutilisable, capable de lire une ligne entière à partir d'un descripteur de fichier, tout en gérant de manière efficace plusieurs descripteurs de fichiers de manière simultanée.

## Buts du Projet

L'objectif central de ce projet est de développer la fonction `get_next_line`, qui a pour mission de lire une ligne complète à partir d'un descripteur de fichier spécifié en argument. Les exigences de cette fonction sont multiples et comprennent :

- La capacité de lire une ligne entière à chaque appel de la fonction.
- La faculté de gérer de multiples descripteurs de fichiers en parallèle, tels que des fichiers ouverts, des entrées standard, etc.
- Une efficacité de lecture optimale, garantissant qu'aucune donnée ne soit perdue ou omise.
- Une gestion adéquate des fins de lignes, marquées par le caractère `\n`, ainsi que des fins de fichiers.

## Méthodologie

Mon approche pour mener à bien ce projet repose sur l'utilisation d'un tampon statique que j'ai nommé `stash`. Voici les étapes clés de mon processus d'implémentation :

1. **Lecture et Accumulation** : La fonction initie le processus en lisant le contenu du fichier dans un tampon temporaire. Elle procède à la lecture de blocs de données de taille `BUFFER_SIZE` et les accumule dans la variable `stash`. Cette étape est répétée jusqu'à ce qu'une ligne complète soit identifiée ou que la fin du fichier soit atteinte.

2. **Extraction de la Ligne** : Lorsqu'une ligne est détectée au sein de `stash`, la fonction isole cette ligne et la transfère dans une variable dénommée `line`. Si aucune fin de ligne n'est présente, `line` se verra attribuer l'intégralité du contenu de `stash`.

3. **Purge de `stash`** : Suite à l'extraction de la ligne, le contenu de `stash` est purgé de la ligne précédemment isolée. Cette opération est essentielle pour préparer `stash` pour la prochaine opération de lecture.

4. **Renvoi de la Ligne Lue** : Pour conclure, la fonction retourne la ligne lue. Dans le cas où la fin du fichier est confirmée, `get_next_line` renvoie `NULL`, signalant qu'il n'y a plus aucune ligne restante à lire.

Cette stratégie assure une gestion efficace de la lecture ligne par ligne à partir de divers descripteurs de fichiers, tout en limitant les allocations dynamiques et en veillant à une gestion méticuleuse de la mémoire.

## Fonctionnalités Clés

- Lecture séquentielle d'une ligne à partir d'un descripteur de fichier donné.
- Prise en charge simultanée de plusieurs descripteurs de fichiers.
- Détection automatique des fins de lignes, indiquées par le caractère `\n`.
- Gestion appropriée des fins de fichiers.
- Minimisation des allocations dynamiques pour une performance accrue.
- Surveillance stricte de la mémoire pour prévenir toute fuite potentielle.

## Guide d'Utilisation

Pour intégrer et utiliser la fonction `get_next_line`, il suffit de l'inclure dans votre projet C et de l'appeler avec un descripteur de fichier valide. La fonction vous fournira la ligne lue ou retournera `NULL` si la fin du fichier est atteinte.

```c
#include "get_next_line.h"

int main()
{
   int     fd;
   char    *line;

   fd = open("fichier.txt", O_RDONLY);
   while ((line = get_next_line(fd)) != NULL)
   {
       printf("%s\n", line);
       free(line);
   }
   close(fd);
   return (0);
}

# PUSH_SWAP 42 v6.0 2023

## Ressources du projet


***
### Liens utiles


***
## Ressources Générales

[MAKEFILE Tuto](https://github.com/clemedon/Makefile_tutor#version-3)

[Aide générale pour 42](https://github.com/agavrel/42_CheatSheet#0x04--choosing-your-path)

[Markdown sheet cheat](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)

***
## Consignes

Fonctions externes autorisées
* read, write, malloc, free, exit
* ft_printf et tout équivalent que VOUS avez codé

***
## Étapes

* ajouter des index
* algo pour faire 3 groupes (size/3)
* algo pour push dans liste_a l'élément de liste_b le + proche en terme d'index
* algo pour calculer le nombre de coup et donc optimiser le push vers liste_a :
  * ra ou rra pour trouver l'élément dans liste_b avec l'index supérieur le + proche de la tête de liste_b  (tête de liste_a > tête de liste_b) avant de push

  * rb ou rrb pour trouver l'élément dans liste_b avec l'index inférieur le + proche de la tête de liste_a  (tête de liste_b < tête de liste_a) avant de push
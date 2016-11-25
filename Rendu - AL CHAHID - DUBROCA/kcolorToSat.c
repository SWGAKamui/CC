#include <stdio.h>
#include <stdlib.h>
#include "all.h"
//gcc main.c all.h C10.h petersen.c -o main
int nb_color;
//getVar doit être bijective
int getVar(int s, int c) {
  //à chaque paire (s,c) sa variable (il faut que ça marche dans l'autre sens pour pouvoir récupérer la coloration)
  return s * nb_color + (c - 1) ;
}
int main (int argc, char* argv[]){
  int order = orderG();
  int size = sizeG();
  nb_color = atoi(argv[1]);
  printf("p cnf %d %d\n",order * nb_color,order + size * nb_color);
  //on demande à ce que chaque sommet soit colorié
  for(int s = 1 ; s <= order ; s++) {
    for(int c = 1 ; c <= nb_color; c++) {
      printf("%d ", getVar(s,c));
    }
    printf("%d 0\n", getVar(s, nb_color - 1)) ;
  }
  //on vérifie que deux voisins n'aient pas la même couleur
  for(int s = 1; s <= order - 1; s++) {
    for(int s2 = s + 1; s2 <= order; s2++) {
      if(are_adjacent(s-1, s2-1) == 1){
        for(int c = 1; c <= nb_color; c++) {
          printf("-%d -%d 0\n", getVar(s,c), getVar(s2,c));
        }
      }
    }
  }
}

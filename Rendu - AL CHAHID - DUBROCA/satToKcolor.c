#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "all.h"
//gcc main.c all.h C10.h petersen.c -o main
int nb_color;
int tmp = 0;
//getVar doit être bijective
int getColor(int varSat) {
  //fonction inverse de gerVar permettant de récupérer la coloration
  return (varSat%nb_color)+1;
}
int getVertex(int varSat){
  return varSat/nb_color;
}

int main (int argc, char* argv[]){
  nb_color = atoi(argv[1]);
  int val;
  int tmp = 0;
  printf("\n");
  for(int i = 2; i < argc; i++){
    val = atoi(argv[i]);
    printf("Sommet %d: Couleur %d\n", getVertex(val), getColor(val));
  }

}

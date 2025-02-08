#include "vecteur.h"
#include <stdio.h>
#include <stdlib.h>

// role: returns an n vecteur initialized to 0
vecteur vecteurNulle(const int n) {
  vecteur v = {.nbc = n, .vect = (T *)malloc(sizeof(T) * n)};
  for (size_t i = 0; i < n; i++) {
    v.vect[i] = 0.0;
  }
  return v;
}

// role: returns the element v(i)
T getV(const vecteur v, const int i) { return v.vect[i]; }

// role: v(i) = x
void setV(vecteur *v, const int i, const T x) { v->vect[i] = x; }

// role: swap row i and j of vecteur v
void echangerLignesV(vecteur *v, const int i, const int j) {
  T x = v->vect[i];
  v->vect[i] = v->vect[j];
  v->vect[j] = x;
}

// role: write vecteur v to standard output
void ecrireVecteur(const vecteur v) {
  printf("vecteur: %d\n", v.nbc);
  for (size_t i = 0; i < v.nbc; i++) {
    printf("%.2f\t", getV(v, i));
  }
  printf("\n\n");
}

// role: initializes the Vecteur v from the file named f
void lireVecteur(vecteur *v, const char *f) {
  FILE *fp = fopen(f, "r");
  if (fp == NULL) {
    perror("open file");
    exit(-1);
  }
  int n = 0;
  if (1 != fscanf(fp, "%d", &n)) {
    perror("read file");
    exit(-1);
  }
  *v = vecteurNulle(n);
  for (size_t i = 0; i < n; i++) {
    T x = 0.0;
    if (1 != fscanf(fp, "%lf", &x)) {
      perror("read file");
      exit(-1);
    }
    setV(v, i, x);
  }
  fclose(fp);
}

// role: returns the number of columns of the vecteur v
int getVecteurNbCols(const vecteur v) { return v.nbc; }
#include <math.h>
#include <stdio.h>

#ifdef MATRICE_C
#include "matriceC.h"
#else
#include "matrice.h"
#endif

#include "vecteur.h"

void GaussRSL(matrice A, vecteur B, vecteur *X) {
  int n = A.nbl; // Size of matrix and vector
  // Gaussian elimination with partial pivoting algorithm
  for (int i = 0; i < n - 1; i++) {
    int mi = i;
    T mv = fabs(getM(A, i, i));
    // Choose the pivot row
    for (int j = i + 1; j < n; j++) {
      if (fabs(getM(A, j, i)) > mv) {
        mi = j;
        mv = fabs(getM(A, j, i));
      }
    }
    // Swap rows in matrix and vector if necessary
    if (mi != i) {
      echangerLignesM(&A, mi, i);
      echangerLignesV(&B, mi, i);
    }
    // Elimination step
    for (int j = i + 1; j < n; j++) {
      T ratio = getM(A, j, i) / getM(A, i, i);
      for (int k = i; k < n; k++) {
        T t1 = getM(A, j, k);
        T t2 = getM(A, i, k);
        setM(&A, j, k, t1 - t2 * ratio);
      }
      T bi = getV(B, i);
      T bj = getV(B, j);
      setV(&B, j, bj - ratio * bi);
    }
  }
  // Back substitution step
  for (int i = n - 1; i >= 0; i--) {
    setV(X, i, getV(B, i));
    for (int j = i + 1; j < n; j++) {
      T t = getM(A, i, j);
      T xj = getV(*X, j);
      T xi = getV(*X, i);
      setV(X, i, xi - t * xj);
    }
    T t = getM(A, i, i);
    T xi = getV(*X, i);
    setV(X, i, xi / t);
  }
}

int main(int argv, char **argc) {
  if (argv != 3) {
    printf("Usage: main matrice.txt vecteur.txt\n");
    return -1;
  }

  matrice A;
  vecteur B;
  lireMatrice(&A, argc[1]);
  lireVecteur(&B, argc[2]);

  printf("A ");
  ecrireMatrice(A);

  printf("B ");
  ecrireVecteur(B);

  vecteur X = vecteurNulle(B.nbc);
  GaussRSL(A, B, &X);

  printf("X ");
  ecrireVecteur(X);

  return 0;
}
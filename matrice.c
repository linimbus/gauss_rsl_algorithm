#include "matrice.h"
#include <stdio.h>
#include <stdlib.h>

// role: returns an m × n matrix initialized to 0
matrice matriceNulle(const int m, const int n) {
  matrice mt = {.nbc = n, .nbl = m, .mat = (T *)malloc(sizeof(T) * m * n)};
  for (size_t i = 0; i < n * m; i++) {
    mt.mat[i] = 0.0;
  }
  return mt;
}

// role: returns the element m(i,j)
T getM(const matrice m, const int i, const int j) {
  return m.mat[i * m.nbc + j];
}

// role: m(i,j) = x
void setM(matrice *m, const int i, const int j, const T x) {
  m->mat[i * m->nbc + j] = x;
}

// role: swap rows i and j of matrix m
void echangerLignesM(matrice *m, const int i, const int j) {
  for (size_t n = 0; n < m->nbc; n++) {
    T x = getM(*m, i, n);
    setM(m, i, n, getM(*m, j, n));
    setM(m, j, n, x);
  }
}

// role: write matrix m to standard output
void ecrireMatrice(const matrice m) {
  printf("matrice: %d * %d\n", m.nbl, m.nbc);
  for (size_t i = 0; i < m.nbl; i++) {
    for (size_t j = 0; j < m.nbc; j++) {
      printf("%.2f\t", getM(m, i, j));
    }
    printf("\n");
  }
  printf("\n");
}

// role: initializes the matrix m from the file named f
void lireMatrice(matrice *mt, const char *f) {
  FILE *fp = fopen(f, "r");
  if (fp == NULL) {
    perror("open file");
    exit(-1);
  }
  int m, n;
  if (2 != fscanf(fp, "%d %d", &m, &n)) {
    perror("read file");
    exit(-1);
  }
  *mt = matriceNulle(m, n);
  for (size_t i = 0; i < n * m; i++) {
    T x = 0.0;
    if (1 != fscanf(fp, "%lf", &x)) {
      perror("read file");
      exit(-1);
    }
    mt->mat[i] = x;
  }
  fclose(fp);
}

// role: returns the number of rows of the matrix m
int getNbLignes(const matrice m) { return m.nbl; }

// role: returns the number of columns of the matrix m
int getNbCols(const matrice m) { return m.nbc; }
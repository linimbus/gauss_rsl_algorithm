#ifndef _MATRICE_C_H_
#define _MATRICE_C_H_

typedef double T;

typedef struct item
{
    int l;
    int c;
    T val;
    int no;
    struct item *next;
} item;

typedef struct matrice
{
    int nbl;   // the number of lines
    int nbc;   // the number of columns
    item *mat; // the elements of the matrix
} matrice;

// role: returns an m × n matrix initialized to 0
extern matrice matriceNulle(const int m, const int n);

// role: returns the element m(i,j)
extern T getM(const matrice m, const int i, const int j);

// role: m(i,j) = x
extern void setM(matrice *m, const int i, const int j, const T x);

// role: swap rows i and j of matrix m
extern void echangerLignesM(matrice *m, const int i, const int j);

// role: write matrix m to standard output
extern void ecrireMatrice(const matrice m);

// role: initializes the matrix m from the file named f
extern void lireMatrice(matrice *m, const char *f);

// role: returns the number of rows of the matrix m
extern int getNbLignes(const matrice m);

// role: returns the number of columns of the matrix m
extern int getNbCols(const matrice m);

#endif
#ifndef _VECTEUR_H_
#define _VECTEUR_H_

typedef double T;

typedef struct vecteur
{
    int nbc; // the number of columns
    T *vect; // the elements of the vecteur
} vecteur;

// role: returns an n vecteur initialized to 0
extern vecteur vecteurNulle(const int n);

// role: returns the element v(i)
extern T getV(const vecteur v, const int i);

// role: v(i) = x
extern void setV(vecteur *v, const int i, const T x);

// role: swap row i and j of vecteur v
extern void echangerLignesV(vecteur *v, const int i, const int j);

// role: write vecteur v to standard output
extern void ecrireVecteur(const vecteur v);

// role: initializes the vecteur v from the file named f
extern void lireVecteur(vecteur *v, const char *f);

// role: returns the number of columns of the vecteur v
extern int getVecteurNbCols(const vecteur v);

#endif
#ifndef MON_H
#define MON_H

#include <stdio.h>




typedef struct
{
    int ligne ;
    int col ;
    int depl ;      /// 1=gauche, 2=haut, 3=droite, 4=bas
} monstre ;




void recuperationGrille (FILE *f, int grille [10][10], int *largeurGrille, int *nbMonstres, monstre tabMonstres [], int *lLutin, int *cLutin, int *lPorte, int *cPorte) ;
void afficherMonstres (monstre tabMonstres [], int nbMonstres) ;
void afficherLigneVide (int largeur) ;
void afficherLigneNumeros (int grille [10][10], int largeur, int l) ;
void afficherLignePleine (int largeur) ;
void afficherGrille (int grille [10][10], int largeur) ;

int ligneMonstre(monstre M);
int colonneMonstre(monstre M);
int deplacementMonstre(monstre M);
void modifDepl (monstre tabMonstre[], int numMonstre, int depl);
void modifligne (monstre tabMonstre[], int numMonstre, int ligne);
void modifcol (monstre tabMonstre[], int numMonstre, int col);
void Droite (monstre tabMonstre[], int numMonstre);
void Gauche (monstre tabMonstre[], int numMonstre);
void Haut (monstre tabMonstre[], int numMonstre);
void Bas (monstre tabMonstre[], int numMonstre);

void deplacementsMonstres (int grille[10][10], int largeur, int nbMonstres,monstre tabMonstres[], int i);
int deplacementMonstresPossible(int g[10][10],int largeur,monstre tabMonstres[],int numMonstre);
void deplacementLutin(int grille[10][10],int deplLutin,int tailleGrille,int *lLutin,int *cLutin);
int deplacementLutinPossible(int g[10][10],int dep,int largeur,int posLigne,int posColonne);

int deplacementsMonstresLutins (int reponse, int *nbTours, int grille [10][10], int largeurGrille, int nbMonstres, monstre tabMonstres [], int *lLutin, int *cLutin, int lPorte, int cPorte) ;
#endif

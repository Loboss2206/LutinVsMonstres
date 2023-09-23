#include <stdio.h>
#include <stdlib.h>
#include "entetes.h"

/*----------------------------------Lutin--------------------------------*/

int deplacementLutinPossible(int g[10][10],int dep,int largeur,int posLigne,int posColonne)
{
    if(dep==1)
    {
        if((posColonne-1)==-1) return 0;
    }
    else if(dep==2)
    {
        if((posLigne-1)==-1) return 0;
    }
    else if(dep==3)
    {
        if((posColonne+1)==largeur) return 0;
    }
    else if(dep==4)
    {
        if((posLigne+1)==largeur) return 0;
    }
    return 1;
}



void deplacementLutin(int grille[10][10],int deplLutin,int tailleGrille,int *lLutin,int *cLutin)
{
    int ligne=*lLutin,colonne=*cLutin;
    grille[ligne][colonne]=0;
    if (deplLutin==1 && deplacementLutinPossible(grille,deplLutin,tailleGrille,ligne,colonne)==1) *cLutin=*cLutin-1;
    else if (deplLutin==2 && deplacementLutinPossible(grille,deplLutin,tailleGrille,ligne,colonne)==1) *lLutin=*lLutin-1;
    else if (deplLutin==3 && deplacementLutinPossible(grille,deplLutin,tailleGrille,ligne,colonne)==1) *cLutin=*cLutin+1;
    else if (deplLutin==4 && deplacementLutinPossible(grille,deplLutin,tailleGrille,ligne,colonne)==1) *lLutin=*lLutin+1;
    ligne=*lLutin;
    colonne=*cLutin;
    grille[ligne][colonne]=1;
}

/*--------------------------------Monstre-----------------------------------*/

int deplacementMonstresPossible(int grille[10][10],int largeur,monstre tabMonstres[],int numMonstre)
{
    if(deplacementMonstre(tabMonstres[numMonstre]) == 1)
    {
        if (((colonneMonstre(tabMonstres[numMonstre]))-1 < 0)|| (grille[ligneMonstre(tabMonstres[numMonstre])][(colonneMonstre(tabMonstres[numMonstre]))-1]>0)) return 0;
    }
    else if(deplacementMonstre(tabMonstres[numMonstre]) == 2)
    {
        if (((ligneMonstre(tabMonstres[numMonstre]))-1 < 0)|| (grille[(ligneMonstre(tabMonstres[numMonstre]))-1][(colonneMonstre(tabMonstres[numMonstre]))]>0)) return 0;
    }
    else if(deplacementMonstre(tabMonstres[numMonstre]) == 3)
    {
        if (((colonneMonstre(tabMonstres[numMonstre]))+1 == largeur)|| (grille[ligneMonstre(tabMonstres[numMonstre])][(colonneMonstre(tabMonstres[numMonstre]))+1]>0)) return 0;
    }
    else if(deplacementMonstre(tabMonstres[numMonstre]) == 4)
    {
        if (((ligneMonstre(tabMonstres[numMonstre]))+1 == largeur )|| (grille[(ligneMonstre(tabMonstres[numMonstre]))+1][(colonneMonstre(tabMonstres[numMonstre]))]>0)) return 0;
    }
    return 1;
}



void deplacementsMonstres (int grille[10][10], int largeur, int nbMonstres, monstre tabMonstres[], int numMonstre)
{
    grille[ligneMonstre(tabMonstres[numMonstre])][colonneMonstre(tabMonstres[numMonstre])]=0;
    if (deplacementMonstre(tabMonstres[numMonstre])==1)
    {
        if(deplacementMonstresPossible(grille,largeur,tabMonstres,numMonstre)) Gauche(tabMonstres,numMonstre);
        else
        {
            modifDepl(tabMonstres,numMonstre,3);
            if(deplacementMonstresPossible(grille,largeur,tabMonstres,numMonstre)) Droite(tabMonstres,numMonstre);
            else modifDepl(tabMonstres,numMonstre,1);
        }
    }
    else if (deplacementMonstre(tabMonstres[numMonstre])==2)
    {
        if(deplacementMonstresPossible(grille,largeur,tabMonstres,numMonstre)) Haut(tabMonstres,numMonstre);
        else
        {
            modifDepl(tabMonstres,numMonstre,4);
            if(deplacementMonstresPossible(grille,largeur,tabMonstres,numMonstre)) Bas(tabMonstres,numMonstre);
            else modifDepl(tabMonstres,numMonstre,2);
        }
    }
    else if (deplacementMonstre(tabMonstres[numMonstre])==3)
    {
        if(deplacementMonstresPossible(grille,largeur,tabMonstres,numMonstre)) Droite(tabMonstres,numMonstre);
        else
        {
            modifDepl(tabMonstres,numMonstre,1);
            if(deplacementMonstresPossible(grille,largeur,tabMonstres,numMonstre)) Gauche(tabMonstres,numMonstre);
            else modifDepl(tabMonstres,numMonstre,3);
        }
    }
    else if (deplacementMonstre(tabMonstres[numMonstre])==4)
    {
        if(deplacementMonstresPossible(grille,largeur,tabMonstres,numMonstre)) Bas(tabMonstres,numMonstre);
        else
        {
            modifDepl(tabMonstres,numMonstre,2);
            if(deplacementMonstresPossible(grille,largeur,tabMonstres,numMonstre)) Haut(tabMonstres,numMonstre);
            else modifDepl(tabMonstres,numMonstre,4);
        }
    }
    grille[ligneMonstre(tabMonstres[numMonstre])][colonneMonstre(tabMonstres[numMonstre])]=2;

}

/*----------------------------Fonction-Principale---------------------------------------*/

int deplacementsMonstresLutins(int deplLutin, int *nbTours, int grille [10][10], int largeurGrille, int nbMonstres, monstre tabMonstres[], int *lLutin, int *cLutin, int lPorte, int cPorte)
{
    int defaite=0,i=0;
    int ligneLutin=*lLutin;
    int colonneLutin=*cLutin;

    *nbTours=*nbTours+1;

    deplacementLutin(grille,deplLutin,largeurGrille,&ligneLutin,&colonneLutin);
    *lLutin=ligneLutin;
    *cLutin=colonneLutin;

    if ((*lLutin==lPorte)&&(*cLutin==cPorte)) return 1;

    for (int j=0; j<nbMonstres; j++)
    {
        if((*lLutin==ligneMonstre(tabMonstres[j]))&&(*cLutin==colonneMonstre(tabMonstres[j]))) defaite=1;
    }

    while (defaite<1 && i<nbMonstres)
    {
        if (deplacementMonstre(tabMonstres[i])==1)
        {
            if ((ligneMonstre(tabMonstres[i])==*lLutin)&&((colonneMonstre(tabMonstres[i]))-1==*cLutin)|| (ligneMonstre(tabMonstres[i])==*lLutin)&&((colonneMonstre(tabMonstres[i]))-1==*cLutin)) defaite=1;
            else deplacementsMonstres(grille,largeurGrille,nbMonstres,tabMonstres,i);
        }
        else if (deplacementMonstre(tabMonstres[i])==2)
        {
            if (((ligneMonstre(tabMonstres[i]))-1==*lLutin)&&(colonneMonstre(tabMonstres[i])==*cLutin)|| (ligneMonstre(tabMonstres[i])+1==*lLutin)&&(colonneMonstre(tabMonstres[i])==*cLutin)) defaite=1;
            else deplacementsMonstres(grille,largeurGrille,nbMonstres,tabMonstres,i);
        }
        else if (deplacementMonstre(tabMonstres[i])==3)
        {
            if ((ligneMonstre(tabMonstres[i])==*lLutin)&&((colonneMonstre(tabMonstres[i]))+1==*cLutin) || (ligneMonstre(tabMonstres[i])==*lLutin)&&((colonneMonstre(tabMonstres[i]))+1==*cLutin)) defaite=1;
            else deplacementsMonstres(grille,largeurGrille,nbMonstres,tabMonstres,i);
        }
        else if (deplacementMonstre(tabMonstres[i])==4)
        {
            if (((ligneMonstre(tabMonstres[i]))+1==*lLutin)&&(colonneMonstre(tabMonstres[i])==*cLutin) || (ligneMonstre(tabMonstres[i])-1==*lLutin)&&(colonneMonstre(tabMonstres[i])==*cLutin)) defaite=1;
            else deplacementsMonstres(grille,largeurGrille,nbMonstres,tabMonstres,i);
        }
        if((*lLutin==ligneMonstre(tabMonstres[i]))&&(*cLutin==colonneMonstre(tabMonstres[i]))) defaite=1;
        i++;
    }
    if (defaite==1) return 2;
    return 0;
}

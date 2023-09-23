#include <stdio.h>
#include <stdlib.h>
#include "entetes.h"

int ligneMonstre(monstre M)
{
    return M.ligne;
}

int colonneMonstre(monstre M)
{
    return M.col;
}

int deplacementMonstre(monstre M)
{
    return M.depl;
}

void modifDepl (monstre tabMonstre[], int numMonstre, int depl)
{
    tabMonstre[numMonstre].depl=depl;
}

void modifligne (monstre tabMonstre[], int numMonstre, int ligne)
{
    tabMonstre[numMonstre].ligne=ligne;
}

void modifcol (monstre tabMonstre[], int numMonstre, int col)
{
    tabMonstre[numMonstre].col=col;
}

void Droite (monstre tabMonstre[], int numMonstre)
{
    tabMonstre[numMonstre].col+=1;
}

void Gauche (monstre tabMonstre[], int numMonstre)
{
    tabMonstre[numMonstre].col-=1;
}

void Haut (monstre tabMonstre[], int numMonstre)
{
    tabMonstre[numMonstre].ligne-=1;
}

void Bas (monstre tabMonstre[], int numMonstre)
{
    tabMonstre[numMonstre].ligne+=1;
}



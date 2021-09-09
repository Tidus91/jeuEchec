#include <stdio.h>
#include <stdlib.h>
#include "../header/afficherGrille.h"

int verifCoord(char *);

struct Roi{
    char nom;
    char *coord;

};
typedef struct Roi Roi;

struct Coord{
    int x;
    int y;
};
typedef struct Coord Coord;

void placementPiece(Roi*, char*);
int testPositionInitial(Roi*, char*, char*);

int main () {

    char grille[100];
    // je remplie ma grille de 10 x 10 cases avec des '.'
    for(int i=0;i<100;i++)
        grille[i] = '.';
    printf("Bienvenue dans le jeu d'échec !!!!!!!!!!!!!! \n\n\n\n");
    afficherGrille(grille);
    printf("\n\nOu voulez vous jouer ?\nRentrez les coordonnées de la pièce que vous souhaitez bouger, puis les coordonnées ou vous souhaitez vous déplacer (4 caractères maximum) !\n exemple : b2c3\n");
    char userCoord[4];
    // demande mouvement à l'utilisateur
    fgets(userCoord,5,stdin);
    verifCoord(userCoord);
    printf("Vous souhaitez donc vous déplacer de : %c%c à %c%c \n\n",userCoord[0],userCoord[1],userCoord[2],userCoord[3]);
    Roi rWhite;
    rWhite.nom = 'R';
    printf("\n j'affiche ma pièce : \n\n");
    placementPiece(&rWhite,grille);
    afficherGrille(grille);
    testPositionInitial(&rWhite,userCoord,grille);

    return 0;
}

int verifCoord(char *userCoord){

    int erreur = 0;
    // je vais tester chaque caractère pour voir si j'ai bien : seulement des nombre entre 1 et 8 et des lettres entre a et h
    for(int i=0;i<4;i++){
        if(!((userCoord[i] >= 'a' && userCoord[i] <= 'h') || (userCoord[i] >= '1' && userCoord[i] <= '8')))
            erreur++;
    }
    if(erreur > 0)
    {
        printf("\nerreur lors de la saisie des coordonnees, vous avez fait %d erreurs \n\n",erreur);
        printf("Veuillez saisir des coordonnees correcte : \n");
        // problème tampon ? double lecture
        fgets(userCoord,5,stdin);
        erreur = verifCoord(userCoord);
    }
}

void placementPiece(Roi *roi, char *grille) {

    //cases disponible : entre 11 et 19, 21 et 29, 31 et 39 ....
    // a -> 11,21,31....
    // b -> 12,22,32....
    // 1 -> entre 11 et 19
    // 2 -> entre 21 et 29
    // je dois convertir mes coordonnées pour trouver l'indice voulu du tableau
    grille[12] = roi->nom;
}

int testPositionInitial(Roi* piece,char *coord, char* grille) {

    // j'utilise solveur pour calculer l'index total pour aller chercher la correspondance dans ma grille
    int solveur = 0;
    int intCoord = coord[1];
    printf("\nmon coord [1] : %d  -> %c\n",solveur,coord[1]);
    printf(" \n intCoord : %d \n\n",intCoord);
    solveur = intCoord+1;
    printf("mon solveur avant les if : %d\n",solveur);
    if(coord[0] == 'a')
        solveur = solveur + 10;
    else if(coord[0] == 'b')
        solveur = solveur + 20;
    else if(coord[0] == 'c')
        solveur = solveur + 30;
    else if(coord[0] == 'd')
        solveur = solveur + 40;
    else if(coord[0] == 'e')
        solveur = solveur + 50;
    else if(coord[0] == 'f')
        solveur = solveur + 60;
    else if(coord[0] == 'g')
        solveur = solveur + 70;
    else if(coord[0] == 'h')
        solveur = solveur + 80;
    printf("\n mon solveur est : %d \n",solveur);
}

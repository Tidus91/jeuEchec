#include <stdio.h>
#include <stdlib.h>
#include "../header/afficherGrille.h"
#include "../header/coord.h"

struct Roi {
    char nom;
    char *deplacement;
};
typedef struct Roi Roi;

struct dame{
    char nom;
    char *deplacement;
};
typedef struct dame dame;

struct Tour{
    char nom;
    char *deplacement;
};
typedef struct Tour Tour;

// je voulais créer une struct Piece pour mettre directement dans les paramètre de mes fonctions, plutôt que mettre des paramètres optionnelles mais bon...

struct Piece{
    char couleur;
    union typeP {
        struct Roi roi;
        struct dame dame;
        struct Tour tour;
    } typep;
};
typedef struct Piece Piece;

#include "../header/creationInit.h"
#include "../header/position.h"

char* getPiece(char*, char*);

int main () {

    char grille[100];
    // je remplie ma grille de 10 x 10 cases avec des '.'
    for(int i=0;i<100;i++)
        grille[i] = '.';
    printf("Bienvenue dans le jeu d'échec ! \n\n\n\n");
    Piece piece1 = creationPiece(&piece1,'r','b');
    Piece piece2 = creationPiece(&piece2,'r','n');
    Piece piece3 = creationPiece(&piece3,'t','b');
    Piece piece4 = creationPiece(&piece4,'d','b');

    printf("nom : %c, nom : %c, nom : %c",piece3.typep.tour.nom,piece3.typep.roi.nom,piece3.typep.dame.nom);
    
    if(initialisationPiece(&piece1,grille) == 0)
        printf("Erreur !! mauvaise initialisation \n");
    if(initialisationPiece(&piece2,grille) == 0)
        printf("Erreur !! mauvaise initialisation \n");
    if(initialisationPiece(&piece3,grille) == 0)
        printf("Erreur !! mauvaise initialisation \n");
    if(initialisationPiece(&piece4,grille) == 0)
        printf("Erreur !! mauvaise initialisation \n");
    
    afficherGrille(grille);
    

    /*char userCoord[4];
    printf("\n\nOu voulez vous jouer ?\nRentrez les coordonnées de la pièce que vous souhaitez bouger, puis les coordonnées ou vous souhaitez vous déplacer (4 caractères maximum) !\n exemple de format valide -->  b2c3\n");
    fgets(userCoord,5,stdin);
    */
    
    deplacementPiece(&piece3,"a7f7",grille);
    afficherGrille(grille);

     
    return 0;
}

char* getPiece(char* coord,char *grille){

    int solveur = 0;
 
    if(coord[0] == 'a')
        solveur = solveur + 1;
    else if(coord[0] == 'b')
        solveur = solveur + 2;
    else if(coord[0] == 'c')
        solveur = solveur + 3;
    else if(coord[0] == 'd')
        solveur = solveur + 4;
    else if(coord[0] == 'e')
        solveur = solveur + 5;
    else if(coord[0] == 'f')
        solveur = solveur + 6;
    else if(coord[0] == 'g')
        solveur = solveur + 7;
    else if(coord[0] == 'h')
        solveur = solveur + 8;
    if(coord[1] == '8')
        solveur = solveur + 10;
    else if(coord[1] == '7')
        solveur = solveur + 20;
    else if(coord[1] == '6')
        solveur = solveur + 30;
    else if(coord[1] == '5')
        solveur = solveur + 40;
    else if(coord[1] == '4')
        solveur = solveur + 50;
    else if(coord[1] == '3')
        solveur = solveur + 60;
    else if(coord[1] == '2')
        solveur = solveur + 70;
    else if(coord[1] == '1')
        solveur = solveur + 80;

    if((grille[solveur] >= 'a' && grille[solveur] <= 'z') || (grille[solveur] >= 'A' && grille[solveur] >= 'Z'))
        return &grille[solveur];
}
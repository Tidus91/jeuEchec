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


int main () {

    char grille[100];
    // je remplie ma grille de 10 x 10 cases avec des '.'
    for(int i=0;i<100;i++)
        grille[i] = '.';
    printf("Bienvenue dans le jeu d'échec ! \n\n\n\n");
    Piece piece1 = creationPiece(&piece1,'r','b');
    Piece piece2 = creationPiece(&piece2,'r','n');
    Piece piece3 = creationPiece(&piece3,'t','b');

    printf("nom : %c, nom : %c, nom : %c",piece3.typep.tour.nom,piece3.typep.roi.nom,piece3.typep.dame.nom);
    
    if(initialisationPiece(&piece1,grille) == 0)
        printf("Erreur !! mauvaise initialisation \n");
    if(initialisationPiece(&piece2,grille) == 0)
        printf("Erreur !! mauvaise initialisation \n");
    if(initialisationPiece(&piece3,grille) == 0)
        printf("Erreur !! mauvaise initialisation \n");
    afficherGrille(grille);
    char userCoord[]="b7c6";
    deplacementPiece(&piece3,userCoord,grille);
    afficherGrille(grille);

     /*
    printf("\n\nOu voulez vous jouer ?\nRentrez les coordonnées de la pièce que vous souhaitez bouger, puis les coordonnées ou vous souhaitez vous déplacer (4 caractères maximum) !\n exemple de format valide -->  b2c3\n");
    char userCoord[4];
    // demande mouvement à l'utilisateur
    fgets(userCoord,5,stdin);
*/
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
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
    int etat;
};
typedef struct Piece Piece;

struct Joueur{
    char couleur;
    int actif;
    char *coupsJouer;
    Piece pieceJoueur[3];
};
typedef struct Joueur Joueur;

#include "../header/afficherGrille.h"
#include "../header/creationInit.h"
#include "../header/position.h"
#include "../header/ligneDeVue.h"

//char* getPiece(char*, char*);

int main () {

    Piece grille[100];
    // je remplie ma grille de 10 x 10 cases avec des '.'
    for(int i=0;i<100;i++)
        grille[i].typep.roi.nom = '.';
    printf("Bienvenue dans ce modeste jeu d'échec ! \n\n\n\n");
    // Creation des joueurs

    // Creation des pieces associés au joueurs
    Joueur Joueur1;
    Joueur Joueur2;
    Joueur1.couleur = 'b';
    Joueur1.actif = 1;
    Joueur2.couleur = 'n';
    Joueur2.actif = 0;
    Piece roiBlanc = creationPiece(&roiBlanc,'r','b');
    Joueur1.pieceJoueur[0] = roiBlanc;
    Piece roiNoir = creationPiece(&roiNoir,'r','n');
    Joueur2.pieceJoueur[0] = roiNoir;
    Piece tourBlanc = creationPiece(&tourBlanc,'t','b');
    Joueur1.pieceJoueur[1] = tourBlanc;
    Piece dameBlanc = creationPiece(&dameBlanc,'d','b');
    Joueur1.pieceJoueur[2] = dameBlanc;

    //printf("nom : %c, nom : %c, nom : %c",tourBlanc.typep.tour.nom,tourBlanc.typep.roi.nom,tourBlanc.typep.dame.nom);
    
    if(initialisationPiece(&roiBlanc,grille) == 0)
        printf("Erreur !! mauvaise initialisation \n");
    if(initialisationPiece(&roiNoir,grille) == 0)
        printf("Erreur !! mauvaise initialisation \n");
    if(initialisationPiece(&tourBlanc,grille) == 0)
        printf("Erreur !! mauvaise initialisation \n");
    if(initialisationPiece(&dameBlanc,grille) == 0)
        printf("Erreur !! mauvaise initialisation \n");
    
    afficherGrille(grille);
    if(Joueur1.actif == 1){
        char userCoord[4];
        printf("\n\nOu voulez vous jouer joueur Blanc ?\nRentrez les coordonnées de la pièce que vous souhaitez bouger, puis les coordonnées ou vous souhaitez vous déplacer (4 caractères maximum) !\n exemple de format valide -->  b2c3\n");
        fgets(userCoord,5,stdin);
        deplacementPiece(&Joueur1,userCoord,grille);
        afficherGrille(grille);
    }
    else if(Joueur2.actif == 1){
        char userCoord[4];
        printf("\n\nOu voulez vous jouer joueur Noir ?\nRentrez les coordonnées de la pièce que vous souhaitez bouger, puis les coordonnées ou vous souhaitez vous déplacer (4 caractères maximum) !\n exemple de format valide -->  b2c3\n");
        fgets(userCoord,5,stdin);
        deplacementPiece(&Joueur2,userCoord,grille);
        afficherGrille(grille);
    }
    
    
    //deplacementPiece(&tourBlanc,userCoord,grille);
    

    return 0;
}
/*
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
}*/
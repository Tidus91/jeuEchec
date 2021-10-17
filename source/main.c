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

struct Fou{
    char nom;
    char *deplacement;
};
typedef struct Fou Fou;

// je voulais créer une struct Piece pour mettre directement dans les paramètre de mes fonctions, plutôt que mettre des paramètres optionnelles mais bon...

struct Piece{
    char couleur;
    int coord;
    union typeP {
        struct Roi roi;
        struct dame dame;
        struct Tour tour;
        struct Fou fou;
    } typep;
    int etat;
};
typedef struct Piece Piece;

struct Joueur{
    char couleur;
    int actif;
    int echec;
    char *coupsJouer;
    Piece pieceJoueur[3]; // tableau des pieces du joueurs
};
typedef struct Joueur Joueur;

#include "../header/afficherGrille.h"
#include "../header/creationInit.h"
#include "../header/position.h"
#include "../header/ligneDeVue.h"
#include "../header/echec.h"

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
    Joueur1.echec = 0;
    Joueur2.couleur = 'n';
    Joueur2.actif = 0;
    Joueur2.echec = 0;
    Piece roiBlanc = creationPiece(&roiBlanc,'r','b');
    Joueur1.pieceJoueur[0] = roiBlanc;
    Piece roiNoir = creationPiece(&roiNoir,'r','n');
    Joueur2.pieceJoueur[0] = roiNoir;
    Piece tourBlanc = creationPiece(&tourBlanc,'t','b');
    Joueur1.pieceJoueur[1] = tourBlanc;
    Piece dameBlanc = creationPiece(&dameBlanc,'d','b');
    Joueur1.pieceJoueur[2] = dameBlanc;
    Piece fouNoir = creationPiece(&fouNoir,'f','n');

    // Placement des pièces sur l'échequier
    if(initialisationPiece(&roiBlanc,grille) == 0)
        printf("Erreur !! mauvaise initialisation \n");
    if(initialisationPiece(&roiNoir,grille) == 0)
        printf("Erreur !! mauvaise initialisation \n");
    if(initialisationPiece(&tourBlanc,grille) == 0)
        printf("Erreur !! mauvaise initialisation \n");
    if(initialisationPiece(&dameBlanc,grille) == 0)
        printf("Erreur !! mauvaise initialisation \n");
    if(initialisationPiece(&fouNoir,grille) == 0)
        printf("Erreur !! mauvaise initialisation \n");
    
    afficherGrille(grille);
    int finPartie = 0;
    while(finPartie == 0){
        if(Joueur1.actif == 1){
            char userCoord[6];
            printf("\n\nOu voulez vous jouer joueur Blanc ?\nRentrez les coordonnées de la pièce que vous souhaitez bouger, puis les coordonnées ou vous souhaitez vous déplacer (4 caractères maximum) !\n exemple de format valide -->  b2c3\n");
            fgets(userCoord,6,stdin);
            printf("chaine de carac : %s \n",userCoord);
            printf("caractere de fin : %c \n",userCoord[5]);
            verifCoord(userCoord);
            if(deplacementPiece(&Joueur1,userCoord,grille) == 1){
                int king = getBlackKing(grille);
                int position = testPositionFinal(userCoord,grille);
                printf("j'arrive bien au moment de isEchec....");
                /*if(isEchec(position,king,grille) == 1)
                    Joueur2.echec = 1;*/
                Joueur1.actif = 0;
                Joueur2.actif = 1;
            }
            afficherGrille(grille);
        }
        else if(Joueur2.actif == 1){
            char userCoord[6];
            printf("\n\nOu voulez vous jouer joueur Noir ?\nRentrez les coordonnées de la pièce que vous souhaitez bouger, puis les coordonnées ou vous souhaitez vous déplacer (4 caractères maximum) !\n exemple de format valide -->  b2c3\n");
            fgets(userCoord,6,stdin);
            printf("chaine de carac : %s \n",userCoord);
            printf("caractere de fin : %c \n",userCoord[5]);
            if(deplacementPiece(&Joueur2,userCoord,grille) == 1){
                int king = getWhiteKing(grille);
                /* pas comme ça qu'il faut faire, car un echec pourrait très bien avoir lieu après déblocage d'une ligne de vue
                int position = testPositionFinal(userCoord,grille);
                if(isEchec(position,king,grille) == 1)
                    Joueur1.echec = 1;*/
                // Pour toute les pièces actives du joueur adverse, je regarde si le roi est atteignable
                // je dois envoyer ces pieces actives a la fonction (isEchec)
                // avant ça je dois modifier ma fonction createINit ....
                /*if(isEchec(&Joueur1,king,grille) == 1){

                }*/
                Joueur2.actif = 0;
                Joueur1.actif = 1;
            }
            afficherGrille(grille);
        }
    }
    
    return 0;
}
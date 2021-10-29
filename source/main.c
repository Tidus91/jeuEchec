#include <stdio.h>
#include <stdlib.h>
#include "../header/coord.h"
#include <assert.h>
#include "../header/Piece.h"

struct Joueur{
    char couleur;
    int actif;
    int echec;
    int gagner;
    int nombreCoups;
    char *coupsJouer;
    Piece pieceJoueur[16]; // tableau des pieces du joueurs
};
typedef struct Joueur Joueur;

#include "../header/afficherGrille.h"
#include "../header/creationInit.h"
#include "../header/position.h"
#include "../header/ligneDeVue.h"
#include "../header/echec.h"

int main () {

    Piece *grille[100];
    // je remplie ma grille de 10 x 10 cases avec des '.'
    for(int i=0;i<100;i++){
        grille[i] = creationPieceVide();
    }


    printf("Bienvenue dans ce modeste jeu d'échec ! \n\n\n\n");
    
    // Final ou jeu echec normal 
    printf("Tapez 1 pour jouer une finale d'echec ou 2 pour une partie complète ! \n1.Finale\n2.Partie complete\n\n");

    int typePartie = 0;
    char choixPartie[3];
    while(typePartie == 0){
        fgets(choixPartie,3,stdin);
        printf("Vous avez choisie : %s\n",choixPartie);
        if(choixPartie[0] == '1'){
            typePartie = 1;
        }
        else if(choixPartie[0] == '2'){
            typePartie = 1;
        }
        else{
            printf("Erreur, Veuillez taper 1 ou 2\n");
        }
    }
    Joueur Joueur1 = creationJoueur('b');
    Joueur Joueur2 = creationJoueur('n');
    if(choixPartie[0] == '1'){
        // Initialisation Finale d'echec
        if(creationSetEchecFinale(&Joueur1,&Joueur2,grille) == 0){
            printf("Erreur !! ");
            return 0;
        }
        
    }
    else if(choixPartie[0] == '2'){
        // Initialisation Jeu d'echec complet
        if(creationSetEchecComplet(&Joueur1,&Joueur2,grille) == 0){
            printf("Erreur !!   vv");
            return 0;
        }
    }
    else{
        printf("c'est impossible.... mais juste au cas ou....\n");
    }

    afficherGrille(grille);

    /*
    int finPartie = 0;
    while(finPartie == 0){
        if(Joueur1.actif == 1){
            char userCoord[6];
            printf("\n\nOu voulez vous jouer joueur Blanc ?\nRentrez les coordonnées de la pièce que vous souhaitez bouger, puis les coordonnées ou vous souhaitez vous déplacer (4 caractères maximum) !\n exemple de format valide -->  b2c3 \n Vous pouvez aussi abandonner en tapant 'ggwp'");
            fgets(userCoord,6,stdin);
            printf("chaine de carac : %s \n",userCoord);
            //printf("caractere de fin : %c \n",userCoord[5]);
            // Verification de la saisie
            if(verifCoord(userCoord) == 2){
                // abandon de la partie
                finPartie = 1;
                Joueur2.gagner = 1;
                break;
            }
            if(deplacementPiece(&Joueur1,userCoord,grille) == 1){
                int king = getBlackKing(grille);
                int position = testPositionFinal(userCoord,grille);
                printf("j'arrive bien au moment de isEchec....");
                if(isEchec(position,king,grille) == 1)
                    Joueur2.echec = 1;
                Joueur1.actif = 0;
                Joueur2.actif = 1;
            }
            afficherGrille(grille);
        }
        else if(Joueur2.actif == 1){
            char userCoord[6];
            printf("\n\nOu voulez vous jouer joueur Noir ?\nRentrez les coordonnées de la pièce que vous souhaitez bouger, puis les coordonnées ou vous souhaitez vous déplacer (4 caractères maximum) !\n exemple de format valide -->  b2c3\n Vous pouvez aussi abandonner en tapant 'ggwp'\n");
            fgets(userCoord,6,stdin);
            printf("chaine de carac : %s \n",userCoord);
            //printf("caractere de fin : %c \n",userCoord[5]);
            // Verification de la saisie
            if(verifCoord(userCoord) == 2){
                // abandon de la partie
                finPartie = 1;
                Joueur1.gagner = 1;
                break;
            }
            if(deplacementPiece(&Joueur2,userCoord,grille) == 1){
                int king = getWhiteKing(grille);
                /* pas comme ça qu'il faut faire, car un echec pourrait très bien avoir lieu après déblocage d'une ligne de vue
                int position = testPositionFinal(userCoord,grille);
                if(isEchec(position,king,grille) == 1)
                    Joueur1.echec = 1;*/
                // Pour toute les pièces actives du joueur adverse, je regarde si le roi est atteignable
                // je dois envoyer ces pieces actives a la fonction (isEchec)
                // avant ça je dois modifier ma fonction createINit ....*/
                /*
                if(isEchec(&Joueur1,king,grille) == 1){

                }
                Joueur2.actif = 0;
                Joueur1.actif = 1;
            }
            afficherGrille(grille);
        }
    }
    if(Joueur2.gagner == 1){
        printf("Bravo ! le joueur noire a gagner !\n");
    }
    else if(Joueur1.gagner == 1){
        printf("Bravo !  le Joueur blanc a gagner ! \n");
    }
    */
    return 0;
}
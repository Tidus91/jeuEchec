#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../header/coord.h"
#include "../header/Piece.h"
#include "../header/Joueur.h"
#include "../header/afficherGrille.h"
#include "../header/creationInit.h"
#include "../header/position.h"
#include "../header/echec.h"
#include "../header/ligneDeVue.h"

#include "../source/coord.c"
#include "../source/Piece.c"
#include "../source/Joueur.c"
#include "../source/afficherGrille.c"
#include "../source/creationInit.c"
#include "../source/position.c"
#include "../source/echec.c"
#include "../source/ligneDeVue.c"


int main () {

    Piece *grille[100];
    for(int i=0;i<100;i++){
        grille[i] = creationPieceVide();
    }

    printf("Bienvenue dans ce modeste jeu d'échec ! \n\n\n\n");
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
        if(creationSetEchecFinale(&Joueur1,&Joueur2,grille) == 0){
            printf("Erreur !! ");
            return 0;
        }
        
    }
    else if(choixPartie[0] == '2'){
        if(creationSetEchecComplet(&Joueur1,&Joueur2,grille) == 0){
            printf("Erreur !!   vv");
            return 0;
        }
    }
    else{
        printf("c'est impossible.... mais juste au cas ou....\n");
    }

    afficherGrille(grille);

    char *chaineTest = JoueurPiecesToString(&Joueur1);
    printf("\njoueur 1 : %s\n",chaineTest);
    chaineTest = JoueurPiecesToString(&Joueur2);
    printf("joueur 2 : %s\n\n",chaineTest);

    int finPartie = 0;
    while(finPartie == 0){
        if(isJoueurActif(&Joueur1) == 1){
            char userCoord[6];
            printf("\n\nOu voulez vous jouer joueur Blanc ?\nRentrez les coordonnées de la pièce que vous souhaitez bouger, puis les coordonnées ou vous souhaitez vous déplacer (4 caractères maximum) !\n exemple de format valide -->  b2c3 \n Vous pouvez aussi abandonner en tapant 'ggwp'");
            if(Joueur1.echec == 1){
                printf("\n####### ATTENTION Vous êtes en Echec ###########\n");
            }
            fgets(userCoord,6,stdin);
            printf("chaine de carac : %s \n",userCoord);
            // Verification de la saisie
            if(verifCoord(userCoord) == 2){
                // abandon de la partie
                finPartie = 1;
                setJoueurGagner(&Joueur2);
                break;
            }
            if(deplacementPiece(&Joueur1,&Joueur2,userCoord,grille) == 1){
                printf("j'arrive bien au moment de isEchec....");
                if(isPutEchec(&Joueur1,grille) == 1)
                    Joueur2.echec = 1;
                setJoueurActif(&Joueur1,&Joueur2);
            }
            afficherGrille(grille);
            // Test ToString
            chaineTest = JoueurPiecesToString(&Joueur1);
            printf("\njoueur 1 : %s\n",chaineTest);
            chaineTest = JoueurPiecesToString(&Joueur2);
            printf("joueur 2 : %s\n\n",chaineTest);

            // Test PiecesJoueur
            int nbTT = 0;
            Piece **tableauTest = getJoueurPieces(&Joueur1,&nbTT);
            for (int i = 0; i < nbTT ;i++){
                printf(" %c",tableauTest[i]->type);
            }
            
        }
        else if(isJoueurActif(&Joueur2) == 1){
            char userCoord[6];
            printf("\n\nOu voulez vous jouer joueur Noir ?\nRentrez les coordonnées de la pièce que vous souhaitez bouger, puis les coordonnées ou vous souhaitez vous déplacer (4 caractères maximum) !\n exemple de format valide -->  b2c3\n Vous pouvez aussi abandonner en tapant 'ggwp'\n");
            if(Joueur2.echec == 1){
                printf("\n####### ATTENTION Vous êtes en Echec ###########\n");
            }
            fgets(userCoord,6,stdin);
            printf("chaine de carac : %s \n",userCoord);

            // Verification de la saisie
            if(verifCoord(userCoord) == 2){
                // abandon de la partie
                finPartie = 1;
                setJoueurGagner(&Joueur1);
                break;
            }
            if(deplacementPiece(&Joueur2,&Joueur1,userCoord,grille) == 1){
                
                if(isPutEchec(&Joueur2,grille) == 1)
                    Joueur1.echec = 1;
                setJoueurActif(&Joueur2,&Joueur1);
            }
            afficherGrille(grille);

            chaineTest = JoueurPiecesToString(&Joueur1);
            printf("\njoueur 1 : %s\n",chaineTest);
            chaineTest = JoueurPiecesToString(&Joueur2);
            printf("joueur 2 : %s\n\n",chaineTest);
        }
    }
    if(getJoueurGagner(&Joueur2) == 1){
        printf("Bravo ! le joueur noire a gagner !\n");
        printf("vous avez gagne en %d coups ! ",getJoueurNbCoups(&Joueur2));
    }
    else if(getJoueurGagner(&Joueur1) == 1){
        printf("Bravo !  le Joueur blanc a gagner ! \n");
        printf("vous avez gagne en %d coups ! ",getJoueurNbCoups(&Joueur1));
    }
    return 0;
}
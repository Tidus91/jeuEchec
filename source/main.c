#include <stdio.h>
#include <stdlib.h>
#include "../header/afficherGrille.h"

int verifCoord(char *);

struct Roi {
    char nom;
    char deplacement;
};
typedef struct Roi Roi;

struct dame{
    char nom;
    char deplacement;
};
typedef struct dame dame;

struct Tour{
    char nom;
    char deplacement;
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
    printf("Bienvenue dans le jeu d'échec !!!!!!!!!!!!!! \n\n\n\n");
    afficherGrille(grille);

    /*
    printf("\n\nOu voulez vous jouer ?\nRentrez les coordonnées de la pièce que vous souhaitez bouger, puis les coordonnées ou vous souhaitez vous déplacer (4 caractères maximum) !\n exemple de format valide -->  b2c3\n");
    char userCoord[4];
    // demande mouvement à l'utilisateur
    fgets(userCoord,5,stdin);
    verifCoord(userCoord);
    printf("Vous souhaitez donc vous déplacer de : %c%c à %c%c \n\n",userCoord[0],userCoord[1],userCoord[2],userCoord[3]);
    */

    Piece piece1 = creationPiece(&piece1,"roi",'b');
    
    
    if(initialisationPiece(&piece1,grille) == 0)
        printf("Erreur !! mauvaise initialisation \n");
    afficherGrille(grille);

    /*placementPiece(&roiBlanc,grille);
    afficherGrille(grille);
    if(testPositionInitial(&roiBlanc,userCoord,grille) != 1)
        printf("Erreur ! , aucune pièce ne se trouve à l'endroit d'origine !\n");
    
*/
    return 0;
}

int verifCoord(char *userCoord){

    int erreurLettre = 0;
    int erreurChiffre = 0;
    int erreur = 0;
    // je vais tester chaque caractère pour voir si j'ai bien : seulement des nombre entre 1 et 8 et des lettres entre a et h
    // finalement je vais faire 2 boucle afin de mieux debugger l'erreur de l'utilisateur
    /*
    for(int i=0;i<4;i++){
        if(!((userCoord[i] >= 'a' && userCoord[i] <= 'h') || (userCoord[i] >= '1' && userCoord[i] <= '8')))
            erreur++;
    }*/
    for(int i=0;i<3;i+=2){
        if(!(userCoord[i] >= 'a' && userCoord[i] <= 'h'))
            erreurLettre++;
    }
    for(int i=1; i<4;i+=2){
        if( !(userCoord[i] >= '1' && userCoord[i] <= '8'))
            erreurChiffre++;
    }
    erreur = erreurLettre+erreurChiffre;
    if(erreur > 0)
    {
        printf("\nerreur lors de la saisie des coordonnees, Veuillez saisir dans ce type de format uniquement : ---> b3c7 \n\n");
        if(erreurLettre > 0 && erreurChiffre == 0)
            printf("Vous avez fait %d erreurs de lettre \n",erreurLettre);
        if(erreurChiffre > 0 && erreurLettre == 0 )
            printf("Vous avez fait %d erreurs de chiffre \n",erreurChiffre);
        printf("Veuillez saisir des coordonnees correcte : \n");
        fgets(userCoord,5,stdin);
        erreur = verifCoord(userCoord);
    }
}
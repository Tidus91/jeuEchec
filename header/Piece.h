struct Piece{
    char couleur;
    int coord;
    char type;
    char *deplacement;
    int valeur;
    int etat;
};
typedef struct Piece Piece;

#include "../source/Piece.c"
//void deplacementPiece(Piece*,char*, char*);
int deplacementPiece(Joueur *,char*,Piece*);
//int testPositionInitial(Piece*, char*, Piece*);
int testPositionInitial(Joueur *,char*,Piece*);
//int testPositionFinal(Piece*, char*, char*);
int testPositionFinal(char*, Piece*);
int isPossible(int,int,Piece*);
int isAdjacent(Piece*,int,int,char*);
int solveurLigneDeVueRectiligne(int,int,Piece*);
int solveurLigneDeVueDiagonale(int ,int ,Piece *);
int solveurLigneDeVueRectiligneDiagonale(int,int,Piece *);

#include "../source/position.c"
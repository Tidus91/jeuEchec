struct Piece{
    char couleur;
    int coord;
    char type;
    char *deplacement;
    int valeur;
    int etat;
};
typedef struct Piece Piece;


Piece* creationPieceVide();
Piece* creationPiece(char, char);

char getPieceColor(Piece *);
char getPieceType(Piece *);
int getPieceValeur(Piece *);
int getPieceEtat(Piece *);
char *getPieceDeplacement(Piece *);

int setPieceType(Piece *,char );
int setPieceEtat(Piece *,int );

int getPiecePosition(Piece *,Piece *[]);

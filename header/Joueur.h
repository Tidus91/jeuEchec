struct Joueur{
    char couleur;
    int actif;
    int echec;
    int gagner;
    int nombreCoups;
    char *coupsJouer;
    Piece *pieceJoueur[16]; // tableau des pieces du joueurs
};
typedef struct Joueur Joueur;

Joueur creationJoueur(char );

char getJoueurColor(Joueur*);

int isJoueurActif(Joueur*);
int setJoueurActif(Joueur*,Joueur*);

int getJoueurGagner(Joueur*);
void setJoueurGagner(Joueur*);

int isJoueurEchec(Joueur*);
void setJoueurEchec(Joueur*);

int getJoueurNbCoups(Joueur*);
void addJoueurNbCoups(Joueur*);

int addPieceJoueur(Joueur*,Piece*);
int deletePieceJoueur(Joueur*,Piece*);
Piece ** getJoueurPieces(Joueur*,int*);
char* JoueurPiecesToString(Joueur*);
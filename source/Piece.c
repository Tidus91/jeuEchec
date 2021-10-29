char getPieceColor(Piece *piece){
    return piece->couleur;
}

char getPieceType(Piece *piece){
    return piece->type;
}

int getPieceValeur(Piece *piece){
    return piece->valeur;
}

int getPieceEtat(Piece *piece){
    return piece->etat;
}

char *getPieceDeplacement(Piece *piece){
    return piece->deplacement;
}

// Fonction utile seulement pour la promotion des pieces... (en effet on ne change pas le type d'une piece juste comme ça...)
int setPieceType(Piece *piece,char typeSet){
    assert(typeSet == 't' || typeSet == 'f' || typeSet == 'd' || typeSet == 'c');
    if((typeSet == 't' || typeSet == 'f' || typeSet == 'd' || typeSet == 'c')){
        piece->type = typeSet;
        if(typeSet== 't'){
            piece->valeur = 5;
            piece->deplacement = "rectiligne";
            return 1;
        }
        else if(typeSet== 'd'){
            piece->valeur = 9;
            piece->deplacement = "rectiligneDiagonale";
            return 1;
        }
        else if(typeSet== 'f'){
            piece->valeur = 3;
            piece->deplacement = "diagonale";
            return 1;
        }
    }
    return 0;
}

int setPieceEtat(Piece *piece,int etatSet){
    assert(etatSet == 1 || etatSet == 0);
    if(etatSet == 1 || etatSet == 0){
        piece->etat = etatSet;
        return 1;
    }
    return 0;
}

Piece* creationPieceVide(){
    Piece *pieceVide = (Piece*)malloc(sizeof(Piece));
    pieceVide->type = '.';
    pieceVide->valeur = 0;
    return pieceVide;
}

Piece creationPiece(char type, char couleur){
    assert(type == 'r' || type == 'd' || type == 't' || type == 'f');
    assert(couleur == 'b' || couleur == 'n');
    if(!(type == 'r' || type == 'd' || type == 't' || type == 'f'))
        printf("Erreur, ce type de piece n'existe pas ! \n\n");
    if(!(couleur == 'b' || couleur == 'n'))
        printf("Erreur mauvaise couleur saisie !");
    
    Piece pieceRandom;
    if(couleur == 'b'){
        pieceRandom.couleur='b';
        if(type=='r'){
            pieceRandom.type = 'R';
            pieceRandom.deplacement = "adjacent";
            pieceRandom.valeur = 0;
        }
        else if(type == 'd'){
            pieceRandom.type = 'D';
            pieceRandom.deplacement = "rectiligneDiagonale";
            pieceRandom.valeur = 9;
        }
        else if(type == 't'){
            pieceRandom.type = 'T';
            pieceRandom.deplacement = "rectiligne";
            pieceRandom.valeur = 5;
        }
        else if(type == 'f'){
            pieceRandom.type = 'F';
            pieceRandom.deplacement = "diagonale";
            pieceRandom.valeur = 3;
        }
    }
    if(couleur == 'n'){
        pieceRandom.couleur='n';
        if(type=='r'){
            pieceRandom.type = 'r';
            pieceRandom.deplacement = "adjacent";
            pieceRandom.valeur = 0;
        }
        else if(type == 'd'){
            pieceRandom.type = 'd';
            pieceRandom.deplacement = "rectiligneDiagonale";
            pieceRandom.valeur = 9;
        }
        else if(type == 't'){
            pieceRandom.type = 't';
            pieceRandom.deplacement = "rectiligne";
            pieceRandom.valeur = 5;
        }
        else if(type == 'f'){
            pieceRandom.type = 'f';
            pieceRandom.deplacement = "diagonale";
            pieceRandom.valeur = 3;
        }
    }
    return pieceRandom;
}
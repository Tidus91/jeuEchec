int getWhiteKing(Piece *grille[]){
    for(int i=0;i<100;i++){
        if(getPieceType(grille[i]) == 'R')
            return i;
    }
}
int getBlackKing(Piece *grille[]){
    for(int i=0;i<100;i++){
        if(getPieceType(grille[i]) == 'r')
            return i;
    }
}
// Fonction qui verifie que je ne suis pas de moi même en echec en bougant ma propre pièce
int isEchec(Joueur *joueurActif,Joueur *joueurAdverse,Piece *grille[]){
    
    int king;
    if(joueurActif->couleur == 'b')
        king = getWhiteKing(grille);
    else if(joueurActif->couleur == 'n')
        king = getBlackKing(grille);
    
    // Je recupère tout les pointeur de Pieces du joueur adverse
    int nbPa = 0;
    Piece** PiecesAdverse = getJoueurPieces(joueurAdverse,&nbPa);

    // Pour chaque pointeur de pieces du joueur adverse je : 
    // 1- trouve leur position
    // 2- regarde si il ne met pas mon roi en echec
    for(int i = 0; i < nbPa ; i++){
        int piecePos = getPiecePosition(PiecesAdverse[i],grille);
        if(isPossible(piecePos,king,grille) == 1){
            return 1;
        }
    }
    // Je retourne 0 si je ne suis pas en echec !
    return 0;

}

// Fonction qui verifie si je met le joueur adverse en echec apres mon deplacement
int isPutEchec(Joueur *joueurActif,int solveur2, Piece *grille[]){
    int king;
    if(joueurActif->couleur == 'b')
        king = getBlackKing(grille);
    else if(joueurActif->couleur == 'n')
        king = getWhiteKing(grille);
    
    int nbPa = 0;
    Piece **PiecesAMoi = getJoueurPieces(joueurActif,&nbPa);

    for(int i =0; i<nbPa;i++){
        int piecePos = getPiecePosition(PiecesAMoi[i],grille);
        if(isPossible(piecePos,king,grille) == 1){
            return 1;
        }
    }
    return 0;
}

int isEchecMat(Joueur *joueurActif,Piece *grille[]){
    // Je prend toutes les pieces de mon joueur, je les bouge partout
    // si je reste quand même en echec alors c'est perdu !
    int Fin = 1; // Si je trouve aucune possibilité alors FIn reste a 1
    int nbPa = 0;
    Piece **PiecesAMoi = getJoueurPieces(joueurActif,&nbPa);

    for(int i =0;i<nbPa;i++){ // Je parcours mes pieces
        int PiecePos = getPiecePosition(PiecesAMoi[i],grille);
        // je vais bouger ma pieces dans toutes les positions possibles et voir
        // si un coup me permet de sortir de l'echec
        for(int y = 10;y < 90;y++){
            if(isPossible(PiecePos,y,grille) == 1){ // si le déplacement est possible alors regarder si l'echec disparait
                //Piece *grilleCopie[] = grille; // j'aimerais faire une copie de ma grille originel, afin de bouger 
                // afin de bouger ma pieces MAIS pas dans la vrai grille, pour ensuite tester l'echec.
                /*
                if(isEchec(......)){ // Je dois verifier à cet endroit si je suis toujours en echec
                    Fin = 0;
                }*/
            }
        }
    }
    return Fin;
}
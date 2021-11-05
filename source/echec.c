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
    
    printf("\n\n########### Je rentre dans IsEchec #############\n\n");
    int king;
    if(joueurActif->couleur == 'b')
        king = getWhiteKing(grille);
    else if(joueurActif->couleur == 'n')
        king = getBlackKing(grille);
    
    // Je recupère tout les pointeur de Pieces du joueur adverse
    int nbPa = 0;
    Piece** PiecesAdverse = getJoueurPieces(joueurAdverse,&nbPa);
    //printf("\n\n ## je suis dans isEchec et voila les pieces adverses : %s\n",JoueurPiecesToString(joueurAdverse));
    // Pour chaque pointeur de pieces du joueur adverse je : 
    // 1- trouve leur position
    // 2- regarde si il ne met pas mon roi en echec
    for(int i = 0; i < nbPa ; i++){
        printf("\n(isEchec) piecesAdverses[i].type : %c",getPieceType(PiecesAdverse[i]));
        int piecePos = getPiecePosition(PiecesAdverse[i],grille);
        if(isPossible(piecePos,king,grille) == 1){
            return 1;
        }
    }
    // Je retourne 0 si je ne suis pas en echec !
    printf("\n\n########### Je SORS de IsEchec #############\n\n");
    return 0;

}

// Fonction qui verifie si je met le joueur adverse en echec apres mon deplacement
int isPutEchec(Joueur *joueurActif, Piece *grille[]){
    int king;
    if(joueurActif->couleur == 'b')
        king = getBlackKing(grille);
    else if(joueurActif->couleur == 'n')
        king = getWhiteKing(grille);
    
    int nbPa = 0;
    Piece **PiecesAMoi = getJoueurPieces(joueurActif,&nbPa);

    for(int i =0; i<nbPa;i++){
        printf("\n(isPUTEchec) piecesAMoi[i].type : %c",getPieceType(PiecesAMoi[i]));
        int piecePos = getPiecePosition(PiecesAMoi[i],grille);
        if(isPossible(piecePos,king,grille) == 1){
            return 1;
        }
    }
    return 0;
}

int isEchecMat(Joueur *joueurEnEchec,Joueur *autreJoueur,Piece *grille[]){
    printf("\n\n########## Je RENTRE DANS ISECHECMAT !!! ###########\n\n");
    // Je prend toutes les pieces de mon joueur, je les bouge partout
    // si je reste quand même en echec alors c'est perdu !
    int Fin = 1; // Si je trouve aucune possibilité alors FIn reste a 1
    int nbPa = 0;
    char* coord = (char*)malloc(sizeof(char) * 5);
    coord[4] = '\0';


    Piece **grilleCopie = (Piece**)malloc(sizeof(Piece) * 100); // Utile par la suite, vous allez comprendre
    for(int i = 0;i<100;i++){
        grilleCopie[i] = creationPieceVide();
    }

    for(int i = 0;i<100;i++){
        (*grilleCopie[i]) = (*grille[i]);
    }

    printf(" \ntest grille copie : %c\n",grilleCopie[41]->type);

    Piece **PiecesAMoi = getJoueurPieces(joueurEnEchec,&nbPa);
    char coord1 = 0;
    char coord2 = 0;
    char coord3 = 0;
    char coord4 = 0;

    char *nbCoord = (char*)malloc(1); 
    char *nbCoord2 = (char*)malloc(1);

    for(int i =0;i<nbPa;i++){ // Je parcours mes pieces
        int PiecePos = getPiecePosition(PiecesAMoi[i],grille);
        coord[0] = getReverseCoord(PiecePos,nbCoord);
        coord[1] = *nbCoord;
        printf("\n\n ###coord de %c est : %c%c### \n\n",PiecesAMoi[i]->type,coord[0],coord[1]);
        
        // je vais bouger ma pieces dans toutes les positions possibles et voir
        // si un coup me permet de sortir de l'echec
        for(int y = 10;y < 90;y++){
            coord[2] = getReverseCoord(y,nbCoord2);
            coord[3] = *nbCoord2;
            printf("\n\n coord[2,3] = %c%c  \n",coord[2],coord[3]);
            if(deplacementPiece(joueurEnEchec,autreJoueur,coord,grille) == 1){
                Fin = 0;
                break;
            }
        }
    }
    free(nbCoord);
    free(nbCoord2);
    free(coord);
    free(grilleCopie);

    printf("### Fin = %d ####",Fin);
    return Fin;
}
int initialisationPieceFinale(Piece *piece,Piece *grille[]){

    // si la piece appartient au joueur noir
    if(getPieceColor(piece) == 'n'){
        if(getPieceType(piece) == 'd')
            grille[57] = piece;
        else if(getPieceType(piece) == 'r')
            grille[15] = piece;
        else if(getPieceType(piece) == 't')
            grille[82] = piece;
        else if(getPieceType(piece) == 'f')
            grille[65] = piece;
        return 1;
    }
    // si la pièce appartient au joueur blanc
    if(getPieceColor(piece) == 'b'){
        if(getPieceType(piece) == 'D')
            grille[23] = piece;
        else if(getPieceType(piece) == 'R')
            grille[41] = piece;
        else if(getPieceType(piece) == 'T')
            grille[43] = piece;
        else if(getPieceType(piece) == 'F')
            grille[72] = piece;
        return 2;
    }
    return 0;
}

int initialisationPieceComplet(Piece *piece,Piece *grille[]){
    if(getPieceColor(piece) == 'n'){
        if(getPieceType(piece) == 'd')
            grille[14] = piece;
        else if(getPieceType(piece)== 'r')
            grille[15] = piece;
        else if(getPieceType(piece)== 't')
            grille[11] = piece;
        else if(getPieceType(piece) == 'f')
            grille[13] = piece;
        return 1;
    }
    // si la pièce appartient au joueur blanc
    if(getPieceColor(piece) == 'b'){
        if((*piece).type == 'D')
            grille[84] = piece;
        else if(getPieceType(piece) == 'R')
            grille[85] = piece;
        else if(getPieceType(piece) == 'T')
            grille[81] = piece;
        else if(getPieceType(piece)== 'F')
            grille[83] = piece;
        return 2;
    }
    return 0;
}

int creationSetEchecFinale(Joueur *Joueur1, Joueur *Joueur2,Piece *grille[]){

    // Je commancee par créer mes pieces
    Piece* roiBlanc = creationPiece('r','b');
    addPieceJoueur(Joueur1,roiBlanc);
    Piece* roiNoir = creationPiece('r','n');
    addPieceJoueur(Joueur2,roiNoir);
    Piece* tourBlanc = creationPiece('t','b');
    addPieceJoueur(Joueur1,tourBlanc);
    Piece* dameBlanc = creationPiece('d','b');
    addPieceJoueur(Joueur1,dameBlanc);
    Piece* fouNoir = creationPiece('f','n');
    addPieceJoueur(Joueur2,fouNoir);

    // Placement des pièces sur l'échequier
    if(initialisationPieceFinale(roiBlanc,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    if(initialisationPieceFinale(roiNoir,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    if(initialisationPieceFinale(tourBlanc,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    if(initialisationPieceFinale(dameBlanc,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    if(initialisationPieceFinale(fouNoir,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    return 1;
        
}

int creationSetEchecComplet(Joueur *Joueur1, Joueur *Joueur2,Piece *grille[]){
    // Je commancee par créer mes pieces
    Piece* roiBlanc = creationPiece('r','b');
    Joueur1->pieceJoueur[0] = roiBlanc;
    Piece* roiNoir = creationPiece('r','n');
    Joueur2->pieceJoueur[0] = roiNoir;
    Piece* tourBlanc = creationPiece('t','b');
    Joueur1->pieceJoueur[1] = tourBlanc;
    Piece* tourNoir = creationPiece('t','n');
    Joueur2->pieceJoueur[1] = tourNoir;
    Piece* dameBlanc = creationPiece('d','b');
    Joueur1->pieceJoueur[2] = dameBlanc;
    Piece* dameNoir = creationPiece('d','n');
    Piece* fouBlanc = creationPiece('f','b');
    Piece* fouNoir = creationPiece('f','n');
    

    // Placement des pièces sur l'échequier
    if(initialisationPieceComplet(roiBlanc,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    if(initialisationPieceComplet(roiNoir,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    if(initialisationPieceComplet(tourBlanc,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    if(initialisationPieceComplet(tourNoir,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    if(initialisationPieceComplet(dameBlanc,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    if(initialisationPieceComplet(dameNoir,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    if(initialisationPieceComplet(fouBlanc,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    if(initialisationPieceComplet(fouNoir,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    return 1;
}
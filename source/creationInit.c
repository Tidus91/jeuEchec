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
            // Inutile car Union, perte de 1 h pour comprendre #PLS
            pieceRandom.typep.dame.nom = '0';
            pieceRandom.typep.tour.nom = '0';
            pieceRandom.typep.roi.nom = 'R';
            pieceRandom.typep.roi.deplacement = "adjacent";
        }
        else if(type == 'd'){
            pieceRandom.typep.dame.nom = 'D';
            pieceRandom.typep.roi.deplacement = "rectiligneDiagonale";
        }
        else if(type == 't'){
            pieceRandom.typep.tour.nom = 'T';
            pieceRandom.typep.roi.deplacement = "rectiligne";
        }
        else if(type == 'f'){
            pieceRandom.typep.tour.nom = 'F';
            pieceRandom.typep.roi.deplacement = "diagonale";
        }
    }
    if(couleur == 'n'){
        pieceRandom.couleur='n';
        if(type=='r'){
            pieceRandom.typep.roi.nom = 'r';
            pieceRandom.typep.roi.deplacement = "adjacent";
        }
        else if(type == 'd'){
            pieceRandom.typep.dame.nom = 'd';
            pieceRandom.typep.roi.deplacement = "rectiligneDiagonale";
        }
        else if(type == 't'){
            pieceRandom.typep.tour.nom = 't';
            pieceRandom.typep.roi.deplacement = "rectiligne";
        }
        else if(type == 'f'){
            pieceRandom.typep.tour.nom = 'f';
            pieceRandom.typep.roi.deplacement = "diagonale";
        }
    }
    return pieceRandom;
}

int initialisationPieceFinale(Piece *piece,Piece *grille){

    // si la piece appartient au joueur noir
    if(piece->couleur == 'n'){
        if((*piece).typep.dame.nom == 'd')
            //grille[57] = (piece->typep.dame.nom);
            grille[57] = (*piece);
        else if(piece->typep.roi.nom == 'r')
            //grille[15] = (*piece).typep.roi.nom;
            grille[15] = (*piece);
        else if(piece->typep.tour.nom == 't')
            //grille[82] = piece->typep.tour.nom;
            grille[82] = (*piece);
        else if(piece->typep.tour.nom == 'f')
            //grille[82] = piece->typep.tour.nom;
            grille[65] = (*piece);
        return 1;
    }
    // si la pièce appartient au joueur blanc
    if(piece->couleur == 'b'){
        if((*piece).typep.dame.nom == 'D')
            //grille[23] = (piece->typep.dame.nom);
            grille[23] = (*piece);
        else if(piece->typep.roi.nom == 'R')
            //grille[41] = (*piece).typep.roi.nom;
            grille[41] = (*piece);
        else if(piece->typep.tour.nom == 'T')
            //grille[43] = piece->typep.tour.nom;
            grille[43] = (*piece);
        else if(piece->typep.tour.nom == 'F')
            //grille[82] = piece->typep.tour.nom;
            grille[72] = (*piece);
        return 2;
    }
    return 0;
}

int initialisationPieceComplet(Piece *piece,Piece *grille){
    if(piece->couleur == 'n'){
        if((*piece).typep.dame.nom == 'd')
            //grille[57] = (piece->typep.dame.nom);
            grille[14] = (*piece);
        else if(piece->typep.roi.nom == 'r')
            //grille[15] = (*piece).typep.roi.nom;
            grille[15] = (*piece);
        else if(piece->typep.tour.nom == 't'){
            grille[11] = (*piece);
        }
        else if(piece->typep.tour.nom == 'f')
            //grille[82] = piece->typep.tour.nom;
            grille[13] = (*piece);
        return 1;
    }
    // si la pièce appartient au joueur blanc
    if(piece->couleur == 'b'){
        if((*piece).typep.dame.nom == 'D')
            //grille[23] = (piece->typep.dame.nom);
            grille[84] = (*piece);
        else if(piece->typep.roi.nom == 'R')
            //grille[41] = (*piece).typep.roi.nom;
            grille[85] = (*piece);
        else if(piece->typep.tour.nom == 'T')
            //grille[43] = piece->typep.tour.nom;
            grille[81] = (*piece);
        else if(piece->typep.tour.nom == 'F')
            //grille[82] = piece->typep.tour.nom;
            grille[83] = (*piece);
        return 2;
    }
    return 0;
}

Joueur creationJoueur(char couleurParam){
    assert(couleurParam == 'b' || couleurParam == 'n');
    if(couleurParam != 'b' && couleurParam != 'n'){
        printf("Erreur, vous devez choisir la couleur 'b' ou 'n' pour un joueur !\n");
    }
    Joueur joueurRandom;
    joueurRandom.couleur = couleurParam;
    joueurRandom.echec = 0;
    joueurRandom.gagner = 0;
    if(couleurParam == 'b')
        joueurRandom.actif = 1;
    else if(couleurParam == 'n')
        joueurRandom.actif = 0;
    return joueurRandom;
}

int creationSetEchecFinale(Joueur *Joueur1, Joueur *Joueur2,Piece *grille){

    // Je commancee par créer mes pieces
    Piece roiBlanc = creationPiece('r','b');
    Joueur1->pieceJoueur[0] = roiBlanc;
    Piece roiNoir = creationPiece('r','n');
    Joueur2->pieceJoueur[0] = roiNoir;
    Piece tourBlanc = creationPiece('t','b');
    Joueur1->pieceJoueur[1] = tourBlanc;
    Piece dameBlanc = creationPiece('d','b');
    Joueur1->pieceJoueur[2] = dameBlanc;
    Piece fouNoir = creationPiece('f','n');
    Joueur2->pieceJoueur[1] = fouNoir;

    // Placement des pièces sur l'échequier
    if(initialisationPieceFinale(&roiBlanc,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    if(initialisationPieceFinale(&roiNoir,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    if(initialisationPieceFinale(&tourBlanc,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    if(initialisationPieceFinale(&dameBlanc,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    if(initialisationPieceFinale(&fouNoir,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    return 1;
        
}

int creationSetEchecComplet(Joueur *Joueur1, Joueur *Joueur2,Piece *grille){
    // Je commancee par créer mes pieces
    Piece roiBlanc = creationPiece('r','b');
    Joueur1->pieceJoueur[0] = roiBlanc;
    Piece roiNoir = creationPiece('r','n');
    Joueur2->pieceJoueur[0] = roiNoir;
    Piece tourBlanc = creationPiece('t','b');
    Joueur1->pieceJoueur[1] = tourBlanc;
    Piece dameBlanc = creationPiece('d','b');
    Joueur1->pieceJoueur[2] = dameBlanc;
    Piece fouNoir = creationPiece('f','n');

    // Placement des pièces sur l'échequier
    if(initialisationPieceComplet(&roiBlanc,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    if(initialisationPieceComplet(&roiNoir,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    if(initialisationPieceComplet(&tourBlanc,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    if(initialisationPieceComplet(&dameBlanc,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    if(initialisationPieceComplet(&fouNoir,grille) == 0){
        printf("Erreur !! mauvaise initialisation \n");
        return 0;
    }
    return 1;
}
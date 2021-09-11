Piece creationPiece(Piece* piece,char *type, char couleur){

    if(!(type == "roi" || type == "dame" || type == "tour"))
        printf("Erreur, ce type de piece n'existe pas ! \n\n");
    if(!(couleur == 'b' || couleur == 'n'))
        printf("Erreur mauvaise couleur saisie !");
    
    if(couleur == 'b'){
        piece->couleur='b';
        if(type=="roi"){
        piece->typep.dame.nom = '0';
        piece->typep.tour.nom = '0';
        piece->typep.roi.nom = 'R';
    }
    else if(type == "dame"){
        piece->typep.dame.nom = 'D';
        piece->typep.tour.nom = '0';
        piece->typep.roi.nom = '0';
    }
    else if(type == "tour"){
        piece->typep.dame.nom = '0';
        piece->typep.tour.nom = 'T';
        piece->typep.roi.nom = '0';
    }
    }
    if(couleur == 'n'){
        piece->couleur='n';
        if(type=="roi"){
        piece->typep.dame.nom = '0';
        piece->typep.tour.nom = '0';
        piece->typep.roi.nom = 'r';
    }
    else if(type == "dame"){
        piece->typep.dame.nom = 'd';
        piece->typep.tour.nom = '0';
        piece->typep.roi.nom = '0';
    }
    else if(type == "tour"){
        piece->typep.dame.nom = '0';
        piece->typep.tour.nom = 't';
        piece->typep.roi.nom = '0';
    }
    }

    return (*piece);
}

int initialisationPiece(Piece *piece,char *grille){

    // si la piece appartient au joueur noir
    if(piece->couleur == 'n'){
        if((*piece).typep.dame.nom == 'd')
            grille[57] = (piece->typep.dame.nom);
        else if(piece->typep.roi.nom == 'r')
            grille[15] = (*piece).typep.roi.nom;
        else if(piece->typep.tour.nom == 't')
            grille[82] = piece->typep.tour.nom;
        return 1;
    }
    // si la pièce appartient au joueur blanc
    if(piece->couleur == 'b'){
        if((*piece).typep.dame.nom == 'D')
            grille[35] = (piece->typep.dame.nom);
        else if(piece->typep.roi.nom == 'R')
            grille[41] = (*piece).typep.roi.nom;
        else if(piece->typep.tour.nom == 'T')
            grille[12] = piece->typep.tour.nom;
        return 2;
    }
    return 0;
}
Piece creationPiece(Piece* piece,char type, char couleur){

    if(!(type == 'r' || type == 'd' || type == 't' || type == 'f'))
        printf("Erreur, ce type de piece n'existe pas ! \n\n");
    if(!(couleur == 'b' || couleur == 'n'))
        printf("Erreur mauvaise couleur saisie !");
    
    if(couleur == 'b'){
        piece->couleur='b';
        if(type=='r'){
            // Inutile car Union, perte de 1 h pour comprendre #PLS
            piece->typep.dame.nom = '0';
            piece->typep.tour.nom = '0';
            piece->typep.roi.nom = 'R';
            piece->typep.roi.deplacement = "adjacent";
        }
        else if(type == 'd'){
            piece->typep.dame.nom = 'D';
            piece->typep.roi.deplacement = "rectiligneDiagonale";
        }
        else if(type == 't'){
            piece->typep.tour.nom = 'T';
            piece->typep.roi.deplacement = "rectiligne";
        }
        else if(type == 'f'){
            piece->typep.tour.nom = 'F';
            piece->typep.roi.deplacement = "diagonale";
        }
    }
    if(couleur == 'n'){
        piece->couleur='n';
        if(type=='r'){
            piece->typep.roi.nom = 'r';
            piece->typep.roi.deplacement = "adjacent";
        }
        else if(type == 'd'){
            piece->typep.dame.nom = 'd';
            piece->typep.roi.deplacement = "rectiligneDiagonale";
        }
        else if(type == 't'){
            piece->typep.tour.nom = 't';
            piece->typep.roi.deplacement = "rectiligne";
        }
        else if(type == 'f'){
            piece->typep.tour.nom = 'f';
            piece->typep.roi.deplacement = "diagonale";
        }
    }

    return (*piece);
}

int initialisationPiece(Piece *piece,Piece *grille){

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
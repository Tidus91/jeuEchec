Joueur creationJoueur(char couleurParam){
    assert(couleurParam == 'b' || couleurParam == 'n');
    if(couleurParam != 'b' && couleurParam != 'n'){
        printf("Erreur, vous devez choisir la couleur 'b' ou 'n' pour un joueur !\n");
    }
    Joueur joueurRandom;
    joueurRandom.couleur = couleurParam;
    joueurRandom.echec = 0;
    joueurRandom.gagner = 0;
    joueurRandom.nombreCoups = 0;
    if(couleurParam == 'b')
        joueurRandom.actif = 1;
    else if(couleurParam == 'n')
        joueurRandom.actif = 0;
    for(int i =0;i<16;i++){
        joueurRandom.pieceJoueur[i] = creationPieceVide();
    }
    return joueurRandom;
}

char getJoueurColor(Joueur* joueur){
    return joueur->couleur;
}

int isJoueurActif(Joueur* joueur){
    return joueur->actif;
}
int setJoueurActif(Joueur* joueurA, Joueur* joueurB){
    if(isJoueurActif(joueurA) == 1){
        joueurA->actif = 0;
        joueurB->actif = 1;
        return 1;
    }
    else{
        printf("quelque chose c'est mal passe (setJoueurActif) ");
        return 0;
    }
    printf("quelque chose c'est mal passe (setJoueurActif) ");
    return 0;
}

int getJoueurGagner(Joueur* joueur){
    return joueur->gagner;
}
int setJoueurGagner(Joueur* joueur){
    joueur->gagner = 1;
}

int isJoueurEchec(Joueur* joueur){
    return joueur->echec;
}
int setJoueurEchec(Joueur* joueur){
    joueur->echec = 1;
}

int getJoueurNbCoups(Joueur* joueur){
    return joueur->nombreCoups;
}
void addJoueurNbCoups(Joueur* joueur){
    joueur->nombreCoups++;
}

int addPieceJoueur(Joueur* joueur,Piece* piece){
    int compteur = 0;
    for(int i = 0 ; i<16;i++){
        if(joueur->pieceJoueur[i]->etat == 1)
            compteur++;
    }
    assert(compteur < 16);
    joueur->pieceJoueur[compteur] = piece;
    if(joueur->pieceJoueur[compteur] != NULL)
        return 1;
    printf("probleme addPieceJoueur.... return 0...");
    return 0;
}
int deletePieceJoueur(Joueur* joueur,Piece* piece){
    for(int i = 0;i<16;i++){
        if(joueur->pieceJoueur[i] == piece){
            joueur->pieceJoueur[i] = creationPieceVide();
            return 1;
        }
    }
    return 0;
}

char* getJoueurPieces(Joueur* joueur){
    int compteur = 0;
    char *chaine = (char*)malloc(1000);
    chaine[0] = '\0';
    char *s = chaine;
    s += sprintf(s,"Vous avez les pieces suivante : ");
    for(int i = 0;i<16;i++){
        if(joueur->pieceJoueur[i]->etat == 1){
            compteur++;
            s += sprintf(s,"%c - ",joueur->pieceJoueur[i]->type);
        }
    }
    s += sprintf(s," ce qui vous fait un total de %d pieces !",compteur);
    return chaine;
}
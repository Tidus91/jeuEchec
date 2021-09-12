void deplacementPiece(Piece *piece,char *coord, char *grille) {

    int solveur = 0;
    int solveur2 = 0;
    int solveur3 = 0;
    solveur = testPositionInitial(piece,coord,grille);
    solveur2 = testPositionFinal(piece,coord,grille);
    solveur3 = isPossible(piece,solveur,solveur2,grille);
    if(solveur3 != 0){
        grille[solveur2] = piece->typep.roi.nom;
        grille[solveur] = '.';
    }
}

int testPositionInitial(Piece* piece,char *coord, char* grille) {

    // j'utilise solveur pour calculer l'index total pour aller chercher la correspondance dans ma grille
    int solveur = 0;
 
    if(coord[0] == 'a')
        solveur = solveur + 1;
    else if(coord[0] == 'b')
        solveur = solveur + 2;
    else if(coord[0] == 'c')
        solveur = solveur + 3;
    else if(coord[0] == 'd')
        solveur = solveur + 4;
    else if(coord[0] == 'e')
        solveur = solveur + 5;
    else if(coord[0] == 'f')
        solveur = solveur + 6;
    else if(coord[0] == 'g')
        solveur = solveur + 7;
    else if(coord[0] == 'h')
        solveur = solveur + 8;
    if(coord[1] == '8')
        solveur = solveur + 10;
    else if(coord[1] == '7')
        solveur = solveur + 20;
    else if(coord[1] == '6')
        solveur = solveur + 30;
    else if(coord[1] == '5')
        solveur = solveur + 40;
    else if(coord[1] == '4')
        solveur = solveur + 50;
    else if(coord[1] == '3')
        solveur = solveur + 60;
    else if(coord[1] == '2')
        solveur = solveur + 70;
    else if(coord[1] == '1')
        solveur = solveur + 80;
/*
    printf("\n si j'ai bien coder êtes actuellement en : %c%c qui correspont à : %d  \n",coord[0],coord[1],solveur);
    printf("\n vous etes la piece : %c \n",piece->typep.roi.nom);
    printf("\n grille solveur : %c \n",grille[solveur]);
*/
    if(grille[solveur] == piece->typep.roi.nom){
        printf("La pièce est bien en %c%c dans la grille \n",coord[0],coord[1]);
        return solveur;
    }
    else
    {
        printf("La piece %c n'est pas à la coordonnée que vous avez rentre ! \n",piece->typep.roi.nom);
        return 0;
    }
    
}

int testPositionFinal(Piece* piece, char *coord, char* grille){

    int solveur = 0;

    if(coord[2] == 'a')
        solveur = solveur + 1;
    else if(coord[2] == 'b')
        solveur = solveur + 2;
    else if(coord[2] == 'c')
        solveur = solveur + 3;
    else if(coord[2] == 'd')
        solveur = solveur + 4;
    else if(coord[2] == 'e')
        solveur = solveur + 5;
    else if(coord[2] == 'f')
        solveur = solveur + 6;
    else if(coord[2] == 'g')
        solveur = solveur + 7;
    else if(coord[2] == 'h')
        solveur = solveur + 8;
    if(coord[3] == '8')
        solveur = solveur + 10;
    else if(coord[3] == '7')
        solveur = solveur + 20;
    else if(coord[3] == '6')
        solveur = solveur + 30;
    else if(coord[3] == '5')
        solveur = solveur + 40;
    else if(coord[3] == '4')
        solveur = solveur + 50;
    else if(coord[3] == '3')
        solveur = solveur + 60;
    else if(coord[3] == '2')
        solveur = solveur + 70;
    else if(coord[3] == '1')
        solveur = solveur + 80;

/*
    printf("Je souhaite donc arriver à la case %d \n",solveur);
    printf("je suis une piece : %c et mon deplacement est : %s \n",piece->typep.roi.nom,piece->typep.roi.deplacement);
*/
    return solveur;
}

int isPossible(Piece *piece ,int solveur,int solveur2,char *grille){
    int testPos = 0;
    if(piece->typep.roi.deplacement == "adjacent"){
        printf("cette piece se déplace de maniere adjacente ! \n");
        // je ne peux me déplacer dans mon index seulement de +-1 ou +-1+-10 ou +-10
        if(solveur2 == solveur+1 || solveur2 == solveur-1 || solveur2 == solveur+10 || solveur2 == solveur-10 || solveur2 == solveur+11 || solveur2 == solveur-11){
            printf("Position pre-autoriser, recherche d'une eventuelle piece allie à cette position \n");
            if(piece->couleur == 'b'){
                // si la lettre est minuscule alors la couleur est noire
                if(!(grille[solveur2] >= 'A' && grille[solveur2] <= 'Z')){
                    printf("alors le déplacement est autorisé \n");
                    testPos = 1;
                    return testPos;
                }
            }
            else if(piece->couleur == 'n'){
                // si la lettre est majuscule alors la couleur est blanche
                if(!(grille[solveur2] >= 'a' && grille[solveur2] <= 'z')){
                    printf("alors le déplacement est autorisé \n");
                    testPos = 1;
                    return testPos;
                }
            }
        }
    }
    else if(piece->typep.roi.deplacement == "rectiligne"){
        printf("cette piece se déplace de maniere rectiligne ! \n");
        // je ne peux me déplacer dans mon index seulement si .....
        int calcul = 0 ;
        calcul = solveur2%8;

    }
    else if(piece->typep.roi.deplacement == "rectiligneDiagonale"){
        printf("cette piece se déplace de maniere rectiligne et diagonale ! \n");
    }
    else{
        printf("Erreur !! \n");
        return 0;
    }
}
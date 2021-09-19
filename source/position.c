//void deplacementPiece(Piece *piece,char *coord, Piece *grille) {
int deplacementPiece(Joueur *joueur,char *coord,Piece *grille){

    int solveur = 0;
    int solveur2 = 0;
    int solveur3 = 0;
    solveur = testPositionInitial(joueur,coord,grille);
    if(solveur == 0){
        return 0;
    }
    solveur2 = testPositionFinal(coord,grille);
    if(solveur == solveur2){
        printf("Vous ne pouvez pas vous faire du surplace....\n");
        return 0;
    }
    solveur3 = isPossible(solveur,solveur2,grille);
    if(solveur3 != 0){
        //grille[solveur2] = piece->typep.roi.nom;
        //grille[solveur] = '.';
        //grille[solveur2].typep.roi.nom = grille[solveur].typep.roi.nom ;
        grille[solveur2] = grille[solveur];
        grille[solveur].typep.roi.nom = '.';
        return 1;
    }
    printf("Quelque chose c'est mal passe, rentrer un coup legale svp \n");
    return 0;
}

//int testPositionInitial(Piece* piece,char *coord, Piece *grille) {
int testPositionInitial(Joueur *joueur,char *coord,Piece *grille){

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
/*
    if(grille[solveur] == piece->typep.roi.nom){
        printf("La pièce est bien en %c%c dans la grille \n",coord[0],coord[1]);
        return solveur;
    }
*/
    if(grille[solveur].typep.roi.nom >= 'a' && grille[solveur].typep.roi.nom <= 'z' && joueur->couleur == 'n'){
        printf("Il y a bien une piece noir en %c%c dans la grille \n",coord[0],coord[1]);
        return solveur;
    }
    else if(grille[solveur].typep.roi.nom >= 'A' && grille[solveur].typep.roi.nom <= 'Z' && joueur->couleur == 'b'){
        printf("Il y a bien une piece de couleur blanche en %c%c dans la grille\n",coord[0],coord[1]);
        return solveur;
    }
    else
    {
        printf("Il n'y a pas de piece a cette coordonnee OU vous n'êtes pas autorise à jouer une piece de cette couleur ! \n");
        return 0;
    }

    
}

//int testPositionFinal(Piece* piece, char *coord, char* grille){
int testPositionFinal(char* coord, Piece* grille){

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

int isPossible(int solveur,int solveur2,Piece *grille){
    printf("je passe bien dans isPossible ! \n");
    int testPos = 0;
    //if(piece->typep.roi.deplacement == "adjacent"){
    if(grille[solveur].typep.roi.deplacement == "adjacent"){
        printf("cette piece se déplace de maniere adjacente (isPossible)! \n");
        // je ne peux me déplacer dans mon index seulement de +-1 ou +-1+-10 ou +-10
        if(solveur2 == solveur+1 || solveur2 == solveur-1 || solveur2 == solveur+10 || solveur2 == solveur-10 || solveur2 == solveur+11 || solveur2 == solveur-11 || solveur2 == solveur-9 || solveur2 == solveur+9){
            printf("Position pre-autoriser, recherche d'une eventuelle piece allie à cette position \n");
            //if(piece->couleur == 'b'){
            if(grille[solveur].couleur == 'b'){
                // si la lettre est minuscule alors la couleur est noire
                if(!(grille[solveur2].typep.roi.nom >= 'A' && grille[solveur2].typep.roi.nom <= 'Z')){
                    printf("alors le déplacement est autorisé \n");
                    testPos = 1;
                    return testPos;
                }
            }
            else if(grille[solveur].couleur == 'n'){
                // si la lettre est majuscule alors la couleur est blanche
                if(!(grille[solveur2].typep.roi.nom >= 'a' && grille[solveur2].typep.roi.nom <= 'z')){
                    printf("alors le déplacement est autorisé \n");
                    testPos = 1;
                    return testPos;
                }
            }
        }
        else{
            printf("deplacement non autorise ! ");
            return 0;
        }
    }
    else if(grille[solveur].typep.roi.deplacement == "rectiligne"){
        printf("cette piece se déplace de maniere rectiligne ! (isPossible function) \n");
        // je ne peux me déplacer dans mon index seulement si .....
        int calcul = 0 ;
        int calculR = solveur%10;
        int calculQ = solveur/10;
        //Verif du déplacement horizontale
        printf("solveur = : %d \n",solveur);
        printf("calcuR =  %d \ncalculQ = %d\n",calculR,calculQ);
        printf("solveur2 = : %d\n",solveur2);
        printf("solveur2 - solveur1 = : %d \n",solveur2-solveur);
        if(calculR == 1){
            printf("déplacement pre-autorise , checking de la ligne de vue requis (calcul R=1 , isPossible function\n");
            return solveurLigneDeVueRectiligne(solveur,solveur2,grille);
        }
        else if(calculR == 2){
            printf("isPossibleRectigligneCalculR2\n");
            return solveurLigneDeVueRectiligne(solveur,solveur2,grille);
        }
        else if(calculR == 3){
            printf("isPossibleisRectiligneCalculR3 \n");
            return solveurLigneDeVueRectiligne(solveur,solveur2,grille);
        }
        else if(calculR == 4){
            printf("isPossibleRectiligneCalculR4 \n");
            return solveurLigneDeVueRectiligne(solveur,solveur2,grille);
        }
        else if(calculR == 5){
            printf("isPossibleRectiligneCalculR5");
            return solveurLigneDeVueRectiligne(solveur,solveur2,grille);
        }
        else if(calculR == 6){
            printf("isPossibleRectiligneCalculR6 \n");
            return solveurLigneDeVueRectiligne(solveur,solveur2,grille);
        }
        else if(calculR == 7){
            printf("isPossibleRectiligneCalculR7 \n");
            return solveurLigneDeVueRectiligne(solveur,solveur2,grille);
        }
        else if(calculR == 8){
            printf("isPossibleRectiligneCalculR8 \n");
            return solveurLigneDeVueRectiligne(solveur,solveur2,grille);
        }
        if(calculQ == 1){
            if(solveur2 == solveur+10 || solveur2 == solveur+20 || solveur2 == solveur+30 || solveur2 == solveur+40 || solveur2 == solveur+50 || solveur2 == solveur+60 || solveur2 == solveur+70){
                printf("déplacement pre-autorise , checking de la ligne de vue requis \n");
                return solveurLigneDeVueRectiligne(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        else if(calculQ == 2){
            if(solveur2 == solveur-10 || solveur2 == solveur+10 || solveur2 == solveur+20 || solveur2 == solveur+30 || solveur2 == solveur+40 || solveur2 == solveur+50 || solveur2 == solveur+60){
                printf("déplacement pre-autorise , checking de la ligne de vue requis \n");
                return solveurLigneDeVueRectiligne(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        else if(calculQ == 3){
            if(solveur2 == solveur-20 || solveur2 == solveur-10 || solveur2 == solveur+10 || solveur2 == solveur+20 || solveur2 == solveur+30 || solveur2 == solveur+40 || solveur2 == solveur+50){
                printf("déplacement pre-autorise , checking de la ligne de vue requis \n");
                return solveurLigneDeVueRectiligne(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        else if(calculQ == 4){
            if(solveur2 == solveur-30 || solveur2 == solveur-20 || solveur2 == solveur-10 || solveur2 == solveur+10 || solveur2 == solveur+20 || solveur2 == solveur+30 || solveur2 == solveur+40){
                printf("déplacement pre-autorise , checking de la ligne de vue requis \n");
                return solveurLigneDeVueRectiligne(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        else if(calculQ == 5){
            if(solveur2 == solveur-40 || solveur2 == solveur-30 || solveur2 == solveur-20 || solveur2 == solveur-10 || solveur2 == solveur+10 || solveur2 == solveur+20 || solveur2 == solveur+30){
                printf("déplacement pre-autorise , checking de la ligne de vue requis \n");
                return solveurLigneDeVueRectiligne(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        else if(calculQ == 6){
            if(solveur2 == solveur-50 || solveur2 == solveur-40 || solveur2 == solveur-30 || solveur2 == solveur-20 || solveur2 == solveur-10 || solveur2 == solveur+10 || solveur2 == solveur+20){
                printf("déplacement pre-autorise , checking de la ligne de vue requis \n");
                return solveurLigneDeVueRectiligne(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        else if(calculQ == 7){
            if(solveur2 == solveur-60 || solveur2 == solveur-50 || solveur2 == solveur-40 || solveur2 == solveur-30 || solveur2 == solveur-20 || solveur2 == solveur-10 || solveur2 == solveur+10){
                printf("déplacement pre-autorise , checking de la ligne de vue requis \n");
                return solveurLigneDeVueRectiligne(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        else if(calculQ == 8){
            if(solveur2 == solveur-70 || solveur2 == solveur-60 || solveur2 == solveur-50 || solveur2 == solveur-40 || solveur2 == solveur-30 || solveur2 == solveur-20 || solveur2 == solveur-10){
                printf("déplacement pre-autorise , checking de la ligne de vue requis \n");
                return solveurLigneDeVueRectiligne(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        // si non verticale ni horizontale
        if(calcul == 2){
            printf("déplacement non autorisé pour ce mouvement rectiligne ! \n");
            return 0;
        }
    }
    else if(grille[solveur].typep.roi.deplacement == "rectiligneDiagonale"){
        printf("cette piece se déplace de maniere rectiligne et diagonale ! \n");
    }
    else{
        printf("Erreur !! (isPossible function) \n");
        return 0;
    }

}

int isAdjacent(Piece* piece,int solveur,int solveur2,char* grille){
    int testPos = 0;
    if(piece->typep.roi.deplacement == "adjacent"){
        printf("cette piece se déplace de maniere adjacente ! \n");
        // Gestion des erreurs possible au niveau de la premiere et derniere ligne
        if(solveur2 <= 10 && solveur2 >= 90){
            printf("Erreur ! cette piece ne peut pas se deplacer ici ! \n");
            return 0;
        }
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
}

int solveurLigneDeVueRectiligne(int solveur,int solveur2,Piece *grille){
    if(grille[solveur].typep.roi.deplacement == "rectiligne"){
        printf("cette piece se déplace de maniere rectiligne ! (fonction solveurLDVR) \n");
        // je ne peux me déplacer dans mon index seulement si .....
        int calcul = 0 ;
        // cette variable est necessaire ! au cas ou un deplacement diagonale est donne ! 
        int calculR = solveur%10;
        int calculQ = solveur/10;
        //Verif du déplacement horizontale
        if(calculR == 1){
            if(solveur2 == solveur+1 || solveur2 == solveur+2 || solveur2 == solveur+3 || solveur2 == solveur+4 || solveur2 == solveur+5 || solveur2 == solveur+6 || solveur2 == solveur+7){
                printf("déplacement pre-autorise , checking de la ligne de vue requis (CalculR = 1) \n");
                return ligneDeVueRectiligne(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        else if(calculR == 2){
            printf("je suis bien dans calculR=2 \n");
            if(solveur2 == solveur-1 || solveur2 == solveur+1 || solveur2 == solveur+2 || solveur2 == solveur+3 || solveur2 == solveur+4 || solveur2 == solveur+5 || solveur2 == solveur+6){
                printf("déplacement pre-autorise , checking de la ligne de vue requis (fonction calculR2)\n");
                return ligneDeVueRectiligne(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        else if(calculR == 3){
            if(solveur2 == solveur-2 || solveur2 == solveur-1 || solveur2 == solveur+1 || solveur2 == solveur+2 || solveur2 == solveur+3 || solveur2 == solveur+4 || solveur2 == solveur+5){
                printf("déplacement pre-autorise , checking de la ligne de vue requis (fonction calculR3)\n");
                return ligneDeVueRectiligne(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        else if(calculR == 4){
            if(solveur2 == solveur-3 || solveur2 == solveur-2 || solveur2 == solveur-1 || solveur2 == solveur+1 || solveur2 == solveur+2 || solveur2 == solveur+3 || solveur2 == solveur+4){
                printf("déplacement pre-autorise , checking de la ligne de vue requis (fonction calculR4)\n");
                return ligneDeVueRectiligne(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        else if(calculR == 5){
            if(solveur2 == solveur-4 || solveur2 == solveur-3 || solveur2 == solveur-2 || solveur2 == solveur-1 || solveur2 == solveur+1 || solveur2 == solveur+2 || solveur2 == solveur+3){
                printf("déplacement pre-autorise , checking de la ligne de vue requis (fonction calculR5)\n");
                return ligneDeVueRectiligne(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        else if(calculR == 6){
            if(solveur2 == solveur-5 || solveur2 == solveur-4 || solveur2 == solveur-3 || solveur2 == solveur-2 || solveur2 == solveur-1 || solveur2 == solveur+1 || solveur2 == solveur+2){
                printf("déplacement pre-autorise , checking de la ligne de vue requis (fonction calculR6)\n");
                return ligneDeVueRectiligne(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        else if(calculR == 7){
            if(solveur2 == solveur-6 || solveur2 == solveur-5 || solveur2 == solveur-4 || solveur2 == solveur-3 || solveur2 == solveur-2 || solveur2 == solveur-1 || solveur2 == solveur+1){
                printf("déplacement pre-autorise , checking de la ligne de vue requis (fonction calculR7)\n");
                return ligneDeVueRectiligne(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        else if(calculR == 8){
            if(solveur2 == solveur-7 || solveur2 == solveur-6 || solveur2 == solveur-5 || solveur2 == solveur-4 || solveur2 == solveur-3 || solveur2 == solveur-2 || solveur2 == solveur-1){
                printf("déplacement pre-autorise , checking de la ligne de vue requis (fonction calculR8)\n");
                return ligneDeVueRectiligne(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        // Verif du déplacement vertical
        if(calculQ == 1){
            if(solveur2 == solveur+10 || solveur2 == solveur+20 || solveur2 == solveur+30 || solveur2 == solveur+40 || solveur2 == solveur+50 || solveur2 == solveur+60 || solveur2 == solveur+70){
                printf("deplacement pre-autorise, checking de la ligne de vue requis(fonction CalculQ1 \n");
                return ligneDeVueRectiligneY(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        else if(calculQ == 2){
            printf("ah ouais grave bizarre... je passe dans calculQ = 2 .....\n");
            if(solveur2 == solveur-10 || solveur2 == solveur+10 || solveur2 == solveur+20 || solveur2 == solveur+30 || solveur2 == solveur+40 || solveur2 == solveur+50 || solveur2 == solveur+60){
                printf("déplacement pre-autorise , checking de la ligne de vue requis \n");
                return ligneDeVueRectiligneY(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        else if(calculQ == 3){
            if(solveur2 == solveur-20 || solveur2 == solveur-10 || solveur2 == solveur+10 || solveur2 == solveur+20 || solveur2 == solveur+30 || solveur2 == solveur+40 || solveur2 == solveur+50){
                printf("déplacement pre-autorise , checking de la ligne de vue requis \n");
                return ligneDeVueRectiligneY(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        else if(calculQ == 4){
            if(solveur2 == solveur-30 || solveur2 == solveur-20 || solveur2 == solveur-10 || solveur2 == solveur+10 || solveur2 == solveur+20 || solveur2 == solveur+30 || solveur2 == solveur+40){
                printf("déplacement pre-autorise , checking de la ligne de vue requis \n");
                return ligneDeVueRectiligneY(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        else if(calculQ == 5){
            if(solveur2 == solveur-40 || solveur2 == solveur-30 || solveur2 == solveur-20 || solveur2 == solveur-10 || solveur2 == solveur+10 || solveur2 == solveur+20 || solveur2 == solveur+30){
                printf("déplacement pre-autorise , checking de la ligne de vue requis \n");
                return ligneDeVueRectiligneY(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        else if(calculQ == 6){
            if(solveur2 == solveur-50 || solveur2 == solveur-40 || solveur2 == solveur-30 || solveur2 == solveur-20 || solveur2 == solveur-10 || solveur2 == solveur+10 || solveur2 == solveur+20){
                printf("déplacement pre-autorise , checking de la ligne de vue requis \n");
                return ligneDeVueRectiligneY(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        else if(calculQ == 7){
            if(solveur2 == solveur-60 || solveur2 == solveur-50 || solveur2 == solveur-40 || solveur2 == solveur-30 || solveur2 == solveur-20 || solveur2 == solveur-10 || solveur2 == solveur+10){
                printf("déplacement pre-autorise , checking de la ligne de vue requis \n");
                return ligneDeVueRectiligneY(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        else if(calculR == 8){
            if(solveur2 == solveur-70 || solveur2 == solveur-60 || solveur2 == solveur-50 || solveur2 == solveur-40 || solveur2 == solveur-30 || solveur2 == solveur-20 || solveur2 == solveur-10){
                printf("déplacement pre-autorise , checking de la ligne de vue requis \n");
                return ligneDeVueRectiligneY(solveur,solveur2,grille);
            }
            else{
                calcul++;
            }
        }
        if(calcul == 2){
            printf("deplaceement non autorise pour ce mouvement rectiligne ! \n");
            return 0;
        }
    }
}
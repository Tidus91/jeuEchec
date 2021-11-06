int deplacementPiece(Joueur *joueurActif,Joueur *joueur2,char *coord,Piece *grille[]){

    int solveur = 0;
    int solveur2 = 0;

    solveur = testPositionInitial(joueurActif,coord,grille);
    if(solveur == 0){
        return 0;
    }
    solveur2 = testPositionFinal(coord,grille);
    if(solveur == solveur2 || solveur2 == 0){
        printf("Vous ne pouvez pas vous faire du surplace....\n");
        return 0;
    }
    if(isPossible(solveur,solveur2,grille)!= 0){
        // Je dois verifier l'echec içi avant de modifier quoi que ce soit.
        // Je dois verifier si mon mouvement ne me met pas de moi même en echec

        // Soluce 1 : Je crée une copie de ma grille et je Test
        // Soluce 2: j'applique le deplacement, je test et je reverse dans le mauvais cas

        //S1 : Je copie donc ma grille, et j'applique le deplacement pour tester sans compromettre ma vrai Grille !

        /*Piece *grilleCopie = malloc(sizeof(Piece) * 100);
        for(int i=0;i<100;i++){
            grilleCopie[i] = (*grille[i]);
        }
        Piece temp = grilleCopie[solveur2];
        grilleCopie[solveur2] = grilleCopie[solveur];
        grilleCopie[solveur] = temp;

        if(isEchec(joueurActif,joueur2,grilleCopie) == 1){
            printf("\n### Vous ne pouvez pas jouer cette piece ici... cela vous mettrez vous même en Echec ! ###\n");
            return 0;
        }
        free(grilleCopie);*/


        if(getPieceType(grille[solveur2]) == '.'){
            /*
            Piece temporaire = (*grille[solveur2]);
            (*grille[solveur2]) = (*grille[solveur]);
            (*grille[solveur]) = temporaire;
            */
            Piece *temporaire = grille[solveur2];
            grille[solveur2] = grille[solveur];
            grille[solveur] = temporaire;

            // Soluce 2 : (reverse)
            if(isEchec(joueurActif,joueur2,grille) == 1){
                
                printf("##################\n je peux pas je suis en echec si je joue ici !!");
                temporaire = grille[solveur2];
                grille[solveur2] = grille[solveur];
                grille[solveur] = temporaire;
                return 0;
            }
            //printf("\n##### isEchec a retourner 0 apparemment... ###\n");
        }
        else{
            //setPieceEtat(grille[solveur2],0);
            //(*grille[solveur2]) = (*grille[solveur]);
            
            //(*grille[solveur2]) = (*grille[solveur]);
            //deletePieceJoueur(joueur,grille[solveur]);

            //grille[solveur] = creationPieceVide();
            //setPieceEtat(grille[solveur2],0);

            /*

            (*grille[solveur2]).type = (*grille[solveur]).type;
            grille[solveur]->type = '.';
            printf("etat de la piece : %d\n",grille[solveur2]->etat);*/

            Piece *temporaire = grille[solveur2];
            grille[solveur2] = grille[solveur];
            grille[solveur] = temporaire;
            grille[solveur]->type = '.';
            grille[solveur]->etat = 0;

            // Solution 2 (reverse)
            if(isEchec(joueurActif,joueur2,grille) == 1){

                temporaire = grille[solveur2];
                grille[solveur2] = grille[solveur];
                grille[solveur] = temporaire;
                grille[solveur]->type = '.';
                grille[solveur]->etat = 0;
                return 0;
            }

        }
        return 1;
    }
    printf("Quelque chose c'est mal passe, rentrer un coup legale svp \n");
    return 0;
}

int testPositionInitial(Joueur *joueur,char *coord,Piece *grille[]){

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

    if(getPieceType(grille[solveur]) >= 'a' && getPieceType(grille[solveur]) <= 'y' && joueur->couleur == 'n'){
        //printf("Il y a bien une piece noir en %c%c dans la grille \n",coord[0],coord[1]);
        return solveur;
    }
    else if(getPieceType(grille[solveur]) >= 'A' && getPieceType(grille[solveur]) <= 'Y' && joueur->couleur == 'b'){
        //printf("Il y a bien une piece de couleur blanche en %c%c dans la grille\n",coord[0],coord[1]);
        return solveur;
    }
    else
    {
        //printf("Il n'y a pas de piece a cette coordonnee OU vous n'êtes pas autorise à jouer une piece de cette couleur ! \n");
        return 0;
    }

}

int testPositionFinal(char* coord, Piece* grille[]){

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
    else
        return 0;
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
    else
        return 0;

    return solveur;
}

int isPossible(int solveur,int solveur2,Piece *grille[]){
    /*
    printf("je passe bien dans isPossible ! \n");
    printf("solveur = : %d\n",solveur);
    printf("solveur2 = : %d\n",solveur2);
    printf("grille[solveur].type : %c\n",getPieceType(grille[solveur]));
    printf("grille[solveur2].type : %c\n",getPieceType(grille[solveur2]));
    printf("\n le type de ma piece en s1 %s , type s2 : %s\n",getPieceDeplacement(grille[solveur]),getPieceDeplacement(grille[solveur2]));
    */
    if(getPieceDeplacement(grille[solveur]) == "adjacent"){
        if(solveurAdjacent(solveur,solveur2,grille) != 0){
            return 1;
        }
        //printf("solveurAdjacent a retourner 0...\n");
        return 0;
    }

    else if(getPieceDeplacement(grille[solveur]) == "rectiligne"){
        if(solveurLigneDeVueRectiligne(solveur,solveur2,grille) != 0)
            return 1;
        //printf("solveurLDVR a retourner 0....\n");
        return 0;
    }
    else if(getPieceDeplacement(grille[solveur])  == "diagonale"){
        //printf("cette piece se déplace de maniere diagonale ! \n");
        if(solveurLigneDeVueDiagonale(solveur,solveur2,grille) != 0)
            return 1;
        //printf("solveurLDVD a retourner 0....");
        return 0;
    }

    else if(getPieceDeplacement(grille[solveur])  == "rectiligneDiagonale"){
        //printf("cette piece se déplace de maniere rectiligne et diagonale ! \n");
        if(solveurLigneDeVueRectiligneDiagonale(solveur,solveur2,grille) != 0)
            return 1;
        //printf("LDVRD a retourner 0....\n");
        return 0;
    }
    else{
        //printf("Erreur !! (isPossible function) \n");
        return 0;
    }

}

int solveurAdjacent(int solveur,int solveur2,Piece* grille[]){

    //printf("cette piece se déplace de maniere adjacente ! \n");
    // Gestion des erreurs possible au niveau de la premiere et derniere ligne
    if(solveur2 <= 10 && solveur2 >= 90){
        //printf("Erreur ! cette piece ne peut pas se deplacer ici ! \n");
        return 0;
    }
    //printf("solveur : %d\nsolveur2 : %d\n\n",solveur,solveur2);
    // je ne peux me déplacer dans mon index seulement de +-1 ou +-1+-10 ou +-10
    if(solveur2 == solveur+1 || solveur2 == solveur-1 || solveur2 == solveur+10 || solveur2 == solveur-10 || solveur2 == solveur+11 || solveur2 == solveur-11 || solveur2 == solveur-9 || solveur2 == solveur+9){
        //printf("Position pre-autoriser, recherche d'une eventuelle piece allie à cette position \n");
        if(getPieceColor(grille[solveur])  == 'b'){
            // si la lettre est minuscule alors la couleur est noire
            if(!(getPieceType(grille[solveur2])  >= 'A' && getPieceType(grille[solveur2]) <= 'Y')){
                //printf("alors le déplacement est autorisé \n");
                return 1;
            }
        }
        else if(getPieceColor(grille[solveur]) == 'n'){
            // si la lettre est majuscule alors la couleur est blanche
            if(!(getPieceType(grille[solveur2]) >= 'a' && getPieceType(grille[solveur2]) <= 'y')){
                //printf("alors le déplacement est autorisé \n");
                return 1;
            }
        }
    }

    //printf("solveurAdjacent retourne 0 \n");
    return 0;
}

int solveurLigneDeVueRectiligne(int solveur,int solveur2,Piece *grille[]){
    //printf("cette piece se déplace de maniere rectiligne ! (fonction solveurLDVR) \n");
    // je ne peux me déplacer dans mon index seulement si .....
    int calcul = 0 ;
    // cette variable est necessaire ! au cas ou un deplacement diagonale est donne ! 
    int calculR = solveur%10;
    int calculQ = solveur/10;
    //debug
    /*
    printf("solveur = : %d\n",solveur);
    printf("solveur2 = : %d\n",solveur2);
    printf("calculR = : %d\n",calculR);
    printf("calculQ = : %d\n",calculQ);
    */
    // cas normalement impossible grâce a ma validation des coordonnées saisie par les users
    if(solveur2 <= 10 && solveur2 >= 90){
        //printf("Erreur ! cette piece ne peut pas se deplacer ici ! \n");
        return 0;
    }
    //Verif du déplacement horizontale
    if(calculR == 1){
        if(solveur2 == solveur+1 || solveur2 == solveur+2 || solveur2 == solveur+3 || solveur2 == solveur+4 || solveur2 == solveur+5 || solveur2 == solveur+6 || solveur2 == solveur+7){
            //printf("déplacement pre-autorise , checking de la ligne de vue requis (CalculR = 1) \n");
            return ligneDeVueRectiligne(solveur,solveur2,grille);
        }
        else{
            calcul++;
        }
    }
    else if(calculR == 2){
        //printf("je suis bien dans calculR=2 \n");
        if(solveur2 == solveur-1 || solveur2 == solveur+1 || solveur2 == solveur+2 || solveur2 == solveur+3 || solveur2 == solveur+4 || solveur2 == solveur+5 || solveur2 == solveur+6){
            //printf("déplacement pre-autorise , checking de la ligne de vue requis (fonction calculR2)\n");
            return ligneDeVueRectiligne(solveur,solveur2,grille);
        }
        else{
            calcul++;
        }
    }
    else if(calculR == 3){
        if(solveur2 == solveur-2 || solveur2 == solveur-1 || solveur2 == solveur+1 || solveur2 == solveur+2 || solveur2 == solveur+3 || solveur2 == solveur+4 || solveur2 == solveur+5){
            //printf("déplacement pre-autorise , checking de la ligne de vue requis (fonction calculR3)\n");
            return ligneDeVueRectiligne(solveur,solveur2,grille);
        }
        else{
            calcul++;
        }
        //printf("je suis dans calculQ=3 , calcul = %d\n",calcul);
    }
    else if(calculR == 4){
        if(solveur2 == solveur-3 || solveur2 == solveur-2 || solveur2 == solveur-1 || solveur2 == solveur+1 || solveur2 == solveur+2 || solveur2 == solveur+3 || solveur2 == solveur+4){
            //printf("déplacement pre-autorise , checking de la ligne de vue requis (fonction calculR4)\n");
            return ligneDeVueRectiligne(solveur,solveur2,grille);
        }
        else{
            calcul++;
        }
    }
    else if(calculR == 5){
        if(solveur2 == solveur-4 || solveur2 == solveur-3 || solveur2 == solveur-2 || solveur2 == solveur-1 || solveur2 == solveur+1 || solveur2 == solveur+2 || solveur2 == solveur+3){
            //printf("déplacement pre-autorise , checking de la ligne de vue requis (fonction calculR5)\n");
            return ligneDeVueRectiligne(solveur,solveur2,grille);
        }
        else{
            calcul++;
        }
    }
    else if(calculR == 6){
        if(solveur2 == solveur-5 || solveur2 == solveur-4 || solveur2 == solveur-3 || solveur2 == solveur-2 || solveur2 == solveur-1 || solveur2 == solveur+1 || solveur2 == solveur+2){
            //printf("déplacement pre-autorise , checking de la ligne de vue requis (fonction calculR6)\n");
            return ligneDeVueRectiligne(solveur,solveur2,grille);
        }
        else{
            calcul++;
        }
    }
    else if(calculR == 7){
        if(solveur2 == solveur-6 || solveur2 == solveur-5 || solveur2 == solveur-4 || solveur2 == solveur-3 || solveur2 == solveur-2 || solveur2 == solveur-1 || solveur2 == solveur+1){
            //printf("déplacement pre-autorise , checking de la ligne de vue requis (fonction calculR7)\n");
            return ligneDeVueRectiligne(solveur,solveur2,grille);
        }
        else{
            calcul++;
        }
    }
    else if(calculR == 8){
        if(solveur2 == solveur-7 || solveur2 == solveur-6 || solveur2 == solveur-5 || solveur2 == solveur-4 || solveur2 == solveur-3 || solveur2 == solveur-2 || solveur2 == solveur-1){
            //printf("déplacement pre-autorise , checking de la ligne de vue requis (fonction calculR8)\n");
            return ligneDeVueRectiligne(solveur,solveur2,grille);
        }
        else{
            calcul++;
        }
    }
    // Verif du déplacement vertical
    if(calculQ == 1){
        if(solveur2 == solveur+10 || solveur2 == solveur+20 || solveur2 == solveur+30 || solveur2 == solveur+40 || solveur2 == solveur+50 || solveur2 == solveur+60 || solveur2 == solveur+70){
            //printf("deplacement pre-autorise, checking de la ligne de vue requis(fonction CalculQ1 \n");
            return ligneDeVueRectiligneY(solveur,solveur2,grille);
        }
        else{
            calcul++;
        }
    }
    else if(calculQ == 2){
        printf("ah ouais grave bizarre... je passe dans calculQ = 2 .....\n");
        if(solveur2 == solveur-10 || solveur2 == solveur+10 || solveur2 == solveur+20 || solveur2 == solveur+30 || solveur2 == solveur+40 || solveur2 == solveur+50 || solveur2 == solveur+60){
            //printf("déplacement pre-autorise , checking de la ligne de vue requis \n");
            return ligneDeVueRectiligneY(solveur,solveur2,grille);
        }
        else{
            calcul++;
        }
    }
    else if(calculQ == 3){
        if(solveur2 == solveur-20 || solveur2 == solveur-10 || solveur2 == solveur+10 || solveur2 == solveur+20 || solveur2 == solveur+30 || solveur2 == solveur+40 || solveur2 == solveur+50){
            //printf("déplacement pre-autorise , checking de la ligne de vue requis \n");
            return ligneDeVueRectiligneY(solveur,solveur2,grille);
        }
        else{
            calcul++;
        }
    }
    else if(calculQ == 4){
        if(solveur2 == solveur-30 || solveur2 == solveur-20 || solveur2 == solveur-10 || solveur2 == solveur+10 || solveur2 == solveur+20 || solveur2 == solveur+30 || solveur2 == solveur+40){
            //printf("déplacement pre-autorise , checking de la ligne de vue requis \n");
            return ligneDeVueRectiligneY(solveur,solveur2,grille);
        }
        else{
            calcul++;
        }
    }
    else if(calculQ == 5){
        if(solveur2 == solveur-40 || solveur2 == solveur-30 || solveur2 == solveur-20 || solveur2 == solveur-10 || solveur2 == solveur+10 || solveur2 == solveur+20 || solveur2 == solveur+30){
            //printf("déplacement pre-autorise , checking de la ligne de vue requis \n");
            return ligneDeVueRectiligneY(solveur,solveur2,grille);
        }
        else{
            calcul++;
        }
    }
    else if(calculQ == 6){
        if(solveur2 == solveur-50 || solveur2 == solveur-40 || solveur2 == solveur-30 || solveur2 == solveur-20 || solveur2 == solveur-10 || solveur2 == solveur+10 || solveur2 == solveur+20){
            //printf("déplacement pre-autorise , checking de la ligne de vue requis \n");
            return ligneDeVueRectiligneY(solveur,solveur2,grille);
        }
        else{
            calcul++;
        }
    }
    else if(calculQ == 7){
        if(solveur2 == solveur-60 || solveur2 == solveur-50 || solveur2 == solveur-40 || solveur2 == solveur-30 || solveur2 == solveur-20 || solveur2 == solveur-10 || solveur2 == solveur+10){
            //printf("déplacement pre-autorise , checking de la ligne de vue requis \n");
            return ligneDeVueRectiligneY(solveur,solveur2,grille);
        }
        else{
            calcul++;
        }
    }
    else if(calculQ == 8){
        if(solveur2 == solveur-70 || solveur2 == solveur-60 || solveur2 == solveur-50 || solveur2 == solveur-40 || solveur2 == solveur-30 || solveur2 == solveur-20 || solveur2 == solveur-10){
            //printf("déplacement pre-autorise , checking de la ligne de vue requis \n");
            return ligneDeVueRectiligneY(solveur,solveur2,grille);
        }
        else{
            calcul++;
        }
    }
    if(calcul == 2){
        printf("deplaceement non autorise pour ce mouvement rectiligne ! (calcul =2)\n");
        return 0;
    }
    //printf("debug... fin de fonction \n");
}

int solveurLigneDeVueDiagonale(int solveur,int solveur2,Piece *grille[]){
    //printf("passage dans solveur LDV diagonale ! (fonction solveurLDVD) \n");
    int calculR = solveur%10;
    int calculQ = solveur/10;
    int calculR2 = solveur2%10;
    int calculQ2 = solveur2/10;
    //debug
    /*
    printf("solveur = : %d\n",solveur);
    printf("solveur2 = : %d\n",solveur2);
    printf("calculR = : %d\n",calculR);
    printf("calculQ = : %d\n",calculQ);
    */
    if(solveur2 <= 10 && solveur2 >= 90){
        printf("Erreur ! cette piece ne peut pas se deplacer ici ! \n");
        return 0;
    }
    if(solveur2 == solveur+9 || solveur2 == solveur+11 || solveur2 == solveur+18 || solveur2 == solveur+22 || solveur2 == solveur+27 || solveur2 == solveur+33 || solveur2 == solveur+36 || solveur2 == solveur+44 || solveur2 == solveur+45 || solveur2 == solveur+55 || solveur2 == solveur+54 || solveur2 == solveur+66 || solveur2 == solveur+63 || solveur2 == solveur+77 || solveur2 == solveur+72 || solveur2 == solveur+88){
        //printf("deplacement vers l'avant \n");
        return ligneDeVueDiagonalePositive(solveur,solveur2,grille);
    }
    else if(solveur2 == solveur-9 || solveur2 == solveur-11 || solveur2 == solveur-18 || solveur2 == solveur-22 || solveur2 == solveur-27 || solveur2 == solveur-33 || solveur2 == solveur-36 || solveur2 == solveur-44 || solveur2 == solveur-45 || solveur2 == solveur-55 || solveur2 == solveur-54 || solveur2 == solveur-66 || solveur2 == solveur-63 || solveur2 == solveur-77 || solveur2 == solveur-72 || solveur2 == solveur-88){
        //printf("deplacement vers l'arriere \n");
        return ligneDeVueDiagonaleNegative(solveur,solveur2,grille);
    }
    //printf("???? bizarre return 0 solveurLDVD");
    return 0;
}

int solveurLigneDeVueRectiligneDiagonale(int solveur, int solveur2, Piece *grille[]){
    //printf("fonction solveur LDV rectiligne diagonale\n");
    int calcul = 0 ;
    int calculR = solveur%10;
    int calculQ = solveur/10;
    int calculR2 = solveur2%10;
    int calculQ2 = solveur2/10;
    //debug
    /*
    printf("solveur = : %d\n",solveur);
    printf("solveur2 = : %d\n",solveur2);
    printf("calculR = : %d\n",calculR);
    printf("calculQ = : %d\n",calculQ);
    */
    if(solveur2 <= 10 && solveur2 >= 90){
        printf("Erreur ! cette piece ne peut pas se deplacer ici ! \n");
        return 0;
    }
    if(solveur2 == solveur+9 || solveur2 == solveur+11 || solveur2 == solveur+18 || solveur2 == solveur+22 || solveur2 == solveur+27 || solveur2 == solveur+33 || solveur2 == solveur+36 || solveur2 == solveur+44 || solveur2 == solveur+45 || solveur2 == solveur+55 || solveur2 == solveur+54 || solveur2 == solveur+66 || solveur2 == solveur+63 || solveur2 == solveur+77 || solveur2 == solveur+72 || solveur2 == solveur+88){
        //printf("deplacement vers l'avant \n");
        return ligneDeVueDiagonalePositive(solveur,solveur2,grille);
    }
    else if(solveur2 == solveur-9 || solveur2 == solveur-11 || solveur2 == solveur-18 || solveur2 == solveur-22 || solveur2 == solveur-27 || solveur2 == solveur-33 || solveur2 == solveur-36 || solveur2 == solveur-44 || solveur2 == solveur-45 || solveur2 == solveur-55 || solveur2 == solveur-54 || solveur2 == solveur-66 || solveur2 == solveur-63 || solveur2 == solveur-77 || solveur2 == solveur-72 || solveur2 == solveur-88){
        //printf("deplacement vers l'arriere \n");
        return ligneDeVueDiagonaleNegative(solveur,solveur2,grille);
    }
    else{
        //printf("je passe dans le else de SLDVRD\n");
        return solveurLigneDeVueRectiligne(solveur,solveur2,grille);
    }
    //printf("Erreur solveur LDV rectiligne diagonale... return 0...\n");
    return 0;
}

char getReverseCoord(int solveur ,char *nb){

    char carac = 'j';

    if(solveur % 10 == 0 )
        carac = 'j';
    else if(solveur % 10 == 1)
        carac = 'a';
    else if(solveur % 10 == 2)
        carac = 'b';
    else if(solveur % 10 == 3)
        carac = 'c';
    else if(solveur % 10 == 4)
        carac = 'd';
    else if(solveur % 10 == 5)
        carac = 'e';
    else if(solveur % 10 == 6)
        carac = 'f';
    else if(solveur % 10 == 7)
        carac = 'g';
    else if(solveur % 10 == 8)
        carac = 'h';
    
    if(solveur / 10 == 0)
        *nb = '0';
    else if(solveur / 10 == 1)
        *nb = '8';
    else if(solveur / 10 == 2)
        *nb = '7';
    else if(solveur / 10 == 3)
        *nb = '6';
    else if(solveur / 10 == 4)
        *nb = '5';
    else if(solveur / 10 == 5)
        *nb = '4';
    else if(solveur / 10 == 6)
        *nb = '3';
    else if(solveur / 10 == 7)
        *nb = '2';
    else if(solveur / 10 == 8)
        *nb = '1';

    return carac;
}
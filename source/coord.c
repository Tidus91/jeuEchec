int verifCoord(char *userCoord){

    int erreurLettre = 0;
    int erreurChiffre = 0;
    int erreur = 0;

    // je vais faire 2 boucles afin de mieux debugger l'erreur de l'utilisateur

    for(int i=0;i<3;i+=2){
        if(!(userCoord[i] >= 'a' && userCoord[i] <= 'h'))
            erreurLettre++;
    }
    for(int i=1; i<4;i+=2){
        if( !(userCoord[i] >= '1' && userCoord[i] <= '8'))
            erreurChiffre++;
    }
    erreur = erreurLettre+erreurChiffre;

    // Verification abandon
    if(userCoord[0] == 'g' && userCoord[1] == 'g' && userCoord[2] == 'w' && userCoord[3] == 'p')
        return 2;

    if(erreur > 0)
    {
        printf("\nerreur lors de la saisie des coordonnees, Veuillez saisir dans ce type de format uniquement : ---> b3c7 \n\n");
        /*
        if(erreurLettre > 0 && erreurChiffre == 0)
            printf("Vous avez fait %d erreurs de lettre \n",erreurLettre);
        if(erreurChiffre > 0 && erreurLettre == 0 )
            printf("Vous avez fait %d erreurs de chiffre \n",erreurChiffre);
        */
        printf("Veuillez saisir des coordonnees correcte : \n");
        fgets(userCoord,6,stdin);
        erreur = 0;
        verifCoord(userCoord);
    }
    return 1;
}
int verifCoord(char *userCoord){

    int erreurLettre = 0;
    int erreurChiffre = 0;
    int erreur = 0;
    // je vais tester chaque caractère pour voir si j'ai bien : seulement des nombre entre 1 et 8 et des lettres entre a et h
    // finalement je vais faire 2 boucle afin de mieux debugger l'erreur de l'utilisateur
    /*
    for(int i=0;i<4;i++){
        if(!((userCoord[i] >= 'a' && userCoord[i] <= 'h') || (userCoord[i] >= '1' && userCoord[i] <= '8')))
            erreur++;
    }*/
    for(int i=0;i<3;i+=2){
        if(!(userCoord[i] >= 'a' && userCoord[i] <= 'h'))
            erreurLettre++;
    }
    for(int i=1; i<4;i+=2){
        if( !(userCoord[i] >= '1' && userCoord[i] <= '8'))
            erreurChiffre++;
    }
    erreur = erreurLettre+erreurChiffre;
    if(erreur > 0)
    {
        printf("\nerreur lors de la saisie des coordonnees, Veuillez saisir dans ce type de format uniquement : ---> b3c7 \n\n");
        if(erreurLettre > 0 && erreurChiffre == 0)
            printf("Vous avez fait %d erreurs de lettre \n",erreurLettre);
        if(erreurChiffre > 0 && erreurLettre == 0 )
            printf("Vous avez fait %d erreurs de chiffre \n",erreurChiffre);
        printf("Veuillez saisir des coordonnees correcte : \n");
        fgets(userCoord,5,stdin);
        erreur = 0;
        erreur = verifCoord(userCoord);
    }
    return 1;
}
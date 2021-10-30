int ligneDeVueRectiligne(int solveur,int solveur2,Piece *grille[]){
    printf("Rentrer dans function ligneDeVueRectiligne..... \n");
    // Si je me deplace vers la "droite"
    if(solveur2-solveur > 0){
        int i = 1;
        // je recherche le premier obstacle ou alors jusqu'a ce que j'arrive a ma destination
        for(i=1;getPieceType(grille[solveur+i]) == '.' && i < (solveur2 - solveur);i++){

        }
        printf(" mon compteur i : %d \n",i);
        if(getPieceColor(grille[solveur]) == 'b'){
            if(getPieceType(grille[solveur+i]) >= 'A' && getPieceType(grille[solveur+i]) <= 'Y'){
                // Si je rencontre un obstacle AVANT l'endroit ou je voulais me déplacer ET que cette pièce est blanche :
                if(i < (solveur2 - solveur) ){
                    printf("déplacement non autorisé, il y a une piece blanche qui vous appartient qui vous bloque la vue ! \n");
                    return 0;
                }
                // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est blanche : probablement pas possible d'ailleurs
                else if(i > (solveur2 - solveur)){
                    printf("déplacement non autorisé, mais c'est impssible toute facon ! \n");
                    return 0;
                }
                // Si je rencontre AUCUN obstacle a l'endroit ou je voulais me déplacer ET que cette pièce est blanche :
                else if(i == (solveur2 - solveur)){
                    printf("deplacement NON autorise une piece blanche, donc de votre equipe est deja presente à cette emplacement !!! \n ");
                    return 0;
                }
            }
            else if(getPieceType(grille[solveur+i]) >= 'a' && getPieceType(grille[solveur+i]) <= 'y'){

                if(i < (solveur2 - solveur)){
                    printf("deplacement NON autorise, une piece de couleur noir vous bloque l'accès ! \n");
                    return 0;
                }
                else if(i == (solveur2-solveur)){
                printf("deplacement autorise, vous allez manger la piece ! bravo \n");
                return 1;
                }
            }
            else if(getPieceType(grille[solveur+i]) == '.'){
                printf("aucune piece ne gene la ldv , deplacement autorise !");
                return 1;
            }
                /*
                // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est noire : probablement pas possible d'ailleurs
                else if(getPieceType(grille[solveur+i]) != '.'){
                    // alors pas d'obstacle rencontrer
                    printf("deplacement NON autorise, ya un truc bizarre la!");
                    return 0;
                }
                // Si je rencontre AUCUN obstacle a l'endroit ou je voulais me déplacer ET que cette pièce est noire :
                else if(i == (solveur2-solveur)){
                    printf("deplacement autorise, vous allez manger la piece ! bravo \n");
                    return 1;
                }*/
        }
        else if(getPieceColor(grille[solveur]) == 'n'){

            if(getPieceType(grille[solveur+i]) >= 'A' && getPieceType(grille[solveur+i]) <= 'Y'){
                // Si je rencontre un obstacle AVANT l'endroit ou je voulais me déplacer ET que cette pièce est blanche :
                if(i < (solveur2 - solveur) ){
                    printf("déplacement non autorisé, une piece vous bloque l'acces! \n");
                    return 0;
                }
                // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est blanche : probablement pas possible d'ailleurs
                else if(i > (solveur2 - solveur)){
                    printf("déplacement non autorisé, impossible de toute maniere (grace a ma boucle) ! \n");
                    return 0;
                }
                // Si je rencontre AUCUN obstacle a l'endroit ou je voulais me déplacer ET que cette pièce est blanche :
                else if(i == (solveur2 - solveur)){
                    printf("deplacement autorise !!!  vous allez manger la piece ! Bravo !\n ");
                    return 1;
                }
            }
            // Si je rencontre un obstacle AVANT l'endroit ou je voulais me déplacer ET que cette pièce est noire :
            else if(getPieceType(grille[solveur+i]) >= 'a' && getPieceType(grille[solveur+i]) <= 'y'){
                if(i < (solveur2 - solveur)){
                    printf("deplacement NON autorise, une piece vous bloque l'accès ! \n");
                    return 0;
                }
                else if(i == (solveur2 - solveur)){
                    printf("deplacement non autorise, vous ne pouvez pas manger une piece vous appartenant...\n");
                    return 0;
                }    
            }
            else if(getPieceType(grille[solveur+i]) == '.'){
                printf("deplacement autorise, rien ne bloque la LDV \n");
                return 1;
            }
        }
    }
    // probleme d'indentation ligne d'après
    else if(solveur2-solveur < 0){
            int i = -1;
            for(i=-1;getPieceType(grille[solveur+i]) == '.' && i > (solveur2 - solveur);i--){

            }
            printf("mon compteur i : %d \n",i);
            printf("solveur2-solveur = : %d\n",solveur2-solveur);
                if(getPieceColor(grille[solveur]) == 'b'){
                    if(getPieceType(grille[solveur+i]) >= 'A' && getPieceType(grille[solveur+i]) <= 'Y'){
                        printf("j'arrive bien a l'indice %d boucle numero %d \t et j'ai bien le caractere %c \n",solveur+i,i,getPieceType(grille[solveur+i]));
                        if(i > (solveur2 - solveur)){
                            printf("deplacement non autorise, il y a une piece blanche qui vous bloque la vue ! \n");
                            return 0;
                        }
                        else if(i < (solveur2 - solveur)){
                            printf("deplacement non autorise, mais impossible d'arriver dans ce cas de toute maniere.....\n");
                            return 0;
                        }
                        else if(i == (solveur2 - solveur)){
                            printf("deplacement NON autorise, une piece de meme couleur est deja presente ! \n");
                            return 0;
                        }
                    }
                    else if(getPieceType(grille[solveur+i]) >= 'a' && getPieceType(grille[solveur+i]) <= 'y'){
                        if(i > (solveur2 - solveur)){
                            printf("deplacement non autorise, il y a une piece noir qui vous bloque la vue !\n");
                            return 0;
                        }
                        else if(i < (solveur2 - solveur)){
                            printf("deplacement impossible de toute facon.....");
                            return 0;
                        }
                        else if(i == (solveur2-solveur)){
                            printf("Bravo ! vous allez manger la piece blanche ! \n");
                            return 1;
                        }
                    }
                    else if(getPieceType(grille[solveur+i]) == '.'){
                        printf("Aucune piece ne bloque la ligne de vue, autorise !\n");
                        return 1;
                    }
                }
                else if(getPieceColor(grille[solveur]) == 'n'){

                    if(getPieceType(grille[solveur+i]) >= 'A' && getPieceType(grille[solveur+i]) <= 'Y'){
                        //printf("j'arrive bien içi a l'indice ! %d boucle numero : %d \t et j'ai bien le caractere : %c\n",solveur+i,i,grille[solveur+i]);
                        if(i > (solveur2 - solveur) ){
                            printf("déplacement non autorisé, une piece de couleur Blanche vous bloque l'acces! \n");
                            return 0;
                        }
                        // cas impossible grace aux 2 conditions de ma boucle
                        else if(i < (solveur2 - solveur)){
                            printf("déplacement non autorisé, truc vraiment bizarre la ! \n");
                            return 0;
                        }
                        // Si je rencontre AUCUN obstacle a l'endroit ou je voulais me déplacer ET que cette pièce est blanche  :
                        else if(i == (solveur2 - solveur)){
                            printf("deplacement autorise !!!  vous allez manger la piece blanche !\n ");
                            return 1;
                        }
                    }
                    else if(getPieceType(grille[solveur+i]) >= 'a' && getPieceType(grille[solveur+i]) <= 'y'){
                        if(i > (solveur2-solveur)){
                            printf("deplacement non autorise, une piece noir vous bloque la LDV...\n");
                            return 0;
                        }
                        else if(i == (solveur2-solveur)){
                            printf("deplacement non autorisé, vous ne pouvez pas manger une piece de votre propre couleur !");
                            return 0;
                        }
                    }
                    else if(getPieceType(grille[solveur+i]) == '.'){
                        printf("deplacement autorise ! aucune piece de ne gêne et l'emplacement est libre");
                        return 1;
                    }
                }
        }
        // au cas ou.... même si j'ai une fonction qui existe deja en prevention (test position initiale et test finale)
        else{
            printf(" solveur 2 - solveur = 0 ? bizarre.... \n");
        }
}


int ligneDeVueRectiligneY(int solveur,int solveur2,Piece *grille[]){

    printf("Rentrer dans function ligneDeVueRectiligne'YY'..... \n");
    if(solveur2 - solveur > 0){
        int i = 10;
        for (i=10;getPieceType(grille[solveur+i]) == '.' && i < (solveur2 - solveur);i = i+10){

        }
        printf("mon compteur i : %d \n",i);
        if(getPieceColor(grille[solveur]) == 'b'){
            if(getPieceType(grille[solveur+i]) >= 'A' && getPieceType(grille[solveur+i]) <= 'Z'){
                printf(" j'arrive bien ici à l'indice %d, boucle numero : %d et caractere %c \n",solveur+i,i,grille[solveur+i]);
                if(i < (solveur2 - solveur)){
                    printf("deplacement non autorise, il y a une piece blanche qui vous bloque la vue ! \n");
                    return 0;
                }
                else if(i > (solveur2 - solveur)){
                    printf("deplacement NON autorise, bizarre normalement c'est pas possible\n");
                    return 0;
                }
                else if(i == (solveur2 - solveur)){
                    printf("deplacement NON autorise, une piece de même couleur (blanche) est deja presente ! \n");
                    return 0;
                }
            }
            else if(getPieceType(grille[solveur+i]) >= 'a' && getPieceType(grille[solveur+i]) <= 'z'){
                if(i < (solveur2 - solveur)){
                    printf("deplacement non autorise, il y a une piece noire qui vous bloque la vue ! \n");
                    return 0;
                }
                else if(i > (solveur2 - solveur)){
                    printf("deplacement NON autorise, bizarre normalement c'est pas possible\n");
                    return 0;
                }
                else if(i == (solveur2 - solveur)){
                    printf("deplacement autorise, vous allez manger la piece noire! \n");
                    return 1;
                }
            }
            else if(getPieceType(grille[solveur+i]) == '.'){
                printf("deplacement autorise, case libre et aucun pb de LDV \n");
                return 1;
            }
        }
        else if(getPieceColor(grille[solveur]) == 'n'){
            if(getPieceType(grille[solveur+i]) >= 'A' && getPieceType(grille[solveur+i]) <= 'Z'){
                printf("j'arrive bien içi a l'indice ! %d boucle numero : %d \t et j'ai bien le caractere : %c\n",solveur+i,i,grille[solveur+i]);
                if(i < (solveur2 - solveur) ){
                    printf("déplacement non autorisé, une piece blanche vous bloque l'acces! \n");
                    return 0;
                }
                else if(i > (solveur2 - solveur)){
                    printf("déplacement non autorisé, truc bizarre la ! \n");
                    return 0;
                }
                else if(i == (solveur2 - solveur)){
                    printf("deplacement autorise !!!  vous allez manger la piece blanche! !\n ");
                    return 1;
                }
            }
            else if(getPieceType(grille[solveur+i]) >= 'a' && getPieceType(grille[solveur+i]) <= 'z'){
                if(i < (solveur2 - solveur)){
                    printf("deplacement non autorise, il y a une piece noire qui vous bloque la vue ! \n");
                    return 0;
                }
                else if(i > (solveur2 - solveur)){
                    printf("deplacement NON autorise, bizarre normalement c'est pas possible\n");
                    return 0;
                }
                else if(i == (solveur2 - solveur)){
                    printf("deplacement NON autorise, une piece de même couleur (noire) est deja presente ! \n");
                    return 0;
                }
            }
            else if(getPieceType(grille[solveur+i]) == '.'){
                // alors pas d'obstacle rencontrer
                printf("deplacement autorise, case libre et aucun pb de LDV!");
                return 1;
            }
        }
    }
    else if(solveur2 - solveur < 0){
        int i = -10;
        for(i=-10;getPieceType(grille[solveur+i]) == '.' && i > (solveur2 - solveur);i= i-10){

        }
        printf("mon compteur i : %d \n",i);
        // probleme d'indentation ici
            if(getPieceColor(grille[solveur]) == 'b'){
                if(getPieceType(grille[solveur+i]) >= 'A' && getPieceType(grille[solveur+i]) <= 'Z'){
                    printf("j'arrive bien a l'indice %d boucle numero %d \t et j'ai bien le caractere %c \n",solveur+i,i,grille[solveur+i]);
                    if(i > (solveur2 - solveur)){
                        printf("deplacement non autorise, il y a une piece blanche qui vous bloque la vue ! \n");
                        return 0;
                    }
                    else if(i < (solveur2 - solveur)){
                        printf("deplacement non autorise, truc bizarre la ! \n");
                        return 0;
                    }
                    else if(i == (solveur2 - solveur)){
                        printf("deplacement NON autorise, une piece de meme couleur (blanche) qui est deja presente ! \n");
                        return 0;
                    }
                }
                else if(getPieceType(grille[solveur+i]) >= 'a' && getPieceType(grille[solveur+i]) <= 'z'){
                    if(i > (solveur2 - solveur)){
                        printf("deplacement non autorise, il y a une piece noire qui vous bloque la vue ! \n");
                        return 0;
                    }
                    else if(i < (solveur2 - solveur)){
                        printf("deplacement non autorise, truc bizarre la ! \n");
                        return 0;
                    }
                    else if(i == (solveur2 - solveur)){
                        printf("deplacement autorise, la piece noire va etre mange! \n");
                        return 1;
                    }
                }
                else if(getPieceType(grille[solveur+i]) == '.'){
                    printf("deplacement autorise, case libre et aucune piece bloque");
                    return 1;
                }
            }
            else if(getPieceColor(grille[solveur]) == 'n'){

                if(getPieceType(grille[solveur+i]) >= 'A' && getPieceType(grille[solveur+i]) <= 'Z'){
                    printf("j'arrive bien içi a l'indice ! %d boucle numero : %d \t et j'ai bien le caractere : %c\n",solveur+i,i,grille[solveur-i]);
                    if(i > (solveur2 - solveur) ){
                        printf("déplacement non autorisé, une piece blanche bloque l'acces! \n");
                        return 0;
                    }
                    // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est blanche : probablement pas possible d'ailleurs
                    else if(i < (solveur2 - solveur)){
                        printf("déplacement non autorisé, truc bizarre la ! \n");
                        return 0;
                    }
                    // Si je rencontre AUCUN obstacle a l'endroit ou je voulais me déplacer ET que cette pièce est blanche :
                    else if(i == (solveur2 - solveur)){
                        printf("deplacement autorise !!!  vous allez manger la piece blanche!\n ");
                        return 1;
                    }
                }
                // Si je rencontre un obstacle AVANT l'endroit ou je voulais me déplacer ET que cette pièce est noire :
                else if(getPieceType(grille[solveur+i]) >= 'a' && getPieceType(grille[solveur+i]) <= 'z'){
                    if(i > (solveur2 - solveur)){
                        printf("deplacement non autorise, il y a une piece noire qui vous bloque la vue ! \n");
                        return 0;
                    }
                    else if(i < (solveur2 - solveur)){
                        printf("deplacement non autorise, truc bizarre la ! \n");
                        return 0;
                    }
                    else if(i == (solveur2 - solveur)){
                        printf("deplacement NON autorise, une piece de meme couleur (noire) qui est deja presente ! \n");
                        return 0;
                    }
                }
                else if(getPieceType(grille[solveur+i]) == '.'){
                    printf("deplacement autorise, aucun pb de ldvv!");
                    return 1;
                }
    }
}
}

int ligneDeVueDiagonalePositive(int solveur,int solveur2,Piece *grille[]){
    printf("FOnction LDVD positive\n");
    int calculR = solveur%10;
    int calculQ = solveur/10;
    int calculR2 = solveur2%10;
    int calculQ2 = solveur2/10;
    int i = 0;
    // je regarde si ma destination est "côté droite" afin d'appliquer le calcul correspondant (+11)
    if(calculR<calculR2){
        for(i=11;getPieceType(grille[solveur+i]) == '.' && i < (solveur2 - solveur);i = i+11){

        }
        printf("i = %d\n",i);
        if(getPieceColor(grille[solveur]) == 'b'){
            if(getPieceType(grille[solveur+i]) >= 'A' && getPieceType(grille[solveur+i]) <= 'Z'){
                if(i < (solveur2-solveur)){
                    printf("deplacement non autorisé LDVD, une piece blanche vous bloque la LDV! \n");
                    return 0;
                }
                else if(i == (solveur2-solveur)){
                    printf("Vous ne pouvez pas manger une piece qui vous appartient \n");
                    return 0;
                }
            }
            else if(getPieceType(grille[solveur+i]) >= 'a' && getPieceType(grille[solveur+i]) <= 'z'){
                if(i < (solveur2-solveur)){
                    printf("deplacement non autorisé LDVD, une piece noire vous bloque la LDV! \n");
                    return 0;
                }
                else if(i == (solveur2-solveur)){
                    printf("OK, autorise, vous allez manger la piece noir \n");
                    return 1;
                }
            }
            else if(getPieceType(grille[solveur+i]) == '.'){
                printf("aucune piece ne vous bloque, la case est vide, deplacement aurotise\n");
                return 1;
            }
        }
        else if(getPieceColor(grille[solveur]) == 'n'){
            if(getPieceType(grille[solveur+i]) >= 'A' && getPieceType(grille[solveur+i]) <= 'Z'){
                if(i < (solveur2-solveur)){
                    printf("deplacement non autorisé LDVD, une piece blanche vous bloque la LDV! \n");
                    return 0;
                }
                else if(i == (solveur2-solveur)){
                    printf("autorise, vous allez manger la piece blanche \n");
                    return 1;
                }
            }
            else if(getPieceType(grille[solveur+i]) >= 'a' && getPieceType(grille[solveur+i]) <= 'z'){
                if(i < (solveur2-solveur)){
                    printf("deplacement non autorisé LDVD, une piece noire vous bloque la LDV! \n");
                    return 0;
                }
                else if(i == (solveur2-solveur)){
                    printf("non autorise, vous ne pouvez pas manger votre propre piece noire\n");
                    return 0;
                }
            }
            else if(getPieceType(grille[solveur+i]) == '.'){
                printf("aucune piece ne vous bloque, la case est vide, deplacement aurotise\n");
                return 1;
            }
        }
        if(i > (solveur2-solveur)){
            printf("deplacement non autorise, i > s2-s1...\n");
            return 0;
        }
    }
    // côté gauche (+9)
    else if(calculR>calculR2){
        for(i=9;getPieceType(grille[solveur+i]) == '.' && i < (solveur2 - solveur);i = i+9){

        }
        printf("i = %d\n",i);
        if(getPieceColor(grille[solveur]) == 'b'){
            if(getPieceType(grille[solveur+i]) >= 'A' && getPieceType(grille[solveur+i]) <= 'Z'){
                if(i < (solveur2-solveur)){
                    printf("deplacement non autorisé LDVD, une piece blanche vous bloque la LDV! \n");
                    return 0;
                }
                else if(i == (solveur2-solveur)){
                    printf("Vous ne pouvez pas manger une piece qui vous appartient \n");
                    return 0;
                }
            }
            else if(getPieceType(grille[solveur+i]) >= 'a' && getPieceType(grille[solveur+i]) <= 'z'){
                if(i < (solveur2-solveur)){
                    printf("deplacement non autorisé LDVD, une piece noire vous bloque la LDV! \n");
                    return 0;
                }
                else if(i == (solveur2-solveur)){
                    printf("OK, autorise, vous allez manger la piece noir \n");
                    return 1;
                }
            }
            else if(getPieceType(grille[solveur+i]) == '.'){
                printf("aucune piece ne vous bloque, la case est vide, deplacement aurotise\n");
                return 1;
            }
        }
        else if(getPieceColor(grille[solveur]) == 'n'){
            if(getPieceType(grille[solveur+i]) >= 'A' && getPieceType(grille[solveur+i]) <= 'Z'){
                if(i < (solveur2-solveur)){
                    printf("deplacement non autorisé LDVD, une piece blanche vous bloque la LDV! \n");
                    return 0;
                }
                else if(i == (solveur2-solveur)){
                    printf("autorise, vous allez manger la piece blanche \n");
                    return 1;
                }
            }
            else if(getPieceType(grille[solveur+i]) >= 'a' && getPieceType(grille[solveur+i]) <= 'z'){
                if(i < (solveur2-solveur)){
                    printf("deplacement non autorisé LDVD, une piece noire vous bloque la LDV! \n");
                    return 0;
                }
                else if(i == (solveur2-solveur)){
                    printf("non autorise, vous ne pouvez pas manger votre propre piece noire\n");
                    return 0;
                }
            }
            else if(getPieceType(grille[solveur+i]) == '.'){
                printf("aucune piece ne vous bloque, la case est vide, deplacement aurotise\n");
                return 1;
            }
        }
        if(i > (solveur2-solveur)){
            printf("deplacement non autorise, i > s2-s1...\n");
            return 0;
        }
    }
}

int ligneDeVueDiagonaleNegative(int solveur,int solveur2,Piece *grille[]){
    printf("FOnction LDVD negative\n");
    int calculR = solveur%10;
    int calculQ = solveur/10;
    int calculR2 = solveur2%10;
    int calculQ2 = solveur2/10;
    int i = 0;
    // Debug
    printf("calcul R2 = %d\n",solveur2%10);
    // je regarde si ma destination est "côté droite" afin d'appliquer le calcul correspondant (+11)
    if(calculR<calculR2){
        for(i=-9;getPieceType(grille[solveur+i]) == '.' && i > (solveur2 - solveur);i = i-9){

        }
        printf("i = %d\n",i);
        if(getPieceColor(grille[solveur]) == 'b'){
            if(getPieceType(grille[solveur+i]) >= 'A' && getPieceType(grille[solveur+i]) <= 'Z'){
                if(i > (solveur2-solveur)){
                    printf("deplacement non autorisé LDVD, une piece blanche vous bloque la LDV! \n");
                    return 0;
                }
                else if(i == (solveur2-solveur)){
                    printf("Vous ne pouvez pas manger une piece qui vous appartient \n");
                    return 0;
                }
            }
            else if(getPieceType(grille[solveur+i]) >= 'a' && getPieceType(grille[solveur+i]) <= 'z'){
                if(i > (solveur2-solveur)){
                    printf("deplacement non autorisé LDVD, une piece noire vous bloque la LDV! \n");
                    return 0;
                }
                else if(i == (solveur2-solveur)){
                    printf("OK, autorise, vous allez manger la piece noir \n");
                    return 1;
                }
            }
            else if(getPieceType(grille[solveur+i]) == '.'){
                printf("aucune piece ne vous bloque, la case est vide, deplacement aurotise\n");
                return 1;
            }
        }
        else if(getPieceColor(grille[solveur]) == 'n'){
            if(getPieceType(grille[solveur+i]) >= 'A' && getPieceType(grille[solveur+i]) <= 'Z'){
                if(i > (solveur2-solveur)){
                    printf("deplacement non autorisé LDVD, une piece blanche vous bloque la LDV! \n");
                    return 0;
                }
                else if(i == (solveur2-solveur)){
                    printf("autorise, vous allez manger la piece blanche \n");
                    return 1;
                }
            }
            else if(getPieceType(grille[solveur+i]) >= 'a' && getPieceType(grille[solveur+i]) <= 'z'){
                if(i > (solveur2-solveur)){
                    printf("deplacement non autorisé LDVD, une piece noire vous bloque la LDV! \n");
                    return 0;
                }
                else if(i == (solveur2-solveur)){
                    printf("non autorise, vous ne pouvez pas manger votre propre piece noire\n");
                    return 0;
                }
            }
            else if(getPieceType(grille[solveur+i]) == '.'){
                printf("aucune piece ne vous bloque, la case est vide, deplacement aurotise\n");
                return 1;
            }
        }
        if(i < (solveur2-solveur)){
            printf("deplacement non autorise, i < s2-s1...\n");
            return 0;
        }
        
    }
    // côté gauche (+9)
    else if(calculR>calculR2){
        for(i=-11;getPieceType(grille[solveur+i]) == '.' && i > (solveur2 - solveur);i = i-11){

        }
        printf("i = %d\n",i );
        if(getPieceColor(grille[solveur]) == 'b'){
            if(getPieceType(grille[solveur+i]) >= 'A' && getPieceType(grille[solveur+i]) <= 'Z'){
                if(i > (solveur2-solveur)){
                    printf("deplacement non autorisé LDVD, une piece blanche vous bloque la LDV! \n");
                    return 0;
                }
                else if(i == (solveur2-solveur)){
                    printf("Vous ne pouvez pas manger une piece qui vous appartient \n");
                    return 0;
                }
            }
            else if(getPieceType(grille[solveur+i]) >= 'a' && getPieceType(grille[solveur+i]) <= 'z'){
                if(i > (solveur2-solveur)){
                    printf("deplacement non autorisé LDVD, une piece noire vous bloque la LDV! \n");
                    return 0;
                }
                else if(i == (solveur2-solveur)){
                    printf("OK, autorise, vous allez manger la piece noir \n");
                    return 1;
                }
            }
            else if(getPieceType(grille[solveur+i]) == '.'){
                printf("aucune piece ne vous bloque, la case est vide, deplacement aurotise\n");
                return 1;
            }
        }
        else if(getPieceColor(grille[solveur]) == 'n'){
            if(getPieceType(grille[solveur+i]) >= 'A' && getPieceType(grille[solveur+i]) <= 'Z'){
                if(i > (solveur2-solveur)){
                    printf("deplacement non autorisé LDVD, une piece blanche vous bloque la LDV! \n");
                    return 0;
                }
                else if(i == (solveur2-solveur)){
                    printf("autorise, vous allez manger la piece blanche \n");
                    return 1;
                }
            }
            else if(getPieceType(grille[solveur+i]) >= 'a' && getPieceType(grille[solveur+i]) <= 'z'){
                if(i > (solveur2-solveur)){
                    printf("deplacement non autorisé LDVD, une piece noire vous bloque la LDV! \n");
                    return 0;
                }
                else if(i == (solveur2-solveur)){
                    printf("non autorise, vous ne pouvez pas manger votre propre piece noire\n");
                    return 0;
                }
            }
            else if(getPieceType(grille[solveur+i]) == '.'){
                printf("aucune piece ne vous bloque, la case est vide, deplacement aurotise\n");
                return 1;
            }
        }
        if(i < (solveur2-solveur)){
            printf("deplacement non autorise, i < s2-s1...\n");
            return 0;
        }
    }

}
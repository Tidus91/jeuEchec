int ligneDeVueRectiligne(int solveur,int solveur2,Piece *grille){
        printf("Rentrer dans function ligneDeVueRectiligne..... \n");
        if(solveur2-solveur > 0){
            int i = 1;
            for(i=1;grille[solveur+i].typep.roi.nom == '.' && i < (solveur2 - solveur);i++){
    
            }
            printf(" mon compteur i : %d \n",i);
            if(grille[solveur].couleur == 'b'){
                if(grille[solveur+i].typep.roi.nom >= 'A' && grille[solveur+i].typep.roi.nom <= 'Z'){
                    // Si je rencontre un obstacle AVANT l'endroit ou je voulais me déplacer ET que cette pièce est blanche :
                    printf("j'arrive bien içi a l'indice ! %d boucle numero : %d \t et j'ai bien le caractere : %c\n",solveur+i,i,grille[solveur+i]);
                    if(i < (solveur2 - solveur) ){
                        printf("déplacement non autorisé, il y a une pièce qui vous bloque la vue ! \n");
                        return 0;
                    }
                    // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est blanche : probablement pas possible d'ailleurs
                    else if(i > (solveur2 - solveur)){
                        printf("déplacement non autorisé, truc bizarre la ! \n");
                        return 0;
                    }
                    // Si je rencontre AUCUN obstacle a l'endroit ou je voulais me déplacer ET que cette pièce est blanche :
                    else if(i == (solveur2 - solveur)){
                        printf("deplacement NON autorise une piece de même couleur est deja presente !!! \n ");
                        return 0;
                    }
                }
                // Si je rencontre un obstacle AVANT l'endroit ou je voulais me déplacer ET que cette pièce est noire :
                else if(grille[solveur+i].typep.roi.nom >= 'a' && grille[solveur+i].typep.roi.nom <= 'z'){
                    printf("deplacement NON autorise, une piece vous bloque l'accès ! \n");
                    return 0;
                }
                // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est noire : probablement pas possible d'ailleurs
                else if(grille[solveur+i].typep.roi.nom != '.'){
                    // alors pas d'obstacle rencontrer
                    printf("deplacement NON autorise, ya un truc bizarre la!");
                    return 0;
                }
                // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est noire :
                else if(i == (solveur2-solveur)){
                    printf("deplacement autorise, vous allez manger la piece ! bravo \n");
                    return 1;
                }
            }
            else if(grille[solveur].couleur == 'n'){

                if(grille[solveur+i].typep.roi.nom >= 'A' && grille[solveur+i].typep.roi.nom <= 'Z'){
                    // Si je rencontre un obstacle AVANT l'endroit ou je voulais me déplacer ET que cette pièce est blanche :
                    printf("j'arrive bien içi a l'indice ! %d boucle numero : %d \t et j'ai bien le caractere : %c\n",solveur+i,i,grille[solveur+i]);
                    if(i < (solveur2 - solveur) ){
                        printf("déplacement non autorisé, une piece vous bloque l'acces! \n");
                        return 0;
                    }
                    // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est blanche : probablement pas possible d'ailleurs
                    else if(i > (solveur2 - solveur)){
                        printf("déplacement non autorisé, truc bizarre la ! \n");
                        return 0;
                    }
                    // Si je rencontre AUCUN obstacle a l'endroit ou je voulais me déplacer ET que cette pièce est blanche :
                    else if(i == (solveur2 - solveur)){
                        printf("deplacement autorise !!!  vous allez manger la piece ! Bravo !\n ");
                        return 1;
                    }
                }
                // Si je rencontre un obstacle AVANT l'endroit ou je voulais me déplacer ET que cette pièce est noire :
                else if(grille[solveur+i].typep.roi.nom >= 'a' && grille[solveur+i].typep.roi.nom <= 'z'){
                    printf("deplacement NON autorise, une piece vous bloque l'accès ! \n");
                    return 0;
                }
                // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est noire : probablement pas possible d'ailleurs
                else if(grille[solveur+i].typep.roi.nom != '.'){
                    // alors pas d'obstacle rencontrer
                    printf("deplacement NON autorise, ya un truc bizarre la!");
                    return 0;
                }
                // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est noire :
                else if(i == (solveur2-solveur)){
                    printf("deplacement NON autorise, une piece de meme couleur est deja presente \n");
                    return 0;
                }
            }
        }
        else if(solveur2-solveur < 0){
            int i = -1;
            for(i=-1;grille[solveur+i].typep.roi.nom == '.' && i > (solveur2 - solveur);i--){

            }
            printf("mon compteur i : %d \n",i);
                if(grille[solveur].couleur == 'b'){
                    if(grille[solveur+i].typep.roi.nom >= 'A' && grille[solveur+i].typep.roi.nom <= 'Z'){
                        printf("j'arrive bien a l'indice %d boucle numero %d \t et j'ai bien le caractere %c \n",solveur+i,i,grille[solveur+i]);
                        if(i > (solveur2 = solveur)){
                            printf("deplacement non autorise, il y a une piece qui vous bloque la vue ! \n");
                            return 0;
                        }
                        else if(i < (solveur2 - solveur)){
                            printf("deplacement non autorise, truc bizarre la ! \n");
                            return 0;
                        }
                        else if(i == (solveur2 - solveur)){
                            printf("deplacement NON autorise, une piece de meme couleur est deja presente ! \n");
                            return 0;
                        }
                    }
                    else if(grille[solveur-i].typep.roi.nom >= 'a' && grille[solveur-i].typep.roi.nom <= 'z'){
                        printf("deplacement NON autorise, une piece vous bloque l'accès ! \n");
                        return 0;
                    }
                    // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est noire : probablement pas possible d'ailleurs
                    else if(grille[solveur+i].typep.roi.nom != '.'){
                        // alors pas d'obstacle rencontrer
                        printf("deplacement NON autorise, ya un truc bizarre la!");
                        return 0;
                    }
                    // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est noire :
                    else if(i == (solveur2-solveur)){
                        printf("deplacement autorise, vous allez manger la piece ! bravo \n");
                        return 1;
                    }
                }
                else if(grille[solveur].couleur == 'n'){

                    if(grille[solveur+i].typep.roi.nom >= 'A' && grille[solveur+i].typep.roi.nom <= 'Z'){
                        // Si je rencontre un obstacle AVANT l'endroit ou je voulais me déplacer ET que cette pièce est blanche :
                        printf("j'arrive bien içi a l'indice ! %d boucle numero : %d \t et j'ai bien le caractere : %c\n",solveur+i,i,grille[solveur-i]);
                        if(i < (solveur2 - solveur) ){
                            printf("déplacement non autorisé, une piece vous bloque l'acces! \n");
                            return 0;
                        }
                        // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est blanche : probablement pas possible d'ailleurs
                        else if(i > (solveur2 - solveur)){
                            printf("déplacement non autorisé, truc bizarre la ! \n");
                            return 0;
                        }
                        // Si je rencontre AUCUN obstacle a l'endroit ou je voulais me déplacer ET que cette pièce est blanche :
                        else if(i == (solveur2 - solveur)){
                            printf("deplacement autorise !!!  vous allez manger la piece ! Bravo !\n ");
                            return 1;
                        }
                    }
                    // Si je rencontre un obstacle AVANT l'endroit ou je voulais me déplacer ET que cette pièce est noire :
                    else if(grille[solveur+i].typep.roi.nom >= 'a' && grille[solveur+i].typep.roi.nom <= 'z'){
                        printf("deplacement NON autorise, une piece vous bloque l'accès ! \n");
                        return 0;
                    }
                    // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est noire : probablement pas possible d'ailleurs
                    else if(grille[solveur+i].typep.roi.nom != '.'){
                        // alors pas d'obstacle rencontrer
                        printf("deplacement NON autorise, ya un truc bizarre la!");
                        return 0;
                    }
                    // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est noire :
                    else if(i == (solveur2-solveur)){
                        printf("deplacement NON autorise, une piece de meme couleur est deja presente \n");
                        return 0;
                    }
                }
        }
        // au cas ou.... même si j'ai une fonction qui existe deja en prevention (test position initiale et test finale)
        else{
            printf(" solveur 2 - solveur = 0 ? bizarre.... \n");
        }
        return ligneDeVueRectiligneY(solveur,solveur2,grille);
}


int ligneDeVueRectiligneY(int solveur,int solveur2,Piece *grille){

    printf("deplacement pre-autorise, checking de la ligne de vue requis(fonction LDVRY ! \n");
    if(solveur2 - solveur > 0){
        int i = 10;
        for (i=10;grille[solveur+i].typep.roi.nom == '.' && i < (solveur2 - solveur);i = i+10){

        }
        printf("mon compteur i : %d \n",i);
        if(grille[solveur].couleur == 'b'){
            if(grille[solveur+i].typep.roi.nom >= 'A' && grille[solveur+i].typep.roi.nom <= 'Z'){
                printf(" j'arrive bien ici à l'indice %d, boucle numero : %d et caractere %c \n",solveur+i,i,grille[solveur+i]);
                if(i < (solveur2 - solveur)){
                    printf("deplacement non autorise, il y a une piece qui vous bloque la vue ! \n");
                    return 0;
                }
                else if(i > (solveur2 - solveur)){
                    printf("deplacement NON autorise, bizarre normalement c'est pas possible\n");
                    return 0;
                }
                else if(i == (solveur2 - solveur)){
                    printf("deplacement NON autorise, une piece de même couleur est deja presente ! \n");
                    return 0;
                }
            }
            else if(grille[solveur+i].typep.roi.nom >= 'a' && grille[solveur+i].typep.roi.nom <= 'z'){
                printf("deplacement NON autorise, une piece vous bloque la ligne de vue");
                return 0;
            }
            else if(grille[solveur+i].typep.roi.nom != '.'){
                printf("deplacement NON autorise, truc bizarre la ");
                return 0;
            }
            else if(i == (solveur2-solveur)){
                printf("deplacement autorise, vous allez manger la piece, bravo !\n");
                return 1;
            }
        }
        else if(grille[solveur].couleur == 'n'){
            if(grille[solveur+i].typep.roi.nom >= 'A' && grille[solveur+i].typep.roi.nom <= 'Z'){
                printf("j'arrive bien içi a l'indice ! %d boucle numero : %d \t et j'ai bien le caractere : %c\n",solveur+i,i,grille[solveur+i]);
                if(i < (solveur2 - solveur) ){
                    printf("déplacement non autorisé, une piece vous bloque l'acces! \n");
                    return 0;
                }
                // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est blanche : probablement pas possible d'ailleurs
                else if(i > (solveur2 - solveur)){
                    printf("déplacement non autorisé, truc bizarre la ! \n");
                    return 0;
                }
                // Si je rencontre AUCUN obstacle a l'endroit ou je voulais me déplacer ET que cette pièce est blanche :
                else if(i == (solveur2 - solveur)){
                    printf("deplacement autorise !!!  vous allez manger la piece ! Bravo !\n ");
                    return 1;
                }
            }
            else if(grille[solveur+i].typep.roi.nom >= 'a' && grille[solveur+i].typep.roi.nom <= 'z'){
                printf("deplacement NON autorise, une piece vous bloque l'accès ! \n");
                return 0;
            }
            // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est noire : probablement pas possible d'ailleurs
            else if(grille[solveur+i].typep.roi.nom != '.'){
                // alors pas d'obstacle rencontrer
                printf("deplacement NON autorise, ya un truc bizarre la!");
                return 0;
            }
            // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est noire :
            else if(i == (solveur2-solveur)){
                printf("deplacement NON autorise, une piece de meme couleur est deja presente \n");
                return 0;
            }
        }
    }
    else if(solveur2 - solveur < 0){
        int i = -10;
        for(i=-10;grille[solveur+i].typep.roi.nom == '.' && i > (solveur2 - solveur);i= i-10){

        }
        printf("mon compteur i : %d \n",i);
            if(grille[solveur].couleur == 'b'){
                if(grille[solveur+i].typep.roi.nom >= 'A' && grille[solveur+i].typep.roi.nom <= 'Z'){
                    printf("j'arrive bien a l'indice %d boucle numero %d \t et j'ai bien le caractere %c \n",solveur+i,i,grille[solveur+i]);
                    if(i > (solveur2 = solveur)){
                        printf("deplacement non autorise, il y a une piece qui vous bloque la vue ! \n");
                        return 0;
                    }
                    else if(i < (solveur2 - solveur)){
                        printf("deplacement non autorise, truc bizarre la ! \n");
                        return 0;
                    }
                    else if(i == (solveur2 - solveur)){
                        printf("deplacement NON autorise, une piece de meme couleur est deja presente ! \n");
                        return 0;
                    }
                }
                else if(grille[solveur-i].typep.roi.nom >= 'a' && grille[solveur-i].typep.roi.nom <= 'z'){
                    printf("deplacement NON autorise, une piece vous bloque l'accès ! \n");
                    return 0;
                }
                // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est noire : probablement pas possible d'ailleurs
                else if(grille[solveur+i].typep.roi.nom != '.'){
                    // alors pas d'obstacle rencontrer
                    printf("deplacement NON autorise, ya un truc bizarre la!");
                    return 0;
                }
                // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est noire :
                else if(i == (solveur2-solveur)){
                    printf("deplacement autorise, vous allez manger la piece ! bravo \n");
                    return 1;
                }
            }
            else if(grille[solveur].couleur == 'n'){

                if(grille[solveur+i].typep.roi.nom >= 'A' && grille[solveur+i].typep.roi.nom <= 'Z'){
                    // Si je rencontre un obstacle AVANT l'endroit ou je voulais me déplacer ET que cette pièce est blanche :
                    printf("j'arrive bien içi a l'indice ! %d boucle numero : %d \t et j'ai bien le caractere : %c\n",solveur+i,i,grille[solveur-i]);
                    if(i < (solveur2 - solveur) ){
                        printf("déplacement non autorisé, une piece vous bloque l'acces! \n");
                        return 0;
                    }
                    // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est blanche : probablement pas possible d'ailleurs
                    else if(i > (solveur2 - solveur)){
                        printf("déplacement non autorisé, truc bizarre la ! \n");
                        return 0;
                    }
                    // Si je rencontre AUCUN obstacle a l'endroit ou je voulais me déplacer ET que cette pièce est blanche :
                    else if(i == (solveur2 - solveur)){
                        printf("deplacement autorise !!!  vous allez manger la piece ! Bravo !\n ");
                        return 1;
                    }
                }
                // Si je rencontre un obstacle AVANT l'endroit ou je voulais me déplacer ET que cette pièce est noire :
                else if(grille[solveur+i].typep.roi.nom >= 'a' && grille[solveur+i].typep.roi.nom <= 'z'){
                    printf("deplacement NON autorise, une piece vous bloque l'accès ! \n");
                    return 0;
                }
                // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est noire : probablement pas possible d'ailleurs
                else if(grille[solveur+i].typep.roi.nom != '.'){
                    // alors pas d'obstacle rencontrer
                    printf("deplacement NON autorise, ya un truc bizarre la!");
                    return 0;
                }
                // Si je rencontre un obstacle APRES l'endroit ou je voulais me déplacer ET que cette pièce est noire :
                else if(i == (solveur2-solveur)){
                    printf("deplacement NON autorise, une piece de meme couleur est deja presente \n");
                    return 0;
                }
    }
}
}
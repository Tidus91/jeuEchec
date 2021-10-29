int getWhiteKing(Piece *grille){
    for(int i=0;i<100;i++){
        if(grille[i].type == 'r')
            return i;
    }
}
int getBlackKing(Piece *grille){
    for(int i=0;i<100;i++){
        if(grille[i].type == 'R')
            return i;
    }
}
/*
int isEchec(Joueur *joueurAdverse,int king,Piece *grille){
    if(grille[solveur2].typep.roi.deplacement == "adjacent"){
        if(grille[solveur2].couleur == 'n'){
            int king = getWhiteKing(grille);
            if(solveur2 == king+1 || solveur2 == king-1 || solveur2 == king+10 || solveur2 == king-10 || solveur2 == king+11 || solveur2 == king-11 || solveur2 == king+9 || solveur2 == king-9){
                printf(" !!! ATTENTION !!!   Le roi Blanc est en echec ! \n\n");
                return 1;
            }
            else
                return 0;
        }
        else if(grille[solveur2].couleur == 'b'){
            int king = getBlackKing(grille);
            if(solveur2 == king+1 || solveur2 == king-1 || solveur2 == king+10 || solveur2 == king-10 || solveur2 == king+11 || solveur2 == king-11 || solveur2 == king+9 || solveur2 == king-9){
                printf(" !!! ATTENTION !!!   Le roi Noir est en echec ! \n\n");
                return 1;
            }
            else
                return 0;
        }
    }
    if(grille[solveur2].typep.roi.deplacement == "rectiligne"){
        printf("COUCOU JE SUIS DANS ISECHEC RECTILIGNE !! \n");
        if(grille[solveur2].couleur == 'n'){
            int king = getWhiteKing(grille);
            if(solveur2 - king > 0){
                int i = 1;
                for(i=1;grille[solveur2+i].type == '.';i++){

                }
                if(grille[solveur2+i].type == 'R'){
                    printf("!!! ATTENTION !!! Le roi Blanc est en echec !! \n\n");
                    return 1;
                }
                else
                    return 0;
            }
            else if(solveur2 - king < 0){
                int i = -1;
                for(i=-1;grille[solveur2+i].type == '.';i--){
                    
                }
                if(grille[solveur2+i].type == 'R'){
                    printf("!!! ATTENTION !!! Le roi Blanc est en echec !! \n\n");
                    return 1;
                }
                else
                    return 0;
            }
        }
        else if(grille[solveur2].couleur == 'b'){
            int king = getBlackKing(grille);
            if(solveur2 - king > 0){
                int i = 1;
                for(i=1;grille[solveur2+i].type == '.';i++){

                }
                if(grille[solveur2+i].type == 'r'){
                    printf("!!! ATTENTION !!! Le roi Noir est en echec !! \n\n");
                    return 1;
                }
                else 
                    return 0;
            }
            else if(solveur2 - king < 0){
                int i = -1;
                for(i=-1;grille[solveur2+i].type == '.';i--){
                    
                }
                if(grille[solveur2+i].type == 'r'){
                    printf("!!! ATTENTION !!! Le roi Noir est en echec !! \n\n");
                    return 1;
                }
                else 
                    return 0;
            }
        }
}
}*/
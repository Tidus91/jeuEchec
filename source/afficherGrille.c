void afficherGrille(Piece *grille[]){

    char ligne[10] = {' ','a','b','c','d','e','f','g','h',' '};
    char colonne[10] = {' ','8','7','6','5','4','3','2','1',' '};
    // j'affiche ma grille :
    for(int i=0;i<100;i++){
        //toutes les 10 cases
        if(i%10 == 0){
            // ce bout de code fonctionne en parallèle avec le "else" afin d'afficher les lettres en bout de "ligne"
            //grille[i+9]=colonne[i/10];
            (*grille[i+9]).type = colonne[i/10];
            (*grille[i]).type = colonne[i/10];
            // je fait un retour chariot et j'affiche mon chiffre
            printf("\n");
            // pour supprimer le "--- --- ---..." en trop du début
            if(i>=10)
                printf("   --- --- --- --- --- --- --- ---\n");
            printf("%c ",colonne[i/10]);
        }
        // pour ma première ligne j'affiche mes lettres
        else if(i < 10){
            //j'initialise a Z les bordures (cela servira plus tard pour le checking des deplacements des pieces)
            (*grille[i]).type = 'Z';
            printf("  %c ",ligne[i]);
        }
        // pour ma dernière ligne j'affiche mes lettres
        else if(i > 90){
            (*grille[i]).type = 'Z';
            printf("  %c ",ligne[i%10]);
        }
        //printf("| %c ",(*grille[i]).type);
        // je n'affiche que mes pieces existante (au lieu des '.')
        else {
            printf("| ",(*grille[i]).type);
            //2eme condition pour afficher mes numeros qui n'ont pas l'état à 1
            if(grille[i]->etat == 1 || (grille[i]->type >= '1' && grille[i]->type <= '8'))
                printf("%c",(*grille[i]).type);
            else
                printf(" ");
            printf(" ",(*grille[i]).type);
        }   
    }
    printf("\n\n grille veritable : \n");
        for(int y =0;y<100;y++){
            if(y%10 == 0)
                printf("\n");
            printf("%c ",(*grille[y]).type);
        }
}
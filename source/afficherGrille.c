void afficherGrille(Piece *grille){

    char ligne[10] = {' ','a','b','c','d','e','f','g','h',' '};
    char colonne[10] = {' ','8','7','6','5','4','3','2','1',' '};
    // j'affiche ma grille :
    for(int i=0;i<100;i++){
        //toutes les 10 cases
        if(i%10 == 0){
            // ce bout de code fonctionne en parallèle avec le "else" afin d'afficher les lettres en bout de "ligne"
            //grille[i+9]=colonne[i/10];
            grille[i+9].typep.roi.nom = colonne[i/10];
            // je fait un retour chariot et j'affiche mon chiffre
            printf("\n");
            // pour supprimer le "--- --- ---..." en trop du début
            if(i>=10)
                printf("   --- --- --- --- --- --- --- ---\n");
            printf("%c ",colonne[i/10]);
        }
        // pour ma première ligne j'affiche mes lettres
        else if(i < 10){
            printf("  %c ",ligne[i]);
        }
        // pour ma dernière ligne j'affiche mes lettres
        else if(i > 90){
            printf("  %c ",ligne[i%10]);
        }
        else {
            printf("| %c ",grille[i].typep.roi.nom);
        }
              
    }
}
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// 1 - creer une fonction qui prend la variable solution, et la variable tableauJoueur (par exemple) : un tableau rempli de 0, cette fonction doit copier certaines valeurs (grace au rand() % N) 
// de solution dans tableauJoueur afin d'initialiser une grille jouable ( car solution est bel est bien la solution, donc pas jouable par définition. ).
// un parametre doit permettre de verifier la condition de victoire en un seul coup (proposer votre façon de faire :) ) 
void copyArray(int tab[8][8], int copy[8][8] ){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            copy[i][j] = tab[i][j];
        }
    }
}



void afficher(int tab[8][8]){
    printf("I\\J");

    for(int i = 0; i <2; i++){
        printf("| %d ", i);

    }
        printf("|\n");

    for(int i = 0; i < 2; i++){
        printf("----");
    
}
    for(int i = 0; i < 8; i++){
        printf("\n");
        printf("| %d >  ", i);
        for(int j = 0; j < 8; j++){
            printf("| %d ", tab[i][j]);
        }
        printf("|\n");
    }
        printf("\n");

}

int verifierGrille(int tab[8][8]){

    int isCorrect =1;
    for(int i = 0; i < 2; i++ ){
    int verifLigne = verifierLigneColonne(tab, i, 1);
    int verifCol = verifierLigneColonne(tab, i, 0);
    if(verifCol || verifLigne){
        printf("\n\nAhrf, il semblerait que votre solution ne corresponde pas aux regles, reessayez !\n\n");
        isCorrect = 0;
  
    return isCorrect;
    }
}
}




// 2- une fonction saisir qui demande au joueur de saisir 3 informations: i, j , et v qui permettront de placer la valeur v aux coordonnées (i,j)

int saisir(int tab[8][8]){
    int result = 0;
    while (result == 0)
{   
    int tableauTest[8][8] = {
        {0,0,0,0, 0,0,0,0},
        {0,0,0,0, 0,0,0,0},
        {0,0,0,0, 0,0,0,0},
        {0,0,0,0, 0,0,0,0},
    
        {0,0,0,0, 0,0,0,0},
        {0,0,0,0, 0,0,0,0},
        {0,0,0,0, 0,0,0,0},
        {0,0,0,0, 0,0,0,0}
    };
    copyArray(tab, tableauTest);
    int saisie = 0;
        printf("Veuillez saisir un I\n");
        scanf("%d", &saisie);
        int saisieI = saisie;
        printf("Veuillez saisir un J\n");
        scanf("%d", &saisie);
        int saisieJ = saisie;
        

        if(tab[saisieI][saisieJ]){
            printf("Cette case est deja remplie Reessayez\n");
        } else {
            printf("Quelle valeur(V) souhaitez vous inserer ?\n");
            scanf("%d", &saisie);
            int saisieVal = saisie;
            tableauTest[saisieJ][saisieI] = saisieVal;
        
            result = verifierGrille(tableauTest);
            if(result == 1 ){
                tab[saisieJ][saisieI] = saisieVal;
            }
        }
    }
    return result;
} 



     




// 3- apres chaque coordonnées il faut verifier les regles du takuzu sur le tableauJoueur donc : 

    // - la fonction verifierLigneColonne ( qui verifie les lignes et les colonnes  sur lesquelles sont la nouvelle valeur)
    // - la fonction verifierGrille (qui fait ceci pour toute la grille et permet de definir la condition de victoire)
int verifierLigneColonne(int tab[8][8], int ligne, int ligneOrCol ){

    int choices[8] = {0,0,0,0,  0,0,0,0};
    int result = 0;
    if(ligneOrCol){
        for(int i = 0; i < 2; i++){
            int numero = tab[i][ligne];
            if(tab[i][ligne] > 0){
                int numero = tab[i][ligne];
                // printf( "\n\n NUM %d", numero -1 );
                choices[numero - 1] = choices[numero- 1] + 1 ;
            }
        }
    } else {
        for(int i = 0; i < 2; i++){
            if(tab[ligne][i]){
                int numero = tab[ligne][i];
                choices[numero - 1] = choices[numero- 1] + 1 ;
            }
        }
    }
    for(int i = 0; i < 2; i++){
        if(choices[i] > 1){
            result = 1; 
        } 
    }
return result;
}



// 4 - Ecrire le code principal qui permet de jouer au joueur :  le programme prend fin quand on gagne 

int main(){
    // Ne pas toucher le code entre les commentaires
    srand( time( NULL ) );


    int i, j, k;
    printf("SOLUTION");  
    printf("\n");  
    printf("---------------------------------");  
    printf("\n");  

    int solution[8][8] = {
        {1,1,0,1, 0,1,0,0},
        {0,0,1,0, 1,0,1,1},
        {0,1,0,0, 1,1,0,1},
        {1,0,1,1, 0,0,1,0},
    
        {1,0,1,0, 0,1,1,0},
        {0,1,0,1, 1,0,0,1},
        {1,1,0,0, 1,0,1,0},
        {0,0,1,1, 0,1,0,1}
    };


    for(i=0;i<8; ++i) 
    {
    for(j=0; j<8; ++j)
        printf("%d ", solution[i][j]);
    printf("\n");  
    }
    printf("---------------------------------");  
    printf("\n");  
    //toucher le code entre les commentaires 
     int tableauJoueur[8][8] = {
        {0,0,0,0, 0,0,0,0},
        {0,0,0,0, 0,0,0,0},
        {0,0,0,0, 0,0,0,0},
        {0,0,0,0, 0,0,0,0},
    
        {0,0,0,0, 0,0,0,0},
        {0,0,0,0, 0,0,0,0},
        {0,0,0,0, 0,0,0,0},
        {0,0,0,0, 0,0,0,0}
    };
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            printf("%d ", tableauJoueur[i][j]);
        }
        printf("\n");
    }
    int isTurning = 0;
    
    do{
        afficher(tableauJoueur);
        saisir(tableauJoueur);
        isTurning = verifierGrille(tableauJoueur);
    }while(isTurning);
    
    printf("Bravo, vous avez reussi l'epreuve du takuzu");


    //Ne pas toucher au code ci dessous
    system("pause");
    return 0;
}
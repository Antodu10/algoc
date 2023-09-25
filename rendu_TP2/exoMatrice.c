#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> 

typedef struct {
    uint16_t nbLignes;
    uint16_t nbColonnes;
    int ** valeurs;
} Matrice;

Matrice*  creer(int16_t valeur, int16_t nbLig, int16_t nbCol){
    Matrice* A = (Matrice *) malloc(sizeof(Matrice));
    A->nbLignes=nbLig;
    A->nbColonnes=nbCol;
    A->valeurs = (int **)malloc(sizeof(int*)*nbCol);
    for(int i=0;i<nbCol;i++){
        A->valeurs[i]=(int*)malloc(sizeof(int*)*nbLig);
        for(int j=0;j<nbLig;j++){
           A->valeurs[i][j]=valeur;
        }
    }
    
    return A;
    }
   
    










int main(void){
 
    return 0;}


/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring

 Tests
 diff out.csv turingWinners.csv

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
//tableau avec chaques cases est une struct à 3 champs

typedef struct{
	int annee;
	char * nom;
	char * nature;
}Winner;

void deplacerCurseur(FILE* f, int num_winner, int partie){
	rewind(f); //on repart de 0
	int num_winner_actif=1;
	int partie_active =1;
	char character = ' ';
//on se déplace au bon winner
	while(num_winner_actif!=num_winner){
		if((character=fgetc(f))=='\n'){
			num_winner_actif++;
		}
	}
//on se déplace au bon caractère
	while(partie_active!=partie){
		if((character=fgetc(f))==';'){
			partie_active++;
		}
	}
//le curseur est placé sur la virgule juste avant l'info souhaité	

}

int numberOfWinners(FILE * fichier){
	char character;
	int counter;
	counter =0;
	while((character=fgetc(fichier))!=EOF){
		if(character=='\n'){
			counter=counter+1;}
		}
		fclose(fichier);
		return counter;
}

int compterTaille(FILE* f, int num_winner, int partie){
	deplacerCurseur(f,num_winner,partie);
	int compteur = 0;
	char character = ' ';
	while(character!=EOF&&character!=';'&&character!='\n'){
		compteur++;
		character=fgetc(f);
	}
	return compteur;
}

void creer_winner(Winner ** tableau_winner, FILE* f,int i){
		tableau_winner[i]= malloc(sizeof(Winner));
		int taille_nom= compterTaille(f,i,2);
		int taille_nature= compterTaille(f,i,3);
		//on créer de la mémoire
		tableau_winner[i]->nom=calloc(taille_nom+1,sizeof(char));
		tableau_winner[i]->nature=calloc(taille_nature+1,sizeof(char));
		deplacerCurseur(f,i,1); 
		//on replace le curseur
		fscanf(f,"%d",&(tableau_winner[i]->annee));
		deplacerCurseur(f,i,2);
		fgets(tableau_winner[i]->nom, taille_nom, f);
		deplacerCurseur(f,i,3);
		fgets(tableau_winner[i]->nature, taille_nature, f);

}

void remplirTableau(Winner** tab_winner, FILE* f, int number_of_winners){

	for(int i; i<number_of_winners;i++){
		creer_winner(tab_winner,f,i+1);
	}
}

Winner ** tableau_winner (FILE* f){
	int number_of_winners = numberOfWinners(f);
	Winner** tab_winners = calloc(number_of_winners, sizeof(Winner*));
	remplirTableau(tab_winners,f,number_of_winners);
	return tab_winners;
}

Winner ** readWinners(FILE * f){
	return tableau_winner(f);
	}
	


int main(void)
{ 
	char filename[] = "turingWinners.csv";
	FILE* f = fopen(filename,"r");
    // TODO
	printf("La valeur de l'entier est : %d\n", numberOfWinners(f));
	Winner ** liste = readWinners(f);
	return EXIT_SUCCESS;
}

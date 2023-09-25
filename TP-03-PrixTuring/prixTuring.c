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


typedef struct{
	int annee;
	char * nom;
	char * nature;
}Winner;


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

int main(void)
{ 
	char filename[] = "turingWinners.csv";
	FILE* f = fopen(filename,"r");
    // TODO
	printf("La valeur de l'entier est : %d\n", numberOfWinners(f));

	return EXIT_SUCCESS;
}

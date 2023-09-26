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
int* tailleGagnant(FILE* f, int i){
	int * tab[numberOfWinners(f)];
	char character;
	int countVirgule =0;
	int nbGagnant=0;
	while ((character=fgetc(f))!=EOF)
	{
		if(character==';'){
			countVirgule+=1;
			if(countVirgule&2==1){
				
			}

		}
	}
	
}












Winner ** creerFichier(FILE* fichier){
	int nbWinners = numberOfWinners(fichier);
	Winner * F[]= (Winner *)malloc(sizeof(Winner)*nbWinners);
		for(int i=0;i<nbWinners;i++){
			F[i].annee= (int)malloc(sizeof(int));
			F[i].nom=(char*)malloc(sizeof(char));
		} 
		

}
int lengthStringFromFileUntil(FILE*f,char delim){
	int result =0;
	char character;
	while((character=fgetc(f))!=delim);
		delim+=1;
}

char * readStringFromFileUntil(FILE* f, char delim){
	int length = lengthStringFromFileUntil(f,delim);
	char * result=calloc(length+1,sizeof(char));
	int poubelle = fseek(f, -length,0);
	char character;
	while ((character=fgetc(f))!=delim)
	{
		
	}
	


}

void readWinner(Winner * winner , FILE*f)
{
	fscanf(f,"%i"";",&winner->annee);
	winner->nom =readStringFromFileUntil(f,';');
	winner->nature=readStringFromFileUntil(f,'\n');
}

void readWinners(FILE * f){
	
	}
	
}

int main(int argc, char** argv)
{ 
	char filename[] = "turingWinners.csv";
	char outputFilename[]="out.csv";
	FILE* f = fopen(filename,"r");
    // TODO
	printf("La valeur de l'entier est : %d\n", numberOfWinners(f));

	return EXIT_SUCCESS;
}

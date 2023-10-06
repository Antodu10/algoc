#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "vaccins_covid.h"

// =========
// = Types =
// =========

const char NUCLEOTIDES[] = "ATCG";

typedef struct{
	int index;
	int distance;
}Difference;

// =============
// = Fonctions =
// =============


bool isNucleotide(char c) {
    return (c==NUCLEOTIDES[0] || c==NUCLEOTIDES[1] || c==NUCLEOTIDES[2] || c==NUCLEOTIDES[3]);
}

int indexOf(char nucleotide) {
	switch(nucleotide) {
		case 'A': return 0;
		case 'T': return 1;
		case 'C': return 2;
		case 'G': return 3;
		default:
			return -1;
	}
}

int distanceBetweenNucleotides(char n1, char n2) {
    return indexOf(n1)-indexOf(n2);
}

int*  statistics(char* sequence){
	int a,b,c,d = 0;
	int n=(sizeof(sequence));
	for(int i=0;i<n;i++){ 
		if(indexOf(sequence[i])==0){a++;}
		else if (indexOf(sequence[i])==1){b++;}
		else if(indexOf(sequence[i])==2){c++;}
		else if(indexOf(sequence[i])==3){d++;}
		else{NULL;}
	}
	int* tab = malloc(4*sizeof(int));
	tab[0]=(a*100)/n;
	tab[1]=(b*100)/n;
	tab[2]=(c*100)/n;
	tab[3]=(d*100)/n;
	return tab;
}
int nombreDeDifferencesBetween(char* seq1,char* seq2){
	int compteur=0;
	int tailleSequence = (sizeof(seq1));
	for(int i=0;i<tailleSequence;i++){
		if(distanceBetweenNucleotides(seq1[i],seq2[i])!=0){
			compteur+=1;
		}
	}
	return compteur;
}

Difference** computeDifferencesBetween(char* seq1, char* seq2){
	//il faut allouer un  certain espace mémoire pour ce tableau de différences
	//pour cela je dois savoir combien j'ai de différence
	//pour mon algorithme j'ai besoin d'un compteur de différence
	int n = nombreDeDifferencesBetween(seq1,seq2);
	int compteur = 0;
	Difference **differences = calloc(n,sizeof(Difference*));

	int tailleSequence = (sizeof(seq1));
	//je remplie ensuite mon tableau
	for(int i=0;i<tailleSequence;i++){
		if(distanceBetweenNucleotides(seq1[i],seq2[i])!=0){
		    differences[compteur] = malloc(sizeof(Difference));
			differences[compteur]->index=i;
			differences[compteur]->distance=distanceBetweenNucleotides(seq1[i],seq2[i]);
			compteur+=1;
		}
	}
return differences;

}

void printDifferences(Difference ** tableauDiff){
	int nbDiff = sizeof(tableauDiff);
	//printf("%i\n",nbDiff);
	for(int i =0;i<nbDiff;i++){
		printf("%i",tableauDiff[i]->index);
		printf("%i\n",tableauDiff[i]->distance);
	}
}

// ========
// = Main =
// ========

int main(void){

	char sequenceDeNucleotides[]="ATGCATCCATCATGCATGTA";
	 char seq1[]= "ATGC";
 	 char seq2[]= "ATCG";
	 // printf("%s\n",code_proteine_spike_moderna);
	 int* tab = statistics(sequenceDeNucleotides);
	 printf("%i",tab[0]);
	 Difference** dif = computeDifferencesBetween(seq1,seq2);
	 printDifferences(dif); 
	

	return EXIT_SUCCESS;
}


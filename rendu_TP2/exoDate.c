#include <stdio.h>


typedef enum {
    janvier,
    fevrier,
    mars,
    avril,
    mai,
    juin,
    juillet,
    aout,
    septembre,
    octobre,
    novembre,
    decembre
}Mois;

typedef struct{
    int jour;
    int annee;
     Mois mois ;
}Date;



void initialise(Date* p){
  
    scanf("%d",&(p->jour));
    scanf("%d",&(p->annee));
    scanf("%d",(int* )&p->mois);

}

Date creerDateParCopie(){
    Date d;
    initialise(&d);
    return d;

}

//Date* newDate(){
   // Date* d = (Date*)malloc(sizeof(Date)); //sizeof rend la taille en octet de Date, et malloc reserve l'espace mémoir de taille donné par sizeof
   // initialise(d);
   // return d;

//}
// faire free pour libérer l'espace mémoire, mais ne plus l'exploiter. Donc pour éviter ça
//il faut allouer à l'ancien pointeur de l'espace la valeur NULL




int main(void){ 
Date d;
initialise(&d);
}
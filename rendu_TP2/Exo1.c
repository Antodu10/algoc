#include <stdio.h>
#include <stdbool.h>

void echangeContenu(int *a, int *b){
int temp = *a;
*a=*b;
*b=temp;
}









int main (void){
   int a =10;
   int b=20;
   echangeContenu(&a,&b);
   printf("L'entier est : %d\n", a);
    return 0;

}
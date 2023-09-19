#include <stdio.h>
#include <stdbool.h>


typedef short TypeEntier;
TypeEntier factorielle(TypeEntier n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorielle(n - 1);
    }
}

int main(void) {
    TypeEntier i;
for (i=1;i<16;i++){
    TypeEntier resultat = factorielle(i);
    printf("La factorielle de %d est : %d\n", i, resultat);}
    return 0;
}
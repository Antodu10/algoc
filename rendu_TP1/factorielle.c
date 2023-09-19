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
    TypeEntier n = 6;
    TypeEntier resultat = factorielle(n);
    printf("La factorielle de %d est : %d\n", n, resultat);
    return 0;
}
// Leia o tamanho do lado de um quadrado e imprima como resultado a sua área. 

#include <stdio.h>

int main(){

int comprimento;
int area;

printf("Informe o comprimento do quadrado?: ");
scanf("%d", &comprimento);

area = comprimento * comprimento;

printf("\nA area do quadrado é: %d\n\n", area);

    return 0;
}
// DCE05858 - Programa��o II (UFES)
// Implemente e teste um programa que leia 3 números inteiros e imprima a sua média
// aritmética. 

#include <stdio.h>

int main(){

float numero1, numero2, numero3;
float media;

printf("Digite o primeiro numero: ");
scanf("%f", &numero1);

printf("Digite o segundo numero: ");
scanf("%f", &numero2);

printf("Digite o terceiro numero: ");
scanf("%f", &numero3);


media = (numero1 + numero2 + numero3) / 3;

printf("A média do 3 numeros é %.2f\n", media);

    return 0;
}

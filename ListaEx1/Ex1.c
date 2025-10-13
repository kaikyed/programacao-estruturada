//Implemente e teste um programa que leia 2 números inteiros e imprima o seu produto. 

#include <stdio.h>

int main(){

int valor1;
int valor2;
int produto;

printf("Digite o primeiro numero: ");
scanf("%d", &valor1);

printf("\nDigite o segundo numero: ");
scanf("%d", &valor2);

produto = valor1 * valor2;

printf("\nO produto de desses dois valores é: %d\n\n", produto);

return 0;

}
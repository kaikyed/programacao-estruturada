// Implemente e teste um programa que leia um número inteiro e imprima o seu antecessor e
// o seu sucessor

#include <stdio.h>

int main(){

    int numero, sucessor, antecessor;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    sucessor = numero + 1;
    antecessor = numero - 1;

    printf("\nO antecessor do número %d é %d\n", numero, antecessor);

    printf("O sucessor do número %d é %d\n\n",numero, sucessor);

    return 0;
}

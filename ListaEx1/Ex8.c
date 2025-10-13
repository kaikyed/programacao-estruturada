// Implemente e teste um programa que leia um valor em real e a cotação do dólar. Em
// seguida, imprima o valor correspondente em dólares. 

#include <stdio.h>

int main (){

    float dolar;
    float real;
    float cotacao;

    printf("Infome o valor em real brasileiro R$: ");
    scanf("%f", &real);

    printf("Informe o valor da cotação $: ");
    scanf("%f", &cotacao);

    dolar = real / cotacao;

    printf("Valor em dolares $: %.3f\n", dolar);

    return 0;
}
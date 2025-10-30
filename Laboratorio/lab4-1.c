// Exercício: Escreva um programa que conta e mostra na tela o número de vezes em que o
// número 7 é digitado pelo usuário. O programa lê números inteiros até que o número -1
// seja digitado.

// Faça apenas com a função while.

#include <stdio.h>
#include <stdlib.h>

int main(){

int num, cont = 0;

printf("Digite um numero: \n");

while (num != -1 )
{
    scanf("%d", &num);

    if(num == 7){

        cont++;

    }

}

printf("O numero 7 fo digitado %d vezes", cont);

    return 0;
}
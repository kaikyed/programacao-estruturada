// DCE05858 - Programa��o II (UFES)
// Faça um programa que leia um número inteiro positivo de três dígitos (de 100 a 999). Gere
// outro número formado pelos dígitos invertidos do número lido. 

#include <stdio.h>

int main(){

    int numero, centena, dezena, unidade, invertido;

    printf("Digite um número inteiro de três dígitos (100 a 999): ");
    scanf("%d", &numero);

    if (numero < 100 || numero > 999) {
    printf("Número inválido! Deve estar entre 100 e 999.\n");
            return 1;
        }

    // Separar os dígitos
    centena = numero / 100;
    dezena = (numero % 100) / 10;
    unidade = numero % 10;

    // Montar número invertido
    invertido = unidade * 100 + dezena * 10 + centena;

    printf("Número invertido: %d\n", invertido);



    return 0;

}


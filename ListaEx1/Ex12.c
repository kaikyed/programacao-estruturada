// DCE05858 - Programa��o II (UFES)
// Leia um número inteiro de 4 dígitos (de 1000 a 9999) e imprima 1 dígito por linha. 

#include <stdio.h>

int main() {

    int numero, milhar, centena, dezena, unidade;

    printf("Digite um número inteiro de quatro dígitos (1000 a 9999): ");
    scanf("%d", &numero);

    if (numero < 1000 || numero > 9999) {
        printf("Número inválido! Deve estar entre 1000 e 9999.\n");
        return 1;
    }

    milhar   = numero / 1000;
    centena  = (numero % 1000) / 100;
    dezena   = (numero % 100) / 10;
    unidade  = numero % 10;

    printf("Milhar: %d\n", milhar);
    printf("Centena: %d\n", centena);
    printf("Dezena: %d\n", dezena);
    printf("Unidade: %d\n", unidade);

    return 0;
}


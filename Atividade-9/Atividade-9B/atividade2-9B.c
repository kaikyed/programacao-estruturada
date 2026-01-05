#include <stdio.h>

// Crie e leia um vetor de inteiros binário:

// Crie um array de 100 inteiros (valores de 1 a 100) e salve em "vetor.bin".
// Em outro programa, leia esse arquivo binário e exiba todos os números.

int main (){

    FILE* arquivo;
    int vetor[100];
    int i;

    for ( i = 0; i < 100; i++)
    {
        vetor[i] = i + 1;
    }
    
    arquivo = fopen("vetor.bin", "wb");

    if (arquivo == NULL){

        printf("Erro ao criar o arquivo!\n");
        return 1;

    }

    fwrite(vetor, sizeof(int), 100, arquivo);

    printf("Arquivo 'vetor.bin' criado com sucesso.\n");

    fclose(arquivo);

    return 0;
}
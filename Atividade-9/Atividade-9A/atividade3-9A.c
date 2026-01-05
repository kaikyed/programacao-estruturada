#include <stdio.h>

// Escreva um programa para criar o arquivo "multiplos7.txt" e gravar em seu conteúdo os números
// múltiplos de sete de 1 até 94365, um em cada linha

int main(){

    FILE* arquivo;
    int multiplo;
    int i;
    arquivo = fopen("multiplos7.txt", "w");

    if (arquivo == NULL){

        printf("Erro ao abrir o arquivo!\n");
        return 1;

    }

    for (i = 7; i <= 94375; i += 7)
    {

        fprintf(arquivo, "%d\n", i);

    }

    fclose(arquivo);
    
    return 0;
}

#include <stdio.h>

// Crie e leia um vetor de inteiros binário:

// Crie um array de 100 inteiros (valores de 1 a 100) e salve em "vetor.bin".
// Em outro programa, leia esse arquivo binário e exiba todos os números.

int main (){

    FILE* arquivo;
    int vetor[100];
    int i;

    arquivo = fopen("vetor.bin", "rb");

    if (arquivo == NULL){

        printf("Erro: Arquivo 'vetor.bin' nao encontrado.\n");
        return 1;

    }

    size_t lidos = fread(vetor, sizeof(int), 100, arquivo);

    if (lidos != 100) {

        printf("Aviso: Esperava 100 numeros, mas li apenas %zu.\n", lidos);

    }
    else{

        printf("Dados carregados com sucesso!: \n");

        for(i = 0; i < 100; i++) {

            printf("%d ", vetor[i]);

        }

        printf("\n");
  
    }

    fclose(arquivo);

    return 0;
}
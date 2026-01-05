#include <stdio.h>

// Crie um programa em C que abra o arquivo dados.txt, criado no exercício anterior, e exiba seu
// conteúdo na tela.

int main (){

    FILE* arquivo;
    char linha[50];
    arquivo = fopen("dados.txt", "r");

    if (arquivo == NULL){
    
        printf("Erro ao abrir o arquivo!\n");
        return 1;

    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) 
    { 
        printf("%s\n", linha); 
    } 

    fclose(arquivo); 

    return 0;
}

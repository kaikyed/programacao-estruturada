#include <stdio.h>
#include <string.h>

// Crie um arquivo chamado "entrada.txt" com o conteúdo abaixo:

// pao 
// joao 
// marciano 
// meridiano 
// colossal 
// fibrose 
//  merito 
// brito 
// nao

// Faça um programa em C que leia o conteúdo do arquivo linha por linha usando o fscanf(). A cada linha lida,
// conte e imprima a quantidade de letras da string.

int main (){

    FILE* arquivo;
    char palavra[50];
    int tamanho;

    arquivo = fopen("entrada.txt", "r");

    if (arquivo == NULL){
    
        printf("Erro ao abrir o arquivo!\n");
        return 1;

    }

    while (fscanf(arquivo, "%s", palavra) != EOF) 
    { 

        tamanho = strlen(palavra);
        printf("Palavra: %s | Contem: %d letras\n", palavra, tamanho);

    } 

    fclose(arquivo); 

    return 0;
}

// DCE05858 - ProgramaÁ„o II (UFES)
#include <stdio.h>

// Crie um programa em C que abra o arquivo dados.txt, criado no exerc√≠cio anterior, e exiba seu
// conte√∫do na tela.

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

// DCE05858 - Programa��o II (UFES)
#include <stdio.h>

// Crie um programa em C que solicite ao usuário seu nome e idade e salve essas informações em um
// arquivo chamado dados.txt. Cada execução do programa deve sobrescrever os dados anteriores.

int main (){

    FILE* arquivo;
    char nome[50];
    int idade;
    arquivo = fopen("dados.txt", "w");

    if (arquivo == NULL){

        printf("Erro ao abrir o arquivo!\n");
        return 1;

    }

    printf("Digite seu nome: ");
    scanf("%s", &nome);

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    fprintf(arquivo, "%s %d\n", nome, idade);

    fclose(arquivo);

    return 0;
}

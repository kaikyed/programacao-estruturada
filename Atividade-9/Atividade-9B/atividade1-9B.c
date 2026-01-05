// DCE05858 - Programa��o II (UFES)
#include <stdio.h>

// Grave e leia uma struct em um arquivo binário:

// Crie um programa em C que solicite nome e idade do usuário, armazene-os numa struct e salve no arquivo “usuario.bin”.
// Feche o arquivo. Depois, abra para leitura binária, recupere os dados e exiba na tela.

    typedef struct{

        char nome[50];
        int idade;

    } Usuario;

int main (){

    FILE* arquivo;
    Usuario entrada;
    Usuario saida;

    printf("Digite seu nome: ");
    scanf("%s", &entrada.nome);

    printf("Digite sua idade: ");
    scanf("%d", &entrada.idade);

    arquivo = fopen("usuario.bin", "wb");

    if (arquivo == NULL){

        printf("Erro ao criar o arquivo!\n");
        return 1;

    }

    fwrite(&entrada, sizeof(Usuario), 1, arquivo);

    fclose(arquivo);

    arquivo = fopen("usuario.bin", "rb");

    if (arquivo == NULL) {

        printf("Erro ao abrir arquivo para leitura!\n");
        return 1;
    }

    fread(&saida, sizeof(Usuario), 1, arquivo);

    printf("Nome: %s\n", saida.nome);
    printf("Idade: %d\n", saida.idade);

    fclose(arquivo);

    return 0;
}

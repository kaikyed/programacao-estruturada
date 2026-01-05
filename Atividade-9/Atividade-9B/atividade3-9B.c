// DCE05858 - Programação II (UFES)
#include <stdio.h>

// Salve e leia mÃºltiplos registros:

// Escreva um programa para cadastrar 3 pessoas (nome/idade), salvar no arquivo â€œpessoas.binâ€ e outro programa para ler e mostrar os 3 registros gravados.

typedef struct {

    char nome[50];
    int idade;

} Pessoa;

int main (){

FILE *arquivo;

    Pessoa pessoas[3]; 
    int i;

    printf("Cadastro de 3 Pessoas\n");

    for(i = 0; i < 3; i++) {

        printf("\nPessoa #%d\n", i + 1);
        
        printf("Nome: ");
        scanf("%s", pessoas[i].nome);
        
        printf("Idade: ");
        scanf("%d", &pessoas[i].idade);

    }

    arquivo = fopen("pessoas.bin", "wb");
    
    if (arquivo == NULL) {

        printf("Erro ao criar arquivo!\n");
        return 1;
        
    }

    fwrite(pessoas, sizeof(Pessoa), 3, arquivo);

    printf("\nSucesso! registros salvos em 'pessoas.bin'.\n");
    
    fclose(arquivo);

    return 0;
}

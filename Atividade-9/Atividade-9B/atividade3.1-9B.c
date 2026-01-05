// DCE05858 - ProgramaÁ„o II (UFES)
#include <stdio.h>

// Salve e leia m√∫ltiplos registros:

// Escreva um programa para cadastrar 3 pessoas (nome/idade), salvar no arquivo ‚Äúpessoas.bin‚Äù e outro programa para ler e mostrar os 3 registros gravados.

typedef struct {

    char nome[50];
    int idade;

} Pessoa;

int main (){

    FILE *arquivo;
    Pessoa pessoas[3];
    int i;

    arquivo = fopen("pessoas.bin", "rb");

    if (arquivo == NULL) {

        printf("Erro: Arquivo 'pessoas.bin' nao encontrado.\n");
        return 1;

    }

    size_t lidos = fread(pessoas, sizeof(Pessoa), 3, arquivo);

    if (lidos != 3) {

        printf("Aviso: O arquivo parece incompleto.\n");

    }

    printf("--- Pessoas Cadastradas ---\n");

    for(i = 0; i < 3; i++) {

        printf("Registro %d: Nome: %-10s | Idade: %d\n", i+1, pessoas[i].nome, pessoas[i].idade);

    }

    fclose(arquivo);
    return 0;
}

//ATIVIDADE DE LABORATÓRIO: AULA 3 (SEM DIREITO A NOTA NA ENTREGA)
//CLINICA VETERINÁRIA AMIGO FIEL

//NOME DO ALUNO:
//KAIKY EDUARDO SANTOS DA COSTA
//

#include <stdio.h>
#include <string.h>

int main() {

    /*INICIO DECLARAÇÃO DE VARIÁVEIS*/

    int opcao = 0;
    int opcao_at = 0;
    float valor_consulta;
    char nome_dono[30];
    char nome_animal[30];
    char conf_cad;
    int peso_animal;

    char ultimo_nome_dono[30];
    char ultimo_nome_animal[30];
    int ultimo_peso_animal;
    float ultimo_valor_consulta;
    int ultimo_opcao_at;
    int cadastro_realizado = 0;

    int total_atendimentos = 0;
    float total_arrecadado = 0.0;
    int total_cachorros = 0;
    int total_gatos = 0;
    int total_outros = 0;

    /*FIM DECLARAÇÃO DE VARIÁVEIS*/

    do {

        /*ESPAÇO PARA EXIBIÇÃO DO MENU PARA O USUÁRIO*/

        printf("Bem vindo a Clinica Veterinaria Amigo Fiel!\n");
        printf("Informe qual o tipo de Serviço deseja Realizar.\n");
        printf("\nSelecione a Opção:\n\n");

        printf("1 - Cadastro de Atendimento.\n");
        printf("2 - Exibir Último atendimento cadastrado.\n");
        printf("3 - Exibir Estatísticas do dia.\n");
        printf("4 - Encerrar processo.\n\n");
        printf("Selecione: ");
        scanf("%d", &opcao);

        /*FIM ESPAÇO PARA EXIBIÇÃO DO MENU PARA O USUÁRIO*/



        /*ESPAÇO PARA SWITCH CASE*/

        switch (opcao) {
        case 1:
            printf("Informe o nome do Dono do Animal\n");
            printf("Nome do Dono: ");
            scanf("%s", nome_dono);
            printf("\n\nInforme o nome do Animal\n");
            printf("Nome do Animal: ");
            scanf("%s", nome_animal);

            printf("\n\nInforme qual o tipo de animal:\n");
            printf("1 - Cachorro\n");
            printf("2 - Gato\n");
            printf("3 - Outro\n");
            printf("Digite aqui: ");
            scanf("%d", &opcao_at);

            int tipo_valido = 1;
            if (opcao_at == 1) {
                printf("Informe o peso do animal (em kg):\n\n");
                printf("peso do animal (em kg): ");
                scanf("%d", &peso_animal);
                if (peso_animal <= 10) {
                    valor_consulta = 60.00;
                } else {
                    valor_consulta = 80.00;
                }
            } else if (opcao_at == 2) {
                printf("Informe o peso do animal (em kg):\n\n");
                printf("peso do animal (em kg): ");
                scanf("%d", &peso_animal);
                if (peso_animal <= 5) {
                    valor_consulta = 50.00;
                } else {
                    valor_consulta = 70.00;
                }
            } else if (opcao_at == 3) {
                printf("Informe o peso do animal (em kg):\n\n");
                printf("peso do animal (em kg): ");
                scanf("%d", &peso_animal);
                valor_consulta = 90.00;
            } else {
                printf("\nOpção de animal inválida! Não será possível cadastrar este atendimento.\n");
                tipo_valido = 0;
            }

            
            if (tipo_valido == 1) {
                
                printf("O valor calculado da consulta é R$ %.2f \n", valor_consulta);
                printf("Deseja continuar com a operação de cadastro? \n");
                printf("Digite aqui (S/N): ");
                scanf(" %c", &conf_cad);

                // Verifica a confirmação
                if (conf_cad == 'S' || conf_cad == 's') {
                    // "Salva" os dados copiando para as variáveis "ultimo"
                    strcpy(ultimo_nome_dono, nome_dono);
                    strcpy(ultimo_nome_animal, nome_animal);
                    ultimo_peso_animal = peso_animal;
                    ultimo_valor_consulta = valor_consulta;
                    ultimo_opcao_at = opcao_at;
                    cadastro_realizado = 1;
                    
                    // Atualiza as estatísticas
                    total_atendimentos++;
                    total_arrecadado += valor_consulta;
                    if (opcao_at == 1) {
                        total_cachorros++;
                    } else if (opcao_at == 2) {
                        total_gatos++;
                    } else if (opcao_at == 3) {
                        total_outros++;
                    }

                    printf("\n*** Cadastro realizado com sucesso! ***\n\n");
                } else {
                    printf("\n*** Cadastro cancelado. ***\n\n");
                }
            } else {
                printf("\n*** Cadastro não realizado devido ao tipo de animal inválido. ***\n\n");
            }

            break;

        case 2:
            if (cadastro_realizado == 0) {
                printf("\nNenhum atendimento foi cadastrado ainda.\n\n");
            } else {
                printf("\n--- Último Atendimento Cadastrado ---\n");
                printf("Nome do Dono: %s\n", ultimo_nome_dono);
                printf("Nome do Animal: %s\n", ultimo_nome_animal);
                printf("Tipo de Animal: ");
                if (ultimo_opcao_at == 1) {
                    printf("Cachorro\n");
                } else if (ultimo_opcao_at == 2) {
                    printf("Gato\n");
                } else if (ultimo_opcao_at == 3) {
                    printf("Outro\n");
                }
                printf("Peso do Animal: %d kg\n", ultimo_peso_animal);
                printf("Valor da Consulta: R$ %.2f\n", ultimo_valor_consulta);
                printf("--------------------------------------\n\n");
            }
            break;

        case 3:
            if(total_atendimentos == 0){
                printf("\nNenhum atendimento registrado ainda.\n\n");
            }
            else{
                float media_valor = total_arrecadado / total_atendimentos;
                
                printf("\n--- Estatísticas do Dia ---\n");
                printf("Total de Atendimentos: %d\n", total_atendimentos);
                printf("Valor Total Arrecadado: R$ %.2f\n", total_arrecadado);
                printf("Valor Médio por Consulta: R$ %.2f\n", media_valor);
                printf("\nTotal de Animais Atendidos:\n");
                printf("- Cachorros: %d\n", total_cachorros);
                printf("- Gatos: %d\n", total_gatos);
                printf("- Outros: %d\n", total_outros);
                printf("---------------------------\n\n");
            }
            break;

        case 4:
            printf("\nProcesso Encerrado.\n\n");
            break;

        default:
            printf("\nOpção inválida! Tente novamente.\n\n");
            break;
        }

        /*FIM ESPAÇO PARA SWITCH CASE*/

    } while (opcao != 4);

    return 0;
}

//ATIVIDADE DE LABORATÓRIO: AULA 5
//CLINICA VETERINÁRIA AMIGO FIEL

//NOME DO ALUNO:
//KAIKY EDUARDO SANTOS DA COSTA
//

#include <stdio.h>
#include <string.h>

int main() {

    /*INICIO DECLARAÇÃO DE VARIÁVEIS*/

    int opcao = 0; // Opção do menu principal
    int opcao_at = 0; // Tipo de animal
    int opcao_pag = 0; // Forma de pagamento
    float valor_consulta; // Valor base da consulta
    char nome_dono[30];
    char nome_animal[30];
    char conf_cad; // Confirmação de cadastro/cancelamento
    char conf_opt; // Confirmação de serviços adicionais
    char conf_parc; // Confirmação de parcelamento
    int parcelas = 0;
    int peso_animal;
    
    float valor_pago; // Valor recebido em dinheiro
    float troco; // Troco calculado
    float acrescimo_atual; // Acréscimo do atendimento atual (urgência/fim de semana)
    
    // Variáveis de Configuração
    float preco_vacina = 40.00;
    float preco_vermifugacao = 30.00;
    float preco_banho_tosa = 50.00;
    float perc_urgencia = 0.20;
    float perc_fim_semana = 0.10;
    int desconto_dinheiro_ativo = 1; // 1 = ativo
    float perc_desconto_dinheiro = 0.05;

    // Acumuladores de Caixa (Relatório)
    float total_dinheiro = 0.0;
    float total_debito = 0.0;
    float total_credito = 0.0;
    float total_descontos = 0.0;
    float total_acrescimos = 0.0;
    float total_troco_entregue = 0.0;
    float maior_troco_devolvido = 0.0;

    // Estatísticas Detalhadas
    float maior_valor_atendimento = 0.0;
    char maior_valor_nome_animal[30] = "";
    char maior_valor_nome_dono[30] = "";
    int maior_valor_tipo_animal = 0;

    float menor_valor_atendimento = 999999.0;
    char menor_valor_nome_animal[30] = "";
    char menor_valor_nome_dono[30] = "";
    int menor_valor_tipo_animal = 0;

    int maior_peso_cachorro = -1;
    char mais_pesado_cachorro_nome[30] = "";
    char mais_pesado_cachorro_dono[30] = "";

    int maior_peso_gato = -1;
    char mais_pesado_gato_nome[30] = "";
    char mais_pesado_gato_dono[30] = "";

    int maior_peso_outro = -1;
    char mais_pesado_outro_nome[30] = "";
    char mais_pesado_outro_dono[30] = "";

    // Último Atendimento Confirmado
    char ultimo_nome_dono[30];
    char ultimo_nome_animal[30];
    int ultimo_peso_animal;
    float ultimo_valor_consulta;
    int ultimo_opcao_at;
    int cadastro_realizado = 0; 
    
    // Detalhes do Último Pagamento
    int ultimo_forma_pagamento;
    float ultimo_desconto_aplicado = 0.0;
    float ultimo_acrescimo_aplicado = 0.0;
    int ultimo_parcelas = 0;
    
    // Acumuladores Gerais
    int total_atendimentos = 0;
    float total_arrecadado = 0.0;
    int total_cachorros = 0;
    int total_gatos = 0;
    int total_outros = 0;

    float vac_rabica;
    float vermifugacao;
    float banho_tosa;
    float subtotal;

    /*FIM DECLARAÇÃO DE VARIÁVEIS*/
    
    printf("--- BEM VINDO À CLÍNICA VETERINÁRIA AMIGO FIEL ---\n\n");
    
    printf("--------------------------------------------------\n");

    do {

        /*ESPAÇO PARA EXIBIÇÃO DO MENU PARA O USUÁRIO*/
        printf("--------------------------------------------\n");
        printf("Selecione a Opção:\n\n");

        printf("1 - Novo atendimento.\n");
        printf("2 - Visualizar último.\n");
        printf("3 - Cancelar último.\n");
        printf("4 - Estatísticas do dia.\n");
        printf("5 - Caixa e pagamentos.\n");
        printf("6 - Configurações do dia.\n");
        printf("7 - Sair.\n\n");
        printf("Selecione: ");
        
        // Validação da Opção do Menu
        if (scanf("%d", &opcao) != 1 || opcao < 1 || opcao > 7) {
            printf("\nOpção inválida! Digite um número de 1 a 7.\n\n");
            while (getchar() != '\n'); 
            opcao = 0;
            continue;
        }
        printf("--------------------------------------------\n");

        /*FIM ESPAÇO PARA EXIBIÇÃO DO MENU PARA O USUÁRIO*/


        /*ESPAÇO PARA SWITCH CASE*/

        switch (opcao) {
        case 1: // CASE 1:
            while (getchar() != '\n'); 
            
            printf("Informe o nome do Dono do Animal\n");
            printf("Nome do Dono: ");
            scanf("%s", nome_dono);
            printf("\n\nInforme o nome do Animal\n");
            printf("Nome do Animal: ");
            scanf("%s", nome_animal);

            do {
                printf("\n\nInforme qual o tipo de animal:\n");
                printf("1 - Cachorro\n");
                printf("2 - Gato\n");
                printf("3 - Outro\n");
                printf("Digite aqui: ");
                scanf("%d", &opcao_at);
                if (opcao_at < 1 || opcao_at > 3) {
                    printf("\nTipo de animal inválido! Digite 1, 2 ou 3.\n");
                }
            } while (opcao_at < 1 || opcao_at > 3);

            int tipo_valido = 1;
            
            do {
                printf("Informe o peso do animal (em kg):\n\n");
                printf("peso do animal (em kg): ");
                scanf("%d", &peso_animal);
                if (peso_animal <= 0) {
                    printf("\nPeso inválido! O peso deve ser maior que zero.\n");
                }
            } while (peso_animal <= 0);


            if (opcao_at == 1) {
                valor_consulta = (peso_animal <= 10) ? 60.00 : 80.00;
            } else if (opcao_at == 2) {
                valor_consulta = (peso_animal <= 5) ? 50.00 : 70.00;
            } else if (opcao_at == 3) {
                valor_consulta = 90.00;
            } else {
                 tipo_valido = 0;
            }

            
            if (tipo_valido == 1) {
                vac_rabica = 0.0;
                vermifugacao = 0.0;
                banho_tosa = 0.0;
                subtotal = valor_consulta;
                acrescimo_atual = 0.0;
                
                printf("O valor calculado da consulta é R$ %.2f \n", valor_consulta);

                
                printf("Deseja realizar a aplicação de vacina antirrabica? (S/N): ");
                scanf(" %c", &conf_opt);
                if (conf_opt == 'S') {
                    vac_rabica = preco_vacina;
                    subtotal += vac_rabica;
                }

                printf("Deseja realizar vermifugação? (S/N): ");
                scanf(" %c", &conf_opt);
                if (conf_opt == 'S') {
                    vermifugacao = preco_vermifugacao;
                    subtotal += vermifugacao;
                }

                printf("Deseja realizar banho/tosa? (S/N): ");
                scanf(" %c", &conf_opt);
                if (conf_opt == 'S') {
                    banho_tosa = preco_banho_tosa;
                    subtotal += banho_tosa;
                }

                float subtotal_antes_acrescimos = subtotal;
                float acr_urgencia = 0.0;
                float acr_fim_semana = 0.0;

                do {
                    printf("O atendimento é com urgência? (S/N): ");
                    scanf(" %c", &conf_opt);
                } while (conf_opt != 'S' && conf_opt != 'N');

                if (conf_opt == 'S') {
                    acr_urgencia = subtotal * perc_urgencia;
                    subtotal += acr_urgencia;
                }

                do {
                    printf("O atendimento vai ser no final de semana? (S/N): ");
                    scanf(" %c", &conf_opt);
                } while (conf_opt != 'S' && conf_opt != 'N');

                if (conf_opt == 'S') {
                    acr_fim_semana = subtotal * perc_fim_semana;
                    subtotal += acr_fim_semana;
                }
                
                acrescimo_atual = subtotal - subtotal_antes_acrescimos;


                do {
                    printf("\n\nQual vai ser a forma de pagamento?");
                    printf("\n\n1 - Dinheiro");
                    printf("\n2 - Débito");
                    printf("\n3 - Crédito");
                    printf("\n\nDigite aqui: ");
                    scanf("%d", &opcao_pag);
                    if (opcao_pag < 1 || opcao_pag > 3) {
                        printf("\nOpção de pagamento inválida! Tente novamente com 1, 2 ou 3.\n");
                    }
                } while (opcao_pag < 1 || opcao_pag > 3);

                float juros_credito = 0.0;
                float desconto_aplicado = 0.0;
                parcelas = 0;
                
                if(opcao_pag == 1){
                    
                    printf("\n\nVocê selecionou Dinheiro!\n");
                    
                    float valor_sem_desconto = subtotal;

                    if (desconto_dinheiro_ativo) {
                        subtotal = subtotal * (1.0 - perc_desconto_dinheiro); 
                        desconto_aplicado = valor_sem_desconto * perc_desconto_dinheiro;
                        printf("Com o desconto de 5%%, o valor a ser pago é R$ %.2f\n", subtotal);
                    } else {
                        printf("Desconto de Dinheiro Inativo. Valor a ser pago é R$ %.2f\n", subtotal);
                    }
                    
                    do {
                        printf("Informe o valor pago pelo cliente: R$ ");
                        scanf("%f", &valor_pago);

                        if (valor_pago < subtotal) {
                            printf("Valor insuficiente. Faltam R$ %.2f\n", subtotal - valor_pago);
                        }

                    } while (valor_pago < subtotal);

                    troco = valor_pago - subtotal;
                    printf("Valor recebido: R$ %.2f\n", valor_pago);
                    printf("Troco: R$ %.2f\n\n", troco);
                    
                    total_dinheiro += subtotal;
                    total_descontos += desconto_aplicado; 
                    total_acrescimos += acrescimo_atual;
                    total_troco_entregue += troco;
                    if (troco > maior_troco_devolvido) {
                        maior_troco_devolvido = troco;
                    }


                }
                else if(opcao_pag == 2){
                    
                    printf("\n\nVocê selecionou Débito (sem acréscimo)\n\n");
                    
                    total_debito += subtotal;
                    total_acrescimos += acrescimo_atual;

                }
                else if(opcao_pag == 3){

                    printf("\n\nVocê selecionou crédito\n\n");

                    do {
                        printf("Deseja realizar parcelamento? (S/N)\n\n");
                        printf("Digite aqui: ");
                        scanf(" %c", &conf_parc);
                    } while (conf_parc != 'S' && conf_parc != 'N');

                    
                    if(conf_parc == 'S'){
                        do {
                            printf("Quantas vezes você deseja parcelar?\n");
                            printf("1X de R$ %.2f\n", subtotal);
                            printf("2X de R$ %.2f\n", (subtotal * 1.02) / 2); 
                            printf("3X de R$ %.2f\n", (subtotal * 1.04) / 3); 
                            printf("\n\nDigite aqui: ");
                            scanf("%d", &parcelas);
                            if (parcelas < 1 || parcelas > 3) {
                                printf("\nOpção de parcela inválida! Digite 1, 2 ou 3.\n");
                            }
                        } while (parcelas < 1 || parcelas > 3);

                        if(parcelas == 1){
                            juros_credito = 0.0;
                        }
                        else if (parcelas == 2){
                            juros_credito = subtotal * 0.02;
                            subtotal = subtotal * 1.02;
                        }
                        else if (parcelas == 3)
                        {
                            juros_credito = subtotal * 0.04;
                            subtotal = subtotal * 1.04;
                        }
                    }
                    
                    total_credito += subtotal;
                    total_acrescimos += acrescimo_atual + juros_credito;
                }
                
                printf("\n--- Resumo do Atendimento --- \n");
                printf("Dono: %s\n", nome_dono);
                printf("Animal: %s\n", nome_animal);
                printf("Tipo de Animal: ");
                if (opcao_at == 1) printf("Cachorro\n");
                else if (opcao_at == 2) printf("Gato\n");
                else if (opcao_at == 3) printf("Outro\n");
                printf("Peso: %d kg\n", peso_animal);
                printf("Consulta (base): R$ %.2f\n", valor_consulta);
                printf("Total Final: R$ %.2f\n", subtotal);
                printf("-----------------------------\n");
                
                do {
                    printf("Deseja confirmar e gravar este atendimento? (S/N): ");
                    scanf(" %c", &conf_cad);
                } while (conf_cad != 'S' && conf_cad != 'N');

                if (conf_cad == 'S') { 
                    
                    strcpy(ultimo_nome_dono, nome_dono);
                    strcpy(ultimo_nome_animal, nome_animal);
                    ultimo_peso_animal = peso_animal;
                    ultimo_valor_consulta = subtotal; 
                    ultimo_opcao_at = opcao_at;
                    ultimo_forma_pagamento = opcao_pag;
                    ultimo_desconto_aplicado = desconto_aplicado;
                    ultimo_acrescimo_aplicado = acrescimo_atual + juros_credito;
                    ultimo_parcelas = parcelas;
                    cadastro_realizado = 1;
                    
                    total_atendimentos++;
                    total_arrecadado += subtotal; 
                    if (opcao_at == 1) {
                        total_cachorros++;
                    } else if (opcao_at == 2) {
                        total_gatos++;
                    } else if (opcao_at == 3) {
                        total_outros++;
                    }
                    
                    if (subtotal > maior_valor_atendimento) {
                        maior_valor_atendimento = subtotal;
                        strcpy(maior_valor_nome_animal, nome_animal);
                        strcpy(maior_valor_nome_dono, nome_dono);
                        maior_valor_tipo_animal = opcao_at;
                    }
                    if (subtotal < menor_valor_atendimento || menor_valor_atendimento == 999999.0) {
                        menor_valor_atendimento = subtotal;
                        strcpy(menor_valor_nome_animal, nome_animal);
                        strcpy(menor_valor_nome_dono, nome_dono);
                        menor_valor_tipo_animal = opcao_at;
                    }

                    if (opcao_at == 1 && peso_animal > maior_peso_cachorro) {
                        maior_peso_cachorro = peso_animal;
                        strcpy(mais_pesado_cachorro_nome, nome_animal);
                        strcpy(mais_pesado_cachorro_dono, nome_dono);
                    } else if (opcao_at == 2 && peso_animal > maior_peso_gato) {
                        maior_peso_gato = peso_animal;
                        strcpy(mais_pesado_gato_nome, nome_animal);
                        strcpy(mais_pesado_gato_dono, nome_dono);
                    } else if (opcao_at == 3 && peso_animal > maior_peso_outro) {
                        maior_peso_outro = peso_animal;
                        strcpy(mais_pesado_outro_nome, nome_animal);
                        strcpy(mais_pesado_outro_dono, nome_dono);
                    }

                    printf("\n*** Cadastro realizado com sucesso! ***\n\n");

                } else {

                    printf("\n*** Cadastro cancelado. ***\n\n");

                }
            } else {

                printf("\n*** Cadastro não realizado devido ao tipo de animal inválido. ***\n\n");

            }

            break;

        case 2: // CASE 2: VISUALIZAR ÚLTIMO
            if (cadastro_realizado == 0) {
                printf("\nNenhum atendimento foi cadastrado ainda.\n\n");
            } else {
                printf("\n--- Último Atendimento Cadastrado (Relatório Completo) ---\n");
                printf("Dono: %s\n", ultimo_nome_dono);
                printf("Animal: %s\n", ultimo_nome_animal);
                printf("Tipo: ");
                if (ultimo_opcao_at == 1) printf("Cachorro\n");
                else if (ultimo_opcao_at == 2) printf("Gato\n");
                else if (ultimo_opcao_at == 3) printf("Outro\n");
                printf("Peso: %d kg\n", ultimo_peso_animal);
                printf("--------------------------------------\n");
                printf("Forma de Pagamento: ");
                if (ultimo_forma_pagamento == 1) printf("Dinheiro\n");
                else if (ultimo_forma_pagamento == 2) printf("Débito\n");
                else if (ultimo_forma_pagamento == 3) printf("Crédito (%dX)\n", ultimo_parcelas);
                
                printf("Total Desconto Aplicado: R$ %.2f\n", ultimo_desconto_aplicado);
                printf("Total Acréscimo Aplicado: R$ %.2f\n", ultimo_acrescimo_aplicado);
                printf("Valor Final Cobrado: R$ %.2f\n", ultimo_valor_consulta);
                printf("--------------------------------------\n\n");
            }
            break;

        case 3: // CASE 3: CANCELAR ÚLTIMO
            if (cadastro_realizado == 0) {
                printf("\nNenhum atendimento foi confirmado para ser cancelado.\n\n");
            } else {
                do {
                    printf("\nConfirma o cancelamento do último atendimento (Dono: %s, Valor: R$ %.2f)? (S/N): ", ultimo_nome_dono, ultimo_valor_consulta);
                    scanf(" %c", &conf_cad);
                } while (conf_cad != 'S' && conf_cad != 'N');

                if (conf_cad == 'S') {
                    total_atendimentos--;
                    total_arrecadado -= ultimo_valor_consulta;

                    if (ultimo_forma_pagamento == 1) {
                        total_dinheiro -= ultimo_valor_consulta;
                        total_descontos -= ultimo_desconto_aplicado;
                    } else if (ultimo_forma_pagamento == 2) {
                        total_debito -= ultimo_valor_consulta;
                    } else if (ultimo_forma_pagamento == 3) {
                        total_credito -= ultimo_valor_consulta;
                    }
                    total_acrescimos -= ultimo_acrescimo_aplicado;
                    
                    if (ultimo_opcao_at == 1) total_cachorros--;
                    else if (ultimo_opcao_at == 2) total_gatos--;
                    else if (ultimo_opcao_at == 3) total_outros--;
                    
                    cadastro_realizado = 0; 
                    printf("\n*** Último atendimento cancelado com sucesso. Os acumuladores foram revertidos. ***\n\n");
                } else {
                    printf("\n*** Cancelamento não realizado. ***\n\n");
                }
            }
            break;

        case 4: // CASE 4: ESTATÍSTICAS DO DIA
            if(total_atendimentos == 0){
                printf("\nNenhum atendimento registrado ainda.\n\n");
            }
            else{
                float ticket_medio = total_arrecadado / total_atendimentos;
                
                printf("\n--- Estatísticas do Dia ---\n");
                printf("Total de Atendimentos Confirmados: %d\n", total_atendimentos);
                printf("Soma Total Arrecadada: R$ %.2f\n", total_arrecadado);
                printf("Ticket Médio: R$ %.2f\n", ticket_medio);
                printf("\nTotal de Animais Atendidos:\n");
                printf("- Cachorros: %d\n", total_cachorros);
                printf("- Gatos: %d\n", total_gatos);
                printf("- Outros: %d\n", total_outros);
                printf("---------------------------\n");

                printf("\nDetalhes de Valor:\n");
                printf("- MAIOR VALOR: R$ %.2f (Animal: %s, Dono: %s, Tipo: %d)\n", 
                       maior_valor_atendimento, maior_valor_nome_animal, maior_valor_nome_dono, maior_valor_tipo_animal);
                printf("- MENOR VALOR: R$ %.2f (Animal: %s, Dono: %s, Tipo: %d)\n", 
                       menor_valor_atendimento, menor_valor_nome_animal, menor_valor_nome_dono, menor_valor_tipo_animal);
                
                printf("\nAnimal Mais Pesado (de cada tipo):\n");
                if (maior_peso_cachorro != -1) {
                     printf("- Cachorro: %d kg (Nome: %s, Dono: %s)\n", maior_peso_cachorro, mais_pesado_cachorro_nome, mais_pesado_cachorro_dono);
                }
                if (maior_peso_gato != -1) {
                     printf("- Gato: %d kg (Nome: %s, Dono: %s)\n", maior_peso_gato, mais_pesado_gato_nome, mais_pesado_gato_dono);
                }
                if (maior_peso_outro != -1) {
                     printf("- Outro: %d kg (Nome: %s, Dono: %s)\n", maior_peso_outro, mais_pesado_outro_nome, mais_pesado_outro_dono);
                }
                printf("---------------------------\n\n");
            }
            break;
        
        case 5: // CASE 5: CAIXA E PAGAMENTOS
            printf("\n--- Relatório de Caixa e Pagamentos ---\n");
            
            printf("Saldo Total do Caixa (Arrecadado): R$ %.2f\n", total_arrecadado);
            printf("---------------------------------------\n");
            
            printf("Total Recebido por Forma de Pagamento:\n");
            printf("- Dinheiro: R$ %.2f\n", total_dinheiro);
            printf("- Débito: R$ %.2f\n", total_debito);
            printf("- Crédito: R$ %.2f\n", total_credito);
            printf("---------------------------------------\n");

            printf("Total de Descontos Concedidos: R$ %.2f\n", total_descontos);
            printf("Total de Acréscimos Cobrados: R$ %.2f\n", total_acrescimos);
            printf("---------------------------------------\n");

            printf("Total de Troco Entregue: R$ %.2f\n", total_troco_entregue);
            printf("Maior Troco Devolvido: R$ %.2f\n", maior_troco_devolvido);
            printf("---------------------------------------\n\n");
            break;

        case 6: { // CASE 6: CONFIGURAÇÕES DO DIA
            int opt_config = 0;
            float novo_valor;
            
            do {
                printf("\n--- Submenu de Configurações ---\n");
                printf("Valores Atuais:\n");
                printf("1 - Vacina Antirrábica: R$ %.2f\n", preco_vacina);
                printf("2 - Vermifugação: R$ %.2f\n", preco_vermifugacao);
                printf("3 - Banho/Tosa: R$ %.2f\n", preco_banho_tosa);
                printf("4 - %s: %.2f%%\n", "Urgência (Acréscimo)", perc_urgencia * 100);
                printf("5 - %s: %.2f%%\n", "Fim de Semana (Acréscimo)", perc_fim_semana * 100);
                printf("6 - Desconto Dinheiro (5%%): %s\n", desconto_dinheiro_ativo ? "ATIVO" : "INATIVO");
                printf("7 - Voltar ao Menu Principal\n");
                printf("Selecione a Opção para Alterar: ");
                
                if (scanf("%d", &opt_config) != 1) {
                    printf("\nOpção inválida! Tente novamente.\n");
                    while (getchar() != '\n');
                    continue;
                }
                
                if (opt_config >= 1 && opt_config <= 5) {
                    printf("Informe o novo valor: ");
                    if (scanf("%f", &novo_valor) != 1) {
                        printf("\nEntrada inválida!\n");
                        while (getchar() != '\n');
                        continue;
                    }

                    if (opt_config >= 1 && opt_config <= 3) {
                        if (novo_valor < 0 || novo_valor > 500) {
                            printf("\nValor inválido! Preços devem estar entre R$ 0 e R$ 500.\n");
                            continue;
                        }
                    } else if (opt_config >= 4 && opt_config <= 5) {
                        if (novo_valor < 0 || novo_valor > 50) {
                            printf("\nValor inválido! Percentuais devem estar entre 0 e 50.\n");
                            continue;
                        }
                        novo_valor /= 100.0;
                    }

                    switch (opt_config) {
                        case 1: preco_vacina = novo_valor; break;
                        case 2: preco_vermifugacao = novo_valor; break;
                        case 3: preco_banho_tosa = novo_valor; break;
                        case 4: perc_urgencia = novo_valor; break;
                        case 5: perc_fim_semana = novo_valor; break;
                    }
                    printf("\nValor atualizado com sucesso.\n");
                } 
                else if (opt_config == 6) {
                    desconto_dinheiro_ativo = !desconto_dinheiro_ativo;
                    printf("\nDesconto de Dinheiro 5%% agora está %s.\n", desconto_dinheiro_ativo ? "ATIVO" : "INATIVO");
                } 
                else if (opt_config != 7) {
                    printf("\nOpção inválida!\n");
                }

            } while (opt_config != 7);
            break;
        }

        case 7:
            printf("\nProcesso Encerrado.\n\n");
            break;

        default:
            break;
        }

        /*FIM ESPAÇO PARA SWITCH CASE*/

    } while (opcao != 7);

    return 0;
}
// Três amigos jogaram na loteria. Caso eles ganhem, o prêmio deve ser repartido
// proporcionalmente ao valor que cada deu para a realização da aposta. Faça um programa
// que leia quanto cada apostador investiu, o valor do prêmio, e imprima quanto cada um
// ganharia do prêmio com base no valor investido. 

#include <stdio.h>

int main(){

    float aposta1;
    float aposta2;
    float aposta3;
    float totalapostado;
    float parte1, parte2, parte3;
    float premio;

    printf("Informe o valor do prêmio da aposta: R$ ");
    scanf("%f", &premio);

    printf("Informe o valor da aposta do amigo 1: R$");
    scanf("%f", &aposta1);

    printf("Informe o valor da aposta do amigo 2: R$");
    scanf("%f", &aposta2);

    printf("Informe o valor da aposta do amigo 3: R$");
    scanf("%f", &aposta3);

    totalapostado = aposta1 + aposta2 + aposta3;

    parte1 = (aposta1/totalapostado) * premio;
    parte2 = (aposta2/totalapostado) * premio;
    parte3 = (aposta3/totalapostado) * premio;

    printf("\nO valor total apostado foi de: R$ %.2f\n", totalapostado);
    printf("\nO primeiro amigo vai receber: R$ %.2f\n", parte1);
    printf("\nO segundo amigo vai receber: R$ %.2f\n", parte2);
    printf("\nO terceiro amigo vai receber: R$ %.2f\n", parte3);


    return 0;

}

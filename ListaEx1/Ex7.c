// Implemente e teste um programa que leia um valor de despesa de restaurante, o valor da
// gorjeta (em porcentagem) e o número de pessoas para dividir a conta, e imprima o valor que
// cada um deve pagar. Assuma que a conta será dividida igualmente. 

#include <stdio.h>

int main(){

float despesa;
float gorjeta = 0.10;
float valor_gorjeta;
float total;
float valor_pessoa;
int num_pessoas;

printf("Informe o valor da despesa: ");
scanf("%f", &despesa);

printf("\nInforme o numero de pessoas para dividir a conta: ");
scanf("%f", &num_pessoas);

valor_gorjeta = despesa * gorjeta;
total = despesa + valor_gorjeta;

valor_pessoa = total / num_pessoas;

    printf("\nValor total da conta (com gorjeta): R$ %.2f\n", total);
    printf("Cada pessoa deve pagar: R$ %.2f\n", valor_pessoa);

    return 0;
}

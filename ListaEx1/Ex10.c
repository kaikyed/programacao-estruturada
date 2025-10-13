// Uma empresa contrata um encanador a R$ 30,00 por dia. Faça um programa que solicite
// o número de dias trabalhados pelo encanador e imprima a quantia líquida que deverá ser
// paga, sabendo-se que são descontados 8% para imposto de renda. 

#include <stdio.h>

int main(){

int num_dia;
float valor_dia = 30.00;
float desconto = 0.08;
float salario;

printf("Informe o numero de dias trabalhados: ");
scanf("%d", &num_dia);

salario = (valor_dia * num_dia) * (1 - desconto);

printf("\nO trabalhador receberá R$ %.3f de salário\n\n", salario);


    return 0;
}
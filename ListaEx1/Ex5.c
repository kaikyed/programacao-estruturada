// Implemente e teste um programa que leia duas notas de um aluno, calcule e imprima sua
// média, sabendo que a primeira nota tem peso 3 e a segunda nota tem peso 7

#include <stdio.h>

int main(){

float nota1;
float nota2;
float media;

printf("Insira a primeira nota: ");
scanf("%f", &nota1);

printf("\nInsira a segunda nota: ");
scanf("%f", &nota2);

media = (nota1 * 3 + nota2 * 7) / 10;

printf("A valor da media do aluno é %.2f\n", media);

    return 0;
}
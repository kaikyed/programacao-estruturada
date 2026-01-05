// Modifique o programa anterior para imprimir a média aritmética com 3 casas decimais. 

#include <stdio.h>

int main(){

float numero1, numero2, numero3;
float media;

printf("Digite o primeiro numero: ");
scanf("%f", &numero1);

printf("Digite o segundo numero: ");
scanf("%f", &numero2);

printf("Digite o terceiro numero: ");
scanf("%f", &numero3);


media = (numero1 + numero2 + numero3) / 3;

printf("A média do 3 numeros é %.3f\n", media);

    return 0;
}

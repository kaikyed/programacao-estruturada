// DCE05858 - ProgramaÁ„o II (UFES)
#include <stdio.h>
#include <stdlib.h>

int main(){

    int x, n, y, i = 1, soma;

    printf("Informe o valor do somat√≥rio que ir√° fazer");
    scanf("%d", &soma);

    switch (soma)
    {
    case 1:
   
    printf("\nInforme o valor de n: ");
    scanf("%d", &n);

    printf("\nInforme o valor de x: ");
    scanf("%d", &x);

        break;
    
    case 2:

    printf("\nInforme o valor de n: ");
    scanf("%d", &n);

    printf("\nInforme o valor de x: ");
    scanf("%d", &x);

    printf("\nInforme o valor de y: ");
    scanf("%d", &y);

        break;

    case 3:
    
    printf("\nInforme o valor de n: ");
    scanf("%d", &n);

    printf("\nInforme o valor de x: ");
    scanf("%d", &x);

        break;

    default:
        

        break;
    }

    return 0;
}

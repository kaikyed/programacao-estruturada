// DCE05858 - Programação II (UFES)
#include <stdio.h>

int main(){

    int somatorio = 0;
    int tam;
    int i;
    

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tam);
    
    int vet[tam];

    for ( i = 0; i < tam; i++)
    {
        printf("Informe os valores do vetor: ");
        scanf("%d", &vet[i]);

    }
    for ( i = 0; i < tam; i++)
    {
        somatorio += vet[i];
    }

    printf("O resultado do somatÃ³rio Ã© %d\n", somatorio);

    return 0;

}

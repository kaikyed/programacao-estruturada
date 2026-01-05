#include <stdio.h>

#define MAX 1000

int main() {
    int vetor[MAX];
    int n, i, soma = 0;

    printf("Digite o tamanho do vetor (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX || n <= 0) {
        printf("Tamanho invalido!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }

    printf("\nSoma dos valores: %d\n", soma);

    return 0;
}

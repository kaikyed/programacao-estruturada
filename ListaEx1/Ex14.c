// Leia uma velocidade em m/s (metros por segundo) e apresente-a convertida em km/h
// (quilômetros por hora). A fórmula de conversão é: K = M*3.6, sendo K a velocidade em km/h
// e M em m/s. 

#include <stdio.h>

int main() {
    float velocidade_ms, velocidade_kmh;

    // Solicita a entrada do usuário (velocidade em m/s)
    printf("Digite a velocidade em m/s: ");
    scanf("%f", &velocidade_ms);

    // Converte m/s para km/h
    velocidade_kmh = velocidade_ms * 3.6;

    // Exibe o resultado
    printf("A velocidade em km/h é: %.2f\n", velocidade_kmh);

    return 0;
}

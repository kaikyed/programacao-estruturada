// Implemente e teste um programa que leia as coordenadas de dois pontos e calcule a
// distância entre eles, utilizando a função double sqrt(double x); da biblioteca padrão math.h.
// Lembre-se que a distância entre dois pontos é dada pela seguinte fórmula: 𝑑= √(𝑥2−𝑥1)2+
// (𝑦2−𝑦1)2 

#include <stdio.h>
#include <math.h>

int main(){

int x1, x2, y1, y2;
double distancia;

printf("Digite o valor de x1 e x2: ");
scanf("%d %d", &x1, &x2);

printf("\nDigite o valor de y1 e y2: ");
scanf("%d %d", &y1, &y2);

distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

printf("\nA distancia entre os pontos e: %.2f\n", distancia);

    return 0;
}
// DCE05858 - Programa��o II (UFES)
// Escreva um programa em C que leia três números inteiros e imprimaos em ordem crescente. Para resolver, utilize apenas ifs aninhados
// (não use operadores lógicos como && ou ||, nem funções de ordenação).

#include <stdio.h>

int main(){

    int a, b, c;

    printf("Digite 3 numeros inteiros: ");
    scanf("%d %d %d", &a, &b, &c);

    if(a <= b){
        if(b <= c){
            printf("A ordem é %d %d %d", a, b, c); 
        }
        else{
            if(c <= a){
                printf("A ordem e %d %d %d", c, a, b); 
            } 
            else{
                printf("A ordem é %d %d %d", a, c, b);
            }
        }
    }
    else {
        if(a <= c){
            printf("A ordem é %d %d %d", b, a, c);
        }
        else{
            if(b <= c){
                printf("A ordem é %d %d %d", b, c, a);
            }
            else{
                printf("A ordem é %d %d %d", c, b, a);
            }
        }
    }
    
    return 0;
}

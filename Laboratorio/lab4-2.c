#include <stdio.h>
#include <stdlib.h>

int main(){

int num, cont =0;

printf("Digite um numero: \n");

do
{
    
    scanf("%d", &num);

    if(num == 7){
        
        num++;

    }
    else{
        
        if(num > 10){
            
            int resto;
            
            while(num != 0){
                
                resto = num % 10;
                if(resto  == 7){
                    
                    cont++;

                }

                num = num / 10;
            }

        }

    }

} while (num != -1);

printf("O numero 7 foi digitado %d vezes", cont);

    return 0;
}
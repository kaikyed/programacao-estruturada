// DCE05858 - Programação II (UFES)
#include <stdio.h>

int main(){

    int vet1[5] = {3,5,4,2,2};
    int vet2[5] = {7,15,20,0,18};

    int vet3[10];

    int i;

    for (i = 0; i < 5; i++)
    {

        vet3[i*2] = vet1[i];

        vet3[(i*2)+1] = vet2[i];


        
    }
    

    int vet3[10] = {vet1[0], vet2[0], vet1[1], vet2[1] , vet1[2], vet2[2] , vet1[3], vet2[3] , vet1[4], vet2[4]};

    for (i = 0; i < 10; i++)
    {
        printf("%d, \n ", vet3[i]);
    }
    



    return 0;
}

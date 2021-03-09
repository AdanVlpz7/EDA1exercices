#include <stdlib.h>
#include <stdio.h>

int main(){
    /*
    int arr[10];
    printf("Direccion de memoria de elementos del arreglo:\n");
    for(int i = 0; i < 10; i++){
        printf("%p\n",&arr[i]);
    }
    printf("La direccion del primer elemento es: %p\n",&arr[0]);
    printf("La direccion del arreglo es: %p",arr);
    */

    /*
    int arr2[3][3];
    for(int i = 0; i<3;i++){
        
        for(int j = 0; j < 3; j++){
            printf("%p \n",&arr2[i][j]);
        }
    }
    printf("\n");
    for(int i = 0; i<3;i++){
        
        for(int j = 0; j < 3; j++){
            printf("%p ",&arr2[i][j]);
        }
        printf("\n");
    }
    //la direccion de los renglones xd
    printf("\n La direccion del primer elemento del arreglo 3x3 es: %p\n", &arr2[0][0]);
    printf("La direccion del arreglo 3x3 es: %p",arr2);
    

    */
    int arr3[3][2][4];
    for(int i = 0; i < 3;i++){
        for(int j=0;j < 2; j++){
            for(int l=0; l<4; l++){
                printf("%p \n",&arr3[i][j][l]);
            }
        }
    }
    printf("\n");
    for(int i = 0; i < 3;i++){
        for(int j = 0;j < 2; j++){
            for(int l = 0; l<4; l++){
                printf("%p ",&arr3[i][j][l]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("La direccion del primer elemento del arreglo 3x2x4 es: %p\n", &arr3[0][0][0]);
    printf("La direccion del arreglo 3x2x4 es: %p",arr3);
    
}
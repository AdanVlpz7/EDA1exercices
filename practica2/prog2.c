#include <stdio.h>
#include <stdlib.h>

int main(){
    //a)
    int *ApuntadorInt;
    char *ApuntadorChar;
    double *ApuntadorDouble;
    long *ApuntadorLong;
    float *ApuntadorFloat;
    short *ApuntadorShort;

    //b)
    ApuntadorInt = (int*)malloc(sizeof(int));
    ApuntadorChar = (char*)malloc(sizeof(char));
    ApuntadorDouble = (double*)malloc(sizeof(double));
    ApuntadorLong = (long*)malloc(sizeof(long));
    ApuntadorFloat = (float*)malloc(sizeof(float));
    ApuntadorShort = (short*)malloc(sizeof(short));

    //c)
    printf("La direccion de memoria del apuntador a entero es: %p\n",&ApuntadorInt);
    printf("La direccion de memoria del apuntador a char es: %p\n",&ApuntadorChar);
    printf("La direccion de memoria del apuntador a double es: %p\n",&ApuntadorDouble);
    printf("La direccion de memoria del apuntador a long es: %p\n",&ApuntadorLong);
    printf("La direccion de memoria del apuntador a float es: %p\n",&ApuntadorFloat);
    printf("La direccion de memoria del apuntador a short es: %p\n",&ApuntadorShort);

    // Asignacion de valor a las varibales
    *ApuntadorInt = 94357;
    *ApuntadorChar = 'L';
    *ApuntadorDouble = 12346789.987654321; 
    *ApuntadorLong = -412748364877865423;
    *ApuntadorFloat = 1.574862;
    *ApuntadorShort = 7;

    printf("%d",*ApuntadorInt);
    
    //e)
    *ApuntadorInt = 1224;
    *ApuntadorChar = 'M';
    *ApuntadorDouble = 320012.3287621; 
    *ApuntadorLong = -144565423;
    *ApuntadorFloat = 7.777777;
    *ApuntadorShort = 4;
    
    //f)
    free(ApuntadorInt);
    free(ApuntadorChar);
    free(ApuntadorDouble);
    free(ApuntadorLong);
    free(ApuntadorFloat);
    free(ApuntadorShort);

}
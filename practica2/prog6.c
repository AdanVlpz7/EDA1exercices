#include <stdlib.h>
#include <stdio.h>

void suma(float a, float b, float *c){
    float x;
    x = a + b;
    c = &x;
    printf("%f",*c);
}
void resta(float a, float b, float* c){
    float x;
    x = a - b;
    c = &x;
    printf("%f",*c);
}
void multiplicacion(float a, float b, float* c){
    float x;
    x = a * b;
    c = &x;
    printf("%f",*c);
}
void division(float a, float b, float* c){
    float x;
    x = a / b;
    c = &x;
    printf("%f",*c);
}
int main(){
    float operando1 = 0;
    float operando2 = 0;
    float* resultado;
    int opcion = 0;

    printf("Bienvenido, ¿que operacion quiere realizar?\n");
    printf("1)Suma\n");
    printf("2)Resta\n");
    printf("3)Multiplicacion\n");
    printf("4)Division\n");
    scanf("%d",&opcion);
    switch(opcion){
        case 1:
            printf("\n¿Cual seria el valor del primer operando?\n");
            scanf("%f",&operando1);
            printf("\n¿Cual seria el valor del segundo operando?\n");
            scanf("%f",&operando2);
            suma(operando1,operando2,resultado);
            break;
        case 2:
            printf("\n¿Cual seria el valor del primer operando?\n");
            scanf("%f",&operando1);
            printf("\n¿Cual seria el valor del segundo operando?\n");
            scanf("%f",&operando2);
            resta(operando1,operando2,resultado);
            break;
        case 3:
            printf("\n¿Cual seria el valor del primer operando?\n");
            scanf("%f",&operando1);
            printf("\n¿Cual seria el valor del segundo operando?\n");
            scanf("%f",&operando2);
            multiplicacion(operando1,operando2,resultado);
            break;
        case 4:
            printf("\n¿Cual seria el valor del primer operando?\n");
            scanf("%f",&operando1);
            printf("\n¿Cual seria el valor del segundo operando?\n");
            scanf("%f",&operando2);
            division(operando1,operando2,resultado);
            break;        
    }
    
}
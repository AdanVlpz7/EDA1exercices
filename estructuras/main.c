#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructura.h"
int main(){
    alumno a1,a2;
    char dato[100];

    a1 = crear_alumno();
    printf("Ingresa el nombre del alumno: \n");
    scanf("%s",&dato);
    strcpy(a1.nombre,dato);
    strcpy(dato,"");//para limpiar el arreglo
    
    printf("Ingresa el apellido paterno del alumno: \n");
    scanf("%s",&dato);
    strcpy(a1.apaterno,dato);
    strcpy(dato,"");//para limpiar el arreglo
    
    printf("Ingresa el apellido materno del alumno: \n");
    scanf("%s",&dato);
    strcpy(a1.amaterno,dato);
    strcpy(dato,"");//para limpiar el arreglo

    printf("Ingresa el numero de cuenta del alumno: \n");
    scanf("%s",&dato);
    strcpy(a1.noCuenta,dato);
    strcpy(dato,"");//para limpiar el arreglo        

    printf("Ingresa el semestre del alumno: \n");
    scanf("%d",&a1.semestre);

    printf("Ingresa el promedio y edad del alumno: \n");
    scanf("%f",&a1.promedio);
    
    printf("Ingresa la edad del alumno: \n");
    scanf("%f",&a1.edad);

    printf("Ingresa la carrera del alumno: \n");
    scanf("%s",&dato);
    strcpy(a1.carrera,dato);
    strcpy(dato,"");//para limpiar el arreglo

    imprimir(a1);
    liberar_alumno(&a1);

    return 0;
}
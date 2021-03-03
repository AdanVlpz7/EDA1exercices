/*
         CLASE DE 03/03/21
    Miguel Adán Vargas López
*/
#include "estructura.h"
#include <string.h>
#include <stdlib.h>

alumno crear_alumno(){
    alumno a;
    a.nombre = (char*)malloc(sizeof(char));
    a.apaterno = (char*)malloc(sizeof(char));
    a.amaterno = (char*)malloc(sizeof(char));
    a.promedio = 0.0f;
    a.edad = 0.0f;
    return a;
}

void liberar_alumno(alumno *a){
    //cuando el tipo estructurado es apuntador, usamos flecha
    free(a->nombre);
    free(a->apaterno);
    free(a->amaterno);
}
void imprimir(alumno a){
    printf("Nombre: %s\n A.Paterno: %s\nA.Materno: %s\n",a.nombre,a.apaterno,a.amaterno);
    printf("Semestre: %d\nPromedio: %f\nEdad: %f\n",a.semestre,a.promedio,a.edad);
    printf("No.de Cuenta: %s\nCarrera: %s\n",a.noCuenta,a.carrera);
}
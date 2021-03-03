/*
         CLASE DE 03/03/21
    Miguel Adán Vargas López
# -> establece directivas de procesador
la estructura es un tipo de dato definido por el usuario.
una estructura puede obtener diferentes tipos de datos
*/
#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

#include <stdio.h>

struct _alumno{
    //toda esta informacion se va a guardar en struct alumno
    char* nombre; //los hacemos apuntadores por que no sabemos el tamaño 
    char* apaterno;
    char* amaterno;
    char noCuenta[9];
    int semestre;
    float promedio;
    float edad;
    char carrera[3];
};
    //TYPEDEF define un alias para un tipo de dato
    //para no llamar struct alumno para definir una variable
    //si no decir ALUMNO variable;
    typedef struct _alumno alumno;
    
    //struct alumno a1;
    //alumno a1;

    alumno crear_alumno();
    void liberar_alumno(alumno *a);
    void imprimir(alumno a);
    
    
#endif
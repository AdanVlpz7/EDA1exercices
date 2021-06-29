#include "polinomio.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    LIST* l = new_list();
    insertar_inicio(l,4,1);
    insertar_inicio(l,2,4);
    insertar_inicio(l,3,-1);
    insertar_fin(l,6,-5);
    imprimir_lista(l);
    eliminarFin(l);
    imprimir_lista(l);
    eliminarPorPosicion(l,1);
    imprimir_lista(l);
    printf("%d",localizar(l,3,-1));
}
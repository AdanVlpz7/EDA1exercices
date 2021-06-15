#include <stdio.h>
#include <stdlib.h>
#include "listaligada.h"

/*
 * 
 */
int main(int argc, char** argv) {
    LIST *l1, l2;

    l1 = new_list();

    l2.head = l2.tail = NULL;
    l2.num = 0;

    insert(l1,0,0);
    insert(l1,5,0);
    insert(l1,10,0);
    insert(l1,5,1);
    insert(l1,2,2);
    insert(l1,4,0);

    int p = localizar(l1, 3);
    printf("Pos = %d\n", p);
    
    p = localizar(l1, -5);
    printf("Pos = %d\n", p);
    
    DATA *info = buscar(l1, 2);
    printf("Info = %d\n", *info);

    insert(&l2,1,0);
    insert(&l2,2,0);
    insert(&l2,3,0);
    eliminarPorPosicion(l1,2);
    imprimir_lista(l1);
    imprimir_lista(&l2);

    vaciar(l1);
    vaciar(&l2);

    return (EXIT_SUCCESS);
}
#include "polinomio.h"
#include <stdio.h>
#include <stdlib.h>

// crear nodo
NODE* new_node(DATA grado, DATA coeficiente){
   NODE* t = (NODE*)malloc(sizeof(NODE));
    t->siguiente = NULL;
    t->grado = grado;
    t->coeficiente = coeficiente;
    return t;
} 

//eliminar nodo
void free_node(NODE *n){
    if(n->siguiente == NULL){
        free(n);
        n = NULL;
    }
} 
//crear lista
LIST* new_list(){
    LIST* l = (LIST*)malloc(sizeof(LIST));
    l->head = l->tail = NULL;
    l->num = 0;
    return l;
} 

//para verificar si la lista esta vacia.
bool is_empty(LIST *l){
    if(l->head == l->tail && l->tail == NULL)
        return true;
    else
        return false;
}

bool insert(LIST *l, DATA grado, DATA coeficiente, int pos){
    if(pos == 0) return insertar_inicio(l, grado,coeficiente);
    else if(pos ==l->num) return insertar_fin(l, grado,coeficiente);
    else if(pos>0 && pos < l->num){
        NODE* nuevo = new_node(grado,coeficiente);
        NODE* temporal = l->head;
        for(int tpos = 0; tpos < pos-1; tpos++) 
            temporal = temporal->siguiente;
        nuevo->siguiente = temporal->siguiente;                
        temporal->siguiente = nuevo;
        l->num++;
        return true;
    }
    return false;
}

bool insertar_inicio(LIST *l,DATA grado, DATA coeficiente){
    NODE* nuevo = new_node(grado,coeficiente);
    if(l->head == NULL && l->tail==NULL){
        l->head = l->tail = nuevo; // l->head = nuevo; l->tail = nuevo;
        l->num++;
        return true;
    }else{
        nuevo->siguiente = l->head;
        l->head = nuevo;
        l->num++;
        return true;
    }
    return false;
}

bool insertar_fin(LIST *l,DATA grado, DATA coeficiente){
    NODE* nuevo = new_node(grado,coeficiente);
    if(l->head == NULL && l->tail==NULL){
        l->head = l->tail = nuevo; // l->head = nuevo; l->tail = nuevo;
        l->num++;
        return true;
    }else{
        l->tail->siguiente = nuevo;
        l->tail = nuevo;// l->tail = l->tail->sig;
        l->num++;
        return true;
    }
    return false;
}
bool vaciar(LIST *l){
    if(is_empty(l)) return false;
    NODE* temporal = l->head;
    while(temporal !=NULL){
        l->head = temporal->siguiente;
        free(temporal);
        temporal = l->head;
    }
    l->head = l->tail = NULL;
    l->num = 0;
    return true;
}

void eliminarInicio(LIST *l){
    //si la lista ya esta vacia no podemos cambiar nada
    if(is_empty(l)) return;
    NODE *temporal = l->head;
    l->head = l->head->siguiente;
    temporal->siguiente = NULL;
    free_node(temporal);
    l->num--;
}

void eliminarFin(LIST *l){
    //si la lista ya esta vacia no podemos cambiar nada
    if(is_empty(l)) return;
    NODE *temporal;
    //instrucción vacía que solo recorre el temporal hasta el anterior a tail.
    for(temporal = l->head; temporal->siguiente!=l->tail;temporal = temporal->siguiente);
    temporal->siguiente = NULL;
    free_node(l->tail);
    l->tail = temporal;
    l->num--;
}
void eliminarPorPosicion(LIST *l, int pos){
    if(pos==0) eliminarInicio(l);
    else if(pos == l->num-1) eliminarFin(l);
    else if(pos > 0 && pos < l->num-1){
        NODE *temporal = l->head, *temporal2;
        for(int i = 0; i < pos - 1; i++){
            temporal = temporal->siguiente;
        }
        temporal2 = temporal->siguiente;
        temporal->siguiente = temporal->siguiente->siguiente;
        temporal2->siguiente = NULL;
        free_node(temporal2);
        l->num--;
    }
}

DATA* buscar(LIST* l, int pos){
    if(is_empty(l)) return NULL;
    if(pos == 0) {
        return &l->head->coeficiente;
        return &l->head->grado;
    }
    if(pos == l->num-1) {
        return &l->tail->coeficiente;
        return &l->tail->grado;
    }
    if(pos > 0 && pos < (l->num-1)){
        NODE *temporal = l->head;
        for(int i = 0; i < pos; i++){
            temporal = temporal->siguiente;
        } 
        return &temporal->grado;
        return &temporal->coeficiente;
    }
}

int localizar(LIST *l, DATA grado, DATA coeficiente){
    if(is_empty(l)) return -1;
    NODE *temporal = l->head;
    int pos = 0;
    while(temporal != NULL){
        if(comparar(temporal->grado, grado) && comparar(temporal->coeficiente,coeficiente)) return pos;
        pos++;
        temporal = temporal->siguiente;
    }
    return -1;
}
bool comparar(DATA info1, DATA info2){
    if(info1 == info2) return true;
    else return false;
}
void imprimir_lista(LIST *l){
    for(NODE* t = l->head;t != NULL; t = t->siguiente){
        if(t->coeficiente > 0)
            printf("+");
        printf("%dx^%d ", t->coeficiente, t->grado);
        
    }
    printf("\n");
}
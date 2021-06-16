/*
    * author: Adán Vargas
    * date : 15/06/21
*/
#include "circular_list.h"
#include <stdio.h>
#include <stdlib.h>

// crear nodo
NODE* new_node(DATA info){
   NODE* t = (NODE*)malloc(sizeof(NODE));
    t->siguiente = NULL;
    t->info = info;
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

bool insert(LIST *l, DATA info, int pos){
    if(pos == 0) return insertar_inicio(l, info);
    else if(pos ==l->num) return insertar_fin(l, info);
    else if(pos>0 && pos < l->num){
        NODE* nuevo = new_node(info);
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

bool insertar_inicio(LIST *l, DATA info){
    NODE* nuevo = new_node(info);
    nuevo->siguiente = l->head;
    l->head = nuevo;
    l->tail->siguiente = l->head;
    l->num++;
    return true;
    /*if(l->head == NULL && l->tail==NULL){
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
    */
}

bool insertar_fin(LIST *l, DATA info){
    NODE* nuevo = new_node(info);
    l->tail->siguiente = nuevo;
    l->tail = nuevo;
    return true;
    /*if(l->head == NULL && l->tail==NULL){
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
    */
}
bool vaciar(LIST *l){
    if(is_empty(l)) return false;
    NODE* temporal = l->head;    
    l->tail->siguiente = l->head;
    while(temporal != NULL)
    {
        l->head = l->head->siguiente;
        temporal->siguiente = NULL;
        free_node(temporal);
        temporal = l->head;
    }
    return true;
}

void eliminarInicio(LIST *l){
    //si la lista ya esta vacia no podemos cambiar nada
    if(is_empty(l)) return;
    NODE *temporal = l->head;
    l->head = l->head->siguiente;
    temporal->siguiente = NULL;
    free_node(temporal);
    l->tail->siguiente = l->head;
    l->num--;
}

void eliminarFin(LIST *l){
    //si la lista ya esta vacia no podemos cambiar nada
    if(is_empty(l)) return;
    NODE *temporal;
    //instrucción vacía que solo recorre el temporal hasta el anterior a tail.
    for(temporal = l->head; temporal->siguiente!=l->tail;temporal = temporal->siguiente);
    temporal->siguiente = l->head;
    l->tail = NULL;
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
    if(pos == 0) return &l->head->info;
    if(pos == l->num-1) return &l->tail->info;
    if(pos > 0 && pos < (l->num-1)){
        NODE *temporal = l->head;
        for(int i = 0; i < pos; i++){
            temporal = temporal->siguiente;
        } 
        return &temporal->info;
    }
}

int localizar(LIST *l, DATA info){
    if(is_empty(l)) return -1;
    NODE *temporal = l->head;
    int pos = 0;
    l->tail->siguiente -> NULL;
    while(temporal != NULL){
        if(comparar(temporal->info, info)) {
            l->tail->siguiente = l->head;
            return pos;
        }
        pos++;
        temporal = temporal->siguiente;
    }
    l->tail->siguiente = l->head;
    return -1;
}
bool comparar(DATA info1, DATA info2){
    if(info1 == info2) return true;
    else return false;
}
void imprimir_lista(LIST *l){
    for(NODE* t = l->head;t != l->tail; t = t->siguiente){
        printf("%d ->", t->info);
    }
    //por que el for llega hasta tail pero no lo va a imprimir
    printf("%d ->", l->tail->info);
    printf("\n");
}
#include "circular_dlinkedList.h"
#include <stdlib.h>

DNODO *crear_nodo(INFO info){
    DNODO* nodo = (DNODO*)malloc(sizeof(DNODO));
    nodo->info = info;
    nodo->sig = nodo->ant = NULL;
}
void eliminar_nodo(DNODO *n){
    if(n->sig == NULL && n->ant == NULL){
        free(n);
        n = NULL;
    }
}

bool insertar_inicio(DLISTA *l, INFO info){
    nodo* nuevo = crear_nodo(info);
    nuevo->sig = l->head;
    l->head->ant = nuevo;
    l->head = nuevo;
    l->head->ant = l->tail;
    l->tail->sig = l->head;
    l->num++;
    return true;
}
bool insertar_fin(DLISTA *l, INFO info){
    DNODO* nuevo = crear_nodo(info);
    l->tail->sig = nuevo;
    nuevo->ant = l->tail;
    l->tail = nuevo;
    l->tail->sig = l->head;
    l->head->ant = l->tail;
    l->num++;
    return true;
}
bool insertar(DLISTA* l, INFO info, int pos){
    if(es_vacia(l)){
        DNODO* nuevo = crear_nodo(info);
        l->head=l->tail = nuevo;
        l->num++;
        return true;
    }
    if(pos==0) return insertar_inicio(l,info);
    else if(pos==l->num) return insertar_fin(l,info);
    else if(pos > 0 && pos < l->num){
        DNODO *nuevo = crear_nodo(info);
        DNODO *temporal = l->head;
        for(int tpos = 0;tpos < pos-1; tpos++){
            temporal = temporal->sig;
        }
        nuevo->sig = temporal->sig;
        nuevo->ant = temporal->ant;
        temporal->sig = nuevo;
        l->num++;
        return true;
    }
    return false;
}

bool es_vacia(DLISTA *l){
    if(l->head == NULL && l->tail == NULL) return true;
    return false;
}

void eliminar_lista(DLISTA *l){
    if(l==NULL) return;
    vaciar(l);
    free(l);
    l = NULL;
}
bool vaciar(DLISTA *l){
    if(es_vacia(l)) return true;
    DNODO *temporal = l->head;
    while(temporal != NULL){
        l->head = temporal->sig;
        temporal->sig = NULL;
        l->head->ant = NULL;
        free(temporal);
        temporal = l->head;
    }
    l->head = l->tail = NULL;
    l->num = 0;
    return true;
}
void imprimir_lista(DLISTA *l){
    l->tail->sig = NULL;
    for(DNODO* t = l->head; t != NULL; t = t->sig){
        printf("%d ->", t->info);
    }
    printf("\n");
    l->tail->sig = l->head;
}

void eliminar_inicio(DLISTA *l){
    if(es_vacia(l)) return;
    //DNODO *temporal = l->head;
    l->head = l->head->sig;
    l->head->ant->sig = NULL;
    l->head->ant->ant = NULL;
    eliminar_nodo(l->head->ant)
    l->head->ant = l->tail;
    l->tail->sig = l->head;
    l->num--;
}

void eliminar_fin(DLISTA *l){
    if(es_vacia(l)) return;
    //DNODO *temporal = l->tail;
    l->tail = l->tail->ant;
    l->tail->sig->ant = NULL;
    l->tail->sig->sig = NULL;
    //temporal->ant = NULL;
    eliminar_nodo(l->tail->sig);
    l->tail->sig = l->head;
    l->head->ant = l->tail;
    l->num--;
}

void eliminar(DLISTA *l, int pos){
    if(pos == 0) eliminar_inicio(l);
    else if(pos == l->num-1) eliminar_fin(l);
    else if(pos > 0 && pos < (l->num-1)){
        DNODO *temporal = l->head;
        for(int i = 0; i < pos - 1; i++){
            temporal = temporal->sig;
        }
        temporal->ant->sig = temporal->sig;
        temporal->sig->ant = temporal->ant;
        temporal->sig = temporal ->ant = NULL;
        eliminar_nodo(temporal);
        l->num--;
    }
}

INFO* buscar(DLISTA* l,int pos){
    if(es_vacia(l)) return NULL;
    if(pos == 0) return &l->head->info;
    if(pos == l->num-1) return &l->tail->info;
    if(pos > 0 && pos < (l->num-1)){
        DNODO *temporal = l->head;
        for(int i = 0; i < pos; i++){
            temporal = temporal->sig;
        }
        return &temporal->info;
    }
}
int localizar(DLISTA *l, INFO info){
    if(es_vacia(l)) return -1;
    DNODO *temporal = l->head;
    int pos = 0;
    l->tail->sig = NULL;
    while(temporal != NULL){
        if(comparar(temporal->info),info)) {
            l->tail->sig = l->head;
            return pos;
        }
        pos++;
        temporal = temporal->sig;
    }
    l->tail->sig = l->head;
    return -1;
}
bool comparar(INFO info1, INFO info2){
    if(info1 == info2) return true;
    return false;
}
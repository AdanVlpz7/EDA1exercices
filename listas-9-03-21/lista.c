#include "lista.h"
#include <stdio.h>


LISTA crear_lista(){
    LISTA l;
    //le fijamos valores al primer y ultimo elemento
    //asi podemos verificar si se ha modificado/esta vacia la lista
    l.primero = -1;
    l.ultimo = -1;
    return l;
}
//funcion usada en localizar, para determinar si un dato esta o no en la lista
bool comparar_nodos(NODO n1,NODO n2){
    if(n1.c == n2.c && n1.x == n2.x && n1.y == n2.y)
        return true;
    return false;
}
//inserta un dato en una posicion p+1
bool insertar(LISTA l, NODO x, int p){
    
    //caso en el que la lista esta vacia
    if(es_vacia(l)){
        l.datos[0] = x;
        l.primero = l.ultimo = 0;
        return true;
    }

    //en el caso que p es el ultimo
    if(p == l.ultimo){
        l.datos[p+1] = x;
        l.ultimo++;
        return true;
    }

    //en el caso que p no es el ultimo
    for(int i = l.ultimo; i >= 0; i--){
        l.datos[i+1] = l.datos[i];
    }
    l.datos[p+1]=x;
    l.ultimo++;
    return true;

    //en el caso que la lista este llena
    if(l.ultimo == NUM_ELEM - 1){
        printf("\nLa lista ya esta llena brou");
        return false;
    }
} 

//devuelve la posicion de x
int localizar(LISTA l, NODO x){
    if(es_vacia(l)){
        printf("\nLa lista esta vacia");
        return -1;
    }

    for(int i = 0; i <= l.ultimo; i++){
        if(comparar_nodos(x,l.datos[i])) return i;
    }

    printf("\nEl dato ingresado no existe en la lista");
    return -1;
}

//devuelve un elemento en posicion p
int recuperar(LISTA l, int p){
    NODO a;
    if(es_vacia(l)){ 
        printf("La lista esta vacia");
        return a;
    } 
    if(p >= 0 && p < NUM_ELEM && p <= l.ultimo){
        return l.datos[p];
    }
    else{
        printf("\nLa posicion indicada es invalida/sale fuera del rango.");
    }

}

//elimina el elemento que se encuentra en p
bool suprimir(LISTA l, int p){

}

//devuelve la posicion siguiente a p
int siguiente(LISTA l, int p){
    if(p>=0 && p <l.ultimo) return p++;
    if(p == l.ultimo){
        printf("ya es el ultimo elemento. \n");
        return -1;
    }
    return -1;
}

//devuelve la posicion anterior a p
int anterior(LISTA l, int p){
    if(p>l.primero && p <l.ultimo) return p;
    if(p == l.primero){
        printf("ya es el ultimo elemento. \n");
        return -1;
    }
    return -1;
}

//para vaciar la lista
bool anular(LISTA l){
    if(l.primero == -1 && l.ultimo == -1){
        //si esto se cumple es por que ya esta vacia
        return false;
    }
    //sabemos que una lista esta vacia cuando el primero y ultimo no apuntan a ningun elemento
    l.primero = -1;
    l.ultimo = -1;
    return true;//devolvemos true por que si se puede vaciar
}

//determinar si la lista esta vacia
bool es_vacia(LISTA l){
    if(l.primero == -1 && l.ultimo == -1)
        return true;
    return false;

}

//devuelve la posicion del elemento l
int primero(LISTA l){
    return l.primero;
}

int ultimo(LISTA l){
    return l.ultimo;
}
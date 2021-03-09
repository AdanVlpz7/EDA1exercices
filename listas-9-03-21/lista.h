/*
    * Author: Adanvlpz
    * Created on march 9, 2021

*/

#ifndef LISTA_H
#define LISTA_H
#include <stdbool.h>
#define NUM_ELEM 100
struct _nodo_lista{
    int x;
    float y;
    char c;
};

typedef _nodo_lista NODO;

bool comparar_nodos(NODO n1,NODO n2);

struct _lista{
    NODO datos[100];
    int primero;
    int ultimo;
}

typedef struct _lista LISTA;


/*
    ++ PROTOTIPOS ++
    funciones definidas por operaciones con listas
*/
//esta funcion va a devolver verdadero si puede insertar
bool insertar(LISTA l, NODO x, int p); 

//devuelve la posicion de x
int localizar(LISTA l, NODO x);

//devuelve un elemento en posicion p
int recuperar(LISTA l, int p);

//elimina el elemento que se encuentra en p
bool suprimir(LISTA l, int p);

//devuelve la posicion siguiente a p
int siguiente(LISTA l, int p);

//devuelve la posicion anterior a p
int anterior(LISTA l, int p);

//para vaciar la lista
bool anular(LISTA l);

//determinar si la lista esta vacia
bool es_vacia(LISTA l);

//devuelve la posicion del elemento l
int primero(LISTA l);

int ultimo(Lista l);
#endif /* LISTA_H */
/*
    * author: Adán Vargas
    * date : 10/03/21
*/
#ifndef POLINOMIO_H
#define POLINOMIO_H
#include <stdbool.h>

typedef struct _node NODE;
typedef int DATA;

struct _node{
    DATA grado; // la información del nodo
    DATA coeficiente;
    NODE *siguiente; //el apuntador al elemento sig. de la lista
};

typedef struct _list LIST;

struct _list{ 
    NODE *head;
    NODE *tail;
    int num;
};

NODE *new_node(DATA grado, DATA coeficiente); // crear nodo
void free_node(NODE *n); //eliminar nodo

LIST *new_list(); //crear lista
bool insertar_inicio(LIST *l, DATA grado, DATA coeficiente);
bool insertar_fin(LIST *l, DATA grado, DATA coeficiente);
bool insert(LIST* l, DATA grado, DATA coeficiente, int pos);

bool is_empty(LIST *l);
bool vaciar(LIST *l);

void imprimir_lista(LIST *l);
void eliminarInicio(LIST *l);
void eliminarFin(LIST *l);
void eliminarPorPosicion(LIST *l, int pos);
DATA* buscar(LIST* l, int pos);
int localizar(LIST *l,DATA grado, DATA coeficiente);
bool comparar(DATA info1, DATA info2);
#endif
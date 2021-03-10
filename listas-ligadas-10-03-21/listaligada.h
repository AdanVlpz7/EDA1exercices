/*
    * author: Adán Vargas
    * date : 10/03/21
*/
#ifndef LISTALIGADA_H
#define LISTALIGADA_H
#include <stdbool.h>

struct _DATA{
    int x;
};
typedef struct _DATA DATA;

typedef struct _node NODE;

struct _node{
    DATA info; // la información del nodo
    NODE *siguiente; //el apuntador al elemento sig. de la lista
};

struct _list{ 
    NODE *head;
    NODE *tail;
    int num;
};

typedef struct _list LIST;

NODE *new_node(DATA info); // crear nodo
void free_node(NODE *n); //eliminar nodo

LIST* new_list(); //crear lista
void free_list(LIST *l); //liberar lista

bool is_empty(LIST *l);
bool insert(LIST *l, DATA info, int p);
#endif
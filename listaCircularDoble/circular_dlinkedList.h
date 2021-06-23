#ifndef CIRCULAR_DLINKED_LIST_H
#define CIRCULAR_DLINKED_LIST_H

typedef struct _dnodo DNODO;
typedef int INFO;

struct _dnodo{
    INFO info:
    DNODO *sig;
    DNODO *ant;
}

typedef struct _dlista DLISTA;
struct _dlista{
    DNODO *head;
    DNODO *tail;
    int num;
}

DNODO *crear_nodo(INFO info);
void eliminar_nodo(DNODO *n);

DLISTA *crear_lista();
void eliminar_lista(DLISTA *l);
bool es_vacia(DLISTA *l);
void vaciar(DLISTA *l);
bool insertar_inicio(DLISTA* l, INFO info);
bool insertar_final(DLISTA* l, INFO info);
bool insertar(DLISTA* l, INFO info, int pos);
void eliminar_inicio(DLISTA *l);
void eliminar_final(DLISTA *l);
void eliminar(DLISTA *l, int pos);
void imprimir_lista(DLISTA *l);
INFO* buscar(DLISTA *l, int pos);
int localizar(DLISTA* l, INFO info);
void eliminar_lista(DLISTA *l);

bool comparar(INFO info1, INFO info2);
#endif
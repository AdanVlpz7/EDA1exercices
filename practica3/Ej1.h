#ifndef EJ1_H
#define EJ1_H
// aqui tenia algo asi
struct _NUM_COMPLEJOS{
  
    float real;
    float complejo;
    //char c;
};

typedef struct _NUM_COMPLEJOS COMPLEJO;

void suma(COMPLEJO *t1, COMPLEJO *t2, COMPLEJO* resultado);
void multiplicacion(COMPLEJO *t1, COMPLEJO *t2, COMPLEJO* resultado);
void imprimir(COMPLEJO c1);
#endif
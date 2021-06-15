/*
    Author: Adán Vargas
    Date: 17/03/21
*/
void delete(LIST *l,int p){
    NODE *temporal = NULL;
    
    if (p == 0){
        temporal = l->head;
        l->head = l->head->siguiente;
        temporal->siguiente = NULL;
        free_node(temporal);
        l->num--;
    }

    else if(p == l->num-1){
        for(temporal = l->head; temporal->siguiente!=l->tail; temporal = temporal->siguiente);
        l->tail = temporal;
        temporal = temporal->siguiente;
        l->tail->siguiente = NULL;
        free_node(temporal);
        l->num--;
    }

    else if(p < l->num && p > 1){
        NODE *anterior = NULL;

        for(int i = 0;i < p-1;i++){
            anterior = anterior->siguiente;
        }
        for(int i = 0; i < p;i++){
            temporal = temporal->siguiente;
        }

        anterior->siguiente = temporal->siguiente;
        temporal->siguiente = NULL;
        free_node(temporal);
        l->num--;
    } 
    else{
        printf("la posicion no es valida");
    }
}
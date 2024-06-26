#include <stdlib.h>
#include "nodo_se.h"

nodo_se* crearNodo(nodo_se* nuevo, int elem)
{
    nuevo = (nodo_se *)malloc(sizeof(nodo_se));
    nuevo->next = NULL;
    nuevo->dato = elem;
    return nuevo;
}
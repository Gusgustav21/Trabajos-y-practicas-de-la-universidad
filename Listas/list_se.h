#ifndef  LIST_SE
#define LIST_SE

#include "nodo_se.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct list_se
{
    nodo_se *prin;
    int elements;
}list_se;

void lse_crear(list_se *list);
void lse_insertar_inicio(list_se *list, int elem);
void lse_insertar_final(list_se *list, int elem);
void lse_insertar_en(list_se *list, int elem, int pos);
void lse_quitar_inicio(list_se *list);
void lse_quitar_final(list_se *list);
void lse_quitar_en(list_se *list, int pos);
int lse_consultar_inicio(list_se *list);
int lse_consultar_final(list_se *list);
int lse_consultar_en(list_se *list, int pos);
void lse_vaciar(list_se *list);
void lse_mostrar_lista(list_se *list);


 #endif
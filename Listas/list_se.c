#include "list_se.h"
#include "nodo_se.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void lse_crear(list_se *list)
{
    list = (list_se *)malloc(sizeof(list_se));
    list->prin = NULL;
    list->elements = 0;
}

void lse_insertar_inicio(list_se *list, int elem)
{
    nodo_se *nuevo_nodo = crearNodo(nuevo_nodo, elem);
    nuevo_nodo->next = list->prin;
    list->prin = nuevo_nodo;
    list->elements++;
}

//La lista debe de tener al menos un elemento
void lse_insertar_final(list_se *list, int elem)
{
    nodo_se *aux;
    nodo_se *nuevo_nodo = crearNodo(nuevo_nodo, elem);
    aux = list->prin;
    while(aux->next != NULL)
    {
        aux = aux->next;
    }
    aux->next = nuevo_nodo;
    list->elements++;
    free(aux);
}


void lse_insertar_en(list_se *list, int elem, int pos)
{
    if(pos >= list->elements + 1)
    {
        lse_insertar_final(list, elem);
    }else
    {
    
        if(pos <= 1)
        {
            lse_insertar_inicio(list, elem);
        }else
        {
            int i;
            nodo_se *nuevo_nodo = crearNodo(nuevo_nodo, elem), *aux;
            aux = list->prin;
            for(i = 1; i < pos; i++)
            {
                aux = aux->next;
            }
            nuevo_nodo->next = aux->next;
            aux->next = nuevo_nodo;
            list->elements++;
            free(aux);
        }
    }

}


void lse_quitar_inicio(list_se *list)
{
    nodo_se *quit_nodo = list->prin;
    if(quit_nodo == NULL)
    {
        printf("La lista está vacía\n\n");
        free(quit_nodo);
        return;
    }

    list->prin = quit_nodo->next;
    quit_nodo->next = NULL;
    free(quit_nodo);
    list->elements--;
}


void lse_quitar_final(list_se *list)
{
    nodo_se *quit_nodo = list->prin;
    if(quit_nodo == NULL)
    {
        printf("La lista está vacía\n\n");
        free(quit_nodo);
        return;
    }

    nodo_se *aux;
    while(quit_nodo->next != NULL)
    {
        aux = quit_nodo;
        quit_nodo = quit_nodo->next;
    }
    aux->next = NULL;
    quit_nodo->next = NULL;
    free(quit_nodo);
    list->elements--;
}


void lse_quitar_en(list_se *list, int pos)
{
    if(pos <= 1)
    {
        lse_quitar_inicio(list);
    }else
    {
        if(pos >= list->elements)
        {
            lse_quitar_final(list);
        }else
        {
            int i;
            nodo_se *quit_nodo = list->prin;
            nodo_se *aux;
            for(i = 1; i < pos; i++)
            {
                aux = quit_nodo;
                quit_nodo = quit_nodo->next;
            }
            aux->next = quit_nodo->next;
            quit_nodo->next = NULL;
            free(quit_nodo);
            list->elements--;
        }
    }
}


int lse_consultar_inicio(list_se *list)
{
    if(list->prin == NULL)
    {
        printf("Lista vacia");
        return -1;
    }
    
    return list->prin->dato;
}


int lse_consultar_final(list_se *list)
{
    if(list->prin == NULL)
    {
        printf("Lista vacia");
        return -1;
    }

    nodo_se *aux = list->prin;
    while(aux->next != NULL)
    {
        aux = aux->next;
    }

    return aux->dato;
}


int lse_consultar_en(list_se *list, int pos)
{
    if(list->prin == NULL)
    {
        printf("Lista vacia");
        return -1;
    }

    if(pos <= 1)
    {
        return lse_consultar_inicio(list);
    }else
    {
        if(pos >= list->elements)
        {
            return lse_consultar_final(list);
        }else
        {
            int i;
            nodo_se *aux = list->prin;
            for(i = 1; i < pos; i++)
            {
                aux = aux->next;
            }

            return aux->dato;
        }
    }
}


void lse_vaciar(list_se *list)
{
    nodo_se *aux1;
    while(list->prin != NULL)
    {
        aux1 = list->prin;
        free(list->prin);
        list->prin = aux1;
    }
    free(aux1);
    list->elements = 0;
}


void lse_mostrar_lista(list_se *list)
{
    if(list->prin == NULL)
    {
        printf("Lista vacia");
        return;
    }

    nodo_se *aux = list->prin;
    int i;
    for(i = 1; i <= list->elements; i++)
    {
        printf("| %i ", aux->dato);
        aux = aux->next;
    }
    printf("|\n\n");
}
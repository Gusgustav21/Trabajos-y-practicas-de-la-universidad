#include <stdio.h>
#include "list_se.h"

int main()
{
    int indice;
    list_se *lista = NULL;

    lse_crear(lista);
    for(indice = 1; indice <= 10; indice++)
    {
        lse_insertar_final(lista, indice);
    }
    lse_mostrar_lista(lista);

    lse_insertar_inicio(lista, 1);
    lse_mostrar_lista(lista);

    lse_insertar_en(lista, 16, 7);
    lse_mostrar_lista(lista);

    lse_quitar_final(lista);
    lse_mostrar_lista(lista);
    
    lse_quitar_inicio(lista);
    lse_mostrar_lista(lista);
    
    lse_quitar_en(lista, 5);
    lse_mostrar_lista(lista);
    
    printf("%i\n\n", lse_consultar_final(lista));

    printf("%i\n\n", lse_consultar_inicio(lista));

    printf("%i\n\n", lse_consultar_en(lista, 7));

    lse_vaciar(lista);
    lse_mostrar_lista(lista);

    return 0;
}
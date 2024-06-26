#include <stdio.h>
#include "list_se.h"

int main()
{
    int indice = 8;
    list_se lista;

    lse_crear(&lista);
    
    for(indice; indice >= 1; indice--)
    {
        lse_insertar_inicio(&lista, indice);
    }
    lse_mostrar_lista(&lista);

    lse_insertar_final(&lista, 11);
    lse_mostrar_lista(&lista);

    lse_insertar_en(&lista, 16, 7);
    lse_mostrar_lista(&lista);

    lse_quitar_final(&lista);
    lse_mostrar_lista(&lista);
    
    lse_quitar_inicio(&lista);
    lse_mostrar_lista(&lista);
    
    lse_quitar_en(&lista, 5);
    lse_mostrar_lista(&lista);
    
    int i,j,k;

    i = lse_consultar_final(&lista);
    j = lse_consultar_inicio(&lista);
    k = lse_consultar_en(&lista, 7);

    printf("%i\n\n", i);

    printf("%i\n\n", j);

    printf("%i\n\n", k);

    lse_vaciar(&lista);
    lse_mostrar_lista(&lista);



    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANT 20

int main()
{
    EPersona listaPesonas[CANT];
    inicializarisEmpty(listaPesonas, CANT);

    char seguir='s';
    int opcion=0;

    do
        {
        system("cls");

        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
            case 1:
                agregarPersona(listaPesonas,CANT);
                break;
            case 2:
                borrarPersona(listaPesonas,CANT);
                break;
            case 3:
                ordenarPersona(listaPesonas,CANT);
                break;
            case 4:
                graficar(listaPesonas,CANT);
                break;
            case 5:
                seguir = 'n';
                break;
            default: printf("Error. Ingresa numero de 1 a 5\a");

        }
        system("pause");
    }    while(seguir=='s');


    return 0;
}

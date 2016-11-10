#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANT 5


int main()
{
    EMovie listaPeliculas[CANT];
    inicalizarIsempty(listaPeliculas, CANT);
    leerArchivo(listaPeliculas, CANT);

    char seguir='s';
    int opcion=0;

   do
    {
        system("cls");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
            case 1:
                agregarPelicula(listaPeliculas,CANT);
                break;
            case 2:
                borrarPelicula(listaPeliculas,CANT);
                break;
            case 3:
                modificarPelicula(listaPeliculas,CANT);
               break;
            case 4: listar(listaPeliculas, CANT);
               break;
            case 5:
                seguir = 'n';
                break;
                default:printf("Ingrese opciones de 1 a 5");
        }
        system("pause");
    } while(seguir=='s');

    return 0;
}

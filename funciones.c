#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "validar.h"

/** \brief Inicializa el Array
 *
 * \param  lista recibe el array
 * \param largo el largo del array
 * \return retorna [0] si se inicializo o [-1] en caso de algun error
 *
 */

int inicalizarIsempty(EMovie lista[],int largo)
{
    int retorno=-1;
    int i;

    if(lista!=NULL&&largo>0)
    {
        for(i=0;i<largo;i++)
        {
            lista[i].isEmpty=1;//vacio

        }
        retorno=0;
    }
    return retorno;
}

/**
 * Obtiene el primer indice libre del array.
 * @param lista,recibe el array.
 /param largo, largo del array
 * @return el primer indice disponible o si es error
 */
int buscarLibre(EMovie lista[], int largo)
{
    int i;
    int retorno=-1;

    if(lista!=NULL&&largo>0)
    {
        for(i=0;i<largo;i++)
        {
            if(lista[i].isEmpty==1)//vacio
            {
                retorno= i;
            }
    }
   }
  return retorno;
}

 /** \brief Busca una pelicula por codigo
 *
 * \param lista recibe el array
 * \param Largo recibe el largo del array
 * \return retorna [0] si se inicializo o [-1] en caso de algun error
 *
 */
int buscarPorCodigo(EMovie lista[], int largo)
{
    int i;
    int retorno=-1;
    int auxCod;

    printf("Ingrese codigo de la pelicula:\n");
    scanf("%d",&auxCod);

    if(lista!=NULL&&largo>0)
    {
        for(i=0;i<largo;i++)
        {
            if(lista[i].isEmpty==0 && auxCod==lista[i].codigo)//lleno
            {
                retorno = i;
            }
         }
      }

     return retorno;
}

/** \brief Agrega datos(peliculas) al array
 *
 * \param lista recibe el array
 * \param Largo recibe el largo del array
* \return retorna error^[-1] o no[0]
 *
 *
 */
int agregarPelicula(EMovie movie[], int largo)
{
   int i;
   int retorno=-1;
   int espacioLibre = buscarLibre(movie,largo);

   if(movie!=NULL&&largo>0)
    {
        for(i=0;i<largo;i++)
        {
            if(movie[i].isEmpty==1)//vacio
            {
                movie[espacioLibre].codigo=espacioLibre;
                getString(movie[espacioLibre].titulo,"Ingrese titulo de la pelicula: ","Error en el ingreso.",1,30);
                getString(movie[espacioLibre].genero,"Ingrese genero de la pelicula: ","Error en el ingreso.",5,20);
                getInt(movie[espacioLibre].duracion,"Ingrese duracion de la pelicula :","Error en el ingreso.",00,04);
                getString(movie[espacioLibre].descripcion,"Ingrese descripcion de la pelicula: ","Error en el ingreso.",10,1500);
                getString(movie[espacioLibre].linkImagen,"Ingrese link de la imagen: ","Error en el ingreso.",10,1000);
                getInt(movie[espacioLibre].puntaje,"Ingrese puntaje de 1 a 5 :","Error en el ingreso.",1,5);
                movie[espacioLibre].isEmpty=0;
                retorno=0;
                escribirArchivo(movie);
                break;


            }
         }
      }
      return retorno;
}

/** \brief borra un elemento(pelicula) del array
 *
 * \param  lista recibe el array
 * \param largo el largo del array
 * \return retorna [0] si se inicializo o [-1] en caso de algun error
 *
 */
int borrarPelicula(EMovie movie[],int largo)
{
    int retorno=-1;
    int aux;
    int i;

    printf("Ingrese codigo de la pelicula a eliminar:");
    scanf("%d",&aux);

    if(movie!=NULL&&largo>0)
    {
        for(i=0;i<largo;i++)
         {
             if(movie[i].codigo==aux)
             {
                 movie[i].isEmpty=1;
                 printf("Esta pelicula se ha borrado");
                 listar(movie, largo);
                 retorno=0;
                 break;
             }
           }
         }
      return retorno;
}

/** \brief modifica a el array(pelicula)
 *
 * \param lista recibe el array
 * \param Largo recibe el largo del array
 * return 0 si no hay errores, -1 si hay
 */
int modificarPelicula(EMovie lista[], int largo)
{

    int retorno=-1;
    int aux;
    int i;
    char seguir='s';
    int opcion=0;

    printf("Ingrese codigo de la pelicula a modificar:");
    scanf("%d",&aux);

    if(lista!=NULL&&largo>0)
    {
        for(i=0;i<largo;i++)
         {
             if(lista[i].codigo==aux && lista[i].isEmpty==0)
             {
                 do
                   {
                      printf("Que desea Modificar?:\n 1-Titulo\n 2-Genero\n 3-Duracion\n 4-Descripcion\n 5-Puntaje\n 6-Imagen\n 7-Salir\n");
                      scanf("%d",&opcion);

                   switch(opcion)
                    {
                       case 1:
                         getString(lista[i].titulo,"Ingrese titulo de la pelicula: ","Error en el ingreso.",1,30);
                            break;

                       case 2:getString(lista[i].genero,"Ingrese genero de la pelicula: ","Error en el ingreso.",5,20);
                            break;
                      case 3:getInt(lista[i].duracion,"Ingrese duracion de la pelicula :","Error en el ingreso.",000,240);//minutos
                            break;
                     case 4:getString(lista[i].descripcion,"Ingrese descripcion de la pelicula: ","Error en el ingreso.",10,1500);
                            break;
                     case 5:getInt(lista[i].puntaje,"Ingrese puntaje de 1 a 5 :","Error en el ingreso.",1,5);
                            break;
                     case 6:getString(lista[i].linkImagen,"Ingrese link de la imagen: ","Error en el ingreso.",10,1000);
                            break;
                     case 7:
                         seguir = 'n';
                            break;
                             default : printf("No se eligio una opcion correcta\n");
                              retorno=0;
                        }
               }while(seguir=='s');

             }
           }
         }
      return retorno;

}
/** \brief imprime peliculas
 *
 * \param  lista recibe el array
 * \param largo el largo del array
 * \return nada
 *
 */
void listar(EMovie lista[],int largo)
{
    int i;
    for(i=0; i< largo;i++)
    {
        if(lista[i].isEmpty==0)
        {
        printf("titulo %s--genero %s--duracion %d--descripcion  %s--\n",lista[i].titulo, lista[i].genero,lista[i].duracion,lista[i].descripcion);
    }
     }
 }

/** \brief escribe un archivo
 *
 * \param  lista recibe el array
 *
 * \return 0 si no hay errores, -1 si hay
 *
 */
int escribirArchivo(EMovie lista[])
{
    int retorno=-1;

    if(lista!=NULL)
    {
     FILE* archivo = fopen("archivo.dat", "ab");

    fwrite(lista, sizeof(EMovie),1, archivo);

    fclose(archivo);
    retorno=0;

    }

    return retorno;

}
/** \brief lee un archivo
 *
 * \param  lista recibe el array
 *
 * \return 0 si no hay errores, -1 si hay
 *
 */
int leerArchivo(EMovie lista[], int largo)
{
    int retorno=-1;
    int i;
    if(lista!=NULL)
    {
        FILE* archivo= fopen("archivo.dat","rb");

        for(i=0;i<largo; i++)
        {
             fread(lista,sizeof(EMovie),1,archivo);
        }

        fclose(archivo);
        retorno=0;

        }
    return retorno;
}
/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 *  @param largo el largo del array.
 */
void generarPagina(EMovie lista[], char nombre[], int largo)
{
    int i;
    nombre = strcat(nombre, ".html");

    FILE* archivo=fopen(nombre,"w");

    for(i=0;i<largo;i++)
    {
        fprintf(archivo,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''>", lista[i].linkImagen);
        fprintf(archivo,"</a><h3><a href='#'>%s</a></h3><ul>",lista[i].titulo);
        fprintf(archivo,"<li>Genero:%s</li><li>Puntaje:%d</li><li>Duracion:%d</li></ul>", lista[i].genero, lista[i].puntaje,lista[i].duracion);
        fprintf(archivo,"<p>%s</p></article>",lista[i].descripcion);


    }

    fclose(archivo);

}




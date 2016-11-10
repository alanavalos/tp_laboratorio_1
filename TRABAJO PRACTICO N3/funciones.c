#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "validar.h"

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
                escribirArchivo(movie,largo);
                break;


            }
         }
      }
      return retorno;
}


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

int escribirArchivo(EMovie lista[], int largo)
{
    int retorno=-1;
    FILE* archivo;

    if(lista!=NULL)
    {
        archivo = fopen("archivo.dat", "wb");

    fwrite(lista, sizeof(EMovie),largo, archivo);
     printf("\nFichero guardado con exito\n");

    fclose(archivo);
    retorno=0;

    }

    return retorno;

}

int leerArchivo(EMovie lista[], int largo)
{
    int retorno=-1;
    int i;
    FILE* archivo;

    if(lista!=NULL)
    {
         archivo= fopen("archivo.dat","rb");

        for(i=0;i<largo; i++)
        {
             fread(lista,sizeof(EMovie),largo,archivo);
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
 */
void generarPagina(EMovie lista[], int largo)
{
    int i;

     FILE *f;

    f=fopen("pagina.html", "w");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }
    fprintf(f,"<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>eMovie Peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>");

  for(i=0;i<largo;i++)
    {
        if(lista[i].isEmpty==0)
        {
         fprintf(f,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''>", lista[i].linkImagen);
         fprintf(f,"</a><h3><a href='#'>%s</a></h3><ul>",lista[i].titulo);
         fprintf(f,"<li>Genero:%s</li><li>Puntaje:%d</li><li>Duracion:%d</li></ul>", lista[i].genero, lista[i].puntaje,lista[i].duracion);
         fprintf(f,"<p>%s</p></article>",lista[i].descripcion);
        }
    }
    fprintf(f,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");
    fclose(f);
    printf("\n\n archivo escrito con exito\n\n");

}



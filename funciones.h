#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int isEmpty;
    int codigo;
}EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie movie[], int);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie[],int);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 *  @param largo el largo del array.
 */
void generarPagina(EMovie lista[], char nombre[],int largo);

///////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

int inicalizarIsempty(EMovie lista[],int largo);
int buscarLibre(EMovie lista[],int largo);
int buscarPorCodigo(EMovie lista[], int largo);
int modificarPelicula(EMovie lista[], int largo);
void listar(EMovie lista[], int largo);
int escribirArchivo(EMovie lista[]);
int leerArchivo(EMovie lista[], int largo);






#endif // FUNCIONES_H_INCLUDED

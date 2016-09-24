#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct {

    char nombre[50];
    int edad;
    int isEmpty;
    int dni;

}EPersona;

void inicializarisEmpty(EPersona[],int);
int agregarPersona(EPersona[],int);
int borrarPersona(EPersona[],int);
void ordenarPersona(EPersona[],int);
void graficar(EPersona[],int);

///////////////////////////////////////////
int getInt(int *input,char message[], char eMessage[], int lowLimit, int hiLimit);
int getFloat(float* input,char message[], char eMessage[], float lowLimit, float hiLimit);
int getChar(char* input,char message[], char eMessage[], char lowLimit, char hiLimit);
int getString(char* input,char message[], char eMessage[], int lowLimit, int hiLimit);
///////////////////////////////////////////
/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);




#endif // FUNCIONES_H_INCLUDED



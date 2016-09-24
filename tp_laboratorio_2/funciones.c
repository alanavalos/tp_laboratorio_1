#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void inicializarisEmpty(EPersona persona[], int largo)
{
 int i;
 for(i=0;i<largo;i++)
 {
     if(persona!=NULL&&largo>0)
     {
             persona[i].isEmpty=1;//vacio

             //Ademas por cuestiones de estetica inicializo todo en 0.
             persona[i].edad = 0;
             persona[i].dni = 0;
             strcpy(persona[i].nombre, "");

     }
 }
}

int obtenerEspacioLibre(EPersona lista[], int largo)
{
    int i;
    int lugarLibre;

    for(i=0;i<largo;i++)
 {
     if(lista[i].isEmpty==1 && lista!=NULL&&largo>0)
     {
         lugarLibre= i;
         break;
     }
 return lugarLibre;
 }
}


int agregarPersona(EPersona persona[],int largo)
{
   int i;
   int retorno=-1;

   for(i=0;i<largo;i++)
 {

    if(persona[i].isEmpty ==1 && persona!=NULL && largo>0)
    {
       getString(persona[i].nombre,"Ingrese nombre:","Error. Reingrese nombre.",3,10);

       getInt(&persona[i].edad,"Ingrese edad:","Error.Edad fuera de limites.Reingrese.",0,100);
       getInt(&persona[i].dni,"Ingrese DNI:","Error,fuera de limites.",10000,99999999);

       persona[i].isEmpty=0;//lleno
       retorno=0;
       break;
    }
 }
 return retorno;
}



int buscarPorDni(EPersona lista[], int largo)
{
    int i;
    int retorno;
    int devolerDni;
    printf("Ingrese DNI :\n");
    scanf("%d", &devolerDni);

    for(i=0;i<largo;i++)
    {
        if(lista[i].isEmpty==0 && devolerDni == lista[i].dni)
        {
           retorno = i;
        }// else error,break;
    }
    return retorno;
}

int borrarPersona(EPersona persona[], int largo)
{

    int retorno=-1;
    int personaBorrar = buscarPorDni(persona,largo);

        if(persona[personaBorrar].isEmpty==0)
        {
            persona[personaBorrar].isEmpty=1;

        }
        else
        {
      printf("Error. La persona no existe");
      retorno=0;
        }
        return retorno;
}


void ordenarPersona(EPersona persona[], int largo)
{
    int i;
    int j;

     EPersona auxPersona;
    for(i=0;i<largo-1;i++)
    {
        for(j=i+1;j<largo;j++)
        {
            if(persona[i].isEmpty==0 && strcmp(persona[i].nombre, persona[j].nombre)>0)
            {
                auxPersona=persona[i];
                persona[i]=persona[j];
                persona[j]=auxPersona;

            }
        }
    }
    for(i=0;i<largo;i++)
    {
            printf("%s-->%d-->%d\n",persona[i].nombre, persona[i].dni, persona[i].edad);

    }

}



void graficar(EPersona persona[], int largo)
{
int i;
int var1=0;
int var2=0;
int var3=0;
int aux;
int flag;
int max;

for(i=0;i<largo;i++)
{
    if(persona[i].isEmpty==0)
    {
        aux=persona[i].edad;
        if(aux<19)
        {
            var1++;
        }
        else if(aux>19&&aux<=35)
        {
            var2;
        }
        else{
            var3;
        }
    }
}
for(i=0;i<3;i++)
{
    if(var1>max || i==0)
    {
        max=var1;
    }
    if(var2>max)
    {
        max=var2;
    }
    if(var3>max)
    {
        max=var3;
    }
}
for(i=max;i>0;i--)
{
    int flag1=0;
    int flag2=0;
    int flag3=0;

    if(i<10)
    {
     printf("%02d|",i);
    }
    else
     printf("%02d|",i);
    if(i<= var1)
    {
      printf("*");
        }
    else
    {
      printf("\t");
        }
     if(i<= var2)
    {
     printf("\t*");
        }
    else
        {
     printf("\t");
            }
    if(i<= var3)
    {
     printf("\t*");
     printf("\n");
            }
            else
            {
                printf("\n");
     }
}
      printf("-------------------\n");
      printf("\n|<18\t19-35\t>35");
      printf("\n   %d\t%d\t%d", var1, var2, var3);

        return 0;

    }

    int getInt(int *input,char message[], char eMessage[], int lowLimit, int hiLimit)
{
    int respuesta=-1;
    int aux;
    int scanfOk;
    puts(message);
    scanfOk = scanf("%d",&aux);
    if(scanfOk)
    {
        if(aux<lowLimit)
        {
            puts(eMessage);
        }
        else
        {  *input=aux;
         respuesta=0;

        }
    }
    return respuesta;

}

int getFloat(float* input,char message[], char eMessage[], float lowLimit, float hiLimit)

{
    int respuesta=-1;
    float aux;
    int scanfOk;
    puts(message);
    scanfOk=scanf("%f",&aux);

    if(scanfOk)
    {
        if(aux<lowLimit||aux>hiLimit)
        {
        puts(eMessage);
        }
        else
        {
        *input=aux;
         respuesta=0;

        }
    }
    return respuesta;

}

int getChar(char* input,char message[], char eMessage[], char lowLimit, char hiLimit)
{
    int respuesta=-1;
    char aux;
    int scanfOk;
    puts(message);
    scanfOk=scanf("%c",&aux);
    aux=tolower(aux);

    if(scanfOk)
    {
        if(aux<lowLimit||aux>hiLimit)
        {
        puts(eMessage);
        }
        else
        {
        aux=toupper(aux);
        *input=aux;
        respuesta=0;

        }
    }
    return respuesta;

}

int getString(char* input,char message[], char eMessage[], int lowLimit, int hiLimit)
{
    char aux[50];
    int respuesta=-1;
    int x;


    printf(message);
    scanf("%s",aux);
    x=strlen(aux);

        if(x<lowLimit || x>hiLimit)
        {
            printf(eMessage);
        }
        else
            {
            strcpy(input,aux);
            respuesta=0;
        }

    return respuesta;
}


#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int numero1=0;
    int numero2=0;
    int flag1=0;
    int flag2=0;



    do
    {
        system("cls");

        printf("Calculadora:\n");
        printf("1- Ingresar 1er operando A=%d\n",numero1);
        printf("2- Ingresar 2do operando B=%d\n",numero2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
            case 1:
                flag1=1;
                numero1=pedirNumero();
                break;
            case 2:
                flag2=1;
                numero2= pedirNumero();
                break;
            case 3:
                if(flag1 ==1 && flag2 == 1)
                {
                    printf("La suma es: %.3f", suma(numero1, numero2));
                }
                else
                {


                    printf("Error. ingrese dos numeros");
                }
                break;
            case 4:
                if(flag1 ==1 && flag2 == 1)
                {
                printf("La resta es: %.3f", resta(numero1,numero2));
                }
                else
                {


                    printf("Error. ingrese dos numeros");
                }
                break;
            case 5:
                if(flag1 ==1 && flag2 == 1)
                {
                printf("La division es: %.3f", division(numero1,numero2));
                if(numero1==0 || numero2==0)
                {
                    printf("Error. Reingrese otro valor distinto a 0 ");
                }
                }
                else
                {


                    printf("Error. ingrese dos numeros");
                }
                break;
            case 6:
                if(flag1 ==1 && flag2 == 1)
                {
                printf("La multiplicacion es: %.3f", multiplicacion(numero1, numero2));
                }
                else
                {


                    printf("Error. ingrese dos numeros");
                }

                break;
            case 7:
                if(flag1 ==1 && flag2 == 1)
                {
                printf("El factorial del 1er numero es: %d\n",factorial(numero1));
                printf("El factorial del 2do numero es: %d\n",factorial(numero2));
                }
                else
                {


                    printf("Error. ingrese dos numeros");
                }
                break;
            case 8:
                if(flag1 ==1 && flag2 == 1)
                {
                printf(" Elcalculo de todas las operaciones es: \n");
                printf("La suma es: %.3f?\n", suma(numero1, numero2));
                printf("La resta es: %.3f\n", resta(numero1,numero2));
                printf("La division es: %.3f\n", division(numero1,numero2));
                printf("La multiplicacion es: %.3f\n", multiplicacion(numero1, numero2));
                printf("El factorial es: %d\n",factorial(numero1));
                }
                else
                {


                    printf("Error. ingrese dos numeros");
                }

                break;
            case 9:
                seguir = 'n';
                break;
            default: printf("Error. Ingresa numero de 1 a 9");

        }
system("pause");
        }while(seguir=='s');


    return 0;
}



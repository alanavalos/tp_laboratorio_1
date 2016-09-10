float suma(float numeroSuma1, float numeroSuma2)
{
    float resultadoSuma;
    resultadoSuma = numeroSuma1 + numeroSuma2;

    return resultadoSuma;
}
float resta(float numeroResta1, float numeroResta2)
{
    float resultadoResta;
    resultadoResta= numeroResta1 - numeroResta2;

    return resultadoResta;


}
float division(float numeroDivision1, float numeroDivision2)
{
    float resultadoDivision;
    resultadoDivision = numeroDivision1 / numeroDivision2;


    return resultadoDivision;
}
float multiplicacion(float numeroMult1, float numeroMult2)
{
    float resultadoMult;
    resultadoMult = numeroMult1 * numeroMult2;

    return resultadoMult;
}

int factorial(int a)
    {
        int fact;
      if(a == 1)
        {
            return 1;
        }
        fact = a*factorial(a-1);
    return fact;
    }


    int pedirNumero()
    {
        int numero;

        printf("ingrese un numero");
        scanf("%d",&numero);

        return numero;
    }



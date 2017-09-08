#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float suma(float a, float b)
{
    float numero1=0, numero2=0, resulta=0;

    numero1=a;
    numero2=b;
    resulta=numero1+numero2;

    return(resulta);
}

float resta(float a, float b)
{
    float numero1=0, numero2=0, resulta=0;

    numero1=a;
    numero2=b;
    resulta=numero1-numero2;

    return(resulta);
}

float dividir(float a, float b)
{
    float numero1=0, numero2=0, resulta=0;

    numero1=a;
    numero2=b;
    resulta=numero1/numero2;

    return(resulta);
}

float multiplicar(float a, float b)
{
    float numero1=0, numero2=0, resulta=0;

    numero1=a;
    numero2=b;
    resulta=numero1*numero2;

    return(resulta);
}

int factorial(float a)
{
    float numero=0;
    int resulta=0;

    numero =(long long)a;
    if(numero==0||numero==1)
    {
        return 1;
    }
    resulta=numero*factorial(numero-1);
    return resulta;
}

void dividirPorCero(int numero)
{
    int a=0;

    a=numero;
    if(a==0)
    {
        printf("No se puede dividir por 0\n");
        system("pause");
    }
}

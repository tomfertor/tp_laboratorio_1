#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int auxOpcion=0;
    float operandoUno=0, operandoDos=0;
    int numero=0;

    while(seguir=='s')
    {
        system("cls");
        printf("1- Ingresar 1er operando %.2f\n", operandoUno);
        printf("2- Ingresar 2do operando %.2f\n",operandoDos);
        printf("3- Calcular la suma %.2f+%.2f\n",operandoUno,operandoDos);
        printf("4- Calcular la resta %.2f-%.2f\n",operandoUno,operandoDos);
        printf("5- Calcular la division %.2f/%.2f\n",operandoUno,operandoDos);
        printf("6- Calcular la multiplicacion %.2f*%.2f\n",operandoUno,operandoDos);
        printf("7- Calcular el factorial %d\n",numero);
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        printf("Elija una opcion: ");
        scanf("%d",&auxOpcion);
        while(auxOpcion<1||auxOpcion>9)
        {
            system("cls");
            printf("Error. Elija una opcion entre 1 y 9.\n");
            printf("1- Ingresar 1er operando %.2f\n", operandoUno);
            printf("2- Ingresar 2do operando %.2f\n",operandoDos);
            printf("3- Calcular la suma %.2f+%.2f\n",operandoUno,operandoDos);
            printf("4- Calcular la resta %.2f-%.2f\n",operandoUno,operandoDos);
            printf("5- Calcular la division %.2f/%.2f\n",operandoUno,operandoDos);
            printf("6- Calcular la multiplicacion %.2f*%.2f\n",operandoUno,operandoDos);
            printf("7- Calcular el factorial %.2f\n",operandoUno);
            printf("8- Calcular todas las operaciones\n");
            printf("9- Salir\n");
            fflush(stdin);
            scanf("%d",&auxOpcion);
        }
        opcion=auxOpcion;

        switch(opcion)
        {
            case 1:
                system("cls");
                printf("Ingrese el primer operando: \n");
                scanf("%f",&operandoUno);
                numero=operandoUno;
                break;
            case 2:
                system("cls");
                printf("Ingrese el segundo operando: \n");
                scanf("%f",&operandoDos);
                break;
            case 3:
                system("cls");
                printf("El resultado de hacer %.2f+%.2f da como resultado %.2f\n",operandoUno,operandoDos,suma(operandoUno,operandoDos));
                system("pause");
                break;
            case 4:
                system("cls");
                printf("El resultado de hacer %.2f-%.2f da como resultado %.2f\n",operandoUno,operandoDos,resta(operandoUno,operandoDos));
                system("pause");
                break;
            case 5:
                system("cls");
                dividirPorCero(operandoDos);
                if(operandoDos==0)
                {
                    break;
                }
                printf("El resultado de hacer %.2f/%.2f da como resultado %.2f\n",operandoUno,operandoDos,dividir(operandoUno,operandoDos));
                system("pause");
                break;
            case 6:
                system("cls");
                printf("El resultado de hacer %.2f*%.2f da como resultado %.2f\n",operandoUno,operandoDos,multiplicar(operandoUno,operandoDos));
                system("pause");
                break;
            case 7:
                system("cls");

                printf("El calculo del factorial de %d da como resultado %d\n",numero,factorial(numero));
                system("pause");
                break;
            case 8:
                system("cls");
                printf("SUMA            %.2f+%.2f = %.2f\n",operandoUno,operandoDos,suma(operandoUno,operandoDos));
                printf("RESTA           %.2f-%.2f = %.2f\n",operandoUno,operandoDos,resta(operandoUno,operandoDos));
                printf("MULTIPLICACION  %.2f*%.2f = %.2f\n",operandoUno,operandoDos,multiplicar(operandoUno,operandoDos));
                printf("FACTORIAL       %d!        = %d\n",numero,factorial(numero));
                dividirPorCero(operandoDos);
                if(operandoDos==0)
                {
                    break;
                }
                printf("DIVISION        %.2f/%.2f = %.2f\n",operandoUno,operandoDos,dividir(operandoUno,operandoDos));
                system("pause");
                break;
            case 9:
                system("cls");
                printf("Desea seguir utilizando la calculadora?(s/n): ");
                fflush(stdin);
                scanf("%c",&seguir);
                while(seguir!='n'&&seguir!='s'&&seguir!='N'&&seguir!='S')
                {
                    system("cls");
                    printf("Error. Opcion ingresada incorrecta. Desea seguir utilizando la calculadora(s/n): ");
                    fflush(stdin);
                    scanf("%c",&seguir);
                }
                break;
        }



}
return 0;
}

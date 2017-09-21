#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAX 20


int main()
{
    EPersona personas[MAX];
    char seguir='s';
    int opcion=0;
    int auxOpcion=0;
    inicializarArray(personas,MAX);


    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n\n");

        printf("Elija una opcion del Menu: ");
        fflush(stdin);
        scanf("%d",&auxOpcion);

        while(auxOpcion<1||auxOpcion>5)
        {
            system("cls");
            printf("ERROR. Elija una opcion entre 1 y 5.\n\n");
            printf("1- Agregar persona\n");
            printf("2- Borrar persona\n");
            printf("3- Imprimir lista ordenada por  nombre\n");
            printf("4- Imprimir grafico de edades\n\n");
            printf("5- Salir\n");
            printf("OPCION: ");
            fflush(stdin);
            scanf("%d", &auxOpcion);
        }

        opcion = auxOpcion;


        switch(opcion)
        {
            case 1:
                system("cls");
                printf("Opcion 1: -AGREGAR PERSONA-\n");
                altaPersona(personas, MAX);
                system("pause");
                break;
            case 2:
                system("cls");
                printf("Opcion 2: -BORRAR PERSONA-\n");
                bajaPersona(personas, MAX);
                system("pause");
                break;
            case 3:
                system("cls");
                printf("Opcion 3: -LISTA DE PERSONAS EN EL SISTEMA ORDENADAS ALFABETICAMENTE-\n");
                mostrarPersonas(personas, MAX);
                system("pause");
                break;
            case 4:
                system("cls");
                printf("Opcion 4: -GRAFICO DE EDADES DE LAS PERSONAS INGRESADAS EN EL SISTEMA-\n");
                graficoEdades(personas, MAX);
                printf("\n\n");
                system("\npause");
                break;
            case 5:
                system("cls");
                printf("Desea seguir utilizando el programa?(s/n): ");
                fflush(stdin);
                scanf("%c", &seguir);
                while(seguir != 'n' && seguir != 's' && seguir != 'N' && seguir != 'S')
                {
                    system("cls");
                    printf("Error. Opcion ingresada incorrecta. Desea seguir utilizando el programa?(s/n): ");
                    fflush(stdin);
                    scanf("%c", &seguir);
                }
                break;
        }
    }

    return 0;
}

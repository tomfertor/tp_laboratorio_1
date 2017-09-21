#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

void inicializarArray(EPersona lista[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
        {
            lista[i].estado = 0;
        }
}

int buscarLibre(EPersona lista[], int tam)
{
    int indice = -1,i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==0)
        {
            indice = i;
        }
    }
    return indice;
}

void altaPersona(EPersona personas[], int tam)
{
    EPersona nuevaPersona;
    int dni, edad, esta, lugar;
    char auxCad[50];

    lugar = buscarLibre(personas, tam);
    if(lugar==-1)
    {
        printf("No hay lugar.\n\n");
    }
    else
    {
        printf("Ingrese DNI: ");
        fflush(stdin);
        scanf("%d", &dni);
        while(dni<=0 || dni>=99999999)
        {
            printf("ERROR. Reingrese DNI: ");
            fflush(stdin);
            scanf("%d", &dni);
        }

        esta = buscarPersona(dni,personas,tam);
        if(esta != -1)
        {
            printf("\nLa persona con DNI: %d ya se encuentra cargada en el sistema.\n", dni);
        }
        else
        {
            nuevaPersona.dni = dni;

            printf("Ingrese Nombre: ");
            fflush(stdin);
            gets(auxCad);
            while(strlen(auxCad)>50)
            {
                printf("ERROR. Nombre demasiado largo. Reingrese NOMBRE: ");
                fflush(stdin);
                gets(auxCad);
            }
            strcpy(nuevaPersona.nombre, auxCad);

            printf("Ingrese Edad: ");
            fflush(stdin);
            scanf("%d", &edad);
            while(edad<=0||edad>=100)
            {
                printf("ERROR. Reingrese EDAD: ");
                fflush(stdin);
                scanf("%d", &edad);
            }
            nuevaPersona.edad = edad;

            nuevaPersona.estado = 1;

            personas[lugar] = nuevaPersona;
            printf("\nPersona Cargada con Exito!!!\n");
        }
    }
}

int buscarPersona(int dni, EPersona personas[], int tam)
{
    int i,indice = -1;
    for(i=0;i<tam;i++)
    {
        if(personas[i].dni == dni && personas[i].estado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void bajaPersona(EPersona personas[], int tam)
{
    int indice, dni;
    char baja='s';

    printf("Ingrese DNI: ");
        fflush(stdin);
        scanf("%d", &dni);
        while(dni<=0 || dni>=99999999)
        {
            printf("ERROR. Reingrese DNI: ");
            fflush(stdin);
            scanf("%d", &dni);
        }
        indice = buscarPersona(dni,personas,tam);
        if(indice == -1)
        {
            printf("\nLa persona con DNI: %d no se encuentra en el sistema.\n\n", dni);
        }
        else
        {
            printf("\nDatos de la persona\n");
            printf("    NOMBRE     EDAD          DNI\n");
            mostrarPersona(personas[indice]);

            printf("\nConfirma la BAJA de la Persona?(s/n): ");
            fflush(stdin);
            scanf("%c", &baja);
            while(baja != 's' && baja != 'n' && baja != 'S' && baja != 'N')
            {
                printf("Error(OPCION INCORRECTA). Confirma la BAJA de la Persona?(s/n): ");
                fflush(stdin);
                scanf("%c", &baja);
            }
            if(baja=='s' || baja == 'S')
            {
                personas[indice].estado = 0;
                printf("\nLa BAJA se ha efectuado con exito!!\n");
            }
            else
            {
                printf("La BAJA fue cancelada!!\n");
            }
        }
}

void mostrarPersona(EPersona unaPersona)
{
    printf("%10s    %3d         %8d\n", unaPersona.nombre, unaPersona.edad, unaPersona.dni);
}

void mostrarPersonas(EPersona lista[], int tam)
{
    int flag=0,i,j;
    EPersona auxPersona;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre)>0)
            {
                auxPersona = lista[i];
                lista[i]   = lista[j];
                lista[j]   = auxPersona;
            }
        }
    }

    printf("\nLista de Personas\n\n");

    printf("    NOMBRE     EDAD        DNI\n");

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado == 1)
        {
             printf("%10s    %3d         %8d\n", lista[i].nombre, lista[i].edad, lista[i].dni);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("------------------------------------------");
        printf("\nNo hay personas caragadas en el sistema\n");
        printf("------------------------------------------\n\n");
    }
}

int graficoEdades(EPersona lista[], int tam)
{
    int i, hasta18=0, de19a35=0, mayorDe35=0, flag=0, masGrande;
    for(i=0;i<tam;i++)
    {
        if(lista[i].edad<=18 && lista[i].estado==1)
        {
            hasta18++;
        }
        else
        {
            if(lista[i].edad>18 && lista[i].edad<=35 && lista[i].estado==1)
            {
                de19a35++;
            }
            else
            {
                if(lista[i].edad>35 && lista[i].estado==1)
                {
                    mayorDe35++;
                }
            }
        }
    }
    if(hasta18 >= de19a35 && hasta18 >= mayorDe35)
    {
        masGrande = hasta18;
    }
    else
    {
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            masGrande = de19a35;
        }
        else
        {
            masGrande = mayorDe35;
        }
    }
    for(i=masGrande;i>0;i--)
    {
        if(i <= hasta18)
        {
            printf("*");
        }
        if(i <= de19a35)
        {
            flag=1;
            printf("\t*");
        }
        if(i <= mayorDe35)
        {
            if(flag == 0)
                printf("\t\t*");
            if(flag == 1)
                printf("\t*");
        }
        printf("\n");
    }
    printf("-------------------");
    printf("\n |<18\t19-35\t>35|");
    printf("\n  %d\t%d\t%d", hasta18, de19a35, mayorDe35);

    return 0;
}

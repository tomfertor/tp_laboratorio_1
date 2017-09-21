#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;


/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);
/**
 * Setea el atributo ESTADO de cada persona a caragarse en 0.
 * @param lista el array se pasa como parametro.
 * @param tamaño de la lista
 * @return no retorna nada
 */
void inicializarArray(EPersona lista[], int tam);
/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible, y en caso de que devuelva -1, se informa que no hay mas lugar.
 */
int buscarLibre(EPersona lista[], int tam);
/**
 * Carga una persona al sistema.
 * @param lista el array se pasa como parametro.
 * @param tamaño de la lista.
 * @return no retorna nada
 */
void altaPersona(EPersona personas[], int tam);
/**
 * Recibe el DNI de la persona, y se fija si ya hay alguien en el sistema con ese mismo DNI.
 * @param DNI de una persona.
 * @param lista el array se pasa como parametro.
 * @param tamaño de la lista.
 * @return retorna el indice en el que se encuentra la persona, o -1 si no esta caragada.
 */
int buscarPersona(int dni, EPersona personas[], int tam);
/**
 * Baja logica de una persona en el sistema.
 * @param lista el array se pasa como parametro.
 * @param tamaño de la lista.
 * @return no retorna nada.
 */
void bajaPersona(EPersona personas[], int tam);
/**
 * Muestra Nombre, Edad y DNI de una persona especifica.
 * @param recibe los datos de una persona
 * @return no retorna nada.
 */
void mostrarPersona(EPersona unaPersona);
/**
 * Muestra Nombre, Edad y DNI de las personas cargadas en el sistema.
 * @param lista el array se pasa como parametro.
 * @param tamaño de la lista.
 * @return no retorna nada.
 */
void mostrarPersonas(EPersona lista[], int tam);
/**
 * Realiza un grafico deacuerdo a las edades de las personas cargadas en el sistema.
 * @param lista el array se pasa como parametro.
 * @param tamaño de la lista.
 * @return .
 */
int graficoEdades(EPersona lista[], int tam);

#endif // FUNCIONES_H_INCLUDED

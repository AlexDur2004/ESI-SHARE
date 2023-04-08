#ifndef PREGUNTAR_LOCALIDAD_H_INCLUDED
#define PREGUNTAR_LOCALIDAD_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "leer.h"

//Prototipo: void pregunta(char *, int);
//Precondición: Tener una cadena y un entero inicializados, que nos indique el nº maximo de caracteres de la misma.
//Postcondición: Introducir en una cadena, la información escaneada, pero cambiando el salto de linea \n por el caracter nulo \0.
void pregunta(char *, int);

//Prototipo: void imprimir_localidad(Estr_Localidad *, int);
//Precondición: Tener la estructura "localidad" inicializada, con su contador.
//Postcondición: Imprimir una lista de 4 filas con todas las localidades.
void imprimir_localidad(Estr_Localidad *, int);

//Prototipo: void pregunta_localidad(Estr_Localidad *, int, char *);
//Precondición: Tener la estructura "localidad" inicializada, con su contador. Además, necesitamos una cadena, donde introducir la localidad introducida.
//Postcondición: Introducir en una cadena, la localidad seleccionada de la lista.
void pregunta_localidad(Estr_Localidad *, int, char *);

//Prototipo: void pregunta_localidad(Estr_Localidad *, int, char *);
//Precondición: Tener la estructura "localidad" inicializada, con su contador. Además, necesitamos una cadena, donde introducir la localidad introducida.
//Postcondición: Introducir en una cadena, la localidad seleccionada de la lista.
void pregunta_localidad(Estr_Localidad *, int, char *);

//Prototipo: void preguntar_veh(Estr_Vehiculo *, int, char *, int *);
//Precondición: Tener la estructura "vehiculo" inicializada, con su contador. Además, necesitamos una cadena, donde introducir la localidad introducida, y una variable bandera con puntero.
//Postcondición: Preguntar una matricula, y comprobar si existe en el sistema.
void preguntar_veh(Estr_Vehiculo *, int, char *, int *);

#endif // PREGUNTAR_LOCALIDAD_H_INCLUDED

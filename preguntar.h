#ifndef PREGUNTAR_LOCALIDAD_H_INCLUDED
#define PREGUNTAR_LOCALIDAD_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "leer.h"

//Prototipo: void pregunta(char *, int);
//Precondici�n: Tener una cadena y un entero inicializados, que nos indique el n� maximo de caracteres de la misma.
//Postcondici�n: Introducir en una cadena, la informaci�n escaneada, pero cambiando el salto de linea \n por el caracter nulo \0.
void pregunta(char *, int);

//Prototipo: void imprimir_localidad(Estr_Localidad *, int);
//Precondici�n: Tener la estructura "localidad" inicializada, con su contador.
//Postcondici�n: Imprimir una lista de 4 filas con todas las localidades.
void imprimir_localidad(Estr_Localidad *, int);

//Prototipo: void pregunta_localidad(Estr_Localidad *, int, char *);
//Precondici�n: Tener la estructura "localidad" inicializada, con su contador. Adem�s, necesitamos una cadena, donde introducir la localidad introducida.
//Postcondici�n: Introducir en una cadena, la localidad seleccionada de la lista.
void pregunta_localidad(Estr_Localidad *, int, char *);

//Prototipo: void pregunta_localidad(Estr_Localidad *, int, char *);
//Precondici�n: Tener la estructura "localidad" inicializada, con su contador. Adem�s, necesitamos una cadena, donde introducir la localidad introducida.
//Postcondici�n: Introducir en una cadena, la localidad seleccionada de la lista.
void pregunta_localidad(Estr_Localidad *, int, char *);

//Prototipo: void preguntar_veh(Estr_Vehiculo *, int, char *, int *);
//Precondici�n: Tener la estructura "vehiculo" inicializada, con su contador. Adem�s, necesitamos una cadena, donde introducir la localidad introducida, y una variable bandera con puntero.
//Postcondici�n: Preguntar una matricula, y comprobar si existe en el sistema.
void preguntar_veh(Estr_Vehiculo *, int, char *, int *);

#endif // PREGUNTAR_LOCALIDAD_H_INCLUDED

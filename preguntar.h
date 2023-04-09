#ifndef PREGUNTAR_H_INCLUDED
#define PREGUNTAR_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listar.h"

//Prototipo: void pregunta(char *, int);
//Precondicion: Tener una cadena y un entero inicializados, que nos indique el num maximo de caracteres de la misma.
//Postcondicion: Introducir en una cadena, la informacion escaneada, pero cambiando el salto de linea \n por el caracter nulo \0.
void pregunta(char *, int);

//Prototipo: void preguntar_contrasena(char *);
//Precondicion: Tener una cadena inicializada, donde introducir la contrasena escaneada.
//Postcondicion: Introducir en una cadena, la contrasena escaneada, pero cambiando el salto de linea \n por el caracter nulo \0. La contrasena introducida debe tener al menos 1 caracter.
//Se hace asi, para poder escribir * cuando se escriba una contrasena.
void preguntar_contrasena(char *);

//Prototipo: void pregunta_localidad(Estr_Localidad *, int, char *);
//Precondicion: Tener la estructura "localidad" inicializada, con su contador. Ademas, necesitamos una cadena, donde introducir la localidad introducida.
//Postcondicion: Introducir en una cadena, la localidad seleccionada de la lista.
void pregunta_localidad(Estr_Localidad *, int, char *);

//Prototipo: void pregunta_ruta(Estr_Localidad *, int, Estr_Rutas **, int, int, char *);
//Precondicion: Tener la estructura "localidad" y "ruta" inicializadas, con sus contadores. Ademas, necesitamos una cadena, donde introducir la localidad introducida.
//Postcondicion: Introducir en una cadena, la localidad seleccionada de la lista, que esté en una ruta.
void pregunta_ruta(Estr_Localidad *, int, Estr_Rutas **, int, int, char *);

//Prototipo: void preguntar_veh(Estr_Vehiculo *, int, char *, int *);
//Precondicion: Tener la estructura "vehiculo" inicializada, con su contador. Ademas, necesitamos una cadena, donde introducir la localidad introducida, y una variable bandera con puntero.
//Postcondicion: Preguntar una matricula, y comprobar si existe en el sistema.
void preguntar_veh(Estr_Vehiculo *, int, char *, int *);

#endif // PREGUNTAR_H_INCLUDED

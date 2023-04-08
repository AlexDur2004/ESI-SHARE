#ifndef RESERVAR_H_INCLUDED
#define RESERVAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leer.h"

//Prototipo: void buscadorRutas(Estr_Rutas **, int, int, Estr_Localidad *, int, Estr_Pasos *, int, char [7]);
//Precondición: Tener las estructuras "ruta", "localidad" y "pasos", con sus contadores. Además, debemos tener una cadena inicializada con la id de viaje.
//Postcondición: Buscar todas las rutas posibles, desde la ciudad seleccionada hasta la ESI.
void buscadorRutas(Estr_Rutas **, int, int, Estr_Localidad *, int, Estr_Pasos *, int, char [7]);

//Prototipo: void imprimirPasos(Estr_Pasos *, int, Estr_Localidad *, int, char *, char *);
//Precondición: Tener las estructuras "pasos" y "localidad", con sus contadores. Además, debemos tener una cadena inicializada con la id de viaje, y otra cadena con la ruta que queremos imprimir.
//Postcondición: Imprimir los pasos de la ruta seleccionada, en el fichero.
void imprimirPasos(Estr_Pasos *, int, Estr_Localidad *, int, char *, char *);

#endif // RESERVAR_H_INCLUDED

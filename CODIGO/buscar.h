#ifndef BUSCAR_H_INCLUDED
#define BUSCAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leer.h"
#include "preguntar.h"

//Prototipo: void buscadorRutas(Estr_Rutas **, int, int, Estr_Localidad *, int, Estr_Pasos *, int, char [7]);
//Precondicion: Tener las estructuras "ruta", "localidad" y "pasos", con sus contadores. Ademas, debemos tener una cadena inicializada con la id de viaje.
//Postcondicion: Buscar todas las rutas posibles, desde la ciudad seleccionada hasta la ESI.
void buscadorRutas(Estr_Rutas **, int, int, Estr_Localidad *, int, Estr_Pasos *, int, char [7]);

#endif // BUSCAR_H_INCLUDED

#ifndef RESERVAR_H_INCLUDED
#define RESERVAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leer.h"
#include "preguntar.h"
#include "encontrar.h"

void buscadorRutas(Estr_Rutas **ruta, int numRutas, int numRutas2, Estr_Localidad *localidad, int numLocalidades, Estr_Pasos *pasos, int numPasos, char id_viaje[7]);
void imprimirPasos(Estr_Pasos *pasos, int numPasos, Estr_Localidad *localidad, int numLocalidades, char *id_viaje, char *token, char *ruta);

#endif // RESERVAR_H_INCLUDED

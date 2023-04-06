#ifndef PREGUNTAR_LOCALIDAD_H_INCLUDED
#define PREGUNTAR_LOCALIDAD_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "leer.h"

void pregunta(char *, int);
void preguntar_id_alta(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos);
void pregunta_localidad(Estr_Localidad *localidad, int numLocalidades, char *local);
void pregunta_ruta(Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, char *rut2);
void preguntar_veh(Estr_Vehiculo *vehiculo, int numVehiculos, char *opc, int *encontrado);

#endif // PREGUNTAR_LOCALIDAD_H_INCLUDED

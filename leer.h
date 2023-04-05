#ifndef LEER_H_INCLUDED
#define LEER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"

void leer(Estr_Usuario **, int *, Estr_Vehiculo **, int *, Estr_Viaje **, int *, Estr_Pasos **, int *, Estr_Reservas **, int *, Estr_Rutas ***, int *, int *, Estr_Localidad **, int *);
void leer_usuario(Estr_Usuario **, int *); //inicio de sesión en usuario existente.
void leer_vehiculo(Estr_Vehiculo **, int *);
void leer_viaje(Estr_Viaje **, int *);
void leer_pasos(Estr_Pasos **, int *);
void leer_localidad(Estr_Localidad **, int *);
void leer_ruta(Estr_Rutas ***, int *, int *);
void leer_reservas(Estr_Reservas **, int *);

#endif // LEER_H_INCLUDED

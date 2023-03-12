#ifndef LEER_H_INCLUDED
#define LEER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"

int numUsuarios;
int numVehiculos;
int numViajes;
int numPasos;
int numLocalidades;
int numRutas;
int numRutas2;

Estr_Usuario *usuario;
Estr_Vehiculo *vehiculo;
Estr_Viaje *viaje;
Estr_Pasos *pasos;
Estr_Localidad *localidad;
Estr_Rutas **ruta;

void leer();
void leer_usuario(Estr_Usuario **, int *); //inicio de sesión en usuario existente.
void leer_vehiculo(Estr_Vehiculo **, int *);
void leer_viaje(Estr_Viaje **, int *);
void leer_pasos(Estr_Pasos **, int *);
void leer_localidad(Estr_Localidad **, int *);
void leer_ruta(Estr_Rutas ***, int *, int *);

#endif // LEER_H_INCLUDED

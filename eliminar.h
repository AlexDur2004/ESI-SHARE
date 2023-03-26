#ifndef ELIMINAR_H_INCLUDED
#define ELIMINAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "leer.h"
#include "preguntar.h"
#include "encontrar.h"

void eliminarVehiculo(int);
void eliminarViaje(int, int);
void eliminarPasos(char *);
void eliminarReservas(char *);
void eliminarAdminVehiculo();
void eliminarAdminViaje();

#endif // ELIMINAR_H_INCLUDED

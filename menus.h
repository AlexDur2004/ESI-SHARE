#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "acceso.h"
#include "leer.h"

void menuPrincipal();
void menuUsuario(int);
void menuPasajero(int);
void menuPasajeroPerfil(int);
void menuPasajeroViajes(int);
void menuConductor(int);
void menuConductorPerfil(int);
void menuConductorVehiculo(int);
void menuConductorViajes(int);
void menuAdmin(int);
void menuAdminUsuarios(int);
void menuAdminVehiculos(int);
void menuAdminViajes(int);

#endif // MENUS_H_INCLUDED

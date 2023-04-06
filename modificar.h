#ifndef MODIFICAR_H_INCLUDED
#define MODIFICAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leer.h"

void modificarVehiculo(Estr_Usuario *usuario, Estr_Vehiculo *vehiculo, int numVehiculos, int i);
void modificarPerfil(int);
void modificarPerfilLocalidad(Estr_Usuario *usuario, int numUsuarios, Estr_Localidad *localidad, int numLocalidades, int i);
void modificarPerfilNombre(Estr_Usuario *usuario, int numUsuarios, int i);
void modificarPerfilUsuario(Estr_Usuario *usuario, int numUsuarios, int);
void modificarPerfilContrasena(Estr_Usuario *usuario, int numUsuarios, int);
void modificarAdminUsuario(Estr_Usuario *usuario, int numUsuarios, Estr_Localidad *localidad, int numLocalidades);
void modificarAdminVehiculo(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, int x);

#endif // MODIFICAR_H_INCLUDED

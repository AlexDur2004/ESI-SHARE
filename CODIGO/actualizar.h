#ifndef ACTUALIZAR_H_INCLUDED
#define ACTUALIZAR_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estructuras.h"

//Cabecera: void actualizarUsuario(Estr_Usuario *, int);
//Precondicion: Tener la estructura "usuario" inicializada, con sus contadores.
//Postcondicion: Reescribir todos los datos de la estructura en el fichero.
void actualizarUsuario(Estr_Usuario *, int);

//Cabecera: void actualizarVehiculo(Estr_Vehiculo *, int);
//Precondicion: Tener la estructura "vehiculo" inicializada, con sus contadores.
//Postcondicion: Reescribir todos los datos de la estructura en el fichero.
void actualizarVehiculo(Estr_Vehiculo *, int);

//Cabecera: void actualizarViaje(Estr_Viaje *, int);
//Precondicion: Tener la estructura "viaje" inicializada, con sus contadores.
//Postcondicion: Reescribir todos los datos de la estructura en el fichero.
void actualizarViaje(Estr_Viaje *, int);

#endif // ACTUALIZAR_H_INCLUDED

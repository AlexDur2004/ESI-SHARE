#ifndef LISTAR_H_INCLUDED
#define LISTAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leer.h"

//Prototipo: void listarUsuarios(Estr_Usuario *, int);
//Precondicion: Tener la estructura "usuario" inicializada, junto a su contador.
//Postcondicion: Dar una lista de todos los usuarios, que hay en la base de datos.
void listarUsuarios(Estr_Usuario *, int);

//Prototipo: void listarVehiculos(Estr_Usuario *, int, Estr_Vehiculo *, int, int);
//Precondicion: Tener las estructuras "usuario" y "vehiculo" inicializadas, junto a sus contadores.
//Postcondicion: Dar una lista de todos los vehiculos, de cada usuario, que hay en la base de datos.
void listarVehiculos(Estr_Usuario *, int, Estr_Vehiculo *, int, int);

//Prototipo: void listarAdminViajes(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, int, int, int *);
//Precondicion: Tener las estructuras "usuario", "vehiculo" y "viaje" inicializadas, junto a sus contadores.
//Postcondicion: Dar una lista de todos los viajes, de cada usuario, que hay en la base de datos.
void listarAdminViajes(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, int, int, int *);

//Prototipo: void listarAdminVehiculoViajes(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, int);
//Precondicion: Tener las estructuras "usuario", "vehiculo" y "viaje" inicializadas, junto a sus contadores.
//Postcondicion: Dar una lista de todos los viajes que ha realizado un vehiculo.
void listarAdminVehiculoViajes(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, int);

#endif // LISTAR_H_INCLUDED

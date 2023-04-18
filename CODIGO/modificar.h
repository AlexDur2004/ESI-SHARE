#ifndef MODIFICAR_H_INCLUDED
#define MODIFICAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encontrar.h"
#include "preguntar.h"
#include "actualizar.h"
#include "fecha.h"
#include "eliminar.h"
#include "buscar.h"
#include "listar.h"
#include "colores.h"
#include "escribir.h"

//Cabecera: void modificarVehiculo(Estr_Usuario *, Estr_Vehiculo *, int, Estr_Viaje *, int, int);
//Precondicion: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario",
//y las estructuras "usuario" y "vehiculo" inicializadas, con sus contadores.
//Postcondicion: Modificar cualquier dato de un vehiculo que tenga el usuario, pero este vehiculo no puede tener viajes abiertos, con plazas ocupadas, ni cerrados ni iniciados.
void modificarVehiculo(Estr_Usuario *, Estr_Vehiculo *, int, Estr_Viaje *, int, int);

//Cabecera: void modificarViaje(Estr_Usuario *, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondicion: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y las estructuras inicializadas, con sus contadores.
//Postcondicion: Modificar cualquier dato de un viaje, que este abierto y sin plazas reservadas, que tenga el usuario.
void modificarViaje(Estr_Usuario *, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);

//Cabecera: void modificarPerfilNombre(Estr_Usuario *, int, int);
//Precondicion: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y la estructura "usuario" inicializada, con su contador.
//Postcondicion: Modificar el nombre del usuario.
void modificarPerfilNombre(Estr_Usuario *, int, int);

//Cabecera: void modificarPerfilLocalidad(Estr_Usuario *, int, Estr_Localidad *, int, int);
//Precondicion: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y la estructura "usuario" inicializada, con su contador.
//Postcondicion: Modificar la localidad del usuario.
void modificarPerfilLocalidad(Estr_Usuario *, int, Estr_Localidad *, int, int);

//Cabecera: void modificarPerfilUsuario(Estr_Usuario *, int, int);
//Precondicion: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y la estructura "usuario" inicializada, con su contador.
//Postcondicion: Modificar el username del usuario.
void modificarPerfilUsuario(Estr_Usuario *, int, int);

//Cabecera: void modificarPerfilContrasena(Estr_Usuario *, int, int);
//Precondicion: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y la estructura "usuario" inicializada, con su contador.
//Postcondicion: Modificar la contrasena del usuario.
void modificarPerfilContrasena(Estr_Usuario *, int, int);

//Cabecera: void modificarAdminUsuario(Estr_Usuario *, int, Estr_Localidad *, int);
//Precondicion: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y las estructuras inicializadas, con sus contadores.
//Postcondicion: Modificar los datos de cualquier usuario.
void modificarAdminUsuario(Estr_Usuario *, int, Estr_Localidad *, int);

//Cabecera: void modificarAdminVehiculo(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, int);
//Precondicion: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y las estructuras inicializadas, con sus contadores.
//Postcondicion: Modificar los datos de un vehiculo, que no tenga viajes abiertos, con plazas ocupadas, ni iniciados ni cerrados, de cualquier usuario.
void modificarAdminVehiculo(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, int);

//Cabecera: void modificarAdminViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondicion: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y las estructuras inicializadas, con sus contadores.
//Postcondicion: Modificar los datos de un viaje de cualquier usuario.
void modificarAdminViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);

#endif // MODIFICAR_H_INCLUDED

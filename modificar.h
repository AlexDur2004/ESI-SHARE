#ifndef MODIFICAR_H_INCLUDED
#define MODIFICAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leer.h"

//Prototipo: void modificarVehiculo(Estr_Usuario *, Estr_Vehiculo *, int, int);
//Precondición: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario",
//y las estructuras "usuario" y "vehiculo" inicializadas, con sus contadores.
//Postcondición: Modificar cualquier dato de un vehiculo que tenga el usuario.
void modificarVehiculo(Estr_Usuario *, Estr_Vehiculo *, int, int);

//Prototipo: void modificarViaje(Estr_Usuario *, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondición: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y las estructuras inicializadas, con sus contadores.
//Postcondición: Modificar cualquier dato de un viaje, que esté abierto y sin plazas reservadas, que tenga el usuario.
void modificarViaje(Estr_Usuario *, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);

//Prototipo: void modificarRuta(Estr_Usuario *, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondición: Tener el entero "num_user", para saber la posicion del usuario en la estructura "usuario", y las estructuras inicializadas, con sus contadores.
//Postcondición: Modificar la ruta de un viaje, que esté abierto y sin plazas reservadas, que tenga el usuario.
void modificarRuta(Estr_Usuario *, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);

//Prototipo: void modificarPerfilNombre(Estr_Usuario *, int, int);
//Precondición: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y la estructura "usuario" inicializada, con su contador.
//Postcondición: Modificar el nombre del usuario.
void modificarPerfilNombre(Estr_Usuario *, int, int);

//Prototipo: void modificarPerfilLocalidad(Estr_Usuario *, int, Estr_Localidad *, int, int);
//Precondición: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y la estructura "usuario" inicializada, con su contador.
//Postcondición: Modificar la localidad del usuario.
void modificarPerfilLocalidad(Estr_Usuario *, int, Estr_Localidad *, int, int);

//Prototipo: void modificarPerfilUsuario(Estr_Usuario *, int, int);
//Precondición: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y la estructura "usuario" inicializada, con su contador.
//Postcondición: Modificar el username del usuario.
void modificarPerfilUsuario(Estr_Usuario *, int, int);

//Prototipo: void modificarPerfilContrasena(Estr_Usuario *, int, int);
//Precondición: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y la estructura "usuario" inicializada, con su contador.
//Postcondición: Modificar la contraseña del usuario.
void modificarPerfilContrasena(Estr_Usuario *, int, int);

//Prototipo: void modificarAdminUsuario(Estr_Usuario *, int, Estr_Localidad *, int);
//Precondición: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y las estructuras inicializadas, con sus contadores.
//Postcondición: Modificar los datos de cualquier usuario.
void modificarAdminUsuario(Estr_Usuario *, int, Estr_Localidad *, int);

//Prototipo: void modificarAdminVehiculo(Estr_Usuario *, int, Estr_Vehiculo *, int, int);
//Precondición: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y las estructuras inicializadas, con sus contadores.
//Postcondición: Modificar los datos de un vehiculo de cualquier usuario.
void modificarAdminVehiculo(Estr_Usuario *, int, Estr_Vehiculo *, int, int);

//Prototipo: void modificarAdminViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondición: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y las estructuras inicializadas, con sus contadores.
//Postcondición: Modificar los datos de un viaje de cualquier usuario.
void modificarAdminViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);

#endif // MODIFICAR_H_INCLUDED

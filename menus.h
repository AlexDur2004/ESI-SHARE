#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "leer.h"

//Prototipo: void menuPrincipal(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int);
//Precondición: Tener las estructuras inicializados, con sus contadores.
//Postcondición: Llevarte a las diferentes funciones, a partir de la opción que se escriba.
void menuPrincipal(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int);

//Prototipo: void menuUsuario(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondición: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//También necesitamos las estructuras inicializados, con sus contadores.
//Postcondición: Llevarte a las diferentes funciones, a partir de la opción que se escriba.
void menuUsuario(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);

//Prototipo: void menuPasajero(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondición: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//También necesitamos las estructuras inicializados, con sus contadores.
//Postcondición: Llevarte a las diferentes funciones, a partir de la opción que se escriba.
void menuPasajero(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);

//Prototipo: void menuPasajeroPerfil(Estr_Usuario *, int, Estr_Localidad *, int, int);
//Precondición: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//También necesitamos las estructuras inicializados, con sus contadores.
//Postcondición: Llevarte a las diferentes funciones, a partir de la opción que se escriba.
void menuPasajeroPerfil(Estr_Usuario *, int, Estr_Localidad *, int, int);

//Prototipo: void menuPasajeroViajes(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondición: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//También necesitamos las estructuras inicializados, con sus contadores.
//Postcondición: Llevarte a las diferentes funciones, a partir de la opción que se escriba.
void menuPasajeroViajes(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);

//Prototipo: void menuConductor(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondición: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//También necesitamos las estructuras inicializados, con sus contadores.
//Postcondición: Llevarte a las diferentes funciones, a partir de la opción que se escriba.
void menuConductor(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);

//Prototipo: void menuConductorPerfil(Estr_Usuario *, int, Estr_Localidad *, int, int);
//Precondición: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//También necesitamos las estructuras inicializados, con sus contadores.
//Postcondición: Llevarte a las diferentes funciones, a partir de la opción que se escriba.
void menuConductorPerfil(Estr_Usuario *, int, Estr_Localidad *, int, int);

//Prototipo: void menuConductorVehiculo(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondición: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//También necesitamos las estructuras inicializados, con sus contadores.
//Postcondición: Llevarte a las diferentes funciones, a partir de la opción que se escriba.
void menuConductorVehiculo(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);

//Prototipo: void menuConductorViajes(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondición: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//También necesitamos las estructuras inicializados, con sus contadores.
//Postcondición: Llevarte a las diferentes funciones, a partir de la opción que se escriba.
void menuConductorViajes(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);

//Prototipo: void menuAdmin(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondición: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//También necesitamos las estructuras inicializados, con sus contadores.
//Postcondición: Llevarte a las diferentes funciones, a partir de la opción que se escriba.
void menuAdmin(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);

//Prototipo: void menuAdminUsuarios(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondición: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//También necesitamos las estructuras inicializados, con sus contadores.
//Postcondición: Llevarte a las diferentes funciones, a partir de la opción que se escriba.
void menuAdminUsuarios(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);

//Prototipo: void menuAdminVehiculos(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondición: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//También necesitamos las estructuras inicializados, con sus contadores.
//Postcondición: Llevarte a las diferentes funciones, a partir de la opción que se escriba.
void menuAdminVehiculos(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);

//Prototipo: void menuAdminViajes(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondición: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//También necesitamos las estructuras inicializados, con sus contadores.
//Postcondición: Llevarte a las diferentes funciones, a partir de la opción que se escriba.
void menuAdminViajes(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);

#endif // MENUS_H_INCLUDED

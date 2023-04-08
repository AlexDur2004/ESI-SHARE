#ifndef ELIMINAR_H_INCLUDED
#define ELIMINAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leer.h"

//Prototipo: void eliminarVehiculo(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);
//Precondición: Tener la variable "i" inicializada, que representa al usuario en la estructura "Usuarios",
//también necesitaremos las estructuras "Vehiculo", "Viajes", "Pasos" y "Reservas", con sus respectivos contadores.
//Postcondición: Preguntar al usuario, qué vehículo quiere eliminar de todos los que tiene, para
//eliminar el vehiculo, con sus viajes, pasos y reservas.
void eliminarVehiculo(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);

//Prototipo: void eliminarVehiculoViajes(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, char *, int);
//Precondición: Tener la cadena "mat", que sería la matrícula del vehículo que se quiere eliminar, y la variable "x", que representa el número
//de vehículos que tiene el usuario, también necesitaremos las estructuras "Vehiculo", "Viajes", "Pasos" y "Reservas", con sus respectivos contadores.
//Postcondición: Eliminar el vehículo, a partir de la matrícula, además de todos sus viajes, pasos y reservas.
void eliminarVehiculoViajes(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, char *, int);

//Prototipo: void eliminarViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);
//Precondición: Tener la variable "i" inicializada, que representa al usuario en la estructura "Usuarios",
//Además se necesitarán las estructuras "Vehiculo", "Viajes", "Pasos" y "Reservas", y sus respectivos contadores.
//Postcondición: Preguntar al usuario, qué viaje quiere eliminar de todos los que tiene, para eliminar el viaje, con sus pasos y reservas.
void eliminarViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);

//Prototipo: void eliminarSoloViaje(Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, char *);
//Precondición: Tener la cadena "id" inicializada, que representa la id del viaje, que se quiere eliminar,
//al igual que las estructura "viaje", "pasos" y "reservas", con sus respectivos contadores.
//Postcondición: Eliminar un viaje, a partir de su id, junto a todos sus pasos y reservas.
void eliminarSoloViaje(Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, char *);

//Prototipo: void eliminarPasos(Estr_Pasos *, int, char *);
//Precondición: Tener la cadena "id" inicializada, que representa la id del viaje, al igual que la estructura "pasos", y su contador "numPasos".
//Postcondición: Eliminar los pasos de un viaje.
void eliminarPasos(Estr_Pasos *, int, char *);

//Prototipo: void eliminarReservas(Estr_Reservas *, int, char *);
//Precondición: Tener la cadena "id" inicializada, que representa la id del viaje, al igual que la estructura "reservas", y su contador "numReservas".
//Postcondición: Eliminar las reservas de un viaje.
void eliminarReservas(Estr_Reservas *, int, char *);

//Prototipo: void eliminarAdminUsuario(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int);
//Precondición: Tener las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas",
//al igual que sus contadores "numUsuarios", "numVehiculos", "numViajes", "numPasos" y "numReservas".
//Postcondición: Preguntar al admin, la id del usuario que quiere eliminar, para borrar dicho usuario, junto a todos sus vehículos, viajes, pasos y reservas.
void eliminarAdminUsuario(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int);

//Prototipo: void eliminarAdminVehiculo(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);
//Precondición: Tener las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas",
//al igual que sus contadores "numUsuarios", "numVehiculos", "numViajes", "numPasos" y "numReservas".
//Postcondición: Preguntar al admin, la id del usuario para saber sus vehículos, y eliminar dicho vehículo, y todos sus viajes, pasos y reservas.
void eliminarAdminVehiculo(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);

//Prototipo: void eliminarAdminViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int, int);
//Precondición: Tener la variable "num", y las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas",
//al igual que sus contadores "numUsuarios", "numVehiculos", "numViajes", "numPasos" y "numReservas".
//Postcondición: Preguntar al admin, la id del usuario para saber sus vehículos, y con todas sus matrículas, localizar sus viajes.
//Si num=0, elimina un viaje, y si num=1, anula/finaliza un viaje, depende de su estado. Todo esto eliminando todos sus pasos y reservas.
void eliminarAdminViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int, int);

#endif // ELIMINAR_H_INCLUDED

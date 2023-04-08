#ifndef ELIMINAR_H_INCLUDED
#define ELIMINAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leer.h"

//Prototipo: void eliminarVehiculo(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);
//Precondici�n: Tener la variable "i" inicializada, que representa al usuario en la estructura "Usuarios",
//tambi�n necesitaremos las estructuras "Vehiculo", "Viajes", "Pasos" y "Reservas", con sus respectivos contadores.
//Postcondici�n: Preguntar al usuario, qu� veh�culo quiere eliminar de todos los que tiene, para
//eliminar el vehiculo, con sus viajes, pasos y reservas.
void eliminarVehiculo(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);

//Prototipo: void eliminarVehiculoViajes(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, char *, int);
//Precondici�n: Tener la cadena "mat", que ser�a la matr�cula del veh�culo que se quiere eliminar, y la variable "x", que representa el n�mero
//de veh�culos que tiene el usuario, tambi�n necesitaremos las estructuras "Vehiculo", "Viajes", "Pasos" y "Reservas", con sus respectivos contadores.
//Postcondici�n: Eliminar el veh�culo, a partir de la matr�cula, adem�s de todos sus viajes, pasos y reservas.
void eliminarVehiculoViajes(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, char *, int);

//Prototipo: void eliminarViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);
//Precondici�n: Tener la variable "i" inicializada, que representa al usuario en la estructura "Usuarios",
//Adem�s se necesitar�n las estructuras "Vehiculo", "Viajes", "Pasos" y "Reservas", y sus respectivos contadores.
//Postcondici�n: Preguntar al usuario, qu� viaje quiere eliminar de todos los que tiene, para eliminar el viaje, con sus pasos y reservas.
void eliminarViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);

//Prototipo: void eliminarSoloViaje(Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, char *);
//Precondici�n: Tener la cadena "id" inicializada, que representa la id del viaje, que se quiere eliminar,
//al igual que las estructura "viaje", "pasos" y "reservas", con sus respectivos contadores.
//Postcondici�n: Eliminar un viaje, a partir de su id, junto a todos sus pasos y reservas.
void eliminarSoloViaje(Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, char *);

//Prototipo: void eliminarPasos(Estr_Pasos *, int, char *);
//Precondici�n: Tener la cadena "id" inicializada, que representa la id del viaje, al igual que la estructura "pasos", y su contador "numPasos".
//Postcondici�n: Eliminar los pasos de un viaje.
void eliminarPasos(Estr_Pasos *, int, char *);

//Prototipo: void eliminarReservas(Estr_Reservas *, int, char *);
//Precondici�n: Tener la cadena "id" inicializada, que representa la id del viaje, al igual que la estructura "reservas", y su contador "numReservas".
//Postcondici�n: Eliminar las reservas de un viaje.
void eliminarReservas(Estr_Reservas *, int, char *);

//Prototipo: void eliminarAdminUsuario(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int);
//Precondici�n: Tener las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas",
//al igual que sus contadores "numUsuarios", "numVehiculos", "numViajes", "numPasos" y "numReservas".
//Postcondici�n: Preguntar al admin, la id del usuario que quiere eliminar, para borrar dicho usuario, junto a todos sus veh�culos, viajes, pasos y reservas.
void eliminarAdminUsuario(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int);

//Prototipo: void eliminarAdminVehiculo(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);
//Precondici�n: Tener las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas",
//al igual que sus contadores "numUsuarios", "numVehiculos", "numViajes", "numPasos" y "numReservas".
//Postcondici�n: Preguntar al admin, la id del usuario para saber sus veh�culos, y eliminar dicho veh�culo, y todos sus viajes, pasos y reservas.
void eliminarAdminVehiculo(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);

//Prototipo: void eliminarAdminViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int, int);
//Precondici�n: Tener la variable "num", y las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas",
//al igual que sus contadores "numUsuarios", "numVehiculos", "numViajes", "numPasos" y "numReservas".
//Postcondici�n: Preguntar al admin, la id del usuario para saber sus veh�culos, y con todas sus matr�culas, localizar sus viajes.
//Si num=0, elimina un viaje, y si num=1, anula/finaliza un viaje, depende de su estado. Todo esto eliminando todos sus pasos y reservas.
void eliminarAdminViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int, int);

#endif // ELIMINAR_H_INCLUDED

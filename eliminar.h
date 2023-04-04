#ifndef ELIMINAR_H_INCLUDED
#define ELIMINAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "leer.h"
#include "preguntar.h"
#include "encontrar.h"

//Prototipo: void eliminarVehiculo(int);
//Precondición: Tener la variable "i" inicializada, que representa al usuario en la estructura "Usuarios",
//también necesitaremos las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas".
//Postcondición: Eliminar el vehículo que seleccione el usuario de la lista de sus vehículos, si hace esto
//se eliminarán todos los viajes, pasos y reservas de dicho vehículo.
void eliminarVehiculo(int);

//Prototipo: void eliminarVehiculoViajes(char *, int);
//Precondición: Tener la cadena "mat", que sería la matrícula del vehículo que se quiere eliminar, y la variable "x",
//que representa el número de vehículos que tiene el usuario, también necesitaremos las estructuras "Vehiculo", "Viajes", "Pasos" y "Reservas".
//Postcondición: Eliminar el vehículo, a partir de la matrícula, además de todos sus viajes, pasos y reservas.
void eliminarVehiculoViajes(char *, int);

//Prototipo: void eliminarViaje(int);
//Precondición: Tener la variable "i" inicializada, que representa al usuario en la estructura "Usuarios",
//e introducir la variable "num", 0 para admin, y 1 para conductor. Además se necesitarán las estructuras
//"Vehiculo", "Viajes", "Pasos" y "Reservas", el contador "numVehiculos".
//Postcondición: Eliminar el viaje que seleccione el usuario de la lista de sus viajes, si hace esto
//se eliminarán todos los pasos y reservas de dicho viaje.
void eliminarViaje(int);

//Prototipo: void eliminarSoloViaje(char *);
//Precondición: Tener la cadena "id" inicializada, que representa la id del viaje, que se quiere eliminar,
//al igual que las estructura "viaje", "pasos" y "reservas", y su contador "numViajes".
//Postcondición: Eliminar un viaje, junto a todos sus pasos y reservas.
void eliminarSoloViaje(char *);

//Prototipo: void eliminarPasos(char *);
//Precondición: Tener la cadena "id" inicializada, que representa la id del viaje, al igual que la estructura "pasos", y su contador "numPasos".
//Postcondición: Eliminar los pasos de un viaje.
void eliminarPasos(char *);

//Prototipo: void eliminarReservas(char *);
//Precondición: Tener la cadena "id" inicializada, que representa la id del viaje, al igual que la estructura "reservas", y su contador "numReservas".
//Postcondición: Eliminar las reservas de un viaje.
void eliminarReservas(char *);

//Prototipo: void eliminarAdminUsuario();
//Precondición: Tener las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas",
//al igual que sus contadores "numUsuarios", "numVehiculos", "numViajes", "numPasos" y "numReservas".
//Postcondición: Preguntar al admin, la id del usuario que quiere eliminar, y eliminar el usuario,
//y todos sus vehículos, viajes, pasos y reservas.
void eliminarAdminUsuario();

//Prototipo: void eliminarAdminVehiculo();
//Precondición: Tener las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas",
//al igual que sus contadores "numUsuarios", "numVehiculos", "numViajes", "numPasos" y "numReservas".
//Postcondición: Preguntar al admin, la id del usuario para saber sus vehículos, y eliminar
//el vehículo, y todos sus viajes, pasos y reservas.
void eliminarAdminVehiculo();

//Prototipo: void eliminarAdminViaje(int);
//Precondición: Tener la variable "num, y las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas",
//al igual que sus contadores "numUsuarios", "numVehiculos", "numViajes", "numPasos" y "numReservas".
//Postcondición: Preguntar al admin, la id del usuario para saber sus vehículos, y con todas sus matrículas,
//localizar sus viajes. Si num=0, elimina un viaje, y si num=1, anula/finaliza un viaje, depende de su estado.
//Todo esto eliminando todos sus pasos y reservas.
void eliminarAdminViaje(int, int);

#endif // ELIMINAR_H_INCLUDED

#ifndef ELIMINAR_H_INCLUDED
#define ELIMINAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leer.h"
#include "preguntar.h"
#include "encontrar.h"

//Prototipo: void eliminarVehiculo(int);
//Precondici�n: Tener la variable "i" inicializada, que representa al usuario en la estructura "Usuarios",
//tambi�n necesitaremos las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas".
//Postcondici�n: Eliminar el veh�culo que seleccione el usuario de la lista de sus veh�culos, si hace esto
//se eliminar�n todos los viajes, pasos y reservas de dicho veh�culo.
void eliminarVehiculo(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);

//Prototipo: void eliminarVehiculoViajes(char *, int);
//Precondici�n: Tener la cadena "mat", que ser�a la matr�cula del veh�culo que se quiere eliminar, y la variable "x",
//que representa el n�mero de veh�culos que tiene el usuario, tambi�n necesitaremos las estructuras "Vehiculo", "Viajes", "Pasos" y "Reservas".
//Postcondici�n: Eliminar el veh�culo, a partir de la matr�cula, adem�s de todos sus viajes, pasos y reservas.
void eliminarVehiculoViajes(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, char *, int);

//Prototipo: void eliminarViaje(int);
//Precondici�n: Tener la variable "i" inicializada, que representa al usuario en la estructura "Usuarios",
//e introducir la variable "num", 0 para admin, y 1 para conductor. Adem�s se necesitar�n las estructuras
//"Vehiculo", "Viajes", "Pasos" y "Reservas", el contador "numVehiculos".
//Postcondici�n: Eliminar el viaje que seleccione el usuario de la lista de sus viajes, si hace esto
//se eliminar�n todos los pasos y reservas de dicho viaje.
void eliminarViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);

//Prototipo: void eliminarSoloViaje(char *);
//Precondici�n: Tener la cadena "id" inicializada, que representa la id del viaje, que se quiere eliminar,
//al igual que las estructura "viaje", "pasos" y "reservas", y su contador "numViajes".
//Postcondici�n: Eliminar un viaje, junto a todos sus pasos y reservas.
void eliminarSoloViaje(Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, char *id);

//Prototipo: void eliminarPasos(char *);
//Precondici�n: Tener la cadena "id" inicializada, que representa la id del viaje, al igual que la estructura "pasos", y su contador "numPasos".
//Postcondici�n: Eliminar los pasos de un viaje.
void eliminarPasos(Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, char *id);

//Prototipo: void eliminarReservas(char *);
//Precondici�n: Tener la cadena "id" inicializada, que representa la id del viaje, al igual que la estructura "reservas", y su contador "numReservas".
//Postcondici�n: Eliminar las reservas de un viaje.
void eliminarReservas(Estr_Reservas *reservas, int numReservas, char *);

//Prototipo: void eliminarAdminUsuario();
//Precondici�n: Tener las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas",
//al igual que sus contadores "numUsuarios", "numVehiculos", "numViajes", "numPasos" y "numReservas".
//Postcondici�n: Preguntar al admin, la id del usuario que quiere eliminar, y eliminar el usuario,
//y todos sus veh�culos, viajes, pasos y reservas.
void eliminarAdminUsuario(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas);

//Prototipo: void eliminarAdminVehiculo();
//Precondici�n: Tener las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas",
//al igual que sus contadores "numUsuarios", "numVehiculos", "numViajes", "numPasos" y "numReservas".
//Postcondici�n: Preguntar al admin, la id del usuario para saber sus veh�culos, y eliminar
//el veh�culo, y todos sus viajes, pasos y reservas.
void eliminarAdminVehiculo(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, int x);

//Prototipo: void eliminarAdminViaje(int);
//Precondici�n: Tener la variable "num, y las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas",
//al igual que sus contadores "numUsuarios", "numVehiculos", "numViajes", "numPasos" y "numReservas".
//Postcondici�n: Preguntar al admin, la id del usuario para saber sus veh�culos, y con todas sus matr�culas,
//localizar sus viajes. Si num=0, elimina un viaje, y si num=1, anula/finaliza un viaje, depende de su estado.
//Todo esto eliminando todos sus pasos y reservas.
void eliminarAdminViaje(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, int x, int num);

#endif // ELIMINAR_H_INCLUDED

#ifndef ELIMINAR_H_INCLUDED
#define ELIMINAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leer.h"
#include "encontrar.h"
#include "preguntar.h"
#include "listar.h"
#include "actualizar.h"

//Prototipo: void eliminarVehiculo(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);
//Precondicion: Tener la variable "i" inicializada, que representa al usuario en la estructura "Usuarios",
//tambien necesitaremos las estructuras "Vehiculo", "Viajes", "Pasos" y "Reservas", con sus respectivos contadores.
//Postcondicion: Preguntar al usuario, que vehiculo quiere eliminar de todos los que tiene, para eliminar el vehiculo, con sus viajes, pasos y reservas.
void eliminarVehiculo(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);

//Prototipo: void eliminarVehiculoViajes(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, char *, int);
//Precondicion: Tener la cadena "mat", que seria la matricula del vehiculo que se quiere eliminar, y la variable "x", que representa el numero
//de vehiculos que tiene el usuario, tambien necesitaremos las estructuras "Vehiculo", "Viajes", "Pasos" y "Reservas", con sus respectivos contadores.
//Postcondicion: Eliminar el vehiculo, a partir de la matricula, ademas de todos sus viajes, pasos y reservas.
void eliminarVehiculoViajes(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, char *, int);

//Prototipo: void eliminarViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);
//Precondicion: Tener la variable "i" inicializada, que representa al usuario en la estructura "Usuarios",
//Ademas se necesitaran las estructuras "Vehiculo", "Viajes", "Pasos" y "Reservas", y sus respectivos contadores.
//Postcondicion: Preguntar al usuario, que viaje quiere eliminar de todos los que tiene, para eliminar el viaje, con sus pasos y reservas.
void eliminarViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);

//Prototipo: void eliminarSoloViaje(Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, char *);
//Precondicion: Tener la cadena "id" inicializada, que representa la id del viaje, que se quiere eliminar,
//al igual que las estructura "viaje", "pasos" y "reservas", con sus respectivos contadores.
//Postcondicion: Eliminar un viaje, a partir de su id, junto a todos sus pasos y reservas.
void eliminarSoloViaje(Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, char *);

//Prototipo: void eliminarPasos(Estr_Pasos *, int, char *);
//Precondicion: Tener la cadena "id" inicializada, que representa la id del viaje, al igual que la estructura "pasos", y su contador "numPasos".
//Postcondicion: Eliminar los pasos de un viaje.
void eliminarPasos(Estr_Pasos *, int, char *);

//Prototipo: void eliminarReservas(Estr_Reservas *, int, char *);
//Precondicion: Tener la cadena "id" inicializada, que representa la id del viaje, al igual que la estructura "reservas", y su contador "numReservas".
//Postcondicion: Eliminar las reservas de un viaje.
void eliminarReservas(Estr_Reservas *, int, char *);

//Prototipo: void eliminarAdminUsuario(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int);
//Precondicion: Tener las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas",
//al igual que sus contadores "numUsuarios", "numVehiculos", "numViajes", "numPasos" y "numReservas".
//Postcondicion: Preguntar al admin, la id del usuario que quiere eliminar, para borrar dicho usuario, junto a todos sus vehiculos, viajes, pasos y reservas.
void eliminarAdminUsuario(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int);

//Prototipo: void eliminarAdminVehiculo(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);
//Precondicion: Tener las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas",
//al igual que sus contadores "numUsuarios", "numVehiculos", "numViajes", "numPasos" y "numReservas".
//Postcondicion: Preguntar al admin, la id del usuario para saber sus vehiculos, y eliminar dicho vehiculo, y todos sus viajes, pasos y reservas.
void eliminarAdminVehiculo(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);

//Prototipo: void eliminarAdminViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int, int);
//Precondicion: Tener la variable "num", y las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas",
//al igual que sus contadores "numUsuarios", "numVehiculos", "numViajes", "numPasos" y "numReservas".
//Postcondicion: Preguntar al admin, la id del usuario para saber sus vehiculos, y con todas sus matriculas, localizar sus viajes.
//Si num=0, elimina un viaje, y si num=1, anula/finaliza un viaje, depende de su estado. Todo esto eliminando todos sus pasos y reservas.
void eliminarAdminViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int, int);

//Prototipo:void finalizar_viaje(Estr_Usuario *, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);
//Precondicion://Precondicion:se necesitara la variable numuser que respresenta al usuario en la estructura Usuarios;
//ademas se necesitaran las estructuras de "vehiculos", "viajes", "pasos", "reservas", con sus respectivos contadores.
//Cabecera: esta funcion tiene una doble finalidad, que seran finalizar y anular los viajes del conductor.
//Postcondicion: el viaje elegido por el usuario sera finalizado o anulado, modificandose el estado del viaje.
void finalizar_viaje(Estr_Usuario *, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);

//Prototipo: void cancelarReserva(Estr_Usuario *, Estr_Viaje *, int, Estr_Reservas *, int, int);
//Precondicion:esta funcion recibe las estructuras "Usuario" y "Viajes" ya inicializadas con sus contadores, y la variables num user que representa la posicion del usuario en la estructura viajes.
//Cabecera:esta funcion permite al usuario cancelar sus viajes siempre que no esten iniciados.
//Postcondicion:el viaje seleccionado es cancelado siendo borrado de la estructura reservas el usuario y aumentando en uno las plazas de dicho viaje.
void cancelarReserva(Estr_Usuario *, Estr_Viaje *, int, Estr_Reservas *, int, int);

#endif // ELIMINAR_H_INCLUDED

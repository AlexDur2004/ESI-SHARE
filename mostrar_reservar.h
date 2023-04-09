#ifndef MOSTRAR_RESERVAR_H_INCLUDED
#define MOSTRAR_RESERVAR_H_INCLUDED

#include "encontrar.h"
#include "leer.h"
#include "fecha.h"
#include "eliminar.h"
//Prototipo:void mostrar_reservar(Estr_Usuario *, int , Estr_Vehiculo *, int , Estr_Viaje *, int , Estr_Pasos *, int , Estr_Reservas *, int , int )
//Precondicion://Precondicion:se necesitara la variable numUsuarios que respresenta al usuario en la estructura Usuarios;
//ádemas se necesitaran las estructuras de "vehiculos", "viajes", "pasos", "reservas", "localidad", "rutas", con sus respectivos contadores.
//Cabecera: esta funcion en dependencia de la fecha elegida por el usuario le seran mostrados todos lo viajes disponibles impidiendole elegir los viajes ya reservados previamente o creados por el
//Postcondicion:en el fichero reserva se guardara la id del viaje que el usuario haya elegido y su id y se restara una plaza al viaje, dato que tambine se modidificara en el fichero
void mostrar_reservar(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, int num_user);
//Prototipo:void cancelarReserva(Estr_Usuario *, Estr_Viaje *, int , Estr_Reservas *, int , int )
//Precondicion:esta funcion recibe las estructuras "Usuario" y "Viajes" ya inicializadas con sus contadores, y la variables num user
//que representa la posicion del usuario en la estructura viajes
//Cabecera:esta funcion permite al usuario cancelar sus viajes siempre que no esten iniciados
//Postcondicion:el viaje seleccionado es cancelado siendo borrado de la estructura reservas el usuario
//y aumentando en uno las plazas de dicho viaje
void cancelarReserva(Estr_Usuario *usuario, Estr_Viaje *viaje, int numViajes, Estr_Reservas *reservas, int numReservas, int num_user);

#endif // MOSTRAR_RESERVAR_H_INCLUDED

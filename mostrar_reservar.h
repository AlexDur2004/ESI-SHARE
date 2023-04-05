#ifndef MOSTRAR_RESERVAR_H_INCLUDED
#define MOSTRAR_RESERVAR_H_INCLUDED

#include "encontrar.h"
#include "leer.h"
#include "fecha.h"
#include "eliminar.h"

void mostrar_reservar(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, int num_user);
void cancelarReserva(Estr_Usuario *usuario, Estr_Viaje *viaje, int numViajes, Estr_Reservas *reservas, int numReservas, int num_user);

#endif // MOSTRAR_RESERVAR_H_INCLUDED

#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <time.h>
#include "leer.h"

void actualizarViajes(Estr_Viaje *viaje, int numViajes, Estr_Reservas *reservas, int numReservas);
void leerFecha(char *, char *, char *); //para leer fecha, hora inic, hora fin.
void leer_dia(char *); //para leer fecha.

#endif // FECHA_H_INCLUDED

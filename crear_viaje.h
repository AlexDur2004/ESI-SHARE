#ifndef CREAR_VIAJE_H_INCLUDED
#define CREAR_VIAJE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leer.h"
//Prototipo:void altaViaje(Estr_Usuario *, int , Estr_Vehiculo *, int , Estr_Viaje *, int numViajes, Estr_Pasos *, int , Estr_Reservas *, int , Estr_Localidad *, int , Estr_Rutas **, int , int , int , int );
//Precondicion:se necesitara la variable numUsuarios que respresenta al usuario en la estructura Usuarios;
//ádemas se necesitaran las estructuras de "vehiculos", "viajes", "pasos", "reservas", "localidad", "rutas", con sus respectivos contadores.
//Cabecera:esta funcion se usa para que el conductor cree viajes ingresando valores como la matricula del coche la fecha, las horas de inicio y fin o el coste,
//y asignadose otros valores automaticamente como el esatdo del viaje, la id del viaje o las plazas de este.
//Postcondicion:se crea una nueva estructura "Viajes" que contendra los datos correspondientes al nuevo viaje creado por el conductor y se habra añadido al fichero el nuevo viaje

void altaViaje(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int num_usuario, int num);
void elegir_coche(Estr_Usuario *, int , Estr_Vehiculo *, int , Estr_Viaje *, int , Estr_Pasos *, int , Estr_Reservas *, int , Estr_Localidad *, int , Estr_Rutas **, int , int , int , char *, int )
#endif

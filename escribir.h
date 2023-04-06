#ifndef ESCRIBIR_H_INCLUDED
#define ESCRIBIR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leer.h"

//Prototipo: void altaUsuario();
//Precondición: Tener la estructura "usuario" inicializada, con su contador "numUsuarios".
//Postcondición: Dar de alta/Registrar un usuario, comprobando que el nombre del usuario no está repetido.
void altaUsuario(Estr_Usuario *usuario, int numUsuarios, Estr_Localidad *localidad, int numLocalidades);

//Prototipo: void altaVehiculo(int);
//Precondición: Tener la variable "i", con la posición del usuario en la estructura "usuario", y
//las estructuras "vehiculo" y "usuario" inicializadas, con sus contadores "numVehiculos".
//Postcondición: Dar de alta/Registrar un vehículo, comprobando que la matrícula es válida, y no está en uso.
void altaVehiculo(Estr_Usuario *usuario, Estr_Vehiculo *vehiculo, int numVehiculos, int i);

//Prototipo: void altaAdmin(int);
//Precondición: Necesario la introducción de un entero, para saber si queremos registrar un vehiculo o un viaje.
//Tener las estructuras "vehiculo", "viajes" y "usuario" inicializadas, con sus contadores "numVehiculos", "numViajes" y "numUsuarios".
//Postcondición: Si n=0, dar de alta/registrar un vehículo, comprobando que la matrícula es válida, y no está en uso,
//y si n=1, dar de alta/registrar un viaje. Ambos, introduciendo la id del usuario al que se quiere crear.
void altaAdmin(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int n);

#endif // ESCRIBIR_H_INCLUDED

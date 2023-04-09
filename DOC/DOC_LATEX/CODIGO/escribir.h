#ifndef ESCRIBIR_H_INCLUDED
#define ESCRIBIR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leer.h"

//Prototipo: void altaUsuario(Estr_Usuario *, int, Estr_Localidad *, int);
//Precondicion: Tener las estructuras "usuario" y "localidad" inicializada, con sus contadores "numUsuarios" y "numLocalidades".
//Postcondicion: Dar de alta/Registrar un usuario, comprobando que el nombre del usuario no esta repetido.
void altaUsuario(Estr_Usuario *, int, Estr_Localidad *, int);

//Prototipo: void altaVehiculo(Estr_Usuario *, Estr_Vehiculo *, int, int);
//Precondicion: Tener la variable "i", con la posicion del usuario en la estructura "usuario", y las estructuras "vehiculo" y "usuario" inicializadas, con su contador "numVehiculos".
//Postcondicion: Dar de alta/Registrar un vehiculo, comprobando que la matricula es valida, y no esta en uso.
void altaVehiculo(Estr_Usuario *, Estr_Vehiculo *, int, int);

//Prototipo: void altaAdmin(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondicion: Necesario la introduccion de un entero, para saber si queremos registrar un vehiculo o un viaje. Tener las estructuras inicializadas, con sus contadores.
//Postcondicion: Si n=0, dar de alta/registrar un vehiculo, comprobando que la matricula es valida, y no esta en uso,
//y si n=1, dar de alta/registrar un viaje. Ambos, introduciendo la id del usuario al que se quiere crear.
void altaAdmin(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);

#endif // ESCRIBIR_H_INCLUDED

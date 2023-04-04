#ifndef ESCRIBIR_H_INCLUDED
#define ESCRIBIR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "leer.h"
#include "preguntar.h"

//Prototipo: void altaUsuario();
//Precondici�n: Tener la estructura "usuario" inicializada, con su contador "numUsuarios".
//Postcondici�n: Dar de alta/Registrar un usuario, comprobando que el nombre del usuario no est� repetido.
void altaUsuario();

//Prototipo: void altaVehiculo(int);
//Precondici�n: Tener la variable "i", con la posici�n del usuario en la estructura "usuario", y
//las estructuras "vehiculo" y "usuario" inicializadas, con sus contadores "numVehiculos".
//Postcondici�n: Dar de alta/Registrar un veh�culo, comprobando que la matr�cula es v�lida, y no est� en uso.
void altaVehiculo(int);

//Prototipo: void altaAdmin(int);
//Precondici�n: Necesario la introducci�n de un entero, para saber si queremos registrar un vehiculo o un viaje.
//Tener las estructuras "vehiculo", "viajes" y "usuario" inicializadas, con sus contadores "numVehiculos", "numViajes" y "numUsuarios".
//Postcondici�n: Si n=0, dar de alta/registrar un veh�culo, comprobando que la matr�cula es v�lida, y no est� en uso,
//y si n=1, dar de alta/registrar un viaje. Ambos, introduciendo la id del usuario al que se quiere crear.
void altaAdmin(int);

#endif // ESCRIBIR_H_INCLUDED

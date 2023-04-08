#ifndef LEER_H_INCLUDED
#define LEER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"

//Prototipo: void leer(Estr_Usuario **, int *, Estr_Vehiculo **, int *, Estr_Viaje **, int *, Estr_Pasos **, int *, Estr_Reservas **, int *, Estr_Rutas ***, int *, int *, Estr_Localidad **, int *);
//Precondici�n: Tener todas las estructuras inicializadas, con sus respectivos contadores. Adem�s todas tienen que pasarse por puntero, para introducir valores en las mismas.
//Postcondici�n: Leer todos los ficheros, e introducir la informaci�n en su estructura, con sus contadores.
void leer(Estr_Usuario **, int *, Estr_Vehiculo **, int *, Estr_Viaje **, int *, Estr_Pasos **, int *, Estr_Reservas **, int *, Estr_Rutas ***, int *, int *, Estr_Localidad **, int *);

//Prototipo: void leer_usuario(Estr_Usuario **, int *);
//Precondici�n: Tener la estructura inicializada, con su contador.
//Postcondici�n: Leer el fichero "usuarios.txt" e introducir la informaci�n en su estructura, aumentando el contador cada vez que se encuentra uno.
void leer_usuario(Estr_Usuario **, int *);

//Prototipo: void leer_vehiculo(Estr_Vehiculo **, int *);
//Precondici�n: Tener la estructura inicializada, con su contador.
//Postcondici�n: Leer el fichero "vehiculos.txt" e introducir la informaci�n en su estructura, aumentando el contador cada vez que se encuentra uno.
void leer_vehiculo(Estr_Vehiculo **, int *);

//Prototipo: void leer_viaje(Estr_Viaje **, int *);
//Precondici�n: Tener la estructura inicializada, con su contador.
//Postcondici�n: Leer el fichero "viajes.txt" e introducir la informaci�n en su estructura, aumentando el contador cada vez que se encuentra uno.
void leer_viaje(Estr_Viaje **, int *);

//Prototipo: void leer_pasos(Estr_Pasos **, int *);
//Precondici�n: Tener la estructura inicializada, con su contador.
//Postcondici�n: Leer el fichero "pasos.txt" e introducir la informaci�n en su estructura, aumentando el contador cada vez que se encuentra uno.
void leer_pasos(Estr_Pasos **, int *);

//Prototipo: void leer_localidad(Estr_Localidad **, int *);
//Precondici�n: Tener la estructura inicializada, con su contador.
//Postcondici�n: Leer el fichero "localidades.txt" e introducir la informaci�n en su estructura, aumentando el contador cada vez que se encuentra uno.
void leer_localidad(Estr_Localidad **, int *);

//Prototipo: void leer_ruta(Estr_Rutas ***, int *, int *);
//Precondici�n: Tener la estructura inicializada, con sus contadores.
//Postcondici�n: Leer el fichero "rutas.txt" e introducir la informaci�n en su estructura, aumentando el contador
//cada vez que se encuentra una ruta nueva, y otro que nos indique el n�mero de localidades m�ximas que hay en todas las rutas.
void leer_ruta(Estr_Rutas ***, int *, int *);

//Prototipo: void leer_reservas(Estr_Reservas **, int *);
//Precondici�n: Tener la estructura inicializada, con su contador.
//Postcondici�n: Leer el fichero "reservas.txt" e introducir la informaci�n en su estructura, aumentando el contador cada vez que se encuentra uno.
void leer_reservas(Estr_Reservas **, int *);

#endif // LEER_H_INCLUDED

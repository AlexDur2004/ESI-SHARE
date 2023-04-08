#ifndef LEER_H_INCLUDED
#define LEER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"

//Prototipo: void leer(Estr_Usuario **, int *, Estr_Vehiculo **, int *, Estr_Viaje **, int *, Estr_Pasos **, int *, Estr_Reservas **, int *, Estr_Rutas ***, int *, int *, Estr_Localidad **, int *);
//Precondición: Tener todas las estructuras inicializadas, con sus respectivos contadores. Además todas tienen que pasarse por puntero, para introducir valores en las mismas.
//Postcondición: Leer todos los ficheros, e introducir la información en su estructura, con sus contadores.
void leer(Estr_Usuario **, int *, Estr_Vehiculo **, int *, Estr_Viaje **, int *, Estr_Pasos **, int *, Estr_Reservas **, int *, Estr_Rutas ***, int *, int *, Estr_Localidad **, int *);

//Prototipo: void leer_usuario(Estr_Usuario **, int *);
//Precondición: Tener la estructura inicializada, con su contador.
//Postcondición: Leer el fichero "usuarios.txt" e introducir la información en su estructura, aumentando el contador cada vez que se encuentra uno.
void leer_usuario(Estr_Usuario **, int *);

//Prototipo: void leer_vehiculo(Estr_Vehiculo **, int *);
//Precondición: Tener la estructura inicializada, con su contador.
//Postcondición: Leer el fichero "vehiculos.txt" e introducir la información en su estructura, aumentando el contador cada vez que se encuentra uno.
void leer_vehiculo(Estr_Vehiculo **, int *);

//Prototipo: void leer_viaje(Estr_Viaje **, int *);
//Precondición: Tener la estructura inicializada, con su contador.
//Postcondición: Leer el fichero "viajes.txt" e introducir la información en su estructura, aumentando el contador cada vez que se encuentra uno.
void leer_viaje(Estr_Viaje **, int *);

//Prototipo: void leer_pasos(Estr_Pasos **, int *);
//Precondición: Tener la estructura inicializada, con su contador.
//Postcondición: Leer el fichero "pasos.txt" e introducir la información en su estructura, aumentando el contador cada vez que se encuentra uno.
void leer_pasos(Estr_Pasos **, int *);

//Prototipo: void leer_localidad(Estr_Localidad **, int *);
//Precondición: Tener la estructura inicializada, con su contador.
//Postcondición: Leer el fichero "localidades.txt" e introducir la información en su estructura, aumentando el contador cada vez que se encuentra uno.
void leer_localidad(Estr_Localidad **, int *);

//Prototipo: void leer_ruta(Estr_Rutas ***, int *, int *);
//Precondición: Tener la estructura inicializada, con sus contadores.
//Postcondición: Leer el fichero "rutas.txt" e introducir la información en su estructura, aumentando el contador
//cada vez que se encuentra una ruta nueva, y otro que nos indique el número de localidades máximas que hay en todas las rutas.
void leer_ruta(Estr_Rutas ***, int *, int *);

//Prototipo: void leer_reservas(Estr_Reservas **, int *);
//Precondición: Tener la estructura inicializada, con su contador.
//Postcondición: Leer el fichero "reservas.txt" e introducir la información en su estructura, aumentando el contador cada vez que se encuentra uno.
void leer_reservas(Estr_Reservas **, int *);

#endif // LEER_H_INCLUDED

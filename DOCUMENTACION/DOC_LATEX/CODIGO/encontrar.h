#ifndef ENCONTRAR_H_INCLUDED
#define ENCONTRAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"

//Cabecera: void encontrarVehiculos(Estr_Usuario *, Estr_Vehiculo *, int, int **, int *, int);
//Precondicion: Introducir un vector de enteros, para introducir datos en el mismo, al igual que la variable "x",
//para saber cuantos vehiculos tiene dicho usuario, y la varible "i", para identificar el usuario, es decir, la posicion
//en la estructura de "usuario". Ademas, se necesitan las estructuras "usuario" y "vehiculo" inicializadas, con sus contadores "numVehiculos" y "numUsuarios".
//Postcondicion: Busca todos los vehiculos de un usuario mediante su id, e introduce las posiciones en la estructura de dichos vehiculos en un vector de enteros.
void encontrarVehiculos(Estr_Usuario *, Estr_Vehiculo *, int, int **, int *, int);

//Cabecera: void encontrarVehiculosViajes(Estr_Usuario *, Estr_Vehiculo *, int, Estr_Viaje *, int, int **, int *, int);
//Precondicion: Introducir un vector de enteros, para introducir datos en el mismo, al igual que la variable "x",
//para saber cuantos vehiculos, con unas restricciones, tiene dicho usuario, y la varible "i", para identificar el usuario, es decir, la posicion
//en la estructura de "usuario". Ademas, se necesitan las estructuras "usuario, "vehiculo" y "viaje" inicializadas, con sus contadores "numVehiculos", "numUsuarios" y "numViajes".
//Postcondicion: Busca todos los vehiculos, que no tengan viajes abiertos, con plazas ocupadas, ni iniciados ni cerrados, de un usuario mediante su id,
//e introduce las posiciones en la estructura de dichos vehiculos en un vector de enteros.
void encontrarVehiculosViajes(Estr_Usuario *, Estr_Vehiculo *, int, Estr_Viaje *, int, int **, int *, int);

//Cabecera: void encontrarViajes(Estr_Vehiculo *, int, Estr_Viaje *, int, char *, int **, int *, int);
//Precondicion: Introducir la cadena "mat", que sera la matricula del vehiculo, al que queremos obtener todos sus viajes, un vector de enteros,
//para introducir datos en el mismo, al igual que la variable "x", para saber cuantos viajes tiene dicho usuario, y la varible "num", que sera 0, 1 o 2,
//dependiendo de para que queramos usar la funcion. Ademas, se necesita las estructuras "vehiculos" y "viaje" inicializadas, con sus contadores.
//Postcondicion: Busca todos los viajes de un vehiculo mediante su matricula, e introduce las posiciones en la estructura de dichos viajes en un vector de enteros.
void encontrarViajes(Estr_Vehiculo *, int, Estr_Viaje *, int, char *, int **, int *, int);

//Cabecera: void encontrarUsuario(Estr_Usuario *, int, char *, int *, int *);
//Precondicion: Introducir la cadena "vec_id", que sera la id de un usuario que queremos encontrar, junto a una variable "x", para obtener la posicion
//del usuario en la estructura "usuario", y la variable "encontrado" incializada. Ademas, se necesita la estructura "usuario", con su contador "numUsuarios".
//Postcondicion: Busca al usuario en la base de datos mediante su id, e introduce su posicion en la estructura en una variable "x", y "encontrado" pasa a ser 1, si se encuentra el usuario.
void encontrarUsuario(Estr_Usuario *, int, char *, int *, int *);

//Cabecera: void encontrarReservas(Estr_Usuario *, Estr_Viaje *, int, Estr_Reservas *, int, int, int **, int **, int *);
//Precondicion: Introducir la varible "num_user", que nos dice la posicion del usuario en la estructura "usuario", junto a una variable "x",
//para obtener el numero maximo de reservas que cumplen las condiciones, y los vectores "vec" y "vec_viaje", para meter las posiciones en esos vector dinamicos.
//Ademas, se necesita las estructuras "usuario", "viaje" y "reservas" inicializadas, con sus contadores.
//Postcondicion: Busca todas las reservas abiertas de un usuario, mediante su id, e introduce las posiciones en la estructura de dichas reservas
//en un vector de enteros, y las posiciones de de los viajes en los que estan esas reservas, en otro vector de enteros.
void encontrarReservas(Estr_Usuario *, Estr_Viaje *, int, Estr_Reservas *, int, int, int **, int **, int *);

//Cabecera: void encontrarViajesReservas(Estr_Usuario *, Estr_Viaje *, int, Estr_Pasos *, int, int, char *, int **, int *, int *);
//Precondicion: Introducir la varible "num_user", que nos dice la posicion del usuario en la estructura "usuario", para saber su localidad, junto a una variable "x",
//para obtener el numero maximo de viajes que cumplen las condiciones, y la variable "loc", para saber si hay viajes por su localidad, pero en fechas distintas,
//junto a un cadena "fecha", para saber en que fecha quiere buscar el viaje, y el vector "vec", para introducir las posiciones de los viajes
//que pasan por la ciudad del usuario. Ademas, se necesita las estructuras "usuario", "viaje" y "pasos" inicializadas, con sus contadores.
//Postcondicion: Busca todas los viajes abiertos o iniciados, que pasen por la localidad de un usuario, mediante su id, e introduce las posiciones en la
//estructura de dichos viajes en un vector de enteros. Si no hay viajes en la fecha indicada, entonces "loc" sera distinto de 0.
void encontrarViajesReservas(Estr_Usuario *, Estr_Viaje *, int, Estr_Pasos *, int, int, char *, int **, int *, int *);

#endif // ENCONTRAR_H_INCLUDED

#ifndef ENCONTRAR_H_INCLUDED
#define ENCONTRAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leer.h"

//Prototipo: void encontrarVehiculos(Estr_Usuario *, Estr_Vehiculo *, int, int **, int *, int);
//Precondición: Introducir un vector de enteros, para introducir datos en el mismo, al igual que la variable "x",
//para saber cuántos vehículos tiene dicho usuario, y la varible "i", para identificar el usuario, es decir, la posición
//en la estructura de "usuario". Además, se necesitan las estructuras "usuario" y "vehiculo" inicializadas, con sus contadores "numVehiculos" y "numUsuarios".
//Postcondición: Busca todos los vehículos de un usuario mediante su id, e introduce las posiciones en la estructura de dichos vehículos en un vector de enteros.
void encontrarVehiculos(Estr_Usuario *, Estr_Vehiculo *, int, int **, int *, int);

//Prototipo: void encontrarViajes(Estr_Vehiculo *, int, Estr_Viaje *, int, char *, int **, int *, int);
//Precondición: Introducir la cadena "mat", que será la matrícula del vehículo, al que queremos obtener todos sus viajes, un vector de enteros,
//para introducir datos en el mismo, al igual que la variable "x", para saber cuántos viajes tiene dicho usuario, y la varible "num", que será 0, 1 ó 2,
//dependiendo de para qué queramos usar la función. Además, se necesita las estructuras "vehiculos" y "viaje" inicializadas, con sus contadores.
//Postcondición: Busca todos los viajes de un vehículo mediante su matrícula, e introduce las posiciones en la estructura de dichos viajes en un vector de enteros.
void encontrarViajes(Estr_Vehiculo *, int, Estr_Viaje *, int, char *, int **, int *, int);

//Prototipo: void encontrarUsuario(Estr_Usuario *, int, char *, int *, int *);
//Precondición: Introducir la cadena "vec_id", que será la id de un usuario que queremos encontrar, junto a una variable "x", para obtener la posición
//del usuario en la estructura "usuario", y la variable "encontrado" incializada. Además, se necesita la estructura "usuario", con su contador "numUsuarios".
//Postcondición: Busca al usuario en la base de datos mediante su id, e introduce su posición en la estructura en una variable "x", y "encontrado" pasa a ser 1, si se encuentra el usuario.
void encontrarUsuario(Estr_Usuario *, int, char *, int *, int *);

//Prototipo: void encontrarReservas(Estr_Usuario *, Estr_Viaje *, int, Estr_Reservas *, int, int, int **, int **, int *);
//Precondición: Introducir la varible "num_user", que nos dice la posición del usuario en la estructura "usuario", junto a una variable "x",
//para obtener el número máximo de reservas que cumplen las condiciones, y los vectores "vec" y "vec_viaje", para meter las posiciones en esos vector dinámicos.
//Además, se necesita las estructuras "usuario", "viaje" y "reservas" inicializadas, con sus contadores.
//Postcondición: Busca todas las reservas abiertas de un usuario, mediante su id, e introduce las posiciones en la estructura de dichas reservas
//en un vector de enteros, y las posiciones de de los viajes en los que están esas reservas, en otro vector de enteros.
void encontrarReservas(Estr_Usuario *, Estr_Viaje *, int, Estr_Reservas *, int, int, int **, int **, int *);

//Prototipo: void encontrarViajesReservas(Estr_Usuario *, Estr_Viaje *, int, Estr_Pasos *, int, int, char *, int **, int *, int *);
//Precondición: Introducir la varible "num_user", que nos dice la posición del usuario en la estructura "usuario", para saber su localidad, junto a una variable "x",
//para obtener el número máximo de viajes que cumplen las condiciones, y la variable "loc", para saber si hay viajes por su localidad, pero en fechas distintas,
//junto a un cadena "fecha", para saber en qué fecha quiere buscar el viaje, y el vector "vec", para introducir las posiciones de los viajes
//que pasan por la ciudad del usuario. Además, se necesita las estructuras "usuario", "viaje" y "pasos" inicializadas, con sus contadores.
//Postcondición: Busca todas los viajes abiertos o iniciados, que pasen por la localidad de un usuario, mediante su id, e introduce las posiciones en la
//estructura de dichos viajes en un vector de enteros. Si no hay viajes en la fecha indicada, entonces "loc" será distinto de 0.
void encontrarViajesReservas(Estr_Usuario *, Estr_Viaje *, int, Estr_Pasos *, int, int, char *, int **, int *, int *);

#endif // ENCONTRAR_H_INCLUDED

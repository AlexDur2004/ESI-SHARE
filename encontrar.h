#ifndef ENCONTRAR_H_INCLUDED
#define ENCONTRAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leer.h"

//Prototipo: void encontrarVehiculos(int **, int *, int);
//Precondición: Introducir un vector de enteros, para introducir datos en el mismo, al igual que la variable "x",
//para saber cuántos vehículos tiene dicho usuario, y la varible "i", para identificar el usuario, es decir, la posición
//en la estructura de "usuario". Además, se necesitan las estructuras "usuario" y "vehiculo" inicializadas, con sus contadores "numVehiculos" y "numUsuarios".
//Postcondición: Busca todos los vehículos de un usuario mediante su id, e introduce las posiciones en la estructura de dichos vehículos en un vector de enteros.
void encontrarVehiculos(Estr_Usuario *usuario, Estr_Vehiculo *vehiculo, int numVehiculos, int **vec, int *x, int i);

//Prototipo: void encontrarViajes(char *, int **, int *, int);
//Precondición: Introducir la cadena "mat", que será la matrícula del vehículo, al que queremos obtener todos sus viajes, un vector de enteros,
//para introducir datos en el mismo, al igual que la variable "x", para saber cuántos viajes tiene dicho usuario, y la varible "num", que será 0, 1 ó 2,
//dependiendo de para qué queramos usar la función. Además, se necesita la estructura "viaje" inicializada, con su contador "numViajes".
//Postcondición: Busca todos los viajes de un vehículo mediante su matrícula, e introduce las posiciones en la estructura de dichos viajes en un vector de enteros.
void encontrarViajes(Estr_Vehiculo *, int, Estr_Viaje *, int, char *, int **, int *, int);

//Prototipo: void encontrarUsuario(char [], int *, int *);
//Precondición: Introducir la cadena "vec_id", que será la id de un usuario que queremos encontrar, junto a una variable "x", para obtener la posición
//del usuario en la estructura "usuario", y la variable "encontrado" incializada. Además, se necesita la estructura "usuario", con su contador "numUsuarios".
//Postcondición: Busca al usuario en la base de datos mediante su id, e introduce su posición en la estructura en una variable "x",
//y "encontrado" pasa a ser 1, si se encuentra el usuario.
void encontrarUsuario(Estr_Usuario *usuario, int numUsuarios, char vec_id[], int *x, int *encontrado);

void encontrarReservas(Estr_Usuario *usuario, Estr_Viaje *viaje, int numViajes, Estr_Reservas *reservas, int numReservas, int num_user, int **vec,int **vec_viaje, int *x);

void encontrarViajesReservas(Estr_Usuario *usuario, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos,int num_user, char *fecha, int **vec, int *x, int *loc);

#endif // ENCONTRAR_H_INCLUDED

#ifndef ENCONTRAR_H_INCLUDED
#define ENCONTRAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leer.h"

//Prototipo: void encontrarVehiculos(int **, int *, int);
//Precondici�n: Introducir un vector de enteros, para introducir datos en el mismo, al igual que la variable "x",
//para saber cu�ntos veh�culos tiene dicho usuario, y la varible "i", para identificar el usuario, es decir, la posici�n
//en la estructura de "usuario". Adem�s, se necesitan las estructuras "usuario" y "vehiculo" inicializadas, con sus contadores "numVehiculos" y "numUsuarios".
//Postcondici�n: Busca todos los veh�culos de un usuario mediante su id, e introduce las posiciones en la estructura de dichos veh�culos en un vector de enteros.
void encontrarVehiculos(Estr_Usuario *usuario, Estr_Vehiculo *vehiculo, int numVehiculos, int **vec, int *x, int i);

//Prototipo: void encontrarViajes(char *, int **, int *, int);
//Precondici�n: Introducir la cadena "mat", que ser� la matr�cula del veh�culo, al que queremos obtener todos sus viajes, un vector de enteros,
//para introducir datos en el mismo, al igual que la variable "x", para saber cu�ntos viajes tiene dicho usuario, y la varible "num", que ser� 0, 1 � 2,
//dependiendo de para qu� queramos usar la funci�n. Adem�s, se necesita la estructura "viaje" inicializada, con su contador "numViajes".
//Postcondici�n: Busca todos los viajes de un veh�culo mediante su matr�cula, e introduce las posiciones en la estructura de dichos viajes en un vector de enteros.
void encontrarViajes(Estr_Vehiculo *, int, Estr_Viaje *, int, char *, int **, int *, int);

//Prototipo: void encontrarUsuario(char [], int *, int *);
//Precondici�n: Introducir la cadena "vec_id", que ser� la id de un usuario que queremos encontrar, junto a una variable "x", para obtener la posici�n
//del usuario en la estructura "usuario", y la variable "encontrado" incializada. Adem�s, se necesita la estructura "usuario", con su contador "numUsuarios".
//Postcondici�n: Busca al usuario en la base de datos mediante su id, e introduce su posici�n en la estructura en una variable "x",
//y "encontrado" pasa a ser 1, si se encuentra el usuario.
void encontrarUsuario(Estr_Usuario *usuario, int numUsuarios, char vec_id[], int *x, int *encontrado);

void encontrarReservas(Estr_Usuario *usuario, Estr_Viaje *viaje, int numViajes, Estr_Reservas *reservas, int numReservas, int num_user, int **vec,int **vec_viaje, int *x);

void encontrarViajesReservas(Estr_Usuario *usuario, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos,int num_user, char *fecha, int **vec, int *x, int *loc);

#endif // ENCONTRAR_H_INCLUDED

#ifndef ENCONTRAR_H_INCLUDED
#define ENCONTRAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leer.h"

//Prototipo: void encontrarVehiculos(Estr_Usuario *, Estr_Vehiculo *, int, int **, int *, int);
//Precondici�n: Introducir un vector de enteros, para introducir datos en el mismo, al igual que la variable "x",
//para saber cu�ntos veh�culos tiene dicho usuario, y la varible "i", para identificar el usuario, es decir, la posici�n
//en la estructura de "usuario". Adem�s, se necesitan las estructuras "usuario" y "vehiculo" inicializadas, con sus contadores "numVehiculos" y "numUsuarios".
//Postcondici�n: Busca todos los veh�culos de un usuario mediante su id, e introduce las posiciones en la estructura de dichos veh�culos en un vector de enteros.
void encontrarVehiculos(Estr_Usuario *, Estr_Vehiculo *, int, int **, int *, int);

//Prototipo: void encontrarViajes(Estr_Vehiculo *, int, Estr_Viaje *, int, char *, int **, int *, int);
//Precondici�n: Introducir la cadena "mat", que ser� la matr�cula del veh�culo, al que queremos obtener todos sus viajes, un vector de enteros,
//para introducir datos en el mismo, al igual que la variable "x", para saber cu�ntos viajes tiene dicho usuario, y la varible "num", que ser� 0, 1 � 2,
//dependiendo de para qu� queramos usar la funci�n. Adem�s, se necesita las estructuras "vehiculos" y "viaje" inicializadas, con sus contadores.
//Postcondici�n: Busca todos los viajes de un veh�culo mediante su matr�cula, e introduce las posiciones en la estructura de dichos viajes en un vector de enteros.
void encontrarViajes(Estr_Vehiculo *, int, Estr_Viaje *, int, char *, int **, int *, int);

//Prototipo: void encontrarUsuario(Estr_Usuario *, int, char *, int *, int *);
//Precondici�n: Introducir la cadena "vec_id", que ser� la id de un usuario que queremos encontrar, junto a una variable "x", para obtener la posici�n
//del usuario en la estructura "usuario", y la variable "encontrado" incializada. Adem�s, se necesita la estructura "usuario", con su contador "numUsuarios".
//Postcondici�n: Busca al usuario en la base de datos mediante su id, e introduce su posici�n en la estructura en una variable "x", y "encontrado" pasa a ser 1, si se encuentra el usuario.
void encontrarUsuario(Estr_Usuario *, int, char *, int *, int *);

//Prototipo: void encontrarReservas(Estr_Usuario *, Estr_Viaje *, int, Estr_Reservas *, int, int, int **, int **, int *);
//Precondici�n: Introducir la varible "num_user", que nos dice la posici�n del usuario en la estructura "usuario", junto a una variable "x",
//para obtener el n�mero m�ximo de reservas que cumplen las condiciones, y los vectores "vec" y "vec_viaje", para meter las posiciones en esos vector din�micos.
//Adem�s, se necesita las estructuras "usuario", "viaje" y "reservas" inicializadas, con sus contadores.
//Postcondici�n: Busca todas las reservas abiertas de un usuario, mediante su id, e introduce las posiciones en la estructura de dichas reservas
//en un vector de enteros, y las posiciones de de los viajes en los que est�n esas reservas, en otro vector de enteros.
void encontrarReservas(Estr_Usuario *, Estr_Viaje *, int, Estr_Reservas *, int, int, int **, int **, int *);

//Prototipo: void encontrarViajesReservas(Estr_Usuario *, Estr_Viaje *, int, Estr_Pasos *, int, int, char *, int **, int *, int *);
//Precondici�n: Introducir la varible "num_user", que nos dice la posici�n del usuario en la estructura "usuario", para saber su localidad, junto a una variable "x",
//para obtener el n�mero m�ximo de viajes que cumplen las condiciones, y la variable "loc", para saber si hay viajes por su localidad, pero en fechas distintas,
//junto a un cadena "fecha", para saber en qu� fecha quiere buscar el viaje, y el vector "vec", para introducir las posiciones de los viajes
//que pasan por la ciudad del usuario. Adem�s, se necesita las estructuras "usuario", "viaje" y "pasos" inicializadas, con sus contadores.
//Postcondici�n: Busca todas los viajes abiertos o iniciados, que pasen por la localidad de un usuario, mediante su id, e introduce las posiciones en la
//estructura de dichos viajes en un vector de enteros. Si no hay viajes en la fecha indicada, entonces "loc" ser� distinto de 0.
void encontrarViajesReservas(Estr_Usuario *, Estr_Viaje *, int, Estr_Pasos *, int, int, char *, int **, int *, int *);

#endif // ENCONTRAR_H_INCLUDED

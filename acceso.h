#ifndef ACCESO_H_INCLUDED
#define ACCESO_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "leer.h"
#include "preguntar.h"
#include "menus.h"
#include "colores.h"

//Prototipo: void acceso(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int);
//Precondicion: Tener inicializada la variable "numUsuarios", con el numero de usuarios maximos del fichero, y la estructura "usuario", con datos leidos
//desde el fichero "usuarios.txt", y haber introducido el numero correspondiente en el menu. Tambien se necesitaran el resto de estructuras, para introducirlas en el menu.
//Postcondicion: Autenticacion de las credenciales introducidas, si coinciden con alguna de la base de datos, pues se accede al programa.
//Si el usuario es "usuario", accedera al menu de usuario, y si es "administrador", accedera al menu de admin.
void acceso(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int);

#endif // ACCESO_H_INCLUDED

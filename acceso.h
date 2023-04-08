#ifndef COMPROBAR_USUARIO_H_INCLUDED
#define COMPROBAR_USUARIO_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "leer.h"

//Prototipo: void acceso(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int);
//Precondici�n: Tener inicializada la variable "numUsuarios", con el n�mero de usuarios m�ximos del fichero, y la estructura "usuario", con datos le�dos
//desde el fichero "usuarios.txt", y haber introducido el n�mero correspondiente en el men�. Tambi�n se necesitar�n el resto de estructuras, para introducirlas en el men�.
//Postcondici�n: Autenticaci�n de las credenciales introducidas, si coinciden con alguna de la base de datos, pues se accede al programa.
//Si el usuario es "usuario", acceder� al men� de usuario, y si es "administrador", acceder� al men� de admin.
void acceso(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int);

#endif // COMPROBAR_USUARIO_H_INCLUDED

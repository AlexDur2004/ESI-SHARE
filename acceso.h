#ifndef COMPROBAR_USUARIO_H_INCLUDED
#define COMPROBAR_USUARIO_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "leer.h"

//Prototipo: void acceso(Estr_Usuario *, int);
//Precondición: Tener inicializada la variable "numUsuarios", con el número de usuarios máximos del fichero, y la estructura "usuario", con datos leídos
//desde el fichero "usuarios.txt", y haber introducido el número correspondiente en el menú.
//Postcondición: Autenticación de las credenciales introducidas, si coinciden con alguna de la base de datos, pues se accede al programa.
//Si el usuario es "usuario", accederá al menú de usuario, y si es "administrador", accederá al menú de admin.
void acceso(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2);

#endif // COMPROBAR_USUARIO_H_INCLUDED

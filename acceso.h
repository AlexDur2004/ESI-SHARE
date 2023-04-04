#ifndef COMPROBAR_USUARIO_H_INCLUDED
#define COMPROBAR_USUARIO_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "estructuras.h"
#include "leer.h"

//Prototipo: void acceso();
//Precondición: Tener inicializada la variable "numUsuarios", con el número de usuarios máximos del fichero, y la estructura "usuario", con datos leídos
//desde el fichero "usuarios.txt", y haber introducido el número correspondiente en el menú.
//Postcondición: Autenticación de las credenciales introducidas, si coinciden con alguna de la base de datos, pues se accede al programa.
//Si el usuario es "usuario", accederá al menú de usuario, y si es "administrador", accederá al menú de admin.
void acceso();

#endif // COMPROBAR_USUARIO_H_INCLUDED

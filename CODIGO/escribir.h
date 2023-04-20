#ifndef ESCRIBIR_H_INCLUDED
#define ESCRIBIR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actualizar.h"
#include "preguntar.h"
#include "listar.h"
#include "fecha.h"
#include "buscar.h"
#include "menus.h"
#include "colores.h"

//Cabecera: void altaUsuario(Estr_Usuario *, int, Estr_Localidad *, int);
//Precondicion: Tener las estructuras "usuario" y "localidad" inicializada, con sus contadores "numUsuarios" y "numLocalidades".
//Postcondicion: Dar de alta/Registrar un usuario, comprobando que el nombre del usuario no esta repetido.
void altaUsuario(Estr_Usuario *, int, Estr_Localidad *, int);

//Cabecera: void altaVehiculo(Estr_Usuario *, Estr_Vehiculo *, int, int);
//Precondicion: Tener la variable "i", con la posicion del usuario en la estructura "usuario", y las estructuras "vehiculo" y "usuario" inicializadas, con su contador "numVehiculos".
//Postcondicion: Dar de alta/Registrar un vehiculo, comprobando que la matricula es valida, y no esta en uso.
void altaVehiculo(Estr_Usuario *, Estr_Vehiculo *, int, int);

//Cabecera: void altaAdmin(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondicion: Necesario la introduccion de un entero, para saber si queremos registrar un vehiculo o un viaje. Tener las estructuras inicializadas, con sus contadores.
//Postcondicion: Si n=0, dar de alta/registrar un vehiculo, comprobando que la matricula es valida, y no esta en uso,
//y si n=1, dar de alta/registrar un viaje. Ambos, introduciendo la id del usuario al que se quiere crear.
void altaAdmin(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);

//Cabecera: void altaViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int, int);
//Precondicion:se necesitara la variable numUsuarios que respresenta al usuario en la estructura Usuarios.
//Ademas se necesitaran las estructuras de "vehiculos", "viajes", "pasos", "reservas", "localidad", "rutas", con sus respectivos contadores.
//Postcondicion: crea un nuevo viaje en el fichero, ingresando valores como la matricula del coche la fecha, las horas de inicio y fin o el coste,
//y asignadose otros valores automaticamente como el esatdo del viaje, la id del viaje o las plazas de este.
void altaViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int, int);

//Cabecera: void altaReserva(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);
//Precondicion://Precondicion:se necesitara la variable numUsuarios que respresenta al usuario en la estructura Usuarios,
//Ademas se necesitaran las estructuras de "vehiculos", "viajes", "pasos", "reservas", "localidad", "rutas", con sus respectivos contadores.
//Postcondicion: en el fichero reserva se guardara la id del viaje que el usuario haya elegido y su id y se restara una plaza al viaje, dato que tambine se modidificara en el fichero,
//en dependencia de la fecha elegida por el usuario y su localidad le seran mostrados todos lo viajes disponibles impidiendole elegir los viajes ya reservados previamente o creados por el,
//y en caso de que no haya ningun viaje que pase por su localidad no se le mostrara ningun viaje y volvera al menu.
void altaReserva(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);

//Cabecera: void verificar_viaje(Estr_Viaje *, int , char *, char *, char *, char *, int *);
//Precondicion:esta funcion recibe la estructura viajes inicializada y su contador,junto con datos de tipo caracter como la matricula la fecha, hora de inicio y fin.
//Postcondicion: Verificar si los datos del viaje que se esta creando no coinciden con los de un viaje creado previamente, devuelve un puntero de tipo entero "rp"
//que indica si el viaje creado ya se habia creado previamente.
void verificar_viaje(Estr_Viaje *, int , char *, char *, char *, char *, int *);

#endif // ESCRIBIR_H_INCLUDED

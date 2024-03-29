#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "fecha.h"
#include "leer.h"
#include "menus.h"

int main()
{
    Estr_Usuario *usuario; //Inicializamos las estructuras.
    Estr_Vehiculo *vehiculo;
    Estr_Viaje *viaje;
    Estr_Pasos *pasos;
    Estr_Localidad *localidad;
    Estr_Reservas *reservas;
    Estr_Rutas **ruta;

    int numUsuarios, numVehiculos, numViajes, numPasos, numLocalidades, numRutas, numRutas2, numReservas; //Inicializamos los contadores de cada estructura.

    setlocale(LC_ALL, "spanish"); //Usado para poner tildes y caracteres especiales.

    //Lectura inicial de todos los ficheros.
    leer(&usuario, &numUsuarios, &vehiculo, &numVehiculos, &viaje, &numViajes, &pasos, &numPasos, &reservas, &numReservas, &ruta, &numRutas, &numRutas2, &localidad, &numLocalidades);
    actualizarViajesEstado(viaje, numViajes, reservas, numReservas, pasos, numPasos); //Actualizacion de estado de todos los viajes que hayan pasado la fecha y hora.

    //Vamos al menu principal.
    menuPrincipal(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2);

return(0);
}

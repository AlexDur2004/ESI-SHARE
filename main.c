#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "acceso.h"
#include "colores.h"
#include "crear_viaje.h"
#include "eliminar.h"
#include "encontrar.h"
#include "estructuras.h"
#include "escribir.h"
#include "fecha.h"
#include "leer.h"
#include "listar.h"
#include "menus.h"
#include "modificar.h"
#include "mostrar_reservar.h"
#include "preguntar.h"
#include "reservar.h"

int main()
{
    Estr_Usuario *usuario;
    Estr_Vehiculo *vehiculo;
    Estr_Viaje *viaje;
    Estr_Pasos *pasos;
    Estr_Localidad *localidad;
    Estr_Reservas *reservas;
    Estr_Rutas **ruta;

    int numUsuarios, numVehiculos, numViajes, numPasos, numLocalidades, numRutas, numRutas2, numReservas;

    setlocale(LC_ALL, "spanish");

    leer(&usuario, &numUsuarios, &vehiculo, &numVehiculos, &viaje, &numViajes, &pasos, &numPasos, &reservas, &numReservas, &ruta, &numRutas, &numRutas2, &localidad, &numLocalidades);
    actualizarViajes(viaje, numViajes, reservas, numReservas);

    menuPrincipal(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2);

return(0);
}

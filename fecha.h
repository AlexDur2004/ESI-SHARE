#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <time.h>
#include "leer.h"

//Prototipo: void actualizarViajes(Estr_Viaje *, int, Estr_Reservas *, int, Estr_Pasos *, int);
//Precondici�n: Tener las estructuras "viaje" y "reservas", con sus contadores.
//Postcondici�n: Actualiza el estado de todos los viajes, si se ha pasado la hora de inicio, pues se pone en estado "Iniciado",
//mientras que si se ha excedido una hora desde la hora de llegada, pues se establece en estado "Finalizado", y se eliminan sus pasos y reservas.
void actualizarViajes(Estr_Viaje *, int, Estr_Reservas *, int, Estr_Pasos *, int);

//Prototipo: void leerFecha(char *, char *, char *);
//Precondici�n: Tener los cadenas "fecha", "h_inic" y "h_fin" inicializados.
//Postcondici�n: Leer la fecha, hora de inicio y hora de llegada, y comprobar si son v�lidas, y posteriores a las actuales. Despu�s, se introducen en su respectiva cadena.
void leerFecha(char *, char *, char *);

//Prototipo: void leer_dia(char *);
//Precondici�n: Tener la cadena "fecha" inicializada.
//Postcondici�n: Leer la fecha, y comprobar si es v�lida, y posterior a las actual. Si esto se cumple, se guarda en la cadena.
void leer_dia(char *);

#endif // FECHA_H_INCLUDED

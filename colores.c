#include "colores.h"

enum colores //Listado de colores
{
	negro=0,
	azul=1,
	verde=2,
	cyan=3,
	rojo=4,
	magenta=5,
	marron=6,
	gris_claro=7,
	gris_oscuro=8,
	azul_claro=9,
	verde_claro=10,
	cyan_claro=11,
	rojo_claro=12,
	magenta_claro=13,
	amarillo=14,
	blanco=15,
};

//Prototipo: void color(int, int);
//Precondici�n: Necesita dos n�meros asociado al color que se quiere colocar, uno para el fondo, y otro para el cuerpo del texto.
//Postcondici�n: Cambia de color, el fondo y el cuerpo del texto.

void color(int fondo, int texto)
{
	HANDLE consola=GetStdHandle(STD_OUTPUT_HANDLE); //Accedemos a la consola.

	//Para cambiar el color, se utilizan n�meros desde el 0 hasta el 255, pero para convertir los colores a un valor adecuado, se realiza el siguiente c�lculo.
	int color_nuevo=texto+(fondo*16);

	SetConsoleTextAttribute(consola, color_nuevo); //Guardamos los cambios en la consola.
}

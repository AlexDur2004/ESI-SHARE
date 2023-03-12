#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <conio.h>
#include "estructuras.h"
#include "menus.h"
#include "colores.h"
#include "comprobar_usuario.h"
#include "escribir.h"
#include "fecha.h"
#include "leer.h"
#include "preguntar_localidad.h"
#include "modificar.h"
#include "eliminar.h"

int main()
{
    printf("champi%c%cn.\n", 164, 162);
    setlocale(LC_ALL, "spanish");

    leer();

    menuPrincipal();

return(0);
}

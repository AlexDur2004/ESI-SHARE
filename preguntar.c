#include "preguntar.h"

//Prototipo: void pregunta(char *, int);
//Precondición: Tener una cadena y un entero inicializados, que nos indique el nº maximo de caracteres de la misma.
//Postcondición: Introducir en una cadena, la información escaneada, pero cambiando el salto de linea \n por el caracter nulo \0.

void pregunta(char *x, int i)
{
    int encontrado=0;

    while(!encontrado)
    {
        fflush(stdin);
        fgets(x, i, stdin);

        char *lin=strchr(x, '\n');
        if(strchr(x,'\n')!=NULL)
        {
            *lin='\0';
        }
        if(strlen(x)>0)
        {
            encontrado=1;
        }
    }
}

//Prototipo: void imprimir_localidad(Estr_Localidad *, int);
//Precondición: Tener la estructura "localidad" inicializada, con su contador.
//Postcondición: Imprimir una lista de 4 filas con todas las localidades.

void imprimir_localidad(Estr_Localidad *localidad, int numLocalidades)
{
    int i=0, j=0, k=0;

    numLocalidades--; //Queremos quitarle la última línea que contiene a la Escuela Superior de Ingeniería (ESI), para que no se imprima por pantalla, junto a las localidades.

    k=numLocalidades/4; //Calcular filas necesarias.

    if(numLocalidades%4!=0) //Si al dividir las localidades entre 4, queda un resto, pues se aumenta una fila.
    {
        k++;
    }

    for(i=0; i<k; i++) //Imprimimos la lista de ciudades en 4 columnas homogéneas.
    {
        for(j=i; j<numLocalidades; j=j+k)
        {
            color(0, 3);
            printf("%s", localidad[j].siglas);
            color(0, 15);
            printf("-%-20s\t", localidad[j].localidad);
        }
        printf("\n");
    }
}

//Prototipo: void pregunta_localidad(Estr_Localidad *, int, char *);
//Precondición: Tener la estructura "localidad" inicializada, con su contador. Además, necesitamos una cadena, donde introducir la localidad introducida.
//Postcondición: Introducir en una cadena, la localidad seleccionada de la lista.

void pregunta_localidad(Estr_Localidad *localidad, int numLocalidades, char *local)
{
    char vec_loc[4];
    int i, encontrado=0;

    imprimir_localidad(localidad, numLocalidades); //Imprime una lista con todas las localicades.

    while(encontrado==0) //Hasta que no se introduzca una cadena correcta.
    {
        pregunta(vec_loc, 4);

        for(i=0; i<numLocalidades; i++) //Recorremos toda la estructura "localidad".
        {
            if(strcmp(vec_loc, localidad[i].siglas)==0) //Si alguna respuesta coincide exactamente con las siglas, salimos del bucle.
            {
                encontrado=1;
                printf("Has seleccionado %s.\n", localidad[i].localidad);

                strcpy(local, localidad[i].localidad); //Copiamos el nombre de la localidad en la cadena "local", para devolverla a otras funciones.
            }
        }
    }
}

//Prototipo: void pregunta_localidad(Estr_Localidad *, int, char *);
//Precondición: Tener la estructura "localidad" inicializada, con su contador. Además, necesitamos una cadena, donde introducir la localidad introducida.
//Postcondición: Introducir en una cadena, la localidad seleccionada de la lista.

void pregunta_ruta(Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, char *rut2)
{
    int i, j, x, encontrado=0;
    char rut[4];

    imprimir_localidad(localidad, numLocalidades); //Imprime una lista con todas las localicades.

    while(encontrado==0) //Hasta que no se introduzca una cadena correcta.
    {
        pregunta(rut, 4);

        for(x=0; x<numLocalidades; x++) //Recorremos toda la estructura "localidad".
        {
            if(strcmp(rut, localidad[x].siglas)==0) //Si alguna respuesta coincide exactamente con las siglas.
            {
                encontrado=1;
                printf("Has seleccionado %s.\n", localidad[x].localidad);

                for(i=0; i<numRutas; i++) //Recorremos todas las filas de la estructura "ruta".
                {
                    for(j=0; j<numRutas2; j++) //Recorremos todas las columnas de la estructura "ruta".
                    {
                        if(strcmp(rut, ruta[i][j].localidad)==0) //Si alguna localidad coincide con las localidades de una ruta, se introduce en la cadena.
                        {
                            strcpy(rut2, ruta[i][j].localidad);
                        }
                    }
                    j=0; //Vamos reseteando las columnas al saltar de fila.
                }
            }
        }
    }
}

//Prototipo: void preguntar_veh(Estr_Vehiculo *, int, char *, int *);
//Precondición: Tener la estructura "vehiculo" inicializada, con su contador. Además, necesitamos una cadena, donde introducir la localidad introducida, y una variable bandera con puntero.
//Postcondición: Preguntar una matricula, y comprobar si existe en el sistema.

void preguntar_veh(Estr_Vehiculo *vehiculo, int numVehiculos, char *opc, int *encontrado)
{
    int counter;

    pregunta(opc, 8); //Pedimos la matricula.
    for(counter=0;(counter<numVehiculos)&&((*encontrado)==0);counter++) //Nos desplazamos por toda la estructura "vehiculo", hasta encontrar la matricula.
    {
        if(strcmp(opc,vehiculo[counter].id_mat)==0) //Si la matricula introducida está en la estructura.
        {
            (*encontrado)=1;
            printf("Has seleccionado el vehiculo con matricula %s", opc);
        }
    }
    if((*encontrado)==0) //Si no existe la matricula.
    {
        system("cls");
        printf("No se ha encontrado ningun vehiculo con la siguiente matricula: %s\n", opc);
        system("PAUSE");
    }
}

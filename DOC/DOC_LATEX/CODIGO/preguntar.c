#include "preguntar.h"

//Prototipo: void pregunta(char *, int);
//Precondicion: Tener una cadena y un entero inicializados, que nos indique el num maximo de caracteres de la misma.
//Postcondicion: Introducir en una cadena, la informacion escaneada, pero cambiando el salto de linea \n por el caracter nulo \0.

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

//Prototipo: void preguntar_contrasena(char *);
//Precondicion: Tener una cadena inicializada, donde introducir la contrasena escaneada.
//Postcondicion: Introducir en una cadena, la contrasena escaneada, pero cambiando el salto de linea \n por el caracter nulo \0. La contrasena introducida debe tener al menos 1 caracter.
//Se hace asi, para poder escribir * cuando se escriba una contrasena.

void preguntar_contrasena(char *contra)
{
    char c;
    int encontrado=0, j=0;

    while(!encontrado) //Bucle para que se compruebe si la contrasena tiene al menos 1 caracter.
    {
        fflush(stdin);
        while((c=getch())!='\r'&&j<8) //Lee el caracter, hasta 8.
        {
            if (c=='\b'&&j>0) //Si se borra algo, se borra un *, y se resta una posicion del vector.
            {
                j--;
                printf("\b \b");
            }
            else if (c != '\b') //Si se escribe algo, se imprime *, y se introduce en vector contra.
            {
            contra[j++] = c;
            printf("*");
            }
        }
        if(j>0) //Si la cadena tiene mas de 1 caracter, salimos del bucle.
        {
            encontrado=1;
        }
        else
        {
            printf("\nLa contrasena debe tener entre 1 y 8 caracteres.\n");
            printf("Vuelva a introducir una contrasena valida.\n");
            j=0;
        }
        contra[j] = '\0';
    }
}

//Prototipo: void pregunta_localidad(Estr_Localidad *, int, char *);
//Precondicion: Tener la estructura "localidad" inicializada, con su contador. Ademas, necesitamos una cadena, donde introducir la localidad introducida.
//Postcondicion: Introducir en una cadena, la localidad seleccionada de la lista.

void pregunta_localidad(Estr_Localidad *localidad, int numLocalidades, char *local)
{
    char vec_loc[4];
    int i, encontrado=0;

    listarLocalidades(localidad, numLocalidades); //Imprime una lista con todas las localicades.

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

//Prototipo: void pregunta_ruta(Estr_Localidad *, int, Estr_Rutas **, int, int, char *);
//Precondicion: Tener la estructura "localidad" y "ruta" inicializadas, con sus contadores. Ademas, necesitamos una cadena, donde introducir la localidad introducida.
//Postcondicion: Introducir en una cadena, la localidad seleccionada de la lista, que esté en una ruta.

void pregunta_ruta(Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, char *rut2)
{
    int i, j, x, encontrado=0;
    char rut[4];

    listarLocalidades(localidad, numLocalidades); //Imprime una lista con todas las localicades.

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
//Precondicion: Tener la estructura "vehiculo" inicializada, con su contador. Ademas, necesitamos una cadena, donde introducir la localidad introducida, y una variable bandera con puntero.
//Postcondicion: Preguntar una matricula, y comprobar si existe en el sistema.

void preguntar_veh(Estr_Vehiculo *vehiculo, int numVehiculos, char *opc, int *encontrado)
{
    int counter;

    pregunta(opc, 8); //Pedimos la matricula.
    for(counter=0;(counter<numVehiculos)&&((*encontrado)==0);counter++) //Nos desplazamos por toda la estructura "vehiculo", hasta encontrar la matricula.
    {
        if(strcmp(opc,vehiculo[counter].id_mat)==0) //Si la matricula introducida esta en la estructura.
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

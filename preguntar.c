#include "preguntar.h"

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

void preguntar_id_alta(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos)
{
    char opc2[4];
    int encontrado=0, i, counter;

    pregunta(opc2, 5);
    for(counter=0;(counter<numUsuarios)&&(encontrado==0);counter++)
    {
        if(strcmp(opc2,usuario[counter].id_usuario)==0)
        {
            encontrado=1;
            i=counter;
            altaVehiculo(usuario, vehiculo, numVehiculos, i);
        }
    }
    if(encontrado==0)
    {
        system("cls");
        printf("No se ha encontrado ningun usuario con la siguiente ID: %s\n",opc2);
        system("PAUSE");
    }
}


void pregunta_localidad(Estr_Localidad *localidad, int numLocalidades, char *local)
{
    char vec_loc[4];
    int i, j, k, encontrado=0, maxLoc;

    leer_localidad(&localidad,&maxLoc);

    maxLoc--; //Queremos quitarle la �ltima l�nea que contiene a la Escuela Superior de Ingenier�a (ESI), para que no se imprima por pantalla, junto a las localidades.

    k=maxLoc/4; //Calcular filas necesarias.

    if (maxLoc%4!=0)
    {
        k++;
    }

    for(i=0; i<k; i++) //Imprimimos la lista de ciudades en 4 columnas homog�neas.
    {
        for (j=i; j<maxLoc; j=j+k)
        {
            color(0, 3);
            printf("%s", localidad[j].siglas);
            color(0, 15);
            printf("-%-20s\t", localidad[j].localidad);
        }
        printf("\n");
    }

    while(encontrado==0)
    {
        pregunta(vec_loc, 4);

        for(i=0; i<maxLoc; i++)
        {
            if(strcmp(vec_loc, localidad[i].siglas)==0)
            {
                encontrado=1;
                printf("Has seleccionado %s.\n", localidad[i].localidad);

                strcpy(local, localidad[i].localidad);
            }
        }
    }
    return;
}

void pregunta_ruta(Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, char *rut2)
{
    int i, h, j, k, x, encontrado=0;
    char rut[4];

    leer_localidad(&localidad,&numLocalidades);
    leer_ruta(&ruta,&numRutas,&numRutas2);

    numLocalidades--; //Queremos quitarle la �ltima l�nea que contiene a la Escuela Superior de Ingenier�a (ESI), para que no se imprima por pantalla, junto a las localidades.

    k=numLocalidades/4; //Calcular filas necesarias.

    if (numLocalidades%4!=0)
    {
        k++;
    }

    for(i=0; i<k; i++) //Imprimimos la lista de ciudades en 4 columnas homog�neas.
    {
        for (j=i; j<numLocalidades; j=j+k)
        {
            color(0, 3);
            printf("%s", localidad[j].siglas);
            color(0, 15);
            printf("-%-20s\t", localidad[j].localidad);
        }
        printf("\n");
    }

    fflush(stdin);
    while(encontrado==0)
    {
        pregunta(rut, 4);

        for(x=0; x<numLocalidades; x++)
        {
            if(strcmp(rut, localidad[x].siglas)==0)
            {
                encontrado=1;
                printf("Has seleccionado %s.\n", localidad[x].localidad);

                for(i=0; i<numRutas; i++)
                {
                    for(j=0; j<numRutas2; j++)
                    {
                        if(strcmp(rut, ruta[i][j].localidad)==0)
                        {
                            strcpy(rut2, ruta[i][j].localidad);
                        }
                    }
                    j=0;
                }
            }
        }
    }
    return;
}

void preguntar_veh(Estr_Vehiculo *vehiculo, int numVehiculos, char *opc, int *encontrado)
{
    int counter;

    pregunta(opc, 8);
    for(counter=0;(counter<numVehiculos)&&((*encontrado)==0);counter++)
    {
        if(strcmp(opc,vehiculo[counter].id_mat)==0)
        {
            (*encontrado)=1;
            printf("Has seleccionado el vehiculo con matricula %s", opc);
        }
    }
    if((*encontrado)==0)
    {
        system("cls");
        printf("No se ha encontrado ningun vehiculo con la siguiente matricula: %s\n", opc);
        system("PAUSE");
    }
}

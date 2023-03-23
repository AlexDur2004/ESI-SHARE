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

void pregunta_localidad(char *local)
{
    char vec_loc[4];
    int i, j, k, encontrado=0, maxLoc;

    leer_localidad(&localidad,&maxLoc);

    maxLoc--; //Queremos quitarle la última línea que contiene a la Escuela Superior de Ingeniería (ESI), para que no se imprima por pantalla, junto a las localidades.

    k=maxLoc/4; //Calcular filas necesarias.

    if (maxLoc%4!=0)
    {
        k++;
    }

    for(i=0; i<k; i++) //Imprimimos la lista de ciudades en 4 columnas homogéneas.
    {
        for (j=i; j<maxLoc; j=j+k)
        {
            printf("%s-%-20s\t", localidad[j].siglas, localidad[j].localidad);
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

void pregunta_ruta(char *rut2)
{
    int i, h, j, k, x, encontrado=0;
    char rut[4];

    leer_localidad(&localidad,&numLocalidades);
    leer_ruta(&ruta,&numRutas,&numRutas2);

    numLocalidades--; //Queremos quitarle la última línea que contiene a la Escuela Superior de Ingeniería (ESI), para que no se imprima por pantalla, junto a las localidades.

    k=numLocalidades/4; //Calcular filas necesarias.

    if (numLocalidades%4!=0)
    {
        k++;
    }

    for(i=0; i<k; i++) //Imprimimos la lista de ciudades en 4 columnas homogéneas.
    {
        for (j=i; j<numLocalidades; j=j+k)
        {
            printf("%s-%-20s\t", localidad[j].siglas, localidad[j].localidad);
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

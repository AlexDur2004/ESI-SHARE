#include "preguntar_localidad.h"

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
            *lin = '\0';
        }
        if(strlen(x)>0)
        {
            encontrado=1;
        }
    }
}

void pregunta_localidad(char local[21])
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
            printf("%s-%-20s\t", localidad[j].siglas, localidad[j].localidad);
        }
        printf("\n");
    }

    printf("\n");
    fflush(stdin);

    while(encontrado==0)
    {
        scanf("%3s", vec_loc);

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

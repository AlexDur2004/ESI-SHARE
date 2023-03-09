#include "preguntar_localidad.h"

void pregunta_localidad(char local[21])
{
    char vec_loc[4];
    int i, j, k, maxLoc;

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

    printf("\n");
    fflush(stdin);
    scanf("%3s", vec_loc);

    for(i=0; i<maxLoc; i++)
    {
        if(strcmp(vec_loc, localidad[i].siglas)==0)
        {
            printf("Has seleccionado %s.\n", localidad[i].localidad);

            strcpy(local, localidad[i].localidad);
        }
    }

    return;
}

#include "encontrar.h"

void encontrarVehiculos(int **vec, int *x, int i)
{
    int j;
    *x=0;

    for(j=0; j<numVehiculos; j++) //con esto se puede sacar todos los vehiculos de un usuario.
    {
        if(strcmp(usuario[i].id_usuario, vehiculo[j].id_usuario)==0)
        {
            *vec=(int *)realloc(*vec,((*x)+1)*sizeof(int));
            if ((*vec)==NULL)
            {
                printf("Error al asignar memoria.\n");
                exit(1);
            }
            (*vec)[*x]=j;
            (*x)++;
        }
    }
}

void encontrarViajes(char *mat, int **vec, int *x)
{
    int j;
    *x=0;

    for(j=0; j<numViajes; j++) //con esto se puede sacar todos los viajes de un vehiculo.
    {
        if(strcmp(viaje[j].id_mat, mat)==0)
        {
            *vec=(int *)realloc(*vec,((*x)+1)*sizeof(int));
            if ((*vec)==NULL)
            {
                printf("Error al asignar memoria.\n");
                exit(1);
            }
            (*vec)[*x]=j;
            (*x)++;
        }
    }
}

void encontrarUsuario(char vec_id[], int *x, int *encontrado)
{
    int j;
    *x=0;
    *encontrado=0;

    for(j=0; j<numUsuarios; j++) //con esto se puede sacar todos los vehiculos de un usuario.
    {
        if(strcmp(vec_id, usuario[j].id_usuario)==0)
        {
            *x=j;
            *encontrado=1;
        }
    }
}

void encontrarRutas(char *loc[4], char ***mat_loc, int *x, int y)
{
    int j, i;
    *x=0;
    printf("%s", loc);

    for(i=0; i<numRutas; i++) //con esto se puede sacar todos los rutas posibles, que habría de una ciudad a la ESI.
    {
        for(j=0; j<numRutas2; j++)
        {
           if(strcmp(ruta[i][j].localidad, loc[y])==0)
            {
                printf("%s", ruta[i][j].localidad);
                *mat_loc=(char **)realloc(*mat_loc,((*x)+1)*sizeof(char*));
                if ((*mat_loc)==NULL)
                {
                    printf("Error al asignar memoria.\n");
                    exit(1);
                }
                (*mat_loc)[*x]=(char*)malloc((strlen(ruta[i][j].localidad)+1)*sizeof(char));
                if ((*mat_loc)[*x]==NULL)
                {
                    printf("Error al asignar memoria 2.\n");
                    exit(1);
                }
                strcpy((*mat_loc)[*x], ruta[i][j].localidad);
                (*x)++;
                printf("%s", ruta[i][j].localidad);
                y++;
            }
        }
    }
}

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

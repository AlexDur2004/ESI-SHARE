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

void encontrarViajes(char *mat, int **vec, int *x, int num) //Si num=0, encuentra todos los viajes de un vehiculo, si num=1, encuentra los abiertos, para anularlos, y si num=2, se encuentran los abiertos y los iniciados.
{
    int i,j;
    *x=0;

    for(j=0; j<numViajes; j++) //con esto se puede sacar todos los viajes de un vehiculo.
    {
        if(strcmp(viaje[j].id_mat, mat)==0)
        {
            if(num==0)
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
            if(num==1)
            {
                if(strcmp(viaje[j].estado, "abierto")==0)
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
            if(num==2)
            {
                if(strcmp(viaje[j].estado, "abierto")==0||strcmp(viaje[j].estado, "iniciado")==0)
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
        if(num==3)
            {
                if(strcmp(viaje[j].estado, "iniciado")==0)
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
         if(num==4)
            {
                for(i=0;i<numVehiculos;i++){
                    if(strcmp(mat,vehiculo[i].id_mat)==0){
                       for(j=0;j<numViajes;j++){
                            if(strcmp(viaje[j].estado,"abierto")==0){
                                if(strcmp(viaje[j].plazas_libre,vehiculo[i].num_plazas)==0){
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
                    }
                }



            }
        }

    }

}

void encontrarResevas(int num_user,int **vec,int **vec_viaje,int *x){
    int i,j;
    (*x)=0;
    for(i=0;i<numReservas;i++){
       if(strcmp(reservas[i].id_usuario,usuario[num_user].id_usuario)==0){
        for(j=0;j<numViajes;j++){
                if(strcmp(viaje[j].id_viaje,reservas[i].id_viaje)==0){
                    if(strcmp(viaje[j].estado,"abierto")==0){
                    *vec=(int *)realloc(*vec,((*x)+1)*sizeof(int));
                    if ((*vec)==NULL)
                    {
                        printf("Error al asignar memoria.\n");
                        exit(1);
                    }
                    *vec_viaje=(int*)realloc(*vec_viaje,((*x)+1)*sizeof(int));
                     if ((*vec_viaje)==NULL)
                        {
                        printf("Error al asignar memoria.\n");
                        exit(1);
                        }

                    (*vec_viaje)[*x]=j;
                    (*vec)[*x]=i;
                    (*x)++;

                }
                }

              }


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

void encontrarViajesReservas(int num_user,char *fecha,int **vec,int *x,int *loc){
     int i,j;
    *x=0;
    *loc=0;
    for(i=0; i<numPasos; i++) {

        if(strcmp(usuario[num_user].localidad,pasos[i].poblacion)==0){
                (*loc)++;
            for(j=0;j<numViajes;j++){
                if(strcmp(pasos[i].id_viaje,viaje[j].id_viaje)==0){

                    if(strcmp(fecha,viaje[j].f_inic)==0){

                        if(strcmp(viaje[j].estado,"abierto")==0||strcmp(viaje[j].estado,"iniciado")==0){

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
            }

        }
    }
}

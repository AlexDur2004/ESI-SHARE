#include "encontrar.h"

//Prototipo: void encontrarVehiculos(int **, int *, int);
//Precondición: Introducir un vector de enteros, para introducir datos en el mismo, al igual que la variable "x",
//para saber cuántos vehículos tiene dicho usuario, y la varible "i", para identificar el usuario, es decir, la posición
//en la estructura de "usuario". Además, se necesitan las estructuras "usuario" y "vehiculo" inicializadas, con sus contadores "numVehiculos" y "numUsuarios".
//Postcondición: Busca todos los vehículos de un usuario mediante su id, e introduce las posiciones en la estructura de dichos vehículos en un vector de enteros.

void encontrarVehiculos(Estr_Usuario *usuario, Estr_Vehiculo *vehiculo, int numVehiculos, int **vec, int *x, int i)
{
    int j, h;
    *x=0;

    for(j=0; j<numVehiculos; j++) //Nos desplazamos por toda la estructura "vehiculo".
    {
        if(strcmp(usuario[i].id_usuario, vehiculo[j].id_usuario)==0) //Si la id del usuario que hemos introducido es igual a la id del usuario de un vehículo.
        {
            *vec=(int *)realloc(*vec,((*x)+1)*sizeof(int)); //Asignamos un espacio de memoria más, para introducir el vehículo detectado.
            if ((*vec)==NULL)
            {
                printf("Error al asignar memoria.\n");
                exit(1);
            }
            (*vec)[*x]=j; //Se introduce la posición del vehículo encontrado en la estructura en el vector de enteros dinámico.
            (*x)++; //Vamos aumentando en 1, la cantidad de vehículos que tiene el usuario, que al mismo tiempo servirá para acceder al vector de enteros.
        }
    }
}

//Prototipo: void encontrarViajes(char *, int **, int *, int);
//Precondición: Introducir la cadena "mat", que será la matrícula del vehículo, al que queremos obtener todos sus viajes, un vector de enteros,
//para introducir datos en el mismo, al igual que la variable "x", para saber cuántos viajes tiene dicho usuario, y la varible "num", que será 0, 1 ó 2,
//dependiendo de para qué queramos usar la función. Además, se necesita la estructura "viaje" inicializada, con su contador "numViajes".
//Postcondición: Busca todos los viajes de un vehículo mediante su matrícula, e introduce las posiciones en la estructura de dichos viajes en un vector de enteros.

void encontrarViajes(Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, char *mat, int **vec, int *x, int num)
{
    int j, i;

    for(j=0; j<numViajes; j++) //Nos desplazamos por toda la estructura "viaje".
    {
        if(strcmp(viaje[j].id_mat, mat)==0) //Si la matrícula del coche que hemos introducido es igual a la matrícula asignada en un viaje.
        {
            if(num==0) //Si num=0, se encuentran todos los viajes de un vehículo.
            {
                *vec=(int *)realloc(*vec,((*x)+1)*sizeof(int)); //Asignamos un espacio de memoria más, para introducir el vehículo detectado.
                if (*vec==NULL)
                {
                    printf("Error al asignar memoria.\n");
                    exit(1);
                }
                (*vec)[*x]=j; //Se introduce la posición del viaje encontrado en la estructura en el vector de enteros dinámico.
                (*x)++; //Vamos aumentando en 1, la cantidad de viajes que tiene el usuario, que al mismo tiempo servirá para acceder al vector de enteros.
            }
            if(num==1) //Si num=1, se encuentran los viajes abiertos e iniciados (para anularlos/finalizarlos).
            {
                if(strcmp(mat,viaje[j].id_mat)==0)
                {
                    for(i=0;i<numVehiculos;i++)
                    {
                        if((strcmp(viaje[j].estado, "abierto")==0)&&(strcmp(mat, vehiculo[i].id_mat)==0))
                        {
                            if(strcmp(viaje[j].plazas_libre, vehiculo[i].num_plazas)==0)
                            {
                                *vec=(int *)realloc(*vec,((*x)+1)*sizeof(int));
                                if (*vec==NULL)
                                {
                                    printf("Error al asignar memoria.\n");
                                    exit(1);
                                }
                                (*vec)[*x]=j;
                                (*x)++;
                            }
                        }
                        if((strcmp(viaje[j].estado, "iniciado")==0)&&(strcmp(mat, vehiculo[i].id_mat)==0))
                        {
                            *vec=(int *)realloc(*vec,((*x)+1)*sizeof(int));
                            if (*vec==NULL)
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
            if(num==2) //Si num=2, se encuentran los viajes abiertos (para modificarlos).
            {
                if((strcmp(viaje[j].estado, "abierto")==0))
                {
                    for(i=0;i<numVehiculos;i++)
                    {
                        if(strcmp(mat,vehiculo[i].id_mat)==0&&(strcmp(mat, viaje[j].id_mat)==0))
                        {
                            if(strcmp(viaje[j].plazas_libre,vehiculo[i].num_plazas)==0)
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
                }
            }
        }
    }
}

//Prototipo: void encontrarUsuario(char *, int *, int *);
//Precondición: Introducir la cadena "vec_id", que será la id de un usuario que queremos encontrar, junto a una variable "x", para obtener la posición
//del usuario en la estructura "usuario", y la variable "encontrado" incializada. Además, se necesita la estructura "usuario", con su contador "numUsuarios".
//Postcondición: Busca al usuario en la base de datos mediante su id, e introduce su posición en la estructura en una variable "x",
//y "encontrado" pasa a ser 1, si se encuentra el usuario.

void encontrarUsuario(Estr_Usuario *usuario, int numUsuarios, char vec_id[], int *x, int *encontrado)
{
    int j;
    *x=0;
    *encontrado=0;

    for(j=0; j<numUsuarios; j++) //Nos desplazamos por toda la estructura "usuario".
    {
        if(strcmp(vec_id, usuario[j].id_usuario)==0) //Si la id de usuario introducida está en la estructura "usuario".
        {
            *x=j; //x obtiene la posición del usuario en la estructura.
            *encontrado=1;
        }
    }
}

void encontrarReservas(Estr_Usuario *usuario, Estr_Viaje *viaje, int numViajes, Estr_Reservas *reservas, int numReservas, int num_user, int **vec, int **vec_viaje, int *x)
{
    int i,j;
    (*x)=0;

    for(i=0;i<numReservas;i++)
    {
       if(strcmp(reservas[i].id_usuario,usuario[num_user].id_usuario)==0)
       {
            for(j=0;j<numViajes;j++)
            {
                if(strcmp(viaje[j].id_viaje,reservas[i].id_viaje)==0)
                {
                    if(strcmp(viaje[j].estado,"abierto")==0)
                    {
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

void encontrarViajesReservas(Estr_Usuario *usuario, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos,int num_user, char *fecha, int **vec, int *x, int *loc)
{
     int i,j;
    *x=0;
    *loc=0;

    (*vec)=malloc((*x)*sizeof(int));
    if ((*vec)==NULL)
    {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    for(i=0; i<numPasos; i++)
    {
        if(strcmp(usuario[num_user].localidad,pasos[i].poblacion)==0)
        {
            (*loc)++;
            for(j=0;j<numViajes;j++)
            {
                if(strcmp(pasos[i].id_viaje,viaje[j].id_viaje)==0)
                {
                    if(strcmp(fecha,viaje[j].f_inic)==0)
                    {
                        if(strcmp(viaje[j].estado,"abierto")==0||strcmp(viaje[j].estado,"iniciado")==0)
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
            }
        }
    }
}

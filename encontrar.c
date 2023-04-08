#include "encontrar.h"

//Prototipo: void encontrarVehiculos(Estr_Usuario *, Estr_Vehiculo *, int, int **, int *, int);
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

//Prototipo: void encontrarViajes(Estr_Vehiculo *, int, Estr_Viaje *, int, char *, int **, int *, int);
//Precondición: Introducir la cadena "mat", que será la matrícula del vehículo, al que queremos obtener todos sus viajes, un vector de enteros,
//para introducir datos en el mismo, al igual que la variable "x", para saber cuántos viajes tiene dicho usuario, y la varible "num", que será 0, 1 ó 2,
//dependiendo de para qué queramos usar la función. Además, se necesita las estructuras "vehiculos" y "viaje" inicializadas, con sus contadores.
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
                *vec=(int *)realloc(*vec,((*x)+1)*sizeof(int)); //Asignamos un espacio de memoria más, para introducir el viaje detectado.
                if (*vec==NULL)
                {
                    printf("Error al asignar memoria.\n");
                    exit(1);
                }
                (*vec)[*x]=j; //Se introduce la posición del viaje encontrado en la estructura en el vector de enteros dinámico.
                (*x)++; //Vamos aumentando en 1, la cantidad de viajes que tiene el usuario, que al mismo tiempo servirá para acceder al vector de enteros.
            }
            if(num==1) //Si num=1, se encuentran los viajes abiertos, sin plazas ocupadas, e iniciados(para anularlos/finalizarlos).
            {
                if(strcmp(mat,viaje[j].id_mat)==0) //Si el viaje tiene la matrícula que hemos introducido.
                {
                    for(i=0;i<numVehiculos;i++)
                    {
                        if((strcmp(viaje[j].estado, "abierto")==0)&&(strcmp(mat, vehiculo[i].id_mat)==0)) //Si el viaje está abierto, y la matrícula del coche coincide.
                        {
                            if(strcmp(viaje[j].plazas_libre, vehiculo[i].num_plazas)==0) //Si no se han ocupado plazas del viaje, es decir, nº plazas libres = nº plazas vehiculo.
                            {
                                *vec=(int *)realloc(*vec,((*x)+1)*sizeof(int)); //Asignamos un espacio de memoria más, para introducir el viaje detectado.
                                if (*vec==NULL)
                                {
                                    printf("Error al asignar memoria.\n");
                                    exit(1);
                                }
                                (*vec)[*x]=j; //Se introduce la posición del viaje encontrado en la estructura en el vector de enteros dinámico.
                                (*x)++; //Vamos aumentando en 1, la cantidad de viajes que tiene el usuario, que al mismo tiempo servirá para acceder al vector de enteros.
                            }
                        }
                        if((strcmp(viaje[j].estado, "iniciado")==0)&&(strcmp(mat, vehiculo[i].id_mat)==0)) //Si el viaje está iniciado, y la matrícula del coche coincide.
                        {
                            *vec=(int *)realloc(*vec,((*x)+1)*sizeof(int)); //Asignamos un espacio de memoria más, para introducir el viaje detectado.
                            if (*vec==NULL)
                            {
                                printf("Error al asignar memoria.\n");
                                exit(1);
                            }
                            (*vec)[*x]=j; //Se introduce la posición del viaje encontrado en la estructura en el vector de enteros dinámico.
                            (*x)++; //Vamos aumentando en 1, la cantidad de viajes que tiene el usuario, que al mismo tiempo servirá para acceder al vector de enteros.
                        }
                    }
                }
            }
            if(num==2) //Si num=2, se encuentran los viajes abiertos (para modificarlos).
            {
                if((strcmp(viaje[j].estado, "abierto")==0)) //Si el viaje está abierto.
                {
                    for(i=0;i<numVehiculos;i++)
                    {
                        if(strcmp(mat,vehiculo[i].id_mat)==0&&(strcmp(mat, viaje[j].id_mat)==0)) //Si la matrícula introducida coincide con la del vehiculo, y la del viaje.
                        {
                            if(strcmp(viaje[j].plazas_libre,vehiculo[i].num_plazas)==0) //Si no se han ocupado plazas del viaje, es decir, nº plazas libres = nº plazas vehiculo.
                            {
                                *vec=(int *)realloc(*vec,((*x)+1)*sizeof(int)); //Asignamos un espacio de memoria más, para introducir el viaje detectado.
                                if ((*vec)==NULL)
                                {
                                    printf("Error al asignar memoria.\n");
                                    exit(1);
                                }
                                (*vec)[*x]=j; //Se introduce la posición del viaje encontrado en la estructura en el vector de enteros dinámico.
                                (*x)++; //Vamos aumentando en 1, la cantidad de viajes que tiene el usuario, que al mismo tiempo servirá para acceder al vector de enteros.
                            }
                        }
                    }
                }
            }
        }
    }
}

//Prototipo: void encontrarUsuario(Estr_Usuario *, int, char *, int *, int *);
//Precondición: Introducir la cadena "vec_id", que será la id de un usuario que queremos encontrar, junto a una variable "x", para obtener la posición
//del usuario en la estructura "usuario", y la variable "encontrado" incializada. Además, se necesita la estructura "usuario", con su contador "numUsuarios".
//Postcondición: Busca al usuario en la base de datos mediante su id, e introduce su posición en la estructura en una variable "x", y "encontrado" pasa a ser 1, si se encuentra el usuario.

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

//Prototipo: void encontrarReservas(Estr_Usuario *, Estr_Viaje *, int, Estr_Reservas *, int, int, int **, int **, int *);
//Precondición: Introducir la varible "num_user", que nos dice la posición del usuario en la estructura "usuario", junto a una variable "x",
//para obtener el número máximo de reservas que cumplen las condiciones, y los vectores "vec" y "vec_viaje", para meter las posiciones en esos vector dinámicos.
//Además, se necesita las estructuras "usuario", "viaje" y "reservas" inicializadas, con sus contadores.
//Postcondición: Busca todas las reservas abiertas de un usuario, mediante su id, e introduce las posiciones en la estructura de dichas reservas
//en un vector de enteros, y las posiciones de de los viajes en los que están esas reservas, en otro vector de enteros.

void encontrarReservas(Estr_Usuario *usuario, Estr_Viaje *viaje, int numViajes, Estr_Reservas *reservas, int numReservas, int num_user, int **vec, int **vec_viaje, int *x)
{
    int i,j;
    (*x)=0;

    for(i=0;i<numReservas;i++) //Nos desplazamos por toda la estructura "reservas".
    {
       if(strcmp(reservas[i].id_usuario,usuario[num_user].id_usuario)==0) //Si la id del usuario que queremos buscar, coincide con la id del usuario en la reserva.
       {
            for(j=0;j<numViajes;j++) //Nos desplazamos por toda la estructura "viajes".
            {
                if(strcmp(viaje[j].id_viaje,reservas[i].id_viaje)==0) //Si la id de viaje, coincide con la id de viaje de la reserva.
                {
                    if(strcmp(viaje[j].estado,"abierto")==0) //Si el viaje está abierto.
                    {
                        *vec=(int *)realloc(*vec,((*x)+1)*sizeof(int)); //Asignamos un espacio de memoria más, para introducir la reserva detectada.
                        if ((*vec)==NULL)
                        {
                            printf("Error al asignar memoria.\n");
                            exit(1);
                        }

                        *vec_viaje=(int*)realloc(*vec_viaje,((*x)+1)*sizeof(int)); //Asignamos un espacio de memoria más, para introducir el viaje detectado.
                        if ((*vec_viaje)==NULL)
                        {
                            printf("Error al asignar memoria.\n");
                            exit(1);
                        }

                        (*vec_viaje)[*x]=j; //Se introduce la posición del viaje encontrado en la estructura en el vector de enteros dinámico.
                        (*vec)[*x]=i; //Introducimos la posición de la reserva encontrada en la estructura en el vector de enteros dinámico.
                        (*x)++; //Vamos aumentando en 1, la cantidad de viajes y reservas que tiene el usuario, que al mismo tiempo servirá para acceder a los dos vectores de enteros.
                    }
                }
            }
        }
    }
}

//Prototipo: void encontrarViajesReservas(Estr_Usuario *, Estr_Viaje *, int, Estr_Pasos *, int, int, char *, int **, int *, int *);
//Precondición: Introducir la varible "num_user", que nos dice la posición del usuario en la estructura "usuario", para saber su localidad, junto a una variable "x",
//para obtener el número máximo de viajes que cumplen las condiciones, y la variable "loc", para saber si hay viajes por su localidad, pero en fechas distintas,
//junto a un cadena "fecha", para saber en qué fecha quiere buscar el viaje, y el vector "vec", para introducir las posiciones de los viajes
//que pasan por la ciudad del usuario. Además, se necesita las estructuras "usuario", "viaje" y "pasos" inicializadas, con sus contadores.
//Postcondición: Busca todas los viajes abiertos o iniciados, que pasen por la localidad de un usuario, mediante su id, e introduce las posiciones en la
//estructura de dichos viajes en un vector de enteros. Si no hay viajes en la fecha indicada, entonces "loc" será distinto de 0.

void encontrarViajesReservas(Estr_Usuario *usuario, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, int num_user, char *fecha, int **vec, int *x, int *loc)
{
     int i,j;
    *x=0;
    *loc=0;

    for(i=0; i<numPasos; i++) //Nos desplazamos por toda la estructura "pasos".
    {
        if(strcmp(usuario[num_user].localidad,pasos[i].poblacion)==0) //Si hay algún viaje que pase por la localidad del usuario.
        {
            (*loc)++; //Se aumenta en 1, entonces sabemos que hay viajes en alguna fecha futura.
            for(j=0;j<numViajes;j++) //Nos desplazamos por toda la estructura "viajes".
            {
                if(strcmp(pasos[i].id_viaje,viaje[j].id_viaje)==0) //Si la id de viaje en los pasos coincide con la id de viaje.
                {
                    if(strcmp(fecha,viaje[j].f_inic)==0) //Comprobamos que la fecha introducida es igual a la fecha del viaje.
                    {
                        if(strcmp(viaje[j].estado,"abierto")==0||strcmp(viaje[j].estado,"iniciado")==0) //Si el viaje está abierto o iniciado.
                        {
                            *vec=(int *)realloc(*vec,((*x)+1)*sizeof(int)); //Asignamos un espacio de memoria más, para introducir el viaje detectado.
                            if ((*vec)==NULL)
                            {
                                printf("Error al asignar memoria.\n");
                                exit(1);
                            }
                            (*vec)[*x]=j; //Se introduce la posición del viaje encontrado en la estructura en el vector de enteros dinámico.
                            (*x)++; //Vamos aumentando en 1, la cantidad de viajes que tiene disponible el usuario para la fecha introducida,
                            //que al mismo tiempo servirá para acceder a los dos vectores de enteros.
                        }
                    }
                }
            }
        }
    }
}

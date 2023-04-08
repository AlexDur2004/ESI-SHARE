#include "encontrar.h"

//Prototipo: void encontrarVehiculos(Estr_Usuario *, Estr_Vehiculo *, int, int **, int *, int);
//Precondici�n: Introducir un vector de enteros, para introducir datos en el mismo, al igual que la variable "x",
//para saber cu�ntos veh�culos tiene dicho usuario, y la varible "i", para identificar el usuario, es decir, la posici�n
//en la estructura de "usuario". Adem�s, se necesitan las estructuras "usuario" y "vehiculo" inicializadas, con sus contadores "numVehiculos" y "numUsuarios".
//Postcondici�n: Busca todos los veh�culos de un usuario mediante su id, e introduce las posiciones en la estructura de dichos veh�culos en un vector de enteros.

void encontrarVehiculos(Estr_Usuario *usuario, Estr_Vehiculo *vehiculo, int numVehiculos, int **vec, int *x, int i)
{
    int j, h;
    *x=0;

    for(j=0; j<numVehiculos; j++) //Nos desplazamos por toda la estructura "vehiculo".
    {
        if(strcmp(usuario[i].id_usuario, vehiculo[j].id_usuario)==0) //Si la id del usuario que hemos introducido es igual a la id del usuario de un veh�culo.
        {
            *vec=(int *)realloc(*vec,((*x)+1)*sizeof(int)); //Asignamos un espacio de memoria m�s, para introducir el veh�culo detectado.
            if ((*vec)==NULL)
            {
                printf("Error al asignar memoria.\n");
                exit(1);
            }
            (*vec)[*x]=j; //Se introduce la posici�n del veh�culo encontrado en la estructura en el vector de enteros din�mico.
            (*x)++; //Vamos aumentando en 1, la cantidad de veh�culos que tiene el usuario, que al mismo tiempo servir� para acceder al vector de enteros.
        }
    }
}

//Prototipo: void encontrarViajes(Estr_Vehiculo *, int, Estr_Viaje *, int, char *, int **, int *, int);
//Precondici�n: Introducir la cadena "mat", que ser� la matr�cula del veh�culo, al que queremos obtener todos sus viajes, un vector de enteros,
//para introducir datos en el mismo, al igual que la variable "x", para saber cu�ntos viajes tiene dicho usuario, y la varible "num", que ser� 0, 1 � 2,
//dependiendo de para qu� queramos usar la funci�n. Adem�s, se necesita las estructuras "vehiculos" y "viaje" inicializadas, con sus contadores.
//Postcondici�n: Busca todos los viajes de un veh�culo mediante su matr�cula, e introduce las posiciones en la estructura de dichos viajes en un vector de enteros.

void encontrarViajes(Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, char *mat, int **vec, int *x, int num)
{
    int j, i;

    for(j=0; j<numViajes; j++) //Nos desplazamos por toda la estructura "viaje".
    {
        if(strcmp(viaje[j].id_mat, mat)==0) //Si la matr�cula del coche que hemos introducido es igual a la matr�cula asignada en un viaje.
        {
            if(num==0) //Si num=0, se encuentran todos los viajes de un veh�culo.
            {
                *vec=(int *)realloc(*vec,((*x)+1)*sizeof(int)); //Asignamos un espacio de memoria m�s, para introducir el viaje detectado.
                if (*vec==NULL)
                {
                    printf("Error al asignar memoria.\n");
                    exit(1);
                }
                (*vec)[*x]=j; //Se introduce la posici�n del viaje encontrado en la estructura en el vector de enteros din�mico.
                (*x)++; //Vamos aumentando en 1, la cantidad de viajes que tiene el usuario, que al mismo tiempo servir� para acceder al vector de enteros.
            }
            if(num==1) //Si num=1, se encuentran los viajes abiertos, sin plazas ocupadas, e iniciados(para anularlos/finalizarlos).
            {
                if(strcmp(mat,viaje[j].id_mat)==0) //Si el viaje tiene la matr�cula que hemos introducido.
                {
                    for(i=0;i<numVehiculos;i++)
                    {
                        if((strcmp(viaje[j].estado, "abierto")==0)&&(strcmp(mat, vehiculo[i].id_mat)==0)) //Si el viaje est� abierto, y la matr�cula del coche coincide.
                        {
                            if(strcmp(viaje[j].plazas_libre, vehiculo[i].num_plazas)==0) //Si no se han ocupado plazas del viaje, es decir, n� plazas libres = n� plazas vehiculo.
                            {
                                *vec=(int *)realloc(*vec,((*x)+1)*sizeof(int)); //Asignamos un espacio de memoria m�s, para introducir el viaje detectado.
                                if (*vec==NULL)
                                {
                                    printf("Error al asignar memoria.\n");
                                    exit(1);
                                }
                                (*vec)[*x]=j; //Se introduce la posici�n del viaje encontrado en la estructura en el vector de enteros din�mico.
                                (*x)++; //Vamos aumentando en 1, la cantidad de viajes que tiene el usuario, que al mismo tiempo servir� para acceder al vector de enteros.
                            }
                        }
                        if((strcmp(viaje[j].estado, "iniciado")==0)&&(strcmp(mat, vehiculo[i].id_mat)==0)) //Si el viaje est� iniciado, y la matr�cula del coche coincide.
                        {
                            *vec=(int *)realloc(*vec,((*x)+1)*sizeof(int)); //Asignamos un espacio de memoria m�s, para introducir el viaje detectado.
                            if (*vec==NULL)
                            {
                                printf("Error al asignar memoria.\n");
                                exit(1);
                            }
                            (*vec)[*x]=j; //Se introduce la posici�n del viaje encontrado en la estructura en el vector de enteros din�mico.
                            (*x)++; //Vamos aumentando en 1, la cantidad de viajes que tiene el usuario, que al mismo tiempo servir� para acceder al vector de enteros.
                        }
                    }
                }
            }
            if(num==2) //Si num=2, se encuentran los viajes abiertos (para modificarlos).
            {
                if((strcmp(viaje[j].estado, "abierto")==0)) //Si el viaje est� abierto.
                {
                    for(i=0;i<numVehiculos;i++)
                    {
                        if(strcmp(mat,vehiculo[i].id_mat)==0&&(strcmp(mat, viaje[j].id_mat)==0)) //Si la matr�cula introducida coincide con la del vehiculo, y la del viaje.
                        {
                            if(strcmp(viaje[j].plazas_libre,vehiculo[i].num_plazas)==0) //Si no se han ocupado plazas del viaje, es decir, n� plazas libres = n� plazas vehiculo.
                            {
                                *vec=(int *)realloc(*vec,((*x)+1)*sizeof(int)); //Asignamos un espacio de memoria m�s, para introducir el viaje detectado.
                                if ((*vec)==NULL)
                                {
                                    printf("Error al asignar memoria.\n");
                                    exit(1);
                                }
                                (*vec)[*x]=j; //Se introduce la posici�n del viaje encontrado en la estructura en el vector de enteros din�mico.
                                (*x)++; //Vamos aumentando en 1, la cantidad de viajes que tiene el usuario, que al mismo tiempo servir� para acceder al vector de enteros.
                            }
                        }
                    }
                }
            }
        }
    }
}

//Prototipo: void encontrarUsuario(Estr_Usuario *, int, char *, int *, int *);
//Precondici�n: Introducir la cadena "vec_id", que ser� la id de un usuario que queremos encontrar, junto a una variable "x", para obtener la posici�n
//del usuario en la estructura "usuario", y la variable "encontrado" incializada. Adem�s, se necesita la estructura "usuario", con su contador "numUsuarios".
//Postcondici�n: Busca al usuario en la base de datos mediante su id, e introduce su posici�n en la estructura en una variable "x", y "encontrado" pasa a ser 1, si se encuentra el usuario.

void encontrarUsuario(Estr_Usuario *usuario, int numUsuarios, char vec_id[], int *x, int *encontrado)
{
    int j;
    *x=0;
    *encontrado=0;

    for(j=0; j<numUsuarios; j++) //Nos desplazamos por toda la estructura "usuario".
    {
        if(strcmp(vec_id, usuario[j].id_usuario)==0) //Si la id de usuario introducida est� en la estructura "usuario".
        {
            *x=j; //x obtiene la posici�n del usuario en la estructura.
            *encontrado=1;
        }
    }
}

//Prototipo: void encontrarReservas(Estr_Usuario *, Estr_Viaje *, int, Estr_Reservas *, int, int, int **, int **, int *);
//Precondici�n: Introducir la varible "num_user", que nos dice la posici�n del usuario en la estructura "usuario", junto a una variable "x",
//para obtener el n�mero m�ximo de reservas que cumplen las condiciones, y los vectores "vec" y "vec_viaje", para meter las posiciones en esos vector din�micos.
//Adem�s, se necesita las estructuras "usuario", "viaje" y "reservas" inicializadas, con sus contadores.
//Postcondici�n: Busca todas las reservas abiertas de un usuario, mediante su id, e introduce las posiciones en la estructura de dichas reservas
//en un vector de enteros, y las posiciones de de los viajes en los que est�n esas reservas, en otro vector de enteros.

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
                    if(strcmp(viaje[j].estado,"abierto")==0) //Si el viaje est� abierto.
                    {
                        *vec=(int *)realloc(*vec,((*x)+1)*sizeof(int)); //Asignamos un espacio de memoria m�s, para introducir la reserva detectada.
                        if ((*vec)==NULL)
                        {
                            printf("Error al asignar memoria.\n");
                            exit(1);
                        }

                        *vec_viaje=(int*)realloc(*vec_viaje,((*x)+1)*sizeof(int)); //Asignamos un espacio de memoria m�s, para introducir el viaje detectado.
                        if ((*vec_viaje)==NULL)
                        {
                            printf("Error al asignar memoria.\n");
                            exit(1);
                        }

                        (*vec_viaje)[*x]=j; //Se introduce la posici�n del viaje encontrado en la estructura en el vector de enteros din�mico.
                        (*vec)[*x]=i; //Introducimos la posici�n de la reserva encontrada en la estructura en el vector de enteros din�mico.
                        (*x)++; //Vamos aumentando en 1, la cantidad de viajes y reservas que tiene el usuario, que al mismo tiempo servir� para acceder a los dos vectores de enteros.
                    }
                }
            }
        }
    }
}

//Prototipo: void encontrarViajesReservas(Estr_Usuario *, Estr_Viaje *, int, Estr_Pasos *, int, int, char *, int **, int *, int *);
//Precondici�n: Introducir la varible "num_user", que nos dice la posici�n del usuario en la estructura "usuario", para saber su localidad, junto a una variable "x",
//para obtener el n�mero m�ximo de viajes que cumplen las condiciones, y la variable "loc", para saber si hay viajes por su localidad, pero en fechas distintas,
//junto a un cadena "fecha", para saber en qu� fecha quiere buscar el viaje, y el vector "vec", para introducir las posiciones de los viajes
//que pasan por la ciudad del usuario. Adem�s, se necesita las estructuras "usuario", "viaje" y "pasos" inicializadas, con sus contadores.
//Postcondici�n: Busca todas los viajes abiertos o iniciados, que pasen por la localidad de un usuario, mediante su id, e introduce las posiciones en la
//estructura de dichos viajes en un vector de enteros. Si no hay viajes en la fecha indicada, entonces "loc" ser� distinto de 0.

void encontrarViajesReservas(Estr_Usuario *usuario, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, int num_user, char *fecha, int **vec, int *x, int *loc)
{
     int i,j;
    *x=0;
    *loc=0;

    for(i=0; i<numPasos; i++) //Nos desplazamos por toda la estructura "pasos".
    {
        if(strcmp(usuario[num_user].localidad,pasos[i].poblacion)==0) //Si hay alg�n viaje que pase por la localidad del usuario.
        {
            (*loc)++; //Se aumenta en 1, entonces sabemos que hay viajes en alguna fecha futura.
            for(j=0;j<numViajes;j++) //Nos desplazamos por toda la estructura "viajes".
            {
                if(strcmp(pasos[i].id_viaje,viaje[j].id_viaje)==0) //Si la id de viaje en los pasos coincide con la id de viaje.
                {
                    if(strcmp(fecha,viaje[j].f_inic)==0) //Comprobamos que la fecha introducida es igual a la fecha del viaje.
                    {
                        if(strcmp(viaje[j].estado,"abierto")==0||strcmp(viaje[j].estado,"iniciado")==0) //Si el viaje est� abierto o iniciado.
                        {
                            *vec=(int *)realloc(*vec,((*x)+1)*sizeof(int)); //Asignamos un espacio de memoria m�s, para introducir el viaje detectado.
                            if ((*vec)==NULL)
                            {
                                printf("Error al asignar memoria.\n");
                                exit(1);
                            }
                            (*vec)[*x]=j; //Se introduce la posici�n del viaje encontrado en la estructura en el vector de enteros din�mico.
                            (*x)++; //Vamos aumentando en 1, la cantidad de viajes que tiene disponible el usuario para la fecha introducida,
                            //que al mismo tiempo servir� para acceder a los dos vectores de enteros.
                        }
                    }
                }
            }
        }
    }
}

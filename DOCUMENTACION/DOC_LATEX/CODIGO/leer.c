#include "leer.h"

//Cabecera: void leer(Estr_Usuario **, int *, Estr_Vehiculo **, int *, Estr_Viaje **, int *, Estr_Pasos **, int *, Estr_Reservas **, int *, Estr_Rutas ***, int *, int *, Estr_Localidad **, int *);
//Precondicion: Tener todas las estructuras inicializadas, con sus respectivos contadores. Ademas todas tienen que pasarse por puntero, para introducir valores en las mismas.
//Postcondicion: Leer todos los ficheros, e introducir la informacion en su estructura, con sus contadores.

void leer(Estr_Usuario **usuario, int *numUsuarios, Estr_Vehiculo **vehiculo, int *numVehiculos, Estr_Viaje **viaje, int *numViajes, Estr_Pasos **pasos, int *numPasos, Estr_Reservas **reservas, int *numReservas, Estr_Rutas ***ruta, int *numRutas, int *numRutas2, Estr_Localidad **localidad, int *numLocalidades)
{
    leer_usuario(usuario, numUsuarios); //Llama a todas las funciones de leer, cada uno de los ficheros.
    leer_vehiculo(vehiculo, numVehiculos);
    leer_viaje(viaje, numViajes);
    leer_pasos(pasos, numPasos);
    leer_localidad(localidad, numLocalidades);
    leer_ruta(ruta, numRutas, numRutas2);
    leer_reservas(reservas, numReservas);
    system("PAUSE");
}

//Cabecera: void leer_usuario(Estr_Usuario **, int *);
//Precondicion: Tener la estructura inicializada, con su contador.
//Postcondicion: Leer el fichero "usuarios.txt" e introducir la informacion en su estructura, aumentando el contador cada vez que se encuentra uno.

void leer_usuario(Estr_Usuario **usuario, int *i)
{
    FILE *fp;
    char vec[80], *token;
    *i=0;

    fp=fopen("DATA/usuarios.txt", "r"); //Abrimos el fichero en modo lectura.

    (*usuario)=malloc((*i)*sizeof(Estr_Usuario)); //Asignamos un espacio de memoria a la estructura.
    if ((*usuario)==NULL)
    {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero usuarios.txt.\n");
        return;
    }
    else
    {
        while(fgets(vec, 80, fp)) //Obtenemos la primera linea, y la introducimos en "vec".
        {
            if(strcmp(vec,"\n")!=0) //Cuando haya un salto de linea, pasamos a la siguiente.
            {
                *usuario=realloc(*usuario,((*i)+1)*sizeof(Estr_Usuario)); //Vamos ampliando la memoria dinamica de la estructura.
                if (*usuario==NULL)
                {
                    printf("Error al asignar memoria.\n");
                    exit(1);
                }
                token=strtok(vec,"-"); //Leemos "vec", y lo cortamos cuando tenemos "-".
                strcpy((*usuario)[*i].id_usuario,token); //Copiamos lo que hemos "cortado", en la cadena correspondiente de la estructura.
                token=strtok(NULL,"-");
                strcpy((*usuario)[*i].nomb_usuario,token);
                token=strtok(NULL,"-");
                strcpy((*usuario)[*i].localidad,token);
                token=strtok(NULL,"-");
                strcpy((*usuario)[*i].perfil,token);
                token=strtok(NULL,"-");
                strcpy((*usuario)[*i].usuario,token);
                token=strtok(NULL,"\n"); //Vamos leyendo hasta que haya un salto de linea.
                strcpy((*usuario)[*i].contrasena,token);

                (*i)++; //Vamos aumentando el contador, para saber el numero maximo de usuarios que hay en la base de datos.
            }
        }
    }

    fclose(fp);

    printf("Se han cargado %i usuarios.\n", *i);
}

//Cabecera: void leer_vehiculo(Estr_Vehiculo **, int *);
//Precondicion: Tener la estructura inicializada, con su contador.
//Postcondicion: Leer el fichero "vehiculos.txt" e introducir la informacion en su estructura, aumentando el contador cada vez que se encuentra uno.

void leer_vehiculo(Estr_Vehiculo **vehiculo, int *i)
{
    FILE *fp;
    char vec[70], *token;
    *i=0;

    fp=fopen("DATA/vehiculos.txt", "r"); //Abrimos el fichero en modo lectura.

    (*vehiculo)=malloc((*i)*sizeof(Estr_Vehiculo)); //Asignamos un espacio de memoria a la estructura.
    if ((*vehiculo)==NULL)
    {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else
    {
        while(fgets(vec, 70, fp)) //Obtenemos la primera linea, y la introducimos en "vec".
        {
            if(strcmp(vec,"\n")!=0) //Cuando haya un salto de linea, pasamos a la siguiente.
            {
                *vehiculo=realloc(*vehiculo,((*i)+1)*sizeof(Estr_Vehiculo)); //Vamos ampliando la memoria dinamica de la estructura.
                if (*vehiculo==NULL)
                {
                    printf("Error al asignar memoria.\n");
                    exit(1);
                }
                token=strtok(vec,"-"); //Leemos "vec", y lo cortamos cuando tenemos "-".
                strcpy((*vehiculo)[*i].id_mat,token); //Copiamos lo que hemos "cortado", en la cadena correspondiente de la estructura.
                token=strtok(NULL,"-");
                strcpy((*vehiculo)[*i].id_usuario,token);
                token=strtok(NULL,"-");
                strcpy((*vehiculo)[*i].num_plazas,token);
                token=strtok(NULL,"\n"); //Vamos leyendo hasta que haya un salto de linea.
                strcpy((*vehiculo)[*i].desc_veh,token);

                (*i)++; //Vamos aumentando el contador, para saber el numero maximo de vehiculos que hay en la base de datos.
            }
        }
    }

    fclose(fp);

    printf("Se han cargado %i vehiculos.\n", *i);
}

//Cabecera: void leer_viaje(Estr_Viaje **, int *);
//Precondicion: Tener la estructura inicializada, con su contador.
//Postcondicion: Leer el fichero "viajes.txt" e introducir la informacion en su estructura, aumentando el contador cada vez que se encuentra uno.

void leer_viaje(Estr_Viaje **viaje, int *i)
{
    FILE *fp;
    char vec[65], *token;
    *i=0;

    fp=fopen("DATA/viajes.txt", "r"); //Abrimos el fichero en modo lectura.

    (*viaje)=malloc((*i)*sizeof(Estr_Viaje)); //Asignamos un espacio de memoria a la estructura.
    if ((*viaje)==NULL)
    {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero viajes.txt.\n");
        return;
    }
    else
    {
        while(fgets(vec, 65, fp)) //Obtenemos la primera linea, y la introducimos en "vec".
        {
            if(strcmp(vec,"\n")!=0) //Cuando haya un salto de linea, pasamos a la siguiente.
            {
                *viaje=realloc(*viaje,((*i)+1)*sizeof(Estr_Viaje)); //Vamos ampliando la memoria dinamica de la estructura.
                if (*viaje==NULL)
                {
                    printf("Error al asignar memoria.\n");
                    exit(1);
                }
                token=strtok(vec,"-"); //Leemos "vec", y lo cortamos cuando tenemos "-".
                strcpy((*viaje)[*i].id_viaje,token); //Copiamos lo que hemos "cortado", en la cadena correspondiente de la estructura.
                token=strtok(NULL,"-");
                strcpy((*viaje)[*i].id_mat,token);
                token=strtok(NULL,"-");
                strcpy((*viaje)[*i].f_inic,token);
                token=strtok(NULL,"-");
                strcpy((*viaje)[*i].h_inic,token);
                token=strtok(NULL,"-");
                strcpy((*viaje)[*i].h_fin,token);
                token=strtok(NULL,"-");
                strcpy((*viaje)[*i].plazas_libre,token);
                token=strtok(NULL,"-");
                strcpy((*viaje)[*i].ida_vuelta,token);
                token=strtok(NULL,"-");
                strcpy((*viaje)[*i].precio,token);
                token=strtok(NULL,"\n"); //Vamos leyendo hasta que haya un salto de linea.
                strcpy((*viaje)[*i].estado,token);

                (*i)++; //Vamos aumentando el contador, para saber el numero maximo de viajes que hay en la base de datos.
            }
        }
    }

    fclose(fp);

    printf("Se han cargado %i viajes.\n", *i);
}

//Cabecera: void leer_pasos(Estr_Pasos **, int *);
//Precondicion: Tener la estructura inicializada, con su contador.
//Postcondicion: Leer el fichero "pasos.txt" e introducir la informacion en su estructura, aumentando el contador cada vez que se encuentra uno.

void leer_pasos(Estr_Pasos **pasos, int *i)
{
    FILE *fp;
    char vec[35], *token;
    *i=0;

    fp=fopen("DATA/pasos.txt", "r"); //Abrimos el fichero en modo lectura.

    (*pasos)=malloc((*i)*sizeof(Estr_Pasos)); //Asignamos un espacio de memoria a la estructura.
    if ((*pasos)==NULL)
    {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero pasos.txt.\n");
        return;
    }
    else
    {
        while(fgets(vec, 35, fp)) //Obtenemos la primera linea, y la introducimos en "vec".
        {
            if(strcmp(vec,"\n")!=0) //Cuando haya un salto de linea, pasamos a la siguiente.
            {
                *pasos=realloc(*pasos,((*i)+1)*sizeof(Estr_Pasos)); //Vamos ampliando la memoria dinamica de la estructura.
                if (*pasos==NULL)
                {
                    printf("Error al asignar memoria.\n");
                    exit(1);
                }
                token=strtok(vec,"-"); //Leemos "vec", y lo cortamos cuando tenemos "-".
                strcpy((*pasos)[*i].id_viaje,token); //Copiamos lo que hemos "cortado", en la cadena correspondiente de la estructura.
                token=strtok(NULL,"\n"); //Vamos leyendo hasta que haya un salto de linea.
                strcpy((*pasos)[*i].poblacion,token);

                (*i)++; //Vamos aumentando el contador, para saber el numero maximo de pasos que hay en la base de datos.
            }
        }
    }

    fclose(fp);

    printf("Se han cargado %i pasos.\n", *i);
}

//Cabecera: void leer_localidad(Estr_Localidad **, int *);
//Precondicion: Tener la estructura inicializada, con su contador.
//Postcondicion: Leer el fichero "localidades.txt" e introducir la informacion en su estructura, aumentando el contador cada vez que se encuentra uno.

void leer_localidad(Estr_Localidad **localidad, int *i)
{
    FILE *fp;
    char vec[30], *token;
    *i=0;

    fp=fopen("DATA/localidades.txt", "r"); //Abrimos el fichero en modo lectura.

    (*localidad)=malloc((*i)*sizeof(Estr_Localidad)); //Asignamos un espacio de memoria a la estructura.
    if ((*localidad)==NULL)
    {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero localidades.txt.\n");
        return;
    }
    else
    {
        while(fgets(vec, 30, fp)) //Obtenemos la primera linea, y la introducimos en "vec".
        {
            if(strcmp(vec,"\n")!=0) //Cuando haya un salto de linea, pasamos a la siguiente.
            {
                *localidad=realloc(*localidad,((*i)+1)*sizeof(Estr_Localidad)); //Vamos ampliando la memoria dinamica de la estructura.
                if (*localidad==NULL)
                {
                    printf("Error al asignar memoria.\n");
                    exit(1);
                }
                token=strtok(vec,"-"); //Leemos "vec", y lo cortamos cuando tenemos "-".
                strcpy((*localidad)[*i].siglas,token); //Copiamos lo que hemos "cortado", en la cadena correspondiente de la estructura.
                token=strtok(NULL,"\n"); //Vamos leyendo hasta que haya un salto de linea.
                strcpy((*localidad)[*i].localidad,token);

                (*i)++; //Vamos aumentando el contador, para saber el numero maximo de localidades que hay en la base de datos.
            }
        }
    }

    fclose(fp);

    printf("Se han cargado %i localidades.\n", *i);
}

//Cabecera: void leer_ruta(Estr_Rutas ***, int *, int *);
//Precondicion: Tener la estructura inicializada, con sus contadores.
//Postcondicion: Leer el fichero "rutas.txt" e introducir la informacion en su estructura, aumentando el contador
//cada vez que se encuentra una ruta nueva, y otro que nos indique el numero de localidades maximas que hay en todas las rutas.

void leer_ruta(Estr_Rutas ***ruta, int *i, int *j)
{
    FILE *fp;
    char vec[60], *token;
    *i=0, *j=0;

    fp=fopen("DATA/rutas.txt", "r"); //Abrimos el fichero en modo lectura.

    (*ruta)=malloc((*i)*sizeof(Estr_Rutas)); //Asignamos un espacio de memoria a la estructura.
    if ((*ruta)==NULL)
    {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    (*ruta)[*i]=malloc((*i)*sizeof(Estr_Rutas)); //Asignamos un espacio de memoria a la estructura, para hacerla una matriz.
    if((*ruta)[*i]==NULL)
    {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero rutas.txt.\n");
        return;
    }
    else
    {
        while(fgets(vec, 60, fp)) //Obtenemos la primera linea, y la introducimos en "vec".
        {
            if(strcmp(vec,"\n")!=0) //Cuando haya un salto de linea, pasamos a la siguiente.
            {
                *ruta=(Estr_Rutas **)realloc(*ruta,(*i+1)*sizeof(Estr_Rutas *)); //Vamos ampliando la memoria dinamica de la estructura.
                if (*ruta==NULL)
                {
                    printf("Error al asignar memoria.\n");
                    exit(1);
                }
                (*ruta)[*i]=NULL;

                int k=0;
                token=strtok(vec, "-"); //Leemos "vec", y lo cortamos cuando tenemos "-".
                while(token!=NULL) //Hasta que la cadena que recibe el corte, no es nula, no saltamos de linea.
                {
                    (*ruta)[*i]=(Estr_Rutas *)realloc((*ruta)[*i],(k+1)*sizeof(Estr_Rutas)); //Vamos ampliando la memoria dinamica de la estructura, para anadir mas elementos en una fila.
                    if((*ruta)[*i]==NULL)
                    {
                        printf("Error al asignar memoria.\n");
                        exit(1);
                    }
                    strcpy((*ruta)[*i][k].localidad, token); //Copiamos en la posicion de la matriz, la localidad que hemos cortado con strtok.
                    k++;
                    token=strtok(NULL, "-"); //Vamos leyendo hasta que en token no haya nada.
                }
                if((*j)<k) //Comparamos si el numero de localidades en la fila leida, es mayor a j.
                {
                    (*j)=k; //Guardamos la cantidad maxima de localidades que hay en una misma ruta/linea.
                }
                (*i)++; //Aumentamos en 1, para agregar una fila mas.


            }
        }
    }

    fclose(fp);

    printf("Se han cargado %i rutas, con %i ciudades como maximo.\n", *i, *j);
}

//Cabecera: void leer_reservas(Estr_Reservas **, int *);
//Precondicion: Tener la estructura inicializada, con su contador.
//Postcondicion: Leer el fichero "reservas.txt" e introducir la informacion en su estructura, aumentando el contador cada vez que se encuentra uno.

void leer_reservas(Estr_Reservas **reservas, int *i)
{
    FILE *fp;
    char vec[30], *token;
    *i=0;

    fp=fopen("DATA/reservas.txt", "r"); //Abrimos el fichero en modo lectura.

    (*reservas)=malloc((*i)*sizeof(Estr_Reservas)); //Asignamos un espacio de memoria a la estructura.
    if ((*reservas)==NULL)
    {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero reservas.txt.\n");
        return;
    }
    else
    {
        while(fgets(vec, 30, fp)) //Obtenemos la primera linea, y la introducimos en "vec".
        {
            if(strcmp(vec,"\n")!=0) //Cuando haya un salto de linea, pasamos a la siguiente.
            {
                *reservas=realloc(*reservas,((*i)+1)*sizeof(Estr_Reservas)); //Vamos ampliando la memoria dinamica de la estructura.
                if (*reservas==NULL)
                {
                    printf("Error al asignar memoria.\n");
                    exit(1);
                }
                token=strtok(vec,"-"); //Leemos "vec", y lo cortamos cuando tenemos "-".
                strcpy((*reservas)[*i].id_viaje,token); //Copiamos lo que hemos "cortado", en la cadena correspondiente de la estructura.
                token=strtok(NULL,"\n"); //Vamos leyendo hasta que haya un salto de linea.
                strcpy((*reservas)[*i].id_usuario,token);

                (*i)++; //Vamos aumentando el contador, para saber el numero maximo de reservas que hay en la base de datos.
            }
        }
    }

    fclose(fp);

    printf("Se han cargado %i reservas.\n", *i);
}


#include "leer.h"

void leer()
{
    leer_usuario(&usuario, &numUsuarios);
    leer_vehiculo(&vehiculo, &numVehiculos);
    leer_viaje(&viaje, &numViajes);
    leer_pasos(&pasos, &numPasos);
    leer_localidad(&localidad, &numLocalidades);
    leer_ruta(&ruta, &numRutas, &numRutas2);
    leer_reservas(&reservas, &numReservas);
    system("PAUSE");
}

void leer_usuario(Estr_Usuario **usuario, int *i)
{
    FILE *fp;
    char vec[80], *token;
    *i=0;

    fp=fopen("usuarios.txt", "r");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero usuarios.txt.\n");
        return;
    }
    else
    {
        while(fgets(vec, 80, fp))
        {
            if(strcmp(vec,"\n")!=0)
            {
                *usuario=realloc(*usuario,((*i)+1)*sizeof(Estr_Usuario));
                if (*usuario==NULL)
                {
                    printf("Error al asignar memoria.\n");
                    exit(1);
                }
                token=strtok(vec,"-");
                strcpy((*usuario)[*i].id_usuario,token);
                token=strtok(NULL,"-");
                strcpy((*usuario)[*i].nomb_usuario,token);
                token=strtok(NULL,"-");
                strcpy((*usuario)[*i].localidad,token);
                token=strtok(NULL,"-");
                strcpy((*usuario)[*i].perfil,token);
                token=strtok(NULL,"-");
                strcpy((*usuario)[*i].usuario,token);
                token=strtok(NULL,"\n");
                strcpy((*usuario)[*i].contrasena,token);

                (*i)++;
            }
        }
    }

    fclose(fp);

    printf("Se han cargado %i usuarios.\n", *i);

    return;
}

void leer_vehiculo(Estr_Vehiculo **vehiculo, int *i)
{
    FILE *fp;
    char vec[70], *token;
    *i=0;

    fp=fopen("vehiculos.txt", "r");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else
    {
        while(fgets(vec, 70, fp))
        {
            if(strcmp(vec,"\n")!=0)
            {
                *vehiculo=realloc(*vehiculo,((*i)+1)*sizeof(Estr_Vehiculo));
                if (*vehiculo==NULL)
                {
                    printf("Error al asignar memoria.\n");
                    exit(1);
                }
                token=strtok(vec,"-");
                strcpy((*vehiculo)[*i].id_mat,token);
                token=strtok(NULL,"-");
                strcpy((*vehiculo)[*i].id_usuario,token);
                token=strtok(NULL,"-");
                strcpy((*vehiculo)[*i].num_plazas,token);
                token=strtok(NULL,"\n");
                strcpy((*vehiculo)[*i].desc_veh,token);

                (*i)++;
            }
        }
    }

    fclose(fp);

    printf("Se han cargado %i vehiculos.\n", *i);

    return;
}

void leer_viaje(Estr_Viaje **viaje, int *i)
{
    FILE *fp;
    char vec[65], *token;
    *i=0;

    fp=fopen("viajes.txt", "r");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero viajes.txt.\n");
        return;
    }
    else
    {
        while(fgets(vec, 65, fp))
        {
            if(strcmp(vec,"\n")!=0)
            {
                *viaje=realloc(*viaje,((*i)+1)*sizeof(Estr_Viaje));
                if (*viaje==NULL)
                {
                    printf("Error al asignar memoria.\n");
                    exit(1);
                }
                token=strtok(vec,"-");
                strcpy((*viaje)[*i].id_viaje,token);
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
                token=strtok(NULL,"\n");
                strcpy((*viaje)[*i].estado,token);

                (*i)++;
            }
        }
    }

    fclose(fp);

    printf("Se han cargado %i viajes.\n", *i);

    return;
}

void leer_pasos(Estr_Pasos **pasos, int *i)
{
    FILE *fp;
    char vec[35], *token;
    *i=0;

    fp=fopen("pasos.txt", "r");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero pasos.txt.\n");
        return;
    }
    else
    {
        while(fgets(vec, 35, fp))
        {
            if(strcmp(vec,"\n")!=0)
            {
                *pasos=realloc(*pasos,((*i)+1)*sizeof(Estr_Pasos));
                if (*pasos==NULL)
                {
                    printf("Error al asignar memoria.\n");
                    exit(1);
                }
                token=strtok(vec,"-");
                strcpy((*pasos)[*i].id_viaje,token);
                token=strtok(NULL,"\n");
                strcpy((*pasos)[*i].poblacion,token);

                (*i)++;
            }
        }
    }

    fclose(fp);

    printf("Se han cargado %i pasos.\n", *i);

    return;
}

void leer_localidad(Estr_Localidad **localidad, int *i)
{
    FILE *fp;
    char vec[30], *token;
    *i=0;

    fp=fopen("localidades.txt", "r");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero localidades.txt.\n");
        return;
    }
    else
    {
        while(fgets(vec, 30, fp))
        {
            if(strcmp(vec,"\n")!=0)
            {
                *localidad=realloc(*localidad,((*i)+1)*sizeof(Estr_Localidad));
                if (*localidad==NULL)
                {
                    printf("Error al asignar memoria.\n");
                    exit(1);
                }
                token=strtok(vec,"-");
                strcpy((*localidad)[*i].siglas,token);
                token=strtok(NULL,"\n");
                strcpy((*localidad)[*i].localidad,token);

                (*i)++;
            }
        }
    }

    fclose(fp);

    printf("Se han cargado %i localidades.\n", *i);

    return;
}

void leer_ruta(Estr_Rutas ***ruta, int *i, int *j)
{
    FILE *fp;
    char vec[60], *token;
    *i=0, *j=0;

    fp=fopen("rutas.txt", "r");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero rutas.txt.\n");
        return;
    }
    else
    {
        while(fgets(vec, 60, fp))
        {
            if(strcmp(vec,"\n")!=0)
            {
                *ruta=(Estr_Rutas **)realloc(*ruta,(*i+1)*sizeof(Estr_Rutas *));
                if (*ruta==NULL)
                {
                    printf("Error al asignar memoria.\n");
                    exit(1);
                }
                (*ruta)[*i]=NULL;

                int k=0;
                token=strtok(vec, "-");
                while(token!=NULL)
                {
                    (*ruta)[*i]=(Estr_Rutas *)realloc((*ruta)[*i],(k+1)*sizeof(Estr_Rutas));
                    if((*ruta)[*i]==NULL)
                    {
                        printf("Error al asignar memoria.\n");
                        exit(1);
                    }
                    strcpy((*ruta)[*i][k].localidad, token);
                    k++;
                    token=strtok(NULL, "-");
                }
                if((*j)<k)
                {
                    (*j)=k;
                }
                (*i)++;


            }
        }
    }

    fclose(fp);

    printf("Se han cargado %i rutas, con %i ciudades como máximo.\n", *i, *j);

    return;
}

void leer_reservas(Estr_Reservas **reservas, int *i)
{
    FILE *fp;
    char vec[30], *token;
    *i=0;

    fp=fopen("reservas.txt", "r");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero reservas.txt.\n");
        return;
    }
    else
    {
        while(fgets(vec, 30, fp))
        {
            if(strcmp(vec,"\n")!=0)
            {
                *reservas=realloc(*reservas,((*i)+1)*sizeof(Estr_Reservas));
                if (*reservas==NULL)
                {
                    printf("Error al asignar memoria.\n");
                    exit(1);
                }
                token=strtok(vec,"-");
                strcpy((*reservas)[*i].id_viaje,token);
                token=strtok(NULL,"\n");
                strcpy((*reservas)[*i].id_usuario,token);

                (*i)++;
            }
        }
    }

    fclose(fp);

    printf("Se han cargado %i reservas.\n", *i);

    return;
}


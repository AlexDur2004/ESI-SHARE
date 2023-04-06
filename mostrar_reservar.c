#include "mostrar_reservar.h"

void mostrar_reservar(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, int num_user)
{
    int *vec=NULL, x, loc, i,seleccion=0,conf1=0,conf=0,plazas;
    char fecha[11],num_plazas[2];

    do
    {
        leer_dia(fecha);
        encontrarViajesReservas(usuario, viaje, numViajes, pasos, numPasos, num_user, fecha, &vec, &x, &loc);

        if(loc==0)
        {
            printf("No hay viajes disponibles en tu localidad (%s), para fechas futuras.\n", usuario[num_user].localidad);
            system("PAUSE");
            conf=1;
        }
        else if(vec==NULL)
        {
            printf("No hay viajes disponibles para esa fecha (%s), prueba con otra fecha.\n", fecha);
            do
            {
                printf("Desea reservar un viaje para otra fecha:\n(1)SI\n(2)NO\n");
                scanf("%i",&i);
                switch(i)
                {
                    case 1:
                        conf=0;
                        break;
                    case 2:
                        conf=1;
                        break;
                }
            }while(i!=1 && i!=2);
        }
        else
        {
            do
            {
                system("cls");
                printf("Viajes disponibles para el %s\n",fecha);
                for(i=0;i<x;i++)
                {
                    color(15, 0);
                    printf("VIAJE %i:\n",i+1);
                    color(0, 3);
                    printf("ID del viaje: ");
                    color(0, 15);
                    printf("%s\n", viaje[vec[i]].id_viaje);
                    color(0, 3);
                    printf("Hora de partida: ");
                    color(0, 15);
                    printf("%s\n", viaje[vec[i]].h_inic);
                    color(0, 3);
                    printf("Hora de llegada: ");
                    color(0, 15);
                    printf("%s\n", viaje[vec[i]].h_fin);
                    color(0, 3);
                    printf("Tipo: ");
                    color(0, 15);
                    printf("%s\n", viaje[vec[i]].ida_vuelta);
                    color(0, 3);
                    printf("Estado: ");
                    color(0, 15);
                    printf("%s\n", viaje[vec[i]].estado);
                    color(0, 3);
                    printf("Nº de plazas: ");
                    color(0, 15);
                    printf("%s\n", viaje[vec[i]].plazas_libre);
                    color(0, 3);
                    printf("Precio: ");
                    color(0, 15);
                    printf("%s euros\n\n", viaje[vec[i]].precio);
                }
                printf("Elija un viaje:\n");
                scanf("%i",&seleccion);

            }while(seleccion>x || seleccion<1);

            verificar_reserva(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, reservas, numReservas, vec, seleccion-1, &conf1, num_user);

            if(conf1==0)
            {
                mostrar_poblaciones(viaje, numViajes, pasos, numPasos, vec, seleccion-1, &conf);

                if(conf==2)
                {
                    plazas=atoi(viaje[vec[seleccion-1]].plazas_libre);
                    plazas--;
                    sprintf(num_plazas,"%01d",plazas);
                    strcpy(viaje[vec[seleccion-1]].plazas_libre,num_plazas);
                    if(plazas==0)
                    {
                        strcpy(viaje[vec[seleccion-1]].estado,"cerrado");
                    }
                    actualizarFichero(viaje, numViajes);
                    guardarPasajero(usuario, viaje, reservas, numReservas, vec, seleccion-1, num_user);
                }
            }
       }
   }while(conf==0);
}

void mostrar_poblaciones(Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, int *vec,int reserva, int *conf)
{
    int i,opc;

    for(i=0;i<numPasos;i++)
    {
        if(strcmp(viaje[vec[reserva]].id_viaje,pasos[i].id_viaje)==0)
        {
            printf("%s\n",pasos[i].poblacion);
        }
    }

    do{
        printf("Desea reservar este viaje :\n(1)SI (2)NO\n");
        scanf("%i",&opc);
        switch (opc)
        {
            case 1:
                (*conf)=2;
                break;
            case 2:
                (*conf)=0;
                break;
            default: printf("Introduzca la opcion correcta.\n");
        }
    }while(opc!=1 && opc!=2);
}

void actualizarFichero(Estr_Viaje *viaje, int numViajes)
{
    int i;

    FILE *fp;
    fp=fopen("DATA/viajes_replace.txt","w+");
    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero");
    }
    else
    {

        for(i=0;i<numViajes;i++)
        {
            fprintf(fp,"%s-%s-%s-%s-%s-%s-%s-%s-%s\n",viaje[i].id_viaje,viaje[i].id_mat,viaje[i].f_inic,viaje[i].h_inic,viaje[i].h_fin,viaje[i].plazas_libre,viaje[i].ida_vuelta,viaje[i].precio,viaje[i].estado);
        }
    }

    fclose(fp);

    remove("DATA/viajes.txt");
    rename("DATA/viajes_replace.txt","DATA/viajes.txt");
    leer_viaje(&viaje,&numViajes);
}

void guardarPasajero(Estr_Usuario *usuario, Estr_Viaje *viaje, Estr_Reservas *reservas, int numReservas, int *vec, int reserva, int num_user)
{
        // crear nuevo fichero que guarde para guardar la reserva
    FILE *fp;

    fp=fopen("DATA/reservas.txt","a+");
    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero reservas.txt.\n");
        return;
    }
    else
    {
        fprintf(fp,"%s-%s\n",viaje[vec[reserva]].id_viaje,usuario[num_user].id_usuario);
    }
    fclose(fp);
    leer_reservas(&reservas,&numReservas); // escribe en la estructura reservas la id del viaje y del usuario
}

void cancelarReserva(Estr_Usuario *usuario, Estr_Viaje *viaje, int numViajes, Estr_Reservas *reservas, int numReservas, int num_user)
{
    int *vec=NULL, *vec_viaje=NULL, x, j=0, i, sel, cont=0, plazas=0;

    encontrarReservas(usuario, viaje, numViajes, reservas, numReservas, num_user, &vec, &vec_viaje, &x);

    if(vec!=NULL){
        do{
            printf("LISTADO DE SUS VIAJES:\n");
            for(i=0;i<x;i++)
            {
                color(15, 0);
                printf("VIAJE %i:\n",i+1);
                color(0, 3);
                printf("ID del viaje: ");
                color(0, 15);
                printf("%s\n", viaje[vec[i]].id_viaje);
                color(0, 3);
                printf("Fecha de partida: ");
                color(0, 15);
                printf("%s\n", viaje[vec[i]].f_inic);
                color(0, 3);
                printf("Hora de partida: ");
                color(0, 15);
                printf("%s\n", viaje[vec[i]].h_inic);
                color(0, 3);
                printf("Hora de llegada: ");
                color(0, 15);
                printf("%s\n", viaje[vec[i]].h_fin);
                color(0, 3);
                printf("Tipo: ");
                color(0, 15);
                printf("%s\n", viaje[vec[i]].ida_vuelta);
                color(0, 3);
                printf("Precio: ");
                color(0, 15);
                printf("%s euros\n\n", viaje[vec[i]].precio);
            }

            printf("Seleccione el viaje que desea cancelar:\n");
            scanf("%i",&sel);
            system("cls");
        }while(sel>x || sel<1);

        eliminarReservas(reservas, numReservas, reservas[vec[sel-1]].id_viaje);
        leer_reservas(&reservas,&numReservas);
        plazas=atoi(viaje[vec_viaje[sel-1]].plazas_libre);
        plazas++;
        sprintf(viaje[vec_viaje[sel-1]].plazas_libre,"%01d",plazas);
        actualizarFichero(viaje, numViajes);
    }
    else
    {
        printf("No tiene viajes reservados\n");
        system("PAUSE");
    }
}

void verificar_reserva(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Reservas *reservas, int numReservas, int *vec,int reserva,int *n,int num_user)
{
    int i,j;
    for(i=0;i<numVehiculos && *n==0;i++)
    {
        if(strcmp(viaje[vec[reserva]].id_mat,vehiculo[i].id_mat)==0)
        {
            if(strcmp(vehiculo[i].id_usuario,usuario[num_user].id_usuario)==0)
            {
                printf("Error/No puede reservar un viaje creado por usted\n");
                *n=1;
            }
        }
    }
    if((*n)!=1)
    {
       for(i=0;i<numReservas;i++)
       {
        if(strcmp(reservas[i].id_usuario,usuario[num_user].id_usuario)==0)
        {
            *n=1;
            printf("Error/No puede reservar un viaje ya reservado previamente\n");
        }
    }

    }
    system("pause");
}

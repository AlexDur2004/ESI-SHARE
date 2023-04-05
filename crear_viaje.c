#include "crear_viaje.h"

void altaViaje(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int num_usuario, int num)
{
    FILE *fv;
    int n=1, i, idmax=0, num_viaje, breakp=0, enc=0, precio=0, rp;
    char viaje_id[7], id_vehiculo[8], fecha[11], hora_inic[6], hora_fin[6], plazas[2], idavuelta[7], coste[5], estado[8];

    fv=fopen("viajes.txt","a+");
    do{
        rp=0;
        elegir_coche(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, num_usuario, id_vehiculo, num);
        asignar_plazas(vehiculo, numVehiculos, id_vehiculo, plazas);

        leerFecha(fecha, hora_inic, hora_fin);

        ida_vuelta(idavuelta);

        while(precio<=0)
        {
            system("cls");
            printf("Establezca el coste de su viaje:\n");
            scanf("%i", &precio);
        }

        sprintf(coste, "%i", precio);

        strcpy(estado, "abierto");

        leer_viaje(&viaje,&numViajes);

        if(fv==NULL)
        {
            printf("No se ha podido abrir el fichero viajes.txt.\n");
            return;
        }
        else
        {
            while(breakp==0)
            {
                for(i=0;i<numViajes && enc==0;i++)
                {
                    idmax=atoi(viaje[i].id_viaje);
                    if(n==idmax)
                        enc=1;
                }
                if(enc==1)
                {
                    n++;
                    enc=0;
                }
                else
                {
                    breakp=1;
                }
            }

            snprintf(viaje_id, sizeof(viaje_id), "%06d", n); //pasa la id nueva a un vector limitado por 7 espacios.

            verificar_viaje(viaje, numViajes, viaje_id, id_vehiculo, fecha, hora_inic, hora_fin, &rp);
            if(rp==0)
            {
                fprintf(fv, "%s-%s-%s-%s-%s-%s-%s-%s-%s\n", viaje_id, id_vehiculo, fecha, hora_inic, hora_fin, plazas, idavuelta, coste, estado);
                fclose(fv);
                leer_viaje(&viaje, &numViajes);
                buscadorRutas(ruta, numRutas, numRutas2, localidad, numLocalidades, pasos, numPasos, viaje_id);
            }
            else
            {
                printf("ERROR/ No se pueden asignar dos viajes con el mismo vehículo en la misma fecha, a no ser que el viaje esté finalizado o anulado.\n");
                system("PAUSE");
            }
        }
    }while(rp==1);
    fclose(fv);
}

void elegir_coche(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int num_usuario, char *id_vehiculo, int num) //0 para usuario, y 1 para admin
{
    int i,*vec_vehiculo=NULL, coches, encontrado=0, opc=0, breakp=0;

    encontrarVehiculos(usuario, vehiculo, numVehiculos, &vec_vehiculo, &coches, num_usuario);

    if(coches==0)
    {
        if(num==0)
        {
            do
            {
                system("cls");
                printf("No tiene ningun vehiculo registrado.\n\n");
                printf("¿Qué quiere hacer?\n");
                printf("(1)Registrar un vehiculo.\n");
                printf("(2)Volver al menu.\n");
                scanf("%d",&opc);
                switch(opc)
                {
                    case 1:
                        breakp=1;
                        altaVehiculo(usuario, vehiculo, numVehiculos, num_usuario);
                        menuConductorViajes(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, num_usuario);
                        break;
                    case 2:
                        breakp=1;
                        menuConductorViajes(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, num_usuario);
                        break;
                }
            }while(breakp==0);
        }
        if(num==1)
        {
            do
            {
                system("cls");
                printf("El usuario %s, con ID %s no tiene ningun vehiculo registrado.\n\n", usuario[num_usuario].nomb_usuario, usuario[num_usuario].id_usuario);
                printf("¿Qué quiere hacer?\n");
                printf("(1)Registrar un vehiculo.\n");
                printf("(2)Volver al menu.\n");
                scanf("%d",&opc);
                switch(opc)
                {
                    case 1:
                        breakp=1;
                        altaVehiculo(usuario, vehiculo, numVehiculos, num_usuario);
                        menuAdminViajes(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, num_usuario);
                        break;
                    case 2:
                        breakp=1;
                        menuAdminViajes(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, num_usuario);
                        break;
                }
            }while(breakp==0);
        }
    }

    do
    {
        system("cls");
        printf("Introduzca sus datos para completar el registro del viaje:\n");
        printf("Elija el vehiculo que desea usar:\n");

        for(i=0;i<coches;i++)
        {
            printf("%s-%s-%s\n", vehiculo[vec_vehiculo[i]].id_mat,vehiculo[vec_vehiculo[i]].num_plazas,vehiculo[vec_vehiculo[i]].desc_veh);
        }

        printf("Introduzca la matrícula del vehiculo que desea usar para el viaje:\n");
        preguntar_veh(vehiculo, numVehiculos, id_vehiculo,&encontrado);

    }while(encontrado==0);
}

void asignar_plazas(Estr_Vehiculo *vehiculo, int numVehiculos, char *id_vehiculo,char *plazas)
{
    int i,breakp=0;

    for(i=0;i<numVehiculos&&breakp==0;i++)
    {
        if(strcmp(vehiculo[i].id_mat,id_vehiculo)==0)
        {
            breakp=1;
            strcpy(plazas,vehiculo[i].num_plazas);
        }
    }
}

void ida_vuelta(char *idavuelta)
{
    int opc=0, breakp=0;

    do
    {
        system("cls");
        printf("Seleccione el tipo de viaje que quiere:\n");
        printf("(1)Ida.\n");
        printf("(2)Vuelta.\n");
        fflush(stdin);
        scanf("%1i",&opc);
        switch(opc)
        {
            case 1:
                breakp=1;
                strcpy(idavuelta,"ida");
                break;
            case 2:
                breakp=1;
                strcpy(idavuelta,"vuelta");
                break;
        }
    }while(breakp==0);
}

void finalizar_viaje(Estr_Usuario *usuario, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, int num_user)
{
    int*vec=NULL,x=0,*vec_viaje=NULL,max_viaje=0,i=0,j;

    encontrarVehiculos(usuario, vehiculo, numVehiculos, &vec, &x, num_user);
    if(vec!=NULL)
    {
        for(j=0;j<x;j++)
        {
            encontrarViajes(usuario, vehiculo, numVehiculos, viaje, numViajes, vehiculo[vec[j]].id_mat,&vec_viaje,&max_viaje,1);
        }
        if(vec_viaje!=NULL){
            printf("LISTADO DE SUS VIAJES:\n");
            for(j=0;j<max_viaje;j++)
            {
                printf("(%i)%s-%s-%s-%s-%s-%s-%s-%s-%s\n",j+1,viaje[vec_viaje[j]].id_viaje,viaje[vec_viaje[j]].id_mat,viaje[vec_viaje[j]].f_inic,viaje[vec_viaje[j]].h_inic,viaje[vec_viaje[j]].h_fin,viaje[vec_viaje[j]].plazas_libre,viaje[vec_viaje[j]].ida_vuelta,viaje[vec_viaje[j]].precio,viaje[vec_viaje[j]].estado);
            }

            do{
                printf("Seleccione el viaje que desea finalizar:\n");
                scanf("%i",&i);
            }while(i>max_viaje||i<0);

            system("cls");
            if(strcmp(viaje[vec_viaje[i-1]].estado, "abierto")==0)
            {
                strcpy(viaje[vec_viaje[i-1]].estado, "anulado");
                printf("El viaje ha sido anulado\n");
            }
            else
            {
                strcpy(viaje[vec_viaje[i-1]].estado, "finalizado");
                printf("El viaje ha sido finalizado\n");
            }
            system("PAUSE");
            actualizar(viaje, numViajes);
            eliminarPasos(pasos, numPasos, reservas, numReservas, viaje[vec_viaje[i-1]].id_viaje);
            eliminarReservas(reservas, numReservas, viaje[vec_viaje[i-1]].id_viaje);
        }
        else
        {
            system("cls");
            printf("No tiene viajes registrados\n");
            system("PAUSE");
        }
    }
    else
    {
        system("cls");
        printf("No tiene coches registrados\n");
        system("PAUSE");
    }
}

void actualizar(Estr_Viaje *viaje, int numViajes){
    int counter=0;

    FILE *fp;
    fp=fopen("viajes_replace.txt","w+");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero");
    }
    else
    {

        for(counter=0;counter<numViajes;counter++)
        {
            fprintf(fp , "%s-%s-%s-%s-%s-%s-%s-%s-%s\n" ,viaje[counter].id_viaje,viaje[counter].id_mat,viaje[counter].f_inic,viaje[counter].h_inic,viaje[counter].h_fin,viaje[counter].plazas_libre,viaje[counter].ida_vuelta,viaje[counter].precio,viaje[counter].estado);
        }
    }

    fclose(fp);

    remove("viajes.txt");
    rename("viajes_replace.txt","viajes.txt");
}

void verificar_viaje(Estr_Viaje *viaje, int numViajes, char *id, char *mat, char *fecha, char *hor_i,char *hor_f,int *rp)
{
    int i,brkp=0;

    for(i=0;i<numViajes&&brkp==0;i++)
    {
        if(strcmp(mat,viaje[i].id_mat)==0)
        {
            if(strcmp(fecha,viaje[i].f_inic)==0)
            {
                if(strcmp(viaje[i].estado,"finalizado")!=0 && strcmp(viaje[i].estado,"anulado")!=0)
                {
                    (*rp)=1;
                    brkp=1;
                }
            }
        }
    }
}

#include "crear_viaje.h"

void altaViaje(int num_usuario, int num)
{
    FILE *fv;
    int n=1, i, idmax=0, num_viaje, breakp=0, enc=0, precio=0;
    char viaje_id[7], id_vehiculo[8], fecha[11], hora_inic[6], hora_fin[6], plazas[2], idavuelta[7], coste[5], estado[8];

    fv=fopen("viajes.txt","a+");

    elegir_coche(num_usuario, id_vehiculo, num);
    asignar_plazas(id_vehiculo, plazas);

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

        fprintf(fv, "%s-%s-%s-%s-%s-%s-%s-%s-%s\n", viaje_id, id_vehiculo, fecha, hora_inic, hora_fin, plazas, idavuelta, coste, estado);

        buscadorRutas(viaje_id);
    }

    fclose(fv);

    leer_viaje(&viaje, &numViajes);
}

void elegir_coche(int num_usuario, char *id_vehiculo, int num) //0 para usuario, y 1 para admin
{
        int i,*vec_vehiculo=NULL, coches, encontrado=0, opc=0, breakp=0;

        encontrarVehiculos(&vec_vehiculo, &coches, num_usuario);

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
                            altaVehiculo(num_usuario);
                            menuConductorViajes(num_usuario);
                            break;
                        case 2:
                            breakp=1;
                            menuConductorViajes(num_usuario);
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
                            altaVehiculo(num_usuario);
                            menuAdminViajes();
                            break;
                        case 2:
                            breakp=1;
                            menuAdminViajes();
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
            preguntar_veh(id_vehiculo,&encontrado);

        }while(encontrado==0);
}

void asignar_plazas(char *id_vehiculo,char *plazas)
{
    int i,breakp=0;

    for(i=0;i<numVehiculos && breakp==0;i++)
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

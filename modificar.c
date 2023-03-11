#include "modificar.h"

void modificarVehiculo(int i)
{
    FILE *fp;
    int n=0, x=0, h=0, m=0, opc=0, k=0, opc2=0, *vec=NULL, encontrado=0;
    char mat[8], plazas[2], descrip[51];

    fp=fopen("vehiculos.txt","w+");

    if(fp==NULL) {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else {
        encontrar(&vec, &x, i);

        printf("¿Qué vehículo quiere modificar?\n");

        for(m=0; m<x; m++)
        {
            printf("(%i)%s-%s-%s\n", m+1, vehiculo[vec[m]].id_mat, vehiculo[vec[m]].num_plazas, vehiculo[vec[m]].desc_veh);
        }
        x++;
        printf("(%i)Guardar y salir.\n", x);
        printf("Ingrese el número correspondiente al vehículo que desea modificar: ");
        fflush(stdin);
        scanf("%d", &opc);

        if((opc>=1&&opc<=x)&&opc!=x) {
            h=opc-1;
            do {
                printf("¿Qué desea modificar?\n");
                printf("(1)Matricula.\n");
                printf("(2)Numero de plazas.\n");
                printf("(3)Descripcion.\n");
                printf("(4)TODO.\n");
                scanf("%d", &opc2);
                switch(opc2)
                {
                    case 1:
                        printf("Matrícula del vehículo (Máximo de 7 caracteres):\n");
                        printf("Matrícula actual: %s\n", vehiculo[vec[h]].id_mat);
                        fflush(stdin);
                        fgets(mat, 8, stdin);

                        for(k=0; k<numVehiculos&&encontrado==0; k++)
                        {
                            if(strcmp(mat, vehiculo[k].id_mat)==0)
                            {
                                encontrado=1;
                            }
                        }
                        if(encontrado==0)
                        {
                            strcpy(vehiculo[vec[h]].id_mat, mat);
                            do{
                                fprintf(fp, "%s-%s-%s-%s\n", vehiculo[n].id_mat, vehiculo[n].id_usuario, vehiculo[n].num_plazas, vehiculo[n].desc_veh);
                                n++;
                            }while(n<numVehiculos-1);
                            fprintf(fp, "%s-%s-%s-%s", vehiculo[n].id_mat, vehiculo[n].id_usuario, vehiculo[n].num_plazas, vehiculo[n].desc_veh);
                            numVehiculos++;

                            printf("La matrícula del vehículo se ha actualizado correctamente.\n");
                            system("PAUSE");
                        }
                        else
                        {
                            printf("La matrícula introducida ya existe en otro vehículo.\n");
                            system("PAUSE");
                        }
                        break;
                    case 2:
                        printf("Número de plazas libres (sin contar el conductor):\n");
                        printf("Plazas actuales: %s\n", vehiculo[vec[h]].num_plazas);
                        fflush(stdin);
                        scanf("%1s", plazas);

                        strcpy(vehiculo[vec[h]].num_plazas, plazas);
                        do{
                            fprintf(fp, "%s-%s-%s-%s\n", vehiculo[n].id_mat, vehiculo[n].id_usuario, vehiculo[n].num_plazas, vehiculo[n].desc_veh);
                            n++;
                        }while(n<numVehiculos-1);
                        fprintf(fp, "%s-%s-%s-%s", vehiculo[n].id_mat, vehiculo[n].id_usuario, vehiculo[n].num_plazas, vehiculo[n].desc_veh);
                        numVehiculos++;

                        printf("El numero de plazas del vehículo se ha actualizado correctamente.\n");
                        system("PAUSE");
                        break;
                    case 3:
                        printf("Descripción del vehículo (Marca, modelo, color, etc) (Máximo de 50 caracteres):\n");
                        printf("Descripción actual: %s\n", vehiculo[vec[h]].desc_veh);
                        fflush(stdin);
                        fgets(descrip, 51, stdin);

                        char *lin=strchr(descrip, '\n');
                        if(strchr(descrip,'\n')!=NULL)
                        {
                            *lin = '\0';
                        }

                        strcpy(vehiculo[vec[h]].desc_veh, descrip);
                        do{
                            fprintf(fp, "%s-%s-%s-%s\n", vehiculo[n].id_mat, vehiculo[n].id_usuario, vehiculo[n].num_plazas, vehiculo[n].desc_veh);
                            n++;
                        }while(n<numVehiculos-1);
                        fprintf(fp, "%s-%s-%s-%s", vehiculo[n].id_mat, vehiculo[n].id_usuario, vehiculo[n].num_plazas, vehiculo[n].desc_veh);
                        numVehiculos++;

                        printf("La descripcion del vehiculo se ha actualizado correctamente.\n");
                        system("PAUSE");
                        break;
                    case 4:
                        printf("Matrícula del vehículo (Máximo de 7 caracteres):\n");
                        printf("Matrícula actual: %s\n", vehiculo[vec[h]].id_mat);
                        fflush(stdin);
                        scanf("%7s", mat);

                        for(k=0; k<numVehiculos&&encontrado==0; k++)
                        {
                            if(strcmp(mat, vehiculo[k].id_mat)==0)
                            {
                                encontrado=1;
                            }
                        }
                        if(encontrado==0)
                        {
                            printf("Número de plazas libres (sin contar el conductor):\n");
                            printf("Plazas actuales: %s\n", vehiculo[vec[h]].num_plazas);
                            fflush(stdin);
                            scanf("%1s", plazas);

                            printf("Descripción del vehículo (Marca, modelo, color, etc) (Máximo de 50 caracteres):\n");
                            printf("Descripción actual: %s\n", vehiculo[vec[h]].desc_veh);
                            fflush(stdin);
                            fgets(descrip, 51, stdin);

                            *lin=strchr(descrip, '\n');
                            if(strchr(descrip,'\n')!=NULL)
                            {
                                *lin = '\0';
                            }

                            strcpy(vehiculo[vec[h]].id_mat, mat);
                            strcpy(vehiculo[vec[h]].num_plazas, plazas);
                            strcpy(vehiculo[vec[h]].desc_veh, descrip);
                            do{
                                fprintf(fp, "%s-%s-%s-%s\n", vehiculo[n].id_mat, vehiculo[n].id_usuario, vehiculo[n].num_plazas, vehiculo[n].desc_veh);
                                n++;
                            }while(n<numVehiculos-1);
                            fprintf(fp, "%s-%s-%s-%s", vehiculo[n].id_mat, vehiculo[n].id_usuario, vehiculo[n].num_plazas, vehiculo[n].desc_veh);
                            numVehiculos++;

                            printf("Se han actualizado todos los datos del vehículo.\n");
                            system("PAUSE");
                        }
                        else
                        {
                            printf("La matrícula introducida ya existe en otro vehículo.\n");
                            system("PAUSE");
                        }
                        break;
                    }
                encontrado=0;
                system("cls");
                break;
            }while(opc2>1&&opc2<4);

        modificarVehiculo(i);
        }
    }
    fclose(fp);
    system("cls");
    leer_vehiculo(&vehiculo, &numVehiculos);

return;
}

void encontrar(int **vec, int *x, int i)
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

#include "eliminar.h"

void eliminarVehiculo(int i)
{
    FILE *fp, *temp;
    int n=0, x=0, h=0, m=0, k=0, opc=0, opc2=0, *vec=NULL, encontrado=0;

    fp=fopen("vehiculos.txt","r+");

    if(fp==NULL) {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else {
        encontrarVehiculos(&vec, &x, i);
        if(x>0){
            printf("�Qu� veh�culo quiere eliminar?\n");

            for(m=0; m<x; m++)
            {
                printf("(%i)%s-%s-%s\n", m+1, vehiculo[vec[m]].id_mat, vehiculo[vec[m]].num_plazas, vehiculo[vec[m]].desc_veh);
            }
            x++;
            printf("(%i)Salir.\n", x);
            printf("Ingrese el n�mero correspondiente al veh�culo que desea eliminar: ");
            fflush(stdin);
            scanf("%d", &opc);
            if(opc==x){
                return;
            }

            if((opc>=1&&opc<x)&&opc!=x){
                h=opc-1;
                do{
                    opc2=0;
                    system("cls");
                    printf("�Seguro que quieres eliminar el vehiculo %s, con matr�cula %s?\n", vehiculo[vec[h]].desc_veh, vehiculo[vec[h]].id_mat);
                    printf("(1)Si\n");
                    printf("(2)No\n");
                    fflush(stdin);
                    scanf("%d", &opc2);

                    if(opc2==1){
                        system("cls");
                        k=1;
                        encontrado=0;
                        for(n=0; (n<numVehiculos)&&(encontrado==0); n++){ //Este bucle se encargar� de suprimir el vehiculo deseado sustituyendo vehiculos.txt por otro.
                            if(strcmp(vehiculo[n].id_usuario, usuario[i].id_usuario)==0){
                                        if(k==opc){
                                            temp=fopen("vehiculos_Temp.txt","w+");
                                            if(temp==NULL) {
                                                printf("No se ha podido abrir el fichero vehiculos_Temp.txt.\n");
                                            }
                                            else{
                                                for(int counter=0; counter<numVehiculos;counter++){
                                                    if(counter!=n){
                                                        fprintf(temp, "%s-%s-%s-%s\n", vehiculo[counter].id_mat, vehiculo[counter].id_usuario, vehiculo[counter].num_plazas, vehiculo[counter].desc_veh);
                                                    }
                                                }
                                            }
                                            fclose(temp);
                                            fclose(fp);
                                            encontrado=1;
                                        }
                                        else{
                                            k++;
                                        }
                                    }
                                }
                                remove("vehiculos.txt");
                                rename("vehiculos_Temp.txt","vehiculos.txt");
                                leer_vehiculo(&vehiculo, &numVehiculos);
                                system("cls");
                                printf("Eliminado con exito\n");
                                system("PAUSE");

                    }
                    else
                    {
                        break;
                    }
                }while((opc2<1)||(opc2>2));
            }
            else {
                system("cls");
                eliminarVehiculo(i);
            }
        }
        else{
            system("cls");
            printf("No posee veh�culos registrados.\n");
            system("PAUSE");
        }
    }
    fclose(fp);
    return;
}

void eliminarAdminVehiculo()
{
    char opc2[4];
    int encontrado=0, i=0;

    system("cls");
    listarVehiculos();
    printf("Escriba la ID del usuario a la que se quiera eliminar un veh�culo\n");
    scanf("%4s",&opc2);
    for(int counter=0;(counter<numUsuarios)&&(encontrado==0);counter++){
        if(strcmp(opc2,usuario[counter].id_usuario)==0){
            encontrado=1;
            i=counter;
            system("cls");
            eliminarVehiculo(i);
        }
    }
    if(encontrado==0){
        system("cls");
        printf("No se ha encontrado ningun usuario con la siguiente ID: %s\n",opc2);
        system("PAUSE");
    }
}

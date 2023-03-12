#include "eliminar.h"

void eliminarVehiculo(int i)
{
    FILE *fp,*temp;
    int n=0, x=0, h=0, m=0, opc=0, k=0, opc2=0, *vec=NULL, encontrado=0;
    char mat[8], plazas[2], descrip[51];

    fp=fopen("vehiculos.txt","r+");

    if(fp==NULL) {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else {
        encontrarVehiculos(&vec, &x, i);

        if(x>0){

            printf("¿Qué vehículo quiere eliminar?\n");

            for(m=0; m<x; m++)
            {
                printf("(%i)%s-%s-%s\n", m+1, vehiculo[vec[m]].id_mat, vehiculo[vec[m]].num_plazas, vehiculo[vec[m]].desc_veh);
            }
            x++;
            printf("(%i)Guardar y salir.\n", x);
            printf("Ingrese el número correspondiente al vehículo que desea eliminar: ");
            fflush(stdin);
            scanf("%d", &opc);

            if(opc!=x){
                do{
                    system("cls");
                    printf("¿Seguro que quieres eliminar el vehiculo seleccionado?\n");
                    printf("(1) Si\n");
                    printf("(2) No\n");
                    scanf("%d", &opc2);

                    switch(opc2){
                            case 1:
                                system("cls");
                                k=1;
                                encontrado=0;
                                for(n=0; (n<numVehiculos)&&(encontrado==0); n++){ //Este bucle se encargará de suprimir el vehiculo deseado sustituyendo vehiculos.txt por otro.
                                    if(strcmp(vehiculo[n].id_usuario, usuario[i].id_usuario)==0){
                                        if(k==opc){
                                            temp=fopen("vehiculos_Temp.txt","w+");
                                            if(fp==NULL) {
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
                                break;
                    }
                }while((opc2<1)||(opc2>2));
            }
        }
        else{
            system("cls");
            printf("No posee vehículos registrados\n");
            system("PAUSE");
        }
    }
    return;
}

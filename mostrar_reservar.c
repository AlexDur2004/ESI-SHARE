#include "mostrar_reservar.h"

void mostrar_reservar(int num_user){
    int *vec=NULL, x, loc, i,seleccion=0,conf1=0,conf=0,plazas;
    char fecha[11],num_plazas[2];


   do{

        leer_dia(fecha);

        encontrarViajesReservas(num_user,fecha,&vec,&x,&loc);

       if(loc==0){
        printf("No hay viajes disponibles en tu locoalidad.\n");
        system("PAUSE");
        conf=1;
       }else if(vec==NULL){
            printf("No hay viajes disponibles para el %s\n",fecha);
            do{
            printf("Desea reservar un viaje para otra fecha:SI(1) NO(2)\n");
            scanf("%i",&i);

              switch(i){
                case 1: conf=0;
                    break;
                case 2: conf=1;
                    break;
                default: printf("Introduzca la opcion correcta\n");
                }
            } while(i!=1 && i!=2);

       }else{
               printf("Viajes disponibles para el %s\n",fecha);
                for(i=0;i<x;i++){
                   printf("(%i)%s-%s-%s-%s-%s-%s-%s\n",i+1,viaje[vec[i]].id_viaje,viaje[vec[i]].h_inic,viaje[vec[i]].h_fin,viaje[vec[i]].ida_vuelta,viaje[vec[i]].estado,viaje[vec[i]].plazas_libre,viaje[vec[i]].precio);
                }
                do{
                printf("Elija un viaje:\n");
                scanf("%i",&seleccion);


                }while(seleccion>x || seleccion<1);

                verificar_reserva(vec,seleccion-1,&conf1,num_user);

                if(conf1==0){
                     mostrar_poblaciones(vec,seleccion-1,&conf);

                    if(conf==2){

                        plazas=atoi(viaje[vec[seleccion-1]].plazas_libre);

                        plazas--;

                        sprintf(num_plazas,"%01d",plazas);

                        strcpy(viaje[vec[seleccion-1]].plazas_libre,num_plazas);

                        if(plazas==0){
                        strcpy(viaje[vec[seleccion-1]].estado,"cerrado");
                        }

                        actualizarFichero();
                        guardarPasajero(vec,seleccion-1,num_user);

                    }
                }

       }
   }while(conf==0);


}

void mostrar_poblaciones(int *vec,int reserva,int *conf){
    int i,opc;


    for(i=0;i<numPasos;i++){


        if(strcmp(viaje[vec[reserva]].id_viaje,pasos[i].id_viaje)==0){
            printf("%s\n",pasos[i].poblacion);
        }
    }

    do{
            printf("Desea reservar este viaje :\n(1)SI (2)NO\n");
            scanf("%i",&opc);


            switch (opc){
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

void actualizarFichero()
{
    int i;

    FILE *fp;
    fp=fopen("viajes_replace.txt","w+");
    if(fp==NULL){
        printf("No se ha podido abrir el fichero");
    }else{

        for(i=0;i<numViajes;i++){


            fprintf(fp,"%s-%s-%s-%s-%s-%s-%s-%s-%s\n",viaje[i].id_viaje,viaje[i].id_mat,viaje[i].f_inic,viaje[i].h_inic,viaje[i].h_fin,viaje[i].plazas_libre,viaje[i].ida_vuelta,viaje[i].precio,viaje[i].estado);

        }
    }

    fclose(fp);


    remove("viajes.txt");
    rename("viajes_replace.txt","viajes.txt");
    leer_viaje(&viaje,&numViajes);
}

void guardarPasajero(int *vec,int reserva,int num_user){
        // crear nuevo fichero que guarde para guardar la reserva
        FILE *fp;


        fp=fopen("reservas.txt","a+");
        if(fp==NULL){
            printf("No se ha podido abrir el fichero reservas.txt.\n");
            return;
        }else{
            fprintf(fp,"%s-%s\n",viaje[vec[reserva]].id_viaje,usuario[num_user].id_usuario);
        }
        fclose(fp);

        leer_reservas(&reservas,&numReservas); // escribe en la estructura reservas la id del viaje y del usuario


}

void cancelarReserva(int num_user){
    int *vec=NULL,*vec_viaje=NULL,x,j=0,i,sel,cont=0, plazas=0;

        encontrarResevas(num_user,&vec,&vec_viaje,&x);

        if(vec!=NULL){
               do{
            printf("Tus reservas:\n");
            for(i=0;i<x;i++){
                            printf("(%i)%s-%s-%s-%s-%s\n",i+1,viaje[vec_viaje[i]].id_viaje,viaje[vec_viaje[i]].f_inic,viaje[vec_viaje[i]].h_inic,viaje[vec_viaje[i]].h_fin,viaje[vec_viaje[i]].ida_vuelta,viaje[vec_viaje[i]].precio);


                        }

                printf("Seleccione el viaje q desea cancelar:\n");
                scanf("%i",&sel);
                system("cls");
                    }while(sel>x || sel<1);





            eliminarReservas(reservas[vec[sel-1]].id_viaje);
            leer_reservas(&reservas,&numReservas);
            plazas=atoi(viaje[vec_viaje[sel-1]].plazas_libre);
            plazas++;
            sprintf(viaje[vec_viaje[sel-1]].plazas_libre,"%01d",plazas);
            actualizarFichero();
        }else {printf("No tiene viajes reservados\n");
                system("pause");
        }
}
void verificar_reserva(int *vec,int reserva,int *n,int num_user){
    int i,j;
    for(i=0;i<numVehiculos && *n==0;i++){
        if(strcmp(viaje[vec[reserva]].id_mat,vehiculo[i].id_mat)==0){
                if(strcmp(vehiculo[i].id_usuario,usuario[num_user].id_usuario)==0){
                 printf("Error/No puede reservar un viaje creado por usted\n");
                 *n=1;
            }
        }
    }
    if((*n)!=1){
       for(i=0;i<numReservas;i++){
        if(strcmp(reservas[i].id_usuario,usuario[num_user].id_usuario)==0){
            *n=1;
            printf("Error/No puede reservar un viaje ya reservado previamente\n");
        }
    }

    }
    system("pause");
}

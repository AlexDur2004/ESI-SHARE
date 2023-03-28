#include "reservar_viaje.h"


void reservar_viaje(int num_user){
    char id[7];
    int num_viaje=0,brkp=0;

    comprobar_mostar_viaje(num_user);

    do{
          printf("Introduzca la id del viaje que quiere reservar:\n");
    pregunta(id,7);
    actualizar_plazas(id,&brkp,&num_viaje);

    if(brkp==0){
        printf("Error:id incorrecta.\n");
    }
    }while(brkp==0);

    guardar_pasajero(num_viaje,num_user);//funcion q haga fichero que guarde la id de viaje y la id de usuario



}

void cancelar_reserva(int num_user){
    char id[7];
    int i,j,cont=1;


    printf("Viajes reservados:\n");
    for(i=0;i<numReservas;i++){
        if(strcmp(reservas[i].id_usuario,usuario[num_user].id_usuario)==0){
            for(j=0;j<numViajes;j++){
               if(strcmp(reservas[i].id_viaje,viaje[j].id_viaje)==0){
                printf("%i-%s",cont,viaje[j].id_viaje);
                cont++;
               }
            }
        }
    }

}

void actualizar_plazas(char *id,int *brkp,int *i){
    int plazas;
    char num_plazas[2];


    for((*i)=0;(*i)<numViajes && (*brkp)==0;(*i)++){

        if(strcmp(id,viaje[*i].id_viaje)==0){

           (*brkp)=1;
        plazas=atoi(viaje[*i].plazas_libre);

         plazas--;



        sprintf(num_plazas, "%d", plazas);
        strcpy(viaje[*i].plazas_libre,num_plazas);

                if(plazas==0){
                        strcpy(viaje[*i].estado,"cerrado");
                }
        }



    }
    actualizar_fichero();


}


void guardar_pasajero(int num_viaje,int num_user){
        // crear nuevo fichero que guarde para guardar la reserva
        FILE *fp;


        fp=fopen("reservas.txt","w+");
        if(fp==NULL){
            printf("No se ha podido abrir el fichero reservas.txt.\n");
            return;
        }else{
            fprintf(fp,"%s-%s\n",viaje[num_viaje].id_viaje,usuario[num_user].id_usuario);
        }
        fclose(fp);

        leer_reservas(&reservas,&numReservas); // escribe en la estructura reservas la id del viaje y del usuario


}

void actualizar_fichero()
{
    int counter=0;

    FILE *fp;
    fp=fopen("viajes_replace.txt","w+");
    if(fp==NULL){
        printf("No se ha podido abrir el fichero");
    }else{

        for(counter=0;counter<numViajes;counter++){


            fprintf(fp , "%s-%s-%s-%s-%s-%s-%s-%s-%s\n" ,viaje[counter].id_viaje,viaje[counter].id_mat,viaje[counter].f_inic,viaje[counter].h_inic,viaje[counter].h_fin,viaje[counter].plazas_libre,viaje[counter].ida_vuelta,viaje[counter].precio,viaje[counter].estado);

        }
    }



    fclose(fp);


    remove("viajes.txt");
    rename("viajes_replace.txt","viajes.txt");
}

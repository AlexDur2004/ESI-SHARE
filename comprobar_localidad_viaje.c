#include "comprobar_localidad_viaje.h"
#include "comprobar_estado_viaje.h"


void comprobar_mostar_viaje(int *num_user){
	int i;
   printf(" 1.La ESI:\n 2.Tu Localidad:\nEn donde te encuentras:");
   scanf("%i",&i);

	switch (i):
		case 1:viajes_esi();
			break;
		case 2:
		    break;viajes_localidad(&num_user);
}

void viajes_localidad(int *num_user){
	int k,i,j,viaje_disponible;

	void leer_usuario(Estr_Usuario **usuario, int *i);
	void leer_pasos(Estr_Pasos **pasos, int *i);

	for(j=0,j<i*,j++){
        if(strcmp(usuario[num_user].localidad,pasos[j].poblacion)){  // como acceder al usuario que esta usando el sistema?
            void comprobar_estado_viajes(&pasos,&viaje_disponible,j);

            if(viaje_disponible==1){
              mostar_viaje();
            }
        }
	}

}
void viajes_esi(){
 	int k,i,j,viaje_disponible;


	void leer_pasos(Estr_Pasos **pasos, int *i);

	for(j=0,j<i*,j++){
        if(strcmp("ESI",pasos[j].poblacion)){  // como acceder al usuario que esta usando el sistema?
            void comprobar_estado_viajes(&pasos,&viaje_disponible,j); // viaje_disponible sera un 1 si esta disponible y 0 si no

            if(viaje_disponible==1){
              mostar_viaje();
            }
        }
	}

}



void mostrar viaje(){
   printf("%s",pasos[j].id_viaje);
}

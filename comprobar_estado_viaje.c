#include "comprobar_estado_viaje.h"

void comprobar_estado_viajes(Estr_Pasos *pasos,int *disponible,int num_pasos){
      int num_viajes,j;

      leer_viaje(&viaje, &num_viajes);

      for(j=0;j<num_viajes && disponible==0;j++){

        if(strcmp(pasos[num_pasos].id_viaje, viaje[num_viajes].id_viaje)==0){
            *disponible++;
        }

      }

}








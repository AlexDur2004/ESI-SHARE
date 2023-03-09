#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char id_usuario[5];
    char nomb_usuario[21];
    char localidad[21];
    char perfil[14];
    char usuario[6];
    char contrasena[9];
} Estr_Usuario;

typedef struct{
    char id_mat[8];
    char id_usuario[5];
    char num_plazas[2];
    char desc_veh[51];
} Estr_Vehiculo;

typedef struct{
    char id_viaje[7];
    char id_mat[8];
    char f_inic[11];
    char h_inic[6];
    char h_fin[6];
    char plazas_libre[2];
    char ida_vuelta[6];
    char precio[5];
    char estado[11];
} Estr_Viaje;

typedef struct{
    char id_viaje[7];
    char poblacion[21];
} Estr_Pasos;

typedef struct{
    char siglas[4];
    char localidad[21];
} Estr_Localidad;

typedef struct{
    char localidad[21];
} Estr_Rutas;

#endif // ESTRUCTURAS_H_INCLUDED

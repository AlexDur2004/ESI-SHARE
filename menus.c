#include "menus.h"
#include <stdio.h>
#include <conio.h>
void menuPrincipal()
{
    int opc;

    while(opc!=3)
    {
        system("cls");
        printf(" \n");
        printf(" \n");
        color(0,6);
        printf("   ______   ______   _____            ______   _    _   _____   ______   ______     \n");
        printf("  |  ____| |  ____| |_   _|          |  ____| | |  | | |  _  | |  __  | |  ____|    \n");
        printf("  | |__    | (____    | |    ______  | (____  | |__| | | |_| | | |__) | | |__       \n");
        printf("  |  __|   |____  |   | |   |______| |____  | |  __  | |  _  | |  _ __| |  __|      \n");
        printf("  | |____   ____) |  _| |_            ____) | | |  | | | | | | | ||_|_  | |____     \n");
        printf("  |______| |______| |_____|          |______| |_|  |_| |_| |_| |_|  |_| |______|    \n");
        printf("                                                                                    \n");
        printf("                       ¿Que le gustaria hacer?\n");
        color(0,14);
        printf("                         (1)Iniciar sesion.\n");
        printf("                         (2)Registrarse.\n");
        printf("                         (3)Salir.\n");
        fflush(stdin);
        scanf("%d", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                acceso(usuario, numUsuarios);
                break;
            case 2:
                altaUsuario(usuario, &numUsuarios);
                break;
            case 3:
                exit(1);
                break;
        }
    }
}

void menuUsuario(int i)
{
    int opc;

    while(opc!=3)
    {
        system("cls");
        color(0, 6);
        printf("Hola %s,\n", usuario[i].nomb_usuario);
        printf(" \n");
        printf("¿Que quiere ser?\n");
        color(0, 14);
        printf("(1)Pasajero.\n");
        printf("(2)Conductor.\n");
        printf("(3)Volver.\n");
        color(0,15);
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                menuPasajero(i);
                break;
            case 2:
                menuConductor(i);
                break;
            case 3:
                menuPrincipal();
                break;
        }
    }
}

void menuPasajero(int i)
{
    int opc;

    while(opc!=3)
    {
        system("cls");
        color(0,6);
        printf("¿Que quiere ver?\n");
        color(0,14);
        printf("(1)Perfil.\n");
        printf("(2)Viajes.\n");
        printf("(3)Volver.\n");
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                menuPasajeroPerfil(i);
                break;
            case 2:
                menuPasajeroViajes(i);
                break;
            case 3:
                menuUsuario(i);
                break;
        }
    }
}

void menuPasajeroPerfil(int i)
{
    int opc;

    while(opc!=5)
    {
        system("cls");
        color(0,6);
        printf("ID de usuario:                                    %s.\n", usuario[i].id_usuario);
        printf("Nombre completo:                                  %s.\n", usuario[i].nomb_usuario);
        printf("Localidad de residencia:                          %s.\n", usuario[i].localidad);
        printf("Tipo de perfil:                                   %s.\n", usuario[i].perfil);
        printf("Usuario:                                          %s.\n", usuario[i].usuario);
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf("                     ¿Que quieres hacer?\n");
        color(0,14);
        printf("                (1)Modificar nombre completo.\n");
        printf("                (2)Modificar localidad de residencia.\n");
        printf("                (3)Modificar usuario.\n");
        printf("                (4)Modificar contrasena.\n");
        printf("                (5)Volver\n");
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                modificarPerfilNombre(i);
                break;
            case 2:
                modificarPerfilLocalidad(i);
                break;
            case 3:
                modificarPerfilUsuario(i);
                break;
            case 4:
                modificarPerfilContrasena(i);
                break;
            case 5:
                menuPasajero(i);
                break;
        }
    }
}

void menuPasajeroViajes(int i)
{
    int opc, x;

    while(opc!=3)
    {
        system("cls");
        color(0,6);
        printf("¿Que quiere hacer?\n");
        color(0,14);
        printf("(1)Reservar viaje.\n");
        printf("(2)Cancelar viaje.\n");
        printf("(3)Volver.\n");
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                buscadorRutas();
                break;
            case 2:
                ;
                break;
            case 3:
                menuPasajero(i);
                break;
        }
    }
}

void menuConductor(int i)
{
    int opc;

    while(opc!=4)
    {
        system("cls");
        color(0,6);
        printf("¿Que quiere ver?\n");
        color(0,14);
        printf("(1)Perfil.\n");
        printf("(2)Vehiculos.\n");
        printf("(3)Viajes.\n");
        printf("(4)Volver.\n");
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                menuConductorPerfil(i);
                break;
            case 2:
                menuConductorVehiculo(i);
                break;
            case 3:
                menuConductorViajes(i);
                break;
            case 4:
                menuUsuario(i);
                break;
        }
    }
}

void menuConductorPerfil(int i)
{
    int opc;

    while(opc!=5)
    {
        system("cls");
        color(0,6);
        printf("ID de usuario:                                    %s.\n", usuario[i].id_usuario);
        printf("Nombre completo:                                  %s.\n", usuario[i].nomb_usuario);
        printf("Localidad de residencia:                          %s.\n", usuario[i].localidad);
        printf("Tipo de perfil:                                   %s.\n", usuario[i].perfil);
        printf("Usuario:                                          %s.\n", usuario[i].usuario);
        printf(" \n");
        printf(" \n");
        printf(" \n");
        printf("                   ¿Que quiere hacer?\n");
        color(0,14);
        printf("                (1)Modificar nombre completo.\n");
        printf("                (2)Modificar localidad de residencia.\n");
        printf("                (3)Modificar usuario.\n");
        printf("                (4)Modificar contrasena.\n");
        printf("                (5)Volver\n");
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                modificarPerfilNombre(i);
                break;
            case 2:
                modificarPerfilLocalidad(i);
                break;
            case 3:
                modificarPerfilUsuario(i);
                break;
            case 4:
                modificarPerfilContrasena(i);
                break;
            case 5:
                menuConductor(i);
                break;
        }
    }
}

void menuConductorVehiculo(int i)
{
    int opc;
    //int numVehiculos;

    while(opc!=4)
    {
        system("cls");
        color(0,6);
        printf("¿Que quiere hacer?\n", usuario[i].nomb_usuario);
        color(0,14);
        printf("(1)Alta de vehículo.\n");
        printf("(2)Modificar vehículo.\n");
        printf("(3)Eliminar vehículo.\n");
        printf("(4)Volver.\n");
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                altaVehiculo(i);
                break;
            case 2:
                modificarVehiculo(i);
                break;
            case 3:
                eliminarVehiculo(i);
                break;
            case 4:
                menuConductor(i);
                break;
        }
    }
}

void menuConductorViajes(int i)
{
    int opc, x;
    //int numViajes;

    while(opc!=3)
    {
        system("cls");
        //llamar a función que nos entrege la info de los viajes activos al momento
        //for(x=0;x<max;x++)
        //{
        //    if(strcmp(usuario[i].id_usuario, viaje[i]))
        //}
        color(0,6);
        printf("¿Que quiere hacer?\n");
        color(0,14);
        printf("(1)Crear viaje.\n");
        printf("(2)Modificar viaje.\n");
        printf("(3)Anular viaje.\n");
        printf("(4)Volver.\n");
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                ;
                break;
            case 2:
                ;
                break;
            case 3:
                ;
                break;
            case 4:
                menuConductor(i);
                break;
        }
    }
}


void menuAdmin(int i)
{
    int opc;

    while(opc!=4)
    {
        system("cls");
        color(0,6);
        printf("Hola %s (Administrador),\n", usuario[i].nomb_usuario);
        printf("¿Que quiere ver?\n");
        color(0,14);
        printf("(1)Usuarios.\n");
        printf("(2)Vehiculos.\n");
        printf("(3)Viajes.\n");
        printf("(4)Volver.\n");
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                menuAdminUsuarios(i);
                break;
            case 2:
                menuAdminVehiculos(i);
                break;
            case 3:
                menuAdminViajes(i);
                break;
            case 4:
                menuPrincipal();
                break;
        }
    }
}

void menuAdminUsuarios(int i)
{
    int opc;

    while(opc!=5)
    {
        system("cls");
        color(0,6);
        printf("¿Que quiere hacer?\n");
        color(0,14);
        printf("(1)Alta de usuario.\n");
        printf("(2)Baja de usuario.\n");
        printf("(3)Modificar usuario.\n");
        printf("(4)Listar usuarios.\n");
        printf("(5)Volver.\n");
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                altaUsuario();
                break;
            case 2:
                ;
                break;
            case 3:
                modificarAdminUsuario();
                break;
            case 4:
                listarUsuarios();
                system("PAUSE");
                break;
            case 5:
                menuAdmin(i);
                break;
        }
    }
}

void menuAdminVehiculos(int i)
{
    int opc,encontrado, contador_veh_usuario;
    char opc2[4];

    while(opc!=6)
    {
        system("cls");
        color(0,6);
        printf("¿Que quiere hacer?\n");
        color(0,14);
        printf("(1)Alta de vehiculo.\n");
        printf("(2)Baja de vehiculo.\n");
        printf("(3)Modificar vehiculo.\n");
        printf("(4)Listar vehiculos.\n");
        printf("(5)Mostrar lista de viajes de vehiculo.\n");
        printf("(6)Volver.\n");
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                encontrado=0;
                system("cls");
                listarUsuarios();
                color(0,6);
                printf("Escriba la ID del usuario a la que se quiera dar de alta el vehículo\n");
                color(0,14);
                scanf("%4s",&opc2);
                for(int counter=0;(counter<numUsuarios)&&(encontrado==0);counter++){
                    if(strcmp(opc2,usuario[counter].id_usuario)==0){
                        encontrado=1;
                        i=counter;
                        altaVehiculo(i);
                    }
                }
                if(encontrado==0){
                    system("cls");
                    color(0,6);
                    printf("No se ha encontrado ningun usuario con la siguiente ID: %s\n",opc2);
                    system("PAUSE");
                }
                break;
            case 2:
                encontrado=0;
                system("cls");
                listarUsuarios();
                color(0,6);
                printf("Escriba la ID del usuario a la que se quiera eliminar un vehículo\n");
                color(0,14);
                scanf("%4s",&opc2);
                for(int counter=0;(counter<numUsuarios)&&(encontrado==0);counter++){
                    if(strcmp(opc2,usuario[counter].id_usuario)==0){
                        encontrado=1;
                        i=counter;
                        system("cls");
                        eliminarVehiculo(i);
                    }
                }
                break;
            case 3:
                encontrado=0;
                system("cls");
                listarUsuarios();
                color(0,6);
                printf("Escriba la ID del usuario a la que se quiera modificar el vehículo\n");
                color(0,14);
                scanf("%4s",&opc2);
                for(int counter=0;(counter<numUsuarios)&&(encontrado==0);counter++){
                    if(strcmp(opc2,usuario[counter].id_usuario)==0){
                        encontrado=1;
                        i=counter;
                        system("cls");
                        modificarVehiculo(i);
                    }
                }
                if(encontrado==0){
                    system("cls");
                    color(0,6);
                    printf("No se ha encontrado ningun usuario con la siguiente ID: %s\n",opc2);
                    system("PAUSE");
                }
                break;
            case 4:
                listarVehiculos();
                break;
            case 5:
                ;
                break;
            case 6:
                menuAdmin(i);
                break;
        }
    }
}

void menuAdminViajes(int i)
{
    int opc;

    while(opc!=5)
    {
        system("cls");
        color(0,6);
        printf("¿Que quiere hacer?\n");
        color(0,14);
        printf("(1)Alta de viaje.\n");
        printf("(2)Baja de viaje.\n");
        printf("(3)Modificar viaje.\n");
        printf("(4)Listar viajes.\n");
        printf("(5)Volver.\n");
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                ;
                break;
            case 2:
                ;
                break;
            case 3:
                ;
                break;
            case 4:
                ;
                break;
            case 5:
                menuAdmin(i);
                break;
        }
    }
}

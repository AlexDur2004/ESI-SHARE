#include "menus.h"

void menuPrincipal()
{
    int opc;

    while(opc!=3)
    {
        system("cls");
        color(15, 1);
        printf("Bienvenid@ a ESI-SHARE\n");
        color(0,15);
        printf("¿Que le gustaria hacer?\n");
        color(0,4);
        printf("(1)Iniciar sesion.\n");
        color(0,3);
        printf("(2)Registrarse.\n");
        color(0,14);
        printf("(3)Salir.\n");
        color(0,15);
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
        color(15, 1);
        printf("Hola %s,\n", usuario[i].nomb_usuario);
        color(0,15);
        printf("¿Que quiere ser?\n");
        color(0, 4);
        printf("(1)Pasajero.\n");
        color(0, 3);
        printf("(2)Conductor.\n");
        color(0,14);
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
        printf("Hola %s,\n¿Que quiere ver?\n(1)Perfil.\n(2)Viajes.\n(3)Volver.\n", usuario[i].nomb_usuario);
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
        printf("ID de usuario: %s.\nNombre completo: %s.\nLocalidad de residencia: %s.\nTipo de perfil: %s.\nUsuario: %s.\n", usuario[i].id_usuario, usuario[i].nomb_usuario, usuario[i].localidad, usuario[i].perfil, usuario[i].usuario);
        printf("¿Que quiere hacer?\n(1)Modificar nombre completo.\n(2)Modificar localidad de residencia.\n(3)Modificar usuario.\n(4)Modificar contrasena.\n(5)Volver\n");
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
        //int numViajes;

        //llamar a función que nos entrege la info de los viajes activos al momento
        //for(x=0;x<max;x++)
        //{
        //    if(strcmp(usuario[i].id_usuario, viaje[i]))
        //}

        printf("¿Que quiere hacer?\n(1)Reservar viaje.\n(2)Cancelar viaje.\n(3)Volver\n");
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
        printf("Hola %s,\n¿Que quiere ver?\n(1)Perfil.\n(2)Vehiculos.\n(3)Viajes.\n(4)Volver.\n", usuario[i].nomb_usuario);
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

    while(opc!=3)
    {
        system("cls");
        printf("ID de usuario: %s.\nNombre completo: %s.\nLocalidad de residencia: %s.\nTipo de perfil: %s.\nUsuario: %s.\n", usuario[i].id_usuario, usuario[i].nomb_usuario, usuario[i].localidad, usuario[i].perfil, usuario[i].usuario);
        printf("¿Que quiere hacer?\n(1)Modificar nombre completo.\n(2)Modificar localidad de residencia.\n(3)Modificar usuario.\n(4)Modificar usuario.\n(5)Modificar contrasena.\n(6)Volver\n");
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
                ;
                break;
            case 6:
                menuConductor(i);
                break;
        }
    }
}

void menuConductorVehiculo(int i)
{
    int opc,ID_actual;
    //int numVehiculos;

    while(opc!=4)
    {
        system("cls");
        printf("¿Que quiere hacer?\n(1)Alta de vehículo.\n(2)Modificar vehículo.\n(3)Eliminar vehículo.\n(4)Volver.\n", usuario[i].nomb_usuario);
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
                ;
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

        printf("¿Que quiere hacer?\n(1)Crear viaje.\n(2)Modificar viaje.\n(3)Anular viaje.\n(4)Salir.\n");
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
        printf("Hola %s (Administrador),\n¿Que quiere ver?\n(1)Usuarios.\n(2)Vehiculos.\n(3)Viajes.\n(4)Volver.\n", usuario[i].nomb_usuario);
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
        printf("Hola %s (Administrador),\n¿Que quiere hacer?\n(1)Alta de usuario.\n(2)Baja de usuario.\n(3)Modificar usuario.\n(4)Listar usuarios.\n(5)Salir.\n", usuario[i].nomb_usuario);
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

void menuAdminVehiculos(int i)
{
    int opc,encontrado;
    char opc2[4];

    while(opc!=6)
    {
        system("cls");
        printf("Hola %s (Administrador),\n¿Que quiere hacer?\n(1)Alta de vehiculo.\n(2)Baja de vehiculo.\n(3)Modificar vehiculo.\n(4)Listar vehiculos.\n(5)Mostrar lista de viajes de vehiculo.\n(6)Salir.\n", usuario[i].nomb_usuario);
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                encontrado=0;
                system("cls");
                printf("Escriba la ID del usuario a la que se quiera dar de alta el vehículo\n");
                for(int counter=0;counter<numUsuarios;counter++){
                    printf("%s\n",usuario[counter].id_usuario);
                }
                printf("\n");
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
                    printf("No se ha encontrado ningun usuario con la siguiente ID: %s\n",opc2);
                    system("PAUSE");
                }
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
        printf("Hola %s (Administrador),\n¿Que quiere hacer?\n(1)Alta de viaje.\n(2)Baja de viaje.\n(3)Modificar viaje.\n(4)Listar viajes.\n(5)Salir.\n", usuario[i].nomb_usuario);
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

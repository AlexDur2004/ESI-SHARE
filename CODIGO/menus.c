#include "menus.h"

//Cabecera: void menuPrincipal(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int);
//Precondicion: Tener las estructuras inicializados, con sus contadores.
//Postcondicion: Llevarte a las diferentes funciones, a partir de la opcion que se escriba.

void menuPrincipal(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2)
{
    int opc;

    while(opc!=3)
    {
        leer_usuario(&usuario, &numUsuarios);
        system("cls");
        color(0, 6);
        printf("   ______   ______   _____            ______   _    _   _____   ______   ______ \n");
        printf("  |  ____| |  ____| |_   _|          |  ____| | |  | | |  _  | |  __  | |  ____|\n");
        printf("  | |__    | (____    | |    ______  | (____  | |__| | | |_| | | |__) | | |__   \n");
        printf("  |  __|   |____  |   | |   |______| |____  | |  __  | |  _  | |  _ __| |  __|  \n");
        printf("  | |____   ____) |  _| |_            ____) | | |  | | | | | | | ||_|_  | |____ \n");
        printf("  |______| |______| |_____|          |______| |_|  |_| |_| |_| |_|  |_| |______|\n");
        printf("                                                                                \n");
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
                acceso(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2);
                break;
            case 2:
                altaUsuario(usuario, numUsuarios, localidad, numLocalidades);
                break;
            case 3:
                exit(1);
                break;
        }
    }
}

//Cabecera: void menuUsuario(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondicion: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//Tambien necesitamos las estructuras inicializados, con sus contadores.
//Postcondicion: Llevarte a las diferentes funciones, a partir de la opcion que se escriba.

void menuUsuario(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int i)
{
    int opc;

    while(opc!=3)
    {
        system("cls");
        color(15, 0);
        printf("Hola %s\n", usuario[i].nomb_usuario);
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
                menuPasajero(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                break;
            case 2:
                menuConductor(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                break;
            case 3:
                menuPrincipal(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2);
                break;
        }
    }
}

//Cabecera: void menuPasajero(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondicion: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//Tambien necesitamos las estructuras inicializados, con sus contadores.
//Postcondicion: Llevarte a las diferentes funciones, a partir de la opcion que se escriba.

void menuPasajero(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int i)
{
    int opc;

    while(opc!=3)
    {
        system("cls");
        color(15, 0);
        printf("Hola %s,\n", usuario[i].nomb_usuario);
        color(0,15);
        printf("¿Que quiere ver?\n");
        color(0, 4);
        printf("(1)Perfil.\n");
        color(0, 3);
        printf("(2)Viajes.\n");
        color(0,14);
        printf("(3)Volver.\n");
        color(0,15);
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                menuPasajeroPerfil(usuario, numUsuarios, viaje, numViajes, reservas, numReservas, localidad, numLocalidades, i);
                break;
            case 2:
                menuPasajeroViajes(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                break;
            case 3:
                menuUsuario(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                break;
        }
    }
}

//Cabecera: void menuPasajeroPerfil(Estr_Usuario *, int, Estr_Viaje *, int, Estr_Reservas *, int, Estr_Localidad *, int, int);
//Precondicion: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//Tambien necesitamos las estructuras inicializados, con sus contadores.
//Postcondicion: Llevarte a las diferentes funciones, a partir de la opcion que se escriba.

void menuPasajeroPerfil(Estr_Usuario *usuario, int numUsuarios, Estr_Viaje *viaje, int numViajes, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, int i)
{
    int opc;

    while(opc!=5)
    {
        leer_usuario(&usuario, &numUsuarios);
        system("cls");
        color(0, 3);
        printf("ID de usuario: ");
        color(0, 15);
        printf("%s\n", usuario[i].id_usuario);
        color(0, 3);
        printf("Nombre completo: ");
        color(0, 15);
        printf("%s\n", usuario[i].nomb_usuario);
        color(0, 3);
        printf("Localidad de residencia: ");
        color(0, 15);
        printf("%s\n", usuario[i].localidad);
        color(0, 3);
        printf("Tipo de perfil: ");
        color(0, 15);
        printf("%s\n", usuario[i].perfil);
        color(0, 3);
        printf("Usuario: ");
        color(0, 15);
        printf("%s\n\n", usuario[i].usuario);
        color(0,15);
        printf("¿Que quiere hacer?\n");
        color(0, 2);
        printf("(1)Modificar nombre completo.\n");
        color(0, 4);
        printf("(2)Modificar localidad de residencia.\n");
        color(0, 11);
        printf("(3)Modificar usuario.\n");
        color(0, 6);
        printf("(4)Modificar contrasena.\n");
        color(0,14);
        printf("(5)Volver.\n");
        color(0,15);
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                modificarPerfilNombre(usuario, numUsuarios, i);
                break;
            case 2:
                modificarPerfilLocalidad(usuario, numUsuarios, viaje, numViajes, reservas, numReservas, localidad, numLocalidades, i);
                break;
            case 3:
                modificarPerfilUsuario(usuario, numUsuarios, i);
                break;
            case 4:
                modificarPerfilContrasena(usuario, numUsuarios, i);
                break;
            case 5:
                return;
                break;
        }
    }
}

//Cabecera: void menuPasajeroViajes(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondicion: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//Tambien necesitamos las estructuras inicializados, con sus contadores.
//Postcondicion: Llevarte a las diferentes funciones, a partir de la opcion que se escriba.

void menuPasajeroViajes(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int i)
{
    int opc;

    while(opc!=3)
    {
        leer_vehiculo(&vehiculo, &numVehiculos);
        leer_viaje(&viaje, &numViajes);
        leer_pasos(&pasos, &numPasos);
        leer_reservas(&reservas, &numReservas);
        system("cls");
        listarReservas(usuario, viaje, numViajes, reservas, numReservas, i);
        color(0,15);
        printf("¿Que quiere hacer?\n");
        color(0, 4);
        printf("(1)Reservar viaje.\n");
        color(0, 3);
        printf("(2)Cancelar viaje.\n");
        color(0,14);
        printf("(3)Volver.\n");
        color(0,15);
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                altaReserva(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, i);
                break;
            case 2:
                cancelarReserva(usuario, viaje, numViajes, reservas, numReservas, i);
                break;
            case 3:
                menuPasajero(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                break;
        }
    }
}

//Cabecera: void menuConductor(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondicion: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//Tambien necesitamos las estructuras inicializados, con sus contadores.
//Postcondicion: Llevarte a las diferentes funciones, a partir de la opcion que se escriba.

void menuConductor(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2,  int i)
{
    int opc;

    while(opc!=4)
    {
        system("cls");
        color(15, 0);
        printf("Hola %s\n", usuario[i].nomb_usuario);
        color(0, 15);
        printf("¿Que quiere ver?\n");
        color(0, 4);
        printf("(1)Perfil.\n");
        color(0, 3);
        printf("(2)Vehiculos.\n");
        color(0, 2);
        printf("(3)Viajes.\n");
        color(0, 14);
        printf("(4)Volver.\n");
        color(0, 15);
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                menuConductorPerfil(usuario, numUsuarios, viaje, numViajes, reservas, numReservas, localidad, numLocalidades, i);
                break;
            case 2:
                menuConductorVehiculo(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                break;
            case 3:
                menuConductorViajes(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                break;
            case 4:
                menuUsuario(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                break;
        }
    }
}

//Cabecera: void menuConductorPerfil(Estr_Usuario *, int, Estr_Viaje *, int, Estr_Reservas *, int, Estr_Localidad *, int, int);
//Precondicion: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//Tambien necesitamos las estructuras inicializados, con sus contadores.
//Postcondicion: Llevarte a las diferentes funciones, a partir de la opcion que se escriba.

void menuConductorPerfil(Estr_Usuario *usuario, int numUsuarios, Estr_Viaje *viaje, int numViajes, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, int i)
{
    int opc;

    while(opc!=5)
    {
        leer_usuario(&usuario, &numUsuarios);
        system("cls");
        color(0, 3);
        printf("ID de usuario: ");
        color(0, 15);
        printf("%s\n", usuario[i].id_usuario);
        color(0, 3);
        printf("Nombre completo: ");
        color(0, 15);
        printf("%s\n", usuario[i].nomb_usuario);
        color(0, 3);
        printf("Localidad de residencia: ");
        color(0, 15);
        printf("%s\n", usuario[i].localidad);
        color(0, 3);
        printf("Tipo de perfil: ");
        color(0, 15);
        printf("%s\n", usuario[i].perfil);
        color(0, 3);
        printf("Usuario: ");
        color(0, 15);
        printf("%s\n\n", usuario[i].usuario);
        color(0,15);
        printf("¿Que quiere hacer?\n");
        color(0, 2);
        printf("(1)Modificar nombre completo.\n");
        color(0, 4);
        printf("(2)Modificar localidad de residencia.\n");
        color(0, 11);
        printf("(3)Modificar usuario.\n");
        color(0, 6);
        printf("(4)Modificar contrasena.\n");
        color(0,14);
        printf("(5)Volver.\n");
        color(0,15);
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                modificarPerfilNombre(usuario, numUsuarios, i);
                break;
            case 2:
                modificarPerfilLocalidad(usuario, numUsuarios, viaje, numViajes, reservas, numReservas, localidad, numLocalidades, i);
                break;
            case 3:
                modificarPerfilUsuario(usuario, numUsuarios, i);
                break;
            case 4:
                modificarPerfilContrasena(usuario, numUsuarios, i);
                break;
            case 5:
                return;
                break;
        }
    }
}

//Cabecera: void menuConductorVehiculo(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondicion: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//Tambien necesitamos las estructuras inicializados, con sus contadores.
//Postcondicion: Llevarte a las diferentes funciones, a partir de la opcion que se escriba.

void menuConductorVehiculo(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int i)
{
    int opc;

    while(opc!=4)
    {
        leer_vehiculo(&vehiculo, &numVehiculos);
        system("cls");
        listarVehiculosUsuario(usuario, vehiculo, numVehiculos, i);
        color(0, 15);
        printf("¿Que quiere hacer?\n");
        color(0, 4);
        printf("(1)Alta de vehiculo.\n");
        color(0, 3);
        printf("(2)Modificar vehiculo.\n");
        color(0, 2);
        printf("(3)Eliminar vehiculo.\n");
        color(0, 14);
        printf("(4)Volver.\n");
        color(0, 15);
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                altaVehiculo(usuario, vehiculo, numVehiculos, i);
                break;
            case 2:
                modificarVehiculo(usuario, vehiculo, numVehiculos, viaje, numViajes, i);
                break;
            case 3:
                eliminarVehiculo(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, i);
                break;
            case 4:
                menuConductor(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                break;
        }
    }
}

//Cabecera: void menuConductorViajes(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondicion: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//Tambien necesitamos las estructuras inicializados, con sus contadores.
//Postcondicion: Llevarte a las diferentes funciones, a partir de la opcion que se escriba.

void menuConductorViajes(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int i)
{
    int opc;

    while(opc!=3)
    {
        leer_vehiculo(&vehiculo, &numVehiculos);
        leer_viaje(&viaje, &numViajes);
        leer_pasos(&pasos, &numPasos);
        leer_reservas(&reservas, &numReservas);
        system("cls");
        listarViajes(usuario, vehiculo, numVehiculos, viaje, numViajes, i);
        color(0, 15);
        printf("¿Que quiere hacer?\n");
        color(0, 4);
        printf("(1)Crear viaje.\n");
        color(0, 3);
        printf("(2)Modificar viaje.\n");
        color(0, 2);
        printf("(3)Anular/Finalizar viaje.\n");
        color(0, 14);
        printf("(4)Volver.\n");
        color(0, 15);
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                altaViaje(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i, 0);
                break;
            case 2:
                modificarViaje(usuario, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                break;
            case 3:
                finalizar_viaje(usuario, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, i);
                break;
            case 4:
                menuConductor(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                break;
        }
    }
}

//Cabecera: void menuAdmin(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondicion: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//Tambien necesitamos las estructuras inicializados, con sus contadores.
//Postcondicion: Llevarte a las diferentes funciones, a partir de la opcion que se escriba.

void menuAdmin(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int i)
{
    int opc;

    while(opc!=4)
    {
        system("cls");
        color(15, 0);
        printf("Hola %s (Administrador)\n", usuario[i].nomb_usuario);
        color(0, 15);
        printf("¿Que quiere ver?\n");
        color(0, 4);
        printf("(1)Usuarios.\n");
        color(0, 3);
        printf("(2)Vehiculos.\n");
        color(0, 2);
        printf("(3)Viajes.\n");
        color(0, 14);
        printf("(4)Volver.\n");
        color(0, 15);
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                menuAdminUsuarios(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                break;
            case 2:
                menuAdminVehiculos(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                break;
            case 3:
                menuAdminViajes(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                break;
            case 4:
                menuPrincipal(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2);
                break;
        }
    }
}

//Cabecera: void menuAdminUsuarios(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondicion: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//Tambien necesitamos las estructuras inicializados, con sus contadores.
//Postcondicion: Llevarte a las diferentes funciones, a partir de la opcion que se escriba.

void menuAdminUsuarios(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int i)
{
    int opc;

    while(opc!=5)
    {
        leer_usuario(&usuario, &numUsuarios);
        leer_vehiculo(&vehiculo, &numVehiculos);
        leer_viaje(&viaje, &numViajes);
        leer_pasos(&pasos, &numPasos);
        leer_reservas(&reservas, &numReservas);
        system("cls");
        color(15, 0);
        printf("Hola %s (Administrador)\n", usuario[i].nomb_usuario);
        color(0, 15);
        printf("¿Que quiere hacer?\n");
        color(0, 2);
        printf("(1)Alta de usuario.\n");
        color(0, 4);
        printf("(2)Baja de usuario.\n");
        color(0, 11);
        printf("(3)Modificar usuario.\n");
        color(0, 6);
        printf("(4)Listar usuarios.\n");
        color(0,14);
        printf("(5)Volver.\n");
        color(0,15);
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                altaUsuario(usuario, numUsuarios, localidad, numLocalidades);
                break;
            case 2:
                eliminarAdminUsuario(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas);
                break;
            case 3:
                modificarAdminUsuario(usuario, numUsuarios, viaje, numViajes, reservas, numReservas, localidad, numLocalidades);
                break;
            case 4:
                listarUsuarios(usuario, numUsuarios);
                break;
            case 5:
                menuAdmin(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                break;
        }
    }
}

//Cabecera: void menuAdminVehiculos(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondicion: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//Tambien necesitamos las estructuras inicializados, con sus contadores.
//Postcondicion: Llevarte a las diferentes funciones, a partir de la opcion que se escriba.

void menuAdminVehiculos(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int i)
{
    int opc;

    while(opc!=6)
    {
        leer_vehiculo(&vehiculo, &numVehiculos);
        leer_viaje(&viaje, &numViajes);
        leer_pasos(&pasos, &numPasos);
        leer_reservas(&reservas, &numReservas);
        system("cls");
        color(15, 0);
        printf("Hola %s (Administrador)\n", usuario[i].nomb_usuario);
        color(0, 15);
        printf("¿Que quiere hacer?\n");
        color(0, 2);
        printf("(1)Alta de vehiculo.\n");
        color(0, 4);
        printf("(2)Baja de vehiculo.\n");
        color(0, 11);
        printf("(3)Modificar vehiculo.\n");
        color(0, 6);
        printf("(4)Listar vehiculos.\n");
        color(0, 9);
        printf("(5)Mostrar lista de viajes de un vehiculo.\n");
        color(0,14);
        printf("(6)Volver.\n");
        color(0,15);
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                altaAdmin(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas, 0);
                break;
            case 2:
                eliminarAdminVehiculo(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, i);
                break;
            case 3:
                modificarAdminVehiculo(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, i);
                break;
            case 4:
                listarVehiculos(usuario, numUsuarios, vehiculo, numVehiculos, i);
                break;
            case 5:
                listarAdminVehiculoViajes(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, i);
                break;
            case 6:
                menuAdmin(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                break;
        }
    }
}

//Cabecera: void menuAdminViajes(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondicion: Tener el entero "i", que nos indica la posicion del usuario que ha iniciado sesion en el sistema, en la estructura "usuario".
//Tambien necesitamos las estructuras inicializados, con sus contadores.
//Postcondicion: Llevarte a las diferentes funciones, a partir de la opcion que se escriba.

void menuAdminViajes(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int i)
{
    int opc, n=0;

    while(opc!=6)
    {
        leer_vehiculo(&vehiculo, &numVehiculos);
        leer_viaje(&viaje, &numViajes);
        leer_pasos(&pasos, &numPasos);
        leer_reservas(&reservas, &numReservas);
        system("cls");
        color(15, 0);
        printf("Hola %s (Administrador)\n", usuario[i].nomb_usuario);
        color(0, 15);
        printf("¿Que quiere hacer?\n");
        color(0, 2);
        printf("(1)Crear viaje.\n");
        color(0, 4);
        printf("(2)Anular/Finalizar viaje.\n");
        color(0, 11);
        printf("(3)Eliminar viaje.\n");
        color(0, 6);
        printf("(4)Modificar viaje.\n");
        color(0, 9);
        printf("(5)Listar viajes.\n");
        color(0,14);
        printf("(6)Volver.\n");
        color(0,15);
        fflush(stdin);
        scanf("%i", &opc);
        system("cls");
        switch(opc)
        {
            case 1:
                altaAdmin(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas, 1);
                break;
            case 2:
                eliminarAdminViaje(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, i, 1);
                break;
            case 3:
                eliminarAdminViaje(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, i, 0);
                break;
            case 4:
                modificarAdminViaje(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                break;
            case 5:
                listarAdminViajes(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, i, 0, &n);
                break;
            case 6:
                menuAdmin(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                break;
        }
    }
}

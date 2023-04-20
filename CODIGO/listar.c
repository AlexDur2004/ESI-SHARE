#include "listar.h"

//Cabecera: void listarUsuarios(Estr_Usuario *, int);
//Precondicion: Tener la estructura "usuario" inicializada, junto a su contador.
//Postcondicion: Dar una lista de todos los usuarios, que hay en la base de datos.

void listarUsuarios(Estr_Usuario *usuario, int numUsuarios)
{
    int counter;

    if(numUsuarios!=0) //Si hay usuarios en el sistema.
    {
        printf("LISTADO DE USUARIOS:\n");
        for(counter=0;counter<numUsuarios;counter++) //Pasa por todos los usuarios, usando el contador "numUsuarios", como delimitador.
        {
            color(0,14);
            printf("    Usuario %i:\n", counter+1); //Imprime todos los datos de cada usuario.
            color(0,3);
            printf("    ID: ");
            color(0,15);
            printf("%s", usuario[counter].id_usuario);
            color(0,3);
            printf(" | Nombre de usuario: ");
            color(0,15);
            printf("%s", usuario[counter].nomb_usuario);
            color(0,3);
            printf(" | Localidad: ");
            color(0,15);
            printf("%s", usuario[counter].localidad);
            color(0,3);
            printf(" | Perfil: ");
            color(0,15);
            printf("%s", usuario[counter].perfil);
            color(0,3);
            printf(" | Usuario: ");
            color(0,15);
            printf("%s\n", usuario[counter].usuario);
        }
    }
    else
    { //Si el delimitador "numUsuarios" es igual a 0, decimos que no hay usuarios registrados.
        color(0,3);
        printf("\tNo hay usuarios registrados.\n");
    }

color(0,15);
system("PAUSE");
}

//Cabecera: void listarVehiculos(Estr_Usuario *, int, Estr_Vehiculo *, int, int);
//Precondicion: Tener la estructura "usuario" y "vehiculo" inicializadas, junto a sus contadores.
//Postcondicion: Dar una lista de todos los vehiculos, de cada usuario, que hay en la base de datos.

void listarVehiculos(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, int i)
{
    int contador_veh_usuario, counter, counter2;

    if(numVehiculos!=0) //Si hay vehiculos en el sistema.
    {
        printf("LISTADO DE VEHICULOS:\n");
        for(counter=0;counter<numUsuarios;counter++) //Pasa por todos los usuarios, usando el contador "numUsuarios", como delimitador.
        {
            contador_veh_usuario=0; //Resetea el numero de vehiculos al empezar un usuario.
            color(0,14);
            printf("> Vehiculos de %s | ID: %s\n",usuario[counter].nomb_usuario,usuario[counter].id_usuario);
            for(counter2=0;counter2<numVehiculos;counter2++) //Pasa por todos los vehiculos, usando el contador "numVehiculos", como delimitador.
            {
                if(strcmp(usuario[counter].id_usuario,vehiculo[counter2].id_usuario)==0)
                //Si la id del usuario propietario del vehiculo coincide con la id del usuario actual, se imprime los datos del vehiculo.
                {
                    color(0,4);
                    printf("    Vehiculo "); //Imprime todos los datos de cada vehiculo.
                    color(0,15);
                    printf("%i", (contador_veh_usuario)+1);
                    color(0,4);
                    printf(":\t");
                    color(0,3);
                    printf("    Matricula: ");
                    color(0,15);
                    printf("%s", vehiculo[counter2].id_mat);
                    color(0,3);
                    printf(" | Nº de plazas: ");
                    color(0,15);
                    printf("%s", vehiculo[counter2].num_plazas);
                    color(0,3);
                    printf(" | Descripcion: ");
                    color(0,15);
                    printf("%s\n", vehiculo[counter2].desc_veh);
                    contador_veh_usuario++; //Se va sumando 1 por vehiculo encontrado.
                }
            }
            if(contador_veh_usuario==0) //Si no se ha encontrado ningun vehiculo para el usuario.
            {
                color(0,3);
                printf("    No posee vehiculos registrados.\n");
            }
        }
    }
    else
    {
        color(0, 15);
        printf("\tNo hay vehiculos registrados.\n");
    }
    color(0,15);
    system("PAUSE");
}

//Cabecera: void listarAdminViajes(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, int, int);
//Precondicion: Tener la estructura "usuario", "vehiculo" y "viaje" inicializadas, junto a sus contadores.
//Postcondicion: Si n=0, da una lista de todos los viajes, de cada usuario, que hay en la base de datos, y si n=1, da una lista de los viajes abiertos que hay de cada usuario.

void listarAdminViajes(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, int i, int n, int *num)
{
    int contador_viaje, *vec=NULL, *vec_viaje=NULL, num_v, m, j, id, counter;

    if(numViajes!=0) //Si hay viajes en el sistema.
    {
        printf("LISTADO DE VIAJES:\n");
        for(counter=0;counter<numUsuarios;counter++) //Pasa por todos los usuarios, usando el contador "numUsuarios", como delimitador.
        {
            color(0,14);
            printf("> Viajes de %s | ID: %s\n", usuario[counter].nomb_usuario,usuario[counter].id_usuario);
            id=atoi(usuario[counter].id_usuario); //Pasamos la id del usuario a entero, para que pueda entrar en la funcion.
            id--;
            encontrarVehiculos(usuario, vehiculo, numVehiculos, &vec, &num_v, id); //Encontramos todos los vehiculos del usuario.
            if(num_v!=0) //Si el usuario tiene algun vehiculo.
            {
                contador_viaje=0;
                for(j=0;j<num_v;j++) //Se encuentran todos los viajes que tiene con todos sus vehiculos.
                {
                    encontrarViajes(vehiculo, numVehiculos, viaje, numViajes, vehiculo[vec[j]].id_mat, &vec_viaje, &contador_viaje, n);
                }

                for(m=0; m<contador_viaje; m++) //Imprimos todos los viajes que tiene.
                {
                    color(0,4);
                    printf("    Viaje "); //Imprime todos los datos de cada vehiculo.
                    color(0,15);
                    printf("%i", m+1);
                    color(0,4);
                    printf(":\t");
                    color(0,3);
                    printf("ID: ");
                    color(0,15);
                    printf("%s", viaje[vec_viaje[m]].id_viaje);
                    color(0,3);
                    printf(" | Matricula: ");
                    color(0,15);
                    printf("%s", viaje[vec_viaje[m]].id_mat);
                    color(0,3);
                    printf(" | Fecha de partida: ");
                    color(0,15);
                    printf("%s", viaje[vec_viaje[m]].f_inic);
                    color(0,3);
                    printf(" | Hora de partida: ");
                    color(0,15);
                    printf("%s", viaje[vec_viaje[m]].h_inic);
                    color(0,3);
                    printf(" |\n                Hora de llegada: ");
                    color(0,15);
                    printf("%s", viaje[vec_viaje[m]].h_fin);
                    color(0,3);
                    printf(" | Plazas libres: ");
                    color(0,15);
                    printf("%s", viaje[vec_viaje[m]].plazas_libre);
                    color(0,3);
                    printf(" | Ida/Vuelta: ");
                    color(0,15);
                    printf("%s", viaje[vec_viaje[m]].ida_vuelta);
                    color(0,3);
                    printf(" | Precio: ");
                    color(0,15);
                    printf("%s", viaje[vec_viaje[m]].precio);
                    color(0,3);
                    printf(" | Estado: ");
                    color(0,15);
                    printf("%s\n\n", viaje[vec_viaje[m]].estado);
                    *num=1;
                }
                if(contador_viaje==0) //Si no tiene viajes.
                {
                    color(0,3);
                    printf("    No posee viajes registrados.\n");
                }
            }
            else //Si no tiene coches.
            {
                color(0,3);
                printf("    No posee vehiculos ni viajes registrados.\n");
            }
        }
    }
    else //Si no hay viajes abiertos en el sistema.
    {
        color(0, 15);
        printf("Ningun usuario del sistema tiene un viaje.\n");
    }
    color(0,15);
    system("PAUSE");
}

//Cabecera: void listarAdminVehiculoViajes(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, int);
//Precondicion: Tener la estructura "usuario", "vehiculo" y "viaje" inicializadas, con sus contadores.
//Postcondicion: Dar una lista de todos los viajes que ha realizado un vehiculo.

void listarAdminVehiculoViajes(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, int i)
{
    int x=0, m=0, z=0, encontrado=0, *vec=NULL;
    char mat[8];

    if(numVehiculos!=0)
    {
        while(encontrado==0) //Hasta que no se encuentre un vehiculo existente en el sistema.
        {
            listarVehiculos(usuario, numUsuarios, vehiculo, numVehiculos, i); //Listamos todos los vehiculos de cada usuario.
            printf("Introduzca la matricula de un vehiculo para obtener los viajes que ha realizado.\n");
            pregunta(mat, 8);

            for(z=0;z<numVehiculos;z++) //Nos desplazamos por toda la estructura "vehiculo".
            {
                if(strcmp(vehiculo[z].id_mat, mat)==0) //Si la matricula introducida existe en la base de datos.
                {
                    encontrado=1;
                }
            }
            if(encontrado==0) //Si el vehiculo no existe en el sistema.
            {
                printf("El vehiculo con matricula %s no existe.\n", mat);
                system("PAUSE");
            }
            system("cls");
        }
        encontrarViajes(vehiculo, numVehiculos, viaje, numViajes, mat, &vec, &x, 0); //Encuentra todos los viajes que tiene el vehiculo.

        if(x==0) //Si el vehiculo no tiene viajes.
        {
            printf("El vehiculo con matricula %s, no ha realizado ningun viaje.\n", mat);
        }
        else
        {
            printf("Los viajes realizados por el vehiculo con matricula %s son:\n", mat);
            for(m=0; m<x; m++) //Imprimimos todos los viajes realizados con ese vehiculo.
            {
                color(15, 0);
                printf("VIAJE %i:\n",m+1);
                color(0, 3);
                printf("   ID del viaje: ");
                color(0, 15);
                printf("%s\n", viaje[vec[m]].id_viaje);
                color(0, 3);
                printf("   Fecha de partida: ");
                color(0, 15);
                printf("%s\n", viaje[vec[m]].f_inic);
                color(0, 3);
                printf("   Hora de partida: ");
                color(0, 15);
                printf("%s\n", viaje[vec[m]].h_inic);
                color(0, 3);
                printf("   Hora de llegada: ");
                color(0, 15);
                printf("%s\n", viaje[vec[m]].h_fin);
                color(0, 3);
                printf("   Tipo: ");
                color(0, 15);
                printf("%s\n", viaje[vec[m]].ida_vuelta);
                color(0, 3);
                printf("   Precio: ");
                color(0, 15);
                printf("%s euros\n", viaje[vec[m]].precio);
                color(0, 3);
                printf("   Estado: ");
                color(0, 15);
                printf("%s\n\n", viaje[vec[m]].estado);
            }
        }
    }
    else
    {
        printf("No hay ni vehiculos ni viajes registrados.\n");
    }

    system("PAUSE");
}

//Cabecera: void listarLocalidades(Estr_Localidad *, int);
//Precondicion: Tener la estructura "localidad" inicializada, con su contador.
//Postcondicion: Imprimir una lista de 4 filas con todas las localidades.

void listarLocalidades(Estr_Localidad *localidad, int numLocalidades)
{
    int i=0, j=0, k=0;

    numLocalidades--; //Queremos quitarle la ultima linea que contiene a la Escuela Superior de Ingenieria (ESI), para que no se imprima por pantalla, junto a las localidades.

    k=numLocalidades/4; //Calcular filas necesarias.

    if(numLocalidades%4!=0) //Si al dividir las localidades entre 4, queda un resto, pues se aumenta una fila.
    {
        k++;
    }

    for(i=0; i<k; i++) //Imprimimos la lista de ciudades en 4 columnas homogeneas.
    {
        for(j=i; j<numLocalidades; j=j+k)
        {
            color(0, 3);
            printf("%s", localidad[j].siglas);
            color(0, 15);
            printf("-%-20s\t", localidad[j].localidad);
        }
        printf("\n");
    }
}

//Cabecera: void listarReservas(Estr_Usuario *, Estr_Viaje *, int, Estr_Reservas *, int, int);
//Precondicion: Tener las estructuras inicializadas, con sus contadores. Ademas, se necesita la variable "num_user", para saber a que usuario nos referimos.
//Postcondicion: Imprimir una lista con todos las reservas activas que tiene un usuario.

void listarReservas(Estr_Usuario *usuario, Estr_Viaje *viaje, int numViajes, Estr_Reservas *reservas, int numReservas, int num_user)
{
    int *vec=NULL, *vec_viaje=NULL, x=0, i;

    encontrarReservas(usuario, viaje, numViajes, reservas, numReservas, num_user, &vec_viaje, &vec, &x); //encuentra las reservas del usuario que estan abiertas

    if(vec!=NULL)
    { //verifica que el usuario tiene reservas
        printf("LISTADO DE SUS RESERVAS:\n");
        for(i=0;i<x;i++)
        {
            color(15, 0);
            printf("RESERVA %i:\n",i+1);
            color(0, 3);
            printf("   ID del viaje: ");
            color(0, 15);
            printf("%s\n", viaje[vec[i]].id_viaje);
            color(0, 3);
            printf("   Fecha de partida: ");
            color(0, 15);
            printf("%s\n", viaje[vec[i]].f_inic);
            color(0, 3);
            printf("   Hora de partida: ");
            color(0, 15);
            printf("%s\n", viaje[vec[i]].h_inic);
            color(0, 3);
            printf("   Hora de llegada: ");
            color(0, 15);
            printf("%s\n", viaje[vec[i]].h_fin);
            color(0, 3);
            printf("   Tipo: ");
            color(0, 15);
            printf("%s\n", viaje[vec[i]].ida_vuelta);
            color(0, 3);
            printf("   Precio: ");
            color(0, 15);
            printf("%s euros\n\n", viaje[vec[i]].precio);
        }
    }
    else
    {
        printf("No tiene viajes reservados.\n\n");
    }
}

//Cabecera: void listarVehiculosUsuario(Estr_Usuario *, Estr_Vehiculo *, int, int);
//Precondicion: Tener las estructuras inicializadas, con sus contadores. Ademas, se necesita la variable "num_user", para saber a que usuario nos referimos.
//Postcondicion: Imprimir una lista con todos los vehiculos que tiene un usuario.

void listarVehiculosUsuario(Estr_Usuario *usuario, Estr_Vehiculo *vehiculo, int numVehiculos, int num_user)
{
    int *vec=NULL, x=0, i;

    encontrarVehiculos(usuario, vehiculo, numVehiculos, &vec, &x, num_user); //encuentra los vehiculos del usuario

    if(vec!=NULL)
    { //verifica que el usuario tiene vehiculos
        printf("LISTADO DE SUS VEHICULOS:\n");
        for(i=0;i<x;i++)
        {
            color(15, 0);
            printf("VEHICULO %i:\n",i+1);
            color(0, 3);
            printf("   Matricula: ");
            color(0, 15);
            printf("%s\n", vehiculo[vec[i]].id_mat);
            color(0, 3);
            printf("   Numero de plazas: ");
            color(0, 15);
            printf("%s\n", vehiculo[vec[i]].num_plazas);
            color(0, 3);
            printf("   Descripcion: ");
            color(0, 15);
            printf("%s\n\n", vehiculo[vec[i]].desc_veh);
        }
    }
    else
    {
        printf("No tiene vehiculos registrados.\n\n");
    }
}

//Cabecera: void listarViajes(Estr_Usuario *, Estr_Vehiculo *, int, Estr_Viaje *, int, int);
//Precondicion: Tener las estructuras inicializadas, con sus contadores. Ademas, se necesita la variable "num_user", para saber a que usuario nos referimos.
//Postcondicion: Imprimir una lista con todos los viajes abiertos e iniciados que tiene un usuario.

void listarViajes(Estr_Usuario *usuario, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, int num_user)
{
    int *vec=NULL, *vec_coche=NULL, x=0, j, i, y=0;

    encontrarVehiculos(usuario, vehiculo, numVehiculos, &vec_coche, &x, num_user); //Encuentra todos los vehiculos del usuario.
    if(vec_coche!=NULL)
    {
        for(j=0;j<x;j++)
        {
            encontrarViajes(vehiculo, numVehiculos, viaje, numViajes, vehiculo[vec_coche[j]].id_mat, &vec, &y, 3); //Encuentra todos los viajes abiertos, que no tienen plazas ocupadas, del usuario.
        }

        if(vec!=NULL)
        { //verifica que el usuario tiene reservas
            printf("LISTADO DE SUS VIAJES:\n");
            for(i=0;i<y;i++)
            {
                color(15, 0);
                printf("VIAJE %i:\n",i+1);
                color(0, 3);
                printf("   ID del viaje: ");
                color(0, 15);
                printf("%s\n", viaje[vec[i]].id_viaje);
                color(0, 3);
                printf("   Matricula: ");
                color(0, 15);
                printf("%s\n", viaje[vec[j]].id_mat);
                color(0, 3);
                printf("   Estado: ");
                color(0, 15);
                printf("%s\n", viaje[vec[i]].estado);
                color(0, 3);
                printf("   Plazas libres: ");
                color(0, 15);
                printf("%s\n", viaje[vec[i]].plazas_libre);
                color(0, 3);
                printf("   Fecha de partida: ");
                color(0, 15);
                printf("%s\n", viaje[vec[i]].f_inic);
                color(0, 3);
                printf("   Hora de partida: ");
                color(0, 15);
                printf("%s\n", viaje[vec[i]].h_inic);
                color(0, 3);
                printf("   Hora de llegada: ");
                color(0, 15);
                printf("%s\n", viaje[vec[i]].h_fin);
                color(0, 3);
                printf("   Tipo: ");
                color(0, 15);
                printf("%s\n", viaje[vec[i]].ida_vuelta);
                color(0, 3);
                printf("   Precio: ");
                color(0, 15);
                printf("%s euros\n\n", viaje[vec[i]].precio);
            }
        }
        else
        {
            printf("No tiene viajes registrados.\n\n");
        }
    }
    else
    {
        printf("No tiene ni vehiculos ni viajes registrados.\n\n");
    }
}


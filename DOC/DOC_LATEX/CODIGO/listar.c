#include "listar.h"

//Prototipo: void listarUsuarios(Estr_Usuario *, int);
//Precondicion: Tener la estructura "usuario" inicializada, junto a su contador.
//Postcondicion: Dar una lista de todos los usuarios, que hay en la base de datos.

void listarUsuarios(Estr_Usuario *usuario, int numUsuarios)
{
    int counter;

    leer_usuario(&usuario, &numUsuarios); //Lee la estructura "usuario", por si ha habido algun cambio.
    system("cls");

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

//Prototipo: void listarVehiculos(Estr_Usuario *, int, Estr_Vehiculo *, int, int);
//Precondicion: Tener la estructura "usuario" y "vehiculo" inicializadas, junto a sus contadores.
//Postcondicion: Dar una lista de todos los vehiculos, de cada usuario, que hay en la base de datos.

void listarVehiculos(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, int i)
{
    int contador_veh_usuario, counter, counter2;

    leer_usuario(&usuario, &numUsuarios); //Lee las estructuras, por si ha habido algun cambio en ellas.
    leer_vehiculo(&vehiculo, &numVehiculos);
    system("cls");

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
                    printf(" | Num de plazas: ");
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

//Prototipo: void listarAdminViajes(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, int, int);
//Precondicion: Tener la estructura "usuario", "vehiculo" y "viaje" inicializadas, junto a sus contadores.
//Postcondicion: Si n=0, da una lista de todos los viajes, de cada usuario, que hay en la base de datos, y si n=1, da una lista de los viajes abiertos que hay de cada usuario.

void listarAdminViajes(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, int i, int n, int *num)
{
    int contador_viaje, *vec=NULL, *vec_viaje=NULL, num_v, m, j, id, counter;

    leer_usuario(&usuario, &numUsuarios); //Lee las estructuras, por si ha habido algun cambio en ellas.
    leer_vehiculo(&vehiculo, &numVehiculos);
    leer_viaje(&viaje, &numViajes);
    system("cls");

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

//Prototipo: void listarAdminVehiculoViajes(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, int);
//Precondicion: Tener la estructura "usuario", "vehiculo" y "viaje" inicializadas, con sus contadores.
//Postcondicion: Dar una lista de todos los viajes que ha realizado un vehiculo.

void listarAdminVehiculoViajes(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, int i)
{
    FILE *fp;
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

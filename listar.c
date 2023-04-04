#include "listar.h"

void listarUsuarios()
{
    int contador_usuario=0, counter;

    leer_usuario(&usuario, &numUsuarios);

    system("cls");
    printf("LISTADO DE USUARIOS:\n");
    for(counter=0;counter<numUsuarios;counter++){
        color(0,14);
        printf("    Usuario %i:\n", (contador_usuario)+1);
        color(0,3);
        printf("    ID: ");
        color(0,15);
        printf("%s", usuario[contador_usuario].id_usuario);
        color(0,3);
        printf(" | Nombre de usuario: ");
        color(0,15);
        printf("%s", usuario[contador_usuario].nomb_usuario);
        color(0,3);
        printf(" | Localidad: ");
        color(0,15);
        printf("%s", usuario[contador_usuario].localidad);
        color(0,3);
        printf(" | Perfil: ");
        color(0,15);
        printf("%s", usuario[contador_usuario].perfil);
        color(0,3);
        printf(" | Usuario: ");
        color(0,15);
        printf("%s\n", usuario[contador_usuario].usuario);
        contador_usuario++;
    }
    if(contador_usuario==0)
    {
        color(0,3);
        printf("    No hay usuarios registrados.\n");
    }

color(0,15);
system("PAUSE");
}

void listarVehiculos(int i, int n)
{
    int contador_veh_usuario, counter, counter2, num=0;

    leer_vehiculo(&vehiculo, &numVehiculos);

    system("cls");
    printf("LISTADO DE VEHICULOS:\n");
    for(counter=0;counter<numUsuarios;counter++){
        contador_veh_usuario=0;
        color(0,14);
        printf("> Vehiculos de %s | ID: %s\n",usuario[counter].nomb_usuario,usuario[counter].id_usuario);
            for(counter2=0;counter2<numVehiculos;counter2++){
                if(strcmp(usuario[counter].id_usuario,vehiculo[counter2].id_usuario)==0){
                    color(0,3);
                    printf("    Vehiculo %i:    Matricula: %s | Numero de plazas: %s | Descripcion: %s\n",(contador_veh_usuario)+1,vehiculo[counter2].id_mat,vehiculo[counter2].num_plazas,vehiculo[counter2].desc_veh);
                    contador_veh_usuario++;
                    num=1;
                }
            }
            if(contador_veh_usuario==0){
                color(0,3);
                printf("    No posee vehiculos registrados.\n");
            }
        }

    if(num==0)
    {
        color(0, 15);
        printf("Ningún usuario del sistema tiene un viaje, con las características requeridas.\n");
        system("PAUSE");
        if(n==0)
        {
            menuConductorVehiculo(i);
        }
        else
        {
            menuAdminVehiculos(i);
        }
    }
    else
    {
        color(0,15);
        system("PAUSE");
    }
}

void listarAdminViajes(int i, int n)
{
    int contador_viaje, *vec=NULL, *vec_viaje=NULL, num_v, m, j, id, counter, num=0;

    leer_viaje(&viaje, &numViajes);

    system("cls");
    printf("LISTADO DE VIAJES:\n");
    for(counter=0;counter<numUsuarios;counter++){
        color(0,14);
        printf("> Viajes de %s | ID: %s\n",usuario[counter].nomb_usuario,usuario[counter].id_usuario);
        id=atoi(usuario[counter].id_usuario);
        id--;
        encontrarVehiculos(&vec, &num_v, id);
        if(num_v!=0)
        {
            for(j=0;j<num_v;j++)
            {
                encontrarViajes(vehiculo[vec[j]].id_mat, &vec_viaje, &contador_viaje, n);
            }

            for(m=0; m<contador_viaje; m++)
            {
                color(0,3);
                printf("    Viaje %i:    ID: %s | Matricula: %s | Fecha de partida: %s | Hora de partida: %s |\n                Hora de llegada: %s | Plazas libres: %s | Ida/Vuelta: %s | Precio: %s | Estado: %s\n\n",m+1,viaje[vec_viaje[m]].id_viaje,viaje[vec_viaje[m]].id_mat,viaje[vec_viaje[m]].f_inic,viaje[vec_viaje[m]].h_inic,viaje[vec_viaje[m]].h_fin,viaje[vec_viaje[m]].plazas_libre,viaje[vec_viaje[m]].ida_vuelta,viaje[vec_viaje[m]].precio,viaje[vec_viaje[m]].estado);
                num=1;
            }
            if(contador_viaje==0)
            {
                color(0,3);
                printf("    No posee viajes registrados.\n");
            }
        }
        else
        {
            color(0,3);
            printf("    No posee vehiculos ni viajes registrados.\n");
        }
    }

    if(num==0)
    {
        color(0, 15);
        printf("Ningún usuario del sistema tiene un viaje, con las características requeridas.\n");
        system("PAUSE");
        menuAdminViajes(i);
    }
    else
    {
        color(0,15);
        system("PAUSE");
    }
}

void listarAdminVehiculoViajes(int i)
{
    FILE *fp;
    int x=0, m=0, z=0, encontrado=0, *vec=NULL;
    char mat[8];

    fp=fopen("viajes.txt","r+");

    if(fp==NULL) {
        printf("No se ha podido abrir el fichero viajes.txt.\n");
        return;
    }
    else
    {
        while(encontrado==0)
        {
            listarVehiculos(i, 1);
            printf("Introduzca la matrícula de un vehículo para obtener los viajes que ha realizado.\n");
            pregunta(mat, 8);

            for(z=0;z<numVehiculos;z++)
            {
               if(strcmp(vehiculo[z].id_mat, mat)==0)
                {
                    encontrado=1;
                }
            }
            printf("El vehiculo con matricula %s no existe.\n", mat);
            system("PAUSE");
            system("cls");
        }
        encontrarViajes(mat, &vec, &x, 0);

        printf("Los viajes realizados por el vehículo con matrícula %s son:\n", mat);
        for(m=0; m<x; m++)
        {
            printf("(%i)%s-%s-%s-%s-%s-%s-%s-%s-%s\n", m+1, viaje[vec[m]].id_viaje, viaje[vec[m]].id_mat, viaje[vec[m]].f_inic, viaje[vec[m]].h_inic, viaje[vec[m]].h_fin, viaje[vec[m]].plazas_libre, viaje[vec[m]].ida_vuelta, viaje[vec[m]].precio, viaje[vec[m]].estado);
        }
        system("PAUSE");
    }
}

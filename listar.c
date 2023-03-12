#include "listar.h"

void listarUsuarios()
{
    int i;

    printf("Lista de todos los usuarios existentes en la base de datos:\n");

    leer_usuario(&usuario, &numUsuarios);

    for(i=0; i<numUsuarios; i++)
    {
        printf("%s-%s-%s-%s-%s-%s\n", usuario[i].id_usuario, usuario[i].nomb_usuario, usuario[i].localidad, usuario[i].perfil, usuario[i].usuario, usuario[i].contrasena);
    }
}

void listarVehiculos()
{
    int i;

    printf("Lista de todos los vehiculos existentes en la base de datos:\n");

    leer_vehiculo(&vehiculo, &numVehiculos);

    for(i=0; i<numVehiculos; i++)
    {
        printf("%s-%s-%s-%s\n", vehiculo[i].id_mat, vehiculo[i].id_usuario, vehiculo[i].num_plazas, vehiculo[i].desc_veh);
    }
}

void listarAdminVehiculoViajes()
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
            listarVehiculos();
            printf("Introduzca la matrícula de un vehículo para obtener los viajes que ha realizado.\n");
            pregunta(mat, 8);

            for(z=0;z<numVehiculos;z++)
            {
               if(strcmp(vehiculo[z].id_mat, mat)==0)
                {
                    encontrado=1;
                }
            }
            system("cls");
        }
        encontrarViajes(mat, &vec, &x);

        printf("Los viajes realizados por el vehículo con matrícula %s son:\n", mat);
        for(m=0; m<x; m++)
        {
            printf("(%i)%s-%s-%s-%s-%s-%s-%s-%s-%s\n", m+1, viaje[vec[m]].id_viaje, viaje[vec[m]].id_mat, viaje[vec[m]].f_inic, viaje[vec[m]].h_inic, viaje[vec[m]].h_fin, viaje[vec[m]].plazas_libre, viaje[vec[m]].ida_vuelta, viaje[vec[m]].precio, viaje[vec[m]].estado);
        }
        system("PAUSE");
    }
}

void listarVehiculoViajes(int i)  //hacer esto
{
    FILE *fp;
    int n=0, x=0, h=0, m=0, opc=0, k=0, opc2=0, *vec=NULL, encontrado=0;

    fp=fopen("viajes.txt","r+");

    if(fp==NULL) {
        printf("No se ha podido abrir el fichero viajes.txt.\n");
        return;
    }
    else {
        encontrarVehiculos(&vec, &x, i);

        printf("¿Qué vehículo quiere modificar?\n");

        for(m=0; m<x; m++)
        {
            printf("(%i)%s-%s-%s\n", m+1, vehiculo[vec[m]].id_mat, vehiculo[vec[m]].num_plazas, vehiculo[vec[m]].desc_veh);
        }
        x++;
        printf("(%i)Salir.\n", x);
        printf("Ingrese el número correspondiente al vehículo que desea modificar: ");
        fflush(stdin);
        scanf("%d", &opc);
        system("cls");

        }
        }

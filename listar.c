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

system("PAUSE");
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

system("PAUSE");
}

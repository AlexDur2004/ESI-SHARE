#include "actualizar.h"

//Cabecera: void actualizarUsuario(Estr_Usuario *, int);
//Precondicion: Tener la estructura "usuario" inicializada, con su contador.
//Postcondicion: Reescribir todos los datos de la estructura en el fichero.

void actualizarUsuario(Estr_Usuario *usuario, int numUsuarios)
{
    int n=0;
    FILE *fp;
    fp=fopen("DATA/usuarios.txt","w+"); //Abrimos el fichero, para actualizarlo desde cero.

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero usuarios.txt");
    }
    else
    {
        for(n=0;n<numUsuarios;n++) //Escribimos toda la estructura usuario en el fichero.
        {
            fprintf(fp, "%s-%s-%s-%s-%s-%s\n", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
        }
    }

    fclose(fp);
}

//Cabecera: void actualizarVehiculo(Estr_Vehiculo *, int);
//Precondicion: Tener la estructura "vehiculo" inicializada, con su contador.
//Postcondicion: Reescribir todos los datos de la estructura en el fichero.

void actualizarVehiculo(Estr_Vehiculo *vehiculo, int numVehiculos)
{
    int n=0;
    FILE *fp;
    fp=fopen("DATA/vehiculos.txt","w+"); //Abrimos el fichero, para actualizarlo desde cero.

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero vehiculos.txt");
    }
    else
    {
        for(n=0;n<numVehiculos;n++) //Escribimos toda la estructura vehiculo en el fichero.
        {
            fprintf(fp, "%s-%s-%s-%s\n", vehiculo[n].id_mat, vehiculo[n].id_usuario, vehiculo[n].num_plazas, vehiculo[n].desc_veh);
        }
    }

    fclose(fp);
}

//Cabecera: void actualizarViaje(Estr_Viaje *, int);
//Precondicion: Tener la estructura "viaje" inicializada, con su contador.
//Postcondicion: Reescribir todos los datos de la estructura en el fichero.

void actualizarViaje(Estr_Viaje *viaje, int numViajes)
{
    int n=0;
    FILE *fp;
    fp=fopen("DATA/viajes.txt","w+"); //Abrimos el fichero, para actualizarlo desde cero.

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero viajes.txt");
    }
    else
    {
        for(n=0;n<numViajes;n++) //Escribimos toda la estructura viaje en el fichero.
        {
            fprintf(fp, "%s-%s-%s-%s-%s-%s-%s-%s-%s\n", viaje[n].id_viaje,viaje[n].id_mat,viaje[n].f_inic,viaje[n].h_inic,viaje[n].h_fin,viaje[n].plazas_libre,viaje[n].ida_vuelta,viaje[n].precio,viaje[n].estado);
        }
    }

    fclose(fp);
}

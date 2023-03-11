#include "escribir.h"

void altaUsuario()
{
    FILE *fp;
    int n=0, idmax=0;
    char id[5], nombre[21], localidad[21], perfil[14], usuario2[6], contrasena[9];

    fp=fopen("usuarios.txt","r+");

    strcpy(perfil, "usuario"); //copia la palabra "usuario" en el vector perfil, s�lo habr� 1 administrador.
    printf("Introduzca sus datos para completar el registro:\n");
    printf("Nombre Completo (M�ximo de 20 caracteres):\n");
    pregunta(nombre, 21);
    printf("Localidad de residencia (Siglas de la lista)):\n");
    pregunta_localidad(localidad);
    printf("Nombre de usuario (M�ximo de 5 caracteres):\n");
    pregunta(usuario2, 6);
    printf("Contrase�a (M�ximo de 8 caracteres):\n");
    pregunta(contrasena, 9);

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero usuarios.txt.\n");
        return;
    }
    else
    {
        do{
            fprintf(fp, "%s-%s-%s-%s-%s-%s\n", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
            n++;
        }while(n<numUsuarios-1);
        fprintf(fp, "%s-%s-%s-%s-%s-%s\n", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
        numUsuarios++;

        idmax=atoi(usuario[n].id_usuario); //convierte la id del �ltimo usuario en entero.
        idmax++; //suma una posici�n a la id del �ltimo usuario, para hacer la nueva id.
        snprintf(id, sizeof(id), "%04d", idmax); //pasa la id nueva a un vector limitado por 4 espacios.

        fprintf(fp, "%s-%s-%s-%s-%s-%s", id, nombre, localidad, perfil, usuario2, contrasena);
        numUsuarios++;
    }

    fclose(fp);

    leer_usuario(&usuario,&numUsuarios);

    return;
}

void altaVehiculo(int i)
{
    FILE *fp;
    int n=0;
    char mat[8], plazas[2], descrip[51];

    fp=fopen("vehiculos.txt","r+");

    printf("Introduzca los datos de su veh�culo para completar su registro:\nMatr�cula del veh�culo (M�ximo de 7 caracteres):\n");
    pregunta(mat, 8);
    printf("N�mero de plazas libres (sin contar el conductor):\n");
    pregunta(plazas, 2);
    printf("Descripci�n del veh�culo (Marca, modelo, color, etc) (M�ximo de 50 caracteres):\n");
    pregunta(descrip, 51);

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else
    {

        do{
            fprintf(fp, "%s-%s-%s-%s\n", vehiculo[n].id_mat, vehiculo[n].id_usuario, vehiculo[n].num_plazas, vehiculo[n].desc_veh);
                n++;
        }while(n<numVehiculos-1);
        fprintf(fp, "%s-%s-%s-%s\n", vehiculo[n].id_mat, vehiculo[n].id_usuario, vehiculo[n].num_plazas, vehiculo[n].desc_veh);
        numVehiculos++;
        fprintf(fp, "%s-%s-%s-%s", mat, usuario[i].id_usuario, plazas, descrip);
        numVehiculos++;
    }

    fclose(fp);

    leer_vehiculo(&vehiculo,&numVehiculos);

    return;
}

void escribir_Viaje(int i)
{
    FILE *fp;
    int n=0;
    char fecha[9];

    fp=fopen("viajes.txt","r+");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero viajes.txt.\n");
        return;
    }
    else
    {
        do{
            fprintf(fp, "%s-%s-%s-%s-%s-%s-%s-%f-%s\n", viaje[n].id_viaje, viaje[n].id_mat, viaje[n].f_inic, viaje[n].h_inic, viaje[n].h_fin, viaje[n].plazas_libre, viaje[n].ida_vuelta, viaje[n].precio, viaje[n].estado);
            n++;
        }while(n<numViajes-1);
        fprintf(fp, "%s-%s-%s-%s-%s-%s-%s-%f-%s", viaje[n].id_viaje, viaje[n].id_mat, viaje[n].f_inic, viaje[n].h_inic, viaje[n].h_fin, viaje[n].plazas_libre, viaje[n].ida_vuelta, viaje[n].precio, viaje[n].estado);
        numViajes++;
    }

    fclose(fp);

    leer_viaje(&viaje,&numViajes);

    return;
}

void escribir_Pasos(int i)
{
    FILE *fp;
    int n=0;

    fp=fopen("pasos.txt","r+");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero pasos.txt.\n");
        return;
    }
    else
    {
        do{
            fprintf(fp, "%s-%s\n", pasos[n].id_viaje, pasos[n].poblacion);
            n++;
        }while(n<numPasos-1);
        fprintf(fp, "%s-%s", pasos[n].id_viaje, pasos[n].poblacion);
        numPasos++;
    }

    fclose(fp);

    leer_pasos(&pasos,&numPasos);

    return;
}

#include "escribir.h"

void altaUsuario()
{
    FILE *fp;
    int n=0, idmax=0, k=0, encontrado=0, preg=0;
    char id[5], nombre[21], localidad[21], perfil[14], usuario2[6], contrasena[9];

    fp=fopen("usuarios.txt","r+");

    strcpy(perfil, "usuario"); //copia la palabra "usuario" en el vector perfil, sólo habrá 1 administrador.
    printf("Introduzca sus datos para completar el registro:\n");
    printf("Nombre Completo (Máximo de 20 caracteres):\n");
    pregunta(nombre, 21);
    printf("Localidad de residencia (Siglas de la lista):\n");
    pregunta_localidad(localidad);
    printf("Nombre de usuario (Máximo de 5 caracteres):\n");
    pregunta(usuario2, 6);
    for(k=0; k<numUsuarios&&encontrado==0; k++)
    {
        if(strcmp(usuario2, usuario[k].usuario)==0)
        {
            encontrado=1;
        }
    }
    if(encontrado==0)
    {
        printf("El nombre de usuario es válido.\n");
        printf("Contraseña (Máximo de 8 caracteres):\n");
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

            idmax=atoi(usuario[n].id_usuario); //convierte la id del último usuario en entero.
            idmax++; //suma una posición a la id del último usuario, para hacer la nueva id.
            snprintf(id, sizeof(id), "%04d", idmax); //pasa la id nueva a un vector limitado por 4 espacios.

            fprintf(fp, "%s-%s-%s-%s-%s-%s", id, nombre, localidad, perfil, usuario2, contrasena);
            numUsuarios++;

            printf("El usuario ha sido agregado correctamente.\n");
            system("PAUSE");

            while(preg!=1||preg!=2)
            {
                system("cls");
                printf("¿Que quiere hacer?\n(1)Iniciar sesion.\n(2)Salir.\n");
                scanf("%1i", &preg);
                if(preg==1)
                {
                    system("cls");
                    acceso(usuario, numUsuarios);
                }
                else
                {
                    menuPrincipal();
                }
            }
        }
    }
    else
    {
        printf("El nombre de usuario ya está siendo usado.\n");
        system("PAUSE");
    }

    fclose(fp);

    leer_usuario(&usuario,&numUsuarios);

}

void altaVehiculo(int i)
{
    FILE *fp;
    int n=0, k, encontrado=0;
    char mat[8], plazas[2], descrip[51];

    fp=fopen("vehiculos.txt","r+");

    printf("Introduzca los datos de su vehículo para completar su registro:\n");
    printf("Matrícula del vehículo (Máximo de 7 caracteres):\n");
    pregunta(mat, 8);

    for(k=0; k<numVehiculos&&encontrado==0; k++)
    {
        if(strcmp(mat, vehiculo[k].id_mat)==0)
        {
            encontrado=1;
        }
    }

    if(encontrado==0)
    {
        printf("La matrícula es válida.\n");
        printf("Número de plazas libres (sin contar el conductor):\n");
        pregunta(plazas, 2);
        printf("Descripción del vehículo (Marca, modelo, color, etc) (Máximo de 50 caracteres):\n");
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
    }
    else
    {
        printf("La matrícula introducida ya existe en otro vehículo.\n");
        system("PAUSE");
    }

    fclose(fp);

    leer_vehiculo(&vehiculo,&numVehiculos);

    return;
}

void altaViaje(int i)
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
            fprintf(fp, "%s-%s-%s-%s-%s-%s-%s-%s-%s\n", viaje[n].id_viaje, viaje[n].id_mat, viaje[n].f_inic, viaje[n].h_inic, viaje[n].h_fin, viaje[n].plazas_libre, viaje[n].ida_vuelta, viaje[n].precio, viaje[n].estado);
            n++;
        }while(n<numViajes-1);
        fprintf(fp, "%s-%s-%s-%s-%s-%s-%s-%s-%s", viaje[n].id_viaje, viaje[n].id_mat, viaje[n].f_inic, viaje[n].h_inic, viaje[n].h_fin, viaje[n].plazas_libre, viaje[n].ida_vuelta, viaje[n].precio, viaje[n].estado);
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

void altaAdminVehiculo()
{
    int i, encontrado=0;
    char id_us[5];

    while(encontrado==0)
    {
        printf("Introduzca la ID del usuario al que quiere darle de alta el vehículo.\n");
        pregunta(id_us, 5);
        for(i=0; i<numUsuarios&&encontrado==0; i++)
        {
            if(strcmp(usuario[i].id_usuario, id_us)==0)
            {
                encontrado=1;
            }
        }
        system("cls");
    }
    altaVehiculo(i-1);
    printf("El vehículo se ha agregado correctamente al usuario %s, con ID %s.\n", usuario[i-1].nomb_usuario, usuario[i-1].id_usuario);
    system("PAUSE");
}

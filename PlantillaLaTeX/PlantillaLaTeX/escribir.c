#include "escribir.h"

void altaUsuario()
{
    FILE *fp;
    int i=0, n=1, idmax=0, k=0, encontrado=0, encontrado2=0, encontrado3=0, preg=0;
    char id[5], nombre[21], localidad[21], perfil[14], usuario2[6], contrasena[9];

    fp=fopen("usuarios.txt","a+");

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
            while(encontrado2==0)
            {
                for(i=0;i<numUsuarios && encontrado3==0;i++)
                {
                    idmax=atoi(usuario[i].id_usuario);
                    if(n==idmax)
                        encontrado3=1;
                }
                if(encontrado3==1)
                {
                    n++;
                    encontrado3=0;
                }
                else
                {
                    encontrado2=1;
                }
            }

            snprintf(id, sizeof(id), "%04d", n); //pasa la id nueva a un vector limitado por 7 espacios.

            fprintf(fp, "%s-%s-%s-%s-%s-%s\n", id, nombre, localidad, perfil, usuario2, contrasena);

            printf("El usuario ha sido agregado correctamente.\n");
            system("PAUSE");
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
    int n=0,error_mat, counter2=0, counter;
    char mat[8], plazas[2], descrip[51];

    fp=fopen("vehiculos.txt","a+");

    do{
        error_mat=0;
        system("cls");
        printf("Introduzca los datos de su vehículo para completar su registro:\nMatrícula del vehículo (Máximo de 7 caracteres):\n");
        fflush(stdin);
        scanf("%7s", mat);
        for(counter=0;(counter<numVehiculos)&&(error_mat==0);counter++){
            if(strcmp(mat,vehiculo[counter].id_mat)==0){
                error_mat=1;
                system("cls");
                printf("La matricula %s esta actualmente registrada.\n",mat);
                system("PAUSE");
            }
        }
        if(strlen(mat)<7){
            system("cls");
            printf("La matricula debe poseer una longitud total de 7 caracteres.\n",mat);
            system("PAUSE");
        }
        for(counter=0;(counter<4)&&(error_mat==0);counter++){
            if((mat[counter]<48)||(mat[counter]>57)){
                error_mat=1;
                printf("Los 4 primeros caracteres de la matricula tienen que ser numeros.\n");
                system("PAUSE");
            }
        }
        for(counter=4;(counter<7)&&(error_mat==0);counter++){
            if((mat[counter]<65)||(mat[counter]>90)){
                error_mat=1;
                printf("Los 3 ultimos caracteres de la matricula tienen que ser letras mayusculas.\n");
                system("PAUSE");
            }
        }
    }while((error_mat==1)||(strlen(mat)<7));

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
        fprintf(fp, "%s-%s-%s-%s\n", mat, usuario[i].id_usuario, plazas, descrip);
        numVehiculos++;
    }

    fclose(fp);

    leer_vehiculo(&vehiculo,&numVehiculos);

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
    char opc2[4];
    int encontrado=0, i=0, counter;

    system("cls");
    listarUsuarios();
    printf("Escriba la ID del usuario al que quiera dar de alta el vehiculo.\n");
    scanf("%4s",&opc2);
    for(counter=0;(counter<numUsuarios)&&(encontrado==0);counter++){
        if(strcmp(opc2,usuario[counter].id_usuario)==0){
            encontrado=1;
            i=counter;
            altaVehiculo(i);
            printf("El vehículo se ha agregado correctamente al usuario %s, con ID %s.\n", usuario[counter].nomb_usuario, usuario[counter].id_usuario);
            system("PAUSE");
        }
    }
    if(encontrado==0){
        system("cls");
        printf("No se ha encontrado ningun usuario con la siguiente ID: %s\n",opc2);
        system("PAUSE");
    }
}

void altaAdminViaje()
{
    char opc2[4];
    int encontrado=0, i=0, counter;

    system("cls");
    listarUsuarios();
    printf("Escriba la ID del usuario al que quiera dar de alta el viaje.\n");
    scanf("%4s",&opc2);
    for(counter=0;(counter<numUsuarios)&&(encontrado==0);counter++){
        if(strcmp(opc2,usuario[counter].id_usuario)==0){
            encontrado=1;
            i=counter;
            altaViaje(i, 1);
            printf("El viaje se ha agregado correctamente al usuario %s, con ID %s.\n", usuario[counter].nomb_usuario, usuario[counter].id_usuario);
            system("PAUSE");
        }
    }
    if(encontrado==0){
        system("cls");
        printf("No se ha encontrado ningun usuario con la siguiente ID: %s\n",opc2);
        system("PAUSE");
    }
}

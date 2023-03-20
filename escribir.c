#include "escribir.h"

void altaUsuario()
{
    FILE *fp;
    int n=0, idmax=0, k=0, encontrado=0, preg=0;
    char id[5], nombre[21], localidad[21], perfil[14], usuario2[6], contrasena[9];

    fp=fopen("usuarios.txt","r+");

    strcpy(perfil, "usuario"); //copia la palabra "usuario" en el vector perfil, s�lo habr� 1 administrador.
    printf("Introduzca sus datos para completar el registro:\n");
    printf("Nombre Completo (M�ximo de 20 caracteres):\n");
    pregunta(nombre, 21);
    printf("Localidad de residencia (Siglas de la lista):\n");
    pregunta_localidad(localidad);
    printf("Nombre de usuario (M�ximo de 5 caracteres):\n");
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
        printf("El nombre de usuario es v�lido.\n");
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

            printf("El usuario ha sido agregado correctamente.\n");
            system("PAUSE");
        }
    }
    else
    {
        printf("El nombre de usuario ya est� siendo usado.\n");
        system("PAUSE");
    }

    fclose(fp);

    leer_usuario(&usuario,&numUsuarios);

}

void altaVehiculo(int i)
{
    FILE *fp;
    int n=0,error_mat, counter2=0;
    char mat[8], plazas[2], descrip[51];

    fp=fopen("vehiculos.txt","a+");

    do{
        error_mat=0;
        system("cls");
        printf("Introduzca los datos de su veh�culo para completar su registro:\nMatr�cula del veh�culo (M�ximo de 7 caracteres):\n");
        fflush(stdin);
        scanf("%7s", mat);
        for(int counter=0;(counter<numVehiculos)&&(error_mat==0);counter++){
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
        for(int counter=0;(counter<4)&&(error_mat==0);counter++){
            if((mat[counter]<48)||(mat[counter]>57)){
                error_mat=1;
                printf("Los 4 primeros caracteres de la matricula tienen que ser numeros.\n");
                system("PAUSE");
            }
        }
        for(int counter=4;(counter<7)&&(error_mat==0);counter++){
            if((mat[counter]<65)||(mat[counter]>90)){
                error_mat=1;
                printf("Los 3 ultimos caracteres de la matricula tienen que ser letras mayusculas.\n");
                system("PAUSE");
            }
        }
    }while((error_mat==1)||(strlen(mat)<7));
    do{
        printf("N�mero de plazas libres (sin contar el conductor):\n");
        fflush(stdin);
        scanf("%1s", plazas);
        system("cls");
        printf("Introduzca los datos de su veh�culo para completar su registro:\nMatr�cula del veh�culo (M�ximo de 7 caracteres):\n");
        printf("%s\n", mat);
    }while((plazas[counter2]<48)||(plazas[counter2]>57));

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
        fprintf(fp, "%s-%s-%s-%s\n", mat, usuario[i].id_usuario, plazas, descrip);
        numVehiculos++;
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
    char opc2[4];
    int encontrado=0, i=0;

    system("cls");
    listarUsuarios();
    printf("Escriba la ID del usuario a la que se quiera dar de alta el veh�culo\n");
    scanf("%4s",&opc2);
    for(int counter=0;(counter<numUsuarios)&&(encontrado==0);counter++){
        if(strcmp(opc2,usuario[counter].id_usuario)==0){
            encontrado=1;
            i=counter;
            altaVehiculo(i);
            printf("El veh�culo se ha agregado correctamente al usuario %s, con ID %s.\n", usuario[counter].nomb_usuario, usuario[counter].id_usuario);
            system("PAUSE");
        }
    }
    if(encontrado==0){
        system("cls");
        printf("No se ha encontrado ningun usuario con la siguiente ID: %s\n",opc2);
        system("PAUSE");
    }
}

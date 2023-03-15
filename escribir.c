#include "escribir.h"

void altaUsuario()
{
    FILE *fp;
    int n=0, idmax=0,encontrado;
    char id[5], nombre[21], localidad[21], perfil[14], usuario2[6], contrasena[9];

    fp=fopen("usuarios.txt","a+");

    strcpy(perfil, "usuario"); //copia la palabra "usuario" en el vector perfil, sólo habrá 1 administrador.
    printf("Introduzca sus datos para completar el registro:\nNombre Completo (Máximo de 20 caracteres):\n");
    fflush(stdin);
    scanf("%20s", nombre);
    printf("Localidad de residencia (Siglas de la lista)):\n");
    pregunta_localidad(localidad);
    do{
        encontrado=0;
        printf("Nombre de usuario (Máximo de 5 caracteres):\n");
        fflush(stdin);
        scanf("%5s", usuario2);
        for(int counter=0;(counter<numUsuarios)&&(encontrado=0);counter++){ //se encarga de que no se repitan usuarios
            if(strcmp(usuario2,usuario[counter].usuario)==0){
                encontrado=1;
                system("cls");
                printf("Nombre de usuario actualmente en uso\n");
                system("PAUSE");
            }
        }
    }while(encontrado==1);
        printf("Contrasena (Máximo de 8 caracteres):\n");
        fflush(stdin);
        scanf("%8s", contrasena);
        contrasena[(strlen(contrasena))-1]='\0';

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero usuarios.txt.\n");
        return;
    }
    else
    {
        fprintf(fp, "%s-%s-%s-%s-%s-%s\n", id, nombre, localidad, perfil, usuario2, contrasena);
        numUsuarios++;
    }

    fclose(fp);
    system("cls");
    printf("Se ha agregado el usuario correctamente\n ");
    system("PAUSE");

    leer_usuario(&usuario,&numUsuarios);

    return;
}
void altaVehiculo(int i)
{
    FILE *fp;
    int n=0,error_mat;
    char mat[8], plazas[2], descrip[51];

    fp=fopen("vehiculos.txt","a+");

    do{
        error_mat=0;
        system("cls");
        printf("Introduzca los datos de su vehículo para completar su registro:\nMatrícula del vehículo (Máximo de 7 caracteres):\n");
        fflush(stdin);
        scanf("%7s", mat);
        for(int counter=0;(counter<numVehiculos)&&(error_mat==0);counter++){
            if(strcmp(mat,vehiculo[counter].id_mat)==0){
                error_mat=1;
                system("cls");
                printf("Esta matricula esta actualmente registrada: %s\n",mat);
                system("PAUSE");
            }
        }
        if(strlen(mat)<7){
            system("cls");
            printf("La matricula debe poseer una longitud total de 7 caracteres\n",mat);
            system("PAUSE");
        }
        for(int counter=0;(counter<4)&&(error_mat==0);counter++){
            if((mat[counter]<48)||(mat[counter]>57)){
                error_mat=1;
                printf("Los 4 primeros caracteres de la matricula tienen que ser numeros\n");
                system("PAUSE");
            }
        }
        for(int counter=4;(counter<7)&&(error_mat==0);counter++){
            if((mat[counter]<65)||(mat[counter]>90)){
                error_mat=1;
                printf("Los 3 ultimos caracteres de la matricula tienen que ser letras mayusculas\n");
                system("PAUSE");
            }
        }
    }while((error_mat==1)||(strlen(mat)<7));
    printf("Número de plazas libres (sin contar el conductor):\n");
    fflush(stdin);
    scanf("%1s", plazas);
    printf("Descripción del vehículo (Marca, modelo, color, etc) (Máximo de 50 caracteres):\n");
    fflush(stdin);
    fgets(descrip,50,stdin);
    descrip[(strlen(descrip))-1]='\0';
    fflush(stdin);

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

void escribir_Viaje(int i)
{
    FILE *fp;
    int n=0;
    char fecha[9];

    fp=fopen("viajes.txt","a+");

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

    fp=fopen("pasos.txt","a+");

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

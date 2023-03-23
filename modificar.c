#include "modificar.h"

void modificarVehiculo(int i)
{
    FILE *fp;
    int n=0, x=0, h=0, m=0, opc=0, k=0, opc2=0, aux=0, y=0, *vec=NULL, encontrado=0, encontrado2=0;
    char mat[8], plazas[2], descrip[51];

    fp=fopen("vehiculos.txt","r+");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else
    {
        encontrarVehiculos(&vec, &x, i);
        aux=x;
        while(encontrado==0)
        {
            x=aux;
            y=aux;
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
            if(opc==x)
            {
                return;
            }
            for(m=1; m<y; m++)
            {
                if(opc==vec[m-1])
                {
                    encontrado=1;
                }
            }

        if((opc>=1&&opc<=x)&&opc!=x)
        {
            h=opc-1;
            do {
                printf("¿Qué desea modificar?\n");
                printf("(1)Matricula.\n");
                printf("(2)Numero de plazas.\n");
                printf("(3)Descripcion.\n");
                printf("(4)TODO.\n");
                printf("(5)Salir.\n");
                scanf("%d", &opc2);
                switch(opc2)
                {
                    case 1:
                        printf("Matrícula del vehículo (Máximo de 7 caracteres):\n");
                        printf("Matrícula actual: %s\n", vehiculo[vec[h]].id_mat);
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
                            strcpy(vehiculo[vec[h]].id_mat, mat);

                            printf("La matrícula del vehículo se ha actualizado correctamente.\n");
                            system("PAUSE");
                        }
                        else
                        {
                            printf("La matrícula introducida ya existe en otro vehículo.\n");
                            system("PAUSE");
                        }
                        break;
                    case 2:
                        printf("Número de plazas libres (sin contar el conductor):\n");
                        printf("Plazas actuales: %s\n", vehiculo[vec[h]].num_plazas);
                        pregunta(plazas, 2);

                        strcpy(vehiculo[vec[h]].num_plazas, plazas);

                        printf("El numero de plazas del vehículo se ha actualizado correctamente.\n");
                        system("PAUSE");
                        break;
                    case 3:
                        printf("Descripción del vehículo (Marca, modelo, color, etc) (Máximo de 50 caracteres):\n");
                        printf("Descripción actual: %s\n", vehiculo[vec[h]].desc_veh);
                        pregunta(descrip, 51);

                        strcpy(vehiculo[vec[h]].desc_veh, descrip);

                        printf("La descripcion del vehiculo se ha actualizado correctamente.\n");
                        system("PAUSE");
                        break;
                    case 4:
                        printf("Matrícula del vehículo (Máximo de 7 caracteres):\n");
                        printf("Matrícula actual: %s\n", vehiculo[vec[h]].id_mat);
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
                            printf("Número de plazas libres (sin contar el conductor):\n");
                            printf("Plazas actuales: %s\n", vehiculo[vec[h]].num_plazas);
                            fflush(stdin);
                            pregunta(plazas, 2);

                            printf("Descripción del vehículo (Marca, modelo, color, etc) (Máximo de 50 caracteres):\n");
                            printf("Descripción actual: %s\n", vehiculo[vec[h]].desc_veh);
                            pregunta(descrip, 51);

                            strcpy(vehiculo[vec[h]].id_mat, mat);
                            strcpy(vehiculo[vec[h]].num_plazas, plazas);
                            strcpy(vehiculo[vec[h]].desc_veh, descrip);

                            printf("Se han actualizado todos los datos del vehículo.\n");
                            system("PAUSE");
                        }
                        else
                        {

                            printf("La matrícula introducida ya existe en otro vehículo.\n");
                            system("PAUSE");
                        }
                        break;
                    case 5:
                        break;
                    }
                encontrado=0;
                system("cls");
                break;
            }while(opc2>1&&opc2<5);

        }
        modificarVehiculo(i);
        }

        do{
            fprintf(fp, "%s-%s-%s-%s\n", vehiculo[n].id_mat, vehiculo[n].id_usuario, vehiculo[n].num_plazas, vehiculo[n].desc_veh);
            n++;
        }while(n<numVehiculos-1);
        fprintf(fp, "%s-%s-%s-%s", vehiculo[n].id_mat, vehiculo[n].id_usuario, vehiculo[n].num_plazas, vehiculo[n].desc_veh);
        numVehiculos++;

    }
    fclose(fp);
    leer_vehiculo(&vehiculo, &numVehiculos);
    system("cls");

return;
}

void modificarPerfilNombre(int i)
{
    FILE *fp;
    int n=0;
    char nomb[21];

    fp=fopen("usuarios.txt","r+");

    if(fp==NULL) {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else {
        printf("Introduzca su nuevo nombre completo (Máximo de 20 caracteres):\n");
        pregunta(nomb, 21);

        strcpy(usuario[i].nomb_usuario, nomb);
        do{
            fprintf(fp, "%s-%s-%s-%s-%s-%s\n", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
            n++;
        }while(n<numUsuarios-1);
        fprintf(fp, "%s-%s-%s-%s-%s-%s", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
        numUsuarios++;

        printf("Su nombre completo se ha actualizado correctamente.\n");
        system("PAUSE");
    }
    fclose(fp);
    leer_usuario(&usuario, &numUsuarios);
    system("cls");

return;
}

void modificarPerfilLocalidad(int i)
{
    FILE *fp;
    int n=0;
    char localidad[21];

    fp=fopen("usuarios.txt","r+");

    if(fp==NULL) {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else {
        printf("Introduzca su nueva localidad de residencia (3 siglas):\n");
        fflush(stdin);
        pregunta_localidad(localidad);

        strcpy(usuario[i].localidad, localidad);
        do{
            fprintf(fp, "%s-%s-%s-%s-%s-%s\n", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
            n++;
        }while(n<numUsuarios-1);
        fprintf(fp, "%s-%s-%s-%s-%s-%s", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
        numUsuarios++;

        printf("Su localidad de residencia se ha actualizado correctamente.\n");
        system("PAUSE");
    }
    fclose(fp);
    leer_usuario(&usuario, &numUsuarios);
    system("cls");

return;
}

void modificarPerfilUsuario(int i)
{
    FILE *fp;
    int n=0, k=0, encontrado=0;
    char usua[6];

    fp=fopen("usuarios.txt","r+");

    if(fp==NULL) {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else {
        printf("Introduzca su nuevo nombre de usuario (Máximo de 5 caracteres):\n");
        pregunta(usua, 6);

        for(k=0; k<numUsuarios&&encontrado==0; k++)
        {
            if(strcmp(usua, usuario[k].usuario)==0)
            {
                encontrado=1;
            }
        }
        if(encontrado==0)
        {
            printf("El nombre de usuario es válido.\n");
            strcpy(usuario[i].usuario, usua);
            do{
                fprintf(fp, "%s-%s-%s-%s-%s-%s\n", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
                n++;
            }while(n<numUsuarios-1);
            fprintf(fp, "%s-%s-%s-%s-%s-%s", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
            numUsuarios++;

            printf("Su nombre de usuario se ha actualizado correctamente.\n");
            system("PAUSE");
            leer_usuario(&usuario, &numUsuarios);
        }
        else
        {
            printf("El nombre de usuario ya está siendo usado.\n");
            system("PAUSE");
        }
    }
    fclose(fp);
    system("cls");
}

void modificarPerfilContrasena(int i)
{
    FILE *fp;
    int j=0, n=0, encontrado=3, x=0, h=0;
    char contra[9], contra2[9], c, c2;

    fp=fopen("usuarios.txt","r+");

    if(fp==NULL) {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else {
        while(encontrado>=0&&x==0)
        {
            printf("Introduzca su antigua contrasena (Máximo de 8 caracteres):\n");
            fflush(stdin);
            while ((c=getch())!='\r'&&j<8)
            {
                if (c=='\b'&&j>0)
                {
                    j--;
                    printf("\b \b");
                }
                else if (c != '\b')
                {
                    contra[j++] = c;
                    printf("*");
                }
            }
            contra[j] = '\0';

            if(strcmp(usuario[i].contrasena,contra)==0)
            {
                x=1;
                printf("\nIntroduzca su nueva contrasena (Máximo de 8 caracteres):\n");
                fflush(stdin);
                while ((c2=getch())!='\r'&&h<8)
                {
                    if (c2=='\b'&&h>0)
                    {
                        h--;
                        printf("\b \b");
                    }
                    else if (c2!='\b')
                    {
                        contra2[h++] = c2;
                        printf("*");
                    }
                }
                contra2[h] = '\0';

                strcpy(usuario[i].contrasena, contra2);
                do{
                    fprintf(fp, "%s-%s-%s-%s-%s-%s\n", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
                    n++;
                }while(n<numUsuarios-1);
                fprintf(fp, "%s-%s-%s-%s-%s-%s", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
                numUsuarios++;

                printf("\nSu contraseña se ha actualizado correctamente.\n");
                system("PAUSE");
            }
            else
            {
                encontrado--;
                printf("\nQueda(n) %i intentos.\n", encontrado);
                *contra=NULL;
                j=0;
                system("PAUSE");
                system("cls");

            }
        }
    }
    fclose(fp);
    leer_usuario(&usuario, &numUsuarios);
    system("cls");

return;
}

void modificarAdminUsuario()
{
    int i=0, j, opc=0, encontrado=0;
    char vec_id[5];

    listarUsuarios();

    while(encontrado==0)
    {
        printf("Introduzca la ID del usuario al que quiere modificarle el usuario.\n");
        pregunta(vec_id, 5);

        encontrarUsuario(vec_id, &j, &encontrado);

        if(encontrado==1)
        {
            while(opc<1||opc>6)
            {
                system("cls");
                printf("¿Qué desea modificar?\n");
                printf("(1)Nombre completo.\n");
                printf("(2)Localidad.\n");
                printf("(3)Nombre de usuario.\n");
                printf("(4)Contrasena.\n");
                printf("(5)TODO.\n");
                printf("(6)Salir.\n");
                scanf("%d", &opc);
                switch(opc)
                    {
                        case 1:
                            modificarPerfilNombre(j);
                            break;
                        case 2:
                            modificarPerfilLocalidad(j);
                            break;
                        case 3:
                            modificarPerfilUsuario(j);
                            break;
                        case 4:
                            modificarPerfilContrasena(j);
                            break;
                        case 5:
                            modificarPerfilNombre(j);
                            modificarPerfilLocalidad(j);
                            modificarPerfilUsuario(j);
                            modificarPerfilContrasena(j);
                            break;
                        case 6:
                            break;
                    }
            }
        }
    }
}

void modificarAdminVehiculo()
{
    char opc2[4];
    int encontrado=0, i=0;

    system("cls");
    listarVehiculos();
    printf("Escriba la ID del usuario a la que se quiera modificar el vehículo\n");
    scanf("%4s",&opc2);
    for(int counter=0;(counter<numUsuarios)&&(encontrado==0);counter++){
        if(strcmp(opc2,usuario[counter].id_usuario)==0){
            encontrado=1;
            i=counter;
            system("cls");
            modificarVehiculo(i);
        }
    }
    if(encontrado==0){
        system("cls");
        printf("No se ha encontrado ningun usuario con la siguiente ID: %s\n",opc2);
        system("PAUSE");
    }
}

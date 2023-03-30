#include "modificar.h"

void modificarVehiculo(int i)
{
    FILE *fp, *temp;
    int n=0, x=0, h=0, m=0, opc=0, opc2=0, aux=0, y=0, *vec=NULL, encontrado=0, error_mat, counter;
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
            do
            {
                printf("¿Qué desea modificar?\n");
                printf("(1)Matricula.\n");
                printf("(2)Numero de plazas.\n");
                printf("(3)Descripcion.\n");
                printf("(4)TODO.\n");
                printf("(5)Salir.\n");
                scanf("%d", &opc2);
                system("cls");
                switch(opc2)
                {
                    case 1:
                        do{
                            error_mat=0;
                            printf("Matrícula del vehículo (Máximo de 7 caracteres):\n");
                            printf("Matrícula actual: %s\n", vehiculo[vec[h]].id_mat);
                            pregunta(mat, 8);

                            for(counter=0;(counter<numVehiculos)&&(error_mat==0);counter++){
                                if(strcmp(mat,vehiculo[counter].id_mat)==0){
                                    error_mat=1;
                                    printf("La matricula %s esta actualmente registrada.\n",mat);
                                    system("PAUSE");
                                }
                            }
                            if(strlen(mat)<7){
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
                            system("cls");
                        }while((error_mat==1)||(strlen(mat)<7));

                        strcpy(vehiculo[vec[h]].id_mat, mat);

                        printf("La matrícula del vehículo se ha actualizado correctamente.\n");
                        system("PAUSE");
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
                        do{
                            error_mat=0;
                            printf("Matrícula del vehículo (Máximo de 7 caracteres):\n");
                            printf("Matrícula actual: %s\n", vehiculo[vec[h]].id_mat);
                            pregunta(mat, 8);

                            for(counter=0;(counter<numVehiculos)&&(error_mat==0);counter++){
                                if(strcmp(mat,vehiculo[counter].id_mat)==0){
                                    error_mat=1;
                                    printf("La matricula %s esta actualmente registrada.\n",mat);
                                    system("PAUSE");
                                }
                            }
                            if(strlen(mat)<7){
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
                            system("cls");
                        }while((error_mat==1)||(strlen(mat)<7));

                        printf("Matrícula del vehículo (Máximo de 7 caracteres):\n");
                        printf("Matrícula actual: %s\n", vehiculo[vec[h]].id_mat);
                        printf("%s\n", mat);

                        strcpy(vehiculo[vec[h]].id_mat, mat);

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
                        break;
                    case 5:
                        break;
                }
                encontrado=1;
            }while((opc2>1&&opc2<5)&&encontrado==0);
            if(opc2!=5)
            {
                temp=fopen("vehiculos_Temp.txt","w+");
                if(temp==NULL) {
                    printf("No se ha podido abrir el fichero vehiculos_Temp.txt.\n");
                }
                else
                {
                    do{
                        fprintf(temp, "%s-%s-%s-%s\n", vehiculo[n].id_mat, vehiculo[n].id_usuario, vehiculo[n].num_plazas, vehiculo[n].desc_veh);
                        n++;
                    }while(n<(numVehiculos-1));
                    fprintf(temp, "%s-%s-%s-%s", vehiculo[n].id_mat, vehiculo[n].id_usuario, vehiculo[n].num_plazas, vehiculo[n].desc_veh);
                }
                fclose(temp);
                fclose(fp);
                remove("vehiculos.txt");
                rename("vehiculos_Temp.txt","vehiculos.txt");
            }
        }
        }
    }
    fclose(fp);
    leer_vehiculo(&vehiculo, &numVehiculos);
    system("cls");
}

void modificarViaje(int i)
{
    FILE *fp, *temp;
    int n=0, h=0, x=0, m=0, j=0, opc=0, opc2=0, *vec=NULL, *vec_viaje=NULL, cont=0, prec=0, encontrado=0, encontrado2=0;
    char mat[8], fecha[11], hora_in[6], hora_fin[6], coste[2];

    fp=fopen("viajes.txt","r+");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero viajes.txt.\n");
        return;
    }
    else
    {
        encontrarVehiculos(&vec, &x, i);
        for(j=0;j<x;j++)
        {
            encontrarViajes(vehiculo[vec[j]].id_mat, &vec_viaje, &cont, 1);
        }
        if(cont==0)
        {
            printf("No posee viajes registrados.\n");
            system("PAUSE");
        }
        while(cont!=0&&encontrado==0)
        {
            printf("¿Que viaje quiere modificar?\n");

            for(m=0; m<cont; m++)
            {
                printf("(%i)%s-%s-%s-%s-%s-%s-%s-%s\n", m+1, viaje[vec_viaje[m]].id_viaje,viaje[vec_viaje[m]].id_mat,viaje[vec_viaje[m]].f_inic,viaje[vec_viaje[m]].h_inic,viaje[vec_viaje[m]].h_fin,viaje[vec_viaje[m]].plazas_libre,viaje[vec_viaje[m]].ida_vuelta,viaje[vec_viaje[m]].precio,viaje[vec_viaje[m]].estado);
            }
            m++;
            printf("(%i)Salir.\n", m);
            printf("Ingrese el número correspondiente al viaje que desea modificar: ");
            fflush(stdin);
            scanf("%d", &opc);
            system("cls");
            if(opc>=1&&opc<=cont)
            {
                encontrado=1;
            }
            if(opc==m)
            {
                return;
            }
        }
        encontrado=0;
        h=opc-1;
        do
        {
            printf("¿Qué desea modificar?\n");
            printf("(1)Vehiculo.\n");
            printf("(2)Fecha.\n");
            printf("(3)Coste.\n");
            printf("(4)Rutas.\n");
            printf("(5)TODO.\n");
            printf("(6)Salir.\n");
            scanf("%d", &opc2);
                switch(opc2)
                {
                    case 1:
                        do
                        {
                            system("cls");
                            printf("LISTADO DE VEHICULOS QUE TIENE:\n");
                            for(i=0;i<x;i++)
                            {
                                printf("%s-%s-%s\n", vehiculo[vec[i]].id_mat, vehiculo[vec[i]].num_plazas, vehiculo[vec[i]].desc_veh);
                            }
                            printf("Matrícula del vehículo (Máximo de 7 caracteres) para asignarle al viaje %s:\n", viaje[vec_viaje[h]].id_viaje);
                            printf("Matrícula actual: %s\n", viaje[vec_viaje[h]].id_mat);
                            pregunta(mat, 8);
                            for(j=0;j<x;j++)
                            {
                                if(strcmp(vehiculo[vec[j]].id_mat, mat)==0)
                                {
                                    encontrado2=1;
                                }
                            }
                        }while(encontrado2==0);

                        strcpy(viaje[vec_viaje[h]].id_mat, mat);

                        printf("El vehículo del viaje se ha actualizado correctamente.\n");
                        system("PAUSE");
                        break;
                    case 2:
                        leerFecha(fecha, hora_in, hora_fin);

                        strcpy(viaje[vec_viaje[h]].f_inic, fecha);
                        strcpy(viaje[vec_viaje[h]].h_inic, hora_in);
                        strcpy(viaje[vec_viaje[h]].h_fin, hora_fin);

                        printf("La fecha del viaje se ha actualizado correctamente.\n");
                        system("PAUSE");
                        break;
                    case 3:
                        while(prec<=0)
                        {
                            system("cls");
                            printf("Coste del viaje (Máximo de 1 digito):\n");
                            printf("Coste actual: %s\n", viaje[vec_viaje[h]].precio);
                            scanf("%1i", &prec);
                        }

                        sprintf(coste, "%1i", prec);

                        strcpy(viaje[vec_viaje[h]].precio, coste);

                        printf("El coste del viaje se ha actualizado correctamente.\n");
                        system("PAUSE");
                        break;

                    case 4:
                        modificarRuta(i);
                        break;
                    case 5:
                        do
                        {
                            system("cls");
                            printf("LISTADO DE VEHICULOS QUE TIENE:\n");
                            for(i=0;i<x;i++)
                            {
                                printf("%s-%s-%s\n", vehiculo[vec[i]].id_mat, vehiculo[vec[i]].num_plazas, vehiculo[vec[i]].desc_veh);
                            }
                            printf("Matrícula del vehículo (Máximo de 7 caracteres) para asignarle al viaje %s:\n", viaje[vec_viaje[h]].id_viaje);
                            printf("Matrícula actual: %s\n", viaje[vec_viaje[h]].id_mat);
                            pregunta(mat, 8);
                            for(j=0;j<x;j++)
                            {
                                if(strcmp(vehiculo[vec[j]].id_mat, mat)==0)
                                {
                                    encontrado2=1;
                                }
                            }
                        }while(encontrado2==0);

                        strcpy(viaje[vec_viaje[h]].id_mat, mat);

                        if(encontrado2==1)
                        {
                            leerFecha(fecha, hora_in, hora_fin);

                            strcpy(viaje[vec_viaje[h]].f_inic, fecha);
                            strcpy(viaje[vec_viaje[h]].h_inic, hora_in);
                            strcpy(viaje[vec_viaje[h]].h_fin, hora_fin);

                            while(prec<=0)
                            {
                                system("cls");
                                printf("Coste del viaje (Máximo de 1 digito):\n");
                                printf("Coste actual: %s\n", viaje[vec_viaje[h]].precio);
                                scanf("%1i", &prec);
                            }

                            sprintf(coste, "%1i", prec);

                            strcpy(viaje[vec_viaje[h]].precio, coste);

                            modificarRuta(i);

                            printf("Se han actualizado todos los datos ingresados del viaje.\n");
                            system("PAUSE");
                        }
                        break;
                    case 6:
                        break;
                    }
                    encontrado=1;
            }while((opc2>1&&opc2<6)&&encontrado==0);
            if(opc2!=6)
            {
                temp=fopen("viajes_Temp.txt","w+");
                if(temp==NULL) {
                    printf("No se ha podido abrir el fichero viajes_Temp.txt.\n");
                }
                else
                {
                    do{
                        fprintf(fp, "%s-%s-%s-%s-%s-%s-%s-%s-%s\n",viaje[n].id_viaje,viaje[n].id_mat,viaje[n].f_inic,viaje[n].h_inic,viaje[n].h_fin,viaje[n].plazas_libre,viaje[n].ida_vuelta,viaje[n].precio,viaje[n].estado);
                        n++;
                    }while(n<numViajes-1);
                    fprintf(fp, "%s-%s-%s-%s-%s-%s-%s-%s-%s",viaje[n].id_viaje,viaje[n].id_mat,viaje[n].f_inic,viaje[n].h_inic,viaje[n].h_fin,viaje[n].plazas_libre,viaje[n].ida_vuelta,viaje[n].precio,viaje[n].estado);
                }
                fclose(temp);
                fclose(fp);
                remove("viajes.txt");
                rename("viajes_Temp.txt","viajes.txt");
            }
    }
    fclose(fp);
    leer_viaje(&viaje, &numViajes);
    system("cls");
}

void modificarRuta(int num_user)
{
    int *vec=NULL, *vec_viaje=NULL, x, num_v, i, j, opc, h;
    char *mat;

    encontrarVehiculos(&vec,&x, num_user);

    for(j=0;j<x;j++)
    {
        encontrarViajes(vehiculo[vec[j]].id_mat, &vec_viaje, &num_v, 0);
    }
    printf("LISTADO DE VIAJES:\n");
    for(i=0;i<num_v;i++){
        printf("(%i)%s-%s-%s-%s-%s-%s-%s-%s-%s\n", i+1, viaje[vec_viaje[i]].id_viaje,viaje[vec_viaje[i]].id_mat,viaje[vec_viaje[i]].f_inic,viaje[vec_viaje[i]].h_inic,viaje[vec_viaje[i]].h_fin,viaje[vec_viaje[i]].plazas_libre,viaje[vec_viaje[i]].ida_vuelta,viaje[vec_viaje[i]].precio,viaje[vec_viaje[i]].estado);
    }
    do{
        printf("Seleccione el viaje que desee modificar:\n");
        scanf("%i",&opc);
    }while(opc>=1&&opc<=num_v);
    h=opc-1;
    eliminarPasos(viaje[vec[h]].id_viaje);
    buscadorRutas(viaje[vec[h]].id_viaje);
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
        while(encontrado>0&&x==0)
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
                system("cls");
                x=1;
                printf("Introduzca su nueva contrasena (Máximo de 8 caracteres):\n");
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
                if(encontrado==0)
                {
                    printf("\n¡Intentos agotados! :(\n");
                    system("PAUSE");
                }
                else
                {
                    *contra=NULL;
                    j=0;
                    printf("\nQueda(n) %i intentos.\n", encontrado);
                    system("PAUSE");
                    system("cls");
                }

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
    int encontrado=0, i=0, counter;

    system("cls");
    listarVehiculos();
    printf("Escriba la ID del usuario a la que se quiera modificar el vehículo\n");
    scanf("%4s",&opc2);
    for(counter=0;(counter<numUsuarios)&&(encontrado==0);counter++){
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

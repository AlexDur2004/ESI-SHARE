#include "eliminar.h"

void eliminarAdminUsuario()
{
    FILE *fp, *temp;
    int n=0, o=0, h=0, m=0, j=0, k=0, opc=0, opc2=0, c=0, num_v=0, id=0, *vec=NULL, encontrado=0, encontrado2=0;
    char vec_id[5];

    fp=fopen("usuarios.txt","r+");

    if(fp==NULL) {
        printf("No se ha podido abrir el fichero usuarios.txt.\n");
        return;
    }
    else {
        listarUsuarios();
        if(numUsuarios>1){
            printf("¿Qué usuario quiere eliminar?\n");
            printf("Introduzca la ID del usuario que quiere eliminar.\n");
            pregunta(vec_id, 5);
            encontrarUsuario(vec_id, &j, &encontrado);
            if(encontrado==1){
                do{
                    opc2=0;
                    system("cls");
                    printf("¿Seguro que quieres eliminar el usuario %s, con ID %s?\n", usuario[j].nomb_usuario, usuario[j].id_usuario);
                    printf("(1)Si\n");
                    printf("(2)No\n");
                    fflush(stdin);
                    scanf("%d", &opc2);

                    if(opc2==1&&encontrado2==0){
                        system("cls");
                        encontrado=0;
                        for(n=0; (n<numUsuarios); n++) //Este bucle se encargará de suprimir el vehiculo deseado sustituyendo vehiculos.txt por otro.
                        {
                            if(strcmp(usuario[n].id_usuario, usuario[j].id_usuario)==0)
                            {
                                temp=fopen("usuarios_Temp.txt","w+");
                                if(temp==NULL) {
                                    printf("No se ha podido abrir el fichero usuarios_Temp.txt.\n");
                                }
                                else{
                                    for(int counter=0; counter<numUsuarios;counter++){
                                        if(strcmp(usuario[counter].id_usuario, vec_id)!=0){
                                            fprintf(temp, "%s-%s-%s-%s-%s-%s\n", usuario[counter].id_usuario, usuario[counter].nomb_usuario, usuario[counter].localidad, usuario[counter].perfil, usuario[counter].usuario, usuario[counter].contrasena);
                                        }
                                    }
                                }
                                fclose(temp);
                                fclose(fp);
                                encontrarVehiculos(&vec, &o, n);
                                for(c=0; c<o; c++)
                                {
                                    eliminarVehiculoViajes(vehiculo[vec[c]].id_mat, o);
                                }
                            }
                        }
                        remove("usuarios.txt");
                        rename("usuarios_Temp.txt","usuarios.txt");
                        leer_usuario(&usuario, &numUsuarios);
                        system("cls");
                        printf("Eliminado con exito\n");
                        system("PAUSE");
                    }
                    else
                    {
                        encontrado2=1;
                    }
                }while((opc2<1)||(opc2>2));
            }
            else {
                system("cls");
                eliminarAdminUsuario();
            }
        }
        else{
            system("cls");
            printf("No hay usuarios registrados.\n");
            system("PAUSE");
        }
    }
    fclose(fp);
    return;
}


void eliminarVehiculo(int i)
{
    FILE *fp, *temp;
    int n=0, x=0, h=0, m=0, j=0, k=0, opc=0, opc2=0, num_v=0,*vec=NULL, *vec_viaje=NULL, encontrado=0;

    encontrarVehiculos(&vec, &x, i);
    if(x>0){
        printf("¿Qué vehiculo quiere eliminar?\n");

        for(m=0; m<x; m++)
        {
            printf("(%i)%s-%s-%s\n", m+1, vehiculo[vec[m]].id_mat, vehiculo[vec[m]].num_plazas, vehiculo[vec[m]].desc_veh);
        }
        m++;
        printf("(%i)Salir.\n", m);
        printf("Ingrese el número correspondiente al vehículo que desea eliminar: ");
        fflush(stdin);
        scanf("%d", &opc);
        if(opc==m){
            return;
        }
        if((opc>=1&&opc<m)&&opc!=m){
            h=opc-1;
            do{
                opc2=0;
                system("cls");
                printf("¿Seguro que quieres eliminar el vehiculo %s, con matrícula %s?\n", vehiculo[vec[h]].desc_veh, vehiculo[vec[h]].id_mat);
                printf("(1)Si\n");
                printf("(2)No\n");
                fflush(stdin);
                scanf("%d", &opc2);
                if(opc2==1){
                    system("cls");
                    eliminarVehiculoViajes(vehiculo[vec[h]].id_mat, x);
                    system("PAUSE");
                }
            }while((opc2<1)||(opc2>2));
        }
        else {
            system("cls");
            eliminarVehiculo(i);
        }
    }
    else{
        system("cls");
        printf("No posee vehículos registrados.\n");
        system("PAUSE");
    }
    return;
}

void eliminarVehiculoViajes(char *mat, int x)
{
    FILE *fp, *temp;
    int n=0, j=0, k=0, num_v=0, *vec_viaje=NULL;

    fp=fopen("vehiculos.txt","r+");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else
    {
        for(n=0; n<numVehiculos; n++)
        {
            if(strcmp(vehiculo[n].id_mat, mat)==0)
            {
                temp=fopen("vehiculos_Temp.txt","w+");
                if(temp==NULL)
                {
                printf("No se ha podido abrir el fichero vehiculos_Temp.txt.\n");
                }
                else
                {
                    for(int counter=0; counter<numVehiculos; counter++)
                    {
                        if(strcmp(vehiculo[counter].id_mat, mat)!=0)
                        {
                            fprintf(temp, "%s-%s-%s-%s\n", vehiculo[counter].id_mat, vehiculo[counter].id_usuario, vehiculo[counter].num_plazas, vehiculo[counter].desc_veh);
                        }
                    }
                }
                fclose(temp);
                fclose(fp);
                for(j=0; j<x; j++)
                {
                    encontrarViajes(vehiculo[n].id_mat, &vec_viaje, &num_v, 0);
                }
                for(k=0; k<num_v; k++)
                {
                    eliminarSoloViaje(viaje[vec_viaje[k]].id_viaje);
                    eliminarPasos(viaje[vec_viaje[k]].id_viaje);
                    eliminarReservas(viaje[vec_viaje[k]].id_viaje);
                }
            }
        }
        remove("vehiculos.txt");
        rename("vehiculos_Temp.txt","vehiculos.txt");
        leer_vehiculo(&vehiculo, &numVehiculos);
    }
    fclose(fp);
    return;
}

void eliminarViaje(int i, int num) //0 para admin, y 1 para conductor.
{
    int n=0, j=0, x=0, w=0, h=0, m=0, num_v=0, opc=0, opc2=0, *vec=NULL, *vec_viaje=NULL, encontrado=0;

    encontrarVehiculos(&vec, &num_v, i);

    for(j=0;j<num_v;j++)
    {
        encontrarViajes(vehiculo[vec[j]].id_mat, &vec_viaje, &x, num);
    }

    if(x>0){
        printf("¿Qué viaje quiere eliminar?\n");

        for(m=0; m<x; m++)
        {
            printf("(%i)%s-%s-%s-%s-%s-%s-%s-%s-%s\n", m+1, viaje[vec_viaje[m]].id_viaje, viaje[vec_viaje[m]].id_mat,viaje[vec_viaje[m]].f_inic,viaje[vec_viaje[m]].h_inic,viaje[vec_viaje[m]].h_fin,viaje[vec_viaje[m]].plazas_libre,viaje[vec_viaje[m]].ida_vuelta,viaje[vec_viaje[m]].precio,viaje[vec_viaje[m]].estado);
        }
        x++;
        printf("(%i)Salir.\n", x);
        printf("Ingrese el número correspondiente al viaje que desea eliminar: ");
        fflush(stdin);
        scanf("%d", &opc);
        if(opc==x)
        {
            return;
        }
        if((opc>=1&&opc<x)&&opc!=x)
        {
            h=opc-1;
            do
            {
                opc2=0;
                system("cls");
                printf("¿Seguro que quieres eliminar el viaje %s, con matrícula %s?\n", viaje[vec_viaje[h]].id_viaje, viaje[vec_viaje[h]].id_mat);
                printf("(1)Si\n");
                printf("(2)No\n");
                fflush(stdin);
                scanf("%d", &opc2);
                if(opc2==1){
                    system("cls");
                    eliminarSoloViaje(viaje[vec_viaje[h]].id_viaje);
                }
            }while((opc2<1)||(opc2>2));
            system("cls");
            printf("Eliminado con exito\n");
            system("PAUSE");
        }
        else
        {
            system("cls");
            eliminarViaje(i, num);
        }
    }
    else{
        system("cls");
        printf("No tiene viajes registrados.\n");
        system("PAUSE");
    }
    return;
}

void eliminarSoloViaje(char *id)
{
    FILE *fp, *temp;
    int n=0;

    fp=fopen("viajes.txt","r+");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero viajes.txt.\n");
        return;
    }
    else
    {
        for(n=0; n<numViajes; n++)
        {
            if(strcmp(viaje[n].id_viaje, id)==0)
            {
                temp=fopen("viajes_Temp.txt","w+");
                if(temp==NULL)
                {
                printf("No se ha podido abrir el fichero viajes_Temp.txt.\n");
                }
                else
                {
                    for(int counter=0; counter<numViajes;counter++)
                    {
                        if(counter!=n)
                        {
                            fprintf(temp, "%s-%s-%s-%s-%s-%s-%s-%s-%s\n", viaje[counter].id_viaje, viaje[counter].id_mat, viaje[counter].f_inic, viaje[counter].h_inic, viaje[counter].h_fin, viaje[counter].plazas_libre, viaje[counter].ida_vuelta, viaje[counter].precio, viaje[counter].estado);
                        }
                    }
                }
                fclose(temp);
                fclose(fp);
                eliminarPasos(viaje[n].id_viaje);
                eliminarReservas(viaje[n].id_viaje);
            }
        }
        remove("viajes.txt");
        rename("viajes_Temp.txt","viajes.txt");
        leer_viaje(&viaje, &numViajes);
    }
    fclose(fp);
    return;
}

void eliminarPasos(char *id)
{
    FILE *fp, *temp;
    int n=0;

    fp=fopen("pasos.txt","r+");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero pasos.txt.\n");
        return;
    }
    else
    {
        for(n=0; n<numPasos; n++)
        {
            if(strcmp(pasos[n].id_viaje, id)==0)
            {
                temp=fopen("pasos_Temp.txt","w+");
                if(temp==NULL)
                {
                printf("No se ha podido abrir el fichero pasos_Temp.txt.\n");
                }
                else
                {
                    for(int counter=0; counter<numPasos;counter++)
                    {
                        if(strcmp(pasos[counter].id_viaje, id)!=0)
                        {
                            fprintf(temp, "%s-%s\n", pasos[counter].id_viaje, pasos[counter].poblacion);
                        }
                    }
                }
                fclose(temp);
                fclose(fp);
            }
        }
        remove("pasos.txt");
        rename("pasos_Temp.txt","pasos.txt");
        leer_pasos(&pasos, &numPasos);
        system("cls");
    }
    fclose(fp);
    return;
}

void eliminarReservas(char *id)
{
    FILE *fp, *temp;
    int n=0;

    fp=fopen("reservas.txt","r+");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero reservas.txt.\n");
        return;
    }
    else
    {
        for(n=0; n<numReservas; n++)
        {
            if(strcmp(reservas[n].id_viaje, id)==0)
            {
                temp=fopen("reservas_Temp.txt","w+");
                if(temp==NULL)
                {
                printf("No se ha podido abrir el fichero reservas_Temp.txt.\n");
                }
                else
                {
                    for(int counter=0; counter<numReservas;counter++)
                    {
                        if(strcmp(reservas[counter].id_viaje, id)!=0)
                        {
                            fprintf(temp, "%s-%s\n", reservas[counter].id_viaje, reservas[counter].id_usuario);
                        }
                    }
                }
                fclose(temp);
                fclose(fp);
            }
        }
        remove("reservas.txt");
        rename("reservas_Temp.txt","reservas.txt");
        leer_reservas(&reservas, &numReservas);
        system("cls");
    }
    fclose(fp);
    return;
}

void eliminarAdminVehiculo()
{
    char opc2[4];
    int encontrado=0, i=0;

    system("cls");
    listarVehiculos();
    printf("Escriba la ID del usuario a la que se quiera eliminar un vehículo\n");
    scanf("%4s",&opc2);
    for(int counter=0;(counter<numUsuarios)&&(encontrado==0);counter++)
    {
        if(strcmp(opc2,usuario[counter].id_usuario)==0)
        {
            encontrado=1;
            i=counter;
            system("cls");
            eliminarVehiculo(i);
        }
    }
    if(encontrado==0)
    {
        system("cls");
        printf("No se ha encontrado ningun usuario con la siguiente ID: %s\n",opc2);
        system("PAUSE");
    }
}

void eliminarAdminViaje()
{
    char opc2[4];
    int encontrado=0, i=0;

    system("cls");
    listarAdminViajes();
    printf("Escriba la ID del usuario al que quiere eliminar un viaje.\n");
    scanf("%4s",&opc2);
    for(int counter=0;(counter<numUsuarios)&&(encontrado==0);counter++)
    {
        if(strcmp(opc2,usuario[counter].id_usuario)==0)
        {
            encontrado=1;
            i=counter;
            system("cls");
            eliminarViaje(i, 0);
        }
    }
    if(encontrado==0)
    {
        system("cls");
        printf("No se ha encontrado ningun usuario con la siguiente ID: %s\n",opc2);
        system("PAUSE");
    }
}

#include "modificar.h"

//Cabecera: void modificarVehiculo(Estr_Usuario *, Estr_Vehiculo *, int, Estr_Viaje *, int, int);
//Precondicion: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario",
//y las estructuras "usuario" y "vehiculo" inicializadas, con sus contadores.
//Postcondicion: Modificar cualquier dato de un vehiculo que tenga el usuario, pero este vehiculo no puede tener viajes abiertos, con plazas ocupadas, ni cerrados ni iniciados.

void modificarVehiculo(Estr_Usuario *usuario, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, int i)
{
    FILE *fp;
    int x=0, h=0, m=0, aux=0, y=0, opc=0, opc2=0, *vec=NULL, encontrado=0, error_mat, counter, plaz=0;
    char mat[8], plazas[2], descrip[51];

    if(numVehiculos!=0) //Si hay vehiculos en el sistema.
    {
        fp=fopen("DATA/vehiculos.txt","r+");

        if(fp==NULL)
        {
            printf("No se ha podido abrir el fichero vehiculos.txt.\n");
            return;
        }
        else
        {
            encontrarVehiculosViajes(usuario, vehiculo, numVehiculos, viaje, numViajes, &vec, &x, i); //Encuentra todos los vehiculos del usuario.
            aux=x;
            if(vec!=NULL) //Si el usuario tiene vehiculos, el vector "vec" no sera nulo
            {
               while(encontrado==0) //Hasta que no se introduzca un vehiculo que este en el vector de enteros, es decir, un vehiculo que el tenga.
                {
                    x=aux;
                    y=aux;
                    printf("¿Que vehiculo quiere modificar?\n");

                    for(m=0; m<x; m++)
                    {
                        color(0,4);
                        printf("    Vehiculo "); //Imprime todos los datos de los vehiculos que tiene el usuario.
                        color(0,15);
                        printf("%i", m+1);
                        color(0,4);
                        printf(":\t");
                        color(0,3);
                        printf("    Matricula: ");
                        color(0,15);
                        printf("%s", vehiculo[vec[m]].id_mat);
                        color(0,3);
                        printf(" | Nº de plazas: ");
                        color(0,15);
                        printf("%s", vehiculo[vec[m]].num_plazas);
                        color(0,3);
                        printf(" | Descripcion: ");
                        color(0,15);
                        printf("%s\n", vehiculo[vec[m]].desc_veh);
                    }
                    x++;
                    color(0,14);
                    printf("(%i)Salir.\n", x);
                    color(0,15);
                    printf("Ingrese el numero correspondiente al vehiculo que desea modificar: ");
                    fflush(stdin);
                    scanf("%d", &opc);
                    system("cls");
                    if(opc==x) //Si introduce lo mismo que vale la variable maxima "x".
                    {
                        return; //Vuelve al menu.
                    }
                    for(m=1; m<y; m++) //Vamos recorriendo el vector de enteros, con los vehiculos del usuario.
                    {
                        if(opc==vec[m-1]) //Si el vehiculo seleccionado esta en este vector.
                        {
                            encontrado=1;
                        }
                    }
                    if((opc>=1&&opc<=x)&&opc!=x)
                    {
                        h=opc-1;
                        do
                        {
                            printf("¿Que desea modificar?\n");
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
                                    do{ //Hasta que la matricula no sea correcta.
                                        error_mat=0;
                                        printf("Matricula del vehiculo (Maximo de 7 caracteres):\n");
                                        printf("Matricula actual: %s\n", vehiculo[vec[h]].id_mat);
                                        pregunta(mat, 8); //Pedimos la nueva matricula.

                                        for(counter=0;(counter<numVehiculos)&&(error_mat==0);counter++) //Comprobamos que la matricula no esta registrada.
                                        {
                                            if(strcmp(mat,vehiculo[counter].id_mat)==0){ //Si se encuentra la matricula en las que hay ahora, pues esta usada.
                                                error_mat=1;
                                                printf("La matricula %s esta actualmente registrada.\n",mat);
                                                system("PAUSE");
                                            }
                                        }
                                        if(strlen(mat)<7) //Si la nueva matricula no tiene 7 caracteres.
                                        {
                                            printf("La matricula %s debe poseer una longitud total de 7 caracteres.\n", mat);
                                            system("PAUSE");
                                        }
                                        for(counter=0;(counter<4)&&(error_mat==0);counter++) //Comprobamos que los 4 primeros caracteres, son digitos.
                                        {
                                            if((mat[counter]<48)||(mat[counter]>57))
                                            {
                                                error_mat=1;
                                                printf("Los 4 primeros caracteres de la matricula tienen que ser numeros.\n");
                                                system("PAUSE");
                                            }
                                        }
                                        for(counter=4;(counter<7)&&(error_mat==0);counter++) //Comprobamos que los 3 ultimos caracteres, son letras mayusculas.
                                        {
                                            if((mat[counter]<65)||(mat[counter]>90))
                                            {
                                                error_mat=1;
                                                printf("Los 3 ultimos caracteres de la matricula tienen que ser letras mayusculas.\n");
                                                system("PAUSE");
                                            }
                                        }
                                        system("cls");
                                    }while((error_mat==1)||(strlen(mat)<7));

                                    strcpy(vehiculo[vec[h]].id_mat, mat); //Copiamos la nueva matricula en la posicion de la estructura correspondiente.

                                    printf("La matricula del vehiculo se ha actualizado correctamente.\n");
                                    system("PAUSE");
                                    break;
                                case 2:
                                    while(encontrado==0)
                                    {
                                        printf("Numero de plazas libres (sin contar el conductor):\n");
                                        printf("Plazas actuales: %s\n", vehiculo[vec[h]].num_plazas);
                                        fflush(stdin);
                                        scanf("%1i", &plaz); //Pedimos el nuevo numero de plazas.
                                        if(plaz<=0)
                                        {
                                            printf("Introduzca un numero de plazas entre 1 y 9.\n");
                                            system("PAUSE");
                                            system("cls");
                                        }
                                        else
                                        {
                                            encontrado=1;
                                        }
                                    }
                                    sprintf(plazas, "%1i", plaz); //Pasamos de entero a cadena.

                                    strcpy(vehiculo[vec[h]].num_plazas, plazas); //Copiamos el nuevo numero de plazas en la posicion de la estructura correspondiente.

                                    printf("El numero de plazas del vehiculo se ha actualizado correctamente.\n");
                                    system("PAUSE");
                                    break;
                                case 3:
                                    printf("Descripcion del vehiculo (Marca, modelo, color, etc) (Maximo de 50 caracteres):\n");
                                    printf("Descripcion actual: %s\n", vehiculo[vec[h]].desc_veh);
                                    pregunta(descrip, 51); //Pedimos la nueva descripcion.

                                    strcpy(vehiculo[vec[h]].desc_veh, descrip); //Copiamos la nueva descripcion en la posicion de la estructura correspondiente.

                                    printf("La descripcion del vehiculo se ha actualizado correctamente.\n");
                                    system("PAUSE");
                                    break;
                                case 4: //Volvemos a hacer todo lo anterior.
                                    do{
                                        error_mat=0;
                                        printf("Matricula del vehiculo (Maximo de 7 caracteres):\n");
                                        printf("Matricula actual: %s\n", vehiculo[vec[h]].id_mat);
                                        pregunta(mat, 8);

                                        for(counter=0;(counter<numVehiculos)&&(error_mat==0);counter++){
                                            if(strcmp(mat,vehiculo[counter].id_mat)==0){
                                                error_mat=1;
                                                printf("La matricula %s esta actualmente registrada.\n",mat);
                                                system("PAUSE");
                                            }
                                        }
                                        if(strlen(mat)<7){
                                            printf("La matricula %s debe poseer una longitud total de 7 caracteres.\n",mat);
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

                                    printf("Matricula del vehiculo (Maximo de 7 caracteres):\n");
                                    printf("Matricula actual: %s\n", vehiculo[vec[h]].id_mat);
                                    printf("%s\n", mat);

                                    strcpy(vehiculo[vec[h]].id_mat, mat);

                                    printf("Numero de plazas libres (sin contar el conductor):\n");
                                    printf("Plazas actuales: %s\n", vehiculo[vec[h]].num_plazas);
                                    while(encontrado==0)
                                    {
                                        fflush(stdin);
                                        scanf("%1i", &plaz); //Pedimos el nuevo numero de plazas.
                                        if(plaz<=0)
                                        {
                                            printf("Introduzca un numero de plazas entre 1 y 9.\n");
                                        }
                                        else
                                        {
                                            encontrado=1;
                                        }
                                    }
                                    sprintf(plazas, "%1i", plaz); //Pasamos de entero a cadena.

                                    strcpy(vehiculo[vec[h]].num_plazas, plazas); //Copiamos el nuevo numero de plazas en la posicion de la estructura correspondiente.

                                    printf("Descripcion del vehiculo (Marca, modelo, color, etc) (Maximo de 50 caracteres):\n");
                                    printf("Descripcion actual: %s\n", vehiculo[vec[h]].desc_veh);
                                    pregunta(descrip, 51);

                                    strcpy(vehiculo[vec[h]].id_mat, mat);
                                    strcpy(vehiculo[vec[h]].num_plazas, plazas);
                                    strcpy(vehiculo[vec[h]].desc_veh, descrip);

                                    printf("Se han actualizado todos los datos del vehiculo.\n");
                                    system("PAUSE");
                                    break;
                                case 5: //Salimos
                                    break;
                            }
                            encontrado=1;
                        }while((opc2>1&&opc2<5)&&encontrado==0);
                        if(opc2!=5)
                        {
                            actualizarVehiculo(vehiculo, numVehiculos);
                        }
                    }
                }
            }
            else
            {
                printf("No tiene vehiculos registrados.\n");
                system("PAUSE");

            }
        }
    }
    else
    {
        printf("No hay vehiculos registrados en el sistema.\n");
        system("PAUSE");
    }
    fclose(fp);
}

//Cabecera: void modificarViaje(Estr_Usuario *, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondicion: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y las estructuras inicializadas, con sus contadores.
//Postcondicion: Modificar cualquier dato de un viaje, que este abierto y sin plazas reservadas, que tenga el usuario.

void modificarViaje(Estr_Usuario *usuario, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int i)
{
    FILE *fp;
    int h=0, x=0, m=0, j=0, opc=0, opc2=0, *vec=NULL, *vec_viaje=NULL, cont=0, prec=0, encontrado=0, encontrado2=0, encontrado3=0;
    char mat[8], fecha[11], hora_in[6], hora_fin[6], coste[2];

    if(numViajes!=0) //Si hay viajes en el sistema.
    {
        fp=fopen("DATA/viajes.txt","r+");

        if(fp==NULL)
        {
            printf("No se ha podido abrir el fichero viajes.txt.\n");
            return;
        }
        else
        {
            encontrarVehiculos(usuario, vehiculo, numVehiculos, &vec, &x, i); //Encuentra todos los vehiculos del usuario.
            for(j=0;j<x;j++)
            {
                encontrarViajes(vehiculo, numVehiculos, viaje, numViajes, vehiculo[vec[j]].id_mat, &vec_viaje, &cont, 2); //Encuentra todos los viajes abiertos, que no tienen plazas ocupadas, del usuario.
            }
            if(vec_viaje==NULL) //Si el vector esta vacio, significa que no hay viajes.
            {
                printf("No posee viajes abiertos, que no hayan sido reservados.\n");
                system("PAUSE");
            }
            else
            {
                while(vec_viaje!=NULL&&encontrado==0)
                {
                    printf("¿Que viaje quiere modificar?\n");

                    for(m=0; m<cont; m++)
                    {
                        color(0,4);
                        printf("    Viaje "); //Imprime todos los datos de cada viaje.
                        color(0,15);
                        printf("%i", m+1);
                        color(0,4);
                        printf(":\t");
                        color(0,3);
                        printf("ID: ");
                        color(0,15);
                        printf("%s", viaje[vec_viaje[m]].id_viaje);
                        color(0,3);
                        printf(" | Matricula: ");
                        color(0,15);
                        printf("%s", viaje[vec_viaje[m]].id_mat);
                        color(0,3);
                        printf(" | Fecha de partida: ");
                        color(0,15);
                        printf("%s", viaje[vec_viaje[m]].f_inic);
                        color(0,3);
                        printf(" | Hora de partida: ");
                        color(0,15);
                        printf("%s", viaje[vec_viaje[m]].h_inic);
                        color(0,3);
                        printf(" |\n                Hora de llegada: ");
                        color(0,15);
                        printf("%s", viaje[vec_viaje[m]].h_fin);
                        color(0,3);
                        printf(" | Plazas libres: ");
                        color(0,15);
                        printf("%s", viaje[vec_viaje[m]].plazas_libre);
                        color(0,3);
                        printf(" | Ida/Vuelta: ");
                        color(0,15);
                        printf("%s", viaje[vec_viaje[m]].ida_vuelta);
                        color(0,3);
                        printf(" | Precio: ");
                        color(0,15);
                        printf("%s\n\n", viaje[vec_viaje[m]].precio);
                    }
                    m++;
                    color(0,14);
                    printf("(%i)Salir.\n", m);
                    color(0,15);
                    printf("Ingrese el numero correspondiente al viaje que desea modificar: ");
                    fflush(stdin);
                    scanf("%d", &opc);
                    system("cls");
                    if(opc>=1&&opc<=cont) //Si la opcion esta entre 1 y la variable maxima.
                    {
                        encontrado=1;
                    }
                    if(opc==m) //Si introduce lo mismo que vale la variable maxima "x".
                    {
                        return; //Vuelve al menu.
                    }
                }
                encontrado=0;
                h=opc-1;
                do
                {
                    printf("¿Que desea modificar?\n");
                    printf("(1)Vehiculo.\n");
                    printf("(2)Fecha.\n");
                    printf("(3)Coste.\n");
                    printf("(4)Rutas.\n");
                    printf("(5)TODO.\n");
                    printf("(6)Salir.\n");
                    scanf("%d", &opc2);
                    system("cls");
                    switch(opc2)
                    {
                            case 1:
                                do
                                {
                                    system("cls");
                                    listarVehiculosUsuario(usuario, vehiculo, numVehiculos, i);
                                    printf("Matricula del vehiculo (Maximo de 7 caracteres) para asignarle al viaje %s:\n", viaje[vec_viaje[h]].id_viaje);
                                    printf("Matricula actual: %s\n", viaje[vec_viaje[h]].id_mat);
                                    pregunta(mat, 8); //Pedimos la nueva matricula que va a llevar el viaje.
                                    for(j=0;j<x;j++)
                                    {
                                        if(strcmp(vehiculo[vec[j]].id_mat, mat)==0) //Si la matricula introducida esta entre sus vehiculos.
                                        {
                                            encontrado2=1;
                                        }
                                    }
                                }while(encontrado2==0);

                                strcpy(viaje[vec_viaje[h]].id_mat, mat); //Copiamos la nueva matricula en la posicion de la estructura correspondiente.

                                printf("El vehiculo del viaje se ha actualizado correctamente.\n");
                                system("PAUSE");
                                break;
                            case 2:
                                leerFecha(fecha, hora_in, hora_fin); //Leemos la fecha, hora inicio y hora llegada.

                                verificar_viaje(viaje, numViajes, viaje[vec_viaje[h]].id_mat, fecha, hora_in, hora_fin, &encontrado3);

                                if(encontrado3==0) //Si el vehiculo ya tiene un viaje en esa fecha.
                                {
                                    strcpy(viaje[vec_viaje[h]].f_inic, fecha); //Introducimos los datos pedidos al viaje.
                                    strcpy(viaje[vec_viaje[h]].h_inic, hora_in);
                                    strcpy(viaje[vec_viaje[h]].h_fin, hora_fin);

                                    printf("\nLa fecha del viaje se ha actualizado correctamente.\n");
                                    system("PAUSE");
                                }
                                else
                                {
                                    printf("\nEl vehiculo tiene un viaje en la fecha introducida.\n");
                                    system("PAUSE");
                                }
                                break;
                            case 3:
                                while(prec<=0) //Mientras que el precio sea menor o igual a 0.
                                {
                                    system("cls");
                                    printf("Coste del viaje (Maximo de 1 digito):\n");
                                    printf("Coste actual: %s\n", viaje[vec_viaje[h]].precio);
                                    scanf("%1i", &prec); //Pedimos el nuevo precio.
                                }

                                sprintf(coste, "%1i", prec); //Pasamos de entero a cadena.

                                strcpy(viaje[vec_viaje[h]].precio, coste); //Copiamos el nuevo precio.

                                printf("El coste del viaje se ha actualizado correctamente.\n");
                                system("PAUSE");
                                break;
                            case 4:
                                eliminarPasos(pasos, numPasos, viaje[vec_viaje[h]].id_viaje); //Elimina los pasos del viaje.
                                buscadorRutas(ruta, numRutas, numRutas2, localidad, numLocalidades, pasos, numPasos, viaje[vec[h]].id_viaje); //Pide la nueva ruta por donde va a ir, e imprime los pasos.
                                break;
                            case 5: //Volvemos a hacer todo lo anterior.
                                do
                                {
                                    system("cls");
                                    listarVehiculosUsuario(usuario, vehiculo, numVehiculos, i);
                                    printf("Matricula del vehiculo (Maximo de 7 caracteres) para asignarle al viaje %s:\n", viaje[vec_viaje[h]].id_viaje);
                                    printf("Matricula actual: %s\n", viaje[vec_viaje[h]].id_mat);
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
                                        printf("Coste del viaje (Maximo de 1 digito):\n");
                                        printf("Coste actual: %s\n", viaje[vec_viaje[h]].precio);
                                        scanf("%1i", &prec);
                                    }

                                    sprintf(coste, "%1i", prec);

                                    strcpy(viaje[vec_viaje[h]].precio, coste);

                                    eliminarPasos(pasos, numPasos, viaje[vec_viaje[h]].id_viaje); //Elimina los pasos del viaje.
                                    buscadorRutas(ruta, numRutas, numRutas2, localidad, numLocalidades, pasos, numPasos, viaje[vec[h]].id_viaje); //Pide la nueva ruta por donde va a ir, e imprime los pasos.
                                    printf("Se han actualizado todos los datos ingresados del viaje.\n");
                                    system("PAUSE");
                                }
                                break;
                            case 6: //Salimos
                                break;
                            }
                            encontrado=1;
                    }while((opc2>1&&opc2<6)&&encontrado==0);
                    if(opc2!=6)
                    {
                        actualizarViaje(viaje, numViajes);
                    }
            }
        }
    }
    else
    {
        printf("No hay viajes registrados.\n");
        system("PAUSE");
    }

    fclose(fp);
}

//Cabecera: void modificarPerfilNombre(Estr_Usuario *, int, int);
//Precondicion: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y la estructura "usuario" inicializada, con su contador.
//Postcondicion: Modificar el nombre del usuario.

void modificarPerfilNombre(Estr_Usuario *usuario, int numUsuarios, int i)
{
    char nomb[21];

    printf("Introduzca su nuevo nombre completo (Maximo de 20 caracteres):\n");
    pregunta(nomb, 21); //Pedimos el nuevo nombre.

    strcpy(usuario[i].nomb_usuario, nomb); //Copiamos el nuevo nombre en la posicion de la estructura correspondiente.
    actualizarUsuario(usuario, numUsuarios); //Actualizamos el fichero usuarios.txt

    printf("Su nombre completo se ha actualizado correctamente.\n");
    system("PAUSE");
}

//Cabecera: void modificarPerfilLocalidad(Estr_Usuario *, int, Estr_Viaje *, int, Estr_Reservas *, int, Estr_Localidad *, int, int);
//Precondicion: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y las estructuras "usuario", "viaje", "localidad" y "reservas" inicializadas, con sus contadores.
//Postcondicion: Modificar la localidad del usuario, si no tiene ninguna reserva activa, ya que al buscar una reserva, se selecciona si pasa por su localidad.

void modificarPerfilLocalidad(Estr_Usuario *usuario, int numUsuarios, Estr_Viaje *viaje, int numViajes, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, int i)
{
    char loc[21];
    int x=0, *vec=NULL, *vec2=NULL;

    encontrarReservas(usuario, viaje, numViajes, reservas, numReservas, i, &vec, &vec2, &x); //Busca las reservas del usuario, para dejarle modificar la localidad.

    if(x!=0) //Si tiene reservas.
    {
        printf("No puede cambiar de localidad, ya que tiene reservas activas.\n");
        system("PAUSE");
        return;
    }
    else //Si no tiene reservas, podra cambiar su localidad.
    {
        printf("Introduzca su nueva localidad de residencia (3 siglas):\n");
        fflush(stdin);
        pregunta_localidad(localidad, numLocalidades, loc); //Pedimos la nueva localidad.

        strcpy(usuario[i].localidad, loc); //Copiamos la nueva localidad en la posicion de la estructura correspondiente.
        actualizarUsuario(usuario, numUsuarios); //Actualizamos el fichero usuarios.txt

        printf("Su localidad de residencia se ha actualizado correctamente.\n");
        system("PAUSE");
    }
}

//Cabecera: void modificarPerfilUsuario(Estr_Usuario *, int, int);
//Precondicion: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y la estructura "usuario" inicializada, con su contador.
//Postcondicion: Modificar el username del usuario.

void modificarPerfilUsuario(Estr_Usuario *usuario, int numUsuarios, int i)
{
    int k=0, encontrado=0;
    char usua[6];

    printf("Introduzca su nuevo nombre de usuario (Maximo de 5 caracteres):\n");
    pregunta(usua, 6); //Pedimos el nuevo username.

    for(k=0; k<numUsuarios&&encontrado==0; k++) //Comprobamos que no esta usado.
    {
        if(strcmp(usua, usuario[k].usuario)==0)
        {
            encontrado=1;
        }
    }

    if(encontrado==0) //Si no esta usado
    {
        printf("El nombre de usuario es valido.\n");
        strcpy(usuario[i].usuario, usua); //Copiamos el nuevo username en la posicion de la estructura correspondiente.
        actualizarUsuario(usuario, numUsuarios); //Actualizamos el fichero usuarios.txt

        printf("Su nombre de usuario se ha actualizado correctamente.\n");
        system("PAUSE");
    }
    else
    {
        printf("El nombre de usuario ya esta siendo usado.\n");
        system("PAUSE");
    }
}

//Cabecera: void modificarPerfilContrasena(Estr_Usuario *, int, int);
//Precondicion: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y la estructura "usuario" inicializada, con su contador.
//Postcondicion: Modificar la contrasena del usuario.

void modificarPerfilContrasena(Estr_Usuario *usuario, int numUsuarios, int i)
{
    int encontrado=3, x=0;
    char contra[9], contra2[9];

    while(encontrado>0&&x==0)
    {
        printf("Introduzca su antigua contrasena (Maximo de 8 caracteres):\n");
        preguntar_contrasena(contra);

        if(strcmp(usuario[i].contrasena,contra)==0) //Si la contrasena introducida es igual a la que tiene.
        {
            system("cls");
            x=1;
            printf("Introduzca su nueva contrasena (Maximo de 8 caracteres):\n");
            preguntar_contrasena(contra2);

            strcpy(usuario[i].contrasena, contra2); //Copiamos la nueva contrasena en la posicion de la estructura correspondiente.
            actualizarUsuario(usuario, numUsuarios); //Actualizamos el fichero usuarios.txt

            printf("\nSu contrasena se ha actualizado correctamente.\n");
            system("PAUSE");
        }
        else //Si no es correcta
        {
            encontrado--;
            if(encontrado==0) //Cuando no tiene intentos
            {
                printf("\n¡Intentos agotados! :(\n");
                system("PAUSE");
            }
            else //Si tiene intentos, se van restando.
            {
                contra[0]='\0';
                printf("\nQueda(n) %i intentos.\n", encontrado);
                system("PAUSE");
                system("cls");
            }
        }
    }
}

//Cabecera: void modificarAdminUsuario(Estr_Usuario *, int, Estr_Viaje *, int, Estr_Reservas *, int, Estr_Localidad *, int);
//Precondicion: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y las estructuras inicializadas, con sus contadores.
//Postcondicion: Modificar los datos de cualquier usuario.

void modificarAdminUsuario(Estr_Usuario *usuario, int numUsuarios, Estr_Viaje *viaje, int numViajes, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades)
{
    int j, opc=0, encontrado=0, id=0;
    char vec_id[5];



    if(numUsuarios!=0) //Si hay usuarios en el sistema.
    {
        while(encontrado==0)
        {
            listarUsuarios(usuario, numUsuarios); //Imprimir una lista de todos los usuarios del sistema.
            printf("Introduzca la ID del usuario al que quiere modificarle el usuario.\n");
            scanf("%i",&id); //Pedimos la id del usuario que queremos modificar.
            sprintf(vec_id, "%04i", id); //Introducimos el entero introducido en la cadena con formato XXXX

            encontrarUsuario(usuario, numUsuarios, vec_id, &j, &encontrado); //Buscamos si el usuario existe en el sistema.

            if(encontrado==1)
            {
                while(opc<1||opc>6) //Elegimos una de las opciones.
                {
                    system("cls");
                    printf("¿Que desea modificar?\n");
                    printf("(1)Nombre completo.\n");
                    printf("(2)Localidad.\n");
                    printf("(3)Nombre de usuario.\n");
                    printf("(4)Contrasena.\n");
                    printf("(5)TODO.\n");
                    printf("(6)Salir.\n");
                    scanf("%d", &opc);
                    system("cls");
                    switch(opc)
                        {
                            case 1:
                                modificarPerfilNombre(usuario, numUsuarios, j);
                                break;
                            case 2:
                                modificarPerfilLocalidad(usuario, numUsuarios, viaje, numViajes, reservas, numReservas, localidad, numLocalidades, j);
                                break;
                            case 3:
                                modificarPerfilUsuario(usuario, numUsuarios, j);
                                break;
                            case 4:
                                modificarPerfilContrasena(usuario, numUsuarios, j);
                                break;
                            case 5:
                                modificarPerfilNombre(usuario, numUsuarios, j);
                                printf("\n");
                                modificarPerfilLocalidad(usuario, numUsuarios, viaje, numViajes, reservas, numReservas, localidad, numLocalidades, j);
                                printf("\n");
                                modificarPerfilUsuario(usuario, numUsuarios, j);
                                printf("\n");
                                modificarPerfilContrasena(usuario, numUsuarios, j);
                                break;
                            case 6:
                                break;
                        }
                }
            }
            else
            {
                printf("La ID de usuario introducida no esta en el sistema.\n");
                system("PAUSE");
                system("cls");
            }
        }
    }
}

//Cabecera: void modificarAdminVehiculo(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, int);
//Precondicion: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y las estructuras inicializadas, con sus contadores.
//Postcondicion: Modificar los datos de un vehiculo, que no tenga viajes abiertos, con plazas ocupadas, ni iniciados ni cerrados, de cualquier usuario.

void modificarAdminVehiculo(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, int x)
{
    char opc2[5];
    int encontrado=0, counter, id;

    system("cls");
    if(numVehiculos!=0) //Si hay vehiculos en el sistema.
    {
        listarVehiculos(usuario, numUsuarios, vehiculo, numVehiculos, x); //Listamos todos los vehiculos.
        printf("Escriba la ID del usuario a la que se quiera modificar el vehiculo\n");
        scanf("%i",&id); //Pedimos la id del usuario, del vehiculo que queremos modificar.
        sprintf(opc2, "%04i", id); //Introducimos el entero introducido en la cadena con formato XXXX.

        for(counter=0;(counter<numUsuarios)&&(encontrado==0);counter++)
        {
            if(strcmp(opc2, usuario[counter].id_usuario)==0) //Si el usuario existe.
            {
                encontrado=1;
                system("cls");
                modificarVehiculo(usuario, vehiculo, numVehiculos, viaje, numViajes, counter); //Vamos a la funcion "modificarVehiculo".
            }
        }
        if(encontrado==0) //Si no existe el usuario introducido.
        {
            system("cls");
            printf("No se ha encontrado ningun usuario con la siguiente ID: %s\n",opc2);
            system("PAUSE");
        }
    }
}

//Cabecera: void modificarAdminViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondicion: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y las estructuras inicializadas, con sus contadores.
//Postcondicion: Modificar los datos de un viaje de cualquier usuario.

void modificarAdminViaje(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int x)
{
    char opc2[5];
    int encontrado=0, i=0, counter, n=0, id=0;

    system("cls");
    listarAdminViajes(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, x, 2, &n); //Listamos todos los viajes, abiertos y sin plazas reservadas.
    if(n!=0) //Si tiene viajes abiertos y sin plazas reservadas.
    {
        printf("Escriba la ID del usuario a la que se quiera modificar el viaje\n");
        scanf("%i", &id); //Pedimos la id del usuario, del vehiculo que queremos modificar.
        sprintf(opc2, "%04i", id); //Introducimos el entero introducido en la cadena con formato XXXX.

        for(counter=0;(counter<numUsuarios)&&(encontrado==0);counter++)
        {
            if(strcmp(opc2,usuario[counter].id_usuario)==0) //Si el usuario existe.
            {
                encontrado=1;
                i=counter;
                system("cls"); //Vamos a la funcion "modificarViaje".
                modificarViaje(usuario, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
            }
        }
        if(encontrado==0) //Si no existe el usuario introducido.
        {
            system("cls");
            printf("No se ha encontrado ningun usuario con la siguiente ID: %s\n",opc2);
            system("PAUSE");
        }
    }
}

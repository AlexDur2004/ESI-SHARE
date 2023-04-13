#include "escribir.h"

void elegir_coche(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int, char *, int);
void asignar_plazas(Estr_Vehiculo *, int , char *, char *);
void ida_vuelta(char *);
void verificar_viaje(Estr_Viaje *, int , char *, char *, char *, char *, char *, int *);
void mostrar_poblaciones(Estr_Viaje *, int, Estr_Pasos *, int, int *, int, int *);
void guardarPasajero(Estr_Usuario *, Estr_Viaje *, Estr_Reservas *, int, int *, int, int);
void verificar_reserva(Estr_Usuario *, Estr_Vehiculo *, int, Estr_Viaje *, Estr_Reservas *, int, int *, int, int *, int);

//Prototipo: void altaUsuario(Estr_Usuario *, int, Estr_Localidad *, int);
//Precondicion: Tener las estructuras "usuario" y "localidad" inicializada, con sus contadores "numUsuarios" y "numLocalidades".
//Postcondicion: Dar de alta/Registrar un usuario, comprobando que el nombre del usuario no esta repetido.

void altaUsuario(Estr_Usuario *usuario, int numUsuarios, Estr_Localidad *localidad, int numLocalidades)
{
    FILE *fp;
    int i=0, n=1, idmax=0, k=0, encontrado=0, encontrado2=0, encontrado3=0;
    char id[5], nombre[21], loc[21], perfil[14], usuario2[6], contrasena[9];

    leer_usuario(&usuario,&numUsuarios); //Volvemos a leer el fichero, para actualizar la estructura, y el contador.
    system("cls");

    fp=fopen("DATA/usuarios.txt","a+");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero viajes.txt.\n");
        return;
    }
    else
    {
        strcpy(perfil, "usuario"); //Copia la cadena "usuario" en el vector perfil, ya que solo habra 1 administrador.
        printf("Introduzca sus datos para completar el registro:\n");
        printf("Nombre Completo (Maximo de 20 caracteres):\n");
        pregunta(nombre, 21); //Funcion similar a un scanf o un fgets, pero con la eliminacion del vector nulo incorporada.
        printf("Localidad de residencia (Siglas de la lista):\n");
        pregunta_localidad(localidad, numLocalidades, loc); //Pregunta de la localidad, impriendo una lista con los acronimos de las ciudades.
        printf("Nombre de usuario (Maximo de 5 caracteres):\n");
        pregunta(usuario2, 6);

        for(k=0; k<numUsuarios&&encontrado==0; k++) //Se desplaza por toda la estructura "usuario", hasta que encuentra un usuario con mismo nick introducido.
        {
            if(strcmp(usuario2, usuario[k].usuario)==0) //Si encuentra un usuario en la base de datos con el mismo nick que hemos introducido.
            {
                encontrado=1;
            }
        }

        if(encontrado==0) //No seria necesario, pero prefiero hacerlo asi, para luego poner un aviso.
        {
            printf("El nombre de usuario es valido.\n");
            printf("Contrasena (Maximo de 8 caracteres):\n");
            pregunta(contrasena, 9);

            if(fp==NULL)
            {
                printf("No se ha podido abrir el fichero usuarios.txt.\n");
                return;
            }
            else
            {
                while(encontrado2==0) //Bucle para encontrar la id mas baja, y ocuparla.
                {
                    for(i=0;i<numUsuarios&&encontrado3==0;i++) //Nos desplazamos por la estructura "usuario", hasta que se encuentra la id mas baja.
                    {
                        idmax=atoi(usuario[i].id_usuario); //Pasa la id actual a un variable de entero.
                        if(n==idmax) //Si n es igual que la id actual, se pone encontrado3 a 1.
                            encontrado3=1;
                    }
                    if(encontrado3==1) //Si encontrado3=1, se aumenta 1 a la cantidad de n, y encontrado3 vuelve a 0, para volver al bucle.
                    {
                        n++;
                        encontrado3=0;
                    }
                    else //Si encontrado3=0, se rompe el bucle principal.
                    {
                        encontrado2=1;
                    }
                }

                snprintf(id, sizeof(id), "%04d", n); //Pasa la nueva id a una cadena de 4 caracteres.

                fprintf(fp, "%s-%s-%s-%s-%s-%s\n", id, nombre, loc, perfil, usuario2, contrasena); //Se imprimen todos los datos del registro en el fichero "usuarios.txt".

                printf("El usuario ha sido agregado correctamente.\n");
                system("PAUSE");
            }
        }
        else //Aparece aviso de que el usuario esta siendo usado.
        {
            printf("El nombre de usuario ya esta siendo usado.\n");
            system("PAUSE");
        }
    }
    fclose(fp);

    leer_usuario(&usuario,&numUsuarios); //Volvemos a leer el fichero, para actualizar la estructura "usuario", y el contador de usuarios, "numUsuarios".
}

//Prototipo: void altaVehiculo(Estr_Usuario *, Estr_Vehiculo *, int, int);
//Precondicion: Tener la variable "i", con la posicion del usuario en la estructura "usuario", y las estructuras "vehiculo" y "usuario" inicializadas, con su contador "numVehiculos".
//Postcondicion: Dar de alta/Registrar un vehiculo, comprobando que la matricula es valida, y no esta en uso.

void altaVehiculo(Estr_Usuario *usuario, Estr_Vehiculo *vehiculo, int numVehiculos, int i)
{
    FILE *fp;
    int error_mat, counter;
    char mat[8], plazas[2], descrip[51];

    leer_vehiculo(&vehiculo,&numVehiculos); //Volvemos a leer el fichero, para actualizar la estructura "vehiculo", y el contador de vehiculos, "numVehiculos".
    system("cls");

    fp=fopen("DATA/vehiculos.txt","a+");

    do{ //Se repite hasta que la matricula sea valida.
        error_mat=0;
        system("cls");
        printf("Introduzca los datos de su vehiculo para completar su registro:\nMatricula del vehiculo (Maximo de 7 caracteres):\n");
        fflush(stdin);
        scanf("%7s", mat);
        for(counter=0;(counter<numVehiculos)&&(error_mat==0);counter++) //Nos desplazamos por toda la estructura "vehiculo" para ver si es valida.
        {
            if(strcmp(mat,vehiculo[counter].id_mat)==0) //Si la matricula introducida, coincide con la de un vehicula de la estructura, pues la matricula esta en uso.
            {
                error_mat=1;
                system("cls");
                printf("La matricula %s esta actualmente registrada.\n", mat);
                system("PAUSE");
            }
        }

        if(strlen(mat)<7) //Comprueba que la longitud de la matricula es de 7 caracteres.
        {
            system("cls");
            printf("La matricula %s debe poseer una longitud total de 7 caracteres.\n", mat);
            system("PAUSE");
        }

        for(counter=0;(counter<4)&&(error_mat==0);counter++) //Nos desplazamos por los 4 primeros caracteres de la matricula, para saber si son numeros, mediante sus valores ASCII.
        {
            if((mat[counter]<48)||(mat[counter]>57))
            {
                error_mat=1;
                printf("Los 4 primeros caracteres de la matricula tienen que ser numeros.\n");
                system("PAUSE");
            }
        }
        for(counter=4;(counter<7)&&(error_mat==0);counter++) //Nos desplazamos por los 3 ultimos caracteres de la matricula, para saber si son letras, mediante sus valores ASCII.
        {
            if((mat[counter]<65)||(mat[counter]>90))
            {
                error_mat=1;
                printf("Los 3 ultimos caracteres de la matricula tienen que ser letras mayusculas.\n");
                system("PAUSE");
            }
        }
    }while((error_mat==1)||(strlen(mat)<7));

    printf("Numero de plazas libres (sin contar el conductor):\n");
    pregunta(plazas, 2);
    printf("Descripcion del vehiculo (Marca, modelo, color, etc) (Maximo de 50 caracteres):\n");
    pregunta(descrip, 51);

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else
    {
        fprintf(fp, "%s-%s-%s-%s\n", mat, usuario[i].id_usuario, plazas, descrip); //Se imprimen todos los datos del registro en el fichero "vehiculos.txt".
    }

    fclose(fp);

    leer_vehiculo(&vehiculo,&numVehiculos); //Volvemos a leer el fichero, para actualizar la estructura "vehiculo", y el contador de vehiculos, "numVehiculos".
}

//Prototipo: void altaAdmin(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondicion: Necesario la introduccion de un entero, para saber si queremos registrar un vehiculo o un viaje. Tener las estructuras inicializadas, con sus contadores.
//Postcondicion: Si n=0, dar de alta/registrar un vehiculo, comprobando que la matricula es valida, y no esta en uso,
//y si n=1, dar de alta/registrar un viaje. Ambos, introduciendo la id del usuario al que se quiere crear.

void altaAdmin(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int n)
{
    char opc2[5];
    int encontrado=0, i=0, counter;

    system("cls");
    listarUsuarios(usuario, numUsuarios);
    printf("Escriba la ID del usuario al que quiera dar de alta el vehiculo.\n");
    scanf("%4s",opc2);
    for(counter=0;(counter<numUsuarios)&&(encontrado==0);counter++) //Nos desplazamos por la estructura "usuario", hasta saber que la id introducida es valida.
    {
        if(strcmp(opc2,usuario[counter].id_usuario)==0) //Si la id introducida es igual que la id actual.
        {
            encontrado=1;
            i=counter;
            if(n==0)
            {
                altaVehiculo(usuario, vehiculo, numVehiculos, i); //Usamos la funcion altaVehiculo, para reusar codigo.
                printf("El vehiculo se ha agregado correctamente al usuario %s, con ID %s.\n", usuario[counter].nomb_usuario, usuario[counter].id_usuario);
                system("PAUSE");
            }
            if(n==1)
            {
                altaViaje(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i, 1);
                //Usamos la funcion altaViaje, para reusar codigo.
                printf("El viaje se ha agregado correctamente al usuario %s, con ID %s.\n", usuario[counter].nomb_usuario, usuario[counter].id_usuario);
                system("PAUSE");
            }
        }
    }

    if(encontrado==0) //Si no se encuentra el usuario, se imprime un aviso.
    {
        system("cls");
        printf("No se ha encontrado ningun usuario con la siguiente ID: %s\n",opc2);
        system("PAUSE");
    }
}

//Prototipo: void altaViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int, int);
//Precondicion:se necesitara la variable numUsuarios que respresenta al usuario en la estructura Usuarios.
//Ademas se necesitaran las estructuras de "vehiculos", "viajes", "pasos", "reservas", "localidad", "rutas", con sus respectivos contadores.
//Cabecera: esta funcion se usa para que el conductor cree viajes ingresando valores como la matricula del coche la fecha, las horas de inicio y fin o el coste,
//y asignadose otros valores automaticamente como el esatdo del viaje, la id del viaje o las plazas de este.
//Postcondicion: se crea una nueva estructura "Viajes" que contendra los datos correspondientes al nuevo viaje creado por el conductor y se habra anadido al fichero el nuevo viaje

void altaViaje(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int num_usuario, int num)
{
    FILE *fv;
    int n=1, i, idmax=0, breakp=0, enc=0, precio=0, rp, encontrado=0;
    char viaje_id[7], id_vehiculo[8], fecha[11], hora_inic[6], hora_fin[6], plazas[2], idavuelta[7], coste[5], estado[8];

    leer_usuario(&usuario,&numUsuarios); //Volvemos a leer el fichero, para actualizar la estructura, y el contador.
    leer_vehiculo(&vehiculo, &numVehiculos);
    leer_viaje(&viaje,&numViajes);
    leer_pasos(&pasos, &numPasos);
    leer_reservas(&reservas, &numReservas);
    system("cls");

    fv=fopen("DATA/viajes.txt","a+");
    do //en este bucle se ingresan todos los datos del viaje y al final se verifica si rp, si es uno deben ingresarse los datos de nuevo
    {
        rp=0;
        elegir_coche(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, num_usuario, id_vehiculo, num);//el usuario aqui elige el coche con el que va a realizar el viaje
        asignar_plazas(vehiculo, numVehiculos, id_vehiculo, plazas); //se asignan las plazas del viaje automaticamnete

        leerFecha(fecha, hora_inic, hora_fin);

        ida_vuelta(idavuelta); //se establece si el viaje es de ida o vuelta

        while(encontrado==0) //aqui se establece el coste del viaje hasta que se encuentre en el rango esatblecido
        {
            system("cls");
            printf("Establezca el coste de su viaje:\n");
            fflush(stdin);
            scanf("%i", &precio);
            if(precio>0&&precio<10)
            {
                encontrado=1;
            }
        }

        sprintf(coste, "%i", precio);

        strcpy(estado, "abierto");

        if(fv==NULL)
        {
            printf("No se ha podido abrir el fichero viajes.txt.\n");
            return;
        }
        else
        {
            while(breakp==0) //se establece de manera automatica la id del viaje
            {
                for(i=0;i<numViajes && enc==0;i++) //busca a traves de la estructura la siguiente id que se debe asignar
                {
                    idmax=atoi(viaje[i].id_viaje);
                    if(n==idmax)
                        enc=1;
                }
                if(enc==1)
                {
                    n++;
                    enc=0;
                }
                else
                {
                    breakp=1;
                }
            }

            snprintf(viaje_id, sizeof(viaje_id), "%06d", n); //pasa la id nueva a un vector limitado por 7 espacios.

            verificar_viaje(viaje, numViajes, viaje_id, id_vehiculo, fecha, hora_inic, hora_fin, &rp);//se verifica si los datos corresponden con los de algun viaje creado antes
            if(rp==0)
            {
                fprintf(fv, "%s-%s-%s-%s-%s-%s-%s-%s-%s\n", viaje_id, id_vehiculo, fecha, hora_inic, hora_fin, plazas, idavuelta, coste, estado);
                fclose(fv);
                leer_viaje(&viaje, &numViajes);
                system("cls");
                buscadorRutas(ruta, numRutas, numRutas2, localidad, numLocalidades, pasos, numPasos, viaje_id);
            }
            else
            {
                printf("ERROR/ No se pueden asignar dos viajes con el mismo vehiculo en la misma fecha, a no ser que el viaje este finalizado o anulado.\n");
                system("PAUSE");
            }
        }
    }while(rp==1);
    fclose(fv);
}

//Prototipo: void elegir_coche(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int, char *, int)
//Precondicion:se necesitara la variable numUsuarios que respresenta al usuario en la estructura Usuarios;
//ademas se necesitaran las estructuras de "vehiculos", "viajes", "pasos", "reservas", "localidad", "rutas", con sus respectivos contadores.
//Cabecera: Esta funcion le muestra al usuario todos los coches que tiene registrados, con los cuales podra realizar el viaje.
//Postcondicion: devuelve un dato de tipo caracter, que es la matricula del coche que ha elegido el condcutor para realizar el viaje

void elegir_coche(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int num_usuario, char *id_vehiculo, int num) //0 para usuario, y 1 para admin
{
    int i,*vec_vehiculo=NULL, coches, encontrado=0, opc=0, breakp=0;

    encontrarVehiculos(usuario, vehiculo, numVehiculos, &vec_vehiculo, &coches, num_usuario);

    if(coches==0) //verifica si se ha encontrado algun coche, en caso de que no se hayan encontrado
    {
        if(num==0) //si num=0, es para usuario
        {
            do
            {
                system("cls");
                printf("No tiene ningun vehiculo registrado.\n\n");
                printf("¿Que quiere hacer?\n");
                printf("(1)Registrar un vehiculo.\n");
                printf("(2)Volver al menu.\n");
                scanf("%d",&opc);
                switch(opc)
                {
                    case 1:
                        breakp=1;
                        altaVehiculo(usuario, vehiculo, numVehiculos, num_usuario);
                        menuConductorViajes(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, num_usuario);
                        break;
                    case 2:
                        breakp=1;
                        menuConductorViajes(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, num_usuario);
                        break;
                }
            }while(breakp==0);
        }
        if(num==1) //si num=1, es para admin
        {
            do
            {
                system("cls");
                printf("El usuario %s, con ID %s no tiene ningun vehiculo registrado.\n\n", usuario[num_usuario].nomb_usuario, usuario[num_usuario].id_usuario);
                printf("¿Que quiere hacer?\n");
                printf("(1)Registrar un vehiculo.\n");
                printf("(2)Volver al menu.\n");
                scanf("%d",&opc);
                switch(opc)
                {
                    case 1:
                        breakp=1;
                        altaVehiculo(usuario, vehiculo, numVehiculos, num_usuario);
                        menuAdminViajes(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, num_usuario);
                        break;
                    case 2:
                        breakp=1;
                        menuAdminViajes(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, num_usuario);
                        break;
                }
            }while(breakp==0);
        }
    }
    else //caso contrario se encontraron coches
    {
        do //el usuario elige uno de sus coches
        {
            system("cls");
            printf("Introduzca sus datos para completar el registro del viaje:\n");
            printf("Elija el vehiculo que desea usar:\n\n");

            for(i=0;i<coches;i++)
            {
                color(0, 3);
                printf("Matricula: ");
                color(0, 15);
                printf("%s\n", vehiculo[vec_vehiculo[i]].id_mat);
                color(0, 2);
                printf("Nº de plazas: ");
                color(0, 15);
                printf("%s\n",vehiculo[vec_vehiculo[i]].num_plazas);
                color(0, 4);
                printf("Descripcion: ");
                color(0, 15);
                printf("%s\n\n",vehiculo[vec_vehiculo[i]].desc_veh);
            }

            printf("Introduzca la matricula del vehiculo que desea usar para el viaje:\n");
            preguntar_veh(vehiculo, numVehiculos, id_vehiculo, &encontrado);
        }while(encontrado==0);//se repite hasta que encontrado sea distinto de 0
    }
}

//Prototipo:void asignar_plazas(Estr_Vehiculo *, int , char *, char *);
//Precondicion:esta funcion debe recicibir la estructura "vehiculo" y su respectivo contador, ademas debe recibir un dato de tipo entero que representa la matricula del coche elegido por el usuario anteriormente.
//Cabecera: esta funcion devuelve el numero de plzas del coche elegido para que sean asignadas al coche.
//Postcondicion: esta funcion devuelve a traves del puntero de tipo entero plazas el numero de plazas del coche elegido para que luegon sean asignadas al viaje.

void asignar_plazas(Estr_Vehiculo *vehiculo, int numVehiculos, char *id_vehiculo, char *plazas)
{
    int i,breakp=0;

    for(i=0;i<numVehiculos&&breakp==0;i++) //busca en la estructura vehiculo el que coincide con el coche elegido anteriormente
    {
        if(strcmp(vehiculo[i].id_mat,id_vehiculo)==0)
        {
            breakp=1;
            strcpy(plazas,vehiculo[i].num_plazas);
        }
    }
}

//Prototipo:void ida_vuelta(char *);
//Precondicion:recibe un char
//Postcondicion:devuelve un char que indica si el viaje es de ida-vuelta

void ida_vuelta(char *idavuelta)
{
    int opc=0, breakp=0;

    do //no se sale del bucle hasta que el usuario no haya elegido la opcion correcta
    {
        system("cls");
        printf("Seleccione el tipo de viaje que quiere:\n");
        printf("(1)Ida.\n");
        printf("(2)Vuelta.\n");
        fflush(stdin);
        scanf("%1i",&opc);
        switch(opc)
        {
            case 1:
                breakp=1;
                strcpy(idavuelta,"ida");
                break;
            case 2:
                breakp=1;
                strcpy(idavuelta,"vuelt");
                break;
        }
    }while(breakp==0);
}

//Prototipo: void verificar_viaje(Estr_Viaje *, int , char *, char *, char *, char *, char *, int *)
//Precondicion:esta funcion recibe la estructura viajes inicializada y su contador,junto con datos de tipo caracter como la id del viaje que se ha creado, la matricula
//la fecha, hora de inicio y fin
//Cabecera:el objetivo de esta funcion es el de verificar si los datos del viaje que se esta creando no coinciden con los de un viaje creado previamente por el usuario
//Postcondicion: devuelve un puntero de tipo entero "rp" que indica si el viaje creado ya se habia creado previamente.

void verificar_viaje(Estr_Viaje *viaje, int numViajes, char *id, char *mat, char *fecha, char *hor_i, char *hor_f, int *rp)
{
    int i, brkp=0;

    for(i=0;i<numViajes&&brkp==0;i++)//recorre la estructura viajes hasta que brkp es distinto de 0
    {
        if(strcmp(mat,viaje[i].id_mat)==0)//verifica si el coche seleccionado es el mismo que el de otro voaje
        {
            if(strcmp(fecha,viaje[i].f_inic)==0)//verifica si las fechas son las mismas
            {
                if(strcmp(viaje[i].estado,"finalizado")!=0 && strcmp(viaje[i].estado,"anulado")!=0)//verifica si el viaje esta activo
                {
                    (*rp)=1;
                    brkp=1;
                }
            }
        }
    }
}

//Prototipo: void altaReserva(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);
//Precondicion://Precondicion:se necesitara la variable numUsuarios que respresenta al usuario en la estructura Usuarios,
//Ademas se necesitaran las estructuras de "vehiculos", "viajes", "pasos", "reservas", "localidad", "rutas", con sus respectivos contadores.
//Cabecera: esta funcion en dependencia de la fecha elegida por el usuario y su localidad le seran mostrados todos lo viajes disponibles impidiendole elegir los viajes ya reservados previamente o creados por el, y en caso de que
//no haya ningun viaje que pase por su localidad no se le mostrara ningun viaje y volvera al menu.
//Postcondicion:en el fichero reserva se guardara la id del viaje que el usuario haya elegido y su id y se restara una plaza al viaje, dato que tambine se modidificara en el fichero

void altaReserva(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, int num_user)
{
    int *vec=NULL, x, loc, i,seleccion=0,conf1=0,conf=0,plazas;
    char fecha[11],num_plazas[2];

    leer_usuario(&usuario,&numUsuarios); //Volvemos a leer el fichero, para actualizar la estructura, y el contador.
    leer_vehiculo(&vehiculo, &numVehiculos);
    leer_viaje(&viaje,&numViajes);
    leer_pasos(&pasos, &numPasos);
    leer_reservas(&reservas, &numReservas);
    system("cls");

    do //se repite el bucle hasta que los datos ingresados esten correctos
    {
        leer_dia(fecha);
        encontrarViajesReservas(usuario, viaje, numViajes, pasos, numPasos, num_user, fecha, &vec, &x, &loc);

        if(loc==0) //verifica si no existen viajes en tu localidad
        {
            printf("No hay viajes disponibles en tu localidad (%s), para fechas futuras.\n", usuario[num_user].localidad);
            system("PAUSE");
            conf=1;
        } //caso contrario existen viajes en tu localidad
        else if(vec==NULL) //verifica si existen viajes para la fecha que especifico el usuario
        {
            printf("No hay viajes disponibles para esa fecha (%s), prueba con otra fecha.\n", fecha);
            do
            {
                printf("Desea reservar un viaje para otra fecha:\n(1)SI\n(2)NO\n");
                scanf("%i",&i);
                switch(i)
                {
                    case 1:
                        conf=0;
                        break;
                    case 2:
                        conf=1;
                        break;
                }
            }while(i!=1 && i!=2);
        }
        else //caso contrario exiten viajes para la fecha
        {
            do
            {
                system("cls");
                printf("Viajes disponibles para el %s\n",fecha);
                for(i=0;i<x;i++) //se muestran los datos de los viajes
                {
                    color(15, 0);
                    printf("VIAJE %i:\n",i+1);
                    color(0, 3);
                    printf("ID del viaje: ");
                    color(0, 15);
                    printf("%s\n", viaje[vec[i]].id_viaje);
                    color(0, 3);
                    printf("Hora de partida: ");
                    color(0, 15);
                    printf("%s\n", viaje[vec[i]].h_inic);
                    color(0, 3);
                    printf("Hora de llegada: ");
                    color(0, 15);
                    printf("%s\n", viaje[vec[i]].h_fin);
                    color(0, 3);
                    printf("Tipo: ");
                    color(0, 15);
                    printf("%s\n", viaje[vec[i]].ida_vuelta);
                    color(0, 3);
                    printf("Estado: ");
                    color(0, 15);
                    printf("%s\n", viaje[vec[i]].estado);
                    color(0, 3);
                    printf("Nº de plazas: ");
                    color(0, 15);
                    printf("%s\n", viaje[vec[i]].plazas_libre);
                    color(0, 3);
                    printf("Precio: ");
                    color(0, 15);
                    printf("%s euros\n\n", viaje[vec[i]].precio);
                }
                printf("Elija un viaje:\n");
                scanf("%i",&seleccion);

            }while(seleccion>x || seleccion<1); //comprueba que el usuario haya elegido un viaje que se encuentre en el rango de opciones

            verificar_reserva(usuario, vehiculo, numVehiculos, viaje, reservas, numReservas, vec, seleccion-1, &conf1, num_user);

            if(conf1==0) //verifica que el viaje no haya sido reservado previamente por el usuario o creado por este
            {
                mostrar_poblaciones(viaje, numViajes, pasos, numPasos, vec, seleccion-1, &conf);

                if(conf==2) //verifica que el usuario eligio la opcion de reservar este viaje
                {
                    plazas=atoi(viaje[vec[seleccion-1]].plazas_libre);
                    plazas--;
                    sprintf(num_plazas,"%01d",plazas);
                    strcpy(viaje[vec[seleccion-1]].plazas_libre,num_plazas);
                    if(plazas==0)//verifica si las plazas del viaje seleccionado son cero para cambiar su estado a cerrado
                    {
                        strcpy(viaje[vec[seleccion-1]].estado,"cerrado");
                    }
                    actualizarViaje(viaje, numViajes);
                    guardarPasajero(usuario, viaje, reservas, numReservas, vec, seleccion-1, num_user);
                }
            }
       }
   }while(conf==0);
}

//Prototipo: void mostrar_poblaciones(Estr_Viaje *, int, Estr_Pasos *, int, int *, int, int *);
//Precondicion:la funcion recibira la estructura viajes con su contador, lo mismo con la estructura pasos, ademas de un vector de tipo entero con un dato (reserva) que es una posicion del vector
//Cabecera: esta funcion muestra las poblaciones del viaje elegido por el usuario
//Postcondicion:devuelve un entero conf que indica si el usuario desea elegir un nuevo viaje

void mostrar_poblaciones(Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, int *vec, int reserva, int *conf)
{
    int i,opc;

    for(i=0;i<numPasos;i++) //muestra todos los pasos del viaje
    {
        if(strcmp(viaje[vec[reserva]].id_viaje,pasos[i].id_viaje)==0)
        {
            printf("%s\n",pasos[i].poblacion);
        }
    }

    do{
        printf("Desea reservar este viaje :\n(1)SI\n(2)NO\n");
        scanf("%i",&opc);
        switch (opc)
        {
            case 1:
                (*conf)=2; //el usuario desea reservar el viaje
                break;
            case 2:
                (*conf)=0; //el usuario desea reservar otro viaje
                break;
            default: printf("Introduzca la opcion correcta.\n");
        }
    }while(opc!=1 && opc!=2); //comprueba que el usuario haya elegido un viaje que se encuentre en el rango de opciones
}

//Prototipo: void guardarPasajero(Estr_Usuario *, Estr_Viaje *, Estr_Reservas *, int, int *, int, int);
//Precondicion:esta funcion recibe la estructura "Usuarios" y "Reservas" con sus contadores, un vecto de tipo entero, un entero que es una posicion del vector y un entero que es el usuario en la estructura.
//Cabecera:esta funcion guarda en el fichero reserva la id del viaje reservado y su id.
//Postcondicion:se guarda en el fichero reserva la id del viaje reservado y el del usuario

void guardarPasajero(Estr_Usuario *usuario, Estr_Viaje *viaje, Estr_Reservas *reservas, int numReservas, int *vec, int reserva, int num_user)
{
    FILE *fp;

    fp=fopen("DATA/reservas.txt","a+");
    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero reservas.txt.\n");
        return;
    }
    else
    {
        fprintf(fp,"%s-%s\n",viaje[vec[reserva]].id_viaje,usuario[num_user].id_usuario);
    }
    fclose(fp);
    leer_reservas(&reservas, &numReservas); // escribe en la estructura reservas la id del viaje y del usuario
}

//Prototipo: void verificar_reserva(Estr_Usuario *, Estr_Vehiculo *, int, Estr_Viaje *, Estr_Reservas *, int, int *, int, int *, int);
//Precondicion:recibe las estructuras "Usuario", "Vehiculo","Reserva","Viaje" y sus respectivos contadores, ademas de un vector de tipo entero
//ya inicializado y una variable que inidica las posiciones en este vector, y una variable que indica la posicion del usuario en la estructura usuario.
//Cabecera: esta funcion verifica que el usuario no haya reservado el viaje previamente o lo haya creado.
//Postcondicion: devuelve un puntero n que indica si el usuario ha reservado anteriormete el viaje o lo ha creado.

void verificar_reserva(Estr_Usuario *usuario, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, Estr_Reservas *reservas, int numReservas, int *vec, int reserva, int *n, int num_user)
{
    int i;
    for(i=0;i<numVehiculos && *n==0;i++) //recorre la estructura vehiculos
    {
        if(strcmp(viaje[vec[reserva]].id_mat,vehiculo[i].id_mat)==0) //verifica que la matricula del viaje a reservar es la misma que la de algun coche del usuario
        {
            if(strcmp(vehiculo[i].id_usuario,usuario[num_user].id_usuario)==0)
            {
                printf("ERROR/No puede reservar un viaje creado por usted\n");
                *n=1;
            }
        }
    }
    if((*n)!=1)
    {
       for(i=0;i<numReservas;i++)
       {
            if(strcmp(reservas[i].id_usuario,usuario[num_user].id_usuario)==0) //verifica que el usuario no haya reservado el mismo viaje
            {
                printf("ERROR/No puede reservar un viaje ya reservado previamente\n");
                *n=1;
            }
        }
    }
    system("PAUSE");
}

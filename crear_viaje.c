#include "crear_viaje.h"
//Prototipo:void altaViaje(Estr_Usuario *, int , Estr_Vehiculo *, int , Estr_Viaje *, int numViajes, Estr_Pasos *, int , Estr_Reservas *, int , Estr_Localidad *, int , Estr_Rutas **, int , int , int , int );
//Precondicion:se necesitara la variable numUsuarios que respresenta al usuario en la estructura Usuarios;
//ádemas se necesitaran las estructuras de "vehiculos", "viajes", "pasos", "reservas", "localidad", "rutas", con sus respectivos contadores.
//Cabecera:esta funcion se usa para que el conductor cree viajes ingresando valores como la matricula del coche la fecha, las horas de inicio y fin o el coste,
//y asignadose otros valores automaticamente como el esatdo del viaje, la id del viaje o las plazas de este.
//Postcondicion:se crea una nueva estructura "Viajes" que contendra los datos correspondientes al nuevo viaje creado por el conductor y se habra añadido al fichero el nuevo viaje

void altaViaje(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int num_usuario, int num)
{
    FILE *fv;
    int n=1, i, idmax=0, num_viaje, breakp=0, enc=0, precio=0, rp, encontrado=0;
    char viaje_id[7], id_vehiculo[8], fecha[11], hora_inic[6], hora_fin[6], plazas[2], idavuelta[7], coste[5], estado[8];

    leer_viaje(&viaje,&numViajes);
    system("cls");

    fv=fopen("DATA/viajes.txt","a+");
    do{//en este bucle se ingresan todos los datos del viaje y al final se verifica si rp, si es uno deben ingresarse los datos de nuevo
        rp=0;
        elegir_coche(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, num_usuario, id_vehiculo, num);//el usuario aqui elige el coche con el que va a realizar el viaje
        asignar_plazas(vehiculo, numVehiculos, id_vehiculo, plazas);//se asignan las plazas del viaje automaticamnete

        leerFecha(fecha, hora_inic, hora_fin);

        ida_vuelta(idavuelta);// se establece si el viaje es de ida o vuelta

        while(encontrado==0)//aqui se establece el coste del viaje hasta que se encuentre en el rango esatblecido
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
            while(breakp==0)// se establece de manera automatica la id del viaje
            {
                for(i=0;i<numViajes && enc==0;i++)//busca a traves de la estructura la siguiente id que se debe asignar
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
            if(rp==0)/
            {
                fprintf(fv, "%s-%s-%s-%s-%s-%s-%s-%s-%s\n", viaje_id, id_vehiculo, fecha, hora_inic, hora_fin, plazas, idavuelta, coste, estado);
                fclose(fv);
                leer_viaje(&viaje, &numViajes);
                system("cls");
                buscadorRutas(ruta, numRutas, numRutas2, localidad, numLocalidades, pasos, numPasos, viaje_id);
            }
            else
            {
                printf("ERROR/ No se pueden asignar dos viajes con el mismo vehículo en la misma fecha, a no ser que el viaje esté finalizado o anulado.\n");
                system("PAUSE");
            }
        }
    }while(rp==1);
    fclose(fv);
}
//Prototipo: void elegir_coche(Estr_Usuario *, int , Estr_Vehiculo *, int , Estr_Viaje *, int , Estr_Pasos *, int , Estr_Reservas *, int , Estr_Localidad *, int , Estr_Rutas **, int , int , int , char *, int )
//Precondicion:se necesitara la variable numUsuarios que respresenta al usuario en la estructura Usuarios;
//ádemas se necesitaran las estructuras de "vehiculos", "viajes", "pasos", "reservas", "localidad", "rutas", con sus respectivos contadores.
//Cabecera: Esta funcion le muestra al usuario todos los coches que tiene registrados, con los cuales podra realizar el viaje.
//Postcondicion: devuelve un dato de tipo caracter, que es la matricula del coche que ha elegido el condcutor para realizar el viaje
void elegir_coche(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int num_usuario, char *id_vehiculo, int num) //0 para usuario, y 1 para admin
{
    int i,*vec_vehiculo=NULL, coches, encontrado=0, opc=0, breakp=0;

    encontrarVehiculos(usuario, vehiculo, numVehiculos, &vec_vehiculo, &coches, num_usuario);

    if(coches==0)//verifica si se ha encontrado algun coche
    {//en caso de que no se hayan encontrado
        if(num==0)//si es para usuario
        {
            do
            {
                system("cls");
                printf("No tiene ningun vehiculo registrado.\n\n");
                printf("¿Qué quiere hacer?\n");
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
        if(num==1)//si es para admin
        {
            do
            {
                system("cls");
                printf("El usuario %s, con ID %s no tiene ningun vehiculo registrado.\n\n", usuario[num_usuario].nomb_usuario, usuario[num_usuario].id_usuario);
                printf("¿Qué quiere hacer?\n");
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
    }else//caso contrario se encontraron coches
    {
        do//el usuario elige uno de sus coches
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

                printf("Introduzca la matrícula del vehiculo que desea usar para el viaje:\n");
                preguntar_veh(vehiculo, numVehiculos, id_vehiculo,&encontrado);

          }while(encontrado==0);//se repite hasta que encontrado sea distinto de 0
    }


}
//Prototipo:void asignar_plazas(Estr_Vehiculo *, int , char *,char *)
//Precondicion:esta funcion debe recicibir la estructura "vehiculo" y su respectivo contador, ademas debe recibir un dato de tipo entero que representa la matricula del coche elegido por el usuario anteriormente.
//Cabecera: esta funcion devuelve el numero de plzas del coche elegido para que sean asignadas al coche.
//Postcondicion: esta funcion devuelve a traves del puntero de tipo entero plazas el numero de plazas del coche elegido para que luegon sean asignadas al viaje.
void asignar_plazas(Estr_Vehiculo *vehiculo, int numVehiculos, char *id_vehiculo,char *plazas)
{
    int i,breakp=0;

    for(i=0;i<numVehiculos&&breakp==0;i++)//busca en la estructura vehiculo el que coincide con el coche elegido anteriormente
    {
        if(strcmp(vehiculo[i].id_mat,id_vehiculo)==0)
        {
            breakp=1;
            strcpy(plazas,vehiculo[i].num_plazas);
        }
    }
}
//Prototipo:void ida_vuelta(char *)
//Precondicion:recibe un char
//Postcondicion:devuelve un char que indica si el viaje es de ida-vuelta

void ida_vuelta(char *idavuelta)
{
    int opc=0, breakp=0;

    do//no se sale del bucle hasta que el usuario no haya elegido la opcion correcta
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
//Prototipo:void finalizar_viaje(Estr_Usuario *, Estr_Vehiculo *, int , Estr_Viaje *, int , Estr_Pasos *, int , Estr_Reservas *, int , int )
//Precondicion://Precondicion:se necesitara la variable numuser que respresenta al usuario en la estructura Usuarios;
//ádemas se necesitaran las estructuras de "vehiculos", "viajes", "pasos", "reservas", con sus respectivos contadores.
//Cabecera: esta funcion tiene una doble finalidad, que seran finalizar y anular los viajes del conductor.
//Postcondicion: el viaje elegido por el usuario sera finalizado o anulado, modificandose el estado del viaje.

void finalizar_viaje(Estr_Usuario *usuario, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, int num_user)
{
    int *vec=NULL, x=0, *vec_viaje=NULL, max_viaje=0, i=0, j;

    encontrarVehiculos(usuario, vehiculo, numVehiculos, &vec, &x, num_user);

    if(vec!=NULL)//verifica si se han encontrado vehiculos
    {
        for(j=0;j<x;j++)//para los vehiculos encontrados verifica si tiene asignado viajes
        {
            encontrarViajes(vehiculo, numVehiculos, viaje, numViajes, vehiculo[vec[j]].id_mat, &vec_viaje, &max_viaje, 1);
        }
        if(vec_viaje!=NULL)//verifica si se encontraron viajes para los coches encontrados
        {
            printf("LISTADO DE SUS VIAJES:\n");
            for(j=0;j<max_viaje;j++)//se muetsran en pantalla esos viajes
            {
                printf("(%i)%s-%s-%s-%s-%s-%s-%s-%s-%s\n",j+1,viaje[vec_viaje[j]].id_viaje,viaje[vec_viaje[j]].id_mat,viaje[vec_viaje[j]].f_inic,viaje[vec_viaje[j]].h_inic,viaje[vec_viaje[j]].h_fin,viaje[vec_viaje[j]].plazas_libre,viaje[vec_viaje[j]].ida_vuelta,viaje[vec_viaje[j]].precio,viaje[vec_viaje[j]].estado);
            }

            do{//verifica que se seleccione la opcion correcta
                printf("Seleccione el viaje que desea finalizar/anular:\n");
                scanf("%i",&i);
            }while(i>max_viaje||i<0);

            system("cls");
            if(strcmp(viaje[vec_viaje[i-1]].estado, "abierto")==0)//verifica si el viaje seleccionado esta abierto
            {
                strcpy(viaje[vec_viaje[i-1]].estado, "anulado");
                printf("El viaje ha sido anulado\n");
            }
            else// caso contrario esta iniciado
            {
                strcpy(viaje[vec_viaje[i-1]].estado, "finalizado");
                printf("El viaje ha sido finalizado\n");
            }
            system("PAUSE");
            actualizar(viaje, numViajes);
            eliminarPasos(pasos, numPasos, viaje[vec_viaje[i-1]].id_viaje);
            eliminarReservas(reservas, numReservas, viaje[vec_viaje[i-1]].id_viaje);
        }
        else//caso contrario no hay viajes registrado para los coches del usuario
        {
            system("cls");
            printf("No tiene viajes registrados\n");
            system("PAUSE");
        }
    }
    else//caso contrario el usuario no tiene coches registrados
    {
        system("cls");
        printf("No tiene coches registrados\n");
        system("PAUSE");
    }
}
//Prototipo:void actualizar(Estr_Viaje *, int )
//Precondicion:esta funcion recibe la estructura viajes ya inicializada y su contador correcpondiente.
//Cabecera: esta funcion se encarga de actualizar el fichero viajes.
//Postcondicion:el fichero de viajes queda actualizado.
void actualizar(Estr_Viaje *viaje, int numViajes){
    int counter=0;

    FILE *fp;
    fp=fopen("DATA/viajes_replace.txt","w+");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero");
    }
    else
    {

        for(counter=0;counter<numViajes;counter++)//imprime en el fichero viajes todos los datos de la estructura
        {
            fprintf(fp , "%s-%s-%s-%s-%s-%s-%s-%s-%s\n" ,viaje[counter].id_viaje,viaje[counter].id_mat,viaje[counter].f_inic,viaje[counter].h_inic,viaje[counter].h_fin,viaje[counter].plazas_libre,viaje[counter].ida_vuelta,viaje[counter].precio,viaje[counter].estado);
        }
    }

    fclose(fp);

    remove("DATA/viajes.txt");
    rename("DATA/viajes_replace.txt","DATA/viajes.txt");
}
//Prototipo:void verificar_viaje(Estr_Viaje *, int , char *, char *, char *, char *,char *,int *)
//Precondicion:esta funcion recibe la estructura viajes inicializada y su contador,junto con datos de tipo caracter como la id del viaje que se ha creado, la matricula
//la fecha, hora de inicio y fin
//Cabecera:el objetivo de esta funcion es el de verificar si los datos del viaje que se esta creando no coinciden con los de un viaje creado previamente por el usuario
//Postcondicion: devuelve un puntero de tipo entero "rp" que indica si el viaje creado ya se habia creado previamente.

void verificar_viaje(Estr_Viaje *viaje, int numViajes, char *id, char *mat, char *fecha, char *hor_i,char *hor_f,int *rp)
{
    int i,brkp=0;

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

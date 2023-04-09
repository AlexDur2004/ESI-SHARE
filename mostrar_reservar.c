#include "mostrar_reservar.h"
//Prototipo:void mostrar_reservar(Estr_Usuario *, int , Estr_Vehiculo *, int , Estr_Viaje *, int , Estr_Pasos *, int , Estr_Reservas *, int , int )
//Precondicion://Precondicion:se necesitara la variable numUsuarios que respresenta al usuario en la estructura Usuarios;
//ádemas se necesitaran las estructuras de "vehiculos", "viajes", "pasos", "reservas", "localidad", "rutas", con sus respectivos contadores.
//Cabecera: esta funcion en dependencia de la fecha elegida por el usuario y su localidad le seran mostrados todos lo viajes disponibles impidiendole elegir los viajes ya reservados previamente o creados por el, y en caso de que
//no haya ningun viaje que pase por su localidad no se le mostrara ningun viaje y volvera al menu.
//Postcondicion:en el fichero reserva se guardara la id del viaje que el usuario haya elegido y su id y se restara una plaza al viaje, dato que tambine se modidificara en el fichero

void mostrar_reservar(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, int num_user)
{
    int *vec=NULL, x, loc, i,seleccion=0,conf1=0,conf=0,plazas;
    char fecha[11],num_plazas[2];

    do//se repite el bucle hasta que los datos ingresados esten correctos
    {
        leer_dia(fecha);
        encontrarViajesReservas(usuario, viaje, numViajes, pasos, numPasos, num_user, fecha, &vec, &x, &loc);

        if(loc==0)//verifica si no existen viajes en tu localidad
        {
            printf("No hay viajes disponibles en tu localidad (%s), para fechas futuras.\n", usuario[num_user].localidad);
            system("PAUSE");
            conf=1;
        }//caso contrario existenviajes en tu localidad
        else if(vec==NULL)//verifica si existen viajes para la fecha que especifico el usuario
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
        else//caso contrario exiten viajes para la fecha
        {
            do
            {
                system("cls");
                printf("Viajes disponibles para el %s\n",fecha);
                for(i=0;i<x;i++)//se muestran los datos de los viajes
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

            }while(seleccion>x || seleccion<1);//comprueba que el usuario haya elegido un viaje que se encuentre en el rango de opciones

            verificar_reserva(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, reservas, numReservas, vec, seleccion-1, &conf1, num_user);

            if(conf1==0)//verifica que el viaje no haya sido reservado previamente por el usuario o creado por este
            {
                mostrar_poblaciones(viaje, numViajes, pasos, numPasos, vec, seleccion-1, &conf);

                if(conf==2)//verifica que el usuario eligio la opcion de reservar este viaje
                {
                    plazas=atoi(viaje[vec[seleccion-1]].plazas_libre);
                    plazas--;
                    sprintf(num_plazas,"%01d",plazas);
                    strcpy(viaje[vec[seleccion-1]].plazas_libre,num_plazas);
                    if(plazas==0)//verifica si las plazas del viaje seleccionado son cero para cambiar su estado a cerrado
                    {
                        strcpy(viaje[vec[seleccion-1]].estado,"cerrado");
                    }
                    actualizarFichero(viaje, numViajes);
                    guardarPasajero(usuario, viaje, reservas, numReservas, vec, seleccion-1, num_user);
                }
            }
       }
   }while(conf==0);
}
//Prototipo:void mostrar_poblaciones(Estr_Viaje *, int , Estr_Pasos *, int , int *, int , int *)
//Precondicion:la funcion recibira la estructura viajes con su contador, lo mismo con la estructura pasos, ademas de un vector de tipo entero con un dato (reserva) que es una posicion del vector
//Cabecera: esta funcion muestra las poblaciones del viaje elegido por el usuario
//Postcondicion:devuelve un enetero conf que indica si el usuario desea elegir un nuevo viaje
void mostrar_poblaciones(Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, int *vec, int reserva, int *conf)
{
    int i,opc;

    for(i=0;i<numPasos;i++)//muestras todos los pasos del viaje
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
                (*conf)=2;//el usuario desea reservar el viaje
                break;
            case 2:
                (*conf)=0;//el usuario desea reservar otro viaje
                break;
            default: printf("Introduzca la opción correcta.\n");
        }
    }while(opc!=1 && opc!=2);//comprueba que el usuario haya elegido un viaje que se encuentre en el rango de opciones
}
//void actualizarFichero(Estr_Viaje *, int )
//Precondicion:esta funcion recibe la estructura "Viajes" y su contador
//Cabecera:esta funcion actualiza el fichero viajes
//Postcondicion:el fichero viaje queda actualizado
void actualizarFichero(Estr_Viaje *viaje, int numViajes)
{
    int i;

    FILE *fp;
    fp=fopen("DATA/viajes_replace.txt","w+");
    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero");
    }
    else
    {

        for(i=0;i<numViajes;i++)
        {
            fprintf(fp,"%s-%s-%s-%s-%s-%s-%s-%s-%s\n",viaje[i].id_viaje,viaje[i].id_mat,viaje[i].f_inic,viaje[i].h_inic,viaje[i].h_fin,viaje[i].plazas_libre,viaje[i].ida_vuelta,viaje[i].precio,viaje[i].estado);
        }
    }

    fclose(fp);

    remove("DATA/viajes.txt");
    rename("DATA/viajes_replace.txt","DATA/viajes.txt");
    leer_viaje(&viaje,&numViajes);
}
//Prototipo:void guardarPasajero(Estr_Usuario *usuario, Estr_Viaje *viaje, Estr_Reservas *reservas, int numReservas, int *vec, int reserva, int num_user)
//Precondicion:esta funcion recibe la estructura "Usuarios" y "Reservas" con sus contadores, un vecto de tipo entero, un entero que es una posicion del vector y un entero que es el usuario en la estructura.
//Cabecera:esta funcion guarda en el fichero reserva la id del viaje reservado y su id.
//Postcondicion:se guarda en el fichero reserva la id del viaje reservado y el del usuario
void guardarPasajero(Estr_Usuario *usuario, Estr_Viaje *viaje, Estr_Reservas *reservas, int numReservas, int *vec, int reserva, int num_user)
{
        // crear nuevo fichero que guarde para guardar la reserva
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
    leer_reservas(&reservas,&numReservas); // escribe en la estructura reservas la id del viaje y del usuario
}
//Prototipo:void cancelarReserva(Estr_Usuario *, Estr_Viaje *, int , Estr_Reservas *, int , int )
//Precondicion:esta funcion recibe las estructuras "Usuario" y "Viajes" ya inicializadas con sus contadores, y la variables num user
//que representa la posicion del usuario en la estructura viajes
//Cabecera:esta funcion permite al usuario cancelar sus viajes siempre que no esten iniciados
//Postcondicion:el viaje seleccionado es cancelado siendo borrado de la estructura reservas el usuario
//y aumentando en uno las plazas de dicho viaje
void cancelarReserva(Estr_Usuario *usuario, Estr_Viaje *viaje, int numViajes, Estr_Reservas *reservas, int numReservas, int num_user)
{
    int *vec=NULL, *vec_viaje=NULL, x, i, sel, plazas=0;

    encontrarReservas(usuario, viaje, numViajes, reservas, numReservas, num_user, &vec, &vec_viaje, &x);//encuentra las reservas del usuario que pueden ser canceladas

    if(vec!=NULL){//verifica que el usuario tiene reservas
        do{
            printf("LISTADO DE SUS VIAJES:\n");
            for(i=0;i<x;i++)
            {
                color(15, 0);
                printf("VIAJE %i:\n",i+1);
                color(0, 3);
                printf("   ID del viaje: ");
                color(0, 15);
                printf("%s\n", viaje[vec[i]].id_viaje);
                color(0, 3);
                printf("   Fecha de partida: ");
                color(0, 15);
                printf("%s\n", viaje[vec[i]].f_inic);
                color(0, 3);
                printf("   Hora de partida: ");
                color(0, 15);
                printf("%s\n", viaje[vec[i]].h_inic);
                color(0, 3);
                printf("   Hora de llegada: ");
                color(0, 15);
                printf("%s\n", viaje[vec[i]].h_fin);
                color(0, 3);
                printf("   Tipo: ");
                color(0, 15);
                printf("%s\n", viaje[vec[i]].ida_vuelta);
                color(0, 3);
                printf("   Precio: ");
                color(0, 15);
                printf("%s euros\n\n", viaje[vec[i]].precio);
            }

            printf("Seleccione el viaje que desea cancelar:\n");
            scanf("%i",&sel);
            system("cls");
        }while(sel>x || sel<1);//comprueba que el usuario haya elegido un viaje que se encuentre en el rango de opciones

        eliminarReservas(reservas, numReservas, reservas[vec[sel-1]].id_viaje);
        leer_reservas(&reservas,&numReservas);
        plazas=atoi(viaje[vec_viaje[sel-1]].plazas_libre);//aumenta en uno las plazas
        plazas++;
        sprintf(viaje[vec_viaje[sel-1]].plazas_libre,"%01d",plazas);
        actualizarFichero(viaje, numViajes);
    }
    else
    {
        printf("No tiene viajes reservados\n");
        system("PAUSE");
    }
}
//Prototipo:void verificar_reserva(Estr_Usuario *, int , Estr_Vehiculo *, int , Estr_Viaje *, int , Estr_Reservas *, int , int *,int ,int *,int )
//Precondicion:recibe las estructuras "Usuario", "Vehiculo","Reserva","Viaje" y sus respectivos contadores, ademas de un vector de tipo entero
//ya inicializado y una variable que inidica las posiciones en este vector, y una variable que inidica
//la posicion del usuario en la estructura usuario.
//Cabecera:esta funcion verifica que el usuario no haya reservado el viaje previamente o lo haya creado.
//Postcondicion:devuelve un puntero n que indica si el usuario ha reservado anteriormete el viaje o lo ha creado.
void verificar_reserva(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Reservas *reservas, int numReservas, int *vec,int reserva,int *n,int num_user)
{
    int i;
    for(i=0;i<numVehiculos && *n==0;i++)//recorre la estructura vehiculos
    {
        if(strcmp(viaje[vec[reserva]].id_mat,vehiculo[i].id_mat)==0)//verifica que la matricula del viaje a reservar es la misma que la de algun coche del usuario
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
        if(strcmp(reservas[i].id_usuario,usuario[num_user].id_usuario)==0)//verifica que el usuario no haya reservado el mismo viaje
        {
            *n=1;
            printf("ERROR/No puede reservar un viaje ya reservado previamente\n");
        }
    }

    }
    system("PAUSE");
}

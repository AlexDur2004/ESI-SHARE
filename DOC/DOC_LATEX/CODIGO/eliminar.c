#include "eliminar.h"

//Prototipo: void eliminarVehiculo(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);
//Precondicion: Tener la variable "i" inicializada, que representa al usuario en la estructura "Usuarios",
//tambien necesitaremos las estructuras "Vehiculo", "Viajes", "Pasos" y "Reservas", con sus respectivos contadores.
//Postcondicion: Preguntar al usuario, que vehiculo quiere eliminar de todos los que tiene, para
//eliminar el vehiculo, con sus viajes, pasos y reservas.

void eliminarVehiculo(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, int i)
{
    int x=0, h=0, m=0, opc=0, opc2=0, *vec=NULL;

    leer_vehiculo(&vehiculo, &numVehiculos);
    system("cls");

    encontrarVehiculos(usuario, vehiculo, numVehiculos, &vec, &x, i); //Encontramos todos los vehiculos del usuario, y los colocamos en un vector de enteros,
    //con las posiciones en la estructura "vehiculo" de sus vehiculos.

    if(x>0){ //Si tiene algun vehiculo, le pregunta el coche que quiere eliminar, si no tiene vehiculo, se imprime un aviso.
        printf("Que vehiculo quiere eliminar?\n");

        for(m=0; m<x; m++) //Imprimimos todos los coches que tiene el usuario.
        {
            printf("(%i)%s-%s-%s\n", m+1, vehiculo[vec[m]].id_mat, vehiculo[vec[m]].num_plazas, vehiculo[vec[m]].desc_veh);
        }
        m++;
        printf("(%i)Salir.\n", m);
        printf("Ingrese el numero correspondiente al vehiculo que desea eliminar: "); //Seleccion del vehiculo que quiere eliminar.
        fflush(stdin);
        scanf("%d", &opc);
        if(opc==m){ //Si introduce el numero mas alto "m", volvera a la funcion anterior, en este caso el menu.
            return;
        }
        if((opc>=1&&opc<m)&&opc!=m) //Si el numero introducido no esta en el rango que se representa, es decir,
            //es menor que 1 o es mayor que m, pues se vuelva a entrar a la funcion, funcionando como un do-while.
        {
            h=opc-1;
            do{
                opc2=0;
                system("cls");
                printf("Seguro que quieres eliminar el vehiculo %s, con matricula %s?\n", vehiculo[vec[h]].desc_veh, vehiculo[vec[h]].id_mat);
                //Si el usuario escoge el 1, se eliminara el vehiculo, si escribe 2, se volvera al menu.
                printf("(1)Si\n");
                printf("(2)No\n");
                fflush(stdin);
                scanf("%d", &opc2);
                if(opc2==1){ //Al escoger 1, nos lleva a otra funcion, que eliminara los viajes, pasos y reservas del vehiculo seleccionado.
                    system("cls");
                    eliminarVehiculoViajes(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, vehiculo[vec[h]].id_mat, x);
                    system("PAUSE");
                }
            }while((opc2<1)||(opc2>2));
        }
        else //Si el numero no esta en el rango, volvemos a entrar en la funcion.
        {
            system("cls");
            eliminarVehiculo(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, i); //Vuelva a entrar en la funcion.
        }
    }
    else //Se imprime un aviso, si no tiene vehiculos asignados.
    {
        system("cls");
        printf("No posee vehiculos registrados.\n");
        system("PAUSE");
    }
}

//Prototipo: void eliminarVehiculoViajes(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, char *, int);
//Precondicion: Tener la cadena "mat", que seria la matricula del vehiculo que se quiere eliminar, y la variable "x", que representa el numero
//de vehiculos que tiene el usuario, tambien necesitaremos las estructuras "Vehiculo", "Viajes", "Pasos" y "Reservas", con sus respectivos contadores.
//Postcondicion: Eliminar el vehiculo, a partir de la matricula, ademas de todos sus viajes, pasos y reservas.

void eliminarVehiculoViajes(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, char *mat, int x)
{
    FILE *fp, *temp;
    int n=0, j=0, k=0, num_v=0, *vec_viaje=NULL, counter, encontrado=0;

    leer_vehiculo(&vehiculo, &numVehiculos);
    leer_viaje(&viaje, &numViajes);
    system("cls");

    fp=fopen("DATA/vehiculos.txt","r+");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else
    {
        for(n=0; n<numVehiculos&&encontrado==0; n++) //Nos desplazamos por toda la estructura "vehiculo", hasta encontrar el vehiculo con la matricula deseada.
        {
            if(strcmp(vehiculo[n].id_mat, mat)==0) //Si coincide la matricula de la posicion actual en la estructura con la matricula deseada.
            {
                temp=fopen("DATA/vehiculos_Temp.txt","w+"); //Se crea un fichero temporal, donde escribir los vehiculos que hay, menos el vehiculo que se quiere eliminar.
                if(temp==NULL)
                {
                printf("No se ha podido abrir el fichero vehiculos_Temp.txt.\n");
                }
                else
                {
                    for(counter=0; counter<numVehiculos; counter++)
                    {
                        if(strcmp(vehiculo[counter].id_mat, mat)!=0) //Cuando el matricula del vehiculo, coincide con la matricula deseada, se salta de linea/omite.
                        {
                            fprintf(temp, "%s-%s-%s-%s\n", vehiculo[counter].id_mat, vehiculo[counter].id_usuario, vehiculo[counter].num_plazas, vehiculo[counter].desc_veh);
                        }
                    }
                }
                fclose(temp); //Cerramos los ficheros.
                fclose(fp);
                for(j=0; j<x; j++)
                {
                    encontrarViajes(vehiculo, numVehiculos, viaje, numViajes, vehiculo[n].id_mat, &vec_viaje, &num_v, 0); //Encontramos todos los viajes del vehiculo, para eliminarlos.
                }
                for(k=0; k<num_v; k++) //Eliminamos todos los viajes, pasos y reservas.
                {
                    eliminarSoloViaje(viaje, numViajes, pasos, numPasos, reservas, numReservas, viaje[vec_viaje[k]].id_viaje);
                    eliminarPasos(pasos, numPasos, viaje[vec_viaje[k]].id_viaje);
                    eliminarReservas(reservas, numReservas, viaje[vec_viaje[k]].id_viaje);
                }
                encontrado=1;
            }
        }
        remove("DATA/vehiculos.txt"); //Borramos el fichero original.
        rename("DATA/vehiculos_Temp.txt","DATA/vehiculos.txt"); //Cambiamos de nombre el fichero temporal por el original.
        leer_vehiculo(&vehiculo, &numVehiculos); //Volvemos a leer el fichero "vehiculos.txt", para actualizar la estructura, y el contador "numVehiculos".
    }
    fclose(fp);
}

//Prototipo: void eliminarViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);
//Precondicion: Tener la variable "i" inicializada, que representa al usuario en la estructura "Usuarios",
//Ademas se necesitaran las estructuras "Vehiculo", "Viajes", "Pasos" y "Reservas", y sus respectivos contadores.
//Postcondicion: Preguntar al usuario, que viaje quiere eliminar de todos los que tiene, para eliminar el viaje, con sus pasos y reservas.

void eliminarViaje(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, int i)
{
    int j=0, x=0, h=0, m=0, num_v=0, opc=0, opc2=0, *vec=NULL, *vec_viaje=NULL;

    leer_vehiculo(&vehiculo, &numVehiculos);
    leer_viaje(&viaje, &numViajes);
    system("cls");

    encontrarVehiculos(usuario, vehiculo, numVehiculos, &vec, &num_v, i);  //Busca los vehiculos que tiene dicho usuario, para luego encontrar los viajes que tiene.

    for(j=0;j<num_v;j++)
    {
        encontrarViajes(vehiculo, numVehiculos, viaje, numViajes, vehiculo[vec[j]].id_mat, &vec_viaje, &x, 2);
    }

    if(x>0){
        printf("Que viaje quiere eliminar?\n");

        for(m=0; m<x; m++) //Imprime una lista de todos los viajes que tiene el usuario.
        {
            printf("(%i)%s-%s-%s-%s-%s-%s-%s-%s-%s\n", m+1, viaje[vec_viaje[m]].id_viaje, viaje[vec_viaje[m]].id_mat,viaje[vec_viaje[m]].f_inic,viaje[vec_viaje[m]].h_inic,viaje[vec_viaje[m]].h_fin,viaje[vec_viaje[m]].plazas_libre,viaje[vec_viaje[m]].ida_vuelta,viaje[vec_viaje[m]].precio,viaje[vec_viaje[m]].estado);
        }
        x++;
        printf("(%i)Salir.\n", x);
        printf("Ingrese el numero correspondiente al viaje que desea eliminar: "); //Introduce el numero del viaje.
        fflush(stdin);
        scanf("%d", &opc);
        if(opc==x) //Si el numero introducido coincide con el del numero maximo "x", se vuelve al menu.
        {
            return;
        }
        if((opc>=1&&opc<x)&&opc!=x) //Si el numero introducido no esta en el rango que se representa, es decir,
            //es menor que 1 o es mayor que m, pues se vuelva a entrar a la funcion, funcionando como un do-while.
        {
            h=opc-1;
            do //Imprime un mensaje de confirmacion para eliminar el viaje seleccionado, se repite hasta que sea 1 o 2.
            {
                opc2=0;
                system("cls");
                printf("Seguro que quieres eliminar el viaje %s, con matricula %s?\n", viaje[vec_viaje[h]].id_viaje, viaje[vec_viaje[h]].id_mat);
                printf("(1)Si\n");
                printf("(2)No\n");
                fflush(stdin);
                scanf("%d", &opc2);
                if(opc2==1){ //Si seleccionamos 1, se va a la funcion, que elimina viajes, pasos y reservas, por la id del viaje.
                    system("cls");
                    eliminarSoloViaje(viaje, numViajes, pasos, numPasos, reservas, numReservas, viaje[vec_viaje[h]].id_viaje);
                }
            }while((opc2<1)||(opc2>2));
            system("cls");
            printf("Eliminado con exito\n");
            system("PAUSE");
        }
        else //Si el numero no esta en el rango, volvemos a entrar en la funcion.
        {
            system("cls");
            eliminarViaje(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, i);
        }
    }
    else{ //Se imprime un aviso, si no tiene viajes creados.
        system("cls");
        printf("No tiene viajes registrados.\n");
        system("PAUSE");
    }
}

//Prototipo: void eliminarSoloViaje(Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, char *);
//Precondicion: Tener la cadena "id" inicializada, que representa la id del viaje, que se quiere eliminar,
//al igual que las estructura "viaje", "pasos" y "reservas", con sus respectivos contadores.
//Postcondicion: Eliminar un viaje, a partir de su id, junto a todos sus pasos y reservas.

void eliminarSoloViaje(Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, char *id)
{
    FILE *fp, *temp;
    int n=0, counter, encontrado=0;

    leer_viaje(&viaje, &numViajes);
    system("cls");

    fp=fopen("DATA/viajes.txt","r+");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero viajes.txt.\n");
        return;
    }
    else
    {
        for(n=0; n<numViajes&&encontrado==0; n++) //Nos desplazamos por toda la estructura "viaje", hasta encontrar el viaje con la id deseada.
        {
            if(strcmp(viaje[n].id_viaje, id)==0) //Si la id del viaje de la posicion actual en la estructura coincide con la id deseada.
            {
                temp=fopen("DATA/viajes_Temp.txt","w+"); //Se crea un fichero temporal, donde escribir los viajes que hay, menos el viaje que se quiere eliminar.
                if(temp==NULL)
                {
                printf("No se ha podido abrir el fichero viajes_Temp.txt.\n");
                }
                else
                {
                    for(counter=0; counter<numViajes;counter++)
                    {
                        if(counter!=n) //Cuando la linea que queremos eliminar, coincide con la linea actual, se salta de linea/omite.
                        {
                            fprintf(temp, "%s-%s-%s-%s-%s-%s-%s-%s-%s\n", viaje[counter].id_viaje, viaje[counter].id_mat, viaje[counter].f_inic, viaje[counter].h_inic, viaje[counter].h_fin, viaje[counter].plazas_libre, viaje[counter].ida_vuelta, viaje[counter].precio, viaje[counter].estado);
                        }
                    }
                }
                fclose(temp); //Cerramos los ficheros.
                fclose(fp);
                eliminarPasos(pasos, numPasos, viaje[n].id_viaje); //Eliminamos los pasos y reservas de dicho viaje.
                eliminarReservas(reservas, numReservas, viaje[n].id_viaje);
                encontrado=1;
            }
        }
        remove("DATA/viajes.txt"); //Borramos el fichero original.
        rename("DATA/viajes_Temp.txt","DATA/viajes.txt"); //Cambiamos de nombre el fichero temporal por el original.
        leer_viaje(&viaje, &numViajes); //Volvemos a leer el fichero "viajes.txt", para actualizar la estructura, y el contador "numViajes".
    }
    fclose(fp);
}

//Prototipo: void eliminarPasos(Estr_Pasos *, int, char *);
//Precondicion: Tener la cadena "id" inicializada, que representa la id del viaje, al igual que la estructura "pasos", y su contador "numPasos".
//Postcondicion: Eliminar los pasos de un viaje.

void eliminarPasos(Estr_Pasos *pasos, int numPasos, char *id)
{
    FILE *fp, *temp;
    int n=0, counter;

    leer_pasos(&pasos, &numPasos);
    system("cls");

    fp=fopen("DATA/pasos.txt","r+");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero pasos.txt.\n");
        return;
    }
    else
    {
        for(n=0; n<numPasos; n++) //Nos desplazamos por toda la estructura "pasos".
        {
            if(strcmp(pasos[n].id_viaje, id)==0) //Si la id del viaje de la posicion actual en la estructura coincide con la id deseada.
            {
                temp=fopen("DATA/pasos_Temp.txt","w+"); //Se crea un fichero temporal, donde escribir los pasos que hay, menos los pasos que se quieren eliminar.
                if(temp==NULL)
                {
                printf("No se ha podido abrir el fichero pasos_Temp.txt.\n");
                }
                else
                {
                    for(counter=0; counter<numPasos;counter++)
                    {
                        if(strcmp(pasos[counter].id_viaje, id)!=0) //Cuando la id del viaje del paso que queremos eliminar,
                            //coincide con la linea actual, se salta de linea/omite.
                        {
                            fprintf(temp, "%s-%s\n", pasos[counter].id_viaje, pasos[counter].poblacion);
                        }
                    }
                }
                fclose(temp); //Cerramos los ficheros.
                fclose(fp);
            }
        }
        remove("DATA/pasos.txt"); //Borramos el fichero original.
        rename("DATA/pasos_Temp.txt","DATA/pasos.txt"); //Cambiamos de nombre el fichero temporal por el original.
        leer_pasos(&pasos, &numPasos); //Volvemos a leer el fichero "pasos.txt", para actualizar la estructura, y el contador "numPasos".
        system("cls");
    }
    fclose(fp);
}

//Prototipo: void eliminarReservas(Estr_Reservas *, int, char *);
//Precondicion: Tener la cadena "id" inicializada, que representa la id del viaje, al igual que la estructura "reservas", y su contador "numReservas".
//Postcondicion: Eliminar las reservas de un viaje.

void eliminarReservas(Estr_Reservas *reservas, int numReservas, char *id)
{
    FILE *fp, *temp;
    int n=0, counter;

    leer_reservas(&reservas, &numReservas);
    system("cls");

    fp=fopen("DATA/reservas.txt","r+");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero reservas.txt.\n");
        return;
    }
    else
    {
        for(n=0; n<numReservas; n++) //Nos desplazamos por toda la estructura "reservas".
        {
            if(strcmp(reservas[n].id_viaje, id)==0) //Si la id del viaje de la posicion actual en la estructura coincide con la id deseada.
            {
                temp=fopen("DATA/reservas_Temp.txt","w+"); //Se crea un fichero temporal, donde escribir los reservas que hay, menos las reservas que se quieren eliminar.
                if(temp==NULL)
                {
                printf("No se ha podido abrir el fichero reservas_Temp.txt.\n");
                }
                else
                {
                    for(counter=0; counter<numReservas;counter++)
                    {
                        if(strcmp(reservas[counter].id_viaje, id)!=0) //Cuando la id del viaje de la reserva que queremos eliminar,
                            //coincide con la linea actual, se salta de linea/omite.
                        {
                            fprintf(temp, "%s-%s\n", reservas[counter].id_viaje, reservas[counter].id_usuario);
                        }
                    }
                }
                fclose(temp); //Cerramos los ficheros.
                fclose(fp);
            }
        }
        remove("DATA/reservas.txt"); //Borramos el fichero original.
        rename("DATA/reservas_Temp.txt","DATA/reservas.txt"); //Cambiamos de nombre el fichero temporal por el original.
        leer_reservas(&reservas, &numReservas); //Volvemos a leer el fichero "reservas.txt", para actualizar la estructura, y el contador "numReservas".
        system("cls");
    }
    fclose(fp);
}

//Prototipo: void eliminarAdminUsuario(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int);
//Precondicion: Tener las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas",
//al igual que sus contadores "numUsuarios", "numVehiculos", "numViajes", "numPasos" y "numReservas".
//Postcondicion: Preguntar al admin, la id del usuario que quiere eliminar, para borrar dicho usuario, junto a todos sus vehiculos, viajes, pasos y reservas.

void eliminarAdminUsuario(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas)
{
    FILE *fp, *temp;
    int n=0, o=0, j=0, opc2=0, c=0, *vec=NULL, encontrado=0, encontrado2=0, id2, counter;
    char vec_id[5];

    fp=fopen("DATA/usuarios.txt","r+");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero usuarios.txt.\n");
        return;
    }
    else
    {
        if(numUsuarios>1)
        {
            do{ //Se pregunta la id del usuario para eliminarlo, hasta que la id sea correcta.
                listarUsuarios(); //Obtenemos una lista de todos los usuarios del sistema.
                printf("Que usuario quiere eliminar?\n");
                printf("Introduzca la ID del usuario que quiere eliminar.\n");
                scanf("%i", &id2);
                if(id2==1) //Si "id2" es igual a 1, se vuelve a preguntar, ya que no se puede eliminar al administrador.
                {
                    printf("No puede eliminar al ADMINITRADOR, con ID 0001.\nVuelva a intentarlo con una ID valida.\n");
                    system("PAUSE");
                }
                else
                {
                    sprintf(vec_id, "%04i", id2);
                    encontrarUsuario(usuario, numUsuarios, vec_id, &j, &encontrado); //Si la id esta en la base de datos, encontrado=1, y sale del bucle.
                }
            }while(encontrado==0);

            do //Repetir lo mismo, hasta que la opcion sea 1 o 2.
            {
                opc2=0;
                system("cls"); //Imprime mensaje de confirmacion.
                printf("Seguro que quieres eliminar el usuario %s, con ID %s?\n", usuario[j].nomb_usuario, usuario[j].id_usuario);
                printf("(1)Si\n");
                printf("(2)No\n");
                fflush(stdin);
                scanf("%d", &opc2);

                if(opc2==1){
                    system("cls");
                    encontrado=0;
                    for(n=0; n<numUsuarios&&encontrado2==0; n++) //Nos desplazamos por toda la estructura "usuario", hasta que se encuentra al usuario deseado.
                    {
                        if(strcmp(usuario[n].id_usuario, usuario[j].id_usuario)==0) //Si la id del usuario de la posicion actual
                            //en la estructura coincide con la id deseada.
                        {
                            temp=fopen("DATA/usuarios_Temp.txt","w+"); //Se crea un fichero temporal, donde escribir los usuarios que hay,
                            //menos el usuario que se quiere eliminar.
                            if(temp==NULL)
                            {
                                printf("No se ha podido abrir el fichero usuarios_Temp.txt.\n");
                            }
                            else
                            {
                                for(counter=0; counter<numUsuarios;counter++)
                                {
                                    if(strcmp(usuario[counter].id_usuario, vec_id)!=0) //Cuando la id del usuario que queremos eliminar,
                                        //coincide con la linea actual, se salta de linea/omite.
                                    {
                                        fprintf(temp, "%s-%s-%s-%s-%s-%s\n", usuario[counter].id_usuario, usuario[counter].nomb_usuario, usuario[counter].localidad, usuario[counter].perfil, usuario[counter].usuario, usuario[counter].contrasena);
                                    }
                                }
                            }
                            fclose(temp); //Cerramos los ficheros.
                            fclose(fp);
                            encontrarVehiculos(usuario, vehiculo, numVehiculos, &vec, &o, n); //Buscamos todos los vehiculos del usuario, para eliminarlos.
                            for(c=0; c<o; c++)
                            {
                                eliminarVehiculoViajes(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, vehiculo[vec[c]].id_mat, o); //Eliminamos los vehiculos, viajes, pasos y reservas del usuario seleccionado.
                            }
                            encontrado2=1;
                        }
                    }
                    remove("DATA/usuarios.txt"); //Borramos el fichero original.
                    rename("DATA/usuarios_Temp.txt","DATA/usuarios.txt"); //Cambiamos de nombre el fichero temporal por el original.
                    leer_usuario(&usuario, &numUsuarios); //Volvemos a leer el fichero "usuarios.txt", para actualizar la estructura, y el contador "numUsuarios".
                    system("cls");
                    printf("Eliminado con exito\n");
                    system("PAUSE");
                }
            }while((opc2<1)||(opc2>2));
        }
        else //Se imprime un aviso, si no hay usuarios.
        {
            system("cls");
            printf("No hay usuarios registrados.\n");
            system("PAUSE");
        }
    }
    fclose(fp);
}

//Prototipo: void eliminarAdminVehiculo(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int);
//Precondicion: Tener las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas",
//al igual que sus contadores "numUsuarios", "numVehiculos", "numViajes", "numPasos" y "numReservas".
//Postcondicion: Preguntar al admin, la id del usuario para saber sus vehiculos, y eliminar dicho vehiculo, y todos sus viajes, pasos y reservas.

void eliminarAdminVehiculo(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, int x)
{
    char opc2[4];
    int encontrado=0, i=0, counter;

    system("cls");
    if(numVehiculos!=0) //Si hay vehiculos en el sistema.
    {
        listarVehiculos(usuario, numUsuarios, vehiculo, numVehiculos, x, 1); //Obtenemos una lista de todos los vehiculos del sistema.
        printf("Escriba la ID del usuario a la que se quiera eliminar un vehiculo\n");
        scanf("%4s",&opc2); //Se pregunta la id del usuario al que quiere eliminar el vehiculo.
        for(counter=0;(counter<numUsuarios)&&(encontrado==0);counter++)
        {
            if(strcmp(opc2,usuario[counter].id_usuario)==0) //Cuando coincida la id del usuario de la estructura, con la id deseada,
                //entra en la funcion eliminarVehiculo, y le preguntara la matricula del vehiculo a eliminar.
            {
                encontrado=1;
                i=counter;
                system("cls");
                eliminarVehiculo(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, i);
            }
        }
        if(encontrado==0) //Si la id del usuario es incorrecta, se imprime este aviso.
        {
            system("cls");
            printf("No se ha encontrado ningun usuario con la siguiente ID: %s\n",opc2);
            system("PAUSE");
        }
    }
}

//Prototipo: void eliminarAdminViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, int, int);
//Precondicion: Tener la variable "num", y las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas",
//al igual que sus contadores "numUsuarios", "numVehiculos", "numViajes", "numPasos" y "numReservas".
//Postcondicion: Preguntar al admin, la id del usuario para saber sus vehiculos, y con todas sus matriculas, localizar sus viajes.
//Si num=0, elimina un viaje, y si num=1, anula/finaliza un viaje, depende de su estado. Todo esto eliminando todos sus pasos y reservas.

void eliminarAdminViaje(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, int x, int num)
{
    char opc2[4];
    int encontrado=0, i=0, counter, n=0;

    system("cls");
    listarAdminViajes(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, x, num, &n); //Obtenemos una lista de todos los viajes del sistema.
    if(n!=0) //Si hay viajes con las condiciones requeridas.
    {
        printf("Escriba la ID del usuario al que quiere eliminar un viaje.\n");
        scanf("%4s",&opc2); //Se pregunta la id del usuario al que quiere eliminar el vehiculo.
        for(counter=0;(counter<numUsuarios)&&(encontrado==0);counter++)
        {
            if(strcmp(opc2,usuario[counter].id_usuario)==0) //Cuando coincida la id del usuario de la estructura, con la id deseada,
                //entra en la funcion eliminarViaje, y le preguntara la id del viaje a eliminar.
            {
                encontrado=1;
                i=counter;
                system("cls");
                if(num==0)
                {
                    eliminarViaje(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, i);
                }
                if(num==1)
                {
                    finalizar_viaje(usuario, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, i);
                }
            }
        }
        if(encontrado==0) //Si la id del usuario es incorrecta, se imprime este aviso.
        {
            system("cls");
            printf("No se ha encontrado ningun usuario con la siguiente ID: %s\n",opc2);
            system("PAUSE");
        }
    }
}

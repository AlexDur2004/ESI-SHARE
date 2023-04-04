#include "eliminar.h"

//Prototipo: void eliminarVehiculo(int);
//Precondici�n: Tener la variable "i" inicializada, que representa al usuario en la estructura "Usuarios",
//tambi�n necesitaremos las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas".
//Postcondici�n: Eliminar el veh�culo que seleccione el usuario de la lista de sus veh�culos, si hace esto
//se eliminar�n todos los viajes, pasos y reservas de dicho veh�culo.

void eliminarVehiculo(int i)
{
    int x=0, h=0, m=0, opc=0, opc2=0, *vec=NULL;

    encontrarVehiculos(&vec, &x, i); //Encontramos todos los veh�culos del usuario, y los colocamos en un vector de enteros,
    //con las posiciones en la estructura "vehiculo" de sus veh�culos.

    if(x>0){ //Si tiene alg�n veh�culo, le pregunta el coche que quiere eliminar, si no tiene veh�culo, se imprime un aviso.
        printf("�Qu� vehiculo quiere eliminar?\n");

        for(m=0; m<x; m++) //Imprimimos todos los coches que tiene el usuario.
        {
            printf("(%i)%s-%s-%s\n", m+1, vehiculo[vec[m]].id_mat, vehiculo[vec[m]].num_plazas, vehiculo[vec[m]].desc_veh);
        }
        m++;
        printf("(%i)Salir.\n", m);
        printf("Ingrese el n�mero correspondiente al veh�culo que desea eliminar: "); //Selecci�n del veh�culo que quiere eliminar.
        fflush(stdin);
        scanf("%d", &opc);
        if(opc==m){ //Si introduce el n�mero m�s alto "m", volver� a la funci�n anterior, en este caso el men�.
            return;
        }
        if((opc>=1&&opc<m)&&opc!=m){ //Si el n�mero introducido no est� en el rango que se representa, es decir,
            //es menor que 1 o es mayor que m, pues se vuelva a entrar a la funci�n, funcionando como un do-while.
            h=opc-1;
            do{
                opc2=0;
                system("cls");
                printf("�Seguro que quieres eliminar el vehiculo %s, con matr�cula %s?\n", vehiculo[vec[h]].desc_veh, vehiculo[vec[h]].id_mat);
                //Si el usuario escoge el 1, se eliminar� el veh�culo, si escribe 2, se volver� al men�.
                printf("(1)Si\n");
                printf("(2)No\n");
                fflush(stdin);
                scanf("%d", &opc2);
                if(opc2==1){ //Al escoger 1, nos lleva a otra funci�n, que eliminar� los viajes, pasos y reservas del veh�culo seleccionado.
                    system("cls");
                    eliminarVehiculoViajes(vehiculo[vec[h]].id_mat, x);
                    system("PAUSE");
                }
            }while((opc2<1)||(opc2>2));
        }
        else {
            system("cls");
            eliminarVehiculo(i); //Vuelva a entrar en la funci�n.
        }
    }
    else{ //Se imprime un aviso, si no tiene veh�culos asignados.
        system("cls");
        printf("No posee veh�culos registrados.\n");
        system("PAUSE");
    }
    return;
}

//Prototipo: void eliminarVehiculoViajes(char *, int);
//Precondici�n: Tener la cadena "mat", que ser�a la matr�cula del veh�culo que se quiere eliminar, y la variable "x",
//que representa el n�mero de veh�culos que tiene el usuario, tambi�n necesitaremos las estructuras "Vehiculo", "Viajes", "Pasos" y "Reservas".
//Postcondici�n: Eliminar el veh�culo, a partir de la matr�cula, adem�s de todos sus viajes, pasos y reservas.

void eliminarVehiculoViajes(char *mat, int x)
{
    FILE *fp, *temp;
    int n=0, j=0, k=0, num_v=0, *vec_viaje=NULL, counter, encontrado=0;

    fp=fopen("vehiculos.txt","r+");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else
    {
        for(n=0; n<numVehiculos&&encontrado==0; n++) //Nos desplazamos por toda la estructura "vehiculo", hasta encontrar el veh�culo con la matr�cula deseada.
        {
            if(strcmp(vehiculo[n].id_mat, mat)==0) //Si coincide la matr�cula de la posici�n actual en la estructura con la matr�cula deseada.
            {
                temp=fopen("vehiculos_Temp.txt","w+"); //Se crea un fichero temporal, donde escribir los veh�culos que hay, menos el veh�culo que se quiere eliminar.
                if(temp==NULL)
                {
                printf("No se ha podido abrir el fichero vehiculos_Temp.txt.\n");
                }
                else
                {
                    for(counter=0; counter<numVehiculos; counter++)
                    {
                        if(strcmp(vehiculo[counter].id_mat, mat)!=0) //Cuando el matr�cula del veh�culo, coincide con la matr�cula deseada, se salta de l�nea/omite.
                        {
                            fprintf(temp, "%s-%s-%s-%s\n", vehiculo[counter].id_mat, vehiculo[counter].id_usuario, vehiculo[counter].num_plazas, vehiculo[counter].desc_veh);
                        }
                    }
                }
                fclose(temp); //Cerramos los ficheros.
                fclose(fp);
                for(j=0; j<x; j++)
                {
                    encontrarViajes(vehiculo[n].id_mat, &vec_viaje, &num_v, 0); //Encontramos todos los viajes del veh�culo, para eliminarlos.
                }
                for(k=0; k<num_v; k++) //Eliminamos todos los viajes, pasos y reservas.
                {
                    eliminarSoloViaje(viaje[vec_viaje[k]].id_viaje);
                    eliminarPasos(viaje[vec_viaje[k]].id_viaje);
                    eliminarReservas(viaje[vec_viaje[k]].id_viaje);
                }
                encontrado=1;
            }
        }
        remove("vehiculos.txt"); //Borramos el fichero original.
        rename("vehiculos_Temp.txt","vehiculos.txt"); //Cambiamos de nombre el fichero temporal por el original.
        leer_vehiculo(&vehiculo, &numVehiculos); //Volvemos a leer el fichero "vehiculos.txt", para actualizar la estructura, y el contador "numVehiculos".
    }
    fclose(fp);
    return;
}

//Prototipo: void eliminarViaje(int);
//Precondici�n: Tener la variable "i" inicializada, que representa al usuario en la estructura "Usuarios",
//Adem�s se necesitar�n las estructuras "Vehiculo", "Viajes", "Pasos" y "Reservas", el contador "numVehiculos".
//Postcondici�n: Eliminar el viaje que seleccione el usuario de la lista de sus viajes, si hace esto
//se eliminar�n todos los pasos y reservas de dicho viaje.

void eliminarViaje(int i)
{
    int j=0, x=0, h=0, m=0, num_v=0, opc=0, opc2=0, *vec=NULL, *vec_viaje=NULL;

    encontrarVehiculos(&vec, &num_v, i);  //Busca los veh�culos que tiene dicho usuario, para luego encontrar los viajes que tiene.

    for(j=0;j<num_v;j++)
    {
        encontrarViajes(vehiculo[vec[j]].id_mat, &vec_viaje, &x, 2);
    }

    if(x>0){
        printf("�Qu� viaje quiere eliminar?\n");

        for(m=0; m<x; m++) //Imprime una lista de todos los viajes que tiene el usuario.
        {
            printf("(%i)%s-%s-%s-%s-%s-%s-%s-%s-%s\n", m+1, viaje[vec_viaje[m]].id_viaje, viaje[vec_viaje[m]].id_mat,viaje[vec_viaje[m]].f_inic,viaje[vec_viaje[m]].h_inic,viaje[vec_viaje[m]].h_fin,viaje[vec_viaje[m]].plazas_libre,viaje[vec_viaje[m]].ida_vuelta,viaje[vec_viaje[m]].precio,viaje[vec_viaje[m]].estado);
        }
        x++;
        printf("(%i)Salir.\n", x);
        printf("Ingrese el n�mero correspondiente al viaje que desea eliminar: "); //Introduce el n�mero del viaje.
        fflush(stdin);
        scanf("%d", &opc);
        if(opc==x) //Si el n�mero introducido coincide con el del n�mero m�ximo "x", se vuelve al men�.
        {
            return;
        }
        if((opc>=1&&opc<x)&&opc!=x) //Si el n�mero introducido no est� en el rango que se representa, es decir,
            //es menor que 1 o es mayor que m, pues se vuelva a entrar a la funci�n, funcionando como un do-while.
        {
            h=opc-1;
            do //Imprime un mensaje de confirmaci�n para eliminar el viaje seleccionado, se repite hasta que sea 1 o 2.
            {
                opc2=0;
                system("cls");
                printf("�Seguro que quieres eliminar el viaje %s, con matr�cula %s?\n", viaje[vec_viaje[h]].id_viaje, viaje[vec_viaje[h]].id_mat);
                printf("(1)Si\n");
                printf("(2)No\n");
                fflush(stdin);
                scanf("%d", &opc2);
                if(opc2==1){ //Si seleccionamos 1, se va a la funci�n, que elimina viajes, pasos y reservas, por la id del viaje.
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
            eliminarViaje(i);
        }
    }
    else{ //Se imprime un aviso, si no tiene viajes creados.
        system("cls");
        printf("No tiene viajes registrados.\n");
        system("PAUSE");
    }
    return;
}

//Prototipo: void eliminarSoloViaje(char *);
//Precondici�n: Tener la cadena "id" inicializada, que representa la id del viaje, que se quiere eliminar,
//al igual que las estructura "viaje", "pasos" y "reservas", y su contador "numViajes".
//Postcondici�n: Eliminar un viaje, junto a todos sus pasos y reservas.

void eliminarSoloViaje(char *id)
{
    FILE *fp, *temp;
    int n=0, counter, encontrado=0;

    fp=fopen("viajes.txt","r+");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero viajes.txt.\n");
        return;
    }
    else
    {
        for(n=0; n<numViajes&&encontrado==0; n++) //Nos desplazamos por toda la estructura "viaje", hasta encontrar el viaje con la id deseada.
        {
            if(strcmp(viaje[n].id_viaje, id)==0) //Si la id del viaje de la posici�n actual en la estructura coincide con la id deseada.
            {
                temp=fopen("viajes_Temp.txt","w+"); //Se crea un fichero temporal, donde escribir los viajes que hay, menos el viaje que se quiere eliminar.
                if(temp==NULL)
                {
                printf("No se ha podido abrir el fichero viajes_Temp.txt.\n");
                }
                else
                {
                    for(counter=0; counter<numViajes;counter++)
                    {
                        if(counter!=n) //Cuando la l�nea que queremos eliminar, coincide con la l�nea actual, se salta de l�nea/omite.
                        {
                            fprintf(temp, "%s-%s-%s-%s-%s-%s-%s-%s-%s\n", viaje[counter].id_viaje, viaje[counter].id_mat, viaje[counter].f_inic, viaje[counter].h_inic, viaje[counter].h_fin, viaje[counter].plazas_libre, viaje[counter].ida_vuelta, viaje[counter].precio, viaje[counter].estado);
                        }
                    }
                }
                fclose(temp); //Cerramos los ficheros.
                fclose(fp);
                eliminarPasos(viaje[n].id_viaje); //Eliminamos los pasos y reservas de dicho viaje.
                eliminarReservas(viaje[n].id_viaje);
                encontrado=1;
            }
        }
        remove("viajes.txt"); //Borramos el fichero original.
        rename("viajes_Temp.txt","viajes.txt"); //Cambiamos de nombre el fichero temporal por el original.
        leer_viaje(&viaje, &numViajes); //Volvemos a leer el fichero "viajes.txt", para actualizar la estructura, y el contador "numViajes".
    }
    fclose(fp);
    return;
}

//Prototipo: void eliminarPasos(char *);
//Precondici�n: Tener la cadena "id" inicializada, que representa la id del viaje, al igual que la estructura "pasos", y su contador "numPasos".
//Postcondici�n: Eliminar los pasos de un viaje.

void eliminarPasos(char *id)
{
    FILE *fp, *temp;
    int n=0, counter;

    fp=fopen("pasos.txt","r+");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero pasos.txt.\n");
        return;
    }
    else
    {
        for(n=0; n<numPasos; n++) //Nos desplazamos por toda la estructura "pasos".
        {
            if(strcmp(pasos[n].id_viaje, id)==0) //Si la id del viaje de la posici�n actual en la estructura coincide con la id deseada.
            {
                temp=fopen("pasos_Temp.txt","w+"); //Se crea un fichero temporal, donde escribir los pasos que hay, menos los pasos que se quieren eliminar.
                if(temp==NULL)
                {
                printf("No se ha podido abrir el fichero pasos_Temp.txt.\n");
                }
                else
                {
                    for(counter=0; counter<numPasos;counter++)
                    {
                        if(strcmp(pasos[counter].id_viaje, id)!=0) //Cuando la id del viaje del paso que queremos eliminar,
                            //coincide con la l�nea actual, se salta de l�nea/omite.
                        {
                            fprintf(temp, "%s-%s\n", pasos[counter].id_viaje, pasos[counter].poblacion);
                        }
                    }
                }
                fclose(temp); //Cerramos los ficheros.
                fclose(fp);
            }
        }
        remove("pasos.txt"); //Borramos el fichero original.
        rename("pasos_Temp.txt","pasos.txt"); //Cambiamos de nombre el fichero temporal por el original.
        leer_pasos(&pasos, &numPasos); //Volvemos a leer el fichero "pasos.txt", para actualizar la estructura, y el contador "numPasos".
        system("cls");
    }
    fclose(fp);
    return;
}

//Prototipo: void eliminarReservas(char *);
//Precondici�n: Tener la cadena "id" inicializada, que representa la id del viaje, al igual que la estructura "reservas", y su contador "numReservas".
//Postcondici�n: Eliminar las reservas de un viaje.

void eliminarReservas(char *id)
{
    FILE *fp, *temp;
    int n=0, counter;

    fp=fopen("reservas.txt","r+");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero reservas.txt.\n");
        return;
    }
    else
    {
        for(n=0; n<numReservas; n++) //Nos desplazamos por toda la estructura "reservas".
        {
            if(strcmp(reservas[n].id_viaje, id)==0) //Si la id del viaje de la posici�n actual en la estructura coincide con la id deseada.
            {
                temp=fopen("reservas_Temp.txt","w+"); //Se crea un fichero temporal, donde escribir los reservas que hay, menos las reservas que se quieren eliminar.
                if(temp==NULL)
                {
                printf("No se ha podido abrir el fichero reservas_Temp.txt.\n");
                }
                else
                {
                    for(counter=0; counter<numReservas;counter++)
                    {
                        if(strcmp(reservas[counter].id_viaje, id)!=0) //Cuando la id del viaje de la reserva que queremos eliminar,
                            //coincide con la l�nea actual, se salta de l�nea/omite.
                        {
                            fprintf(temp, "%s-%s\n", reservas[counter].id_viaje, reservas[counter].id_usuario);
                        }
                    }
                }
                fclose(temp); //Cerramos los ficheros.
                fclose(fp);
            }
        }
        remove("reservas.txt"); //Borramos el fichero original.
        rename("reservas_Temp.txt","reservas.txt"); //Cambiamos de nombre el fichero temporal por el original.
        leer_reservas(&reservas, &numReservas); //Volvemos a leer el fichero "reservas.txt", para actualizar la estructura, y el contador "numReservas".
        system("cls");
    }
    fclose(fp);
    return;
}

//Prototipo: void eliminarAdminUsuario();
//Precondici�n: Tener las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas",
//al igual que sus contadores "numUsuarios", "numVehiculos", "numViajes", "numPasos" y "numReservas".
//Postcondici�n: Preguntar al admin, la id del usuario que quiere eliminar, y eliminar el usuario,
//y todos sus veh�culos, viajes, pasos y reservas.

void eliminarAdminUsuario()
{
    FILE *fp, *temp;
    int n=0, o=0, j=0, opc2=0, c=0, *vec=NULL, encontrado=0, encontrado2=0, id2, counter;
    char vec_id[5];

    fp=fopen("usuarios.txt","r+");

    if(fp==NULL) {
        printf("No se ha podido abrir el fichero usuarios.txt.\n");
        return;
    }
    else {
        if(numUsuarios>1){
            do{ //Se pregunta la id del usuario para eliminarlo, hasta que la id sea correcta.
                listarUsuarios(); //Obtenemos una lista de todos los usuarios del sistema.
                printf("�Qu� usuario quiere eliminar?\n");
                printf("Introduzca la ID del usuario que quiere eliminar.\n");
                scanf("%i", &id2);
                sprintf(vec_id, "%04i", id2);
                encontrarUsuario(vec_id, &j, &encontrado); //Si la id est� en la base de datos, encontrado=1, y sale del bucle.
            }while(encontrado==0);

            do{
                opc2=0;
                system("cls"); //Imprime mensaje de confirmaci�n.
                printf("�Seguro que quieres eliminar el usuario %s, con ID %s?\n", usuario[j].nomb_usuario, usuario[j].id_usuario);
                printf("(1)Si\n");
                printf("(2)No\n");
                fflush(stdin);
                scanf("%d", &opc2);

                if(opc2==1){
                    system("cls");
                    encontrado=0;
                    for(n=0; n<numUsuarios&&encontrado2==0; n++) //Nos desplazamos por toda la estructura "usuario", hasta que se encuentra al usuario deseado.
                    {
                        if(strcmp(usuario[n].id_usuario, usuario[j].id_usuario)==0) //Si la id del usuario de la posici�n actual
                            //en la estructura coincide con la id deseada.
                        {
                            temp=fopen("usuarios_Temp.txt","w+"); //Se crea un fichero temporal, donde escribir los usuarios que hay,
                            //menos el usuario que se quiere eliminar.
                            if(temp==NULL) {
                                printf("No se ha podido abrir el fichero usuarios_Temp.txt.\n");
                            }
                            else{
                                for(counter=0; counter<numUsuarios;counter++)
                                {
                                    if(strcmp(usuario[counter].id_usuario, vec_id)!=0) //Cuando la id del usuario que queremos eliminar,
                                    //coincide con la l�nea actual, se salta de l�nea/omite.
                                    {
                                        fprintf(temp, "%s-%s-%s-%s-%s-%s\n", usuario[counter].id_usuario, usuario[counter].nomb_usuario, usuario[counter].localidad, usuario[counter].perfil, usuario[counter].usuario, usuario[counter].contrasena);
                                    }
                                }
                            }
                            fclose(temp); //Cerramos los ficheros.
                            fclose(fp);
                            encontrarVehiculos(&vec, &o, n); //Buscamos todos los veh�culos del usuario, para eliminarlos.
                            for(c=0; c<o; c++)
                            {
                                eliminarVehiculoViajes(vehiculo[vec[c]].id_mat, o); //Eliminamos los veh�culos, viajes, pasos y reservas del usuario seleccionado.
                            }
                            encontrado2=1;
                        }
                    }
                    remove("usuarios.txt"); //Borramos el fichero original.
                    rename("usuarios_Temp.txt","usuarios.txt"); //Cambiamos de nombre el fichero temporal por el original.
                    leer_usuario(&usuario, &numUsuarios); //Volvemos a leer el fichero "usuarios.txt", para actualizar la estructura, y el contador "numUsuarios".
                    system("cls");
                    printf("Eliminado con exito\n");
                    system("PAUSE");
                }
            }while((opc2<1)||(opc2>2));
        }
        else{ //Se imprime un aviso, si no hay usuarios.
            system("cls");
            printf("No hay usuarios registrados.\n");
            system("PAUSE");
        }
    }
    fclose(fp);
}

//Prototipo: void eliminarAdminVehiculo();
//Precondici�n: Tener las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas",
//al igual que sus contadores "numUsuarios", "numVehiculos", "numViajes", "numPasos" y "numReservas".
//Postcondici�n: Preguntar al admin, la id del usuario para saber sus veh�culos, y eliminar
//el veh�culo, y todos sus viajes, pasos y reservas.

void eliminarAdminVehiculo(int x)
{
    char opc2[4];
    int encontrado=0, i=0, counter;

    system("cls");
    listarVehiculos(x,1); //Obtenemos una lista de todos los vehiculos del sistema.
    printf("Escriba la ID del usuario a la que se quiera eliminar un veh�culo\n");
    scanf("%4s",&opc2); //Se pregunta la id del usuario al que quiere eliminar el veh�culo.
    for(counter=0;(counter<numUsuarios)&&(encontrado==0);counter++)
    {
        if(strcmp(opc2,usuario[counter].id_usuario)==0) //Cuando coincida la id del usuario de la estructura, con la id deseada,
            //entra en la funci�n eliminarVehiculo, y le preguntar� la matr�cula del veh�culo a eliminar.
        {
            encontrado=1;
            i=counter;
            system("cls");
            eliminarVehiculo(i);
        }
    }
    if(encontrado==0) //Si la id del usuario es incorrecta, se imprime este aviso.
    {
        system("cls");
        printf("No se ha encontrado ningun usuario con la siguiente ID: %s\n",opc2);
        system("PAUSE");
    }
}

//Prototipo: void eliminarAdminViaje(int);
//Precondici�n: Tener la variable "num, y las estructuras "Usuario", "Vehiculo", "Viajes", "Pasos" y "Reservas",
//al igual que sus contadores "numUsuarios", "numVehiculos", "numViajes", "numPasos" y "numReservas".
//Postcondici�n: Preguntar al admin, la id del usuario para saber sus veh�culos, y con todas sus matr�culas,
//localizar sus viajes. Si num=0, elimina un viaje, y si num=1, anula/finaliza un viaje, depende de su estado.
//Todo esto eliminando todos sus pasos y reservas.

void eliminarAdminViaje(int x, int num)
{
    char opc2[4];
    int encontrado=0, i=0, counter;

    system("cls");
    listarAdminViajes(x, num); //Obtenemos una lista de todos los viajes del sistema.
    printf("Escriba la ID del usuario al que quiere eliminar un viaje.\n");
    scanf("%4s",&opc2); //Se pregunta la id del usuario al que quiere eliminar el veh�culo.
    for(counter=0;(counter<numUsuarios)&&(encontrado==0);counter++)
    {
        if(strcmp(opc2,usuario[counter].id_usuario)==0) //Cuando coincida la id del usuario de la estructura, con la id deseada,
            //entra en la funci�n eliminarViaje, y le preguntar� la id del viaje a eliminar.
        {
            encontrado=1;
            i=counter;
            system("cls");
            if(num==0)
            {
                eliminarViaje(i);
            }
            if(num==1)
            {
                finalizar_viaje(i);
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

#include "modificar.h"

//Prototipo: void modificarVehiculo(Estr_Usuario *, Estr_Vehiculo *, int, int);
//Precondición: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario",
//y las estructuras "usuario" y "vehiculo" inicializadas, con sus contadores.
//Postcondición: Modificar cualquier dato de un vehiculo que tenga el usuario.

void modificarVehiculo(Estr_Usuario *usuario, Estr_Vehiculo *vehiculo, int numVehiculos, int i)
{
    FILE *fp, *temp;
    int n=0, x=0, h=0, m=0, aux=0, y=0, opc=0, opc2=0, *vec=NULL, encontrado=0, error_mat, counter;
    char mat[8], plazas[2], descrip[51];

    leer_vehiculo(&vehiculo, &numVehiculos); //Vuelve a leer la estructura "vehiculo", por si hay cambios.
    system("cls");

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
            encontrarVehiculos(usuario, vehiculo, numVehiculos, &vec, &x, i); //Encuentra todos los vehiculos del usuario.
            aux=x;
            while(encontrado==0) //Hasta que no se introduzca un vehiculo que esté en el vector de enteros, es decir, un vehiculo que él tenga.
            {
                x=aux;
                y=aux;
                printf("¿Qué vehículo quiere modificar?\n");

                for(m=0; m<x; m++)
                {
                    color(0,4);
                    printf("    Vehiculo "); //Imprime todos los datos de los vehiculos que tiene el usuario.
                    color(0,15);
                    printf("%i", m+1);
                    color(0,4);
                    printf(":\t");
                    color(0,3);
                    printf("    Matrícula: ");
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
                printf("Ingrese el número correspondiente al vehículo que desea modificar: ");
                fflush(stdin);
                scanf("%d", &opc);
                system("cls");
                if(opc==x) //Si introduce lo mismo que vale la variable máxima "x".
                {
                    return; //Vuelve al menú.
                }
                for(m=1; m<y; m++) //Vamos recorriendo el vector de enteros, con los vehiculos del usuario.
                {
                    if(opc==vec[m-1]) //Si el vehiculo seleccionado está en este vector.
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
                                do{ //Hasta que la matricula no sea correcta.
                                    error_mat=0;
                                    printf("Matrícula del vehículo (Máximo de 7 caracteres):\n");
                                    printf("Matrícula actual: %s\n", vehiculo[vec[h]].id_mat);
                                    pregunta(mat, 8); //Pedimos la nueva matricula.

                                    for(counter=0;(counter<numVehiculos)&&(error_mat==0);counter++) //Comprobamos que la matricula no está registrada.
                                    {
                                        if(strcmp(mat,vehiculo[counter].id_mat)==0){ //Si se encuentra la matricula en las que hay ahora, pues está usada.
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

                                printf("La matrícula del vehículo se ha actualizado correctamente.\n");
                                system("PAUSE");
                                break;
                            case 2:
                                printf("Número de plazas libres (sin contar el conductor):\n");
                                printf("Plazas actuales: %s\n", vehiculo[vec[h]].num_plazas);
                                pregunta(plazas, 2); //Pedimos el nuevo numero de plazas.

                                strcpy(vehiculo[vec[h]].num_plazas, plazas); //Copiamos el nuevo numero de plazas en la posicion de la estructura correspondiente.

                                printf("El numero de plazas del vehículo se ha actualizado correctamente.\n");
                                system("PAUSE");
                                break;
                            case 3:
                                printf("Descripción del vehículo (Marca, modelo, color, etc) (Máximo de 50 caracteres):\n");
                                printf("Descripción actual: %s\n", vehiculo[vec[h]].desc_veh);
                                pregunta(descrip, 51); //Pedimos la nueva descripcion.

                                strcpy(vehiculo[vec[h]].desc_veh, descrip); //Copiamos la nueva descripcion en la posicion de la estructura correspondiente.

                                printf("La descripcion del vehiculo se ha actualizado correctamente.\n");
                                system("PAUSE");
                                break;
                            case 4: //Volvemos a hacer todo lo anterior.
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
                            case 5: //Salimos
                                break;
                        }
                        encontrado=1;
                    }while((opc2>1&&opc2<5)&&encontrado==0);
                    if(opc2!=5)
                    {
                        temp=fopen("DATA/vehiculos_Temp.txt","w+"); //Creamos un archivo temporal.
                        if(temp==NULL) {
                            printf("No se ha podido abrir el fichero vehiculos_Temp.txt.\n");
                        }
                        else
                        {
                            do{ //Escribimos toda la estructura vehiculo en el archivo temporal.
                                fprintf(temp, "%s-%s-%s-%s\n", vehiculo[n].id_mat, vehiculo[n].id_usuario, vehiculo[n].num_plazas, vehiculo[n].desc_veh);
                                n++;
                            }while(n<(numVehiculos-1));
                            fprintf(temp, "%s-%s-%s-%s", vehiculo[n].id_mat, vehiculo[n].id_usuario, vehiculo[n].num_plazas, vehiculo[n].desc_veh);
                        }
                        fclose(temp); //Cerramos los ficheros.
                        fclose(fp);
                        remove("DATA/vehiculos.txt"); //Borramos el fichero original.
                        rename("DATA/vehiculos_Temp.txt","DATA/vehiculos.txt"); //Renombramos el fichero temporal por el original.
                    }
                }
            }
        }
    }
    else
    {
        printf("No hay vehiculos registrados.\n");
        system("PAUSE");
    }
    fclose(fp);
}

//Prototipo: void modificarViaje(Estr_Usuario *, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondición: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y las estructuras inicializadas, con sus contadores.
//Postcondición: Modificar cualquier dato de un viaje, que esté abierto y sin plazas reservadas, que tenga el usuario.

void modificarViaje(Estr_Usuario *usuario, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int i)
{
    FILE *fp, *temp;
    int n=0, h=0, x=0, m=0, j=0, opc=0, opc2=0, *vec=NULL, *vec_viaje=NULL, cont=0, prec=0, encontrado=0, encontrado2=0;
    char mat[8], fecha[11], hora_in[6], hora_fin[6], coste[2];

    leer_viaje(&viaje, &numViajes); //Vuelve a leer la estructura "viaje", por si hay cambios.
    system("cls");

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
            if(vec_viaje==NULL) //Si el vector está vacio, significa que no hay viajes.
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
                    printf("Ingrese el número correspondiente al viaje que desea modificar: ");
                    fflush(stdin);
                    scanf("%d", &opc);
                    system("cls");
                    if(opc>=1&&opc<=cont) //Si la opción está entre 1 y la variable máxima.
                    {
                        encontrado=1;
                    }
                    if(opc==m) //Si introduce lo mismo que vale la variable máxima "x".
                    {
                        return; //Vuelve al menú.
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
                    system("cls");
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
                                    pregunta(mat, 8); //Pedimos la nueva matricula que va a llevar el viaje.
                                    for(j=0;j<x;j++)
                                    {
                                        if(strcmp(vehiculo[vec[j]].id_mat, mat)==0) //Si la matricula introducida está entre sus vehículos.
                                        {
                                            encontrado2=1;
                                        }
                                    }
                                }while(encontrado2==0);

                                strcpy(viaje[vec_viaje[h]].id_mat, mat); //Copiamos la nueva matricula en la posicion de la estructura correspondiente.

                                printf("El vehículo del viaje se ha actualizado correctamente.\n");
                                system("PAUSE");
                                break;
                            case 2:
                                leerFecha(fecha, hora_in, hora_fin); //Leemos la fecha, hora inicio y hora llegada.

                                strcpy(viaje[vec_viaje[h]].f_inic, fecha); //Introducimos los datos pedidos al viaje.
                                strcpy(viaje[vec_viaje[h]].h_inic, hora_in);
                                strcpy(viaje[vec_viaje[h]].h_fin, hora_fin);

                                printf("La fecha del viaje se ha actualizado correctamente.\n");
                                system("PAUSE");
                                break;
                            case 3:
                                while(prec<=0) //Mientras que el precio sea menor o igual a 0.
                                {
                                    system("cls");
                                    printf("Coste del viaje (Máximo de 1 digito):\n");
                                    printf("Coste actual: %s\n", viaje[vec_viaje[h]].precio);
                                    scanf("%1i", &prec); //Pedimos el nuevo precio.
                                }

                                sprintf(coste, "%1i", prec); //Pasamos de entero a cadena.

                                strcpy(viaje[vec_viaje[h]].precio, coste); //Copiamos el nuevo precio.

                                printf("El coste del viaje se ha actualizado correctamente.\n");
                                system("PAUSE");
                                break;
                            case 4:
                                modificarRuta(usuario, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                                //Empleamos la función "modificarRuta"
                                break;
                            case 5: //Volvemos a hacer todo lo anterior.
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

                                    modificarRuta(usuario, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);

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
                        temp=fopen("DATA/viajes_Temp.txt","w+"); //Creamos un archivo temporal.
                        if(temp==NULL) {
                            printf("No se ha podido abrir el fichero viajes_Temp.txt.\n");
                        }
                        else
                        {
                            do{ //Escribimos toda la estructura viaje en el archivo temporal.
                                fprintf(fp, "%s-%s-%s-%s-%s-%s-%s-%s-%s\n",viaje[n].id_viaje,viaje[n].id_mat,viaje[n].f_inic,viaje[n].h_inic,viaje[n].h_fin,viaje[n].plazas_libre,viaje[n].ida_vuelta,viaje[n].precio,viaje[n].estado);
                                n++;
                            }while(n<numViajes-1);
                            fprintf(fp, "%s-%s-%s-%s-%s-%s-%s-%s-%s",viaje[n].id_viaje,viaje[n].id_mat,viaje[n].f_inic,viaje[n].h_inic,viaje[n].h_fin,viaje[n].plazas_libre,viaje[n].ida_vuelta,viaje[n].precio,viaje[n].estado);
                        }
                        fclose(temp); //Cerramos los ficheros.
                        fclose(fp);
                        remove("DATA/viajes.txt"); //Borramos el fichero original.
                        rename("DATA/viajes_Temp.txt","DATA/viajes.txt"); //Renombramos el fichero temporal por el original.
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

//Prototipo: void modificarRuta(Estr_Usuario *, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondición: Tener el entero "num_user", para saber la posicion del usuario en la estructura "usuario", y las estructuras inicializadas, con sus contadores.
//Postcondición: Modificar la ruta de un viaje, que esté abierto y sin plazas reservadas, que tenga el usuario.

void modificarRuta(Estr_Usuario *usuario, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int num_user)
{
    int *vec=NULL, *vec_viaje=NULL, x=0, num_v=0, i, j, opc, h;

    encontrarVehiculos(usuario, vehiculo, numVehiculos, &vec, &x, num_user); //Encuentra todos los vehiculos del usuario.
    if(x!=0)
    {
        for(j=0;j<x;j++)
        {
            encontrarViajes(vehiculo, numVehiculos, viaje, numViajes, vehiculo[vec[j]].id_mat, &vec_viaje, &num_v, 2); //Encuentra todos los viaje de cada vehiculo del usuario.
        }
        if(num_v!=0) //Si el usuario tiene viajes abiertos y sin plazas reservadas.
        {
            printf("LISTADO DE VIAJES:\n");
            for(i=0;i<num_v;i++){
                color(0,4);
                printf("    Viaje "); //Imprime todos los datos de cada viaje.
                color(0,15);
                printf("%i", i+1);
                color(0,4);
                printf(":\t");
                color(0,3);
                printf("ID: ");
                color(0,15);
                printf("%s", viaje[vec_viaje[i]].id_viaje);
                color(0,3);
                printf(" | Matricula: ");
                color(0,15);
                printf("%s", viaje[vec_viaje[i]].id_mat);
                color(0,3);
                printf(" | Fecha de partida: ");
                color(0,15);
                printf("%s", viaje[vec_viaje[i]].f_inic);
                color(0,3);
                printf(" | Hora de partida: ");
                color(0,15);
                printf("%s", viaje[vec_viaje[i]].h_inic);
                color(0,3);
                printf(" |\n                Hora de llegada: ");
                color(0,15);
                printf("%s", viaje[vec_viaje[i]].h_fin);
                color(0,3);
                printf(" | Plazas libres: ");
                color(0,15);
                printf("%s", viaje[vec_viaje[i]].plazas_libre);
                color(0,3);
                printf(" | Ida/Vuelta: ");
                color(0,15);
                printf("%s", viaje[vec_viaje[i]].ida_vuelta);
                color(0,3);
                printf(" | Precio: ");
                color(0,15);
                printf("%s\n\n", viaje[vec_viaje[i]].precio);
            }
            do{
                printf("Seleccione el viaje que desee modificar:\n");
                scanf("%i",&opc);
            }while(opc<0&&opc<num_v); //Repetir hasta que el viaje no esté entre 1 y el número máximo de viajes.
            h=opc-1;
            eliminarPasos(pasos, numPasos, viaje[vec[h]].id_viaje); //Elimina los pasos del viaje.
            buscadorRutas(ruta, numRutas, numRutas2, localidad, numLocalidades, pasos, numPasos, viaje[vec[h]].id_viaje); //Pide la nueva ruta por donde va a ir, e imprime los pasos.
        }
        else
        {
            printf("No tiene ningún viaje abierto y sin plazas reservadas.\n");
            system("PAUSE");
        }
    }
    else
    {
        printf("No tiene ni vehiculos ni viajes registrados.\n");
        system("PAUSE");
    }
}

//Prototipo: void modificarPerfilNombre(Estr_Usuario *, int, int);
//Precondición: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y la estructura "usuario" inicializada, con su contador.
//Postcondición: Modificar el nombre del usuario.

void modificarPerfilNombre(Estr_Usuario *usuario, int numUsuarios, int i)
{
    FILE *fp;
    int n=0;
    char nomb[21];

    leer_usuario(&usuario, &numUsuarios); //Leemos el fichero, por si hay cambios.
    system("cls");

    fp=fopen("DATA/usuarios.txt","r+");

    if(fp==NULL) {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else {
        printf("Introduzca su nuevo nombre completo (Máximo de 20 caracteres):\n");
        pregunta(nomb, 21); //Pedimos el nuevo nombre.

        strcpy(usuario[i].nomb_usuario, nomb); //Copiamos el nuevo nombre en la posicion de la estructura correspondiente.
        do{ //Escribimos toda la estructura usuario en el archivo temporal.
            fprintf(fp, "%s-%s-%s-%s-%s-%s\n", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
            n++;
        }while(n<numUsuarios-1);
        fprintf(fp, "%s-%s-%s-%s-%s-%s", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
        numUsuarios++;

        printf("Su nombre completo se ha actualizado correctamente.\n");
        system("PAUSE");
    }
    fclose(fp);
}

//Prototipo: void modificarPerfilLocalidad(Estr_Usuario *, int, Estr_Localidad *, int, int);
//Precondición: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y la estructura "usuario" inicializada, con su contador.
//Postcondición: Modificar la localidad del usuario.

void modificarPerfilLocalidad(Estr_Usuario *usuario, int numUsuarios, Estr_Localidad *localidad, int numLocalidades, int i)
{
    FILE *fp;
    int n=0;
    char loc[21];

    leer_usuario(&usuario, &numUsuarios); //Leemos el fichero, por si hay cambios.
    system("cls");

    fp=fopen("DATA/usuarios.txt","r+");

    if(fp==NULL) {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else {
        printf("Introduzca su nueva localidad de residencia (3 siglas):\n");
        fflush(stdin);
        pregunta_localidad(localidad, numLocalidades, loc); //Pedimos la nueva localidad.

        strcpy(usuario[i].localidad, loc); //Copiamos la nueva localidad en la posicion de la estructura correspondiente.
        do{ //Escribimos toda la estructura usuario en el fichero.
            fprintf(fp, "%s-%s-%s-%s-%s-%s\n", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
            n++;
        }while(n<numUsuarios-1);
        fprintf(fp, "%s-%s-%s-%s-%s-%s", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
        numUsuarios++;

        printf("Su localidad de residencia se ha actualizado correctamente.\n");
        system("PAUSE");
    }
    fclose(fp);
}

//Prototipo: void modificarPerfilUsuario(Estr_Usuario *, int, int);
//Precondición: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y la estructura "usuario" inicializada, con su contador.
//Postcondición: Modificar el username del usuario.

void modificarPerfilUsuario(Estr_Usuario *usuario, int numUsuarios, int i)
{
    FILE *fp;
    int n=0, k=0, encontrado=0;
    char usua[6];

    leer_usuario(&usuario, &numUsuarios); //Leemos el fichero, por si hay cambios.
    system("cls");

    fp=fopen("DATA/usuarios.txt","r+");

    if(fp==NULL) {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else {
        printf("Introduzca su nuevo nombre de usuario (Máximo de 5 caracteres):\n");
        pregunta(usua, 6); //Pedimos el nuevo username.

        for(k=0; k<numUsuarios&&encontrado==0; k++) //Comprobamos que no está usado.
        {
            if(strcmp(usua, usuario[k].usuario)==0)
            {
                encontrado=1;
            }
        }

        if(encontrado==0) //Si no está usado
        {
            printf("El nombre de usuario es válido.\n");
            strcpy(usuario[i].usuario, usua); //Copiamos el nuevo username en la posicion de la estructura correspondiente.
            do{ //Escribimos toda la estructura usuario en el fichero.
                fprintf(fp, "%s-%s-%s-%s-%s-%s\n", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
                n++;
            }while(n<numUsuarios-1);
            fprintf(fp, "%s-%s-%s-%s-%s-%s", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
            numUsuarios++;

            printf("Su nombre de usuario se ha actualizado correctamente.\n");
            system("PAUSE");
        }
        else
        {
            printf("El nombre de usuario ya está siendo usado.\n");
            system("PAUSE");
        }
    }
    fclose(fp);
}

//Prototipo: void modificarPerfilContrasena(Estr_Usuario *, int, int);
//Precondición: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y la estructura "usuario" inicializada, con su contador.
//Postcondición: Modificar la contraseña del usuario.

void modificarPerfilContrasena(Estr_Usuario *usuario, int numUsuarios, int i)
{
    FILE *fp;
    int j=0, n=0, encontrado=3, x=0, h=0;
    char contra[9], contra2[9], c, c2;

    leer_usuario(&usuario, &numUsuarios); //Leemos el fichero, por si hay cambios.
    system("cls");

    fp=fopen("DATA/usuarios.txt","r+");

    if(fp==NULL) {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else
    {
        while(encontrado>0&&x==0)
        {
            printf("Introduzca su antigua contrasena (Máximo de 8 caracteres):\n");
            fflush(stdin); //Pedimos la antigua contrasena.
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

            if(strcmp(usuario[i].contrasena,contra)==0) //Si la contrasena introducida es igual a la que tiene.
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

                strcpy(usuario[i].contrasena, contra2); //Copiamos la nueva contraseña en la posicion de la estructura correspondiente.
                do{ //Escribimos toda la estructura usuario en el fichero.
                    fprintf(fp, "%s-%s-%s-%s-%s-%s\n", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
                    n++;
                }while(n<numUsuarios-1);
                fprintf(fp, "%s-%s-%s-%s-%s-%s", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
                numUsuarios++;

                printf("\nSu contraseña se ha actualizado correctamente.\n");
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
}

//Prototipo: void modificarAdminUsuario(Estr_Usuario *, int, Estr_Localidad *, int);
//Precondición: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y las estructuras inicializadas, con sus contadores.
//Postcondición: Modificar los datos de cualquier usuario.

void modificarAdminUsuario(Estr_Usuario *usuario, int numUsuarios, Estr_Localidad *localidad, int numLocalidades)
{
    int j, opc=0, encontrado=0, id=0;
    char vec_id[5];

    listarUsuarios(usuario, numUsuarios); //Imprimir una lista de todos los usuarios del sistema.

    if(numUsuarios!=0) //Si hay usuarios en el sistema.
    {
        while(encontrado==0)
        {
            printf("Introduzca la ID del usuario al que quiere modificarle el usuario.\n");
            scanf("%i",&id); //Pedimos la id del usuario que queremos modificar.
            sprintf(vec_id, "%04i", id); //Introducimos el entero introducido en la cadena con formato XXXX

            encontrarUsuario(usuario, numUsuarios, vec_id, &j, &encontrado); //Buscamos si el usuario existe en el sistema.

            if(encontrado==1)
            {
                while(opc<1||opc>6) //Elegimos una de las opciones.
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
                    system("cls");
                    switch(opc)
                        {
                            case 1:
                                modificarPerfilNombre(usuario, numUsuarios, j);
                                break;
                            case 2:
                                modificarPerfilLocalidad(usuario, numUsuarios, localidad, numLocalidades, j);
                                break;
                            case 3:
                                modificarPerfilUsuario(usuario, numUsuarios, j);
                                break;
                            case 4:
                                modificarPerfilContrasena(usuario, numUsuarios, j);
                                break;
                            case 5:
                                modificarPerfilNombre(usuario, numUsuarios, j);
                                modificarPerfilLocalidad(usuario, numUsuarios, localidad, numLocalidades, j);
                                modificarPerfilUsuario(usuario, numUsuarios, j);
                                modificarPerfilContrasena(usuario, numUsuarios, j);
                                break;
                            case 6:
                                break;
                        }
                }
            }
        }
    }
}

//Prototipo: void modificarAdminVehiculo(Estr_Usuario *, int, Estr_Vehiculo *, int, int);
//Precondición: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y las estructuras inicializadas, con sus contadores.
//Postcondición: Modificar los datos de un vehiculo de cualquier usuario.

void modificarAdminVehiculo(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, int x)
{
    char opc2[5];
    int encontrado=0, counter, id;

    system("cls");
    if(numVehiculos!=0) //Si hay vehiculos en el sistema.
    {
        listarVehiculos(usuario, numUsuarios, vehiculo, numVehiculos, x); //Listamos todos los vehiculos.
        printf("Escriba la ID del usuario a la que se quiera modificar el vehículo\n");
        scanf("%i",&id); //Pedimos la id del usuario, del vehiculo que queremos modificar.
        sprintf(opc2, "%04i", id); //Introducimos el entero introducido en la cadena con formato XXXX.

        for(counter=0;(counter<numUsuarios)&&(encontrado==0);counter++)
        {
            if(strcmp(opc2, usuario[counter].id_usuario)==0) //Si el usuario existe.
            {
                encontrado=1;
                system("cls");
                modificarVehiculo(usuario, vehiculo, numVehiculos, counter); //Vamos a la función "modificarVehiculo".
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

//Prototipo: void modificarAdminViaje(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int, int);
//Precondición: Tener el entero "i", para saber la posicion del usuario en la estructura "usuario", y las estructuras inicializadas, con sus contadores.
//Postcondición: Modificar los datos de un viaje de cualquier usuario.

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

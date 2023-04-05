#include "escribir.h"

//Prototipo: void altaUsuario();
//Precondición: Tener la estructura "usuario" inicializada, con su contador "numUsuarios".
//Postcondición: Dar de alta/Registrar un usuario, comprobando que el nombre del usuario no está repetido.

void altaUsuario(Estr_Usuario *usuario, int numUsuarios, Estr_Localidad *localidad, int numLocalidades)
{
    FILE *fp;
    int i=0, n=1, idmax=0, k=0, encontrado=0, encontrado2=0, encontrado3=0, preg=0;
    char id[5], nombre[21], loc[21], perfil[14], usuario2[6], contrasena[9];

    fp=fopen("usuarios.txt","a+");

    strcpy(perfil, "usuario"); //Copia la cadena "usuario" en el vector perfil, ya que sólo habrá 1 administrador.
    printf("Introduzca sus datos para completar el registro:\n");
    printf("Nombre Completo (Máximo de 20 caracteres):\n");
    pregunta(nombre, 21); //Función similar a un scanf o un fgets, pero con la eliminación del vector nulo incorporada.
    printf("Localidad de residencia (Siglas de la lista):\n");
    pregunta_localidad(localidad, numLocalidades, loc); //Pregunta de la localidad, impriendo una lista con los acrónimos de las ciudades.
    printf("Nombre de usuario (Máximo de 5 caracteres):\n");
    pregunta(usuario2, 6);

    for(k=0; k<numUsuarios&&encontrado==0; k++) //Se desplaza por toda la estructura "usuario", hasta que encuentra un usuario con mismo nick introducido.
    {
        if(strcmp(usuario2, usuario[k].usuario)==0) //Si encuentra un usuario en la base de datos con el mismo nick que hemos introducido.
        {
            encontrado=1;
        }
    }

    if(encontrado==0) //No sería necesario, pero prefiero hacerlo así, para luego poner un aviso.
    {
        printf("El nombre de usuario es válido.\n");
        printf("Contraseña (Máximo de 8 caracteres):\n");
        pregunta(contrasena, 9);

        if(fp==NULL)
        {
            printf("No se ha podido abrir el fichero usuarios.txt.\n");
            return;
        }
        else
        {
            while(encontrado2==0) //Bucle para encontrar la id más baja, y ocuparla.
            {
                for(i=0;i<numUsuarios&&encontrado3==0;i++) //Nos desplazamos por la estructura "usuario", hasta que se encuentra la id más baja.
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
    else //Aparece aviso de que el usuario está siendo usado.
    {
        printf("El nombre de usuario ya está siendo usado.\n");
        system("PAUSE");
    }

    fclose(fp);

    leer_usuario(&usuario,&numUsuarios); //Volvemos a leer el fichero, para actualizar la estructura "usuario", y el contador de usuarios, "numUsuarios".

    return;
}

//Prototipo: void altaVehiculo(int);
//Precondición: Tener la variable "i", con la posición del usuario en la estructura "usuario", y
//las estructuras "vehiculo" y "usuario" inicializadas, con sus contadores "numVehiculos".
//Postcondición: Dar de alta/Registrar un vehículo, comprobando que la matrícula es válida, y no está en uso.

void altaVehiculo(Estr_Usuario *usuario, Estr_Vehiculo *vehiculo, int numVehiculos, int i)
{
    FILE *fp;
    int n=0,error_mat, counter2=0, counter;
    char mat[8], plazas[2], descrip[51];

    fp=fopen("vehiculos.txt","a+");

    do{ //Se repite hasta que la matrícula sea válida.
        error_mat=0;
        system("cls");
        printf("Introduzca los datos de su vehículo para completar su registro:\nMatrícula del vehículo (Máximo de 7 caracteres):\n");
        fflush(stdin);
        scanf("%7s", mat);
        for(counter=0;(counter<numVehiculos)&&(error_mat==0);counter++) //Nos desplazamos por toda la estructura "vehiculo" para ver si es válida.
        {
            if(strcmp(mat,vehiculo[counter].id_mat)==0) //Si la matrícula introducida, coincide con la de un vehícula de la estructura, pues la matrícula está en uso.
            {
                error_mat=1;
                system("cls");
                printf("La matricula %s esta actualmente registrada.\n", mat);
                system("PAUSE");
            }
        }

        if(strlen(mat)<7) //Comprueba que la longitud de la matrícula es de 7 caracteres.
        {
            system("cls");
            printf("La matricula debe poseer una longitud total de 7 caracteres.\n", mat);
            system("PAUSE");
        }

        for(counter=0;(counter<4)&&(error_mat==0);counter++) //Nos desplazamos por los 4 primeros caracteres de la matrícula, para saber si son números, mediante sus valores ASCII.
        {
            if((mat[counter]<48)||(mat[counter]>57))
            {
                error_mat=1;
                printf("Los 4 primeros caracteres de la matricula tienen que ser numeros.\n");
                system("PAUSE");
            }
        }
        for(counter=4;(counter<7)&&(error_mat==0);counter++) //Nos desplazamos por los 3 ultimos caracteres de la matrícula, para saber si son letras, mediante sus valores ASCII.
        {
            if((mat[counter]<65)||(mat[counter]>90))
            {
                error_mat=1;
                printf("Los 3 ultimos caracteres de la matricula tienen que ser letras mayusculas.\n");
                system("PAUSE");
            }
        }
    }while((error_mat==1)||(strlen(mat)<7));

    printf("Número de plazas libres (sin contar el conductor):\n");
    pregunta(plazas, 2);
    printf("Descripción del vehículo (Marca, modelo, color, etc) (Máximo de 50 caracteres):\n");
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

    return;
}

//Prototipo: void altaAdmin(int);
//Precondición: Necesario la introducción de un entero, para saber si queremos registrar un vehiculo o un viaje.
//Tener las estructuras "vehiculo", "viajes" y "usuario" inicializadas, con sus contadores "numVehiculos", "numViajes" y "numUsuarios".
//Postcondición: Si n=0, dar de alta/registrar un vehículo, comprobando que la matrícula es válida, y no está en uso,
//y si n=1, dar de alta/registrar un viaje. Ambos, introduciendo la id del usuario al que se quiere crear.

void altaAdmin(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2, int n)
{
    char opc2[4];
    int encontrado=0, i=0, counter;

    system("cls");
    listarUsuarios(usuario, numUsuarios);
    printf("Escriba la ID del usuario al que quiera dar de alta el vehiculo.\n");
    scanf("%4s",&opc2);
    for(counter=0;(counter<numUsuarios)&&(encontrado==0);counter++) //Nos desplazamos por la estructura "usuario", hasta saber que la id introducida es válida.
    {
        if(strcmp(opc2,usuario[counter].id_usuario)==0) //Si la id introducida es igual que la id actual.
        {
            encontrado=1;
            i=counter;
            if(n==0)
            {
                altaVehiculo(usuario, vehiculo, numVehiculos, i); //Usamos la función altaVehiculo, para reusar código.
                printf("El vehículo se ha agregado correctamente al usuario %s, con ID %s.\n", usuario[counter].nomb_usuario, usuario[counter].id_usuario);
                system("PAUSE");
            }
            if(n==1)
            {
                altaViaje(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i, 1); //Usamos la función altaViaje, para reusar código.
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

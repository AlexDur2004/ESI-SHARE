#include "acceso.h"

//Prototipo: void acceso(Estr_Usuario *, int, Estr_Vehiculo *, int, Estr_Viaje *, int, Estr_Pasos *, int, Estr_Reservas *, int, Estr_Localidad *, int, Estr_Rutas **, int, int);
//Precondicion: Tener inicializada la variable "numUsuarios", con el numero de usuarios maximos del fichero, y la estructura "usuario", con datos leidos
//desde el fichero "usuarios.txt", y haber introducido el numero correspondiente en el menu. Tambien se necesitaran el resto de estructuras, para introducirlas en el menu.
//Postcondicion: Autenticacion de las credenciales introducidas, si coinciden con alguna de la base de datos, pues se accede al programa.
//Si el usuario es "usuario", accedera al menu de usuario, y si es "administrador", accedera al menu de admin.

void acceso(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2)
{
    int i, j=0, k=0, encontrado=0, encontrado2=0, encontrado3=3, preg=0;
    char usua[6], contra[9], c;

    leer_usuario(&usuario, &numUsuarios);
    system("cls");

    printf("Introduzca sus credenciales de acceso:\n");
    color(0, 2);
    printf("Usuario:\n");
    color(0, 15);
    pregunta(usua, 6);

    for(k=0; k<numUsuarios&&encontrado2==0; k++)
    {
        if(strcmp(usua, usuario[k].usuario)==0) //Comprueba si el usuario esta en la base de datos.
        {
            encontrado2=1;
        }
    }

    if(encontrado2==1) //Si el usuario esta en la base de datos, salta aqui.
    {
        while(encontrado3>0&&encontrado==0) //Sistema de 3 intentos para introducir la contrasena correctamente.
        {
            color(0, 3);
            printf("Contrasena:\n");
            color(0, 15);
            fflush(stdin);
            while ((c=getch())!='\r'&&j<8) //Lee el caracter, hasta 8.
            {
                if (c=='\b'&&j>0) //Si se borra algo, se borra un *, y se resta una posicion del vector.
                {
                    j--;
                    printf("\b \b");
                }
                else if (c != '\b') //Si se escribe algo, se imprime *, y se introduce en vector contra.
                {
                    contra[j++] = c;
                    printf("*");
                }
            }
            contra[j] = '\0';

            for(i=0; i<numUsuarios||encontrado!=0; i++) //Comprueba si el usuario y la contrasena son correctos.
            {
                if(strcmp(usuario[i].usuario,usua)==0)
                {
                    if(strcmp(usuario[i].contrasena,contra)==0)
                    {
                        if(strcmp(usuario[i].perfil,"usuario")==0) //Si el usuario, tiene perfil de "usuario", salta al menu de usuario.
                        {
                            encontrado=1;
                            menuUsuario(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                        }
                        else if(strcmp(usuario[i].perfil,"administrador")==0) //Si el usuario, tiene perfil de "administrador", salta al menu de admin.
                        {
                            encontrado=1;
                            menuAdmin(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                        }
                    }
                }
            }

            if(encontrado==0)
            {
                color(0, 4);
                printf("\nLa contrasena introducida es incorrecta.\n"); //Si la contrasena no es correcta, se imprime esta frase.
                encontrado3--; //Se resta 1 intento, hasta llegar a 0.
                if(encontrado3==0)
                {
                    color(15, 0);
                    printf("iIntentos agotados! :(\n");
                    color(0, 15);
                    system("PAUSE");
                }
                else if(encontrado3>0)
                {
                    *contra=NULL;
                    j=0;
                    color(15, 0);
                    printf("Queda(n) %i intentos.\n", encontrado3); //Imprime un contador de intentos, para saber cuantos quedan.
                    color(0, 15);
                    system("PAUSE");
                    system("cls");
                    printf("Introduzca sus credenciales de acceso:\n");
                    color(0, 2);
                    printf("Usuario:\n");
                    color(0, 15);
                    printf("%s\n", usua);
                }
            }
        }
    }
    else
    {
        printf("Usuario no encontrado en nuestra base de datos.\n"); //Si el usuario no esta en la base de datos.
        system("PAUSE");
    }
}

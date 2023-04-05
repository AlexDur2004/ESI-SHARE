#include "acceso.h"

//Prototipo: void acceso();
//Precondici�n: Tener inicializada la variable "numUsuarios", con el n�mero de usuarios m�ximos del fichero, y la estructura "usuario", con datos le�dos
//desde el fichero "usuarios.txt", y haber introducido el n�mero correspondiente en el men�.
//Postcondici�n: Autenticaci�n de las credenciales introducidas, si coinciden con alguna de la base de datos, pues se accede al programa.
//Si el usuario es "usuario", acceder� al men� de usuario, y si es "administrador", acceder� al men� de admin.

void acceso(Estr_Usuario *usuario, int numUsuarios, Estr_Vehiculo *vehiculo, int numVehiculos, Estr_Viaje *viaje, int numViajes, Estr_Pasos *pasos, int numPasos, Estr_Reservas *reservas, int numReservas, Estr_Localidad *localidad, int numLocalidades, Estr_Rutas **ruta, int numRutas, int numRutas2)
{
    int i, j=0, k=0, encontrado=0, encontrado2=0, encontrado3=3, preg=0;
    char usua[6], contra[9], c;

    leer_usuario(&usuario, &numUsuarios);

    printf("Introduzca sus credenciales de acceso:\nUsuario:\n");
    pregunta(usua, 6);

    for(k=0; k<numUsuarios&&encontrado2==0; k++)
    {
        if(strcmp(usua, usuario[k].usuario)==0) //Comprueba si el usuario est� en la base de datos.
        {
            encontrado2=1;
        }
    }

    if(encontrado2==1) //Si el usuario est� en la base de datos, salta aqu�.
    {
        while(encontrado3>0&&encontrado==0) //Sistema de 3 intentos para introducir la contrase�a correctamente.
        {
            printf("Contrasena:\n");
            fflush(stdin);
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

            for(i=0; i<numUsuarios||encontrado!=0; i++) //Comprueba si el usuario y la contrase�a son correctos.
            {
                if(strcmp(usuario[i].usuario,usua)==0)
                {
                    if(strcmp(usuario[i].contrasena,contra)==0)
                    {
                        if(strcmp(usuario[i].perfil,"usuario")==0) //Si el usuario, tiene perfil de "usuario", salta al men� de usuario.
                        {
                            encontrado=1;
                            menuUsuario(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                        }
                        else if(strcmp(usuario[i].perfil,"administrador")==0) //Si el usuario, tiene perfil de "administrador", salta al men� de admin.
                        {
                            encontrado=1;
                            menuAdmin(usuario, numUsuarios, vehiculo, numVehiculos, viaje, numViajes, pasos, numPasos, reservas, numReservas, localidad, numLocalidades, ruta, numRutas, numRutas2, i);
                        }
                    }
                    else
                    {
                        printf("\nLa contrasena introducida es incorrecta.\n"); //Si la contrase�a no es correcta, se imprime esta frase.
                        encontrado3--; //Se resta 1 intento, hasta llegar a 0.
                        if(encontrado3==0)
                        {
                            printf("�Intentos agotados! :(\n");
                            system("PAUSE");
                        }
                        else
                        {
                            *contra=NULL;
                            j=0;
                            printf("Queda(n) %i intentos.\n", encontrado3); //Imprime un contador de intentos, para saber cu�ntos quedan.
                            system("PAUSE");
                            system("cls");
                            printf("Introduzca sus credenciales de acceso:\nUsuario:\n");
                            printf("%s\n", usua);
                        }
                    }
                }
            }
        }
    }
    else
    {
        printf("Usuario no encontrado en nuestra base de datos.\n"); //Si el usuario no est� en la base de datos.
        system("PAUSE");
    }
}

#include "comprobar_usuario.h"

void acceso(Estr_Usuario *usuario, int n)
{
    int i, j=0, k=0, encontrado=0, encontrado2=0, preg=0;
    char usua[6], contra[9], c;

    printf("Introduzca sus credenciales de acceso:\nUsuario:\n");
    pregunta(usua, 6);
    for(k=0; k<numUsuarios&&encontrado2==0; k++)
    {
        if(strcmp(usua, usuario[k].usuario)==0)
        {
            encontrado2=1;
        }
    }
    if(encontrado2==1)
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

        for(i=0; i<n||encontrado!=0; i++)
        {
            if(strcmp(usuario[i].usuario,usua)==0)
            {
                if(strcmp(usuario[i].contrasena,contra)==0)
                {
                    if(strcmp(usuario[i].perfil,"usuario")==0)
                    {
                        encontrado=1;
                        menuUsuario(i);
                    }
                    else if(strcmp(usuario[i].perfil,"administrador")==0)
                    {
                        encontrado=1;
                        menuAdmin(i);
                    }
                }
                else
                {
                    printf("\nLa contrasena introducida es incorrecta.\n");
                    system("PAUSE");
                    return(0);
                }
            }
        }
    }
    else
    {
        printf("Usuario no encontrado en nuestra base de datos.\n");
        system("PAUSE");

        while(preg!=1||preg!=2||preg!=3)
        {
            system("cls");
            printf("¿Que quiere hacer?\n(1)Reintentar.\n(2)Registrarse.\n(3)Salir.\n");
            scanf("%1i", &preg);
            if(preg==1)
            {
                system("cls");
                acceso(usuario, numUsuarios);
            }
            else if(preg==2)
            {
                system("cls");
                altaUsuario(usuario,&numUsuarios);
            }
            else if(preg==3)
            {
                menuPrincipal();
            }
        }
    }
}

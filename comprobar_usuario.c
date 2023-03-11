#include "comprobar_usuario.h"

void acceso(Estr_Usuario *usuario, int n)
{
    int i, j=0, encontrado=0;
    char usua[6], contra[9], c;

    printf("Introduzca sus credenciales de acceso:\nUsuario:\n");
    fflush(stdin);
    scanf("%5s",usua);

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

    if(encontrado==0)
    {
        printf("\nUsuario no encontrado en nuestra base de datos.\n");
        system("PAUSE");
        menuPrincipal();
    }
}

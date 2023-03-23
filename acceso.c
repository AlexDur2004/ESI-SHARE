#include "acceso.h"

void acceso(Estr_Usuario *usuario, int n)
{
    int i, j=0, k=0, encontrado=0, encontrado2=0, encontrado3=3, preg=0;
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
        while(encontrado3>0&&encontrado==0)
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
                        encontrado3--;
                        if(encontrado3==0)
                        {
                            printf("¡Intentos agotados! :(\n");
                            system("PAUSE");
                        }
                        else
                        {
                            *contra=NULL;
                            j=0;
                            printf("Queda(n) %i intentos.\n", encontrado3);
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
        printf("Usuario no encontrado en nuestra base de datos.\n");
        system("PAUSE");
    }
}

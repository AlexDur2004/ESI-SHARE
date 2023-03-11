#include "modificar_perfil.h"

void modificarPerfilNombre(int i)
{
    FILE *fp;
    int n=0;
    char nomb[21];

    fp=fopen("usuarios.txt","r+");

    if(fp==NULL) {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else {
        printf("Introduzca su nuevo nombre completo (Máximo de 20 caracteres):\n");
        fflush(stdin);
        fgets(nomb, 21, stdin);

        char *lin=strchr(nomb, '\n');
        if(strchr(nomb,'\n')!=NULL)
        {
            *lin = '\0';
        }

        strcpy(usuario[i].nomb_usuario, nomb);
        do{
            fprintf(fp, "%s-%s-%s-%s-%s-%s\n", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
            n++;
        }while(n<numUsuarios-1);
        fprintf(fp, "%s-%s-%s-%s-%s-%s", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
        numUsuarios++;

        printf("Su nombre completo se ha actualizado correctamente.\n");
        system("PAUSE");
    }
    fclose(fp);
    leer_usuario(&usuario, &numUsuarios);

return;
}

void modificarPerfilLocalidad(int i)
{
    FILE *fp;
    int n=0;
    char localidad[21];

    fp=fopen("usuarios.txt","r+");

    if(fp==NULL) {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else {
        printf("Introduzca su nueva localidad de residencia (3 siglas):\n");
        fflush(stdin);
        pregunta_localidad(localidad);

        strcpy(usuario[i].localidad, localidad);
        do{
            fprintf(fp, "%s-%s-%s-%s-%s-%s\n", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
            n++;
        }while(n<numUsuarios-1);
        fprintf(fp, "%s-%s-%s-%s-%s-%s", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
        numUsuarios++;

        printf("Su localidad de residencia se ha actualizado correctamente.\n");
        system("PAUSE");
    }
    fclose(fp);
    leer_usuario(&usuario, &numUsuarios);

return;
}

void modificarPerfilUsuario(int i)
{
    FILE *fp;
    int n=0;
    char usua[6];

    fp=fopen("usuarios.txt","r+");

    if(fp==NULL) {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else {
        printf("Introduzca su nuevo nombre de usuario (Máximo de 5 caracteres):\n");
        fflush(stdin);
        fgets(usua, 6, stdin);

        char *lin=strchr(usua, '\n');
        if(strchr(usua,'\n')!=NULL)
        {
            *lin = '\0';
        }

        strcpy(usuario[i].usuario, usua);
        do{
            fprintf(fp, "%s-%s-%s-%s-%s-%s\n", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
            n++;
        }while(n<numUsuarios-1);
        fprintf(fp, "%s-%s-%s-%s-%s-%s", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
        numUsuarios++;

        printf("Su nombre de usuario se ha actualizado correctamente.\n");
        system("PAUSE");
    }
    fclose(fp);
    leer_usuario(&usuario, &numUsuarios);

return;
}

void modificarPerfilContrasena(int i)
{
    FILE *fp;
    int j=0, n=0, encontrado=3, x=0;
    char contra[9], contra2[9], c;

    fp=fopen("usuarios.txt","r+");

    if(fp==NULL) {
        printf("No se ha podido abrir el fichero vehiculos.txt.\n");
        return;
    }
    else {
        while(encontrado>=0&&x==0)
        {
            printf("Introduzca su antigua contrasena (Máximo de 8 caracteres):\n");
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

            if(strcmp(usuario[i].contrasena,contra)==0)
            {
                x=1;
                j=0;
                printf("\nIntroduzca su nueva contrasena (Máximo de 8 caracteres):\n");
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
                        contra2[j++] = c;
                        printf("*");
                    }
                }
                contra2[j] = '\0';

                strcpy(usuario[i].contrasena, contra2);
                do{
                    fprintf(fp, "%s-%s-%s-%s-%s-%s\n", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
                    n++;
                }while(n<numUsuarios-1);
                fprintf(fp, "%s-%s-%s-%s-%s-%s", usuario[n].id_usuario, usuario[n].nomb_usuario, usuario[n].localidad, usuario[n].perfil, usuario[n].usuario, usuario[n].contrasena);
                numUsuarios++;

                printf("\nSu contraseña se ha actualizado correctamente.\n");
                system("PAUSE");
            }
            else
            {
                encontrado--;
                printf("\nQueda(n) %i intentos.\n", encontrado);
                *contra=NULL;
                j=0;
            }
        }
    }
    fclose(fp);
    leer_usuario(&usuario, &numUsuarios);

return;
}


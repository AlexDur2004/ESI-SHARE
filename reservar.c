#include "reservar.h"

void reservarViaje()
{
    FILE *fp;
    char rutas[numRutas][100], partida[numLocalidades], **rutas_guard;
    int num_rutas=0, num_rutas_impresas=0, i=0, encontrado=0, cont=1, encontrado2=0;;

    fp=fopen("rutas.txt", "r");
    if(fp==NULL)
    {
        printf("No se pudo abrir el archivo rutas.txt.\n");
        return 1;
    }
    while(fgets(rutas[num_rutas], 100, fp)!=NULL)
    {
        num_rutas++;
    }
    fclose(fp);

    printf("Ingrese las siglas de la ciudad de partida:\n ");
    pregunta_ruta(partida);

    printf("%s", partida);

    for(i=0; i<num_rutas; i++)
    {
        char *ciudad;
        char *token=strtok(rutas[i], "-");
        encontrado=0;
        while(token!=NULL)
        {
            ciudad=token;
            if(strcmp(ciudad, partida)==0)
            {
                if(encontrado==0)
                {
                    printf("(%i)", cont-i);
                    printf("%s", ciudad);
                    encontrado=1;
                }
                else
                {
                    printf("-%s", ciudad);
                }
                token=strtok(NULL, "-");
                while(token!=NULL&&encontrado2==0)
                {
                    cont++;
                    if(strcmp(token, "ESI")==0)
                    {
                        printf("-%s\n", token);
                        encontrado2=1;
                    }
                    if(encontrado==0)
                    {
                        printf("-%s", token);
                        encontrado=1;
                    }
                    else
                    {
                        printf("-%s", token);
                    }
                    token=strtok(NULL, "-");
                }
            }
            else
            {
                token=strtok(NULL, "-");
            }
        }
    }

    printf("Cantidad de rutas encontradas: %i\n", cont);
    system("PAUSE");
    return;
}

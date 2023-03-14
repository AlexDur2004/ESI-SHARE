#include "reservar.h"

void reservarViaje()
{
    FILE *fp;
    char rutas[numRutas][100], partida[numLocalidades], **rutas_guard, rutas_impr[numRutas][100];;
    int i=0, j=0, num_rutas=0, encontrado=0, encontrado2=0, numGuardados=0, numImpresos=0, repetido=0;

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

    rutas_guard=(char **)calloc(num_rutas, sizeof(char*));
    for(i=0; i<num_rutas; i++)
    {
        rutas_guard[i]=(char *)calloc(100, sizeof(char));
    }

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
                    strcat(rutas_guard[numGuardados], ciudad);
                    encontrado=1;
                }
                token=strtok(NULL, "-");
                while(token!=NULL&&encontrado2==0)
                {
                    if(strcmp(token, "ESI")==0&&encontrado==0)
                    {
                        strcat(rutas_guard[numGuardados], "-");
                        strcat(rutas_guard[numGuardados], token);
                        encontrado=1;
                    }
                    else
                    {
                        strcat(rutas_guard[numGuardados], "-");
                        strcat(rutas_guard[numGuardados], token);
                    }
                    token=strtok(NULL, "-");
                }
                numGuardados++;
            }
            else
            {
                token=strtok(NULL, "-");
            }
        }
    }

    for(i=0; i<numGuardados; i++)
    {
        repetido=0;
        for(j=0; j<numImpresos&&repetido==0; j++)
        {
            if(strcmp(rutas_guard[i], rutas_impr[j])==0)
            {
                repetido=1;

            }
        }
        if(!repetido)
        {
            strcpy(rutas_impr[numImpresos],rutas_guard[i]);
            printf("%s", rutas_guard[i]);
            numImpresos++;
        }
    }

    printf("Cantidad de rutas encontradas: %i\n", numImpresos);
    system("PAUSE");
    return;
}

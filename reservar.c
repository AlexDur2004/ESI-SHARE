#include "reservar.h"

void buscadorRutas(Estr_Rutas **ruta, int numRutas, int numRutas2, Estr_Localidad *localidad, int numLocalidades, Estr_Pasos *pasos, int numPasos, char id_viaje[7])
{
    FILE *fp;
    char rutas[numRutas][100], partida[numLocalidades], **rutas_guard, **rutas_impr, *token;
    int i=0, j=0, num_rutas=0, encontrado=0, encontrado2=0, numGuardados=0, numImpresos=0, repetido=0, opc=0;

    fp=fopen("DATA/rutas.txt", "r");
    if(fp==NULL)
    {
        printf("No se pudo abrir el archivo rutas.txt.\n");
        exit(1);
    }
    while(fgets(rutas[num_rutas], 100, fp)!=NULL)
    {
        num_rutas++;
    }
    fclose(fp);

    printf("Ingrese las siglas de la ciudad de partida/salida:\n");
    pregunta_ruta(localidad, numLocalidades, ruta, numRutas, numRutas2, partida);

    rutas_guard=(char **)calloc(num_rutas, sizeof(char*));
    if (rutas_guard==NULL)
    {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    for(i=0; i<num_rutas; i++)
    {
        rutas_guard[i]=(char *)calloc(100, sizeof(char));
        if (rutas_guard[i]==NULL)
        {
            printf("Error al asignar memoria.\n");
            exit(1);
        }
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

    rutas_impr=(char **)calloc(numRutas, sizeof(char*));
    if (rutas_impr==NULL)
    {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    for(i=0; i<numRutas2; i++)
    {
        rutas_impr[i]=(char *)calloc(50, sizeof(char));
        if (rutas_impr[i]==NULL)
        {
            printf("Error al asignar memoria.\n");
            exit(1);
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
            rutas_impr=(char **)realloc(rutas_impr,(numImpresos+1)*sizeof(char*));
            rutas_impr[numImpresos]=(char *)calloc(50, sizeof(char));
            strcpy(rutas_impr[numImpresos], rutas_guard[i]);
            printf("(%i)%s", numImpresos+1, rutas_guard[i]);
            numImpresos++;
        }
    }
    printf("Cantidad de rutas encontradas: %i\n", numImpresos);

    do{
        printf("Seleccione el n�mero de la ruta que quiere escoger: ");
        scanf("%1i", &opc);
    }while(opc<1||opc>numImpresos);

    imprimirPasos(pasos, numPasos, localidad, numLocalidades, id_viaje, token, rutas_impr[opc-1]);

    system("PAUSE");
}

void imprimirPasos(Estr_Pasos *pasos, int numPasos, Estr_Localidad *localidad, int numLocalidades, char *id_viaje, char *token, char *ruta)
{
    FILE *fp;
    int j=0, i=0, x=0, n=0;
    char *ciudad, *ciudades[10];

    ciudad=strtok(ruta, "-");
    while(ciudad!=NULL)
    {
        ciudades[j]=(char *)malloc(4*sizeof(char));
        strcpy(ciudades[j], ciudad);
        j++;
        ciudad=strtok(NULL, "-");
    }

    fp=fopen("DATA/pasos.txt","a+");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero pasos.txt.\n");
        return;
    }
    else
    {
        for(i=0; i<j; i++)
        {
            for(x=0; x<numLocalidades; x++)
            {
                if(strcmp(ciudades[i], localidad[x].siglas)==0)
                {
                    fprintf(fp, "%s-%s\n", id_viaje, localidad[x].localidad);
                    numPasos++;
                }
            }
        }
    }

    fclose(fp);

    leer_pasos(&pasos,&numPasos);
}

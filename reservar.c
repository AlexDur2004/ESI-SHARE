#include "reservar.h"

//Prototipo: void buscadorRutas(Estr_Rutas **, int, int, Estr_Localidad *, int, Estr_Pasos *, int, char [7]);
//Precondición: Tener las estructuras "ruta", "localidad" y "pasos", con sus contadores. Además, debemos tener una cadena inicializada con la id de viaje.
//Postcondición: Buscar todas las rutas posibles, desde la ciudad seleccionada hasta la ESI.

void buscadorRutas(Estr_Rutas **ruta, int numRutas, int numRutas2, Estr_Localidad *localidad, int numLocalidades, Estr_Pasos *pasos, int numPasos, char id_viaje[7])
{
    FILE *fp;
    char rutas[numRutas][50], partida[numLocalidades], **rutas_guard, **rutas_impr, *token;
    int i=0, j=0, encontrado=0, encontrado2=0, numGuardados=0, numImpresos=0, repetido=0, opc=0;

    fp=fopen("DATA/rutas.txt", "r"); //Abrimos el fichero rutas.txt
    if(fp==NULL)
    {
        printf("No se pudo abrir el archivo rutas.txt.\n");
        exit(1);
    }
    for(i=0; fgets(rutas[i], 100, fp)!=NULL ; i++) //Vamos introduciendo en la matriz rutas, todas las rutas que tiene el fichero, hasta el fin de fichero.
    {
        fgets(rutas[i], 100, fp);
    }
    fclose(fp);

    printf("Ingrese las siglas de la ciudad de partida/destino:\n");
    pregunta_ruta(localidad, numLocalidades, ruta, numRutas, numRutas2, partida); //Pedimos ciudad de partida o destino

    rutas_guard=(char **)calloc(numRutas, sizeof(char*)); //Asignamos espacio de memoria, para las columnas de la matriz.
    if (rutas_guard==NULL)
    {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    for(i=0; i<numRutas; i++) //Vamos introduciendo espacios de memoria de 50 caracteres a cada fila de la matriz.
    {
        rutas_guard[i]=(char *)calloc(50, sizeof(char));
        if (rutas_guard[i]==NULL)
        {
            printf("Error al asignar memoria.\n");
            exit(1);
        }
    }

    for(i=0; i<numRutas; i++) //Nos desplazamos por toda la estructura "ruta".
    {
        char *ciudad;
        char *token=strtok(rutas[i], "-");
        encontrado=0;
        while(token!=NULL) //Cuando ya no haya -, significa que ha terminado la ruta.
        {
            ciudad=token;
            if(strcmp(ciudad, partida)==0) //Si al ciudad de partida está en la ruta, la guardamos.
            {
                if(encontrado==0)
                {
                    strcat(rutas_guard[numGuardados], ciudad); //Guardamos la ciudad.
                    encontrado=1;
                }
                token=strtok(NULL, "-");
                while(token!=NULL&&encontrado2==0) //Hasta que no acabe la ruta, o aparezca ESI, no dejamos de introducir ciudades, para hacer la ruta.
                {
                    if(strcmp(token, "ESI")==0&&encontrado==0) //Si encontramos ESI, pasamos a escanear la siguiente ruta, con la variable bandera.
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
                numGuardados++; //Vamos aumentando la variable delimitadora, para luego hacer un for.
            }
            else
            {
                token=strtok(NULL, "-");
            }
        }
    }

    rutas_impr=(char **)calloc(numRutas, sizeof(char*)); //Asignamos espacio de memoria, para las columnas de la matriz.
    if (rutas_impr==NULL)
    {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    for(i=0; i<numRutas2; i++) //Vamos introduciendo espacios de memoria de 50 caracteres a cada fila de la matriz.
    {
        rutas_impr[i]=(char *)calloc(50, sizeof(char));
        if (rutas_impr[i]==NULL)
        {
            printf("Error al asignar memoria.\n");
            exit(1);
        }
    }

    for(i=0; i<numGuardados; i++) //Nos desplazamos por toda la matriz "rutas_guard".
    {
        repetido=0;
        for(j=0; j<numImpresos&&repetido==0; j++) //Nos desplazamos por toda la matriz "rutas_impr".
        {
            if(strcmp(rutas_guard[i], rutas_impr[j])==0) //Si la ruta guardada coincide con la ruta impresa, se omite.
            {
                repetido=1;
            }
        }

        if(!repetido) //Si la ruta no está repetida, se imprime.
        {
            rutas_impr=(char **)realloc(rutas_impr,(numImpresos+1)*sizeof(char*)); //Asignamos un espacio de memoria más.
            rutas_impr[numImpresos]=(char *)calloc(50, sizeof(char)); //Introducimos un espacio de memoria de 50 caracteres a la fila creada.
            strcpy(rutas_impr[numImpresos], rutas_guard[i]); //Copiamos la ruta impresa en la matriz.
            printf("(%i)%s", numImpresos+1, rutas_guard[i]); //Imprimimos la ruta.
            numImpresos++;
        }
    }
    printf("\nCantidad de rutas encontradas: %i\n", numImpresos);

    do{
        printf("Seleccione el número de la ruta que quiere escoger: ");
        scanf("%1i", &opc);
    }while(opc<1||opc>numImpresos);

    imprimirPasos(pasos, numPasos, localidad, numLocalidades, id_viaje, rutas_impr[opc-1]); //Imprimimos las localidades de la ruta seleccionada en el fichero pasos.txt
}

//Prototipo: void imprimirPasos(Estr_Pasos *, int, Estr_Localidad *, int, char *, char *);
//Precondición: Tener las estructuras "pasos" y "localidad", con sus contadores. Además, debemos tener una cadena inicializada con la id de viaje, y otra cadena con la ruta que queremos imprimir.
//Postcondición: Imprimir los pasos de la ruta seleccionada, en el fichero.

void imprimirPasos(Estr_Pasos *pasos, int numPasos, Estr_Localidad *localidad, int numLocalidades, char *id_viaje, char *ruta)
{
    FILE *fp;
    int j=0, i=0, x=0, n=0;
    char *ciudad, *ciudades[10];

    ciudad=strtok(ruta, "-"); //Vamos separando la ruta, en siglas.
    while(ciudad!=NULL) //Hasta que no haya acabado la ruta.
    {
        ciudades[j]=(char *)malloc(4*sizeof(char)); //Asignamos un espacio de memoria para las siglas de la localidad.
        strcpy(ciudades[j], ciudad); //Copiamos las siglas en el vector.
        j++;
        ciudad=strtok(NULL, "-"); //Vamos haciendo lo mismo hasta que acabe la ruta.
    }

    fp=fopen("DATA/pasos.txt","a+"); //Abrimos el fichero "pasos.txt" en modo edición.

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero pasos.txt.\n");
        return;
    }
    else
    {
        for(i=0; i<j; i++) //Nos desplazamos por el vector "ciudades".
        {
            for(x=0; x<numLocalidades; x++) //Nos desplazamos por la estructura "localidad".
            {
                if(strcmp(ciudades[i], localidad[x].siglas)==0) //Si las siglas de la ciudad, coinciden con las de la estructura.
                {
                    fprintf(fp, "%s-%s\n", id_viaje, localidad[x].localidad); //Imprimimos la localidad a la que le corresponden las siglas, junto a la id de viaje.
                    numPasos++;
                }
            }
        }
    }

    fclose(fp);

    printf("La ruta seleccionada se ha asignado correctamente al viaje con ID %s", id_viaje);
    system("PAUSE");

    leer_pasos(&pasos,&numPasos); //Actualizamos la estructura "pasos".
    system("cls");
}

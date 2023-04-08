#include "fecha.h"

//Prototipo: void actualizarViajes(Estr_Viaje *, int, Estr_Reservas *, int, Estr_Pasos *, int);
//Precondición: Tener las estructuras "viaje" y "reservas", con sus contadores.
//Postcondición: Actualiza el estado de todos los viajes, si se ha pasado la hora de inicio, pues se pone en estado "Iniciado",
//mientras que si se ha excedido una hora desde la hora de llegada, pues se establece en estado "Finalizado", y se eliminan sus pasos y reservas.

void actualizarViajes(Estr_Viaje *viaje, int numViajes, Estr_Reservas *reservas, int numReservas, Estr_Pasos *pasos, int numPasos)
{
    FILE *fp;
    char *token=NULL, vec_fecha[11], vec_h_inic[6], vec_h_fin[6];
    int n=0, i=0, min_inic=0, hora_inic=0, min_fin=0, hora_fin=0, dia=0, mes=0, ano=0, encontrado=0;

    fp=fopen("DATA/viajes.txt","r+");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero viajes.txt.\n");
        return;
    }
    else
    {
        for(i=0; i<numViajes; i++) //Nos desplazamos por todal la estructura "Viajse"
        {
            strcpy(vec_fecha, viaje[i].f_inic); //Obtenemos la fecha de inicio, y la separamos en 3 enteros.
            token=strtok(vec_fecha, "/");
            dia=atoi(token);
            token=strtok(NULL, "/");
            mes=atoi(token);
            token=strtok(NULL, "\n");
            ano=atoi(token);

            strcpy(vec_h_inic, viaje[i].h_inic); //Obtenemos la hora de inicio, y la separamos en 2 enteros.
            token=strtok(vec_h_inic, ":");
            hora_inic=atoi(token);
            token=strtok(NULL, "\n");
            min_inic=atoi(token);

            time_t ahora=time(NULL); //Esta sería la hora actual, en segundos.

            struct tm tiempo_introducido={0}; //Definimos estructura para poner años desde 2023, meses y días.
            tiempo_introducido.tm_year=ano-1900; //Metemos todos los enteros de la fecha y la hora de inicio, en la estructura.
            tiempo_introducido.tm_mon=mes-1;
            tiempo_introducido.tm_mday=dia;
            tiempo_introducido.tm_hour=hora_inic-1;
            tiempo_introducido.tm_min=min_inic;

            time_t tiempo_introducido_segundos=mktime(&tiempo_introducido); //Transforma la estructura de (dia/mes/ano y hora:segundos) a segundos.

            if(tiempo_introducido_segundos<ahora) //Si la fecha actual es posterior a la fecha y hora de partida del viaje.
            {
                if(strcmp(viaje[i].estado, "abierto")==0||strcmp(viaje[i].estado, "cerrado")==0) //Si el viaje está en "abierto" o "cerrado".
                {
                    strcpy(viaje[i].estado, "iniciado"); //Se le asigna como estado "iniciado".
                    encontrado=1;
                }

                if(strcmp(viaje[i].estado, "iniciado")==0) //Si el viaje está en "iniciado".
                {
                    strcpy(vec_h_fin, viaje[i].h_fin); //Obtenemos la hora de llegada, y la separamos en 2 enteros.
                    token=strtok(vec_h_fin, ":");
                    hora_fin=atoi(token);
                    token=strtok(NULL, "\n");
                    hora_inic=atoi(token);

                    struct tm tiempo_introducido={0}; //Definimos estructura para poner años desde 2023, meses y días.
                    tiempo_introducido.tm_year=ano-1900; //Metemos todos los enteros de la fecha y la hora de llegada con 1 hora más, en la estructura.
                    tiempo_introducido.tm_mon=mes-1;
                    tiempo_introducido.tm_mday=dia;
                    tiempo_introducido.tm_hour=hora_fin;
                    tiempo_introducido.tm_min=min_fin;

                    time_t tiempo_introducido_segundos=mktime(&tiempo_introducido); //Transforma la estructura de (dia/mes/ano y hora:segundos) a segundos.

                    if(tiempo_introducido_segundos<ahora) //Si la fecha actual es posterior a la fecha y hora de llegada + 1 hora, del viaje.
                    {
                        strcpy(viaje[i].estado, "finalizado"); //Se le asigna como estado "finalizado".
                        encontrado=1;
                        eliminarPasos(pasos, numPasos, viaje[i].id_viaje); //Eliminamos los pasos del viaje.
                        eliminarReservas(reservas, numReservas, viaje[i].id_viaje); //Eliminamos las reservas del viaje.
                    }
                }
            }
        }

        if(encontrado==1) //Si ha habido algún cambio, se imprime en el fichero.
        {
            do{
            fprintf(fp, "%s-%s-%s-%s-%s-%s-%s-%s-%s\n", viaje[n].id_viaje, viaje[n].id_mat, viaje[n].f_inic, viaje[n].h_inic, viaje[n].h_fin, viaje[n].plazas_libre, viaje[n].ida_vuelta, viaje[n].precio, viaje[n].estado);
            n++;
            }while(n<numViajes-1);
            fprintf(fp, "%s-%s-%s-%s-%s-%s-%s-%s-%s", viaje[n].id_viaje, viaje[n].id_mat, viaje[n].f_inic, viaje[n].h_inic, viaje[n].h_fin, viaje[n].plazas_libre, viaje[n].ida_vuelta, viaje[n].precio, viaje[n].estado);
        }
    }

    fclose(fp);

    leer_viaje(&viaje,&numViajes);
}

//Prototipo: void leerFecha(char *, char *, char *);
//Precondición: Tener los cadenas "fecha", "h_inic" y "h_fin" inicializados.
//Postcondición: Leer la fecha, hora de inicio y hora de llegada, y comprobar si son válidas, y posteriores a las actuales. Después, se introducen en su respectiva cadena.

void leerFecha(char fecha[11], char h_inic[6], char h_fin[6])  //DD/MM/AAAA
{
    int min_inic=0, hora_inic=0, min_fin=0, hora_fin=0, dia=0, mes=0, ano=0, maxdia=0, encontrado=0, encontrado3=0;
    char *token=NULL;

    leer_dia(fecha); //Usamos la funcion "leer_dia", para leer la fecha, y ver si es válida.

    token=strtok(fecha, "/"); //Desglosamos la fecha en 3 enteros, para introducirlos en la estructura, al pedir la hora.
    dia=atoi(token);
    token=strtok(NULL, "/");
    mes=atoi(token);
    token=strtok(NULL, "\n");
    ano=atoi(token);

    while(encontrado3==0)
    {
        sprintf(fecha, "%02i/%02i/%04i", dia, mes, ano); //Se introduce los enteros en formato DD/MM/AAAA en la cadena "fecha".
        system("cls");
        printf("La fecha introducida es: %s\n", fecha);

        printf("Introduzca la hora de inicio (HH:MM) y la hora de llegada (HH:MM) de su viaje:\n");
        printf("Hora de inicio:\n");

        encontrado=0;
        while(encontrado==0) //Lee el entero "hora_inic", hasta que sea correcto.
        {
            printf("Hora:");
            fflush(stdin);
            scanf("%2d", &hora_inic);

            if(hora_inic<0||hora_inic>23)
            {
                while(getchar()!='\n');
            }
            else
            {
                encontrado=1;
            }
        }

        encontrado=0;
        while(encontrado==0) //Lee el entero "min_inic", hasta que sea correcto.
        {
            printf("Minutos:");
            fflush(stdin);
            scanf("%2d", &min_inic);

            if(min_inic<0||min_inic>59)
            {
                while(getchar()!='\n');
            }
            else
            {
                encontrado=1;
            }
        }

        sprintf(h_inic, "%02i:%02i", hora_inic, min_inic); //Se introduce los enteros en formato MM:SS en la cadena "h_inic"

        printf("Hora de llegada:\n");

        encontrado=0;
        while(encontrado==0) //Lee el entero "hora_fin", hasta que sea correcto.
        {
            printf("Hora:");
            fflush(stdin);
            scanf("%2d", &hora_fin);

            if(hora_fin<0||hora_fin>23)
            {
                while(getchar()!='\n');
            }
            else
            {
                encontrado=1;
            }
        }

        encontrado=0;
        while(encontrado==0) //Lee el entero "min_fin", hasta que sea correcto.
        {
            printf("Minutos:");
            fflush(stdin);
            scanf("%2d", &min_fin);

            if(min_fin<0||min_fin>59)
            {
                while(getchar()!='\n');
            }
            else
            {
                break;
            }
        }

        sprintf(h_fin, "%02i:%02i", hora_fin, min_fin); //Se introduce los enteros en formato MM:SS en la cadena "h_fin"

        if(hora_fin>hora_inic||min_fin>min_inic) //Se compara si la hora y min fin son mayores a las de inicio.
        {
            time_t ahora=time(NULL); //Esta sería la hora actual, en segundos.

            struct tm tiempo_introducido={0}; //definimos estructura para poner años desde 2023, meses y días.
            tiempo_introducido.tm_year=ano-1900; //Metemos todos los enteros de la hora de inicio, en la estructura.
            tiempo_introducido.tm_mon=mes-1;
            tiempo_introducido.tm_mday=dia;
            tiempo_introducido.tm_hour=hora_inic-1;
            tiempo_introducido.tm_min=min_inic;

            time_t tiempo_introducido_segundos=mktime(&tiempo_introducido); //Transforma la estructura de (dia/mes/ano y min/seg) a segundos.

            if(tiempo_introducido_segundos<ahora) //Comparamos si la fecha y hora introducidas son anteriores a la fecha y hora actual.
            {
                printf("La fecha y hora de inicio ingresada es anterior a la fecha y hora actual.\n");
                system("PAUSE");
                system("cls");
            }
            else //Si son posteriores, se cumple todo.
            {
                system("cls");
                printf("La fecha introducida es: %s\n", fecha);
                printf("La hora de inicio introducida es: %s\n", h_inic);
                printf("La hora de llegada introducida es: %s\n", h_fin);
                system("PAUSE");
                encontrado3=1;
            }
        }
        else //Imprime aviso, si la hora de llegada no es posterior.
        {
            printf("La hora de llegada es anterior a la hora de inicio.\n");
            system("PAUSE");
            system("cls");
        }
    }
}

//Prototipo: void leer_dia(char *);
//Precondición: Tener la cadena "fecha" inicializada.
//Postcondición: Leer la fecha, y comprobar si es válida, y posterior a las actual. Si esto se cumple, se guarda en la cadena.

void leer_dia(char fecha[11])  //DD/MM/AAAA
{
    int dia=0, mes=0, ano=0, maxdia=0, encontrado=0, encontrado2=0;

    while(encontrado2==0) //Hacer esto hasta que se encuentre una fecha válida.
    {
        system("cls");
        printf("Introduzca la fecha (DD/MM/AAAA) en la que quiere realizar su viaje:\n");

        encontrado=0;
        while(encontrado==0) //Lee el entero "dia", hasta que sea correcto.
        {
            printf("Día:");
            fflush(stdin);
            scanf("%2d", &dia);

            if(dia<1||dia>31)
            {
                while(getchar()!='\n');
            }
            else
            {
                encontrado=1;
            }
        }

        encontrado=0;
        while(encontrado==0) //Lee el entero "mes", hasta que sea correcto.
        {
            printf("Mes:");
            fflush(stdin);
            scanf("%2d", &mes);

            if(mes<1||mes>12)
            {
                while(getchar()!='\n');
            }
            else
            {
                encontrado=1;
            }
        }

        encontrado=0;
        while(encontrado==0) //Lee el entero "ano", hasta que sea correcto.
        {
            printf("Año:");
            fflush(stdin);
            scanf("%4d",&ano);

            if(ano<2023)
            {
                while(getchar()!='\n');
            }
            else
            {
                encontrado=1;
            }
        }
        maxdia=dias_meses(mes,ano); //Llama a función maxdia, para saber si el ano es bisiesto, o si el mes tiene 28, 29, 30 o 31 dias.

        if(dia<1||dia>maxdia||mes<1||mes>12||ano<1)
        {
            printf("La fecha no es válida.\n");
            system("PAUSE");
            system("cls");
        }
        else
        {
            time_t ahora=time(NULL); //Esta sería la hora actual, en segundos.

            struct tm tiempo_introducido={0}; //definimos estructura para poner años desde 2023, meses y días.
            tiempo_introducido.tm_year=ano-1900; //Metemos todos los enteros de la fecha, en la estructura.
            tiempo_introducido.tm_mon=mes-1;
            tiempo_introducido.tm_mday=dia+1;

            time_t tiempo_introducido_segundos=mktime(&tiempo_introducido); //Transforma la estructura de (dia/mes/ano) a segundos.

            if(tiempo_introducido_segundos<ahora) //Si la fecha actual es posterior a la fecha introducida.
            {
                printf("La fecha ingresada es anterior a la fecha actual.\n");
                system("PAUSE");
                system("cls");
            }
            else //Si la fecha no es correcta, vuelve a pedir la fecha.
            {
                encontrado2=1;
            }
        }
    }
    sprintf(fecha, "%02i/%02i/%04i", dia, mes, ano); //Se introduce los enteros en formato DD/MM/AAAA en la cadena "fecha".
    system("cls");
    printf("La fecha introducida es: %s\n", fecha);
    system("PAUSE");
}

//Prototipo: int dias_meses(int, int);
//Precondición: Tener los enteros "mes" y "ano" inicializados.
//Postcondición: Devuelve el numero de dias que hay en cada mes del ano. También se comtemplan los anos bisiestos.

int dias_meses(int mes, int ano)
{
    int dias=31; //suponemos que hay 31 días.

    if (mes==4||mes==6||mes==9||mes==11)
    {
        dias=30; //abril, junio, septiembre y noviembre tienen 30 días
    }
    else if (mes==2)
    {
        if ((ano%4==0&&ano%100!=0)||ano%400==0)
        {
            dias=29; //febrero tiene 29 días en años bisiestos
        }
        else
        {
            dias=28; //febrero tiene 28 días en años no bisiestos
        }
    }

return dias;
}

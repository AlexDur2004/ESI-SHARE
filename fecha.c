#include "fecha.h"

void actualizarViajes(Estr_Viaje *viaje, int numViajes, Estr_Reservas *reservas, int numReservas)
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
        for(i=0; i<numViajes; i++)
        {
            strcpy(vec_fecha, viaje[i].f_inic);
            token=strtok(vec_fecha, "/");
            dia=atoi(token);
            token=strtok(NULL, "/");
            mes=atoi(token);
            token=strtok(NULL, "\n");
            ano=atoi(token);

            strcpy(vec_h_inic, viaje[i].h_inic);
            token=strtok(vec_h_inic, ":");
            hora_inic=atoi(token);
            token=strtok(NULL, "\n");
            min_inic=atoi(token);

            time_t ahora=time(NULL);

            struct tm tiempo_introducido={0}; //definimos estructura para poner años desde 2023, meses y días.
            tiempo_introducido.tm_year=ano-1900;
            tiempo_introducido.tm_mon=mes-1;
            tiempo_introducido.tm_mday=dia;
            tiempo_introducido.tm_hour=hora_inic-1;
            tiempo_introducido.tm_min=min_inic;

            time_t tiempo_introducido_segundos=mktime(&tiempo_introducido);

            if(tiempo_introducido_segundos<ahora)
            {
                if(strcmp(viaje[i].estado, "abierto")==0||strcmp(viaje[i].estado, "cerrado")==0)
                {
                    strcpy(viaje[i].estado, "iniciado");
                    encontrado=1;
                }

                if(strcmp(viaje[i].estado, "iniciado")==0)
                {
                    strcpy(vec_h_fin, viaje[i].h_fin);
                    token=strtok(vec_h_fin, ":");
                    hora_fin=atoi(token);
                    token=strtok(NULL, "\n");
                    hora_inic=atoi(token);

                    struct tm tiempo_introducido={0}; //definimos estructura para poner años desde 2023, meses y días.
                    tiempo_introducido.tm_year=ano-1900;
                    tiempo_introducido.tm_mon=mes-1;
                    tiempo_introducido.tm_mday=dia;
                    tiempo_introducido.tm_hour=hora_fin;
                    tiempo_introducido.tm_min=min_fin;

                    time_t tiempo_introducido_segundos=mktime(&tiempo_introducido);

                    if(tiempo_introducido_segundos<ahora)
                    {
                        strcpy(viaje[i].estado, "finalizado");
                        encontrado=1;
                        eliminarReservas(reservas, numReservas, viaje[i].id_viaje);
                    }
                }
            }
        }

        if(encontrado==1)
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

void leerFecha(char fecha[11], char h_inic[6], char h_fin[6])  //DD/MM/AAAA
{
    int min_inic=0, hora_inic=0, min_fin=0, hora_fin=0, dia=0, mes=0, ano=0, maxdia=0, encontrado=0, encontrado2=0, encontrado3=0;

    while(encontrado2==0)
    {
        system("cls");
        printf("Introduzca la fecha (DD/MM/AAAA) en la que quiere realizar su viaje:\n");

        encontrado=0;
        while(encontrado==0)
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
        while(encontrado==0)
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
        while(encontrado==0)
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
        maxdia=dias_meses(mes,ano);

        if(dia<1||dia>maxdia||mes<1||mes>12||ano<1)
        {
            printf("La fecha no es válida.\n");
            system("PAUSE");
            system("cls");
        }
        else
        {
            time_t ahora=time(NULL);

            struct tm tiempo_introducido={0}; //definimos estructura para poner años desde 2023, meses y días.
            tiempo_introducido.tm_year=ano-1900;
            tiempo_introducido.tm_mon=mes-1;
            tiempo_introducido.tm_mday=dia+1;

            time_t tiempo_introducido_segundos=mktime(&tiempo_introducido);

            if(tiempo_introducido_segundos<ahora)
            {
                printf("La fecha ingresada es anterior a la fecha actual.\n");
                system("PAUSE");
                system("cls");
            }
            else
            {
                encontrado2=1;
            }
        }
    }

    if(encontrado2==1)
    {
        while(encontrado3==0)
        {
            sprintf(fecha, "%02i/%02i/%04i", dia, mes, ano);
            system("cls");
            printf("La fecha introducida es: %s\n", fecha);

            printf("Introduzca la hora de inicio (HH:MM) y la hora de llegada (HH:MM) de su viaje:\n");

            printf("Hora de inicio:\n");

            encontrado=0;
            while(encontrado==0)
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
            while(encontrado==0)
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

            sprintf(h_inic, "%02i:%02i", hora_inic, min_inic);

            printf("Hora de llegada:\n");

            encontrado=0;
            while(encontrado==0)
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
            while(encontrado==0)
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

            sprintf(h_fin, "%02i:%02i", hora_fin, min_fin);

            if(hora_fin>hora_inic||min_fin>min_inic)
            {
                time_t ahora=time(NULL);

                struct tm tiempo_introducido={0}; //definimos estructura para poner años desde 2023, meses y días.
                tiempo_introducido.tm_year=ano-1900;
                tiempo_introducido.tm_mon=mes-1;
                tiempo_introducido.tm_mday=dia;
                tiempo_introducido.tm_hour=hora_inic-1;
                tiempo_introducido.tm_min=min_inic;

                time_t tiempo_introducido_segundos=mktime(&tiempo_introducido);

                if(tiempo_introducido_segundos<ahora)
                {
                    printf("La fecha y hora de inicio ingresada es anterior a la fecha y hora actual.\n");
                    system("PAUSE");
                    system("cls");
                }
                else
                {
                    system("cls");
                    printf("La fecha introducida es: %s\n", fecha);
                    printf("La hora de inicio introducida es: %s\n", h_inic);
                    printf("La hora de llegada introducida es: %s\n", h_fin);
                    system("PAUSE");
                    encontrado3=1;
                }
            }
            else
            {
                printf("La hora de llegada es anterior a la hora de inicio.\n");
                system("PAUSE");
                system("cls");

            }
        }
    }
}


void leer_dia(char fecha[11])  //DD/MM/AAAA
{
    int dia=0, mes=0, ano=0, maxdia=0, encontrado=0, encontrado2=0;

    while(encontrado2==0)
    {
        system("cls");
        printf("Introduzca la fecha (DD/MM/AAAA) en la que quiere realizar su viaje:\n");

        encontrado=0;
        while(encontrado==0)
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
        while(encontrado==0)
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
        while(encontrado==0)
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
        maxdia=dias_meses(mes,ano);

        if(dia<1||dia>maxdia||mes<1||mes>12||ano<1)
        {
            printf("La fecha no es válida.\n");
            system("PAUSE");
            system("cls");
        }
        else
        {
            time_t ahora=time(NULL);

            struct tm tiempo_introducido={0}; //definimos estructura para poner años desde 2023, meses y días.
            tiempo_introducido.tm_year=ano-1900;
            tiempo_introducido.tm_mon=mes-1;
            tiempo_introducido.tm_mday=dia+1;

            time_t tiempo_introducido_segundos=mktime(&tiempo_introducido);

            if(tiempo_introducido_segundos<ahora)
            {
                printf("La fecha ingresada es anterior a la fecha actual.\n");
                system("PAUSE");
                system("cls");
            }
            else
            {
                encontrado2=1;
            }
        }
    }
    sprintf(fecha, "%02i/%02i/%04i", dia, mes, ano);
    system("cls");
    printf("La fecha introducida es: %s\n", fecha);
    system("PAUSE");
}

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

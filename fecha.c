#include "fecha.h"

void leer_fecha(char fecha[11], char h_inic[6], char h_fin[6])  //DD/MM/AAAA
{
    int min_inic=0, hora_inic=0, min_fin=0, hora_fin=0, dia=0, mes=0, ano=0, maxdia=0;

    printf("Introduzca la fecha (DD/MM/AAAA) en la que quiere realizar su viaje:\n");

    while(1)
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
            break;
        }
    }

    while(1)
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
            break;
        }
    }

    while(1)
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
            break;
        }
    }

    maxdia=dias_meses(mes,ano);

    if(dia<1||dia>maxdia||mes<1||mes>12||ano<1)
    {
        printf("La fecha no es válida.\n");
    }
    else
    {
        sprintf(fecha, "%02i/%02i/%04i", dia, mes, ano);
        system("cls");
        printf("La fecha introducida es: %s\n", fecha);

        printf("Introduzca la hora de inicio (HH:MM) y la hora de llegada (HH:MM) de su viaje:\n");

        printf("Hora de inicio:\n");

        while(1)
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
                break;
            }
        }

        while(1)
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
                break;
            }
        }

        sprintf(h_inic, "%02i:%02i", hora_inic, min_inic);

        printf("Hora de llegada:\n");

        while(1)
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
                break;
            }
        }

        while(1)
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
            time_t now=time(NULL);

            struct tm user_time = {0}; //definimos estructura para poner años desde 2023, meses y días.
            user_time.tm_year = ano - 1900;
            user_time.tm_mon = mes - 1;
            user_time.tm_mday = dia;
            user_time.tm_hour = hora_inic;
            user_time.tm_min = min_inic;

            time_t user_time_seconds=mktime(&user_time);

            if(user_time_seconds<now)
            {
                printf("La fecha y la hora de inicio ingresadas es anterior a la fecha y hora actual.\n");
            }
            else
            {
                system("cls");
                printf("La fecha introducida es: %s\n", fecha);
                printf("La hora de inicio introducida es: %s\n", h_inic);
                printf("La hora de llegada es: %s\n", h_fin);
            }
        }
        else
        {
            printf("La hora de llegada es anterior a la hora de inicio.\n");

        }
    }
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

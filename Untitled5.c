#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char localidad[21];
} Estr_Rutas;

typedef struct{
    char siglas[4];
    char localidad[21];
} Estr_Localidad;

Estr_Rutas **ruta;
Estr_Localidad *localidad;

void cambiar_sigla_localidad(Estr_Rutas **, Estr_Localidad *, int *, int *, int *);
void leer_ruta(Estr_Rutas ***, int *, int *);
void leer_localidad(Estr_Localidad **, int *);

int main()
{
    int i,j,k,x,m;

    leer_localidad(&localidad, &k);
    leer_ruta(&ruta, &i, &j);

    for(x=0;x<i;x++)
	{
		for(m=0;m<12;m++)
		{
			printf("%s", ruta[x][m].localidad);
		}
		printf("\n");
	}

return(0);
}

void leer_ruta(Estr_Rutas ***ruta, int *i, int *max)
{
    FILE *fp;
    char vec[100], *token;
    int k=0;
    *i=0;
    *max=0;

    fp=fopen("rutas.txt", "r");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero rutas.txt.\n");
        return;
    }
    else
    {
        while(!feof(fp))
        {
            fgets(vec, 100, fp);

            if(strcmp(vec,"\0"))
            {
                *ruta=(Estr_Rutas **)realloc(*ruta,(*i+1)*sizeof(Estr_Rutas *));
                if (*ruta==NULL)
                {
                    printf("Error al asignar memoria.\n");
                    exit(1);
                }
                (*ruta)[*i]=NULL;

                token=strtok(vec, "-");
                k=0;
                while(token!=NULL)
                {
                    (*ruta)[*i]=(Estr_Rutas *)realloc((*ruta)[*i],(k+1)*sizeof(Estr_Rutas));
                    if((*ruta)[*i]==NULL)
                    {
                        printf("Error al asignar memoria.\n");
                        exit(1);
                    }

                    strcpy((*ruta)[*i][k].localidad, token);
                    k++;
                    token=strtok(NULL, "-");
                }
                token=strtok(vec, "\n");
                strcpy((*ruta)[*i][k].localidad, token);
                (*i)++;
                
                if(*max<k)
            	{
            		(*max)=k;
				}
               		

            }
        }
    }

    fclose(fp);

    printf("Se han cargado %i rutas, con %i ciudades como máximo.\n", *i, *max);
    system("PAUSE");

    return;
}

void leer_localidad(Estr_Localidad **localidad, int *i)
{
    FILE *fp;
    char vec[30], *token;
    *i=0;

    fp=fopen("localidades.txt", "r");

    if(fp==NULL)
    {
        printf("No se ha podido abrir el fichero localidades.txt.\n");
        return;
    }
    else
    {
        while(!feof(fp))
        {
            fgets(vec, 30, fp);

            if(strcmp(vec,"\0"))
            {
                *localidad=realloc(*localidad,((*i)+1)*sizeof(Estr_Localidad));
                if (*localidad==NULL)
                {
                    printf("Error al asignar memoria.\n");
                    exit(1);
                }
                token=strtok(vec,"-");
                strcpy((*localidad)[*i].siglas,token);
                token=strtok(NULL,"\n");
                strcpy((*localidad)[*i].localidad,token);

                (*i)++;
            }
        }
    }

    fclose(fp);

    printf("Se han cargado %i localidades.\n", *i);
    system("PAUSE");

    return;
}

void cambiar_sigla_localidad(Estr_Rutas **ruta, Estr_Localidad *localidad, int *i, int *j, int *k)
{
    int m, l, p;

    if((*i)<(*k))
    {
        for(m=0; m<(*i); m++)
        {
            for(l=0; l<(*j); l++)
            {
                if(strcmp(ruta[m][l].localidad, localidad[l].siglas)==0)
                {
                    strcpy(ruta[m][l].localidad, localidad[l].localidad);
                }
            }
        }
    }
    else
    {
        for(m=0; m<(*k); m++)
        {
            for(l=0; l<(*j); l++)
            {
                if(strcmp(ruta[m][l].localidad, localidad[l].siglas)==0)
                {
                    strcpy(ruta[m][l].localidad, localidad[l].localidad);
                }
            }
        }
    }

return;
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#define PELIS 3

/** \brief Agrega pelicula al archivo.
 * \param  eMovie *pelicula. Es el puntero de la estructura.
 * \param  FILE *pFile. Es el puntero de archivo.
 * \return no retorna valor algun (void)
 */

void Agregar(eMovie *pelicula, FILE *pFile)
{
    int estado;
    int auxDuracion, auxPuntaje;
    estado = 0;

    printf("\n\t\t\t** AGREGAR PELICULA **\n\n");

    printf("\nIngrese Titulo de la pelicula (30 letras max.):\n");
    fflush(stdin);
    scanf("%s", &pelicula->Titulo);
    strupr(pelicula->Titulo);

    while(strlen(pelicula->Titulo)>30)
    {
        printf("\nERROR! Debe ingresar un maximo de 30 letras: ");
        fflush(stdin);
        scanf("%s", &pelicula->Titulo);
        strupr(pelicula->Titulo);
    }

    printf("\nIngrese Genero de la pelicula (30 letras max.):\n");
    fflush(stdin);
    gets(pelicula->Genero);
    strupr(pelicula->Genero);

    while(strlen(pelicula->Genero)>30)
    {
        printf("\nERROR! Debe ingresar un maximo de 30 letras: ");
        fflush(stdin);
        scanf("%s", &pelicula->Genero);
        strupr(pelicula->Genero);
    }

    printf("\nIngrese Duracion de la pelicula (en minutos):\n");
    scanf("%d",&auxDuracion);
    while(auxDuracion<0 || auxDuracion>999)
    {
        printf("\nERROR! La duracion debe ser entre 0 y 999 minutos: ");
        scanf("%d",&auxDuracion);
        auxDuracion= Val_Entero(auxDuracion,1,999);
    }

    printf("\nIngrese Descripcion de la pelicula (100 letras max.):\n");
    fflush(stdin);
    scanf("%s", &pelicula->Descripcion);
    strupr(pelicula->Descripcion);
    while(strlen(pelicula->Descripcion)>30)
    {
        printf("\nERROR! Debe ingresar un maximo de 100 letras: ");
        fflush(stdin);
        scanf("%s", &pelicula->Descripcion);
        strupr(pelicula->Descripcion);
    }

    printf("\nIngrese Puntaje de la pelicula:\n");
    scanf("%d", &auxPuntaje);
    auxPuntaje= Val_Entero(auxPuntaje,1,10);
    while(auxPuntaje<0 || auxPuntaje>10)
    {
        printf("\nERROR! El puntaje debe ser entre 0 y 10: ");
        scanf("%d", &auxPuntaje);
        auxPuntaje= Val_Entero(auxPuntaje,1,10);
    }


    printf("\nIngrese Link de Imagen de la pelicula (80 letras max.):\n");
    fflush(stdin);
    gets(pelicula->LImagen);
    strupr(pelicula->LImagen);
    // validaString(pelicula->LImagen);

    estado = 1;

    fseek(pFile,0L,SEEK_END);

    fwrite(&pelicula, sizeof(eMovie), 1, pFile);

    if(estado == 0)
    {
        printf("\nERROR! No se pudo guardar la pelicula\n");
        system("pause");
    }
    else
    {
        printf("Pelicula guardada con suceso!\n");
        system("pause");
        system("cls");
    }
}

/** \brief Borra pelicula al archivo.
 * \param  Emovie *pelicula. Es el puntero de la estructura.
 * \param  FILE *pFile. Es el puntero de archivo.
 * \return no retorna valor algun (void)
 */

void Borrar(eMovie *pelicula, FILE *pFile)
{
    int estado;
    char auxBaja[256];

    estado = 0;

    printf("\n\t\t\t** BORRAR PELICULA **\n\n");

    printf("Ingrese el Titulo de la pelicula que desea borrar del archivo:\n");
    fflush(stdin);
    gets(auxBaja);
    rewind(pFile);

    while(!feof(pFile))
    {
        fread(&pelicula,sizeof(eMovie),1,pFile);

        if(strcmp(auxBaja, pelicula->Titulo)==0)
        {
            fseek(pFile,(-1)*sizeof(eMovie),SEEK_CUR);

            fwrite(&pelicula, sizeof(eMovie), 1, pFile);
            printf("\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nPuntaje: %d\nLink de Imagen: %s\n\n",pelicula->Titulo,pelicula->Genero,pelicula->Duracion,pelicula->Descripcion,pelicula->Puntaje,pelicula->LImagen);
            printf("\n\nPelicula borrada con suceso!\n");
            estado=1;
            system("pause");
            system("cls");
            return 0;
         }
    }
    if(estado==0)
    {
        printf("\nERROR! No se pudo borrar la pelicula.\n");
        system("pause");
        system("cls");
    }
}


/** \brief Valida la Cadena de caracteres. Funcion generica
 * \param  char opc[]. Lee cadena de caracteres
 * \return no retorna valor algun (void)
 */

void validaString(char opc[])
{
    char aux_cadena[256];
    fflush(stdin);
    gets(aux_cadena);

    while(strlen(aux_cadena) < 1 || strlen(aux_cadena) >81)
    {
        printf("\nERROR! Reingrese el nombre (max.: 80 letras): \n");
        gets(aux_cadena);
    }
        strcpy(opc,aux_cadena);
        return;

}

/** \brief Valida numeros enteros. Funcion generica.
 * \param  int opc. Entero de opcion ingresada.
 * \param  int desde. Valor limite minimo.
 * \param  int hasta. Valor limite maximo.
 * \return opc- Retorna valor de opcion.
 */

int Val_Entero(int opc, int desde, int hasta)
{
  while (opc< desde || opc > hasta)
  {
        printf("\nERROR! Reingrese el puntaje de la pelicula (0 - 10):\n");
        scanf("%d", &opc);
  }
  return opc;
}

/** \brief Modifica pelicula al archivo.
 * \param  eMovie *pelicula. Puntero a la estructura
 * \param  FILE *pFile . Puntero del archivo
 * \return no retorna valor algun (void)
 */

void Modificar(eMovie *pelicula, FILE *pFile)
{
    int estado;

    int Aux_EntModificar;
    char auxModifica[256];

    int opcion=0;

    estado=0;

    printf("\n\t\t\t** MODIFICAR PELICULA **\n\n");

    printf("Ingrese el Titulo de la pelicula que desea modificar:\n");
    fflush(stdin);
    gets(auxModifica);

    rewind(pFile);

    while(!feof(pFile))
    {
        fread(&pelicula,sizeof(eMovie),1,pFile);

        if(stricmp(auxModifica, pelicula->Titulo)==0)
        {

            printf("\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nPuntaje: %d\nLink de Imagen: %s\n\n",pelicula->Titulo,pelicula->Genero,pelicula->Duracion,pelicula->Descripcion,pelicula->Puntaje,pelicula->LImagen);

            while (opcion!=7)
            {
                printf("\t\t\t** MODIFICAR PELICULA\n\n");
                printf("1.Titulo a modificar\n2.Genero a modificar\n3.Duracion a modificar\n4.Descripcion a modificar\n5.Puntaje a modificar\n6.Link de imagen a modificar\n\nElija opcion:\n\n");
                scanf("%d", &opcion);

            switch(opcion)
            {
            case 1:

            system("cls");
            printf("Ingrese el titulo de la pelicula a modificar:\n");
            fflush(stdin);
            gets(auxModifica);
            validaString(auxModifica);
            strcpy(pelicula->Titulo, auxModifica);
            break;

            case 2:

            system("cls");
            printf("Ingrese el genero de la pelicula a modificar:\n");
            fflush(stdin);
            gets(auxModifica);
            validaString(auxModifica);
            strcpy(pelicula->Genero, auxModifica);
            break;

            case 3:
            system("cls");
            printf("Ingrese la duracion a modificar (en minutos):\n");
            scanf("%d", &Aux_EntModificar);
            pelicula->Duracion = Aux_EntModificar;
  //          Aux_EntModificar= Val_Entero(Aux_EntModificar,1,999);
            break;

            case 4: system("cls");
            printf("Ingrese la descripcion a modificar:\n");
            fflush(stdin);
            gets(auxModifica);
            validaString(auxModifica);
            strcpy(pelicula->Descripcion, auxModifica);
            break;

            case 5: system("cls");
            printf("Ingrese el puntaje a modificar:\n");
            scanf("%d", &Aux_EntModificar);
            pelicula->Puntaje = Aux_EntModificar;
            Aux_EntModificar= Val_Entero(Aux_EntModificar,1,999);
            break;

            case 6: system("cls");
            printf("Ingrese el link de Imagen a modificar:\n");
            fflush(stdin);
            gets(auxModifica);
            validaString(auxModifica);
            strcpy(pelicula->LImagen, auxModifica);
            break;

            case 7: system("cls");
                    printf("\nVOLVER AL MENU PRINCIPAL");
                    break;
            }
            }
            fseek(pFile,(-1)*sizeof(eMovie),SEEK_CUR);
            fwrite(&pelicula, sizeof(eMovie), 1, pFile);

            printf("\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nPuntaje: %d\nLink de Imagen: %s\n\n",pelicula->Titulo,pelicula->Genero,pelicula->Duracion,pelicula->Descripcion,pelicula->Puntaje,pelicula->LImagen);

            printf("\n\nPelicula modificada con suceso.\n");

            estado=1;
            system("pause");
            system("cls");
        }
    }
    if(estado==0)
    {
        printf("\nERROR! No se pudo modificar la pelicula.\n");
        system("pause");
        system("cls");
    }
}

/** \brief Genera pagina web al archivo
 * \param  eMovie *pelicula. Es el puntero de la estructura
 * \param  FILE *pFile .Es el puntero del archivo
 * \return no retorna valor algun (void)
 */

int Generar_PWeb(eMovie *pelicula,FILE *pFile)
{
    int i;

    FILE*f;

    printf("\n\t\t\t** GENERAR PAGINA WEB **\n\n");

    f=fopen("index.html","w");

    int retorno=-1;

    if(f == NULL)
     {
          printf("\nERROR! No se pudo abrir el archivo.\n");
     }
     else
     {

        fprintf(f,"\n<html>");
        fprintf(f,"\n<head>");
        fprintf(f,"\n<title>PELICULAS</title>");
        fprintf(f,"\n</head>");
        fprintf(f,"\n<body>");

        fprintf(f,"\n<h4> Titulo : </h4>");

         for(i=0; i<PELIS; i++)
         {
            if(pelicula->estado !=0)
            {
                fprintf(f,"\n<!-- Repetir cada pelicula -->");
                fprintf(f,"\n<article class='col-md-4 article-intro'>");
                fprintf(f,"\n<a href='#'>");
                fprintf(f,"\n<img class='img-responsive img-rounded' src='%s' alt=''>",pelicula->LImagen);
                fprintf(f,"\n</a>");
                fprintf(f,"\n<h3>");
                fprintf(f,"\n<a href='#'>%s</a>",pelicula->Titulo);
                fprintf(f,"\n</h3>");
                fprintf(f,"\n<ul>");
                fprintf(f,"\n<li>Género:%s</li>",pelicula->Genero);
                fprintf(f,"\n<li>Puntaje:%d</li>",pelicula->Puntaje);
                fprintf(f,"\n<li>Duración:%d</li>	",pelicula->Duracion);
                fprintf(f,"\n</ul>");
                fprintf(f,"\n<p>%s</p>",pelicula->Descripcion);
                fprintf(f," \n</article>");
                fprintf(f,"	\n<!-- Repetir cada pelicula -->");
            }
         }
        fprintf(f,"</body>");
        fprintf(f,"</html>");
        retorno=0;
    }
    fclose(f);
    printf("\nPAGINA CREADA CON SUCESO!\n");
    system("pause");
    return retorno;
}

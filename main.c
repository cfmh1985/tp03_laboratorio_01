/*
UTN FRA - TSP
PROGRAMACION/LABORATORIO 01
TP 03 - ESTRUCTURA MOVIE
PROGRAMADOR: CARLOS FELIPE M. HENRIQUES
EMAIL: CFMH1985@GMAIL.COM
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "funciones.h"
#define PELIS 3

int main()
{
    eMovie pelicula;
    char rta='n';

    FILE *pFile;

    int opcion;

    if((pFile = fopen("Pelicula.bin", "rb+"))== NULL)
        {
            if((pFile = fopen("pelicula.bin", "wb+"))==NULL)
        {
            printf("\nERROR! Archivo inexistente.\n");
            exit(1);
        }
        }
do
    {
        system("cls");
        system("color 1f");
        printf("\n\n\t*** TP 03 - Estructura Movie ***");
        printf("\n\n MENU PRINCIPAL");
        printf("\n\n [1] - Agregar pelicula");
        printf("\n\n [2] - Borrar pelicula");
        printf("\n\n [3] - Modificar pelicula");
        printf("\n\n [4] - Generar pagina Web");
        printf("\n\n\n [0] - SALIR");

        printf("\n\n\nElija una opcion (0 - 4): ");
        scanf("%d", &opcion);

        while(opcion<0 || opcion>4)
        {
            printf("\n\nERROR! Debe elegir una opcion valida (0 - 4): ");
            scanf("%d", &opcion);
        }

        switch (opcion)
        {
            case 1: system("cls");
                    Agregar(&pelicula, pFile);
                    break;

            case 2: system("cls");
                    Borrar(&pelicula, pFile);
                    break;

            case 3: system("cls");
                    Modificar(&pelicula, pFile);
                    break;

            case 4: system("cls");
                    Generar_PWeb(&pelicula, pFile);
                    break;

            case 0: system("cls");
                    printf("\n*** FIN DEL PROGRAMA ***\n");
                    rta='s';
                    system("pause");
                    break;
        }


    fclose(pFile);
    }while(rta=='n');
    return 0;
}

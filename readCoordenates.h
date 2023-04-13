// Libreria para leer las coordenadas del acelerometro del telefono
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float * readCoordenates () {
    // Variables para las coordenadas x, y, z
    float coordenates[2];
    float *ptrCoordenates = coordenates;

    // Leemos el archivo csv
    FILE *fp;
    float rx, ry;

    fp = fopen("coordenadas.csv", "r");
    if (fp == NULL)
    {
        printf("El archivo no se puede abrir \n");
        exit(1);
    }

    while (fscanf(fp, "%f, %f", &rx, &ry) != EOF)
    {
        coordenates[0] = rx;
        coordenates[1] = ry;
    }
    return (ptrCoordenates);
}
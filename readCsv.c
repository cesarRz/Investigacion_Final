
// C program for the above approach
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Driver Code
int main()
{

    // Variables para las coordenadas x, y, z
    float x = 0;
    float y = 0;

    // Leemos el archivo csv
    FILE *fp;
    float rx, ry;

    while (true)
    {
        fp = fopen("coordenadas.csv", "r");
        if (fp == NULL)
        {
            printf("El archivo no se puede abrir \n");
            exit(1);
        }

        while (fscanf(fp, "%f, %f", &rx, &ry) != EOF)
        {
            x = rx;
            y = ry;
        }
        printf("\nX: %f\n", x);
        printf("\nY: %f\n", y);
        fclose(fp);
    }

    return 0;
}
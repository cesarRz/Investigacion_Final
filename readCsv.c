
// C program for the above approach
#include <stdio.h>
#include "readCoordenates.h"

// Driver Code
int main()
{

    float * coordenates = readCoordenates();
    printf("\nX: %f\n", coordenates[0]);
    printf("\nY: %f", coordenates[1]);
    return 0;
}
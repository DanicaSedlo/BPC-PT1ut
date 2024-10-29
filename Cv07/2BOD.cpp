#include <stdio.h>
#include <math.h>
#include "2BOD.h"

int indexNejblizsi(int velikost, int (*poleBodu)[2], int referencniX, int referencniY) 
{
    int x = 0;
    double minVzdalenost = sqrt(pow(poleBodu[0][0] - referencniX, 2) + pow(poleBodu[0][1] - referencniY, 2));

    for (int i = 1; i < velikost; i++) 
    {
        double vzdalenost = sqrt(pow(poleBodu[i][0] - referencniX, 2) + pow(poleBodu[i][1] - referencniY, 2));
        if (vzdalenost < minVzdalenost) 
        {
            minVzdalenost = vzdalenost;
            x = i;
        }
    }

    return x;
}

double prumernaVzdalenost(int velikost, int (*poleBodu)[2], int referencniX, int referencniY) 
{
    double x = 0;

    for (int i = 0; i < velikost; i++) 
    {
        x += sqrt(pow(poleBodu[i][0] - referencniX, 2) + pow(poleBodu[i][1] - referencniY, 2));
    }

    return x / velikost;
}

int BodyVKvadrantu(int velikost, int (*poleBodu)[2], int referencniX, int referencniY, int kvadrant) 
{
    int PB = 0;

    for (int i = 0; i < velikost; i++) 
    {
        int x = poleBodu[i][0] - referencniX;
        int y = poleBodu[i][1] - referencniY;

        int jeVKvadrantu = 0;
        if (kvadrant == 1 && x > 0 && y > 0) 
        {
            jeVKvadrantu = 1;
        }
        else if (kvadrant == 2 && x < 0 && y > 0) 
        {
            jeVKvadrantu = 1;
        }
        else if (kvadrant == 3 && x < 0 && y < 0) 
        {
            jeVKvadrantu = 1;
        }
        else if (kvadrant == 4 && x > 0 && y < 0) 
        {
            jeVKvadrantu = 1;
        }

        if (jeVKvadrantu) 
        {
            printf("(%d, %d) lezi v kvadrantu %d.\n", poleBodu[i][0], poleBodu[i][1], kvadrant);
            PB++;
        }
    }
    return PB;
}

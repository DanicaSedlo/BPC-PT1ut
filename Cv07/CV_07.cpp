// CV07.cpp: Definuje vstupní bod pro aplikaci.
//

#include <stdio.h>
#include <math.h>
#include "2BOD.h"

#define POCET_BODU 10

int main() {

    int body[POCET_BODU][2] = 
    {
        {5, 10},
        {-14, 2},
        {45, 4},
        {-9, 8},
        {58, -3},
        {47, 5},
        {-18, -86},
        {75, 7},
        {-25, 51},
        {17, 98}
    };

    int RefX;
    int RefY;
    int Kvadrant;

    printf("Zadej souradnice referencniho bodu oddelene mezerou (X Y): ");
    scanf("%d %d", &RefX, &RefY);

    
    printf("Zadejte cislo kvadrantu (1-4): ");
    scanf("%d", &Kvadrant);

    int index=indexNejblizsi(POCET_BODU, body, RefX, RefY);
    double prumer=prumernaVzdalenost(POCET_BODU, body, RefX, RefY);


    printf("Nejblizsi bod je: (%d, %d)\n", body[index][0], body[index][1]);
    printf("Prumerna vzdalenost k referencnimu bodu je: %.2f\n", prumer);


    int PocetBoduKvadrantu = BodyVKvadrantu(POCET_BODU, body, RefX, RefY, Kvadrant);


    if (PocetBoduKvadrantu == 0) 
    {
        printf("v tomto kvadrantu zadne body nelezi  %d.\n", Kvadrant);
    }
    return 0;
}

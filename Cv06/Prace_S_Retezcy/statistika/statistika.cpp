// statistika.cpp: Definuje vstupní bod pro aplikaci.
//

#include "statistika.h"

using namespace std;

int JednotliveDelky[100];
    
int pocet_pismen(char* a) {
    int pocet = 0;

    while (*a) 
    {
        if (isalpha(*a)) {

            pocet++;
        }

        a++;
    }

    return pocet;
}

int pocet_cisel(char* a) {
    int pocet = 0;

    while (*a)
    {
        if (isdigit(*a)) {
            pocet++;
        }

        a++;
    }
    return pocet;
}

int DelkySlov(char* text, int* delky) 
{
    int i = 0;
    int delka = 0;

    while (*text) {
        if (isalpha(*text)) {
            delka++;
        }
        else if (delka > 0) {

            delky[i++] = delka;
            delka = 0;

            if (i >= 100) {

                break;
            }
        }
        text++;
    }

    if (delka > 0 && i < 100) {
        delky[i++] = delka;
    }

    return i;
}



int main()
{
	char text[] = "Toto jsou 2 vzorove vety, ktere budou zpracovavany Vasemi funkcemi.Auto Hyundai ix35 ma pres 120 konskych sil.";

    printf("Toto jsou 2 vzorove vety, ktere budou zpracovavany Vasemi funkcemi.Auto Hyundai ix35 ma pres 120 konskych sil.          ");
    printf("Pocet pismen: %d \n", pocet_pismen(text));
    printf("Pocet cisel: %d\n", pocet_cisel(text));
    printf("Pocet slov: %d\n",DelkySlov(text,JednotliveDelky));
    

    int PocetSlov = DelkySlov(text, JednotliveDelky);

    for (int i = 0; i < PocetSlov; i++) 
    {
        printf("%d", JednotliveDelky[i]);
        
        if (i < PocetSlov - 1) {
            printf(" , ");
        }
    }

	return 0;
}

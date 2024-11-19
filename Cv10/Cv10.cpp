// CV10.cpp : Defines the entry point for the application.
//

#include "CV10.h"
#include <stdio.h>
#include <ctype.h>

int main()
{

	FILE* vstup, * vystup;
	char znak;
	int pocetCisel = 0;
	int pocetPismen = 0;
	int pocetSlov = 0;
	int pocetVet = 0;

	const char* VstupniSouborCesta = "..\\..\\..\\vstup.txt";
	const char* VystupniSouborCesta = "..\\..\\..\\vystup.txt";

	if (fopen_s(&vstup, VstupniSouborCesta, "r") != 0) {

		printf("Nelze otevrit vstupni soubor");
		return -1;

	}

	if (fopen_s(&vystup, VystupniSouborCesta, "w") != 0) {

		printf("Nelze otevrit vystupni soubor");
		return -1;

	}

	while ((znak = fgetc(vstup)) != EOF) {
		if (isdigit(znak)) {
			pocetCisel++;
		}
		else if (isalpha(znak)) {
			pocetPismen++;
		}
		else if (znak == 32 or znak == 10) {
			pocetSlov++;
		}
		else if (znak == 46) {
			pocetVet++;
		}
	}

	fprintf(vystup, "Pocet pismen: %d\n", pocetPismen);
	fprintf(vystup, "Pocet cisel: %d\n", pocetCisel);
	fprintf(vystup, "Pocet slov: %d\n", pocetSlov);
	fprintf(vystup, "Pocet vet: %d\n", pocetVet);

	fclose(vystup);
	fclose(vstup);

	printf("Pocet pismen: %d\n", pocetPismen);
	printf("Pocet cisel: %d\n", pocetCisel);
	printf("Pocet slov: %d\n", pocetSlov);
	printf("Pocet vet: %d\n", pocetVet);



	return 0;
}

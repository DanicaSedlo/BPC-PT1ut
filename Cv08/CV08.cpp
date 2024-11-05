// CV08.cpp : Defines the entry point for the application.
//

#include "CV08.h"
#include "sedlacek.h"

using namespace std;

int main()
{
	double zacatek1, zacatek2, konec1, konec2, vysl_zacatek, vysl_konec;

	printf("Zadejte pocatek intervalu A:");
	scanf_s("%lf", &zacatek1);
	printf("Zadejte konec intervalu A:");
	scanf_s("%lf", &konec1);
	printf("Zadejte pocatek intervalu B:");
	scanf_s("%lf", &zacatek2);
	printf("Zadejte konec intervalu B:");
	scanf_s("%lf", &konec2);

	int result = prunik(zacatek1, konec1, zacatek2, konec2, &vysl_zacatek, &vysl_konec);

	if (result == 0) 
	{
		printf("Nema prunik");
	}
	else if (result == 1) 
	{
		if (vysl_zacatek > vysl_konec) {
			printf("Prunik: %.1lf, %.1lf", vysl_konec, vysl_zacatek);
		}
		else 
		{
			printf("Prunik: %.1lf, %.1lf", vysl_zacatek, vysl_konec);
		}
	}
	return 0;
}

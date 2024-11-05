// sedlacek.cpp : Defines the entry point for the application.
//

#include "sedlacek.h"

using namespace std;

int prunik(double zacatek1, double konec1, double zacatek2, double konec2, double* vysl_zacatek, double* vysl_konec)
{

	if (!(zacatek1 <= konec1)) 
	{
		double xzacatek1 = zacatek1;
		double xkonec1 = konec1;

		if (xzacatek1 >= xkonec1) 
		{
			zacatek1 = xkonec1;
			konec1 = xzacatek1;
		}

	}

	if (!(zacatek2 <= konec2)) 
	{
		double xzacatek2 = zacatek2;
		double xkonec2 = konec2;

		if (xzacatek2 >= xkonec2) 
		{
			zacatek2 = xkonec2;
			konec2 = xzacatek2;
		}

	}

	*vysl_zacatek = (zacatek1 > zacatek2) ? zacatek1 : zacatek2;
	*vysl_konec = (konec1 < konec2) ? konec1 : konec2;

	if (*vysl_zacatek > *vysl_konec) 
	{
		return 0;
	}
	else 
	{
		return 1;
	}

}

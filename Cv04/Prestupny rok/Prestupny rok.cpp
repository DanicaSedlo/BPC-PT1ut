// Prestupny rok.cpp: Definuje vstupní bod pro aplikaci.
//

#include "Prestupny rok.h"

using namespace std;

int prestupnyRok(int rok)
{
	int prestupnyRok(int rok);
	{
		if ((rok % 4 == 0 && rok % 100 != 0) || (rok % 400 == 0))
		{
			printf("%d", rok);
			
			printf(" 1 \n");
		}
		else
		{
			printf("%d", rok);
			
			printf(" 0 \n");
		}
		return 0;

	}

}
int main()
{
	prestupnyRok(1000);
	prestupnyRok(2000);
	prestupnyRok(2002);
	prestupnyRok(2012);
	prestupnyRok(2022);
	prestupnyRok(2200);
	return 0;
}

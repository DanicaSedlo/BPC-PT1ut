// CV09.cpp : Defines the entry point for the application.
//

#include "CV09.h"
#include "VectorMath.h"

using namespace std;

int main()
{
	struct vector3d u, v, w;
	enum typOperace op;


	printf("Zadejte vektor u ve formatu s carkami x,y,z: ");
	scanf_s("%lf,%lf,%lf", &u.x, &u.y, &u.z);

	printf("Zadejte vektor v ve formatu s carkami x,y,z: ");
	scanf_s("%lf,%lf,%lf", &v.x, &v.y, &v.z);

	printf("Zadejte operaci (1 = soucet, 2 = vektorovy soucin, 3 = skalarni soucin): ");
	scanf_s("%d", &op);

	if (op == 3) 
	{
		tiskSkalar(skalSoucin(u, v));
	}
	else if (op == 1 or op == 2 or op == 3) 
	{
		tisk(operace(u, v, op));
	}
	else {
		printf("Neplatna operace!!!");
		return 0;
	}

	return 0;
}
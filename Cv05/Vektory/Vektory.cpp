// Vektory.cpp: Definuje vstupní bod pro aplikaci.
//

#include "Vektory.h"
#include "vektorovySoucin.h"

using namespace std;
double A[3];
double B[3];
double C[3] = {0,0,0};

void vektorovySoucet(double a[3], double b[3], double c[3])
{
	c[0] = a[0] + b[0];
	c[1] = a[1] + b[1];
	c[2] = a[2] + b[2];

	return;
}

double velikost(double a[3])
{
	double x;
	x = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	return x;
}

double skalarniSoucin(double a[3], double b[3])
{
	double x;
	x = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
	return x;
}

int main()
{
	//Hodnoty pro vektor A 
	printf("Vektor A (3 hodnoty oddelene carkou): ");
	scanf_s("%lf,%lf,%lf,", &A[0], &A[1], &A[2]);


	//Hodnoty pro vektor B
	printf("Vektor B (3 hodnoty oddelene carkou): ");
	scanf_s("%lf,%lf,%lf,", &B[0], &B[1], &B[2]);

	vektorovySoucet(A, B, C);
	printf("Soucet A+B : %lf %lf %lf", C[0], C[1], C[2]);
	printf("\n");

	printf("Velikost vektoru A: %lf", velikost(A));

	printf("\n");
	printf("Skalarni soucin AB: %lf", skalarniSoucin(A, B));
	printf("\n");
	
	//CV 5 - Bod 2 
	vektorovySoucin(A,B,C);
	printf("Vektorovy Soucin A*B : %lf %lf %lf", C[0], C[1], C[2]);

	return 0;
}

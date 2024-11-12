#pragma once
#include <iostream>
enum typOperace { soucet = 1, vektorovySoucin, skalarniSoucin };
struct vector3d
{
	double x;
	double y;
	double z;
};
struct vector3d operace(struct vector3d u, struct vector3d v, enum typOperace typ);
double skalSoucin(struct vector3d u, struct vector3d v);
void tisk(struct vector3d u);
void tiskSkalar(double skalW);
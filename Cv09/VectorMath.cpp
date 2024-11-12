#include "VectorMath.h"
#include <math.h>

struct vector3d operace(struct vector3d u, struct vector3d v, enum typOperace typ) {

	struct vector3d w;

	if (typ == 1) {
		w.x = u.x + v.x;
		w.y = u.y + v.y;
		w.z = u.z + v.z;
	}
	else if (typ == 3) {
		w.x = (u.y * v.z - u.z * v.y);
		w.y = (u.z * v.x - u.x * v.z);
		w.z = (u.x * v.y - u.y * v.x);
	}
	else if (typ == 2) {
		w.x = u.x - v.x;
		w.y = u.y - v.y;
		w.z = u.z - v.z;

	}

	return w;
}

double skalSoucin(struct vector3d u, struct vector3d v) {

	double skalW;

	skalW = (u.x * v.x) + (u.y * v.y) + (u.z * v.z);

	return skalW;
}

void tiskSkalar(double skalW) {

	printf("w = %.3lf", skalW);

}

void tisk(struct vector3d w) {

	double sizeW;

	sizeW = sqrt(w.x * w.x + w.y * w.y + w.z * w.z);

	printf("w = (%.3lf, %.3lf, %.3lf)\n", w.x, w.y, w.z);
	printf("|w| = %.3lf", sizeW);

}

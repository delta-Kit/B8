#include <stdio.h>

#define dt		0.05
#define maxstep 100000
#define m		1.0
#define k		1.0
#define gamma	0.0

double fx(double x, double v) {
	return v;
}

double fv(double x, double v) {
	return -gamma / m * v - k / m * x;
}

double X(double preX, double preV, double h) {
	return preX + fx(preX, preV) * h;
}

double V(double preX, double preV, double h) {
	return preV + fv(preX, preV) * h;
}

int main() {
	double x = 1.0, v = 0.0, preX = 0.0, preV = 0.0, x1, v1, x2, v2, x3, v3, x4, v4;
	for (int step = 0; step < maxstep; step++) {
		printf("%f %f %f\n", dt * step, x, v);
		preX = x;
		preV = v;
		x1 = dt * fx(X(preX, preV, 0), V(preX, preV, 0));
		x2 = dt * fx(X(preX, preV, 0) + x1 / 2, V(X(preX, preV, 0) + x1 / 2, preV, dt / 2));
		x3 = dt * fx(X(preX, preV, 0) + x2 / 2, V(X(preX, preV, 0) + x2 / 2, preV, dt / 2));
		x4 = dt * fx(X(preX, preV, 0) + x3, V(X(preX, preV, 0) + x3, preV, dt));
		v1 = dt * fv(X(preX, preV, 0), V(preX, preV, 0));
		v2 = dt * fv(X(preX, V(preX, preV, 0) + v1 / 2, dt / 2), V(preX, preV, 0) + v1 / 2);
		v3 = dt * fv(X(preX, V(preX, preV, 0) + v2 / 2, dt / 2), V(preX, preV, 0) + v2 / 2);
		v4 = dt * fv(X(preX, V(preX, preV, 0) + v3, dt), V(preX, preV, 0) + v3);
		x = preX + (x1 + 2 * x2 + 2 * x3 + x4) / 6;
		v = preV + (v1 + 2 * v2 + 2 * v3 + v4) / 6;
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double pi;

double rnd() {
	return ((double)rand()) / (((double)RAND_MAX) + 1);
}

double cr(double x1, double y1, double x2, double y2) {
	return x1 * y2 - x2 * y1;
}

double x[50], y[50];
double cross(int i, int j, int k) {
	return cr(x[k] - x[i], y[k] - y[i], x[j] - x[i], y[j] - y[i]);
}

int main() {
	freopen("intersection.in", "r", stdin);
	freopen("intersection.out", "w", stdout);

	int i, n, xc, yc, r;
	pi = acos(-1.);
	long long in = 0, ar = 0;
	srand(time(NULL));
	scanf("%d %d %d", &xc, &yc, &r);
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%lf %lf", &x[i], &y[i]);
	while(((double)clock()) / CLOCKS_PER_SEC <= 1.9) {
		double ang = rnd() * 2 * pi, ra = rnd() * r;
		double xx = ra * cos(ang) + xc, yy = ra * sin(ang) + yc;
		x[n] = xx; y[n] = yy;
		int p = (cross(n - 1, 0, n) >= 0);
		for(i = 0; i < n - 1; i++)
			if((cross(i, i + 1, n) >= 0) != p)
				break;
		if(i == n - 1) in++;
		ar++;
	}
	double all = pi * (double) r * r;
	printf("%.10f\n", ((double)in / ar) * all);
	return 0;
}

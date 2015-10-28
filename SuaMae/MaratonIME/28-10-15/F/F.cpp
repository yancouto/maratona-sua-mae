#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653589793238462643;
typedef pair<double, int> pii;
#define d first
#define i second


double h; int r;
double dist(double x1, double x2) {
	double d = sqrt((x1 - x2) * (x1 - x2) + h * h);
	d = min(d, sqrt((x1 + 2. * pi * r - x2) * (x1 + 2. * pi * r - x2) + h * h));
	d = min(d, sqrt((x1 - 2. * pi * r - x2) * (x1 - 2. * pi * r - x2) + h * h));
	return d;
}

pii x[3][1003];
int n;
double mnf(int g) {
	int i, j;
	double best = 1/0.;
	for(i = 0; i < n; i++) {
		double tot = 0;
		for(j = 0; j < n; j++) {
			printf("shift %d -> %.15lf\n", i, dist(x[g][j].d, x[g + 1][(i + j) % n].d));
			tot += dist(x[g][j].d, x[g + 1][(i + j) % n].d);
		}
		best = min(best, tot);
		printf("tot %.15f\n", tot);
		putchar('\n');
	}
	return best;
}

int main() {
	int i, j; double al;
	scanf("%d %d %lf", &n, &r, &h);
	h /= 2;
	for(j = 0; j < 3; j++) {
		for(i = 0; i < n; i++) {
			scanf("%lf", &al);
			if(al < 0) al += 2. * pi;
			x[j][i] = pii(al * r, i);
			printf("%d -> %.15f\n", j, x[j][i].d);
		}
		putchar('\n');
		sort(x[j], x[j] + n);
	}
	printf("%.15f\n", mnf(0) + mnf(1));
}

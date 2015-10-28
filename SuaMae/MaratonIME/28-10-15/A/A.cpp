#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

double sq(double x) { return x*x; }

double dist(pii a, pii b) { return sqrt(sq(a.first - b.first) + sq(a.second - b.second)); }

int main() {
	pii a, b, c;
	freopen("bomb.in", "r", stdin);
	freopen("bomb.out", "w", stdout);
	scanf("%d%d", &a.first, &a.second);
	scanf("%d%d", &b.first, &b.second);
	scanf("%d%d", &c.first, &c.second);
	double dab = dist(a, b), dac = dist(a, c), dbc = dist(b, c);
	double ra = (dab - dbc + dac) / 2, rb = dab - ra, rc = dbc - rb;
	printf("%.10lf\n%.10lf\n%.10lf\n", ra, rb, rc);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef long double dd;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const dd eps = 10e-10;

inline dd dist(dd xa, dd ya, dd xb, dd yb) {
	return sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
}
inline dd dabs(dd x) { if(x < 0) return -x; return x; }

dd per, area, pxa, pya, pxb, pyb;
dd xa, ya, xb, yb, xc, yc;
dd theta, alpha, beta, AB, AC, BC, dmax;

dd newton(dd sen) {
	dd x = per;
	while(42) {
		dd f = x * (per - x) * sen - area / 2.0;
		dd fl = (-2.0 * x * sen) + sen * per;
		dd xn = x - f/fl;
		if(dabs(xn - x) <= 10e-11) break;
		x = xn;
	}
	return x;
}

bool check(dd theta, dd sa, dd sb, dd x, dd y, dd x1, dd y1, dd x2, dd y2) {
	dd sen = sin(theta) / 2.0;
	dd da = newton(sen);
	dd db = per - da;
	//printf("da %.15Lf sa %.15Lf db %.15Lf e sb %.15Lf\n", da, sa, db, sb);
	if(da > sa + eps || db > sb + eps) return false;
	dd norma = sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
	pxa = da * (x1 - x) / norma + x;
	pya = da * (y1 - y) / norma + y; 
	norma = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
	pxb = db * (x2 - x) / norma + x;
	pyb = db * (y2 - y) / norma + y; 
	return true;
}

int main() {
	scanf("%Lf %Lf %Lf %Lf %Lf %Lf", &xa, &ya, &xb, &yb, &xc, &yc);
	AB = dist(xa, ya, xb, yb);
	AC = dist(xa, ya, xc, yc);
	BC = dist(xb, yb, xc, yc);
	per = AB + AC + BC; per /= 2.0;
	theta = (AC * AC + BC * BC - AB * AB) / (2.0 * AC * BC); //oposto a AB
	alpha = (AB * AB + AC * AC - BC * BC) / (2.0 * AB * AC); //oposto a BC
	beta  = (AB * AB + BC * BC - AC * AC) / (2.0 * AB * BC); //oposto a AC
	theta = acos(theta); alpha = acos(alpha); beta  = acos(beta );
	area = (xa * yb + ya * xc + xb * yc - xc * yb - yc * xa - xb * ya) / 2.0;
	area = dabs(area);
	//Checa AC e BC
	if(check(theta, AC, BC, xc, yc, xa, ya, xb, yb)) 
		printf("YES\n%.15Lf %.15Lf\n%.15Lf %.15Lf\n", pxa, pya, pxb, pyb);
	//Checa AB e AC 
	else if(check(alpha, AB, AC, xa, ya, xb, yb, xc, yc)) 
		printf("YES\n%.15Lf %.15Lf\n%.15Lf %.15Lf\n", pxa, pya, pxb, pyb);
	//Checa AB e BC
	else if(check(beta, AB, BC, xb, yb, xa, ya, xc, yc))
		printf("YES\n%.15lf %.15lf\n%.15lf %.15lf\n", pxa, pya, pxb, pyb);
	else puts("NO");
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const double eps = 10e-13;

inline double dist(double xa, double ya, double xb, double yb) {
	return sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
}

double per, area, pxa, pya, pxb, pyb;
double xa, ya, xb, yb, xc, yc;
double theta, alpha, beta, AB, AC, BC;

bool check(double theta, double sa, double sb, double x, double y, double x1, double y1, double x2, double y2) {
	double ang = sin(theta);
	double delta = per * per * ang * ang - 4.0 * ang * area;
	double da = (per * ang + sqrt(delta)) / (2.0 * ang);
	double db = per - da;
	if(da > sa + eps || db > sb + eps) return false;
	double norma = sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
	pxa = da * (x1 - x) / norma + x;
	pya = da * (y1 - y) / norma + y; 
	norma = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
	pxb = db * (x2 - x) / norma + x;
	pyb = db * (y2 - y) / norma + y; 
	return true;
}

int main() {
	scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &xb, &yb, &xc, &yc);
	AB = dist(xa, ya, xb, yb);
	AC = dist(xa, ya, xc, yc);
	BC = dist(xb, yb, xc, yc);
	per = AB + AC + BC; per /= 2.0;
	theta = (AC * AC + BC * BC - AB * AB) / (2.0 * AC * BC); //oposto a AB
	alpha = (AB * AB + AC * AC - BC * BC) / (2.0 * AB * AC); //oposto a BC
	beta  = (AB * AB + BC * BC - AC * AC) / (2.0 * AB * BC); //oposto a AC
	theta = acos(theta); alpha = acos(alpha); beta  = acos(beta );
	area = (xa * yb + ya * xc + xb * yc - xc * yb - yc * xa - xb * ya) / 2.0;
	if(area < 0.0 + eps) area *= -1;
	//Checa AC e BC
	if(check(theta, AC, BC, xc, yc, xa, ya, xb, yb)) 
		printf("YES\n%.15f %.15f\n%.15f %.15f\n", pxa, pya, pxb, pyb);
	//Checa AB e AC 
	else if(check(alpha, AB, AC, xa, ya, xb, yb, xc, yc)) 
		printf("YES\n%.15f %.15f\n%.15f %.15f\n", pxa, pya, pxb, pyb);
	//Checa AB e BC
	else if(check(beta, AB, BC, xb, yb, xa, ya, xc, yc))
		printf("YES\n%.15f %.15f\n%.15f %.15f\n", pxa, pya, pxb, pyb);
	else puts("NO");
	return 0;
}

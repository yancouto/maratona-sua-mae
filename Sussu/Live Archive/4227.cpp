#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<double, double> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }


// area de calota 2.pi.R.h (h altura)
// volume de calota pi.h/6 * (3r^2 + h^2)

#include <cmath>
#define temp template<typename num>
#define ptn point<num>
temp struct point {
	num x, y;
	ptn() {}
	ptn(num a, num b) : x(a), y(b) {}
	ptn operator + (ptn o) const { return ptn(x + o.x, y + o.y); }
	ptn operator - (ptn o) const { return ptn(x - o.x, y - o.y); }
	num operator * (ptn o) const { return x * o.x + y * o.y; }
	num operator ^ (ptn o) const { return x * o.y - y * o.x; }
	ptn operator * (num i) const { return ptn(x * i, y * i); }
	ptn operator / (num i) const { return ptn(x / i, y / i); }
	bool operator != (ptn o) const { return (x != o.x || y != o.y); }
	point<double> rotate(double deg) {
		double cs = cos(deg), sn = sin(deg);
		return point<double>(x*cs - y*sn, x*sn + y*cs);
	}
	num dist_sqr(ptn o) const { return (*this - o) * (*this - o); }
	bool operator < (ptn o) const { return x < o.x || (x == o.x && y < o.y); }
};
typedef point<int> pti;
typedef point<double> ptd;
temp inline num cross(ptn a, ptn b, ptn c) { return (c - a) ^ (b - a); }

temp struct line {
	num a, b, c;
	line() {}
	line(num aa, num bb, num cc) : a(aa), b(bb), c(cc) {}
	line(ptn s, ptn e) : a(e.y - s.y), b(s.x - e.x), c(a*s.x + b*s.y) {}
	line pass(ptn p) { return line(a, b, a*p.x + b*p.y); }
	bool parallel(const line &o) const { return a * o.b - o.a * b == 0; }
	point<double> inter(line o) {
		double d = a * o.b - o.a * b;
		if(d == 0) return point<double>(0, 0); // fudeu
		return point<double>((o.b * c - b * o.c)/d, (a * o.c - o.a * c)/d);
	}
};
typedef line<int> lni;
typedef line<double> lnd;

double area(ptd a, ptd b, ptd c){
	return abs(cross(c, a, b)/2.);
}

double dist(ptd a, ptd b){
	return sqrt(a.dist_sqr(b));
}

double perim(ptd a, ptd b, ptd c){
	return dist(a, b) + dist(a, c) + dist(b, c);
}

pii round(double a, double b){
	int aa =(a*1000.+0.5);
	int bb = (b*1000. + 0.5);
	return pii(aa/1000.0, bb/1000.);
}

int main (){
	ptd p1, p2, p3, p4, z;
	z.x = 0;
	z.y = 0;
	while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y, &p4.x, &p4.y) != EOF && (p1 != z || p2 != z || p3 != z || p4 != z)){
		lnd d1 = line<double>(p3, p1);
		lnd d2 = line<double>(p4, p2);
		ptd it = d1.inter(d2);
		pii ans[5];
		ans[0] = round(area(p1, p2, it), perim(p1, p2, it)); 
		ans[1] = round(area(p1, p4, it), perim(p1, p4, it)); 
		ans[2] = round(area(p2, p3, it), perim(p2, p3, it)); 
		ans[3] = round(area(p3, p4, it), perim(p3, p4, it)); 
		sort(ans, ans+4);
		for(int a=3;a>=0;a--){
			if(a != 3)
				putchar(' ');
			printf("%.3f %.3f", ans[a].fst, ans[a].snd);
		}
		putchar('\n');

	}
}

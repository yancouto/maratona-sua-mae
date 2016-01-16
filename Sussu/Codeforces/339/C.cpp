#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

#define PI (double)acos(-1)

const int MAXN = 100010;

int n;

double r[MAXN], mai, men;

struct poi{
	ll i, j;
} p[MAXN], c;

#define num ll

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
	point<double> rotate(double deg) {
		double cs = cos(deg), sn = sin(deg);
		return point<double>(x*cs - y*sn, x*sn + y*cs);
	}
	num distSqr(ptn o) const { return (*this - o) * (*this - o); }
	bool operator < (ptn o) const { return x < o.x || (x == o.x && y < o.y); }
};
temp inline num cross(ptn a, ptn b, ptn c) { return (c - a) ^ (b - a); }
temp inline bool betweenSeg(ptn a, ptn b, ptn c) { return cross(a, b, c) == 0 && ((b - c) * (a - c) <= 0); }
temp double distSegSqr(ptn a, ptn b, ptn c) {
	if((b - a) * (c - b) > 0) return b.distSqr(c);
	if((a - b) * (c - a) > 0) return a.distSqr(c);
	double d = (b - a) ^ (c - a);
	return d * d / ((b - a) * (b - a));
}
temp bool intersectSeg(ptn a, ptn b, ptn c, ptn d) {
	if(betweenSeg(a, b, c) || betweenSeg(a, b, d) || betweenSeg(c, d, a) || betweenSeg(c, d, b)) return true;
	if(((cross(a, b, c) > 0) ^ (cross(a, b, d) > 0)) && ((cross(c, d, a) > 0) ^ (cross(c, d, b) > 0))) return true;
	return false;
}

temp struct line {
	num a, b, c;
	line() {}
	line(num aa, num bb, num cc) : a(aa), b(bb), c(cc) {}
	line(ptn s, ptn e) : a(e.y - s.y), b(s.x - e.x), c(a*s.x + b*s.y) {}
	line pass(ptn p) { return line(a, b, a*p.x + b*p.y); }
	bool parallel(const line &o) const { return a * o.b - o.a * b == 0; }
	point<double> inter(line o) {
		double d = a * o.b - o.a * b;
		if(d == 0) return point<double>(0, 0); //fudeu
		return point<double>((o.b * c - b * o.c)/d, (a * o.c - o.a * c)/d);
	}
};
typedef point<int> pti;
typedef point<double> ptd;
typedef line<int> lni;
typedef line<double> lnd;

int main (){
	scanf("%d", &n);
	cin >> c.i >> c.j;
	mai = -1., men  = -1.;
	for(int a=0;a<n;a++){
		cin >> p[a].i >> p[a].j;
		r[a] = sqrt((p[a].i - c.i)*(p[a].i - c.i) + (p[a].j - c.j)*(p[a].j - c.j));
		mai = max(mai,r[a]);
		if(men == -1.) men = r[a];
		men = min(men,r[a]);
		if(a!=0){
			men = min(men,sqrt(distSegSqr(ptn(p[a].i,p[a].j),ptn(p[a-1].i,p[a-1].j),ptn(c.i,c.j))));
			mai = max(mai,sqrt(distSegSqr(ptn(p[a].i,p[a].j),ptn(p[a-1].i,p[a-1].j),ptn(c.i,c.j))));
		}
	}
	men = min(men,sqrt(distSegSqr(ptn(p[0].i,p[0].j),ptn(p[n-1].i,p[n-1].j),ptn(c.i,c.j))));
	mai = max(mai,sqrt(distSegSqr(ptn(p[0].i,p[0].j),ptn(p[n-1].i,p[n-1].j),ptn(c.i,c.j))));
	//cout << men << " " << mai << "\n";
	printf("%.25f", PI*(((mai*mai)-(men*men))));
	
}
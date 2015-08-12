#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

template<typename num> struct point {
	num x, y;
	point() {}
	point(num a, num b) : x(a), y(b) {}
	point operator + (point o) const { return point(x + o.x, y + o.y); }
	point operator - (point o) const { return point(x - o.x, y - o.y); }
	num operator * (point o) const { return x * o.x + y * o.y; }
	num operator ^ (point o) const { return x * o.y - y * o.x; }
	point operator * (num i) const { return point(x * i, y * i); }
	point operator / (num i) const { return point(x / i, y / i); }
	point<double> rotate(double deg) {
		double cs = cos(deg), sn = sin(deg);
		return point<double>(x*cs - y*sn, x*sn + y*cs);
	}
	num distSqr(point o) const { return (*this - o) * (*this - o); }
	bool operator < (point o) const { return (x + y) < (o.x + o.y); }
};
template<typename num> double distSegSqr(point<num> a, point<num> b, point<num> c) {
	if((b - a) * (c - b) > 0) return b.distSqr(c);
	if((a - b) * (c - a) > 0) return a.distSqr(c);
	double d = (b - a) ^ (c - a);
	return d * d / ((b - a) * (b - a));
}

template <typename num> struct line {
	num a, b, c;
	line() {}
	line(num aa, num bb, num cc) : a(aa), b(bb), c(cc) {}
	line(point<num> s, point<num> e) : a(e.y - s.y), b(e.x - s.x), c(a*s.x + b*s.y) {}
	line pass(point<num> p) { return line(a, b, a*p.x + b*p.y); }
	bool parallel(const line &o) const { return (a * o.b - o.a * b) == 0; }
	point<double> inter(line o) {
		double d = a * o.b - o.a * b;
		if(d == 0) return point<double>(0, 0); //fudeu
		return point<double>((o.b * c - b * o.c)/d, (a * o.c - o.a * c)/d);
	}
};
typedef point<int> pointi;
typedef point<double> pointd;
typedef line<int> linei;
typedef line<double> lined;

pointi ps[4009];
vector<int> adj[2009];
bool intersect(int i, int j) {
	linei l1(ps[2*i], ps[2*i + 1]), l2(ps[2*j], ps[2*j + 1]);
	if(l1.parallel(l2)) return ((ps[2*i+1] - ps[2*i]) ^ (ps[2*j+1] - ps[2*j])) == 0;

}

int main() {
	while(true) {
		scanf("%d", &n);
		if(!n) return 0;
		for(i = 0; i < n; i++) {
			pointi a[4];
			for(j = 0; j < 4; j++) scanf("%d %d", &a[i].x, &a[i].y);
			sort(a, a + 4);
			ps[4*i] = a[0];
			ps[4*i + 1] = a[3];
			ps[4*i + 2] = a[1];
			ps[4*i + 3] = a[2];
			adj[2*i].clear();
			adj[2*i + 1].clear();
		}
		
	}
}

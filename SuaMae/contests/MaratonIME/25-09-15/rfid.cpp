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

set<int> ls[20100];
set<int>& l(int y) { return ls[y + 10009]; }
int r, w;
pti wa[10][2];

bool pos(pti a, pti b) {
	double d = sqrt(a.distSqr(b));
	int i;
	for(i = 0; i < w; i++)
		if(intersectSeg(a, b, wa[i][0], wa[i][1]))
			d++;
	return d <= r;
}

pti ss[1000];
void solve(pti p) {
	int sz = 0, i;
	for(i = p.y - r; i <= p.y + r; i++) {
		auto lb = l(i).lower_bound(p.x - r);
		auto ub = l(i).upper_bound(p.x + r);
		while(lb != ub) {
			if(pos(p, pti(*lb, i)))
				ss[sz++] = pti(*lb, i);
			++lb;
		}
	}
	sort(ss, ss + sz);
	printf("%d", sz);
	for(i = 0; i < sz; i++)
		printf(" (%d,%d)", ss[i].x, ss[i].y);
	putchar('\n');
}


int main() {
	int i, s, p, x, y;
	for_tests(t, tt) {
		scanf("%d %d %d %d", &s, &r, &w, &p);
		for(i = 0; i < 20100; i++) ls[i].clear();
		for(i = 0; i < s; i++) {
			scanf("%d %d", &x, &y);
			l(y).insert(x);
		}
		for(i = 0; i < w; i++) {
			scanf("%d %d %d %d", &wa[i][0].x, &wa[i][0].y, &wa[i][1].x, &wa[i][1].y);
		}
		for(i = 0; i < p; i++) {
			scanf("%d %d", &x, &y);
			solve(pti(x, y));
		}
	}
}

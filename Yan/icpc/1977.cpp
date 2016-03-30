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
	template<typename num2> ptn(point<num2> p) : x(p.x), y(p.y) {}
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
	num dist_sqr(ptn o) const { return (*this - o) * (*this - o); }
	ptn norm() const { return *this / ((*this) * (*this)); }
	bool operator < (ptn o) const { return x < o.x || (x == o.x && y < o.y); }
};
typedef point<int> pti;
typedef point<double> ptd;
temp inline num cross(ptn a, ptn b, ptn c) { return (c - a) ^ (b - a); }
// o ponto c esta no segmento [a, b]?
temp inline bool between_seg(ptn a, ptn b, ptn c) { return cross(a, b, c) == 0 && ((b - c) * (a - c) <= 0); }
// sqr dist de c pro segmento [a, b]
temp double dist_seg_sqr(ptn a, ptn b, ptn c) {
	if((b - a) * (c - b) > 0) return b.dist_sqr(c);
	if((a - b) * (c - a) > 0) return a.dist_sqr(c);
	double d = (b - a) ^ (c - a);
	return d * d / ((b - a) * (b - a));
}
temp int sign(num x) { return (x > 0) - (x < 0); }
// [a, b] intersecta [c, d]?
temp bool inter_seg(ptn a, ptn b, ptn c, ptn d) {
	if(between_seg(a, b, c) || between_seg(a, b, d) || between_seg(c, d, a) || between_seg(c, d, b)) return true;
	if((sign(cross(a, b, c)) * sign(cross(a, b, d)) == -1) && (sign(cross(c, d, a)) * sign(cross(c, d, b)) == -1)) return true;
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
		if(d == 0) return point<double>(0, 0); // fudeu
		return point<double>((o.b * c - b * o.c)/d, (a * o.c - o.a * c)/d);
	}
};
typedef line<int> lni;
typedef line<double> lnd;

pti C[40][40], p[100];
int m[40];
int c;

double mn_dist(ptd p) {
	int i, j;
	double d = 1/0.;
	for(i = 0; i < c; i++)
		for(j = 0; j < m[i]; j++)
			d = min(d, dist_seg_sqr(ptd(C[i][j]), ptd(C[i][j + 1]), p));
	return d;
}
typedef pair<double, int> pdi;
#define out second
ptd get(ptd a, ptd b, double d) {
	return (((b - a).norm() * d) + a);
}

double tern(ptd a, ptd b, double l, double r) {
	//printf("(%.0f, %.0f).(%.0f, %.0f)\n%.5f .. %.5f\n", a.x, a.y, b.x, b.y, l, r);
	for(int i = 0; i < 50; i++) {
		double m1 = (2.*l + r) / 3.;
		double m2 = (l + 2.*r) / 3.;
		if(mn_dist(get(a, b, m1)) < mn_dist(get(a, b, m2))) l = m1;
		else r = m2;
	}
	//printf("ans %.5f\n", sqrt(mn_dist(get(a, b, (l + r) / 2.))));
	return sqrt(mn_dist(get(a, b, (l + r) / 2.)));
}

bool in;
double ans;
void process(pti a, pti b) {
	//printf("IN (%d, %d) (%d, %d)\n", a.x, a.y, b.x, b.y);
	ptd da(a), db(b);
	vector<pdi> v;
	int i, j;
	for(i = 0; i < c; i++)
		for(j = 0; j < m[i]; j++) {
			if(((b - a) ^ (C[i][j + 1] - C[i][j])) == 0) {
				if(!inter_seg(a, b, C[i][j], C[i][j + 1])) continue;
				//printf("parallel to %d.%d but inter\n", i, j);
				ptd pa(C[i][j]), pb(C[i][j + 1]);
				if(((db - da) * (pa - da)) < 0) pa = a;
				if(((db - da) * (pb - da)) < 0) pb = a;
				if(((pb - da) * (pb - da)) < ((pa - da) * (pa - da))) pa = pb;
				v.pb(pdi(min((pa - da) * (pa - da), (pb - da) * (pb - da)), false));
			} else if(inter_seg(a, b, C[i][j], C[i][j + 1])) {
				//printf("inter %d.%d (%d, %d) (%d, %d)\n", i, j, C[i][j].x, C[i][j].y, C[i][j+1].x, C[i][j+1].y);
				ptd p = lnd(a, b).inter(lnd(C[i][j], C[i][j + 1]));
				// TALVEZ MUDAR
				bool ou = ((db - p) ^ (ptd(C[i][j + 1]) - p)) < 0;
				v.pb(pdi((p - da) * (p - da), ou));
				//printf("%.5f -- %d\n", v.back().fst, v.back().out);
			}
		}
	v.pb(pdi((db - da) * (db - da), false));
	v.pb(pdi(0, !in));
	sort(v.begin(), v.end());
	j = 0;
	for(i = 0; i < v.size() - 1; i++) {
		if((v[i + 1].fst - v[i].fst) <= 1e-9) {
			v[i].snd |= v[i + 1].snd;
			i++;
		}
		v[i].fst = sqrt(v[i].fst);
		v[j++] = v[i];
	}
	while(i > j) v.pop_back(), i--;
	sort(v.begin(), v.end());
	for(i = 0; i < v.size() - 1; i++) {
		pdi g = v[i];
		if(g.out) {
			in = false;
			ans = max(ans, tern(da, db, g.fst, v[i + 1].fst));
		} else in = true;
		//printf("(%.0f, %.0f).(%.0f, %.0f) -- %.5f in %d\n", da.x, da.y, db.x, db.y, g.fst, in);
	}
}

int main() {
	int i, j, n;
	for_tests(t, tt) {
		scanf("%d %d", &c, &n);
		for(i = 0; i < n; i++)
			scanf("%d %d", &p[i].x, &p[i].y);
		for(i = 0; i < c; i++) {
			scanf("%d", &m[i]);
			for(j = 0; j < m[i]; j++)
				scanf("%d %d", &C[i][j].x, &C[i][j].y);
			C[i][j] = C[i][0];
			ll tot = 0;
			for(j = 1; j < m[i] - 1; j++)
				tot += cross(C[i][0], C[i][j], C[i][j + 1]);
			//if(tot < 0) printf("inv %d\n", i);
			if(tot < 0) reverse(C[i] + 1, C[i] + m[i]);
		}
		ans = 0.;
		in = true;
		for(i = 0; i < n - 1; i++)
			process(p[i], p[i + 1]);
		printf("%.10f\n", ans);
	}

}

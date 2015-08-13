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
	template<typename num2> point(point<num2> p) : x(p.x), y(p.y) {}
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
	bool operator < (point o) const { return ((x+y) == (o.x+o.y) &&  x < o.x)|| (x + y) < (o.x + o.y); }
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
	line(point<num> s, point<num> e) : a(e.y - s.y), b(s.x - e.x), c(a*s.x + b*s.y) {}
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
const int MAX = 2009;
pointi ps[4009];
vector<int> adj[MAX];
bool intersect(int i, int j) {
	pointi &a = ps[2*i], &b = ps[2*i+1], &c = ps[2*j], &d = ps[2*j+1];
	linei l1(a, b), l2(c, d);
	//printf("comp %d, %d\n", i, j);
	//printf("(%d, %d) -> (%d, %d) and\n(%d, %d) -> (%d, %d)\npal %d\n", a.x, a.y, b.x, b.y, c.x, c.y, d.x, d.y, l1.parallel(l2));
	if(l1.parallel(l2)) return ((b - a) ^ (b - c)) == 0 && !(max(a.x, b.x) < min(c.x, d.x) || max(c.x, d.x) < min(a.x, b.x) 
		|| max(a.y, b.y) < min(c.y, d.y) || max(c.y, d.y) < min(a.y, b.y));
	pointd p = l1.inter(l2);
	//printf("int (%.3f, %.3f)\n", p.x, p.y);
	return abs(distSegSqr<double>(a, b, p)) < 1e-7 &&
	       abs(distSegSqr<double>(c, d, p)) < 1e-7;
}

int n;
int seen[MAX], d[MAX], low[MAX], tc, tempo;
vector<int> st;
int comp[MAX], ct;
bool ok;
void dfs(int u) {
	if(seen[u] == tc) return;
	seen[u] = tc;
	low[u] = d[u] = tempo++;
	st.pb(u);
	for(int v : adj[u]) {
		dfs(v);
		low[u] = min(low[u], low[v]);
	}
	if(low[u] == d[u]) {
		int s; ct++; //printf("round %d\n", ct);
		do {
			s = st.back(); st.pop_back();
			low[s] = INT_MAX;
			//printf("%d here (%d)\n", s, s ^ 1);
			if(comp[s ^ 1] == ct) ok = false;
			comp[s] = ct;
		} while(s != u);
	}
}

int main() {
	int i, j;
	while(true) {
		st.clear();
		scanf("%d", &n);
		if(!n) return 0;
		for(i = 0; i < n; i++) {
			pointi a[4];
			for(j = 0; j < 4; j++) scanf("%d %d", &a[j].x, &a[j].y);
			sort(a, a + 4);
			ps[4*i] = a[0];
			ps[4*i + 1] = a[3];
			ps[4*i + 2] = a[1];
			ps[4*i + 3] = a[2];
			adj[2*i].clear();
			adj[2*i + 1].clear();
		}
		for(i = 0; i < 2*n; i++)
			for(j = i + 1; j < 2*n; j++) {
				if(i == (j ^ 1)) continue;	
				if(intersect(i, j)) {
					//printf("%d, %d intersect\n", i, j);
					adj[i].pb(j ^ 1);
					adj[j].pb(i ^ 1);
				}
			}
		ok = true;
		tc++; tempo = 0;
		for(i = 0; i < 2*n; i++)
			dfs(i);
		if(ok) puts("YES");
		else puts("NO");
	}
}

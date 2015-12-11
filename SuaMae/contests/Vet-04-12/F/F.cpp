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
	ptn(){}
	ptn(num a, num b) : x(a), y(b){}
	num operator * (ptn o) const { return x*o.x + y*o.y; }
	ptn operator * (num i) const { return ptn(x*i,y*i); }
	ptn operator - (ptn o) const { return ptn(x - o.x, y- o.y);}
	num operator ^ (ptn o) const { return x*o.y - y*o.x; }
	bool operator < (ptn o) const { return x < o.x || (x==o.x && y < o.y);}
};
temp inline num cross(ptn a,ptn b,ptn c){ return (b-a) ^ (c-a); }

temp double distSegSqr(ptn a,ptn b,ptn c){
	double d = (b-a) ^ (c-a);
	return d * d / ((b-a) * (b-a));
}

temp struct line {
	num a, b, c;
	line() {}
	line(num aa, num bb, num cc) : a(aa), b(bb), c(cc) {}
	point<double> inter(line o) {
		double d = a * o.b - o.a * b;
		if(d == 0) return point<double>(0, 0); // fudeu
		return point<double>((o.b * c - b * o.c) / d, (a * o.c - o.a * c) / d);
	}
};

typedef point <int> pti;
typedef line <ll> lni;

const int N = 100009;
struct li {
	li() {}
	li(ll aa, ll bb, double s) : a(aa), b(bb), st(s) {}
	ll a, b;
	double st;
};
li st[N]; int sn;

ll solve(ll p) {
	int l = 0, r = sn - 1;
	while(l < r) {
		int m = (l + r) / 2;
		if(st[m].st <= p) r = m;
		else l = m + 1;
	}
	return st[l].a * p + st[l].b;
}

double inter(li p, li q) {
	return lni(p.a, -1, -p.b).inter(lni(q.a, -1, q.b)).x;
}

bool better(li p, li q, li nx) {
	double i = inter(p, q);	
	return i >= nx.st;
}

void add(li l) {
	while(sn > 1 && better(l, st[sn - 1], st[sn - 2])) sn--;
	double p = inter(l, st[sn - 1]);
	st[sn - 1].st = p;
	st[sn++] = l;
}

ll D[N], P[N], R[N], G[N], p[N], dp[N];
int main() {
	int n, i, t = 0;
	ll c, d;
	while(scanf("%d %lld %lld", &n, &c, &d) != EOF && (n || c || d)) {
		for(i = 0; i < n; i++)
			scanf("%lld %lld %lld %lld", &D[i], &P[i], &R[i], &G[i]), p[i] = i;
		sort(p, p + n, [](int i, int j) { return D[i] < D[j]; });
		//for(i = 0; i < n; i++) printf("D[%d] = %d\n", p[i], D[p[i]]);
		D[n] = d + 1; dp[n] = 0;
		sn = 0;
		st[sn++] = li(d + 1, 0, -1/0.);
		for(i = n - 1; i >= 0; i--) {
			int l = p[i];
			dp[i] = R[l] - P[l] - G[l] * D[l] - G[l] + 
				solve(G[l]);
			add(li(D[l], dp[i], -1/0.));
			printf("dp[%d] = %lld\n", i, dp[i]);
		}
		ll best = 0;
		for(i = 0; i < n; i++)
			if(c >= P[p[i]]) {
				printf("[%d] %lld max= %lld\n", i, best, dp[i] + c);
				best = max(best, dp[i] + c);
			}
		printf("Case %d: %lld\n", ++t, best);
	}
}

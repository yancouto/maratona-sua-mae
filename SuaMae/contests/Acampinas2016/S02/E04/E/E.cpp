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
const int N = 12000, M = 14 * 3500;

ll c[N]; int cn;
inline int comp(ll x) {
	return lower_bound(c, c + cn, x) - c;
}

int nx[M], es[N], to[M], cp[M], fl[M], seen[N], en;

int f;
int dfs(int u, int t) {
	if(seen[u] == f + 1) return 0;
	seen[u] = f + 1;
	if(u == t) return 1;
	for(int e = es[u]; e != -1; e = nx[e])
		if(cp[e] - fl[e] && dfs(to[e], t)) {
			fl[e]++;
			fl[e ^ 1]--;
			return 1;
		}
	return 0;
}

int max_flow(int s, int t) {
	while(dfs(s, t)) f++;
	return f;
}


void add_edge(int a, int b) {
	cp[en] = 1; to[en] = b; nx[en] = es[a]; es[a] = en++;
	cp[en] = 0; to[en] = a; nx[en] = es[b]; es[b] = en++;
}

ll a[3000], b[3000], num[3000]; int p[3000]; char op[3000];
int main() {
	int i, n;
	memset(es, -1, sizeof es);
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%lld %lld", &a[i], &b[i]);
		c[cn++] = a[i] + b[i];
		c[cn++] = a[i] - b[i];
		c[cn++] = a[i] * b[i];
		p[i] = i;
	}
	sort(c, c + cn);
	cn = unique(c, c + cn) - c;
	random_shuffle(p, p + n);
	for(i = 0; i < n; i++) {
		add_edge(2550, i);
		add_edge(i, 2600 + comp(a[p[i]] + b[p[i]]));
		add_edge(i, 2600 + comp(a[p[i]] - b[p[i]]));
		add_edge(i, 2600 + comp(a[p[i]] * b[p[i]]));
	}
	for(i = 0; i < cn; i++)
		add_edge(2600 + i, 2551);
	if(max_flow(2550, 2551) < n) { puts("impossible"); return 0; }
	for(i = 0; i < n; i++) {
		for(int e = es[i]; e != -1; e = nx[e])
			if(fl[e] == 1) {
				ll x = c[to[e] - 2600];
				num[p[i]] = x;
				if(a[p[i]] + b[p[i]] == x) op[p[i]] = '+';
				else if(a[p[i]] - b[p[i]] == x) op[p[i]] = '-';
				else if(a[p[i]] * b[p[i]] == x) op[p[i]] = '*';
			}
	}
	for(i = 0; i < n; i++)
		printf("%lld %c %lld = %lld\n", a[i], op[i], b[i], num[i]);
}

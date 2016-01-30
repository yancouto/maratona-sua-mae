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
const int N = 20009;
int es[N], nx[N], to[N], fl[N], cp[N];

int seen[N], cur = 1, en;
int dfs(int s, int u, int f, int t) {
	if(u == t) return f;
	if(seen[u] == cur) return 0;
	seen[u] = cur;
	for(int e = es[u]; e != -1; e = nx[e])
		if(cp[e] - fl[e] && to[e] != s)
			if(int a = dfs(s, to[e], min(f, cp[e] - fl[e]), t)) {
				fl[e] += a;
				fl[e ^ 1] -= a;
				return a;
			}
	return 0;
}


void max_flow(int s, int t) {
	while(dfs(s, s, INT_MAX, t)) cur++;
}


void add_edge(int a, int b, int c) {
	cp[en] = c; to[en] = b; nx[en] = es[a]; es[a] = en++;
	cp[en] = 0; to[en] = a; nx[en] = es[b]; es[b] = en++;
}


int main() {
	freopen("arrays.in", "r", stdin);
	freopen("arrays.out", "w", stdout);
	int i, j, n, k, s, v;
	memset(es, -1, sizeof es);
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++) {
		add_edge(i, 1500, k);
		scanf("%d", &s);
		for(j = 0; j < s; j++) {
			scanf("%d", &v);
			add_edge(100 + v, i, 1);
		}
		add_edge(100, i, 100);
	}
	add_edge(1501, 100, 10000);
	for(i = 1; i <= 1000; i++)
		add_edge(1501, 100 + i, 1);
	max_flow(1501, 1500);
	int tot = 0;
	for(i = 1; i <= 1000; i++)
		for(int e = es[100 + i]; e != -1; e = nx[e])
			if(fl[e]) {
				tot += i;
				break;
			}
	printf("%d\n", tot);
	for(i = 0; i < n; i++) {
		vector<int> vv;
		for(j = es[i]; j != -1; j = nx[j])
			if(to[j] >= 100 + 1 && to[j] <= 100 + 1000 && fl[j] < 0)
				vv.pb(to[j] - 100);
		printf("%d", (int) vv.size());
		for(int x : vv) printf(" %d", x);
		putchar('\n');
	}
}

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
inline int count_1s(int x) { return __builtin_popcount(x); }
inline int count_1s(ull x) { return __builtin_popcountll(x); }
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif

int n;
struct ed{
	int to;
	int c, f;
	ed() {}
	ed(int a, int b, int c) : to(a), c(b), f(c) {} 
} es[20009];
int en;
vector<int> adj[209];


int seen[209], tempo;
int d[209];
bool bfs() {
	memset(d, -1, sizeof d);
	deque<int> q;
	q.pb(0);
	d[0] = 0;
	bool found = false;
	while(!q.empty()) {
		int u = q.front();
		q.pop_front();
		for(int ee : adj[u]) {
			ed &e = es[ee];
			if(d[e.to] == -1) {
				d[e.to] = d[u] + 1;
				q.pb(e.to);
				if(e.to == 2*n + 1) found = true;
			}
		}
	}
	return found;
}

bool dfs_v(int u) {
	if(seen[u] == tempo) return false;
	seen[u] = tempo;
	if(u == 2*n + 1) return true;
	for(int ee : adj[u]) {
		ed &e = es[ee];
		if(d[e.to] == d[u] + 1) {
			if(dfs_v(e.to)) {
				// printf("%d->%d valid (good)\n", u, e.to);
				e.f++;
				es[ee^1].f--;
				return true;
			}
		}
	}
	return false;
}

bool dfs() {
	dfs_v(0);
}

int max_flux() {
	int f = 0, b, d;
	tempo = 1;
	while(bfs()) {
		// puts("aa");
		tempo++;
		while(dfs()) { tempo++; f++; }
		tempo++;
	}
	printf("f%d\n", f);
	return f;
}

void add_edge(int u, int v, int c) {
	adj[u].pb(en);
	es[en++] = ed(v, c, 0);
	adj[v].pb(en);
	es[en++] = ed(u, 0, 0);
}

int main() {
	int i, j; en = 0; char c;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		add_edge(0, i + 1, 1);
		add_edge(n + 1 + i, 2 * n + 1, 1);
		for(j = 0; j < n; j++) {
			scanf(" %c", &c);
			if(c == '.') {
				add_edge(i + 1, j + n + 1, 1);
			}
		}
	}
	int ff = max_flux();
	if(ff < n) puts("-1");
	else {
		for(i = 0; i < en; i += 2) {
			if(es[i].to >= 1 && es[i].to <= n && es[i^1].to >= n+1 && es[i^1].to <= 2*n)
				printf("%d %d\n", es[i].to, es[i^1].to);
			else if(es[i^1].to >= 1 && es[i^1].to <= n && es[i].to >= n+1 && es[i].to <= 2*n)
				printf("%d %d\n", es[i^1].to, es[i].to);
		}
	}
	return 0;
}
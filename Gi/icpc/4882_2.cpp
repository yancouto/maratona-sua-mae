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
const int MAXN = 1005;
const int MAXM = 100005;

struct Edge {
	int u, v, l;
	Edge() {}
	Edge(int u, int v, int l) : u(u), v(v), l(l) {}
	bool operator <(const Edge &o) const {
		return o.l > l;
	}
};

int n, m, p, u, v, l;
int mark[MAXN];
vector<Edge> ed;
int id[MAXN], sz[MAXN];

int find(int x) {
	if(x == id[x]) return x;
	return id[x] = find(id[x]);
}

void join(int x, int y) {
	x = find(x); y = find(y);
	if(x == y) return;
	if(sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y];
	id[y] = x;
}

int seen[MAXN];
int kruskall(int op) {
	sort(ed.begin(), ed.end());
	int ans = 0;
	for(int i = 0; i < ed.size(); i++) {
		u = ed[i].u; v = ed[i].v;
		if(find(u) == find(v)) continue;
		if(op && (mark[u] || mark[v])) continue; 
		if(mark[u] && mark[v]) continue;
		seen[u] = seen[v] = 1;
		ans += ed[i].l;
		join(ed[i].u, ed[i].v);
	}
	return ans;
}

void Initialize() {
	memset(mark, 0, sizeof mark);
	memset(seen, 0, sizeof seen);
	ed.clear();
	for(int i = 0; i < n; i++)
		sz[i] = 1, id[i] = i;
}

int main() {
	while(scanf("%d %d %d", &n, &m, &p) != EOF) {	
		Initialize();
		for(int i = 0; i < p; i++)
			scanf("%d", &u), mark[u-1] = 1;
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &l);
			u--; v--;
			ed.pb(Edge(u, v, l));
		}
		if(n == 2 && m > 0) { printf("%d\n", ed[0].l); continue; }
		if(n == 1) { puts("0"); continue; }
		int ans = kruskall(1);
		bool f = true;
		int comp;
		for(int i = 0; i < n; i++) {
			if(f && !mark[i]) { comp = find(i); f = false; }
			if(!mark[i] && find(i) != comp) { ans = -1; break; }
		}
		if(ans == -1) puts("impossible");
		else {
			ans += kruskall(0);
			for(int i = 0; i < n; i++)
				if(!seen[i]) { ans = -1; break; }
			if(ans == -1) puts("impossible");
			else printf("%d\n", ans);
		}
	}

	return 0;
}

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
#define max_v 210
#define max_e 30000
using namespace std;

int s, t;

struct Edge {
	int u, v;
	int c, f;
	inline int cf() { return c - f; }
} es[2 * max_e];
int en;

list<int> adj[max_v];
typedef list<int>::iterator It;

struct No {
	int e, cost, nv;
	No() {}
	No(int a, int b, int c) : e(a), cost(b), nv(c) {}
	bool operator < (const No &o) const { return cost < o.cost; }
};

int usado[max_v], pai[max_v], tempo, nv[max_v];
int find_stream() {
	priority_queue<No> pq;
	pai[s] = -1; usado[s] = ++tempo; nv[s] = 0;
	for(It it = adj[s].begin(); it != adj[s].end(); ++it) pq.push(No(*it, es[*it].cf(), 1));
	while(!pq.empty()) {
		No no = pq.top();
		pq.pop();
		Edge &e = es[no.e];
		if(usado[e.v] == tempo) continue;
		usado[e.v] = tempo;
		pai[e.v] = no.e;
		nv[e.v] = no.nv;
		if(e.v == t) {
			int l = no.e;
			while(l != -1) {
				es[l].f += no.cost;
				es[l ^ 1].f -= no.cost;
				l = pai[es[l].u];
			}
			return no.cost;
		}
		for(It it = adj[e.v].begin(); it != adj[e.v].end(); ++it) {
			Edge &e2 = es[*it];
			if(usado[e2.v] != tempo && e2.cf())
				pq.push(No(*it, min(e2.cf(), no.cost), no.nv + 1));
		}
	}
	return 0;
}

int dfs_visit(int v, int m) {
	usado[v] = tempo;
	if(v == t) {
		int l = pai[v];
		while(l != -1) {
			es[l].f += m;
			es[l ^ 1].f -= m;
			l = pai[es[l].u];
		}
		return m;
	}
	for(It it = adj[v].begin(); it != adj[v].end(); ++it) {
		Edge &e2 = es[*it];
		if(usado[e2.v] != tempo && e2.cf() > 0 && nv[e2.v] == nv[e2.u] + 1) {
			pai[e2.v] = *it;
			if(int d = dfs_visit(e2.v, min(m, e2.cf()))) return d;
		}
	}
	return 0;
}

int dfs() {
	tempo++; pai[s] = -1;
	return dfs_visit(s, INT_MAX);
}

int max_flux() {
	int d, d2, fl = 0;
	memset(nv, -1, sizeof usado);
	memset(usado, 0, sizeof usado); tempo = 0;
	do {
		d = find_stream();
		fl += d;
		while(d2 = dfs()) fl += d2;
	} while(d);
	return fl;
}

void add_edge(int i, int j, int fl) {
	Edge &e1 = es[en++], &e2 = es[en++];
	e1.u = e2.v = i;
	e1.v = e2.u = j;
	e1.c = fl; e2.c = 0;
	e1.f = e2.f = 0;
	adj[i].push_back(en - 2);
	adj[j].push_back(en - 1);
}

int ff() {
	int n, m, a, b, fl, i;
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for(i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &fl);
		add_edge(a, b, fl);
	}
	printf("%d\n", max_flux());
}

int n; double d;
struct nest {
	int x, y, n, m;
	void read() { scanf("%d %d %d %d", &x, &y, &n, &m); }
	bool reach(nest &o) {
		return ((o.x-x)*(o.x-x)+(o.y-y)*(o.y-y)) <= d*d;
	}
}ns[102];

int inf = 100000000;
int main() {
	int i, j;
	for_tests(tt, ttt) {
		scanf("%d %lf", &n, &d);
		en = 0;
		int tot = 0;
		for(i = 0; i <= 2*n+3; i++)
			adj[i].clear();
		for(i = 1; i <= n; i++) {
			ns[i].read();
			tot += ns[i].n;
			add_edge(2*i, 2*i+1, ns[i].m);
			if(ns[i].n)
				add_edge(0, 2*i, ns[i].n);
		}
		for(i = 1; i <= n; i++)
			for(j = 1; j<= n; j++) {
				if(i == j) continue;
				if(!ns[i].reach(ns[j])) continue;
				add_edge(i*2+1, j*2, inf);
				add_edge(j*2+1, i*2, inf);
			}
		int qt = 0;
		for(i = 1; i <= n; i++) {
			for(j = 0; j < en; j++)
				es[j].f = 0;
			s = 0; t = 2*i;
			int mf = max_flux();
			if(mf == tot) {
				if(qt) printf(" %d", i - 1);
				else printf("%d", i - 1);
				qt++;
			}
		}
		if(qt) putchar('\n');
		else puts("-1");
	}
	return 0;
}

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
#	define debug(args...) //fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif

#define max_v 505
#define max_e 50009


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

struct nest {
	int x, y, f, r;
	inline void read() {
		scanf("%d %d %d %d", &x, &y, &f, &r);
	}
}ns[109];

struct leaf {
	int x, y, f;
	inline void read() {
		scanf("%d %d %d", &x, &y, &f);
	}
} ls[409];

bool inside(ull x1, ull y1, ull r, ull x2, ull y2) {
	return (((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 -  y2))) <= r*r;
}

int main() {
	int i, j, w, p, x, y, f;
	for_tests(tt, ttt) {
		en = 0;
		for(i = 0; i < max_v; i++) adj[i].clear();
		scanf("%d %d", &w, &p);
		for(i = 0; i < w; i++)
			ns[i].read();
		j = 0;
		for(i = 0; i < p; i++) {
			ls[j].read();
			if(inside(ns[0].x, ns[0].y, ns[0].r, ls[j].x, ls[j].y))
				ns[0].f += ls[j].f;
			else j++;
		}
		p = j;
		debug("newp %d", p);
		ull tot = 0;
		for(i = 0; i < p; i++) {
			add_edge(w + i, w + p, ls[i].f);
			tot += ls[i].f;
		}
		debug("tot%llu", tot);
		for(i = 1; i < w; i++) {
			if(ns[i].f > ns[0].f) break;
			add_edge(0, i, ns[0].f - ns[i].f);
			for(j = 0; j < p; j++)
				if(inside(ns[i].x, ns[i].y, ns[i].r, ls[j].x, ls[j].y))
					add_edge(i, w + j, 10000000);
		}
		if(i < w) { puts("Lonesome Willy"); continue; }
		for(i = 0; i < p; i++)
			if(adj[w + i].size() == 1)
				tot -= ls[i].f;
		s = 0; t = w + p;
		if(max_flux() == tot) puts("Suiting Success");
		else puts("Lonesome Willy");
	}
	return 0;
}

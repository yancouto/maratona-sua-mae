#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <climits>
const int max_v = 209;
const int max_e = 20009;
using namespace std;

int s, t;

struct Edge {
	int u, v;
	int c, f;
	inline int cf() { return c - f; }
} es[2 * max_e];
int en;

vector<int> adj[max_v];
typedef vector<int>::iterator It;

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
const int inf = 1000000;

char grid[103][103];
int main() {
	int n, i, j; char c;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		add_edge(0, i + 1, 1);
		add_edge(n + 1 + i, 2 * n + 1, inf);
		for(j = 0; j < n; j++) {
			scanf(" %c", &c);
			grid[i][j] = c;
			if(c == '.') {
				add_edge(i + 1, j + n + 1, 1);
			}
		}
	}
	s = 0; t = 2 * n + 1;
	int ff = max_flux();
	if(ff == n) {
		for(i = 0; i < en; i += 2) {
			if(es[i].u >= 1 && es[i].u <= n && es[i].v >= n+1 && es[i].v <= 2*n)
				if(es[i].f)
					printf("%d %d\n", es[i].u, es[i].v - n);
		}
		return 0;
	}
	en = 0;
	for(i = 0; i < 2 * n + 4; i++) adj[i].clear();
	for(i = 0; i < n; i++) {
		add_edge(0, i + 1, inf);
		add_edge(n + 1 + i, 2 * n + 1, 1);
		for(j = 0; j < n; j++) {
			if(grid[i][j] == '.') {
				add_edge(i + 1, j + n + 1, 1);
			}
		}
	}
	s = 0; t = 2 * n + 1;
	ff = max_flux();
	if(ff == n) {
		for(i = 0; i < en; i += 2) {
			if(es[i].u >= 1 && es[i].u <= n && es[i].v >= n+1 && es[i].v <= 2*n)
				if(es[i].f)
					printf("%d %d\n", es[i].u, es[i].v - n);
		}
	}
	return 0;
}
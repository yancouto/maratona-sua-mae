#include <bits/stdc++.h>
#define mp make_pair
#define debug(args...) //fprintf(stderr, args)
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int MAXV = 200000, INF = 0x7FFFFFFF;

int V = MAXV;
int prio[MAXV], curflow[MAXV], prevedge[MAXV], prevnode[MAXV], q[MAXV], pot[MAXV];
bool inqueue[MAXV];

struct Edge {
	int to, f, cap, cost, rev;
};

vector<Edge> graph[MAXV];

void addEdge(int s, int t, int cap, int cost) {
	Edge a = {t, 0, cap, cost, (int) graph[t].size()};
	Edge b = {s, 0, 0, -cost, (int) graph[s].size()};
	graph[s].push_back(a);
	graph[t].push_back(b);
}

void bellmanFord(int s, int dist[]) {
	fill(dist, dist + V, INF);
	dist[s] = 0;
	int qt = 0;
	q[qt++] = s;
	for (int qh = 0; (qh - qt) % V != 0; qh++) {
		int u = q[qh % V];
		inqueue[u] = false;
		for (int i = 0; i < (int) graph[u].size(); i++) {
			Edge &e = graph[u][i];
			if (e.cap <= e.f) continue;
			int v = e.to;
			int ndist = dist[u] + e.cost;
			if (dist[v] > ndist) {
				dist[v] = ndist;
				if (!inqueue[v]) {
					inqueue[v] = true;
					q[qt++ % V] = v;
				}
			}
		}
	}
}

pii minCostFlow(int s, int t, int maxf) {
	bellmanFord(s, pot);
	int flow = 0;
	int flowCost = 0;
	while (flow < maxf) {
		priority_queue<ll, vector<ll>, greater<ll> > q;
		q.push(s);
		fill(prio, prio + V, INF);
		prio[s] = 0;
		curflow[s] = INF;
		while (!q.empty()) {
			ll cur = q.top();
			int d = cur >> 32;
			int u = cur;
			q.pop();
			if (d != prio[u])
				continue;
			for (int i = 0; i < (int) graph[u].size(); i++) {
				Edge &e = graph[u][i];
				int v = e.to;
				if (e.cap <= e.f) continue;
				int nprio = prio[u] + e.cost + pot[u] - pot[v];
				if (prio[v] > nprio) {
					prio[v] = nprio;
					q.push(((ll) nprio << 32) + v);
					prevnode[v] = u;
					prevedge[v] = i;
					curflow[v] = min(curflow[u], e.cap - e.f);
				}
			}
		}
		if (prio[t] == INF)
			break;
		for (int i = 0; i < V; i++)
			pot[i] += prio[i];
		int df = min(curflow[t], maxf - flow);
		flow += df;
		for (int v = t; v != s; v = prevnode[v]) {
			Edge &e = graph[prevnode[v]][prevedge[v]];
			e.f += df;
			graph[v][e.rev].f -= df;
			flowCost += df * e.cost;
		}
	}
	return make_pair(flow, flowCost);
}

void clear() {
	for(int i = 0; i < V; i++)
		graph[i].clear();
}

vector<int> v[250];
int u[250];

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	V = m + n + 2;
	for(int i = 1; i <= m; i++) {
		int k;
		scanf("%d", &k);
		addEdge(0, i, 1, 0);
		debug("%d -> %d (%d, %d)\n", 0, i, 1, 0);
		for(int j = 0; j < k; j++) {
			int aux;
			scanf("%d", &aux);
			v[i].pb(aux);
		}
	}
	map<int, int> ma;
	for(int i = 1; i <= m; i++) {
		scanf("%d", &u[i]);
		if(u[i]) ma[u[i]] = 1;
	}
	for(int i = 1; i <= n; i++) {
		if(ma.find(i) != ma.end()) addEdge(i + m, m + n + 1, 1, -int(1e6));
		else addEdge(i + m, m + n + 1, 1, 0);
		debug("%d -> %d (%d, %d)\n", i + m, m + n + 1, 1, 0);
	}
	for(int i = 1; i <= m; i++) {
		for(int j = 0; j < v[i].size(); j++) {
			if(u[i] && u[i] != v[i][j]) {
				addEdge(i, v[i][j] + m, 1, 1);
				debug("%d -> %d (%d, %d)\n", i, v[i][j] + m, 1, 1);
			}
			else {
				addEdge(i, v[i][j] + m, 1, 0);
				debug("%d -> %d (%d, %d)\n", i, v[i][j] + m, 1, 0);
			}
		}
	}
	pii ans = minCostFlow(0, V - 1, INF);
	printf("%d %d\n", ans.ff, ans.ss + int(1e6)*ma.size());
	for(int i = 1; i <= m; i++) {
		for(Edge e : graph[i]) {
			if(e.to != 0 && e.cap - e.f == 0) {
				printf("%d ", e.to - m);
				goto next;
			}
		}
		printf("0 ");
		next:;
	}
	return 0;
}

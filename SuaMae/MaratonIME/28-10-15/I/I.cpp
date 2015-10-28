#include <bits/stdc++.h>
using namespace std;

const int MAXV = 900, INF = 0x7FFFFFFF;
struct edge {
	int dest, rev, cap, f;
	edge(int dest, int rev, int cap) : dest(dest), rev(rev), cap(cap) {
		f = 0;
	}
};

int dist[MAXV + 1], ptr[MAXV + 1];
vector<edge> adj[MAXV + 1];
int V, S, T;

void add_edge(int a, int b, int cap) {
	adj[a].push_back(edge(b, adj[b].size(), cap));
	adj[b].push_back(edge(a, adj[a].size() - 1, 0));
}

bool bfs() {
	for(int i = 1; i <= V; i++)
		dist[i] = -1;
	dist[S] = 0;
	queue<int> q;
	q.push(S);
	while(!q.empty()) {
		int v = q.front(); q.pop();
		for(int i = 0; i < adj[v].size(); i++) {
			edge e = adj[v][i];
			if(dist[e.dest] == -1 && e.cap > e.f) {
				dist[e.dest] = dist[v] + 1;
				q.push(e.dest);
			}
		}
	}
	return dist[T] != -1;
}

int dfs(int v, int f) {
	if(v == T) return f;
	for(; ptr[v] < adj[v].size(); ++ptr[v]) {
		edge &e = adj[v][ptr[v]];
		if(dist[e.dest] == dist[v] + 1 && e.cap > e.f) {
			int df = dfs(e.dest, min(f, e.cap - e.f));
			if(df > 0) {
				e.f += df;
				adj[e.dest][e.rev].f -= df;
				return df;
			}
		}
	}
	return 0;
}

int max_flow() {
	int flow = 0;
	while(bfs()) {
		for(int i = 1; i <= V; i++)
			ptr[i] = 0;
		while(true) {
			int df = dfs(S, INF);
			if(df == 0) break;
			flow += df;
		}
	}
	return flow;
}

void imp() { puts("-1"); exit(0); }
const int E = 100000;
int deg[1000], a[E], b[E], e[E];
int num[350][305];
int main() {
	freopen("trade.in", "r", stdin);
	freopen("trade.out", "w", stdout);
	int i, n, m, p;
	scanf("%d %d %d", &m, &n, &p);
	V = m + n + 100;
	for(i = 0; i < p; i++) {
		scanf("%d %d", &a[i], &b[i]);
		a[i]--; b[i]--;
		//a[i] = rand() % m; b[i] = rand() % n;
		num[a[i]][b[i]] = i;
		deg[a[i]]++; deg[b[i] + m]++;
	}
	for(i = 0; i < n + m; i++)
		if(deg[i] < 2)
			imp();
	//f::reset_all();
	for(i = 0; i < m; i++)
		add_edge(n + m + 10, i + 1, deg[i] - 2);
	for(i = 0; i < n; i++)
		add_edge(i + m + 1, n + m + 12, deg[i + m] - 2);
	for(i = 0; i < p; i++)
		add_edge(a[i] + 1, b[i] + m + 1, 1);		
	S = n + m + 10; T = n + m + 12;
	int x = max_flow();
	int st[E], sn = 0;
	for(i = 0; i < m; i++)
		for(edge e : adj[i + 1])
			if(e.f == 0 && e.dest >= m + 1 && e.dest <= m + n)
				st[sn++] = num[i][e.dest - m - 1];
	sort(st, st + sn);
	printf("%d\n%d", sn, st[0] + 1);
	for(i = 1; i < sn; i++)
		printf(" %d", st[i] + 1);
	putchar('\n');
}

#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#define MAX 210

using namespace std;

struct Edge {
	int to, cap;
	Edge() {}
	Edge(int to, int cap) : to(to), cap(cap) {}
};

vector<int> adj[MAX];
vector<Edge> edge;
int used[MAX], dist[MAX], A[MAX], B[MAX];
int mat[MAX][MAX];

bool dinic_bfs (int s, int t) {
	memset(dist, -1, sizeof dist);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty() && dist[t] == -1) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < adj[v].size(); i++) {
			int ind = adj[v][i];
			int next = edge[ind].to;
			if (dist[next] == -1 && edge[ind].cap) {
				dist[next] = dist[v] + 1;
				q.push(next);
			}
		}
	}
	return dist[t] != -1;
}

int dinic_dfs (int v, int t, int flow) {
	if (v == t) return flow;
	for (int i = 0; i < (int)adj[v].size(); i++) {
		int ind = adj[v][i];
		int next = edge[ind].to;
		if (dist[next] == dist[v] + 1 && edge[ind].cap) {
			int got = dinic_dfs(next, t, min(flow, edge[ind].cap));
			if (got) {
				edge[ind].cap -= got;
				edge[ind^1].cap += got;
				return got;
			}
		}
	}
	return 0;
}

int max_flow(int s, int t) {
	int ans = 0, got = 0;
	while (dinic_bfs(s, t)) {
		memset(used, 0, sizeof used);
		do {
			int got = dinic_dfs(s, t, INT_MAX);
			//printf("Peguei=%d\n", got);
			ans += got;
		} while (got);
	}
	return ans;
}

inline void add_edge(int u, int v, int c) {
	adj[u].push_back(edge.size());
	edge.push_back(Edge(v, c));
	adj[v].push_back(edge.size());
	edge.push_back(Edge(u, 0));
}

int main () {
	int n, m;
	scanf("%d%d", &n, &m);
	int s = 0, t = 2 * n + 2;
	int totA, totB;

	totA = 0;
	for (int v = 1; v <= n; v++) {
		scanf("%d", &A[v]);
		totA += A[v];
		add_edge(s, 2*v, A[v]);
		add_edge(2*v, 2*v + 1, A[v]);
	}

	totB = 0;
	for (int v = 1; v <= n; v++) {
		scanf("%d", &B[v]);
		totB += B[v];
		add_edge(2*v + 1, t, B[v]);
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(2*u, 2*v + 1, A[u]);
		add_edge(2*v, 2*u + 1, A[v]);
	}
	
	if (totB == max_flow(s, t) && totA == totB) {
		printf("YES\n");
		for (int v = 1; v <= n; v++) 
			for (int a = 0; a < adj[2*v].size(); a++) {
				int ind = adj[2*v][a];
				Edge ed = edge[ind];
				if (ed.to == s) continue;
				mat[v][ed.to/2] = A[v] - ed.cap;
			}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < n; j++) 
				printf("%d ", mat[i][j]);
			printf("%d\n", mat[i][n]);
		}
	} 
	else 
		printf("NO\n");

	return 0;
}
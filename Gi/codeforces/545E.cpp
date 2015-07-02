#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#include <list>
//typedef pair<pair<int, int>, pair<int, int>> tipo;

using namespace std;

int n, m;
int used[300003];

struct No {
	int v, edge, a;
	long long dist;
	No() {}
	No(int v, long long dist, int edge, int a) : v(v), dist(dist), edge(edge), a(a) {}
	bool operator < (const No &e) const{
		if (dist == e.dist) 
			return edge > e.edge;
		return dist > e.dist ;
	}
};


struct Ad {
	int u, w, a; 
	Ad () {}
	Ad (int u, int w, int a) : u(u), w(w), a(a) {}
};

vector<Ad> adj[300003];

long long dik (int s) {
	long long ans = 0;
	priority_queue<No> pq;
	pq.push(No(s, 0, 0, -1));
	while (!pq.empty()) {
		No x = pq.top();
		pq.pop();
		if (used[x.v]) continue;
		used[x.v] = x.a;
		ans += x.edge;
		for (int i = 0; i < adj[x.v].size(); i++) {
			Ad n = adj[x.v][i];
			if (!used[n.u])
				pq.push(No(n.u, x.dist + n.w, n.w, n.a));
		}
	}
	return ans;
}

int main () {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back(Ad(v, w, i + 1));
		adj[v].push_back(Ad(u, w, i + 1));
	}

	int s;
	scanf("%d", &s);
	printf("%lld\n", dik(s));
	for (int i = 1; i <= n; i++)
		if (i != s)
			printf("%d ", used[i]);
	printf("\n");



	return 0;
}
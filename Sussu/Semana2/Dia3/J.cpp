#include <bits/stdc++.h>
#define mp make_pair
#define debug(args...) //fprintf(stderr, args)
#define pb push_back
#define ff first
#define ss second
using namespace std;

const int MAXN = 112345;

vector<int> adj[MAXN];
map<vector<int>, int> m;
map<int, int> t;
int k = 1;

void dfs(int v) {
	for(int u : adj[v]) dfs(u);
	vector<int> x;
	for(int u : adj[v]) x.pb(t[u]);
	sort(x.begin(), x.end());
	if(m.find(x) == m.end()) m[x] = t[v] = k++;
	else t[v] = m[x];
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n; i++) {
		int par;
		scanf("%d", &par);
		adj[par].pb(i);
	}
	dfs(1);
	for(int i = 1; i <= n; i++) printf("%d ", t[i]);
	return 0;
}

#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 100010;

vector<int> adj[MAX];
int mrk[MAX];

void dfs(int v, int t) {
	mrk[v] = t++;
	for(int u : adj[v])
		if(mrk[u] == -1)
			dfs(u, t);
}

int main(){
	int t, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			adj[i].clear();
			mrk[i] = -1;
		}
		for(int i = 1; i < n; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			adj[b].push_back(a);
			adj[a].push_back(b);
		}
		dfs(0, 0);
		int orig, best = -1;
		for(int i = 0; i < n; i++) {
			if(mrk[i] > best) {
				best = mrk[i];
				orig = i;
			}
			mrk[i] = -1;
		}
		dfs(orig, 0);
		int ans = -1;
		for(int i = 0; i < n; i++) {
			if(mrk[i] > ans) {
				ans = mrk[i];
			}
		}
		printf("%d\n", (ans + 1) / 2);
	}
	return 0;
}

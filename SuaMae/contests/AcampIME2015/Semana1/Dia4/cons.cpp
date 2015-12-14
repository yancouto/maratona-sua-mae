#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 200009;
int n, m;
int c[MAX];
int deg[MAX], deg2[MAX];
vector<int> adj[MAX];


int main() {
	int t, i, x, y;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		for(i = 0; i < n; i++) {
			scanf("%d", &c[i]);
			adj[i].clear();
			deg[i] = deg2[i] = 0;
		}
		for(i = 0; i < m; i++) {
			scanf("%d %d", &x, &y); x--; y--;
			adj[x].push_back(y);
			deg[y]++;
			deg2[y]++;
		}
		vector<int> Q;
		for(i = 0; i < n; i++)
			if(deg[i] == 0)
				Q.push_back(i);
		int color = 1, changes = -1;
		while(!Q.empty()) {
			vector<int> Q2;
			while(!Q.empty()) {
				int u = Q.back();
				Q.pop_back();
				if(c[u] == color) {
					for(int v : adj[u]) {
						deg[v]--;
						if(!deg[v]) {
							if(c[v] == color)
								Q.push_back(v);
							else
								Q2.push_back(v);
						}
					}
				} else Q2.push_back(u);
			}
			color = 3 - color;
			changes++;
			Q.swap(Q2);
		}
		Q.clear();
		for(i = 0; i < n; i++)
			if(deg2[i] == 0)
				Q.push_back(i);
		int color2 = 2, changes2 = -1;
		while(!Q.empty()) {
			vector<int> Q2;
			while(!Q.empty()) {
				int u = Q.back();
				Q.pop_back();
				if(c[u] == color2) {
					for(int v : adj[u]) {
						deg2[v]--;
						if(!deg2[v]) {
							if(c[v] == color2)
								Q.push_back(v);
							else
								Q2.push_back(v);
						}
					}
				} else Q2.push_back(u);
			}
			color2 = 3 - color2;
			changes2++;
			Q.swap(Q2);
		}
		printf("%d\n", min(changes, changes2));
	}
	return 0;
}
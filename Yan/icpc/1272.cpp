// terminar
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
#define pb push_back

pii operator + (pii a, pii b) { return pii(a.fst + b.fst, a.snd + b.snd); }

int main() {
	while(scanf("%d %d %d", &n, &to, &m) != EOF) {
		to--;
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				adj[i][j] = pii(1000000000, 1000000000), mid[i][j] = -1;
		for(i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c); a--; b--;
			adj[a][b] = adj[b][a] = pii(c, 1);
		}
		for(k = 0; k < n; k++)
			for(i = 0; i < n; i++)
				for(j = 0; j < n; j++)
					if(adj[i][j] < adj[i][k] + adj[k][j]) {
						adj[i][j] = adj[i][k] + adj[k][j];
						mid[i][j] = k;
					}
		scanf("%d", &k);
		for(i = 0; i < k; i++)
			scanf("%d", &from[i]);
		
	}
}

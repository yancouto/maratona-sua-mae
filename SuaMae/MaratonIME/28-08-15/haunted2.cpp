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
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
const int MAX = 32;
int G[MAX][MAX], D[MAX][MAX];
struct ed {
	int i, j, c;
	ed() {}
	ed(int a, int b, int k) : i(a), j(b), c(k) {}
};
vector<ed> adj[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;
inline bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; }
int main() {
	int i, j, k, a, b, c, d, t, g, e;
	while(true) {
		scanf("%d %d", &n, &m);
		if(!n) return 0;
		scanf("%d", &g);
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++) {
				G[i][j] = 0;
				adj[i][j].clear();
				D[i][j] = INT_MAX;
			}
		for(i = 0; i < g; i++) {
			scanf("%d %d", &a, &b);
			G[a][b] = 1;
		}
		scanf("%d", &e);
		for(i = 0; i < e; i++) {
			scanf("%d %d %d %d %d", &a, &b, &c, &d, &t);
			adj[a][b].pb(ed(c, d, t));
			G[a][b] = 2;
		}
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				if(G[i][j] == 0 && (i != n - 1 || j != m - 1))
					for(d = 0; d < 4; d++)
						if(valid(i + dx[d], j + dy[d]) && G[i + dx[d]][j + dy[d]] != 1)
							adj[i][j].pb(ed(i + dx[d], j + dy[d], 1));
		D[0][0] = 0;
		for(k = 0; k < n*m; k++) {
			for(i = 0; i < n; i++)
				for(j = 0; j < m; j++)
					for(ed es : adj[i][j])
						if(D[i][j] != INT_MAX && D[es.i][es.j] > D[i][j] + es.c)
							D[es.i][es.j] = D[i][j] + es.c;
		}
		bool ok = true;
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				for(ed es : adj[i][j])
					if(D[i][j] != INT_MAX && D[es.i][es.j] > D[i][j] + es.c)
						ok = false;
		if(!ok) puts("Never");
		else if(D[n-1][m-1] == INT_MAX) puts("Impossible");
		else printf("%d\n", D[n-1][m-1]);
	}
}

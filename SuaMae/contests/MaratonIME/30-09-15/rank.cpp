#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int adj[502][502], n;
int seen[502], te, f[502], tempo, pos[502], t[502];
void dfs(int u) {
	if(seen[u] == te) return;
	seen[u] = te;
	for(int v = 0; v < n; v++)	
		if(adj[u][v])
			dfs(v);
	f[tempo++] = u;
}

int main() {
	int i, j, a, b, m;
	for_tests(tn, tt) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%d", &t[i]);
			pos[--t[i]] = i;
		}
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				adj[i][j] = pos[i] < pos[j];
		//for(i = 0; i < n; i++) {
		//	for(j = 0; j < n; j++)
		//		putchar('0' + adj[i][j]);
		//	putchar('\n');
		//}
		scanf("%d", &m);
		for(i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			swap(adj[a-1][b-1], adj[b-1][a-1]);
		}
		//for(i = 0; i < n; i++) {
		//	for(j = 0; j < n; j++)
		//		putchar('0' + adj[i][j]);
		//	putchar('\n');
		//}
		te++; tempo = 0;
		for(i = 0; i < n; i++)
			dfs(i);
		reverse(f, f + n);
		//for(i = 0; i < n; i++)
		//	printf("%d ", f[i] + 1);
		//putchar('\n');
		bool ok = true;
		for(i = 0; i < n; i++)
			for(j = i + 1; j < n; j++)
				if(!adj[f[i]][f[j]])
					ok = false;
		if(!ok) { puts("IMPOSSIBLE"); continue; }
		printf("%d", f[0] + 1);
		for(i = 1; i < n; i++)
			printf(" %d", f[i] + 1);
		putchar('\n');
	}
}

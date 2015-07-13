// TLE
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
#define pb push_back
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
int n, m, q;
struct vx {
	int c;
	ull ns[2];
} vs[100009];
ull ww[2], dif;

unordered_map<int, int> adj[100009];
int main() {
	char op[10];
	int i, j, u, v, w; int tt = 0;
	while(scanf("%d %d", &n, &m) != EOF) {
		ww[0] = ww[1] = dif = 0;
		for(i = 0; i < n; i++) {
			scanf("%d", &vs[i].c);
			vs[i].ns[0] = vs[i].ns[1] = 0;
		}
		for(i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &w); u--; v--;
			if(vs[u].c != vs[v].c) dif += w;
			else ww[vs[u].c] += w;
			vs[u].ns[vs[v].c] += w;
			vs[v].ns[vs[u].c] += w;
			adj[u].insert(pii(v, w));
			adj[v].insert(pii(u, w));
		}
		scanf("%d", &q);
		int sqq = ceil(sqrt(q));
		unordered_set<int> vc;
		printf("Case %d:\n", ++tt);
		for(i = 0; i < q; i++) {
			if(i && (i % q) == 0) {
				dif = ww[0] = ww[1] = 0;
				vc.clear();
				for(j = 0; j < n; j++) {
					vs[j].ns[0] = vs[j].ns[1] = 0;
					for(pii e : adj[j]) {
						vs[j].ns[vs[e.fst].c] += e.snd;
						if(e.fst > j) {
							if(vs[j].c != vs[e.fst].c) dif += e.snd;
							else ww[vs[j].c] += e.snd;
						}
					}
				}
			}
			scanf(" %s %d", op, &u);
			if(op[0] == 'A') {
				scanf("%d", &v);
				if(u != v) printf("%llu\n", dif);
				else printf("%llu\n", ww[u]);
			} else {
				u--;
				ull d0 = 0;
				for(int a : vc) {
					if(adj[u].count(a)) {
						int aa = adj[u][a];
						d0 += vs[a].c? -aa : aa;
					}
				}
				ull d[2] = {d0, -d0};
				dif += vs[u].ns[vs[u].c] + d[vs[u].c];
				dif -= vs[u].ns[!vs[u].c] + d[!vs[u].c];
				ww[vs[u].c] -= vs[u].ns[vs[u].c] + d[vs[u].c];
				ww[!vs[u].c] += vs[u].ns[!vs[u].c] + d[!vs[u].c];
				if(vc.count(u)) vc.erase(u);
				else vc.insert(u);
				vs[u].c = !vs[u].c;
			}
		}
		for(i = 0; i < n; i++)
			adj[i].clear();
	}
	return 0;
}
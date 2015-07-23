/* TLE DO DEMONIO */
#include <stdio.h>
#include <math.h>
typedef unsigned long long ull;
int n, m, q;
#define MAX 100009
int c[MAX];
ull ns[MAX][2];
ull ww[2], dif;
int sqm;
int deg[MAX];

int ev[MAX*2], ew[2*MAX], ei[2*MAX];

int adj[MAX];
int main() {
	char op[10];
	int i, j, u, v, w; int tt = 0;
	while(scanf("%d %d", &n, &m) != EOF) {
		ww[0] = ww[1] = dif = 0;
		int en = 0;
		for(i = 0; i < n; i++) {
			scanf("%d", &c[i]);
			ns[i][0] = ns[i][1] = 0;
			deg[i] = 0; adj[i] = -1;  
		}
		for(i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &w); u--; v--;
			if(c[u] != c[v]) dif += w;
			else ww[c[u]] += w;
			ns[u][c[v]] += w;
			ns[v][c[u]] += w;
			ev[en] = v; ew[en] = w; ei[en] = adj[u]; adj[u] = en++;
			ev[en] = u; ew[en] = w; ei[en] = adj[v]; adj[v] = en++;
			deg[u]++; deg[v]++;
		}
		sqm = ceil(sqrt(m));
		for(i = 0; i < n; i++) {
			if(deg[i] > sqm) {
				int *l = &adj[i];
				for(j = adj[i]; j != -1; j = ei[j])
					if(deg[ev[j]] > sqm) {
						*l = j;
						l = &ei[j];
					}
				*l = -1;
			}
		}
		scanf("%d", &q);
		printf("Case %d:\n", ++tt);
		for(i = 0; i < q; i++) {
			scanf(" %s %d", op, &u);
			if(op[0] == 'A') {
				scanf("%d", &v);
				if(u != v) printf("%llu\n", dif);
				else printf("%llu\n", ww[u]);
			} else {
				if(deg[--u] > sqm) {
					dif += ns[u][c[u]];
					dif -= ns[u][!c[u]];
					ww[c[u]] -= ns[u][c[u]];
					ww[!c[u]] += ns[u][!c[u]];
					for(j = adj[u]; j != -1; j = ei[j]) {
						ns[ev[j]][c[u]] -= ew[j];
						ns[ev[j]][!c[v]] += ew[j];
					}
					c[u] = !c[u];
				} else {
					for(j = adj[u]; j != -1; j = ei[j]) {
						if(deg[ev[j]] > sqm) {
							ns[ev[j]][c[u]] -= ew[j];
							ns[ev[j]][!c[v]] += ew[j];
						}
						if(c[u] == c[ev[j]]) {
							dif += ew[j];
							ww[c[u]] -= ew[j];
						} else {
							dif -= ew[j];
							ww[c[ev[j]]] += ew[j];
						}
					}
					c[u] = !c[u];
				}
			}
		}
	}
	return 0;
}

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
const int MAX = 505;

int m, n, cmp;
vector<int> g[MAX];
vector<pii> ed;
int seen[MAX * 52];

void dfs(int e) {
	seen[e] = 1; cmp++;
	for(int i = 0; i < g[ed[e].snd].size(); i++) 
		if(!seen[g[ed[e].snd][i]]) dfs(g[ed[e].snd][i]);
}

int main() {
	int u, v;
	scanf("%d %d", &m, &n);
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &v);
			if(v == i) continue;
			ed.pb(pii(i, v)); g[i].pb(ed.size() - 1);
		}
	}
	for(int i = 0; i < ed.size(); i++)
		if(!seen[i]) { dfs(i); cmp++; }
	cmp = max(cmp - 1, 0);
	printf("%d\n", cmp);
	return 0;
}

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
const int MAX = 110;

int n;
vector<int> g[MAX];
int ans[MAX], seen[MAX];
void dfs(int no, int c) {
	ans[no] = c; seen[no] = 1;
	for(int i = 0; i < g[no].size(); i++) {
		int x = g[no][i];
		if(seen[x] && ans[x] != !c) {
			puts("-1"); exit(0);
		}
		if(seen[x]) continue;
		dfs(x, !c);
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int u; 
		while(42) { 
			scanf("%d", &u);
			if(!u) break; u--;
			g[i].pb(u); g[u].pb(i);
		}
	}
	dfs(0, 0);
	for(int i = 0; i < n; i++)
		printf("%d", ans[i]);
	putchar('\n');
	return 0;
}

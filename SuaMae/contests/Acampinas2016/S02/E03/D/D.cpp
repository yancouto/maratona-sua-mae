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
const int N = 100009;
int so[N]; ll num[N];
vector<int> adj[N];
int dfs(int u, int p) {
	int &r = so[u]; r = 1;
	for(int v : adj[u])
		if(v != p)
			r += dfs(v, u);
	num[u] = r;
	for(int v : adj[u])
		if(v != p)
			num[u] += ll(r - so[v]) * ll(so[v]);
	return r;	
}

int main() {
	freopen("lca.in", "r", stdin);
	freopen("lca.out", "w", stdout);
	int i, a, b, n;
	scanf("%d", &n);
	for(i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b); a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0, 0);
	ll t = *max_element(num, num + n);
	vector<int> v;
	for(i = 0; i < n; i++)
		if(num[i] == t)
			v.pb(i + 1);
	printf("%d\n", (int) v.size());
	for(int x : v)
		printf("%d ", x);
	putchar('\n');
}

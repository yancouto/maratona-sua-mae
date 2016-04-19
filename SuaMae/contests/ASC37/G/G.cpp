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
const int N = 212345;

int op[N], v[N], x[N], ans[N];

deque<int> d;
vector<int> adj[N];

void dfs(int u) {
	if(op[u] == 1) d.pb(x[u]);
	else if(op[u] == -1) ans[u] = d.front(), d.pop_front();
	for(int v : adj[u])
		dfs(v);
	if(op[u] == 1) d.pop_back();
	else if(op[u] == -1) d.push_front(ans[u]);
}

int main() {
	freopen("queue.in", "r", stdin);
	freopen("queue.out", "w", stdout);
	int i, n;
	scanf("%d", &n);
	for(i = 1; i <= n; i++) {
		scanf("%d %d", &op[i], &v[i]);
		if(op[i] == 1) scanf("%d", &x[i]);
		adj[v[i]].pb(i);
	}
	dfs(0);
	for(i = 1; i <= n; i++)
		if(op[i] == -1)
			printf("%d\n", ans[i]);
}

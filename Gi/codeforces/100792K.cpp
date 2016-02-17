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
const int N = 200000;

int n, m;
int dg[N];
vector<int> g[N], ans;
priority_queue<int> dq;

void solve() {
	while(!dq.empty()) {
		int v = dq.top();
		dq.pop(); ans.pb(v);
		for(int x : g[v]) {
			dg[x]--;
			if(!dg[x]) dq.push(x);
		}
	}
}

int main() {
	int u, v, i;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		u--; v--;
		g[v].pb(u);
		dg[u]++;
	}
	for(i = 0; i < n; i++)
		if(!dg[i]) dq.push(i);
	solve();
	for(i = ans.size() - 1; i >= 0; i--) 
		printf("%d ", ans[i] + 1);
	putchar('\n');
	return 0;
}

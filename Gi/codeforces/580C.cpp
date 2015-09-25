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

int n, m;
vector<int> g[100005];
int cat[100005];
int mark[100005];
int dfs(int no, int c) {
	if(c > m) return 0;
	mark[no] = 1;
	int ans = 0;
	bool one = false;
	for(int i = 0; i < g[no].size(); i++) {
		int x = g[no][i];
		if(mark[x]) continue;
		ans += dfs(x, c*cat[x] + cat[x]);
		one = true;
	}
	if(!one) return 1;
	return ans;
}

int main() {
	int a, b;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &cat[i]);
	for(int i = 0; i < n-1; i++) {
		scanf("%d %d", &a, &b);
		a--; b--;
		g[a].pb(b);	g[b].pb(a);
	}
	printf("%d\n", dfs(0, cat[0]));
	return 0;
}

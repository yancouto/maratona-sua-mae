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

const int MAXN = 100010;

int n, k, c[MAXN];

ll res;

vector<int> adj[MAXN];

set <int> ans[MAXN];

void go(int v){
	ans[v].insert(c[v]);
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		go(nxt);
		if(ans[nxt].size()>ans[v].size())
			ans[v].swap(ans[nxt]);
		for(int x: ans[nxt]){
			ans[v].insert(x);
		}
	}
	res+=ans[v].size();
}

int main (){
	scanf("%d %d", &n, &k);
	for(int a=2;a<=n;a++){
		int b;
		scanf("%d", &b);
		adj[b].pb(a);
	}
	for(int a=1;a<=n;a++){
		scanf("%d", &c[a]);
	}
	go(1);
	printf("%lld\n", res);
}

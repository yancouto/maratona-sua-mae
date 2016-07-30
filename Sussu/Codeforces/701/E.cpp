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
const int MAXN = 212345;

int n, k, eh[MAXN];
ll s[MAXN];

vector <int> adj[MAXN];

void dfs(int v, int p){
	s[v] = eh[v];
	for(int nxt: adj[v]){
		if(nxt != p){
			dfs(nxt, v);
			s[v] += s[nxt];
		}
	}
}

ll go(int v, int p){
	ll ans = 0;
	for(int nxt: adj[v]){
		if(nxt != p){
			ans += go(nxt, v) + min(s[nxt], 2*k - s[nxt]);
		}
	}
	return ans;
}

int main (){
	scanf("%d%d", &n, &k);
	int i;
	for(int a=0;a<2*k;a++){
		scanf("%d", &i);
		eh[i] = 1;
	}
	for(int a=0;a<n-1;a++){
		int j;
		scanf("%d%d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	dfs(1, 0);
	cout << go(1, 0);
}

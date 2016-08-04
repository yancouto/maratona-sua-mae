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

const int MAXN = 112345;

int n, p[MAXN], sz[MAXN], h[MAXN];

double s[MAXN];

vector<int> adj[MAXN];

int dfs(int v){
	sz[v] = 1;
	for(int nxt: adj[v]){
		h[nxt] = h[v] + 1;
		sz[v] += dfs(nxt);
	}
	return sz[v];
}

void go(int v){
	s[v] = (n - sz[v] - h[v])/2. + h[v] + 1;
	for(int nxt: adj[v]){
		go(nxt);
	}
}

int main (){
	scanf("%d", &n);
	for(int a=2;a<=n;a++){
		scanf("%d", &p[a]);
		adj[p[a]].pb(a);
	}
	h[1] = 0;
	dfs(1);
	go(1);
	for(int a=1;a<=n;a++){
		printf("%.1f ",s[a]); 
	}
}

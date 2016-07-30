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

const int MAXN = 3000002;

int n, sz[MAXN];

int fodeu = 0;

vector <int> adj[MAXN];

void go(int v, int p, int d){
	if(fodeu) return;
	for(int nxt: adj[v]){
		if(nxt == p) continue;
		go(nxt, v, d);
		if(sz[nxt] != d)
			sz[v] += sz[nxt];
		if(sz[v] > d){
			fodeu = 1;
			return;
		}
	}	
}

int main (){
	scanf("%d", &n);
	for(int a=2;a<=n;a++){
		int u;
		scanf("%d", &u); 
		adj[u].pb(a);
		adj[a].pb(u);
	}
	for(int a=n;a>=1;a--){
		if(n%a == 0){
			for(int b=0;b<=n;b++)
				sz[b] = 1;
			fodeu = 0;
			go(1, 0, a);
			if(!fodeu)
				printf("%d ", n/a);
		}
	}
}

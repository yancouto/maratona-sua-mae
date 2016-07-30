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

vector <int> adj[MAXN], in[MAXN];

int mrk[MAXN], n, m;

ll s[MAXN];

ll go(int v, int p){
	mrk[v] = p;
	ll ans = s[v];
	for(int nxt: adj[v]){
		if(mrk[nxt] != p)
			ans += go(nxt, p);
	}
	return ans;
}

int main (){
	while(scanf("%d%d", &n, &m)!=  EOF && n+m != 0){
		for(int a=0;a<=n;a++){
			adj[a].clear();
			mrk[a] = -1;
		}
		for(int a=0;a<=m;a++){
			in[a].clear();
		}
		for(int a=1;a<=n;a++){
			int nv, np;
			scanf("%lld %d %d", &s[a], &nv, &np);
			for(int b=0;b<nv;b++){
				int u;
				scanf("%d", &u);
				adj[a].pb(u);
			}
			for(int b=0;b<np;b++){
				int p;
				scanf("%d", &p);
				in[p].pb(a);
			}			
		}
		puts("*****");
		for(int a=1;a<=m;a++){
			ll ans = 0;
			for(int v: in[a]){
				if(mrk[v] == a) continue;
				ans += go(v, a);
			}
			printf("%d %lld\n", a, ans);
		}
	}
}

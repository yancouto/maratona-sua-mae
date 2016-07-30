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

int n, mrk[MAXN], low[MAXN], ind[MAXN], degi, pte[MAXN];

vector <int> adj[MAXN], ver;

ll sz, np, ans, res;

int r;

void go(int v){
//	printf("entre %d\n", v); 
	ind[v] = degi++;
	low[v] = ind[v];
	mrk[v] = 1;
	int cnt = 0;
	for(int nxt: adj[v]){
		if(!mrk[nxt]){
			cnt++;
			go(nxt);
//			printf("volta %d\n", v);
			if(low[nxt] >= ind[v])
				pte[v] = 1;
			low[v] = min(low[nxt], low[v]);
		}
		else
			low[v] = min(low[v], ind[nxt]);	
	}
	if(v == r){
		pte[v] = (cnt > 1);
	}
}

set <int> ptes;

void cnt(int v){
	sz++;
	mrk[v] = 1;
	for(int nxt: adj[v]){
		if(mrk[nxt]) continue;
		else if(pte[nxt]){
			np++;
			ptes.insert(nxt);
			continue;
		}
		cnt(nxt);
	}
}

int main (){
	int t = 0;
	while(scanf("%d", &n)!= EOF && n){
		degi = 1;
		for(int a=0;a<n;a++){
			int i, j;
			scanf("%d %d", &i, &j);
			ver.pb(i);
			ver.pb(j);
			adj[i].pb(j);
			adj[j].pb(i);
		}
		sort(ver.begin(), ver.end());
		ver.erase(unique(ver.begin(), ver.end()), ver.end());
		unique(ver.begin(), ver.end());
		for(int v: ver){
			if(mrk[v]) continue;
			r = v;
			go(v);
		}
		int degc = 0;
		res = 1;
		ans = 0;
		for(int v: ver){
			mrk[v] = 0;
		}
		for(int v: ver){
//			printf("%d mrk %d pte %d\n", v, mrk[v], pte[v]);
			if(mrk[v] || pte[v]) continue;
			sz = 0;
			np = 0;
			ptes.clear();
			cnt(v);
//			printf("cnt %d  %lld %lld\n", v, sz, np);
			if(ptes.size() == 0){
				ans += (1 + (sz > 1));
				res *= max(1ll, (sz*(sz-1))/2ll);
			}
			else if(ptes.size() == 1){
				ans += 1;
				res *= sz;
			}
		}
		printf("Case %d: %lld %lld\n", ++t, ans, res);
		for(int v: ver){
			adj[v].clear();
			mrk[v] = 0;
			pte[v] = 0;
		}
		ver.clear();
	}
}

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

const int MAXN = 500010*2, INF = 0x3f3f3f3f;

vector <int> adj[MAXN], prox[MAXN];

int d0[MAXN], dn[MAXN], mai, mrk[MAXN], maid[MAXN], n, maislonge;

void go(int v,int d){
	mrk[v] = 1;
	d0[v] = d;
	mai = max(mai,d0[v]);
	for(int a=0;a<prox[v].size();a++){
		int nxt = prox[v][a];
		if(mrk[nxt] != 1){
			go(nxt,d+1);
		}
	}
}

int distn(int v,int d){
	mrk[v] = 1;
	dn[v] = d;
	maid[v] = d;
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(mrk[nxt] != 1 && d0[nxt]>=d0[v]){
			distn(nxt,d+1);
			maid[v] = max(maid[v],maid[nxt]);
		}
	}
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(mrk[nxt]!=1 && d0[nxt]<d0[v]){
			distn(nxt,d+1);
		}
	}
	return dn[v];
}

int main (){
	for_tests(t,tt){
		scanf("%d", &n);
		memset(d0, INF,sizeof(d0));
		memset(dn,INF,sizeof(dn));
		for(int a=0;a<=n;a++){
			adj[a].clear();
			prox[a].clear();
		}
		for(int a=0;a<n;a++){
			int i;
			scanf("%d", &i);
			if(i == -1) i = n;
			prox[a].pb(i);
			adj[i].pb(a);
		}
		mai = -1;
		memset(mrk,0,sizeof(mrk));
		go(0,0);
		memset(mrk,0,sizeof(mrk));
		if(d0[n] == INF){
			// tano ciclo
			int aux = mai;

			distn(n,0);
			printf("%d\n", aux+maid[n]+1);
		}
		else{
			maislonge = 0;
			distn(n,0);
		//	printf("%d\n", maislonge);
			int v = 0, res = dn[0]+maid[n], d=0;
			while(v!=n){
				int nxt = prox[v][0];
				v = nxt;
				d++;
				res = max(res,d+maid[v]);
			}
			printf("%d\n", res);
		}
	}
	return 0;
}

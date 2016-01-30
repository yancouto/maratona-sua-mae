
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

int n, ind[MAXN], sal2[MAXN], sal[MAXN], viz[MAXN], c[MAXN], m, s[MAXN], h[MAXN], raiz[MAXN], last[MAXN];

vector <int> adj[MAXN];

vector <int> pri[MAXN];

int paizao(int v){
	if(raiz[v] == v) return v;
		
	return raiz[v] = paizao(raiz[v]);
}

void join(int a,int b){
	a = paizao(a);
	b = paizao(b);
	if(a == b) return;
	if(h[a] < h[b]){
		raiz[a] = b;
	}
	else if(h[a] > h[b]){
		raiz[b] = a;
	}
	else{
		raiz[a] = b;
		h[b]++;
	}
}

int go(int v){
	int mai = viz[v];
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		mai = max(mai,viz[nxt]); 
		mai = max(mai,sal[nxt]);
		if(last[nxt] != -1 && c[last[nxt]] == c[v]) join(last[nxt],v);
		if(c[nxt] == c[v])join(nxt,v);
		last[nxt] = v;
//		printf("%d nxt %d  viz %d sal %d\n",v, nxt, viz[nxt], sal[nxt]); 	
	}
	return mai;
}

void refresh(int v){
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		viz[nxt] = max(viz[nxt], sal[v]);
//		printf("%d viz %d nxt %d\n", v, viz[nxt], nxt);

	}
}

int main (){
	scanf("%d", &n);
	memset(last,-1,sizeof(last));
	for(int a=0;a<n;a++){
		raiz[a] = a;
		scanf("%d", &c[a]);
		pri[c[a]].pb(a);
	}
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j); i--; j--;
		adj[i].pb(j);
		adj[j].pb(i);
	}
	ll res = 0;
	for(int a=0;a<MAXN-1;a++){
		for(int b=0;b<pri[a].size();b++){
			int v = pri[a][b];
			sal2[v] = 1 + go(v);
		}
		for(int b=0;b<pri[a].size();b++){
			int v = pri[a][b];
			sal[v] = sal2[v];
			sal[paizao(v)] = max(sal[paizao(v)], sal[v]);
//			printf("sal %d = %d\n", v, sal[v]);
		}
		for(int b=0;b<pri[a].size();b++){
			int v = pri[a][b];
			sal[v] = sal[paizao(v)];
			refresh(v);
			res += sal[v];
		}
	}
	cout << res << '\n';
}

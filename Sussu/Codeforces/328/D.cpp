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

const int MAXN = 123456+10;

int n, m, mrk[MAXN], esp[MAXN], pai[MAXN], carry[MAXN], cima[MAXN], cont, mark, imai, mai, ini, imaiaux;

vector <int> adj[MAXN];

void dfs(int v,int ant){
	mrk[v]=1;
	pai[v]=ant;
	if(esp[v]==1){
		carry[v]++;
		cima[v]++;
	}
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(mrk[nxt]==0){
			dfs(nxt,v);
			carry[v] += carry[nxt];
			cima[nxt] += cima[v];
		}
	}
}

void conta(int v,int d){
	if(mai==d && v<imai)
		imai=v;
	if(mai<d){
		mai=d;
		imai=v;
	}
	mrk[v] = mark;
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(mrk[nxt]!=mark && carry[nxt]!=0){
			cont++;
			conta(nxt,d+1);
		}
	}
}

void diam(int v,int d,int dir){
	if(mai==d && v<imai)
		imai=v;
	if(mai<d){
		mai=d;
		imai=v;
	}
	if(dir==1 && v==ini)
		dir=0;
	mrk[v]=mark;
	int nxt;
	if(dir==0){
		for(int a=0;a<adj[v].size();a++){
			nxt = adj[v][a];
			if(mrk[nxt]!=mark && carry[nxt]!=0){
				diam(nxt,d+1,dir);
			}
		}
	}
	else{
		nxt = pai[v];
		if(mrk[nxt]!=mark && cima[nxt]!=0){
			diam(nxt,d+1,dir);
		}
	}
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n-1;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	for(int a=0;a<m;a++){
		int i;
		scanf("%d", &i);
		esp[i]=1;
		ini = i;
	}
	dfs(ini,0);
	mark=2;
	mai=-1;
	conta(ini,0);
	mark=3;
	mai=-1;
	imaiaux=imai;
	diam(imai,0,0);
	diam(imai,0,1);
	printf("%d\n%d\n", min(imaiaux,imai), cont*2-mai);
	return 0;
}
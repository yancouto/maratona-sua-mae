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

const int MAXN = 110;

int n, m, deg;

char M[MAXN][MAXN];
int ind[MAXN][MAXN], mrk[MAXN*MAXN*4], c[MAXN*MAXN*4];

int U[MAXN][MAXN]; 
int D[MAXN][MAXN]; 
int R[MAXN][MAXN];
int L[MAXN][MAXN]; 

pii tow[MAXN*MAXN];

vector <int> adj[MAXN*MAXN*4], inv[MAXN*MAXN*4];

stack <int> s;

int ver(int v){
	return 2*v;
}

int hor(int v){
	return ver(v)+1;
}

int sim(int v){
	return 2*v;
}

int nao(int v){
	return sim(v)+1;
}

void add(int u, int v){
	adj[u].pb(v);
	inv[v].pb(u);
}

void dfs(int v){
	mrk[v] = 1;
	for(int nxt: adj[v]){
		if(mrk[nxt]) continue;
		dfs(nxt);
	}
	s.push(v);
}

void go(int v){
	for(int nxt: inv[v]){
		if(!c[nxt]) continue;
		c[nxt] = c[v];
		go(nxt);
	}
}

int main (){
	scanf("%d%d", &n, &m);
	deg = 1;
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			scanf(" %c", &M[a][b]);
			if(M[a][b] == 'T'){
				ind[a][b] = deg;
				tow[deg++] = pii(a, b);
			}
		}
	}
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			L[a][b] = L[a][b-1];	
			if(M[a][b-1] == 'T') L[a][b] = ind[a][b-1];
			if(M[a][b-1] == '#') L[a][b] = 0;
		}
	}
	for(int a=1;a<=n;a++){
		for(int b=m;b>0;b--){
			R[a][b] = R[a][b+1];
			if(M[a][b+1] == 'T') R[a][b] = ind[a][b+1];
			if(M[a][b+1] == '#') R[a][b] = 0;
		}
	}

	for(int b=1;b<=m;b++){
		for(int a=1;a<=n;a++){
			U[a][b] = U[a-1][b];
			if(M[a-1][b] == 'T') U[a][b] = ind[a-1][b];
			if(M[a-1][b] == '#') U[a][b] = 0;
		}
	}

	for(int b=1;b<=m;b++){
		for(int a=n;a>0;a--){
			D[a][b] = D[a+1][b];
			if(M[a+1][b] == 'T') D[a][b] = ind[a+1][b];
			if(M[a+1][b] == '#') D[a][b] = 0;
		}
	}

	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			if(M[a][b] != 'n') continue;
			printf("%d %d implicaa:\n", a, b);
			int u = U[a][b], d = D[a][b], l = L[a][b], r = R[a][b];
			printf("u - %d  d - %d  l - %d  r - %d\n", u, d, l , r);
			if((u != 0) + (d != 0) + (l != 0) + (r != 0) == 3){
				if( u == 0 ){
					add(nao(ver(d)), sim(ver(d)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
					add(nao(hor(r)), sim(hor(r)));
					printf("add(nao(hor(%d)), sim(hor(%d)))\n", r, r);
					add(sim(hor(l)), nao(hor(l)));
					printf("add(sim(hor(%d)), nao(hor(%d)))\n", l, l);
				}
				else if( d == 0 ){
					add(sim(ver(u)), nao(ver(u)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
					add(nao(hor(r)), sim(hor(r)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
					add(sim(hor(l)), nao(hor(l)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
				}
				else if( l == 0 ){
					add(sim(hor(r)), nao(hor(r)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
					add(nao(ver(u)), sim(ver(u)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
					add(sim(ver(d)), nao(ver(d)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
				}
				else{
					add(nao(hor(l)), sim(hor(l)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
					add(nao(ver(u)), sim(ver(u)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
					add(sim(ver(d)), nao(ver(d)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
				}
			}
			else if((u != 0) + (d != 0) + (l != 0) + (r != 0) == 2){
				if( u + r == 0 ){
					add(nao(hor(l)), sim(ver(d)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
					add(nao(ver(d)), sim(hor(l)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
				}
				else if( u + l == 0 ){
					add(sim(hor(r)), sim(ver(d)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
					add(nao(ver(d)), nao(hor(r)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
				}
				else if( d + r == 0 ){
					add(nao(hor(l)), nao(ver(u)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
					add(sim(ver(u)), sim(hor(l)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
				}
				else if( d + l == 0){
					add(sim(hor(r)), nao(ver(u)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
					add(sim(ver(u)), nao(hor(r)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
				}
			}
			else{
				if( u != 0 ){
					add(sim(ver(u)), nao(ver(u)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
				}
				else if( d != 0 ){
					add(nao(ver(d)), sim(ver(d)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
				}
				else if( l != 0 ){
					add(nao(hor(l)), sim(hor(l)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
				}
				else{
					add(sim(hor(r)), nao(hor(r)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
				}
			}
		}
	}

	for(int a=sim(ver(1));a<=nao(hor(deg-1));a++)
		if(!mrk[a])
			dfs(a);

	int cor = 1;
	while(!s.empty()){
		int v = s.top();
		s.pop();
		c[v] = cor++;
		go(v);
	}
	for(int a=ver(1);a <= hor(deg-1);a++){
		if(c[sim(a)] == c[nao(a)]){
			printf("FUDEU %d - ind %d\n", a, a/2);
			return 0;
		}
	}
	printf("funfou\n");
}
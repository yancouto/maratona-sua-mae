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
int ind[MAXN][MAXN], mrk[MAXN*MAXN*4], c[MAXN*MAXN*4], proi[MAXN*MAXN*4], degr[MAXN*MAXN*4];
int jah[MAXN*MAXN], jav[MAXN*MAXN], res[MAXN*MAXN];
int resv[MAXN], resh[MAXN], ja[MAXN*MAXN*4];
int U[MAXN][MAXN]; 
int D[MAXN][MAXN]; 
int R[MAXN][MAXN];
int L[MAXN][MAXN]; 

pii tow[MAXN*MAXN];

queue <int> topsrt;

vector <int> adj[MAXN*MAXN*4], inv[MAXN*MAXN*4];

vector <int> vc[MAXN*MAXN*4];

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
	degr[u]++;
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
	vc[c[v]].pb(v);
	for(int nxt: inv[v]){
		if(c[nxt]) continue;
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
					proi[nao(hor(r))] = 1;
					proi[sim(hor(l))] = 1;
				}
				else if( d == 0 ){
					add(sim(ver(u)), nao(ver(u)));
					printf("add(sim(ver(%d)), nao(ver(%d)))\n", u, u);
					add(nao(hor(r)), sim(hor(r)));
					printf("add(nao(hor(%d)), sim(hor(%d)))\n", r, r);
					add(sim(hor(l)), nao(hor(l)));
					printf("add(sim(hor(%d)), nao(hor(%d)))\n", l, l);
					proi[nao(hor(r))] = 1;
					proi[sim(hor(l))] = 1;
				}
				else if( l == 0 ){
					add(sim(hor(r)), nao(hor(r)));
					printf("add(sim(hor(%d)), nao(hor(%d)))\n", r, r);
					add(nao(ver(u)), sim(ver(u)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", u, u);
					add(sim(ver(d)), nao(ver(d)));
					printf("add(sim(ver(%d)), nao(ver(%d)))\n", d, d);
					proi[nao(ver(u))] = 1;
					proi[sim(ver(d))] = 1;
				}
				else{
					add(nao(hor(l)), sim(hor(l)));
					printf("add(nao(hor(%d)), sim(hor(%d)))\n", l, l);
					add(nao(ver(u)), sim(ver(u)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", u, u);
					add(sim(ver(d)), nao(ver(d)));
					printf("add(sim(ver(%d)), nao(ver(%d)))\n", d, d);
					proi[nao(ver(u))] = 1;
					proi[sim(ver(d))] = 1;
				}
			}
			else if((u != 0) + (d != 0) + (l != 0) + (r != 0) == 2){
				if( u + r == 0 ){
					add(nao(hor(l)), sim(ver(d)));
					printf("add(nao(hor(%d)), sim(ver(%d)))\n", l, d);
					add(nao(ver(d)), sim(hor(l)));
					printf("add(nao(ver(%d)), sim(hor(%d)))\n", d, l);
				}
				else if( u + l == 0 ){
					add(sim(hor(r)), sim(ver(d)));
					printf("add(sim(hor(%d)), sim(ver(%d)))\n", r, d);
					add(nao(ver(d)), nao(hor(r)));
					printf("add(nao(ver(%d)), nao(hor(%d)))\n", d, r);
				}
				else if( d + r == 0 ){
					add(nao(hor(l)), nao(ver(u)));
					printf("add(nao(hor(%d)), nao(ver(%d)))\n", d, d);
					add(sim(ver(u)), sim(hor(l)));
					printf("dd(sim(ver(%d)), sim(hor(%d)))\n", u, l);
				}
				else if( d + l == 0){
					add(sim(hor(r)), nao(ver(u)));
					printf("add(sim(hor(%d)), nao(ver(%d)))\n", r, u);
					add(sim(ver(u)), nao(hor(r)));
					printf("add(sim(ver(%d)), nao(hor(%d)));\n", u, r);
				}
			}
			else{
				if( u != 0 ){
					add(sim(ver(u)), nao(ver(u)));
					printf("add(sim(ver(%d)), nao(ver(%d)))\n", u, u);
					proi[sim(ver(u))] = 1;
				}
				else if( d != 0 ){
					add(nao(ver(d)), sim(ver(d)));
					printf("add(nao(ver(%d)), sim(ver(%d)))\n", d, d);
					proi[nao(ver(d))] = 1;
				}
				else if( l != 0 ){
					add(nao(hor(l)), sim(hor(l)));
					printf("add(nao(hor(%d)), sim(hor(%d)))\n", l, l);
					proi[nao(hor(l))] = 1;
				}
				else{
					add(sim(hor(r)), nao(hor(r)));
					printf("add(sim(hor(r)), nao(hor(r)))\n", r, r);
					proi[sim(hor(r))] = 1;
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
		if(c[v]) continue;
		c[v] = cor++;
		go(v);
	}

	/*
	for(int a=ver(1);a <= hor(deg-1);a++){
		if(c[sim(a)] == c[nao(a)]){
			printf("FUDEU %d - ind %d de cor %d\n", a, a/2, c[sim(a)]);
			return 0;
		}
	}
	for(int a=1;a<cor;a++){
		int ver = 0;
		for(int v: vc[a]){
			if(((v/2)&1 && jah[v/4]) || (!((v/2)&1) && jav[v/4]) || proi[v]) {ver = 1; break;}
		}
		if(!ver){
			for(int v: vc[a]){
				if(((v/2)&1)){
					jah[v/4] = 1;
					res[v/4] += (v%4 - 1);
				}
				else{
					jav[v/4] = 1;
					if(!(v&1)) res[v/4] += 2;
				}

			}
		}
	}
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			if(M[a][b] != 'T') printf("%c", M[a][b]);
			else{
				if(res[ind[a][b]] == 1 || res[ind[a][b]] == 2)
					res[ind[a][b]] = 3 - res[ind[a][b]];
				printf("%d", res[ind[a][b]]);
			}
		}
		printf("\n");
	}
	*/
	for(int a=sim(ver(1));a<=nao(hor(deg - 1));a++){
		if(degr[a] == 0) topsrt.push(a);
	}
	while(!topsrt.empty()){
		int v = topsrt.front();
		topsrt.pop();
		for(int nxt: adj[v]){
			degr[nxt]--;
			if(degr[nxt] == 0)
				topsrt.push(nxt);
		}
		if(ja[v]) continue;
		if(v&1){ //hor
			resh[v/4] = ((v/2)&1);
			ja[v] = 1;
			if(v%4 < 2)
				ja[v+2] = 1;
			else
				ja[v-2] = 1;
		}
		else{
			resv[v/4] = ((v/2)&1);
			ja[v] = 1;
			if(v%4 < 2)
				ja[v+2] = 1;
			else
				ja[v-2] = 1;
		}
	}
	for(int a=1;a<=deg-1;a++){
		if(!resh[a] && !resv[a]) M[tow[a].fst][tow[a].snd] = '1';
		if(resh[a] && !resv[a]) M[tow[a].fst][tow[a].snd] = '2';
		if(resh[a] && resv[a]) M[tow[a].fst][tow[a].snd] = '3';
		if(!resh[a] && resv[a]) M[tow[a].fst][tow[a].snd] = '4';
	}
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			printf("%c", M[a][b]);
		}
		printf("\n");
	}
}
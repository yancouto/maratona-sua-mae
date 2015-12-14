
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

const int MAXN = 40, MAXC = 25*40;

map <string,int> ind;

int n, deg, mrk[MAXN], degp, ifim, res, r[MAXN], degr;

char s[MAXC], pal[MAXC], ini[MAXC], fim[MAXC], indr[MAXN][MAXC];

vector <int> adj[MAXN];

void go(int v){
	mrk[v]=1;
	if(v==ifim){
		res=1;
		r[degr++]=v;
		return;
	}
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(mrk[nxt]==0){
			go(nxt);
		}
		if(res==1){
			r[degr++]=v;
			return;
		}
	}
}

int main (){
	fgets(s, 100, stdin);
	sscanf(s, "%d", &n);
	res=0;
	for(int a=0;a<n;a++){
		fgets(s, MAXC - 2, stdin);
		//printf("%s\n", s);
		int tam = strlen(s);
		int pri=0;
		int pai=0, prox;
		for(int a=0;a<tam;a++){
			if(a==tam-1 || s[a]==' '){
				pal[degp]='\0';
				degp=0;
				//printf("pal %s\n", pal);
				if(pri==0){
					if(ind.find(pal)==ind.end()){
						ind[pal]=deg++;
						strcpy(indr[ind[pal]],pal);
					}
				//	printf("pai %d\n", ind[pal]);
					pai = ind[pal];
					pri=1;
				}
				else{
					if(ind.find(pal)==ind.end()){
						ind[pal]=deg++;
						strcpy(indr[ind[pal]],pal);
					}
					prox = ind[pal];
				//	printf("prox %d\n", prox);
					adj[pai].pb(prox);
					adj[prox].pb(pai);
				}
			}
			else{
				pal[degp++]=s[a];
			}
		}
	}
	scanf(" %s %s", ini, fim);
	if(ind.find(ini)==ind.end() || ind.find(fim)==ind.end()){
		printf("no route found\n");
		return 0;
	}
	degr=0;
	ifim = ind[fim];
	go(ind[ini]);
	if(degr==0){
		printf("no route found\n");
	}
	else{
		for(int a=degr-1;a>=0;a--){
			if(a!=0)printf("%s ", indr[r[a]]);
			else printf("%s\n", indr[r[a]]);
		}
	}
	return 0;
}

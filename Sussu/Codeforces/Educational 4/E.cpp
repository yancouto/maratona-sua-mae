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

const int MAXN = 1000010;

int n, s[MAXN], nciclo[MAXN], deg, tciclo[MAXN], iciclo[MAXN], adj[MAXN], res[MAXN];

vector <int> ciclos[MAXN];

inline void go(int v,int ini){
	while(v!=ini){
		nciclo[v] = deg;
		tciclo[deg]++;
		v = adj[v];
	}
}

inline void botaimp(int v,int ini,int pula){
	int prox = v;
	pula++;
	while(pula){
		prox = adj[prox];
		pula--;
	}
	while(v!=ini){
		//printf("res[%d] = %d\n", v, prox);
		res[v] = prox;
		prox = adj[prox];
		v = adj[v];
	}
	//printf("res[%d] = %d\n", v, prox);	
	res[v] = prox;
}

inline void botapar(int v,int ini,int p){
	int v2 = p;

	while(v!=ini){
		//printf("res[%d] = %d\n", v, v2);
		res[v] = v2;
		v = adj[v];
		//printf("res[%d] = %d\n", v2, v);
		res[v2] = v;
		v2 = adj[v2];
	}
	//printf("res[%d] = %d\n", v, v2);
	res[v] = v2;
	v = adj[v];
	//printf("res[%d] = %d\n", v2, v);
	res[v2] = v;
}

int main(){
	scanf("%d", &n);
	for(int a = 1; a <= n ; a++){
		scanf("%d", &s[a]);
		adj[a] = s[a];
	}
	deg = 0;
	for(int a=1;a<=n;a++){
		if(nciclo[a] == 0){
			deg++;
			nciclo[a] = deg;
			iciclo[deg] = a;
			tciclo[deg] = 1;
			go(adj[a],a);
			ciclos[tciclo[deg]].pb(deg);
		}
	}
	for(int a=1;a<=n;a++){
		if(!ciclos[a].empty()){
			if(a%2){
				for(int c = 0;c<ciclos[a].size();c++){
					int nxt = ciclos[a][c];
					botaimp(adj[iciclo[nxt]],iciclo[nxt], a/2);
				}
			}
			else{
				if(ciclos[a].size() % 2){
					printf("-1\n");
					return 0;
				}
				else{
					for(int c = 0;c < ciclos[a].size();c+=2){
						int nxt = ciclos[a][c];
						int nxt2 = ciclos[a][c+1];
						//printf("%d %d botapar %d %d %d\n", a, ciclos[a].size(), adj[iciclo[nxt]], iciclo[nxt], iciclo[nxt2]);
						botapar(adj[iciclo[nxt]], iciclo[nxt], iciclo[nxt2]);
					}
				}
			}
		}
	}
	for(int a=1;a<=n;a++){
		printf("%d ", res[a]);
	}
}
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

const int MAXN = 10010, LOGN = 20;

vector<int> adj[MAXN], cus[MAXN];

int n, p[MAXN][LOGN], d[MAXN], h[MAXN];

void dfs(int v,int pai, int alt){
	h[v] = alt;
	p[v][0] = pai;
	for(int a = 1;a<LOGN;a++){
		p[v][a] = p[p[v][a-1]][a-1];
	}
	for(int a = 0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt == pai) continue;
		d[nxt] = d[v] + cus[v][a];
		dfs(nxt,v,alt+1);
	}
}

int lca(int i, int j){
	if(h[j] > h[i]) swap(i,j);
	if(h[i] > h[j]){
		for(int a=LOGN-1;a>=0;a--){
			if(h[p[i][a]] > h[j]){
				i = p[i][a];
			}
		}
		i = p[i][0];
	}

	if(i != j){
		for(int a = LOGN-1;a>=0;a--){
			if(p[i][a] != p[j][a]){
				i = p[i][a];
				j = p[j][a];
			}
		}
		i = p[i][0];
	}

	return i;
}

int main(){
	for_tests(t,tt){
		scanf("%d", &n);
		for(int a=0;a<=n;a++){
			adj[a].clear();
			cus[a].clear();
		}
		int ini = -1;
		for(int a=0;a<n-1;a++){
			int i, j, k;
			scanf("%d %d %d", &i, &j, &k);
			if(ini == -1) ini = i;
			adj[i].pb(j);
			cus[i].pb(k);

			adj[j].pb(i);
			cus[j].pb(k);
		}
		d[ini] = 0;
		dfs(ini,ini,0);
		char s[1000];
		while(scanf(" %s", s) != EOF && s[1] != 'O'){
			int i, j, k;
			scanf("%d %d", &i, &j);

			if(s[1] == 'I'){
				printf("%d\n", d[i] + d[j] - 2*d[lca(i,j)]);
			}
			else{
				scanf("%d", &k);
				int m = lca(i,j);
				if(h[i] - h[m] + 1 < k){
					k -= h[i] - h[m] + 1;
					k = h[j] - h[m] + 1 - k;
					swap(i,j);
				}
				k--;
				for(int a = LOGN-1;a>=0;a--){
					if((1 << a) < k){
						k -= (1 << a);
						i = p[i][a];
					}
				}
				if(k==1)
					i = p[i][0];
				printf("%d\n", i);
			}
		}
		printf("\n");
	}
	return 0;
}
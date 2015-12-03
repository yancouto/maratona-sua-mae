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

const int MAXN = 410;

int vei, n, m, adj[MAXN][MAXN], d[MAXN], fil[MAXN], degi, degf;

void bfs(int v){
	while(degi!=degf){
		v = fil[degi++];
		for(int a=1;a<=n;a++){
			if(adj[v][a]==vei && d[a]==-1){
				fil[degf++] = a;
				d[a]=d[v]+1;
			}
		}
	}
}

int main (){
	scanf("%d %d", &n, &m);
	memset(d,-1,sizeof(d));
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		adj[i][j]=1;
		adj[j][i]=1;
	}
	vei = 1-adj[1][n];
	fil[degf++] = 1;
	d[1]=0;
	bfs(1);
	printf("%d\n", d[n]);
	return 0;
}
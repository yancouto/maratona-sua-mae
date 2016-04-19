
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

#define mp make_pair


const int MAXN = 112345, INF = 1000000010;

int s[MAXN], m, n, deg[MAXN], degfix[MAXN], smin[MAXN];

vector <int> adj[MAXN], inv[MAXN];

int go(int v){
	if(smin[v] != INF) return smin[v];
	smin[v] = s[v];
	for(int nxt: adj[v]){
		smin[v] = min(smin[v], go(nxt)-1);
	}
	return smin[v];
}

set <pii> fil;


bool roda(int k, bool i=0){
	fil.clear();
	for(int a=1;a<=n;a++){
		deg[a] = degfix[a];
		if(smin[a] == INF){
			go(a);
		}
		if(deg[a] == 0)
			fil.insert(pii(smin[a],  a));
	}
	int cnt = 1;
	while(!fil.empty()){

		pii b = *fil.begin();
		if(i) printf("%d ", b.snd);
		if(cnt - smin[b.snd] > k) return 0;
		cnt++;
		for(int nxt: adj[b.snd]){
			deg[nxt]--;
			if(deg[nxt] == 0)
				fil.insert(pii(smin[nxt], nxt));
		}
		fil.erase(b);
	}
	if(i)putchar('\n');
	return 1;
}

int main (){
	freopen("grand.in", "r", stdin);	
	freopen("grand.out", "w", stdout);
	
	while(scanf("%d", &n)!=EOF && n != 0){ 
		for(int a=1;a<=n;a++){
			scanf("%d", &s[a]);
			adj[a].clear();
			degfix[a] = deg[a] = 0;
		}
		scanf("%d", &m);
		for(int a=0;a<m;a++){
			int i, j;
			scanf("%d%d", &i, &j);
			adj[i].pb(j);
			deg[j]++;
			degfix[j] = deg[j];
		}
		for(int a=0;a<=n;a++){
			smin[a] = INF;
		}
		int i = 0, j = 1000000;
		while(i < j){
			int m = (i+j)/2;
			if(roda(m))
				j = m;
			else
				i = m+1;
		}
		printf("%d\n", i);
		roda(i,1);
	}	
}

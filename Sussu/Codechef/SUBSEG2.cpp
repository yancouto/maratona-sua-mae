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

const int MAXN = 112345, LOGN = 30, INF = 1e7;

int n, q;

int degr;

struct even{
	int i, j;
	even(){}
	even(int ii, int jj){
		i = ii;
		j = jj;
	}

	bool in(even other){
		return (i >= other.i && j <= other.j);
	}

	bool operator < (const even other) const {
		return (i < other.i || (i == other.i && j < other.j));
	}
} s[MAXN], cs[MAXN];


int degs;

vector <int> adj[MAXN];

int pai[MAXN][LOGN], h[MAXN];

inline int bb(int i, int j, int v){
	while( i < j ){
		int m = (i+j)/2;
		if(cs[m].i < v)
			i = m+1;
		else
			j = m;

	}
}


void go(int v){
	h[v] = h[pai[v][0]] + 1;
	for(int a=1;a<LOGN;a++){
		pai[v][a] = pai[pai[v][a-1]][a-1];
	}
	for(int nxt:adj[v]){
		if(pai[v][0] == nxt) continue;
		go(nxt);
	}
}

inline int deiswap(int i, int j, int deis){
	if(deis)
		return j;
	return i;
}

inline int lca(int i, int j){
	int deis = 0;
	if(h[j] > h[i])
		swap(i, j);

	
	for(int a=LOGN-1;a>=0;a--){
		if(h[pai[i][a]] > h[j])
			i = pai[i][a];
	}
	if(h[i] > h[j])
		i = pai[i][0];
	
	if(i == j)
		return i;

	for(int a=LOGN-1;a>=0;a--){
		if(pai[i][a] != pai[j][a]){
			i = pai[i][a];
			j = pai[j][a];
		}
	}
	i = pai[i][0];
	return i;
}

int main (){
	scanf("%d%d", &n, &q);
	for(int a=0;a<n;a++){
		scanf("%d%d", &s[a].i, &s[a].j);
	}
	sort(s, s+n);
	for(int a=0;a<n;a++){
		if(a == 0 || !(s[a].in(s[a-1]))){
			pai[degs][0] = degs;
			cs[degs++] = s[a];
		}
	}
	pai[degs][0] = degs;
	cs[degs++] = even(INF, INF + 1);
	for(int a=0;a<n;a++){
		int p = bb(0, degs-1, cs[a].j);
		pai[a][0] = p;
		adj[p].pb(a);
	}
	h[degs-1] = 0;
	go(degs-1);
	for(int a=0;a<q;a++){
		int i, j;
		scanf("%d %d",  &i, &j);
		int ii = bb(0, degs-1, i);
		int jj = bb(0, degs-1, j+1);
		int m = lca(ii, jj);
		int res = 0;
		int ult = ii;
		for(int a=LOGN-1;a>=0;a--){
			if(h[pai[ult][a]] > h[m])
				ult = pai[ult][a];
		}
		printf("%d\n", h[ii] - h[m] - (cs[ult].j > j)); 
	}
}


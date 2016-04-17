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

int n, mrk[MAXN];

struct node{
	int c, g;
	node(){}
	node(int cc,int gg){
		c = cc; g = gg;
	}
	bool operator < (node other) const {
		return g > other.g;
	}
} s[MAXN], inf;

vector<int> adj[MAXN];

node go(int v, int pai){
	//printf("entra go(%d, %d)\n", v, pai);
	vector<node> seq;
	for(int nxt: adj[v]){
		if(nxt != pai){
			//printf("%d -> %d\n", v, nxt);
			node aux = go(nxt, v);
			seq.pb(aux);
		}
	}
	sort(seq.begin(), seq.end());
	node ans  = s[v];
	//printf("%d pega, na ordem: ", v);
	for(node u: seq){
		//printf("(%d, %d) ", u.c, u.g);
		if(u.c - ans.g >= 0){
			ans.c += u.c - ans.g;
			ans.g = 0;
		}
		else{
			ans.g -= u.c;
		}
		ans.g += u.g;
	}
	//printf("\ngo(%d, %d) returns (%d, %d)\n", v, pai, ans.c, ans.g);
	seq.clear();
	return ans;
}

int main (){
	int t = 0;
	inf = node(87654321, 87654321);
	while(scanf("%d", &n)!=EOF && n != 0){
		for(int a=0;a<n;a++){
			adj[a].clear();
			int i, j, k;
			scanf("%d%d%d", &i, &j, &k);
			s[a].c = max(i, j+k);
			s[a].g = s[a].c -j -k;
		}
		for(int a=0;a<n-1;a++){
			int i, j;
			scanf("%d%d", &i, &j);
			i--;j--;
			adj[i].pb(j);
			adj[j].pb(i);
		}
		node ans = inf, aux;
		for(int a=0;a<n;a++){
			//printf("RAIZ: %d\n", a);
			aux = go(a, -1);
			if(ans.c > aux.c)
				ans = aux;
		}
		printf("Case %d: %d\n", ++t, ans.c);
	}
}
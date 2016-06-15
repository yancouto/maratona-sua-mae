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

const int MAXN = 100010;

int n, m, pai[MAXN], s[MAXN], res[4*MAXN];
int di, df;
int deg[MAXN];

int fodeu = 0;

vector<int> adj[MAXN];
vector<int> v;

map<pii,int> lig;
inline void liga(int u, int v){
	if(v == 0) return;
	if(lig.find(pii(u, v)) == lig.end())
		adj[u].pb(v);
	lig[pii(u, v)] = 1;
	deg[v]++;
	if(lig.find(pii(u, v)) != lig.end())
		fodeu = max(fodeu, lig[pii(v, u)]);	

	//	printf("fodeu %d\n", fodeu);
}


int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		pai[j] = i;
	}
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
		if(s[a] != pai[a] && s[a] != pai[pai[a]] && s[a] != a)
			fodeu = 1;	
	}
	//	printf("fodeu %d\n", fodeu);
	for(int a=1;a<=n;a++){
		if(s[a] == a){
			liga(a, pai[a]);
			liga(a, pai[pai[a]]);
		}
		if(s[a] == pai[a]){
			liga(pai[a], pai[pai[a]]);
			liga(pai[a], a);
		}
		if(s[a] == pai[pai[a]]){
			liga(pai[pai[a]], pai[a]);
			liga(pai[pai[a]], a);
		}
	}
	if(fodeu){
		puts("-1");
		return 0;
	}
	int v[MAXN], degi = 0;
	for(int a=1;a<=n;a++){
		if(deg[a] == 0){
			v[degi++] = a;
		}
	}
	printf("%d\n", n);
	for(int a=0;a<degi;a++){
		int vv = v[a];
		printf("%d\n", vv);
		for(int nxt: adj[vv]){
			deg[nxt]--;
			if(deg[nxt] == 0)
				v[degi++] = nxt;
		}
	}
}

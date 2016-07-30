

#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define lld I64d
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

const int MAXN = 112345;

int degi;

map <vector<int>, int> ind;

vector <int> adj[MAXN], t[MAXN];

int go(int v){
	t[v].pb(1);
	for(int nxt: adj[v]){
		t[v].pb(go(nxt));
	}
	sort(t[v].begin(), t[v].end());
	if(ind.find(t[v]) == ind.end())
		ind[t[v]] = degi++;

	return ind[t[v]];
}

int main() {
	int i, j, n;
	scanf("%d", &n);
	degi = 1;
	for(int a=2;a<=n;a++){
		int p;
		scanf("%d", &p);
		adj[p].pb(a);
	}
	go(1);
	for(int a=1;a<=n;a++){
		printf("%d ", ind[t[a]]);
	}
	
}

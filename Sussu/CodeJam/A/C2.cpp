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

const int MAXN = 12, DOISA = (1<<11), INF = 1000000;

int n, to[MAXN], dp[MAXN][DOISA][3][MAXN], mrk[MAXN][MAXN];

vector <int> inv[MAXN];

int go(int v, int bm){
	if((bm & (1<<to[v])))
		return 0;
	return go(to[v], bm|(1<<v))+1;
}

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		memset(mrk, 0, sizeof(mrk));
		memset(dp, -1, sizeof(dp));
		for(int a=0;a<=n;a++){
			inv[a].clear();
		}
		for(int a=0;a<n;a++){
			scanf("%d", &to[a]);
			to[a]--;
			inv[to[a]].pb(a);
			mrk[a][to[a]] = 1;
		}
		int res = 0;
		for(int a=0;a<n;a++){
			res = max(res, go(a, 0, 0, a)+1);
		}
		printf("Case #%d: %d\n", tt, res);
	}
}
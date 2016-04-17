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

int go(int v, int bm, int sen, int pri){
	if(dp[v][bm][sen][pri] != -1) return dp[v][bm][sen][pri];

	dp[v][bm][sen][pri] = (-INF)*(to[v] != pri);
	if(sen == 0 && (bm & (1<<to[v])) == 0){
		if(to[to[v]] == v)
			dp[v][bm][sen][pri] = max(dp[v][bm][sen][pri], 1+go(to[v], bm|(1<<v), 1, pri));
		else
			dp[v][bm][sen][pri] = max(dp[v][bm][sen][pri], 1+go(to[v], bm|(1<<v), 0, pri));
	}
	else if(sen == 1){
		dp[v][bm][sen][pri] = 0;
		for(int nxt: inv[v]){
			if((bm & (1<<nxt)) == 0){
				dp[v][bm][sen][pri] = max(dp[v][bm][sen][pri], 1+go(nxt, bm|(1<<v), 1, pri));
			}
		}
	}
	return dp[v][bm][sen][pri];
}

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		memset(dp, -1, sizeof(dp));
		for(int a=0;a<=n;a++)
			inv[a].clear();
		for(int a=0;a<n;a++){
			scanf("%d", &to[a]);
			to[a]--;
			inv[to[a]].pb(a);
		}
		int res = 0;
		for(int a=0;a<n;a++)
			res = max(res, go(a, 0, 0, a)+1);
		printf("Case #%d: %d\n", tt, res);
	}
}
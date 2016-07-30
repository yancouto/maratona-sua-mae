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

const int MAXN = 100010, MAXK = 1010;

int n, k, s[MAXN], p[MAXN], dp[MAXN][3];

int ini[MAXN], fim[MAXN], deg;

int cs[MAXN];

vector <int> adj[MAXN];

void go(int v){
	cs[deg] = s[v];
	ini[v] = deg++;
	for(int nxt: adj[v]){
		go(nxt);
	}
	fim[ini[v]] = deg;
}

int main (){
	while(scanf("%d%d", &n, &k)!=EOF && n+k){
		deg = 0;
		for(int a=0;a<=n;a++){
			adj[a].clear();
			for(int b=0;b<=k;b++){
				dp[a][b] = -1;
			}
		}
		int r;
		for(int a=1;a<=n;a++){
			scanf("%d%d", &p[a], &s[a]);
			adj[p[a]].pb(a);
			if(p[a] == 0)
				r = a;
		}
		go(r);
		dp[0][0] = 0;
		for(int kk = 0;kk < k;kk++){
			int pk = kk&1;
			for(int i = 0;i < n ;i++){
				if(dp[i][pk] == -1) continue;
				dp[i+1][pk] = max(dp[i][pk], dp[i+1][pk]);
				dp[fim[i]][1 - pk] = max(dp[fim[i]][1 - pk], dp[i][pk] + cs[i]);
			}
			for(int i=0;i<=n;i++){
				dp[i][pk] = -1;
			}
		}
		int ans = 0;
		for(int a=0;a<=n;a++){
			ans = max(dp[a][k&1], ans);
		}
		printf("%d\n", ans);
	}
}

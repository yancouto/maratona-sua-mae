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

const int MAXN = 1000010, INF = 0x3f3f3f3f, MAXB = 1000;

int n, pir[MAXB][3], mrk[MAXN][3];

struct pd{
	int v;
	int res[10], deg;
	int tip[10];
} dp[MAXN];

inline char let(int tip){
	if(tip == 0) return 'H';
	return 'L';
}

int main (){
	for(int a=0;a<MAXN;a++){
		dp[a].v = INF;
	}

	for(int a=1;pir[a-1][0] < MAXN;a++){
		pir[a][0] = a*a + pir[a-1][0];
	}
	pir[1][1] = 1;
	for(int a=2;pir[a-1][1] < MAXN || pir[a-2][1] < MAXN;a++){
		pir[a][1] = a*a + pir[a-2][1];
	}
	pir[1][0] = 0;
	pir[1][1] = pir[2][1] = 0;
	dp[0].v = 0;
	for(int a=1;pir[a][1] < MAXN;a++){
		for(int b = MAXN-1 - pir[a][1];b>=0;b--){
			if(dp[b].v != INF){
				if(dp[b + pir[a][1]].v > dp[b].v + 1 && dp[b].deg+1 <= 6){
					for(int c=0;c<dp[b].deg;c++){
						dp[b+pir[a][1]].res[c] = dp[b].res[c];
						dp[b+pir[a][1]].tip[c] = dp[b].tip[c];
					}
					dp[b+pir[a][1]].deg = dp[b].deg;
					dp[b+pir[a][1]].res[dp[b+pir[a][1]].deg] = a;
					dp[b+pir[a][1]].tip[dp[b+pir[a][1]].deg++] = 1;

					dp[b + pir[a][1]].v = dp[b].v +1;
				}
			}
		}
		for(int b = MAXN-1 - pir[a][0];b>=0;b--){
			if(dp[b].v != INF){

				if(dp[b + pir[a][0]].v > dp[b].v + 1 && dp[b].deg+1 <= 6){
					for(int c=0;c<dp[b].deg;c++){
						dp[b+pir[a][0]].res[c] = dp[b].res[c];
						dp[b+pir[a][0]].tip[c] = dp[b].tip[c];
					}
					dp[b+pir[a][0]].deg = dp[b].deg;
					dp[b+pir[a][0]].res[dp[b+pir[a][0]].deg] = a;
					dp[b+pir[a][0]].tip[dp[b+pir[a][0]].deg++] = 0;

					dp[b + pir[a][0]].v = dp[b].v + 1;
				}
			}
		}
	}
	while(scanf("%d", &n)!=EOF && n!=0){
		if(dp[n].v == INF){
			printf("impossible\n");
			continue;
		}
		for(int a=dp[n].deg-1;a>=0;a--){
			printf("%d%c ", dp[n].res[a], let(dp[n].tip[a]));
		}
		printf("\n");
	}
	return 0;
}
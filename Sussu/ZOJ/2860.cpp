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

const int MAXN = 1010;
const ll INF = 10000000000LL;

int n, m, s[MAXN], best[MAXN][MAXN];
ll dp[MAXN][MAXN];

int main (){
	while(scanf("%d%d", &n , &m)!=EOF){
		for(int a=1;a<=m;a++){
			scanf("%d", &s[a]);
		}
		s[0] = 0;
		s[m+1] = n;
		sort(s,s+m+2);

		for(int a=0;a<=m+1;a++){
			for(int b=0;b<=m+1;b++){
				dp[a][b] = INF;
			}
		}

		for(int a=0;a<=m+1;a++){
			dp[a][a] = 0;
			best[a][a] = a;
			if(a != m+1){
				best[a][a+1] = a;
				dp[a][a+1] = 0;
				//printf("dp[%d][%d] %d\nbest[%d][%d] %d\n", a, a+1, dp[a][a+1], a, a+1, a);
			}
		}

		for(int sz=2;sz<=m+1;sz++){
			for(int i=0;i <= m+1-sz; i++){
				int ind;
				ll men = INF;
				for(int mid = best[i][i+sz-1] ; mid <= best[i+1][i+sz] ; mid++){
					if(men > dp[i][mid] + dp[mid][i+sz] + s[i+sz] - s[i]){
						men = dp[i][mid] + dp[mid][i+sz] + s[i+sz] - s[i];
						ind = mid;
					}
				}
				dp[i][i+sz] = men;
				best[i][i+sz] = ind;
				//printf("dp[%d][%d] %d\nbest[%d][%d] %d\n", i, i+sz, men, i, i+sz, ind);
			}
		}
		printf("%lld\n", dp[0][m+1]);
	}
	return 0;
}
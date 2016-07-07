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

int n, m, best[MAXN][MAXN];

ll s[MAXN], sum[MAXN], dp[MAXN][MAXN];

int main (){
	while(scanf("%d%d", &n, &m)!=EOF && n+m!=0){
		for(int a=0;a<=n;a++){
			for(int b=0;b<=n;b++){
				dp[a][b] = INF;
			}
		}
		for(int a=0;a<n;a++){
			scanf("%lld", &s[a]);
			sum[a] = s[a];
			if(a!=0)
				sum[a] += sum[a-1];
		}
		for(int a=0;a<n;a++){
			dp[a][a] = 0;
			best[a][a] = a;
			if(a!=n-1){
				dp[a][a+1] = s[a]*s[a+1];
				best[a][a+1] = a;
			}
		}
		for(int sz = 2; sz < n; sz++){
			ll tot = 0;
			for(int i = 0;i<sz;i++)
				tot += s[i]*(sum[sz] - sum[i]);
			for(int i = 0; i < n-sz;i++){
				ll men = INF;
				int ind;
				if(i > 0){
					tot -= s[i-1]*(sum[i-1+sz] - sum[i-1]);
					tot += s[i+sz]*(sum[i+sz-1] - sum[i-1]);
				}
				for(int j = best[i][i+sz-1]; j <= best[i+1][i+sz];j++){
					if(men > dp[i][j] + dp[j+1][i+sz]){
						men = dp[i][j] + dp[j+1][i+sz];
						ind = j;
					}
				}
				best[i][i+sz] = ind;
				dp[i][i+sz] = tot;
				//printf("%d %d dp %lld best %d (men = %lld)\n", i, i+sz, dp[i][i+sz], best[i][i+sz], men);
			}
		}


		for(int sz = n-m; sz < n; sz++){
			for(int i = 0;i < n-sz;i++){
				ll men = INF;
				int ind;
				for(int j = best[i][i+sz-1]; j <= best[i+1][i+sz];j++){
					if(men > dp[i][j] + dp[j+1][i+sz]){
						men = dp[i][j] + dp[j+1][i+sz];
						ind = j;
					}
				}
				dp[i][i+sz] = men;
				best[i][i+sz] = ind;
				//printf("%d %d dp %lld best %d\n", i, i+sz, dp[i][i+sz], best[i][i+sz]);
			}
		}
		printf("%lld\n", dp[0][n-1]);
	}
	return 0;
}

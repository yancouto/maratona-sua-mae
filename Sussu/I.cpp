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

const int MAXN = 100002, INF = INT_MIN + 10000;

int n, k, s[MAXN], t[MAXN], dp[MAXN][2][2];

int go(int i, int kk, int fl){
	if(kk < 0) return INF;
	if(dp[i][kk][fl] != INF)
		return dp[i][kk][fl];

	if(i == n){
		return dp[i][kk][fl] = 0;
	}
	dp[i][kk][fl] = max(dp[i][kk][fl], go(i+1, kk, fl));
	if(fl)
		dp[i][kk][fl] = max(dp[i][kk][fl], go(i, kk-1, 0) + t[i] + s[i]);
	else
		dp[i][kk][fl] = max(dp[i][kk][fl], go(i+1, kk, 1) - s[i]); 
	return dp[i][kk][fl];
}

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<=n;a++){
		for(int b=0;b<=k;b++){
			for(int c=0;c<2;c++){
				dp[a][b][c] = INF;
			}
		}
	}
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	for(int a=1;a<n;a++){
		scanf("%d", &t[a]);
	}
	dp[0][0][0] = 0;
	for(int kk=0;kk < k;kk++){
		int pk = kk&1;
		for(int i=0;i<n;i++){
			for(int fl=0;fl<2;fl++){
				dp[i+1][pk][fl] = max(dp[i+1][pk][fl], dp[i][pk][fl]);
				printf("%d %d %d %d\n", i, kk, fl, dp[i][pk][fl]);
				if(fl)
					dp[i+1][pk^1][0] = max(dp[i+1][pk^1][0], dp[i][pk][1] + s[i] + t[i]);
				else
					dp[i][pk^1][1] = max(dp[i][pk^1][1], dp[i][pk][0] - s[i]);
			}
		}
		for(int i=0;i<n;i++){
			for(int fl=0;fl<2;fl++){
				dp[i][pk][fl] = INF;
			}
		}
	}
	for(int a=0;a<=n;a++)
		printf("%d %d 0  %d\n", a, k, dp[a][k&1][0]);

}

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

const int LOGN = 60;

ll n;

int s[LOGN];

ll dp[LOGN][4][3][3];

ll go(int i, int n3, int low, int flag){
	if(i == -1)
		return ll(n3 == 0 && flag);

	if(dp[i][n3][low][flag] != -1)
		return dp[i][n3][low][flag];
		
	dp[i][n3][low][flag] = 0;
	
	if(low){
		dp[i][n3][low][flag] += go(i-1, (n3+1)%3, low, 1) + go(i-1, n3, low, flag);	
	}
	else{
		dp[i][n3][low][flag] += go(i-1, n3, s[i], flag);
		if(s[i] == 1){
			dp[i][n3][low][flag] += go(i-1, (n3+1)%3, low, 1);
		}
	}
	

//	printf("return dp[%d][%d][%d] %lld\n", i, n3, low, dp[i][n3][low][flag]);
	return dp[i][n3][low][flag];
}

int main (){
	while(scanf("%lld", &n)!=EOF){
		for(int a=LOGN-1;a>=0;a--){
			s[a] = min((1ll << a)&n, 1ll);
			for(int b=0;b<2;b++){
				for(int c=0;c<3;c++){
					for(int d=0;d<3;d++){
						dp[a][c][b][d] = -1;

					}

				}
			}
		}
		printf("Day %lld: Level = %lld\n", n, go(LOGN-1, 0, 0, 0));
	}

}

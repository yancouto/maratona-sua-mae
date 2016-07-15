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

const int MAXN = 1010, INF = 0x3f3f3f3f;

int n, sdi;
int dp[MAXN][MAXN];
int mrk[MAXN][MAXN];
int res;

int go(int sd, int s){
	if(sd < 0) return INF+1;
	if(dp[sd][s] != INF)
		return dp[sd][s];
	dp[sd][s] = INF-1;
	if(sd == 0 && s == 0){
		return dp[sd][s] = 0;
	}
	for(int d=0;d<=9;d++){
//		printf("%d %d chama %d-%d %d\n", sd, s, sd , d, (s*10 + d)%n);
		dp[sd][s] = min(dp[sd][s], go(sd - d, (s*10 + d)%n)+1);
//		printf("dp deu %d\n", dp[sd][s]);
	}
//	printf("%d %d: %d\n", sd, s, dp[sd][s]);
	return dp[sd][s];
}

void rego(int sd, int s){
	if(sd == 0 && s == 0){
		return ;
	}
	for(int d=0;d<=9;d++){
		if(sd - d >= 0 && go(sd, s) == go(sd - d,(s*10 + d)%n)+1){
			printf("%d", d);
			rego(sd - d, (s*10 + d)%n);
			break;
		}
	}
}

int main (){
	memset(dp, INF, sizeof(dp));
	scanf("%d", &n);
	int nn = n;
	while(nn != 0){
		sdi += nn%10;
		nn/=10;
	}
	res = go(n,0);
	rego(n, 0);
	printf("\n");
}

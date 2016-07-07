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

const int MAXN = 1123;

int n, k;

ll s[MAXN], dp[MAXN][MAXN], sum[MAXN], sum2[MAXN];
int opt[MAXN][MAXN];

inline ll s2(int i, int j){
	ll ss = (sum[j] - sum[i-1]);
	return (ss*ss - sum2[j] + sum2[i-1])/2;
}

void go(int i, int j, int l, int r, int kk){
	if(i > j) return;
	int m = (i + j)/2;
	//printf("calcula dp[%d][%d]\n", m, kk);
	for(int a=l;a<=min(r, m);a++){
	//	printf("    confere com a = %d   %lld + %lld\n", a, dp[a-1][kk-1], s2(a, m));
		if(dp[m][kk] > dp[a-1][kk-1] + s2(a, m)){
			dp[m][kk] = dp[a-1][kk-1] + s2(a, m);
			opt[m][kk] = a;
		}
	}
	//printf("dp[%d][%d]: %lld\n", m, kk, dp[m][kk]);
	go(i, m-1, l, opt[m][kk], kk);
	go(m+1, j, opt[m][kk], r, kk);
}


int main (){
	while(scanf("%d %d", &n, &k)!=EOF && n+k != 0){
		sum[0] = 0;
		sum2[0] = 0;
		for(int a=0;a<=n;a++){
			for(int b=0;b<=k;b++){
				dp[a][b] = LLONG_MAX;
				if(a == 0)
					dp[a][b] = 0;
			}
		}
		for(int a=1;a<=n;a++){
			scanf("%lld", &s[a]);
			sum[a] = s[a];
			sum2[a] = s[a]*s[a];
			sum[a] += sum[a-1];
			sum2[a] += sum2[a-1];
		}
		for(int a=0;a<=n;a++){
			dp[a][0] = s2(0, a);
		}
		for(int kk=1;kk<=k;kk++){
			go(1, n, 1, n, kk);
		}
		printf("%lld\n", dp[n][k]);
	}
}

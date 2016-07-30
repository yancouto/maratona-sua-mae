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

const int INF = 0x3f3f3f3f, MAXN = 1123;

const double PI = acos(-1);

int n, m;

char s[MAXN];
int k[MAXN];

double dp[MAXN][11];

double circ(int r){
	return PI*(r/2.);
}

double diag(int a, int b){
	return sqrt((double)a*a + (double)b*b);
}

int main (){
	while(scanf("%d%d", &n, &m)!=EOF && n+m){
		for(int a=0;a<=n;a++){
			for(int b=0;b<=m;b++){
				dp[a][b] = 1000000000;
			}
		}
		for(int a=0;a<n;a++){
			scanf(" %c %d", &s[a], &k[a]);
		}
		for(int a=0;a<m;a++){
			dp[0][a] = 0;
		}
		for(int i=0;i<n;i++){
			for(int l=0;l<m;l++){
				if(s[i] == 'L'){
					dp[i+1][l] = min(dp[i+1][l], dp[i][l] + circ(k[i] + 5 + 10*l));
				}
				else if(s[i] == 'R'){
					dp[i+1][l] = min(dp[i+1][l], dp[i][l] + circ(k[i] + 5 + 10*(m-l-1)));
				}
				else{
					for(int ll = 0;ll < m;ll++){
						if(100*abs(l - ll) > k[i]) continue;
						dp[i+1][ll] = min(dp[i+1][ll], dp[i][l] + diag(k[i], abs(l-ll)*10));
					}
				}
			}
		}
		double ans = INF;
		for(int l = 0;l<m;l++){
			ans = min(ans, dp[n][l]);
		}
		printf("%.2f\n", ans);
	}
}

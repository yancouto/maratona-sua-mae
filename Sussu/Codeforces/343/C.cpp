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

const int MAXN = 100010;

int n, m;

char s[MAXN];

long long dp[2010][2010];

ll go(){
	int l = 0;
	dp[0][0] = 1;
	while(l <= 2000){
		for(int d = 0;d <= 2000;d++){
			if(dp[l][d] == 0) continue;
			dp[l+1][d+1] = mod(dp[l+1][d+1] + dp[l][d]);
			if(d != 0) dp[l+1][d-1] = mod(dp[l+1][d-1] + dp[l][d]);
		}
		l++;
	} 
}

int main (){
	go();
	scanf("%d%d", &n, &m);
	int cnt = 0;
	int ant = 0;
	int dep = 0;
	for(int a=0;a<m;a++){
		scanf(" %c", &s[a]);
		if(s[a] == '(') cnt++;
		if(s[a] == ')') cnt--;
		if(cnt < 0){
			cnt = 0;
			ant++;
		}
	}
	dep = cnt;
	ll res = 0;
	//printf("%d %d\n", ant, dep);
	while(ant + dep <= n-m){
		for(int szi = ant; szi+dep <= n-m; szi++){
			int szf = n-m - szi;
			res = mod(res + mod(dp[szi][ant]*dp[szf][dep]));
		}
		ant++;
		dep++;
	}
	cout << res;
}
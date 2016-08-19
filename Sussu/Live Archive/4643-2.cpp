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

const int MAXN = 130, MAXM = 13;

int n, m;

int s[MAXN], dp[(1<<12)][(1<<12)];

int cnt(int bm, int d){
	int ans = 0;
	for(int a=0;a<n;a++){
		if(((s[a]&d)^bm) == 0)
			ans++;
	}
	return ans;
}

int go(int bm, int def){
	if(cnt(bm, def) <= 1)
		return 0;
	if(dp[bm][def] != -1)
		return dp[bm][def];
	dp[bm][def] = INT_MAX;
	for(int i=0;i<m;i++){
		if(!(def & (1<<i)))
			dp[bm][def] = min(dp[bm][def], 1+max(go(bm|(1<<i), def|(1<<i)), go(bm, def|(1<<i))));
	}
	return dp[bm][def];
}

int main (){
	while(scanf("%d%d", &m, &n)!=EOF && n+m){
		memset(dp, -1, sizeof(dp));
		for(int a=0;a<n;a++){
			s[a] = 0;
		}
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				char c;
				scanf(" %c", &c);
				s[a] += (c-'0')*(1<<(m-1-b));
			}
		}
		printf("%d\n", go(0, 0));
	}
}

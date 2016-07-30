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

const int MAXN = 112;

int n;
int s[MAXN], dp[MAXN][4];

/*
0 - ok
1 - fez c
2 - fez a
*/

int go(int i, int es){
	if(i == n)
		return dp[i][es] = 0;
	if(dp[i][es] != INT_MAX)
		return dp[i][es];
	dp[i][es] = min(dp[i][es], 1+go(i+1, 0));

	if(es != 1 && (s[i] == 1 || s[i] == 3)){
		dp[i][es] = min(dp[i][es], go(i+1, 1));
	}
	if(es != 2 && (s[i] == 2 || s[i] == 3)){
		dp[i][es] = min(dp[i][es], go(i+1, 2));
	}
	return dp[i][es];
}

int main (){
	int i, j;
	scanf("%d", &n);
	for(int a=0;a<=n;a++){
		for(int b=0;b<3;b++){
			dp[a][b] = INT_MAX;
		}
	}
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	printf("%d", go(0, 0));

}

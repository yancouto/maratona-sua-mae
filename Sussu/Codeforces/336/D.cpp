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

const int MAXN = 510, INF = 0x3f3f3f3f;

int n, s[MAXN], dp[MAXN][MAXN];

int go(int i,int j){
	if(dp[i][j] != INF) return dp[i][j];
	if(i==j-1 && s[i]==s[j]) return dp[i][j] = 1;
	if(i==j) return dp[i][j] = 1;
	if(s[i]==s[j] && j != i+1) dp[i][j] = min(dp[i][j],go(i+1,j-1));
	for(int a=i;a<j;a++){
		dp[i][j] = min(dp[i][j],go(i,a)+go(a+1,j));
	}
	return dp[i][j];
}


int main (){
	memset(dp,INF,sizeof(dp));
	scanf("%d", &n);
	for(int a=0;a<n;a++)
		scanf("%d", &s[a]);
	printf("%d\n", go(0,n-1));
}
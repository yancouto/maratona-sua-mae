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


const int MAXN = 3010;

int n;

ll b[MAXN], sum[MAXN], dp[MAXN][MAXN];

int bb(int i,int j, ll v){
	while(i<j){
		int m = (i+j)/2;
		if(sum[m] >= v)
			j = m;
		else
			i = m+1;
	}
	if(sum[i] < v) i++;
	return i;
}

ll go(int i,int j){
	if(dp[i][j]==-1){
		if(j==n-1) return dp[i][j] = 0;
		dp[i][j] = 0;
		ll sumi = 0;
		if(i!=0) sumi = sum[i-1];
		int jj = bb(j+1,n-1,sum[j]*2 - sumi);
		//printf("%d %d %d\n", i, j, jj);
		if(jj >= n) return 0;
		for(int a = jj;a<n;a++)
			dp[i][j] = max(go(j+1,a)+1,dp[i][j]);
	}
	return dp[i][j];
}

int main (){
	memset(dp,-1,sizeof(dp));
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		cin >> b[a];
		if(a!=0) sum[a] = sum[a-1];
		sum[a]+=b[a];
	}
	ll res =0;
	for(int a=0;a<n;a++){
		res = max(res,go(0,a)+1);
	}
	cout << res;
}
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

const int MAXN = 510;

int n, m, dp[MAXN][MAXN]; 
char M[MAXN][MAXN];

bool valid(int i,int j, int ii, int jj){
	return (M[i][j] != '#' && M[ii][jj] != '#' && ii<=n && jj<=m && i<=n && j<=m);
}

int pre(int i, int j){
	if(dp[i][j]!= -1) return dp[i][j];

	if(i == n && j == m) return dp[i][j] = 0;
	if(i == n) return dp[i][j] = pre(i,j+1) + valid(i,j,i,j+1);
	if(j == m) return dp[i][j] = pre(i+1,j) + valid(i,j,i+1,j);

	return dp[i][j] = pre(i+1,j) + valid(i,j,i+1,j) + pre(i,j+1) + valid(i,j,i,j+1) - pre(i+1,j+1);
}

int hor(int l,int i,int f){
	int ans = 0;
	for(int a=i;a<=f;a++){
		ans += valid(l,a,l+1,a);
	}
	return ans;
}

int ver(int c,int i,int f){
	int ans = 0;
	for(int a=i;a<=f;a++){
		ans += valid(a,c,a,c+1);
	}
	return ans;
}

int main (){
	scanf("%d %d", &n, &m);
	memset(dp,-1,sizeof(dp));
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			scanf(" %c", &M[a][b]);
		}
	}
	int q;
	pre(1,1);
	scanf("%d", &q);
	for(int a=0;a<q;a++){
		int i, j, ii, jj;
		scanf("%d%d%d%d", &i, &j, &ii, &jj);
		printf("%d\n", max(0,dp[i][j]) - max(0,dp[ii+1][j]) - max(0,dp[i][jj+1]) + max(0,dp[ii+1][jj+1]) - hor(ii,j,jj) - ver(jj,i,ii));
	}
}
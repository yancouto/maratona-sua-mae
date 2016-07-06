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


const int MAXN = 55, MAXC = 30, INF = 0x3f3f3f3f;

int n, dp[MAXN][MAXN][MAXC];

struct rule{
	int i, j;

	rule(){}
	rule(int ii, int jj){
		i = ii;
		j = jj;
	}
};


vector <rule> adj[500];

char s[100];

int go(int i, int j, int c){
	//printf("chamei go(%d %d %d): \n", i, j, c);
	if(dp[i][j][c] != INF)
		return dp[i][j][c];
	dp[i][j][c] = INF - 1;
	if(i == j){
		if(c == s[i]-'A')
			dp[i][j][c] = 0;
	//	printf("            %d\n", dp[i][j][c]);
		return dp[i][j][c];
	}

	for(int k = i;k < j;k++){
		for(rule r: adj[c]){
			dp[i][j][c] = min(1 + max(go(i, k, r.i), go(k+1, j, r.j)), dp[i][j][c]);
		}
	}
//	printf("            %d\n", dp[i][j][c]);
	return dp[i][j][c];
}

int main (){
	while(scanf("%d", &n)!=EOF && n!=0){
		memset(dp, INF, sizeof(dp));
		for(int a = 0;a<='Z'-'A';a++){
			adj[a].clear();
		}
		for(int a=0;a<n;a++){
			char x, i, j;
			scanf(" %c%c%c", &x, &i, &j);
			adj[x-'A'].pb(rule(i-'A', j-'A'));
		}
		scanf(" %s", s);
		int tam = strlen(s);
		int ans = INF-1;
		for(int a=0;a<='Z'-'A';a++){
			ans = min(ans, go(0, tam-1, a));
		}
		if(ans == INF-1)
			puts("-1");
		else
			printf("%d\n", ans);
	}
}

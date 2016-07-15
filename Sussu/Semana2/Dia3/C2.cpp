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

const int MAXN = 3123;

int n, s[MAXN];

int dp[MAXN][MAXN], prox[MAXN][MAXN];


map <int, vector<int> > m;

int go(int i, int j){
	if(dp[i][j] != -1)
		return dp[i][j];
	dp[i][j] = max(dp[i][j], go(j, prox[i][j]) + 1);
	return dp[i][j];
}

void rego(int i, int j){
	if(i == n) return ;
	printf("%d ", s[i]);
	rego( j, prox[i][j]);
}

int main (){
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		m[s[a]].pb(a);
	}
	if(n==1){
		printf("1\n%d\n", s[0]);
		return 0;
	}
	for(int a=0;a<n;a++){
		for(int b=a+1;b<n;b++){
			int som  = s[a] + s[b];
			if(m.find(som) != m.end()){
				if(upper_bound(m[som].begin(), m[som].end(), b) == m[som].end())
					prox[a][b] = n;
				else
					prox[a][b] = *upper_bound(m[som].begin(), m[som].end(), b);
			}
			else
				prox[a][b] = n;
	//		printf("%d %d : %d\n", a, b, prox[a][b]);
		}
	}
	int res = 0;
	for(int a=0;a<n;a++){
		dp[a][n] = 1;
	}

	for(int a=0;a<n;a++){
		for(int b=a+1;b<n;b++){
			res = max(res, go(a, b));
		}
	}

	printf("%d\n", res);
	for(int a=0;a<n;a++){
		for(int b=a+1;b<n;b++){
			if(dp[a][b] == res){
				rego(a, b);
				return 0;
			}
		}
	}
}

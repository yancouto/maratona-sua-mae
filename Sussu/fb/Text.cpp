#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 310, MAXS = 100010;

int lcp[MAXN][MAXN], n, k, dp[MAXN][MAXN];

vector <char> s[MAXN];

char pal[MAXS];

int go(int p,int q){
	if(dp[p][q] != -1) return dp[p][q];
	if(q==0)
		return dp[p][q] = (int)s[p].size();
	for(int a=0;a<)
}	

int main (){
	for_tests(t,tt){
		memset(dp,-1,sizeof(dp));
		scanf("%d%d", &n, &k);
		for(int a=1;a<=n;a++){
			scanf(" %s", pal);
			int tam = strlen(pal);
			for(int b=0;b<tam;b++){
				s[a].pb(pal[b]);
			}
		}
		for(int a=1;a<=n;a++){
			for(int b=1;b<=n;b++){
				if(a==b){
					lcp[a][b] = -1;
					continue;
				}
				int tam = min(s[a].size(),s[b].size());
				for(int c=0;c<tam;c++){
					if(s[a][c] != s[b][c]) break;
					lcp[a][b]++;
				}
			}
		}
		printf("%d", go(0,k));			
	}
}


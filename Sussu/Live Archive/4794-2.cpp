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

const int MAXN = 16, MAXD = 110;

int n, x, y, s[MAXD], sum[(1<<MAXN)], dp[MAXD][(1<<MAXN)];

vector <int> val[MAXD*MAXD];

bool go(int x, int bm){
	if(dp[x][bm] != -1) return dp[x][bm];
	int y = sum[bm]/x;
	dp[x][bm] = 0;
	if(y*x != sum[bm]) return dp[x][bm];
	if(__builtin_popcount(bm) == 1){
		//printf("eh true caso base x %d y %d bm %d sum[bm] %d\n", x, y, bm, sum[bm]);
		return dp[x][bm] = 1;
	}
	for(int xx = 1;xx<x;xx++){  
		if(!val[xx*y].empty() && !val[(x-xx)*y].empty()){
			for(int s: val[xx*y]){
				if(s&bm != s || sum[(bm^s)] != (x-xx)*y) continue;
				//printf("DIVIDE %d %d sum %d em %d %d com %d e  %d %d com %d\n", x, y, sum[bm], xx, y, sum[s], x-xx, y, sum[bm^s]);
				dp[x][bm] = max(dp[x][bm], (int)(go(xx, s) && go(x-xx, bm^s)));
				if(dp[x][bm]) return dp[x][bm];
			}
		}
	}
	for(int yy = 1;yy<y;yy++){
		if(!val[x*yy].empty() && !val[x*(y-yy)].empty()){
			for(int s: val[x*yy]){
				if(s&bm != s || sum[(bm^s)] != x*(y-yy)) continue;
				//printf("DIVIDE %d %d sum %d em %d %d com %d e  %d %d com %d\n", x, y, sum[bm], x, yy, sum[s], x, y-yy, sum[bm^s]);
				dp[x][bm] = max(dp[x][bm], (int)(go(x, s) && go(x, bm^s)));
				if(dp[x][bm]) return dp[x][bm];
			}
		}
	}
	return dp[x][bm];

}

int main (){
	int t = 0;
	while(scanf("%d", &n)!=EOF && n != 0){
		scanf("%d%d", &x, &y);
		int som = 0;
		for(int a=0;a<n;a++){
			scanf("%d", &s[a]);
			som += s[a];
		}
		printf("Case %d: ", ++t);
		if(som != x*y){
			puts("No");
			continue;
		}
		for(int a=0;a<=som;a++){
			val[a].clear();
		}
		for(int bm=0;bm<(1<<n);bm++){
			sum[bm] = 0;
			int i = 0;
			for(int a=1;a<(1<<n);a*=2){
				if(bm&a) sum[bm] += s[i];
				i++;
			}
			//printf("sum[%d] %d\n", bm, sum[bm]);
			val[sum[bm]].pb(bm);
		}	
		for(int a=0;a<=x;a++){
			for(int bm=0;bm<(1<<n);bm++){
				dp[a][bm] = -1;
			}
		}
		if(go(x, (1<<n)-1))
			puts("Yes");
		else
			puts("No");
	}
}

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

const int MAXN  = 1000010, MAXK = 10, MAXB = 1010, INF = 0x3f3f3f3f;

int n, p[MAXB][2];

struct pd{
	int v, b;
	char t;
} dp[MAXN][MAXK];

int main(){
	for(int a=1;p[a-1][0]<MAXN;a++){
		p[a][0] = a*a + p[a-1][0];
		if(p[a][0] >= MAXN) printf("high %d\n", a);
	}
	p[1][1] = 1;
	for(int a=2;p[a-2][1]<MAXN || p[a-1][1]<MAXN;a++){
		p[a][1] = p[a-2][1] + a*a;
		if(p[a][1] >= MAXN && p[a-1][1] >= MAXN) printf("low %d\n", a);
	}
	for(int a=0;a<MAXN;a++){
		for(int b=0;b<MAXK;b++){
			dp[a][b].v = INF;
		}
	}
	dp[0][0].v = 0;
	for(int k = 0;k < MAXK;k++){
		for(int i = 0;i < MAXN; i++){
			if(dp[i][k].v == -1) continue;
			for(int tip =0;tip<2;tip++){
				for(int bas = 1;i+p[bas][tip] < MAXN;bas++){
					if(dp[i+p[bas][tip]][k+1].v > dp[  
				}	
			}
		}
	}
	while(scanf("%d", &n) != EOF && n!=0){
				
	}
}

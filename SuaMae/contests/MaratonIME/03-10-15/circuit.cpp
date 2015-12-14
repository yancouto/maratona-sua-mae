
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

const int MAXN = 910; 

int n,i, j, deg;

long long dp[MAXN][MAXN];

struct point{
	int i, j, ii, jj;
} fil[MAXN*MAXN];

int main (){
	scanf("%d", &n);
	memset(dp,0,sizeof(dp));
	dp[450][450]=1;
	for(int a=0;a<n;a++){
		scanf("%d %d", &i, &j);
		deg=0;
		//printf("%d %d\n\n", i, j);
		for(int b = 905;b>=0;b--){
				for(int c=905;c>=0;c--){	
					if(dp[b][c]!=0){
						fil[deg].ii=b+i;
						fil[deg].jj=c+j;
						fil[deg].i=b;
						fil[deg].j=c;
						deg++;
					}
				}
		}
		for(int z=0;z<deg;z++){
	//		printf("atualizei %d %d\n", fil[z].ii, fil[z].jj);
			dp[fil[z].ii][fil[z].jj]+=dp[fil[z].i][fil[z].j];
		}
	}
	
	printf("%lld\n", dp[450][450]-1);
	return 0;
}

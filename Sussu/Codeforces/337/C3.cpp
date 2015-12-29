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

const int MAXN = (1<<9) + 10;

int res[MAXN][MAXN][10], k;

int main (){
	scanf("%d", &k);
	res[1][1][0] = 1;
	for(int kk=1;kk<=k;kk++){
		int deg = 1;
		for(int i = 1;i <= (1 << (kk-1));i++){
			for(int j = 1;j <= (1 << (kk-1)); j++){
				res[deg][j][kk] = res[i][j][kk-1];
				res[deg][j + (1 << (kk-1))][kk] = res[i][j][kk-1];
				res[deg+1][j][kk] = res[i][j][kk-1];
				res[deg+1][j + (1 << (kk-1))][kk] = (-1)*res[i][j][kk-1];
			}
			deg+=2;
		}
	}

	for(int a=1;a<=(1<<k);a++){
		for(int d=1;d<=(1<<k);d++){
			//printf("%d ", res[a][d][k]);
			
			if(res[a][d][k] == 1)
				printf("+");
			else
				printf("*");
			
		}
		printf("\n");
	}
}
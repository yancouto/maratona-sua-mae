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

const int MAXN = 65, MAXK = 500, INF = 0x3f3f3f3f;

int n, nv, r;

int dp[MAXN][MAXN][MAXK], m[MAXN][MAXN][MAXNse], d[MAXN][MAXN];


int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}


int go(int i, int j, int k){
	int *h = &dp[i][j][k];
	//printf("dp[%d][%d][%d] %d %d\n", i, j, k, *h, dp[i][j][k]);
	
	if( *h != INF ) return *h;
	if(i == j) return *h = 0;
	if(k == 1) return *h = d[i][j];
	for(int v=0;v<n;v++){
		if(v == i) continue;
		*h = min(*h, d[i][v] + go(v, j, k-1));
	}
	return *h;
}

int main (){
	scanf("%d%d%d", &n, &nv, &r);
	//n = readInt();
	//nv = readInt();
	//r = readInt();
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			for(int c=0;c<MAXK - 4;c++){
				dp[a][b][c] = INF;
			}
		}
	}
	for(int a=0;a<nv;a++){
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				scanf("%d", &m[i][j][a]);
				//m[i][j][a] = readInt();
			}
		}
	}

	for(int v=0;v<nv;v++){
		for(int ij=0;ij<n;ij++){
			for(int i=0;i<n;i++){
				if(i == ij) continue;
				for(int j=0;j<n;j++){
					if(j == ij || i == j) continue;
					m[i][j][v] = min(m[i][j][v], m[i][ij][v] + m[ij][j][v]);
				}
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			d[i][j] = INF;
			for(int v=0;v<nv;v++){
				d[i][j] = min(d[i][j], m[i][j][v]);
			}
			//printf("%d ", d[i][j]);
		}
		//printf("\n");
	}

	for(int q=0;q<r;q++){
		int i, j, k;
		scanf("%d%d%d", &i, &j, &k);
		//i = readInt();
		//j = readInt();
		//k = readInt();
		i--;j--;k++;
		if(k > 400){
			k = 400;
		}
		printf("%d\n", go(i, j, k));
	}
}
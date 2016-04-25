
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

const int MAXN = 5010;

int l[MAXN], c[MAXN], tl[MAXN], tc[MAXN];
int n, m, k;

int M[MAXN][MAXN], atm[MAXN][MAXN];

int main (){
	scanf("%d%d%d", &n, &m, &k);
	for(int a=1;a<=k;a++){
		int t, i, co;
		scanf("%d%d%d", &t, &i, &co);
		if(t == 1){
			l[i] = co;
			tl[i] = a;
		}
		else{
			c[i] = co;
			tc[i] = a;
		}
	}
	for(int a=1;a<=n;a++){
		for(int j=1;j<=m;j++){
			M[a][j] = l[a];
			atm[a][j] = tl[a];
		}
	}

	for(int a=1;a<=m;a++){
		for(int i=1;i<=n;i++){
			if(tc[a] > atm[i][a]) M[i][a] = c[a];
		}
	}
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			printf("%d ", M[a][b]);
		}
		printf("\n");
	}
}

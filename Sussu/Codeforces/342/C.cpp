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

const int MAXN = 510;

int n, k, M[MAXN][MAXN];

int main (){
	scanf("%d%d", &n, &k);
	int i = 1, f;
	f = (k-1)*n + 1;
	int ans = 0;
	for(int a=1;a<=n;a++){
		for(int b=1;b<=n;b++){
			if(b < k)
				M[a][b] = i++;
			else
				M[a][b] = f++;

			if(b == k)
				ans += M[a][b];
		}
	}
	printf("%d\n", ans);
	for(int a=1;a<=n;a++){
		for(int b=1;b<=n;b++){
			printf("%d ", M[a][b]);
		}
		printf("\n");
	}
	printf("\n");
}
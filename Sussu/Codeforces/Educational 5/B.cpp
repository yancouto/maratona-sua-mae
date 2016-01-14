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

const int MAXN = 110;

int n, m, c[MAXN][MAXN], men[MAXN], res;

int main(){
	scanf(" %d%d", &n, &m);
	res = 0;
	for(int a=0;a<n;a++){
		men[a] = 1000000000;
		for(int b=0;b<m;b++){
			scanf("%d", &c[a][b]);
			men[a] = min(men[a],c[a][b]);
		}
		res = max(res,men[a]);
	}
	printf("%d\n", res);
	return 0;
}
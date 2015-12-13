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

const int MAXN = 100010, INF = 0x3f3f3f3f;

int i, j, k;

int main(){
	scanf("%d %d %d", &i, &j, &k);
	int ii, jj, kk;
	scanf("%d%d%d", &ii, &jj, &kk);
	int si = i-ii, sj = j-jj, sk = k-kk;
	int neg = abs(si*(si<0) + sj*(sj<0) + sk*(sk<0));
	int pos = (si/2) * (si>0) + (sj/2) * (sj>0) + (sk/2)*(sk>0);
	//printf("%d %d\n", pos, neg);
	if(pos>=neg)
		puts("Yes");
	else
		puts("No");
	return 0;
}
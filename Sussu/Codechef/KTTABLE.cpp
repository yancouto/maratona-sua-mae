
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

const int MAXN = 11234;

ll f[MAXN], tem[MAXN];

int main (){
	for_tests(t, tt){
		int n;
		scanf("%d", &n);
		for(int a=1;a<=n;a++){
			scanf("%lld", &f[a]);
		}
		int res = 0;
		for(int a=1;a<=n;a++){
			scanf("%lld", &tem[a]);
			if(f[a] - f[a-1] >= tem[a])
				res++;
		}
		printf("%d\n", res);
	}
}

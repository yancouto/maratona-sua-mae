
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


int n;
int a[2000];

int main() {
	int i; 
	while(42) {
		scanf("%d", &n);
		if(n == 0) break;
		for(i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		int mx = 0;
		for(i = 1; i < n; i++)
			mx = max(mx, a[i] - a[i-1]);
		mx = max(mx, max(a[0], 2*(1422 - a[n-1])));
		if(mx > 200) puts("IMPOSSIBLE");
		else puts("POSSIBLE");
	}
	return 0;
}

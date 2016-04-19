
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

int x[20005], y[20005];

int main() {
	int aa, bb, n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &aa, &bb); 
		x[aa+10000] = y[bb+10000] = 1;

	}
	vector<int> a, b;
	for(int xx = -10000; xx <= 10000; xx++) {
		if(x[xx+10000]) a.pb(xx);
	}
	for(int xx = -10000; xx <= 10000; xx++) 
		if(y[xx+10000]) b.pb(xx);
	if(a.size() == 2 && b.size() == 2) printf("%d\n", (a[1]-a[0]) * (b[1]-b[0]));
	else printf("-1\n");
		
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int main() {
	for_tests(t, tt) {
		int n, i, ans = 0;
		double a, b, c, x, y;
		map<double, int> mp;
		map<pdd, int> mpl;
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%lf %lf %lf", &a, &b, &c);
			y = 10, x = (-c -b*y) / a;
			if(a == 0) x = 10, y = (-c -a*x) / b; 
			double ang, lin;
			ang = -a / b;
			if(b == 0) ang = 100000000;
			lin = y - ang * x;
			if(mpl.count(pdd(ang, lin))) continue;
			mpl[pdd(ang, lin)]++;
			ans = max(ans, ++mp[ang]);
		}
		printf("%d\n", ans);
	}
	return 0;
}

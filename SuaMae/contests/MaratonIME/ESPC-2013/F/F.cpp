#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll c1(ll x) { return (x * (x + 1) * (2 * x + 1)) / 6; }
inline ll c2(ll x) { return (x * (x + 1)) / 2; }
int main() {
	freopen("army.in", "r", stdin);
	int tn; ll n;
	scanf("%d", &tn);
	for(int tt = 1; tt <= tn; tt++) {
		scanf("%I64d", &n);
		ll l = 1, r = 1500000;
		while(l < r) {
			ll m = (l + r + 1) / 2;
			if(c1(m) <= n) l = m;
			else r = m - 1;
		}
		n -= c1(l);
		ll tot = l * l;
		printf("Case %d: ", tt);
		l++;
		if(n <= c2(l)) {
			ll x = l;
			l = 0; r = x;
			while(l < r) {
				ll m = (l + r) / 2;
				if(c2(m) >= n) r = m;
				else l = m + 1;
			}
			tot += l;
		} else {
			n -= c2(l); tot += l;
			ll x = l;
			l = 0; r = x;
			while(l < r) {
				ll m = (l + r) / 2;
				if((x * m - c2(m)) >= n) r = m;
				else l = m + 1;
			}
			tot += l;
		}
		printf("%I64d\n", tot);
	}
}

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

ll comb(int n, int k) {
	if(k == 0 || k < 0) return 0;
	
}

int main() {
	scanf("%d %d", &n, &t);
	for(i = 0; i < n; i++) 
		scanf("%d", &cl[i]), fc[cl[i]]++;
	scanf("%d %d", &k, &x); k--; x--;
	fc[cl[k]]--;
	mn = mx = 0;
	for(i = 0; i <= 5000; i++) 
		if(i < cl[k]) mn += fc[i];
		else mx += fc[i];
	ll ans = 0;
	for(left = 0; left < x && left < fc[cl[k]]; left++) {
		for(right = 0; right < t - x - 1 && left + right < fc[cl[k]]; right++) {
			cur = mod(comb(fc[cl[k]], left + right));
			cur = mod(cur * mod(comb(mn, x - left) * mod(comb(mx, t - x - 1 - right))));
			ans = mod(ans + cur);
		}
	}
	printf("%lld\n", ans);
	return 0;
}

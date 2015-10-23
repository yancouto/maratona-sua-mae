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

int abs(int x) {
	if(x < 0) return -x;
	return x;
}

int main() {
	for_tests(t, tt) {
		int n, k;
		int v[105];
		scanf("%d %d", &n, &k);
		for(int i = 0; i < n; i++)
			scanf("%d", &v[i]);
		int ans = 1;
		sort(v, v + n);
		for(int i = 1; i < n; i++)
			if(abs(v[i] - v[i-1]) > k) ans++;
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}

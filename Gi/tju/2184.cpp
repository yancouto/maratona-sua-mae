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

int num[2][505], sz[2];
int seen[505], v[505];

int main() {
	int n, k, ans, i, j;
	while(42) {
		scanf("%d %d", &n, &k);
		if(n + k == 0) break;
		memset(seen, 0, sizeof seen);
		for(i = 0; i < n; i++) 
			scanf("%d", &v[i]);
		sort(v, v + n); ans = 0;
		for(i = 0; i < n; i++) {
			if(seen[i]) continue;
			for(j = i + 1; j < n; j++)
				if(!seen[j] && v[j] % 2 == !(v[i] % 2)) break;
			if(j == n || v[j] - v[i] > k) continue;
			seen[i] = seen[j] = 1; ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}

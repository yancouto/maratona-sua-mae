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

const int N = 100009;
int x[N], y[N], k, n;

int dist(int i) {
	return min(abs(x[i] - y[i]), abs(k - abs(x[i] - y[i])));
}

int main() {
	int i;
	for_tests(t, tt) {
		scanf("%d %d", &n, &k);
		for(i = 0; i < n; i++)
			scanf("%d", &x[i]);
		for(i = 0; i < n; i++)
			scanf("%d", &y[i]);
		bool any_ok = false;
		ll tot = 0;
		for(i = 0; i < n; i++) {
			if(2*dist(i) == k) {
				tot += dist(i);
				any_ok = true;
			} else {
				tot += 2 + dist(i);
				if(dist(i) == ((k - 1) / 2)) tot--;
				else any_ok = true;
			}
		}
		if(!any_ok) tot--;
		printf("%lld\n", tot);
	}

}

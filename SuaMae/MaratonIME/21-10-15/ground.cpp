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
const int MAX = 1000009;
ll h[MAX], all[MAX];
int main() {
	int i, n, m;
	char c;
	for_tests(t, tt) {
		scanf("%d %d", &n, &m);
		int cur = MAX;
		ll mn = LLONG_MAX;
		deque<int> d;
		for(i = 1; i <= n; i++) {
			scanf(" %c", &c);
			if(c == '\\') cur--;
			h[i] = cur;
			all[i] = 2ll * cur + (c != '_') + all[i -1];
			if(c == '/') cur++;
			while(!d.empty() && d.back() > h[i]) d.pop_back();
			d.pb(h[i]);
			if(i >= m) {
				if(i > m && d.front() == h[i - m]) d.pop_front();
				int x = d.front();
				mn = min(mn, all[i] - all[i - m] - 2ll * ll(m) * x);
			}
		}
		printf("Case #%d: %.1f\n", tt, mn / 2.);
	}
}

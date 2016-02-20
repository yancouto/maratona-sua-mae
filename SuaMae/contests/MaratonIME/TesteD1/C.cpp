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
const int N = 1000009;

int ans[N], l, mn[N];

int main() {
	int i, x, n, m;
	for_tests(t, tt) {
		l = 0;
		scanf("%d %d", &n, &m);
		for(i = 0; i <= n; i++) mn[i] = -1;
		bool pos = true;
		map<int, int> s;
		for(i = 0; i < m; i++) {
			scanf("%d", &x);
			if(!pos) continue;
			if(!x) {
				s[i] = l;
				ans[l++] = 0;
			} else {
				auto it = s.upper_bound(mn[x]);
				if(it == s.end()) { pos = false; continue; }
				ans[it->snd] = x;
				s.erase(it);
				mn[x] = i;
			}
		}
		if(!pos) { puts("NO"); continue; }
		puts("YES");
		if(l) printf("%d", ans[0]);
		for(i = 1; i < l; i++)
			printf(" %d", ans[i]);
		putchar('\n');
	}
}

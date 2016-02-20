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
const int N = 1000;

multiset<ll> s;
ll x[N], a[N];
bool ok(ll x0, ll x1, ll x2) {
	if((x0 - x1 + x2) & 1) return false;
	a[1] = (x0 - x1 + x2) / 2;
	a[0] = x0 - a[1];
	a[2] = x1 - a[0];
	return true;
}

int n, m;
ll b[N];
bool solve() {
	int i, j;
	for(i = 3; i < n; i++) {
		if(s.empty()) return false;
		ll k = *s.begin();
		a[i] = k - a[0];
		for(j = 0; j < i; j++) {
			if(s.find(a[i] + a[j]) == s.end()) return false;
			s.erase(s.find(a[i] + a[j]));
		}
	}
	for(i = 0; i < n - 1; i++)
		if(a[i] > a[i + 1])
			return false;
	int bn = 0;
	for(i = 0; i < n; i++)
		for(j = i + 1; j < n; j++)
			b[bn++] = a[i] + a[j];
	sort(b, b + m);
	for(i = 0; i < m; i++)
		if(b[i] != x[i])
			return false;
	return true;
}

int main() {
	int i, j;
	while(scanf("%d", &n) != EOF) {
		m = ((n * (n - 1)) / 2);
		for(i = 0; i < m; i++)
			scanf("%lld", &x[i]);
		sort(x, x + m);
		for(i = 2; i < m; i++)
			if(ok(x[0], x[1], x[i])) {
				s.clear();
				for(j = 2; j < m; j++)
					if(j != i)
						s.insert(x[j]);
				if(solve()) {
					printf("%lld", a[0]);
					for(j = 1; j < n; j++)
						printf(" %lld", a[j]);
					putchar('\n');
					break;
				}
			}
		if(i == m) puts("Impossible");
	}
}

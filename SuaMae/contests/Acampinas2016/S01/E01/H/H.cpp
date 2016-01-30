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

ll memo[2][507];
unsigned v[100009];
int n;
ll &m(int i, int ch) {
	return memo[i&1][i-ch];
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%x", &v[i]);
	for(int i = n - 1; i >= 0; i--)
		for(int ch = i; ch >= i - 500; ch--)
			m(i, ch) = max(m(i + 1, ch + 1) + (v[i] ^ ch), m(i + 1, ch));
	printf("%lld\n", m(0, 0));
}

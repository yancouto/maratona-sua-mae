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

ll memo[2][100009];

inline int get() {
	int a = 0;
	char c;
	while(isdigit(c = getchar_unlocked()))
		a = (a << 3) + (a << 1) + (c - '0');
	return a;
}
#define pc putchar_unlocked

inline void prn(ll x) {
	if(x == 0) { pc('0'); return; }
	int dg = 0;
	ll y = 0;
	while(x) y = (y << 3) + (y << 1) + (x % 10), x /= 10, dg++;
	while(dg--) pc((y % 10) + '0'), y /= 10;
}

int s[1000009], v[1000009];
int sn[303], ct[303];

ll *it[303];

int main() {
	int i, n, k, j, w;
	//n = get(); k = get();
	n = 1000000; k = 100000;
	for(i = 0; i < n; i++) {
		//s[i] = get(); v[i] = get();
		s[i] = (rand() % 300) + 1;
		v[i] = rand();
		sn[s[i]]++;
	}
	for(i = 1; i <= 300; i++)
		it[i] = new ll[sn[i]];
	for(i = 0; i < n; i++)
		it[s[i]][ct[s[i]]++] = v[i];
	for(i = 1; i <= 300; i++) {
		sort(it[i], it[i] + sn[i], greater<ll>());
		for(j = 1; j < sn[i]; j++)
			it[i][j] += it[i][j - 1];
	}
	for(i = 300; i > 0; i--)
		for(w = 0; w <= k; w++) {
			ll &r = memo[i & 1][w];
			r = memo[(i + 1) & 1][w];
			for(j = 1; j * i <= w && j <= sn[i]; j++)
				r = max(r, memo[(i + 1) & 1][w - j * i] + it[i][j - 1]);
		}
	for(i = 1; i <= k; i++) {
		prn(memo[1][i]);
		pc(' ');
	}
	pc('\n');
}

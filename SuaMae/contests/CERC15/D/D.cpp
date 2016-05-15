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

char g[312345];
int main() {
	int i, n, m;
	scanf("%d %d", &n, &m);
	int r = 0, tot = 0;
	for(i = 0; i < n; i++) {
		scanf(" %c", &g[i]);
		r = (10 * r + (g[i] - '0')) % m;
		if(r == 0) tot++;
	}
	if(r != 0) puts("0");
	else {
		ll val = 1;
		for(tot--; tot; tot--) val = mod(val * 2);
		printf("%d\n", (int) val);
	}
}

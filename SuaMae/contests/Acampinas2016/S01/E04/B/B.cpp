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

char s[200009];
int nx[200009];
int main() {
	freopen("bad.in", "r", stdin);
	freopen("bad.out", "w", stdout);
	int i, n, tot = 0;
	scanf("%s", s);
	n = strlen(s);
	for(i = 0; i < n; i++) tot += 4 * (s[i] == '1');
	nx[n - 1] = n;
	for(i = n - 2; i >= 0; i--) {
		if(s[i + 1] == '1') nx[i] = i + 1;
		else nx[i] = nx[i + 1];
	}
	int best = n - (s[0] == '1'? 0 : nx[0]);
	for(i = 0; i < n; i++) {
		int b1 = i, b2 = n - nx[i];
		best = min(best, b1 + b2 + min(b1, b2));
	}
	printf("%d\n", tot + best * 7);
}
